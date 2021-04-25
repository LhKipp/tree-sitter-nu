(string) @string

(cmd_name) @function

(identifier) @property

(variable_deref) @variable

(variable_declaration name: (identifier) @variable)

((identifier) @constant
 (#match? @constant "^[A-Z][A-Z\\d_]*$"))

[
 "let"
 "def"
 "it"
] @keyword

(comment) @comment

(function_definition func_name: (identifier) @function)

[
 (command_substitution)
 (math_mode)
]@embedded

[
  ; "/" Not making / an operator may lead to better highlighting?
  "$"
  "|"
  "+"
  "-"
  "*"
  "="
  "!="
  "&&"
  "||"
  "=="
  ">"
] @operator

"." @delimiter
"," @delimiter
";" @delimiter

(command (_) @constant)

(number_literal) @number
