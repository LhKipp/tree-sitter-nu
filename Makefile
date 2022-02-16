fmt:
	js-beautify -r  grammar.js

test:
	tree-sitter generate && tree-sitter test
