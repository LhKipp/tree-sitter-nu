#include <tree_sitter/parser.h>
#include <wctype.h>

enum TokenType {
    _CMD_NEWLINE
};

void *tree_sitter_nu_external_scanner_create() { return NULL; }
void tree_sitter_nu_external_scanner_destroy(void *p) {}
void tree_sitter_nu_external_scanner_reset(void *p) {}
unsigned tree_sitter_nu_external_scanner_serialize(void *p, char *buffer) { return 0; }
void tree_sitter_nu_external_scanner_deserialize(void *p, const char *b, unsigned n) {}

bool tree_sitter_nu_external_scanner_scan(
    void *payload, TSLexer *lexer, const bool *valid_symbols
) {
    while (lexer->lookahead == ' ') {lexer->advance(lexer, true);}
    if (valid_symbols[_CMD_NEWLINE]) {
        if (lexer->lookahead == 0 
            || lexer->lookahead == '}'  
            || lexer->lookahead == ')' 
            || lexer->lookahead == '\n'
            || lexer->lookahead == '\r' // \r\n for windows newlines
            ){
            lexer->result_symbol = _CMD_NEWLINE;
            return true;
        }
    }
    return false;
}
