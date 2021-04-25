const PREC = {
  PAREN_DECLARATOR: -10,
  DEFAULT: 0,
  LOGICAL_OR: 1,
  LOGICAL_AND: 2,
  // INCLUSIVE_OR: 3,
  // EXCLUSIVE_OR: 4,
  // BITWISE_AND: 5,
  EQUAL: 6,
  RELATIONAL: 7,
  SHIFT: 9,
  ADD: 10,
  MULTIPLY: 11,
  UNARY: 13,
};

const SPECIAL_CHARACTERS = [
    "'", '"',
    '<', '>',
    '{', '}',
    '\\[', '\\]',
    '(', ')',
    '`', '$',
    '|', '&', ';',
    '\\',
    '\\s',
    '#',
];

module.exports = grammar({
    name: 'nu',

    conflicts: $ => [
       [$.variable_deref, $.value_path]
    ],

    extras: $ => [
        $.comment,
        /\s/,
    ],

    rules: {
        // TODO: add the actual grammar rules
        source_file: $ => optional($._statements),

        _statements: $ => prec(1, seq(
            repeat(seq(
                $._statement,
                $._terminator
            )),
            $._statement,
            optional($._terminator)
        )),

        _statement: $ => choice(
            $.variable_declaration,
            $.function_definition,
            $.command,
            // $.for_statement,
            // $.while_statement,
            // $.if_statement,
            // $.case_statement,
            $.pipeline,
            $.block,
            $._math_expression,
        ),

        function_definition: $ => seq(
            'def',
            field('func_name', choice($.identifier, $.string)),
            $.signature,
            $.block,
        ),

        signature: $ => seq(
            '[',
            repeat(
                seq(choice(
                    $.parameter,
                    $.flag,
                    // $.rest
                ),
                    optional(',')),
            ),
            ']',
        ),
        parameter: $ => seq(
            $.identifier,
            optional(seq(':', $.type)),
            optional('?'),
        ),
        flag: $ => seq(
            $.flag_name,
            optional(
                seq('(', $.flag_shorthand_name ,')')
            ),
            optional(seq(':', $.type)),
        ),
        flag_name: $ => /--[a-zA-Z_]+[a-zA-Z_0-9]*/,
        flag_shorthand_name: $ => /-[a-zA-Z0-9]/,
        rest: $ => seq(
            '...rest',
            optional(seq(':', $.type)),
        ),
        type: $ => choice(
            'int',
            'string',
            'path',
            'table',
            'unit',
            'number',
            'pattern',
            'range',
            'block',
            'any',
        ),

        variable_declaration: $ => seq(
            'let',
            field('name', $.identifier),
            '=',
            field('value', $._literal),
        ),

        command: $ => seq(
            $.cmd_name,
            repeat($._literal)
        ),

        cmd_name: $ => /[a-zA-Z_]+(-?[a-zA-Z_0-9]+)*/,

        pipeline: $ => prec.left(1, seq(
          $._statement,
          '|',
          $._statement,
        )),

        // literals
        _literal: $ => choice(
            // $.concatenation,
            $._primary_expression,
            // alias(prec(-2, repeat1($._special_character)), $.word)
        ),

        _primary_expression: $ => choice(
            $.number_literal,
            $.string,
            $.value_path,
            $.variable_deref,
            $.math_mode,
            $.command_substitution,
            $.table,
            $.array,
            $.block,
            $.word,
        ),

        number_literal: $ => /(0x[\da-fA-F]+|[\d]+(\.([\d]+)?)?|0b[01]+)/,

        word: $ => token(repeat1(choice(
            noneOf(...SPECIAL_CHARACTERS),
            seq('\\', noneOf('\\s'))
        ))),

    string: $ => choice(
        seq( 
            '"',
            repeat($.qouted_string_content),
            '"'
        ),
        seq( 
            '\'',
            repeat($.single_qouted_string_content),
            '\''
        ),
    ),
    qouted_string_content: $ => token(prec(-1, /([^"\\]|\\(.|\n))+/)),
    single_qouted_string_content: $ => token(prec(-1, /([^'\\]|\\(.|\n))+/)),

    value_path: $ => seq(
        $.variable_deref,
        token.immediate('.'),
        $.identifier
    ),

    variable_deref: $ => seq(
        '$',
        $.identifier
    ),

    command_substitution: $ => seq(
        '$(', $._statements, ')',
    ),

    math_mode: $ => seq(
        '$(', '=', $._math_expression, ')',
    ),

    identifier: $ => /[a-zA-Z_]+[a-zA-Z_0-9-]*/,

    table: $ => seq(
        '[', $.column_header, ';', repeat($.array), ']'
    ),

    column_header: $ => seq(
        '[', repeat(seq($.identifier, ',')), ']'
    ),

    array: $ => seq(
        '[', repeat(seq($.identifier, ',')), ']'
    ),

    block: $ => seq(
        '{', optional($._statements), '}'
    ),

    comment: $ => token(prec(-10, /#.*/)),

    _terminator: $ => choice(';', '\n'),

    _math_expression: $ => choice(
        $.binary_expression,
        $.math_mode,
        $.command_substitution,
        $.parenthesized_math_expression,
        $.variable_deref,
        $.number_literal,
    ),

    parenthesized_math_expression: $ => seq(
      '(',
      $._math_expression,
      ')'
    ),

    binary_expression: $ => {
        const table = [
            ['+', PREC.ADD],
            ['-', PREC.ADD],
            ['*', PREC.MULTIPLY],
            ['/', PREC.MULTIPLY],
            ['%', PREC.MULTIPLY],
            ['||', PREC.LOGICAL_OR],
            ['&&', PREC.LOGICAL_AND],
            // ['^', PREC.EXCLUSIVE_OR],
            // ['&', PREC.BITWISE_AND],
            ['==', PREC.EQUAL],
            ['!=', PREC.EQUAL],
            ['>', PREC.RELATIONAL],
            ['>=', PREC.RELATIONAL],
            ['<=', PREC.RELATIONAL],
            ['<', PREC.RELATIONAL],
            ['<<', PREC.SHIFT],
            ['>>', PREC.SHIFT],
        ];

        return choice(...table.map(([operator, precedence]) => {
            return prec.left(precedence, seq(
                field('left', $._math_expression),
                field('operator', operator),
                field('right', $._math_expression)
            ))
        }));
    },
}
});

// Values in nu are immutable. There is nothing like assignment
// variable_assignment: $ => seq(
//     field('name', choice(
//         $.variable_name,
//         // $.subscript
//     )),
//     '=',
//     field('value', choice(
//         $._literal,
//         // $.array,
//     ))
// ),


function noneOf(...characters) {
  const negatedString = characters.map(c => c == '\\' ? '\\\\' : c).join('')
  return new RegExp('[^' + negatedString + ']')
}
