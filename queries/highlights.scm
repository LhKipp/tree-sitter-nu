(string) @string

(command cmd_name: (identifier) @function)

(identifier) @property

(value_path) @variable

(variable_declaration name: (identifier) @variable)

((identifier) @constant
 (#match? @constant "^[A-Z][A-Z\\d_]*$"))

[
 "let"
 "def"
] @keyword

(comment) @comment

(function_definition func_name: (identifier) @function)

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
(range from: (number_literal) @number)
(range to: (number_literal) @number)

(type) @type
