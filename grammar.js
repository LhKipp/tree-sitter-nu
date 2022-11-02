const PREC = {
    PAREN_DECLARATOR: -10,
    // PIPE: -5,
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
    ASSIGN: 16,
};

const OPERATOR_PREC = [
    // ['|', PREC.PIPE],
    ['+', PREC.ADD],
    ['-', PREC.ADD],
    ['*', PREC.MULTIPLY],
    ['/', PREC.MULTIPLY],
    ['%', PREC.MULTIPLY],
    ['=', PREC.ASSIGN],
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
    "'", '"', '`', '@',
    '{', '}',
    '\\[', '\\]',
    '(', ')',
    '\\', '\\s',
    '$', ';', '.', '|',
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

    externals: $ => [
        $._cmd_newline
    ],

    conflicts: $ => [
        [$._cmd_expr, $.command],
        [$._cmd_expr, $._expression],
        [$.command], // TODO is this needed?
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

        _terminator: $ => choice(';', '\n', '|'),

        _statement: $ => choice(
            $.variable_declaration,
            $.env_export,
            $.function_definition,
            $.alias,
            $.if_statement,
            $._expression,
            // A record entry is not a 'real' statement, but treating it as such
            // makes life much easier
            repeat1(seq($.record_entry, optional(",")))
        ),

        record_entry: $ => seq(field("entry_name", choice($.identifier, $.string, $.value_path)), ':', $._expression),

        env_export: $ => seq(
            'export',
            'env',
            $.identifier,
            $._expression,
        ),

        if_statement: $ => seq(
            "if",
            $._cmd_expr,
            $.block,
            optional(seq("else", $.block))
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
            optional($.default_parameter_assignment),
        ),
        flag: $ => seq(
            $.flag_name,
            optional(
                seq('(', $.flag_shorthand_name, ')')
            ),
            optional(seq(':', $.type)),
            optional($.default_parameter_assignment),
        ),
        flag_name: $ => /--[a-zA-Z_]+[a-zA-Z_0-9]*/,
        flag_shorthand_name: $ => /-[a-zA-Z0-9]/,
        rest: $ => seq(
            '...rest',
            optional(seq(':', $.type)),
        ),
        type: $ => choice(
            "int",
            "float",
            "range",
            "bool",
            "string",
            "block",
            "duration",
            "date",
            "filesize",
            "number",
            "table",
            "error",
            "binary",
        ),
        default_parameter_assignment: $ => seq(
            choice(
                seq("=", $._cmd_expr),
                seq("@", $.identifier))
        ),

        variable_declaration: $ => seq(
            'let',
            choice(field('name', $.identifier), $.number_literal),
            '=',
            field('value', $._expression),
        ),

        command: $ => seq(
            field('cmd_name', seq(optional('^'), $.identifier, optional('?'))),
            repeat(field('arg', $._cmd_expr)), 
            choice($._cmd_newline, $._terminator)
            // prec(9002,$._terminator)
            // ITS OVER 9000 
            // ^- Thanks to my previous me for the meme. Had a good laugh for this random comment :)
        ),

        _expression: $ => choice(
            $.command,
            $.number_literal,
            $.string,
            $.value_path,
            $.file_path, // TODO
            $.flag_arg,
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
            $.flag_arg,
            $.range,
            $.record_or_block,
            // $.operator,
            $.cmd_invocation,
            $.table,
            $.array,
            $.binary_expression,
            $.word,
        ),

        // TODO figure out 
        // number_literal: $ => /(0x[\da-fA-F]+|[\d]+(\.([\d]+)?)?|0b[01]+)/,
        number_literal: $ => /[\d]+(\.[\d]+)?/,

        word: $ => token(prec(-1, repeat1(choice(
            noneOf(...SPECIAL_CHARACTERS),
            seq('\\', noneOf('\\s'))
        )))),

        string: $ => seq(optional('$'), choice(
            seq(
                '"',
                token(prec(-1, /[^"]*/)),
                '"'
            ),
            seq(
                '\'',
                token(prec(-1, /([^']|)*/)),
                '\''
            ),
            seq(
                '`',
                token(prec(-1, /[^`]*/)),
                '`'
            ),
        )),

        value_path: $ => seq(
            '$',
            choice($.identifier, $.number_literal),
            repeat(seq(token.immediate('.'), choice($.identifier, $.number_literal)))
        ),

        file_path: $ => choice(
            // '-', //previous pwd (conflicts with operator)
            /[^\S\r\n]\.\.|\s\.[^\S\r\n]/, //Expect ws before .|.. and after (but exclude newline)
            /(([\w\-\.~]+\/)*)([\w\-\.~]+)\.\w+/, //filepath must end with <.file_ending> for now
        ),

        flag_arg: $ =>  /-?-[a-zA-Z_]+[a-zA-Z_0-9\-]*/,

        range: $ => seq(
            field('from', choice($.number_literal, $.value_path)),
            '..',
            field('to', choice($.number_literal, $.value_path)),
        ),

        identifier: $ => /[a-zA-Z_][a-zA-Z0-9_\-]*/,

        table: $ => seq(
            '[', $.array, ';', repeat($.array), ']'
        ),

        array: $ => seq(
            '[', repeat(seq($._expression, optional(','))), ']'
        ),

        // In LR(1) its undecidable whether `{ ident ... }` is a record or block
        // backtracking is not allowed in ts. Therefore we have a catch both rule
        record_or_block: $ => seq(
            '{',
            optional($.block_args),
            optional($._statements),
            '}'
        ),

        block: $ => seq(
            '{',
            optional($.block_args),
            optional($._statements),
            '}'
        ),

        block_args: $ => seq(
            '|',
            repeat(seq(field("block_param", $.identifier), optional(','))),
            '|',
        ),

        comment: $ => token(prec(-10, /#.*/)),

        cmd_invocation: $ => seq(
            '(',
            $._statements,
            ')',
            repeat(seq(token.immediate('.'), choice($.identifier, $.number_literal)))
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
