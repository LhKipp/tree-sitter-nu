const PREC = {
    PAREN_DECLARATOR: -10,
    PIPE: -5,
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
    ['|', PREC.PIPE],
    ['+', PREC.ADD],
    ['-', PREC.ADD],
    ['*', PREC.MULTIPLY],
    ['/', PREC.MULTIPLY],
    ['%', PREC.MULTIPLY],
    ['mod', PREC.MULTIPLY],
    ['||', PREC.LOGICAL_OR],
    ['&&', PREC.LOGICAL_AND],
    // ['^', PREC.EXCLUSIVE_OR],
    // ['&', PREC.BITWISE_AND],
    ['=~', PREC.EQUAL],
    ['==', PREC.EQUAL],
    ['!=', PREC.EQUAL],
    ['in', PREC.EQUAL],
    ['>', PREC.RELATIONAL],
    ['>=', PREC.RELATIONAL],
    ['<=', PREC.RELATIONAL],
    ['<', PREC.RELATIONAL],
    ['<<', PREC.SHIFT],
    ['>>', PREC.SHIFT],
];


const SPECIAL_CHARACTERS = [
    "'", '"', '`',
    '{', '}',
    '\\[', '\\]',
    '(', ')',
    '\\', '\\s',
    '$', ';', '.', '|', '=',
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
        [$.command],
        // conflict on parsing array of array vs table
        [$._expression, $.column_header],
        // conflict on parsing table vs array of array
        [$.array, $.column_header],
    ],

    // word: $ => $.word,

    rules: {
        source_file: $ => optional($._statements),

        _statements: $ => seq(
            repeat(seq(
                $._statement,
                $._terminator
            )),
            $._statement,
            optional($._terminator)
        ),

        _terminator: $ => choice(';', '\n'),

        _statement: $ => choice(
            $.variable_declaration,
            $.function_definition,
            $.alias,
            // $.for_statement,
            // $.while_statement,
            // $.if_statement,
            // $.case_statement,
            // $.pipeline,
            $._expression,
        ),

        function_definition: $ => seq(
            optional('export'),
            'def',
            field('func_name', choice($.identifier, $.string)),
            $.signature,
            $.block,
        ),

        alias: $ => seq(
            'alias',
            field('alias_name', $.identifier),
            '=',
            $._statement,
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
                seq('(', $.flag_shorthand_name, ')')
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
            field('cmd_name', seq($.identifier, optional('?'))),
            repeat(prec.left(9001, field('arg', $._cmd_expr))) // ITS OVER 9000
            // repeat(field('arg', $._cmd_expr)) // ITS OVER 9000
        ),

        _expression: $ => choice(
            $.command,
            $.number_literal,
            $.string,
            $.value_path,
            $.file_path, // TODO
            $._flag_arg,
            $.range,
            $.record_or_block,
            // $.operator,
            $.cmd_invocation,
            $.table,
            $.array,
            $.binary_expression,
            $.word,
        ),


        _cmd_expr: $ => choice(
            $.identifier,
            $.number_literal,
            $.string,
            $.value_path,
            $.file_path, // TODO
            $._flag_arg,
            $.range,
            $.record_or_block,
            // $.operator,
            $.cmd_invocation,
            $.table,
            $.array,
            // $.binary_expression,
            $.word,
        ),

        // TODO figure out 
        // number_literal: $ => /(0x[\da-fA-F]+|[\d]+(\.([\d]+)?)?|0b[01]+)/,
        number_literal: $ => /[\d]+(\.([\d]+)?)?/,

        word: $ => token(prec(-1, repeat1(choice(
            noneOf(...SPECIAL_CHARACTERS),
            seq('\\', noneOf('\\s'))
        )))),

        string: $ => choice(
            seq(
                '"',
                token(prec(-1, /[^"]+/)),
                '"'
            ),
            seq(
                '\'',
                token(prec(-1, /([^']|)+/)),
                '\''
            ),
            seq(
                '`',
                token(prec(-1, /[^`]+/)),
                '`'
            ),
        ),

        value_path: $ => seq(
            '$',
            $.identifier,
            repeat(seq(token.immediate('.'), $.identifier))
        ),

        file_path: $ => choice(
            // '-', //previous pwd (conflicts with operator)
            /\s[^\S\r\n]\.\.|\s\.[^\S\r\n]/, //Expect ws before .|.. and after (but exclude newline)
            /(([\w\.]+\/)*)([\w\.]+)\.\w+/, //filepath must end with <.file_ending> for now
        ),

        _flag_arg: $ => choice(
            $.flag_name,
            $.flag_shorthand_name,
        ),

        range: $ => seq(
            field('from', $.number_literal),
            '..',
            field('to', $.number_literal),
        ),

        identifier: $ => /[a-zA-Z_][a-zA-Z0-9_\-]*/,

        table: $ => seq(
            '[', $.column_header, ';', repeat($.array), ']'
        ),

        column_header: $ => seq(
            '[', optional($._expression), repeat(seq(',', $._expression)), ']'
        ),

        array: $ => seq(
            '[', optional($._expression), repeat(seq(choice(',', ' '), $._expression)), ']'
        ),

        // In LR(1) its undecidable whether `{ ident ... }` is a record or block
        // backtracking is not allowed in ts. Therefore we have a catch both rule
        record_or_block: $ => seq(
            '{',
            choice(
                // repeat1(seq(prec(50,$.identifier), ':', $._expression)),
                repeat(seq($.identifier, ':', $._expression)),
                optional($._statements)
            ),
            '}'
        ),
        record_field: $ => seq('.'),

        block: $ => seq(
            '{',
            optional($._statements),
            '}'
        ),

        comment: $ => token(prec(-10, /#.*/)),

        cmd_invocation: $ => seq(
            '(',
            $._expression,
            ')'
        ),

        operator: $ => choice(...OPERATOR_PREC.map(([operator, _]) => {
            return seq(operator)
        })),

        binary_expression: $ => {
            return choice(...OPERATOR_PREC.map(([operator, precedence]) => {
                return prec.left(precedence, seq(
                    field('left', $._expression),
                    field('operator', operator),
                    field('right', $._expression)
                ))
            }));
        },
    }
});

function noneOf(...characters) {
    const negatedString = characters.map(c => c == '\\' ? '\\\\' : c).join('')
    return new RegExp('[^' + negatedString + ']')
}
