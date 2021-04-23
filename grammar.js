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

  extras: $ => [
    $.comment
    // /\\?\s/,
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

    _statement: $ => token('rm'),

    comment: $ => token(prec(-10, /#.*/)),

    _terminator: $ => choice(';', '\n')
  }
});
