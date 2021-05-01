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

const OPERATOR_PREC = [
    ['+', PREC.ADD],
    ['-', PREC.ADD],
    ['*', PREC.MULTIPLY],
    ['/', PREC.MULTIPLY],
    ['%', PREC.MULTIPLY],
    ['||', PREC.LOGICAL_OR],
    ['&&', PREC.LOGICAL_AND],
    // ['^', PREC.EXCLUSIVE_OR],
    // ['&', PREC.BITWISE_AND],
    ['=~', PREC.EQUAL],
    ['==', PREC.EQUAL],
    ['!=', PREC.EQUAL],
    ['>', PREC.RELATIONAL],
    ['>=', PREC.RELATIONAL],
    ['<=', PREC.RELATIONAL],
    ['<', PREC.RELATIONAL],
    ['<<', PREC.SHIFT],
    ['>>', PREC.SHIFT],
];


const SPECIAL_CHARACTERS = [
    "'", '"',
    '{', '}',
    '\\[', '\\]',
    '(', ')',
    '\\', '\\s',
    '$', ';',
    '#',
    '\\-',
];

const ws_no_newline = new RegExp('[^\S\r\n]');

module.exports = grammar({
    name: 'nu',

    extras: $ => [
        $.comment,
        /\s/,
    ],

  conflicts: $ => [
    // conflict on parsing array of array vs table
    [$._expression, $.column_header],
  ],

    word: $ => $.word,

    rules: {
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
            // $.block,
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
                    $.rest
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
            field('value', $._expression),
        ),

        command: $ => seq(
            field('cmd_name', $.identifier),
            repeat(field('arg', $._expression))
        ),

        pipeline: $ => prec.left(1, seq(
          $._statement,
          '|',
          $._statement,
        )),

        _expression: $ => choice(
            $.number_literal,
            $.string,
            $.value_path,
            $.file_path,
            $._flag_arg,
            $.range,
            $.math_mode,
            $.operator,
            $.command_substitution,
            $.table,
            $.array,
            $.block,
            $.identifier,
        ),

        // TODO figure out 
        // number_literal: $ => /(0x[\da-fA-F]+|[\d]+(\.([\d]+)?)?|0b[01]+)/,
        number_literal: $ => /[\d]+(\.([\d]+)?)?/,

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
        '$',
        $.identifier,
        repeat(seq('.', $.identifier))
    ),

    file_path: $ => choice(
            // '-', //previous pwd (conflicts with operator)
            /[^\S\r\n]\.\.|\.[^\S\r\n]/, //Expect ws before .|.. and after (but exclude newline)
            /(([\w\.]+\/)*)([\w\.]+)\.\w+/, //filepath must end with <.file_ending> for now
        ),

    _flag_arg: $ => choice(
        seq(ws_no_newline, $.flag_name),
        seq(ws_no_newline, $.flag_shorthand_name),
    ),

    range: $ => seq(
        $.number_literal,
        '..',
        $.number_literal,
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

    identifier: $ => /[a-zA-Z_]+(-?[a-zA-Z_0-9]+)*/,

    table: $ => seq(
        '[', $.column_header, ';', repeat($.array), ']'
    ),

    column_header: $ => seq(
        '[', repeat(seq($.identifier, ',')), ']'
    ),

    array: $ => seq(
        '[', repeat(seq($._expression, choice(',', ' '))), ']'
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
        $.value_path,
        $.number_literal,
    ),

    parenthesized_math_expression: $ => seq(
      '(',
      $._math_expression,
      ')'
    ),

    operator: $ => choice(...OPERATOR_PREC.map(([operator, _]) => {
        return seq(operator)
    })),

    binary_expression: $ => {
        return choice(...OPERATOR_PREC.map(([operator, precedence]) => {
            return prec.left(precedence, seq(
                field('left', $._math_expression),
                field('operator', operator),
                field('right', $._math_expression)
            ))
        }));
    },
}
});

function noneOf(...characters) {
  const negatedString = characters.map(c => c == '\\' ? '\\\\' : c).join('')
  return new RegExp('[^' + negatedString + ']')
}
