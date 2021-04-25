#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 187
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 89
#define ALIAS_COUNT 0
#define TOKEN_COUNT 56
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 6
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 4

enum {
  anon_sym_def = 1,
  anon_sym_LBRACK = 2,
  anon_sym_COMMA = 3,
  anon_sym_RBRACK = 4,
  anon_sym_COLON = 5,
  anon_sym_QMARK = 6,
  anon_sym_LPAREN = 7,
  anon_sym_RPAREN = 8,
  sym_flag_name = 9,
  sym_flag_shorthand_name = 10,
  anon_sym_DOT_DOT_DOTrest = 11,
  anon_sym_int = 12,
  anon_sym_string = 13,
  anon_sym_path = 14,
  anon_sym_table = 15,
  anon_sym_unit = 16,
  anon_sym_number = 17,
  anon_sym_pattern = 18,
  anon_sym_range = 19,
  anon_sym_block = 20,
  anon_sym_any = 21,
  anon_sym_let = 22,
  anon_sym_EQ = 23,
  sym_cmd_name = 24,
  anon_sym_PIPE = 25,
  sym_number_literal = 26,
  sym_word = 27,
  anon_sym_DQUOTE = 28,
  anon_sym_SQUOTE = 29,
  sym_qouted_string_content = 30,
  sym_single_qouted_string_content = 31,
  anon_sym_DOT = 32,
  anon_sym_DOLLAR = 33,
  anon_sym_DOLLAR_LPAREN = 34,
  sym_identifier = 35,
  anon_sym_SEMI = 36,
  anon_sym_LBRACE = 37,
  anon_sym_RBRACE = 38,
  sym_comment = 39,
  anon_sym_LF = 40,
  anon_sym_PLUS = 41,
  anon_sym_DASH = 42,
  anon_sym_STAR = 43,
  anon_sym_SLASH = 44,
  anon_sym_PERCENT = 45,
  anon_sym_PIPE_PIPE = 46,
  anon_sym_AMP_AMP = 47,
  anon_sym_EQ_EQ = 48,
  anon_sym_BANG_EQ = 49,
  anon_sym_GT = 50,
  anon_sym_GT_EQ = 51,
  anon_sym_LT_EQ = 52,
  anon_sym_LT = 53,
  anon_sym_LT_LT = 54,
  anon_sym_GT_GT = 55,
  sym_source_file = 56,
  sym__statements = 57,
  sym__statement = 58,
  sym_function_definition = 59,
  sym_signature = 60,
  sym_parameter = 61,
  sym_flag = 62,
  sym_type = 63,
  sym_variable_declaration = 64,
  sym_command = 65,
  sym_pipeline = 66,
  sym__literal = 67,
  sym__primary_expression = 68,
  sym_string = 69,
  sym_value_path = 70,
  sym_variable_deref = 71,
  sym_command_substitution = 72,
  sym_math_mode = 73,
  sym_table = 74,
  sym_column_header = 75,
  sym_array = 76,
  sym_block = 77,
  sym__terminator = 78,
  sym__math_expression = 79,
  sym_parenthesized_math_expression = 80,
  sym_binary_expression = 81,
  aux_sym__statements_repeat1 = 82,
  aux_sym_signature_repeat1 = 83,
  aux_sym_command_repeat1 = 84,
  aux_sym_string_repeat1 = 85,
  aux_sym_string_repeat2 = 86,
  aux_sym_table_repeat1 = 87,
  aux_sym_column_header_repeat1 = 88,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_def] = "def",
  [anon_sym_LBRACK] = "[",
  [anon_sym_COMMA] = ",",
  [anon_sym_RBRACK] = "]",
  [anon_sym_COLON] = ":",
  [anon_sym_QMARK] = "\?",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [sym_flag_name] = "flag_name",
  [sym_flag_shorthand_name] = "flag_shorthand_name",
  [anon_sym_DOT_DOT_DOTrest] = "...rest",
  [anon_sym_int] = "int",
  [anon_sym_string] = "string",
  [anon_sym_path] = "path",
  [anon_sym_table] = "table",
  [anon_sym_unit] = "unit",
  [anon_sym_number] = "number",
  [anon_sym_pattern] = "pattern",
  [anon_sym_range] = "range",
  [anon_sym_block] = "block",
  [anon_sym_any] = "any",
  [anon_sym_let] = "let",
  [anon_sym_EQ] = "=",
  [sym_cmd_name] = "cmd_name",
  [anon_sym_PIPE] = "|",
  [sym_number_literal] = "number_literal",
  [sym_word] = "word",
  [anon_sym_DQUOTE] = "\"",
  [anon_sym_SQUOTE] = "'",
  [sym_qouted_string_content] = "qouted_string_content",
  [sym_single_qouted_string_content] = "single_qouted_string_content",
  [anon_sym_DOT] = ".",
  [anon_sym_DOLLAR] = "$",
  [anon_sym_DOLLAR_LPAREN] = "$(",
  [sym_identifier] = "identifier",
  [anon_sym_SEMI] = ";",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [sym_comment] = "comment",
  [anon_sym_LF] = "\n",
  [anon_sym_PLUS] = "+",
  [anon_sym_DASH] = "-",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_PERCENT] = "%",
  [anon_sym_PIPE_PIPE] = "||",
  [anon_sym_AMP_AMP] = "&&",
  [anon_sym_EQ_EQ] = "==",
  [anon_sym_BANG_EQ] = "!=",
  [anon_sym_GT] = ">",
  [anon_sym_GT_EQ] = ">=",
  [anon_sym_LT_EQ] = "<=",
  [anon_sym_LT] = "<",
  [anon_sym_LT_LT] = "<<",
  [anon_sym_GT_GT] = ">>",
  [sym_source_file] = "source_file",
  [sym__statements] = "_statements",
  [sym__statement] = "_statement",
  [sym_function_definition] = "function_definition",
  [sym_signature] = "signature",
  [sym_parameter] = "parameter",
  [sym_flag] = "flag",
  [sym_type] = "type",
  [sym_variable_declaration] = "variable_declaration",
  [sym_command] = "command",
  [sym_pipeline] = "pipeline",
  [sym__literal] = "_literal",
  [sym__primary_expression] = "_primary_expression",
  [sym_string] = "string",
  [sym_value_path] = "value_path",
  [sym_variable_deref] = "variable_deref",
  [sym_command_substitution] = "command_substitution",
  [sym_math_mode] = "math_mode",
  [sym_table] = "table",
  [sym_column_header] = "column_header",
  [sym_array] = "array",
  [sym_block] = "block",
  [sym__terminator] = "_terminator",
  [sym__math_expression] = "_math_expression",
  [sym_parenthesized_math_expression] = "parenthesized_math_expression",
  [sym_binary_expression] = "binary_expression",
  [aux_sym__statements_repeat1] = "_statements_repeat1",
  [aux_sym_signature_repeat1] = "signature_repeat1",
  [aux_sym_command_repeat1] = "command_repeat1",
  [aux_sym_string_repeat1] = "string_repeat1",
  [aux_sym_string_repeat2] = "string_repeat2",
  [aux_sym_table_repeat1] = "table_repeat1",
  [aux_sym_column_header_repeat1] = "column_header_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_def] = anon_sym_def,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_QMARK] = anon_sym_QMARK,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [sym_flag_name] = sym_flag_name,
  [sym_flag_shorthand_name] = sym_flag_shorthand_name,
  [anon_sym_DOT_DOT_DOTrest] = anon_sym_DOT_DOT_DOTrest,
  [anon_sym_int] = anon_sym_int,
  [anon_sym_string] = anon_sym_string,
  [anon_sym_path] = anon_sym_path,
  [anon_sym_table] = anon_sym_table,
  [anon_sym_unit] = anon_sym_unit,
  [anon_sym_number] = anon_sym_number,
  [anon_sym_pattern] = anon_sym_pattern,
  [anon_sym_range] = anon_sym_range,
  [anon_sym_block] = anon_sym_block,
  [anon_sym_any] = anon_sym_any,
  [anon_sym_let] = anon_sym_let,
  [anon_sym_EQ] = anon_sym_EQ,
  [sym_cmd_name] = sym_cmd_name,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [sym_number_literal] = sym_number_literal,
  [sym_word] = sym_word,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [sym_qouted_string_content] = sym_qouted_string_content,
  [sym_single_qouted_string_content] = sym_single_qouted_string_content,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_DOLLAR] = anon_sym_DOLLAR,
  [anon_sym_DOLLAR_LPAREN] = anon_sym_DOLLAR_LPAREN,
  [sym_identifier] = sym_identifier,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [sym_comment] = sym_comment,
  [anon_sym_LF] = anon_sym_LF,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [anon_sym_PIPE_PIPE] = anon_sym_PIPE_PIPE,
  [anon_sym_AMP_AMP] = anon_sym_AMP_AMP,
  [anon_sym_EQ_EQ] = anon_sym_EQ_EQ,
  [anon_sym_BANG_EQ] = anon_sym_BANG_EQ,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_GT_EQ] = anon_sym_GT_EQ,
  [anon_sym_LT_EQ] = anon_sym_LT_EQ,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_LT_LT] = anon_sym_LT_LT,
  [anon_sym_GT_GT] = anon_sym_GT_GT,
  [sym_source_file] = sym_source_file,
  [sym__statements] = sym__statements,
  [sym__statement] = sym__statement,
  [sym_function_definition] = sym_function_definition,
  [sym_signature] = sym_signature,
  [sym_parameter] = sym_parameter,
  [sym_flag] = sym_flag,
  [sym_type] = sym_type,
  [sym_variable_declaration] = sym_variable_declaration,
  [sym_command] = sym_command,
  [sym_pipeline] = sym_pipeline,
  [sym__literal] = sym__literal,
  [sym__primary_expression] = sym__primary_expression,
  [sym_string] = sym_string,
  [sym_value_path] = sym_value_path,
  [sym_variable_deref] = sym_variable_deref,
  [sym_command_substitution] = sym_command_substitution,
  [sym_math_mode] = sym_math_mode,
  [sym_table] = sym_table,
  [sym_column_header] = sym_column_header,
  [sym_array] = sym_array,
  [sym_block] = sym_block,
  [sym__terminator] = sym__terminator,
  [sym__math_expression] = sym__math_expression,
  [sym_parenthesized_math_expression] = sym_parenthesized_math_expression,
  [sym_binary_expression] = sym_binary_expression,
  [aux_sym__statements_repeat1] = aux_sym__statements_repeat1,
  [aux_sym_signature_repeat1] = aux_sym_signature_repeat1,
  [aux_sym_command_repeat1] = aux_sym_command_repeat1,
  [aux_sym_string_repeat1] = aux_sym_string_repeat1,
  [aux_sym_string_repeat2] = aux_sym_string_repeat2,
  [aux_sym_table_repeat1] = aux_sym_table_repeat1,
  [aux_sym_column_header_repeat1] = aux_sym_column_header_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_def] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_QMARK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [sym_flag_name] = {
    .visible = true,
    .named = true,
  },
  [sym_flag_shorthand_name] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DOT_DOT_DOTrest] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_int] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_string] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_path] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_table] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_unit] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_number] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pattern] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_range] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_block] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_any] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_let] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [sym_cmd_name] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [sym_number_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_word] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [sym_qouted_string_content] = {
    .visible = true,
    .named = true,
  },
  [sym_single_qouted_string_content] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOLLAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOLLAR_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_GT] = {
    .visible = true,
    .named = false,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__statements] = {
    .visible = false,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym_function_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_signature] = {
    .visible = true,
    .named = true,
  },
  [sym_parameter] = {
    .visible = true,
    .named = true,
  },
  [sym_flag] = {
    .visible = true,
    .named = true,
  },
  [sym_type] = {
    .visible = true,
    .named = true,
  },
  [sym_variable_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_command] = {
    .visible = true,
    .named = true,
  },
  [sym_pipeline] = {
    .visible = true,
    .named = true,
  },
  [sym__literal] = {
    .visible = false,
    .named = true,
  },
  [sym__primary_expression] = {
    .visible = false,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym_value_path] = {
    .visible = true,
    .named = true,
  },
  [sym_variable_deref] = {
    .visible = true,
    .named = true,
  },
  [sym_command_substitution] = {
    .visible = true,
    .named = true,
  },
  [sym_math_mode] = {
    .visible = true,
    .named = true,
  },
  [sym_table] = {
    .visible = true,
    .named = true,
  },
  [sym_column_header] = {
    .visible = true,
    .named = true,
  },
  [sym_array] = {
    .visible = true,
    .named = true,
  },
  [sym_block] = {
    .visible = true,
    .named = true,
  },
  [sym__terminator] = {
    .visible = false,
    .named = true,
  },
  [sym__math_expression] = {
    .visible = false,
    .named = true,
  },
  [sym_parenthesized_math_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_binary_expression] = {
    .visible = true,
    .named = true,
  },
  [aux_sym__statements_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_signature_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_command_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_table_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_column_header_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_func_name = 1,
  field_left = 2,
  field_name = 3,
  field_operator = 4,
  field_right = 5,
  field_value = 6,
};

static const char *ts_field_names[] = {
  [0] = NULL,
  [field_func_name] = "func_name",
  [field_left] = "left",
  [field_name] = "name",
  [field_operator] = "operator",
  [field_right] = "right",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 3},
  [2] = {.index = 3, .length = 1},
  [3] = {.index = 4, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_left, 0},
    {field_operator, 1},
    {field_right, 2},
  [3] =
    {field_func_name, 1},
  [4] =
    {field_name, 1},
    {field_value, 3},
};

static TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static inline bool sym_word_character_set_1(int32_t c) {
  return (c < '&'
    ? (c < '\r'
      ? (c < '\t'
        ? c == 0
        : c <= '\n')
      : (c <= '\r' || (c < '"'
        ? c == ' '
        : c <= '$')))
    : (c <= ')' || (c < '['
      ? (c < '>'
        ? (c >= ';' && c <= '<')
        : c <= '>')
      : (c <= ']' || (c < '{'
        ? c == '`'
        : c <= '}')))));
}

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(70);
      if (lookahead == '!') ADVANCE(10);
      if (lookahead == '"') ADVANCE(118);
      if (lookahead == '#') ADVANCE(138);
      if (lookahead == '$') ADVANCE(129);
      if (lookahead == '%') ADVANCE(145);
      if (lookahead == '&') ADVANCE(6);
      if (lookahead == '\'') ADVANCE(119);
      if (lookahead == '(') ADVANCE(78);
      if (lookahead == ')') ADVANCE(79);
      if (lookahead == '*') ADVANCE(143);
      if (lookahead == '+') ADVANCE(140);
      if (lookahead == ',') ADVANCE(74);
      if (lookahead == '-') ADVANCE(142);
      if (lookahead == '.') ADVANCE(127);
      if (lookahead == '/') ADVANCE(144);
      if (lookahead == '0') ADVANCE(105);
      if (lookahead == ':') ADVANCE(76);
      if (lookahead == ';') ADVANCE(133);
      if (lookahead == '<') ADVANCE(153);
      if (lookahead == '=') ADVANCE(96);
      if (lookahead == '>') ADVANCE(150);
      if (lookahead == '?') ADVANCE(77);
      if (lookahead == '[') ADVANCE(73);
      if (lookahead == ']') ADVANCE(75);
      if (lookahead == 'a') ADVANCE(35);
      if (lookahead == 'b') ADVANCE(32);
      if (lookahead == 'd') ADVANCE(18);
      if (lookahead == 'i') ADVANCE(39);
      if (lookahead == 'l') ADVANCE(22);
      if (lookahead == 'n') ADVANCE(53);
      if (lookahead == 'p') ADVANCE(14);
      if (lookahead == 'r') ADVANCE(13);
      if (lookahead == 's') ADVANCE(47);
      if (lookahead == 't') ADVANCE(12);
      if (lookahead == 'u') ADVANCE(36);
      if (lookahead == '{') ADVANCE(134);
      if (lookahead == '|') ADVANCE(104);
      if (lookahead == '}') ADVANCE(135);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(68)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(106);
      END_STATE();
    case 1:
      if (lookahead == '!') ADVANCE(10);
      if (lookahead == '"') ADVANCE(118);
      if (lookahead == '#') ADVANCE(138);
      if (lookahead == '%') ADVANCE(145);
      if (lookahead == '&') ADVANCE(6);
      if (lookahead == '\'') ADVANCE(119);
      if (lookahead == ')') ADVANCE(79);
      if (lookahead == '*') ADVANCE(143);
      if (lookahead == '+') ADVANCE(140);
      if (lookahead == '-') ADVANCE(141);
      if (lookahead == '/') ADVANCE(144);
      if (lookahead == '<') ADVANCE(153);
      if (lookahead == '=') ADVANCE(11);
      if (lookahead == '>') ADVANCE(150);
      if (lookahead == '[') ADVANCE(73);
      if (lookahead == ']') ADVANCE(75);
      if (lookahead == '|') ADVANCE(55);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(131);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(118);
      if (lookahead == '#') ADVANCE(138);
      if (lookahead == '$') ADVANCE(129);
      if (lookahead == '\'') ADVANCE(119);
      if (lookahead == '0') ADVANCE(107);
      if (lookahead == '[') ADVANCE(73);
      if (lookahead == '\\') ADVANCE(61);
      if (lookahead == '{') ADVANCE(134);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(108);
      if (lookahead != 0 &&
          (lookahead < '&' || ')' < lookahead) &&
          lookahead != ';' &&
          lookahead != '<' &&
          lookahead != '>' &&
          lookahead != ']' &&
          lookahead != '`' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(117);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(118);
      if (lookahead == '#') ADVANCE(120);
      if (lookahead == '\\') ADVANCE(62);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(121);
      if (lookahead != 0) ADVANCE(122);
      END_STATE();
    case 4:
      if (lookahead == '#') ADVANCE(138);
      if (lookahead == '(') ADVANCE(78);
      if (lookahead == ',') ADVANCE(74);
      if (lookahead == '-') ADVANCE(7);
      if (lookahead == ':') ADVANCE(76);
      if (lookahead == '?') ADVANCE(77);
      if (lookahead == ']') ADVANCE(75);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(131);
      END_STATE();
    case 5:
      if (lookahead == '#') ADVANCE(123);
      if (lookahead == '\'') ADVANCE(119);
      if (lookahead == '\\') ADVANCE(63);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(124);
      if (lookahead != 0) ADVANCE(125);
      END_STATE();
    case 6:
      if (lookahead == '&') ADVANCE(147);
      END_STATE();
    case 7:
      if (lookahead == '-') ADVANCE(58);
      END_STATE();
    case 8:
      if (lookahead == '.') ADVANCE(9);
      END_STATE();
    case 9:
      if (lookahead == '.') ADVANCE(44);
      END_STATE();
    case 10:
      if (lookahead == '=') ADVANCE(149);
      END_STATE();
    case 11:
      if (lookahead == '=') ADVANCE(148);
      END_STATE();
    case 12:
      if (lookahead == 'a') ADVANCE(15);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(37);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(50);
      END_STATE();
    case 15:
      if (lookahead == 'b') ADVANCE(33);
      END_STATE();
    case 16:
      if (lookahead == 'b') ADVANCE(23);
      END_STATE();
    case 17:
      if (lookahead == 'c') ADVANCE(31);
      END_STATE();
    case 18:
      if (lookahead == 'e') ADVANCE(25);
      END_STATE();
    case 19:
      if (lookahead == 'e') ADVANCE(46);
      END_STATE();
    case 20:
      if (lookahead == 'e') ADVANCE(91);
      END_STATE();
    case 21:
      if (lookahead == 'e') ADVANCE(87);
      END_STATE();
    case 22:
      if (lookahead == 'e') ADVANCE(49);
      END_STATE();
    case 23:
      if (lookahead == 'e') ADVANCE(42);
      END_STATE();
    case 24:
      if (lookahead == 'e') ADVANCE(45);
      END_STATE();
    case 25:
      if (lookahead == 'f') ADVANCE(71);
      END_STATE();
    case 26:
      if (lookahead == 'g') ADVANCE(85);
      END_STATE();
    case 27:
      if (lookahead == 'g') ADVANCE(20);
      END_STATE();
    case 28:
      if (lookahead == 'h') ADVANCE(86);
      if (lookahead == 't') ADVANCE(24);
      END_STATE();
    case 29:
      if (lookahead == 'i') ADVANCE(40);
      END_STATE();
    case 30:
      if (lookahead == 'i') ADVANCE(51);
      END_STATE();
    case 31:
      if (lookahead == 'k') ADVANCE(92);
      END_STATE();
    case 32:
      if (lookahead == 'l') ADVANCE(41);
      END_STATE();
    case 33:
      if (lookahead == 'l') ADVANCE(21);
      END_STATE();
    case 34:
      if (lookahead == 'm') ADVANCE(16);
      END_STATE();
    case 35:
      if (lookahead == 'n') ADVANCE(54);
      END_STATE();
    case 36:
      if (lookahead == 'n') ADVANCE(30);
      END_STATE();
    case 37:
      if (lookahead == 'n') ADVANCE(27);
      END_STATE();
    case 38:
      if (lookahead == 'n') ADVANCE(90);
      END_STATE();
    case 39:
      if (lookahead == 'n') ADVANCE(48);
      END_STATE();
    case 40:
      if (lookahead == 'n') ADVANCE(26);
      END_STATE();
    case 41:
      if (lookahead == 'o') ADVANCE(17);
      END_STATE();
    case 42:
      if (lookahead == 'r') ADVANCE(89);
      END_STATE();
    case 43:
      if (lookahead == 'r') ADVANCE(29);
      END_STATE();
    case 44:
      if (lookahead == 'r') ADVANCE(19);
      END_STATE();
    case 45:
      if (lookahead == 'r') ADVANCE(38);
      END_STATE();
    case 46:
      if (lookahead == 's') ADVANCE(52);
      END_STATE();
    case 47:
      if (lookahead == 't') ADVANCE(43);
      END_STATE();
    case 48:
      if (lookahead == 't') ADVANCE(84);
      END_STATE();
    case 49:
      if (lookahead == 't') ADVANCE(94);
      END_STATE();
    case 50:
      if (lookahead == 't') ADVANCE(28);
      END_STATE();
    case 51:
      if (lookahead == 't') ADVANCE(88);
      END_STATE();
    case 52:
      if (lookahead == 't') ADVANCE(83);
      END_STATE();
    case 53:
      if (lookahead == 'u') ADVANCE(34);
      END_STATE();
    case 54:
      if (lookahead == 'y') ADVANCE(93);
      END_STATE();
    case 55:
      if (lookahead == '|') ADVANCE(146);
      END_STATE();
    case 56:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(112);
      END_STATE();
    case 57:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(114);
      END_STATE();
    case 58:
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 59:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(82);
      END_STATE();
    case 60:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 61:
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(117);
      END_STATE();
    case 62:
      if (lookahead != 0) ADVANCE(122);
      END_STATE();
    case 63:
      if (lookahead != 0) ADVANCE(125);
      END_STATE();
    case 64:
      if (eof) ADVANCE(70);
      if (lookahead == '\n') ADVANCE(139);
      if (lookahead == '!') ADVANCE(10);
      if (lookahead == '#') ADVANCE(138);
      if (lookahead == '%') ADVANCE(145);
      if (lookahead == '&') ADVANCE(6);
      if (lookahead == ')') ADVANCE(79);
      if (lookahead == '*') ADVANCE(143);
      if (lookahead == '+') ADVANCE(140);
      if (lookahead == '-') ADVANCE(141);
      if (lookahead == '.') ADVANCE(126);
      if (lookahead == '/') ADVANCE(144);
      if (lookahead == ';') ADVANCE(133);
      if (lookahead == '<') ADVANCE(153);
      if (lookahead == '=') ADVANCE(11);
      if (lookahead == '>') ADVANCE(150);
      if (lookahead == '|') ADVANCE(104);
      if (lookahead == '}') ADVANCE(135);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(65)
      END_STATE();
    case 65:
      if (eof) ADVANCE(70);
      if (lookahead == '\n') ADVANCE(139);
      if (lookahead == '!') ADVANCE(10);
      if (lookahead == '#') ADVANCE(138);
      if (lookahead == '%') ADVANCE(145);
      if (lookahead == '&') ADVANCE(6);
      if (lookahead == ')') ADVANCE(79);
      if (lookahead == '*') ADVANCE(143);
      if (lookahead == '+') ADVANCE(140);
      if (lookahead == '-') ADVANCE(141);
      if (lookahead == '/') ADVANCE(144);
      if (lookahead == ';') ADVANCE(133);
      if (lookahead == '<') ADVANCE(153);
      if (lookahead == '=') ADVANCE(11);
      if (lookahead == '>') ADVANCE(150);
      if (lookahead == '|') ADVANCE(104);
      if (lookahead == '}') ADVANCE(135);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(65)
      END_STATE();
    case 66:
      if (eof) ADVANCE(70);
      if (lookahead == '\n') ADVANCE(139);
      if (lookahead == '"') ADVANCE(118);
      if (lookahead == '#') ADVANCE(138);
      if (lookahead == '$') ADVANCE(129);
      if (lookahead == '\'') ADVANCE(119);
      if (lookahead == ')') ADVANCE(79);
      if (lookahead == '.') ADVANCE(128);
      if (lookahead == '0') ADVANCE(107);
      if (lookahead == ';') ADVANCE(133);
      if (lookahead == '[') ADVANCE(73);
      if (lookahead == '\\') ADVANCE(61);
      if (lookahead == '{') ADVANCE(134);
      if (lookahead == '|') ADVANCE(103);
      if (lookahead == '}') ADVANCE(135);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(67)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(108);
      if (lookahead != 0 &&
          (lookahead < '&' || '(' < lookahead) &&
          lookahead != '<' &&
          lookahead != '>' &&
          lookahead != ']' &&
          lookahead != '`') ADVANCE(117);
      END_STATE();
    case 67:
      if (eof) ADVANCE(70);
      if (lookahead == '\n') ADVANCE(139);
      if (lookahead == '"') ADVANCE(118);
      if (lookahead == '#') ADVANCE(138);
      if (lookahead == '$') ADVANCE(129);
      if (lookahead == '\'') ADVANCE(119);
      if (lookahead == ')') ADVANCE(79);
      if (lookahead == '0') ADVANCE(107);
      if (lookahead == ';') ADVANCE(133);
      if (lookahead == '[') ADVANCE(73);
      if (lookahead == '\\') ADVANCE(61);
      if (lookahead == '{') ADVANCE(134);
      if (lookahead == '|') ADVANCE(103);
      if (lookahead == '}') ADVANCE(135);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(67)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(108);
      if (lookahead != 0 &&
          (lookahead < '&' || '(' < lookahead) &&
          lookahead != '<' &&
          lookahead != '>' &&
          lookahead != ']' &&
          lookahead != '`') ADVANCE(117);
      END_STATE();
    case 68:
      if (eof) ADVANCE(70);
      if (lookahead == '!') ADVANCE(10);
      if (lookahead == '"') ADVANCE(118);
      if (lookahead == '#') ADVANCE(138);
      if (lookahead == '$') ADVANCE(129);
      if (lookahead == '%') ADVANCE(145);
      if (lookahead == '&') ADVANCE(6);
      if (lookahead == '\'') ADVANCE(119);
      if (lookahead == '(') ADVANCE(78);
      if (lookahead == ')') ADVANCE(79);
      if (lookahead == '*') ADVANCE(143);
      if (lookahead == '+') ADVANCE(140);
      if (lookahead == ',') ADVANCE(74);
      if (lookahead == '-') ADVANCE(142);
      if (lookahead == '.') ADVANCE(8);
      if (lookahead == '/') ADVANCE(144);
      if (lookahead == '0') ADVANCE(105);
      if (lookahead == ':') ADVANCE(76);
      if (lookahead == ';') ADVANCE(133);
      if (lookahead == '<') ADVANCE(153);
      if (lookahead == '=') ADVANCE(96);
      if (lookahead == '>') ADVANCE(150);
      if (lookahead == '?') ADVANCE(77);
      if (lookahead == '[') ADVANCE(73);
      if (lookahead == ']') ADVANCE(75);
      if (lookahead == 'a') ADVANCE(35);
      if (lookahead == 'b') ADVANCE(32);
      if (lookahead == 'd') ADVANCE(18);
      if (lookahead == 'i') ADVANCE(39);
      if (lookahead == 'l') ADVANCE(22);
      if (lookahead == 'n') ADVANCE(53);
      if (lookahead == 'p') ADVANCE(14);
      if (lookahead == 'r') ADVANCE(13);
      if (lookahead == 's') ADVANCE(47);
      if (lookahead == 't') ADVANCE(12);
      if (lookahead == 'u') ADVANCE(36);
      if (lookahead == '{') ADVANCE(134);
      if (lookahead == '|') ADVANCE(104);
      if (lookahead == '}') ADVANCE(135);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(68)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(106);
      END_STATE();
    case 69:
      if (eof) ADVANCE(70);
      if (lookahead == '#') ADVANCE(138);
      if (lookahead == '$') ADVANCE(129);
      if (lookahead == '(') ADVANCE(78);
      if (lookahead == ')') ADVANCE(79);
      if (lookahead == '-') ADVANCE(59);
      if (lookahead == '0') ADVANCE(105);
      if (lookahead == '=') ADVANCE(96);
      if (lookahead == 'd') ADVANCE(97);
      if (lookahead == 'l') ADVANCE(98);
      if (lookahead == '{') ADVANCE(134);
      if (lookahead == '}') ADVANCE(135);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(69)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(106);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_def);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_def);
      if (lookahead == '-') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(102);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_QMARK);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_flag_name);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(81);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(80);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_flag_name);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_flag_shorthand_name);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_DOT_DOT_DOTrest);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_int);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_string);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_path);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_table);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_unit);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_number);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_pattern);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_range);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(anon_sym_block);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(anon_sym_any);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_let);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_let);
      if (lookahead == '-') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(102);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym_cmd_name);
      if (lookahead == '-') ADVANCE(60);
      if (lookahead == 'e') ADVANCE(99);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(102);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym_cmd_name);
      if (lookahead == '-') ADVANCE(60);
      if (lookahead == 'e') ADVANCE(100);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(102);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym_cmd_name);
      if (lookahead == '-') ADVANCE(60);
      if (lookahead == 'f') ADVANCE(72);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(102);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym_cmd_name);
      if (lookahead == '-') ADVANCE(60);
      if (lookahead == 't') ADVANCE(95);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(102);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym_cmd_name);
      if (lookahead == '-') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(102);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(101);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym_cmd_name);
      if (lookahead == '-') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '|') ADVANCE(146);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym_number_literal);
      if (lookahead == '.') ADVANCE(113);
      if (lookahead == 'b') ADVANCE(56);
      if (lookahead == 'x') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(106);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_number_literal);
      if (lookahead == '.') ADVANCE(113);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(106);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym_number_literal);
      if (lookahead == '.') ADVANCE(110);
      if (lookahead == '\\') ADVANCE(61);
      if (lookahead == 'b') ADVANCE(115);
      if (lookahead == 'x') ADVANCE(116);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(108);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(117);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(sym_number_literal);
      if (lookahead == '.') ADVANCE(110);
      if (lookahead == '\\') ADVANCE(61);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(108);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(117);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym_number_literal);
      if (lookahead == '\\') ADVANCE(61);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(109);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(117);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym_number_literal);
      if (lookahead == '\\') ADVANCE(61);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(110);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(117);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym_number_literal);
      if (lookahead == '\\') ADVANCE(61);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(111);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(117);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_number_literal);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(112);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym_number_literal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(113);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym_number_literal);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(114);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(61);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(109);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(117);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(61);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(111);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(117);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(61);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(117);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_qouted_string_content);
      if (lookahead == '\n') ADVANCE(122);
      if (lookahead == '\\') ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(120);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_qouted_string_content);
      if (lookahead == '"') ADVANCE(118);
      if (lookahead == '#') ADVANCE(120);
      if (lookahead == '\\') ADVANCE(62);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(121);
      if (lookahead != 0) ADVANCE(122);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_qouted_string_content);
      if (lookahead == '\\') ADVANCE(62);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(122);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_single_qouted_string_content);
      if (lookahead == '\n') ADVANCE(125);
      if (lookahead == '\\') ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(123);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym_single_qouted_string_content);
      if (lookahead == '#') ADVANCE(123);
      if (lookahead == '\'') ADVANCE(119);
      if (lookahead == '\\') ADVANCE(63);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(124);
      if (lookahead != 0) ADVANCE(125);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym_single_qouted_string_content);
      if (lookahead == '\\') ADVANCE(63);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(125);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_DOT);
      if (lookahead == '.') ADVANCE(9);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_DOT);
      if (lookahead == '\\') ADVANCE(61);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(117);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      if (lookahead == '(') ADVANCE(130);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_DOLLAR_LPAREN);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(132);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(131);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(132);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead == '\n') ADVANCE(122);
      if (lookahead != 0) ADVANCE(120);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead == '\n') ADVANCE(125);
      if (lookahead != 0) ADVANCE(123);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(138);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(139);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '-') ADVANCE(58);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(anon_sym_BANG_EQ);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(151);
      if (lookahead == '>') ADVANCE(155);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '<') ADVANCE(154);
      if (lookahead == '=') ADVANCE(152);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(anon_sym_LT_LT);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(anon_sym_GT_GT);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 69},
  [2] = {.lex_state = 67},
  [3] = {.lex_state = 67},
  [4] = {.lex_state = 67},
  [5] = {.lex_state = 69},
  [6] = {.lex_state = 67},
  [7] = {.lex_state = 69},
  [8] = {.lex_state = 67},
  [9] = {.lex_state = 69},
  [10] = {.lex_state = 69},
  [11] = {.lex_state = 69},
  [12] = {.lex_state = 69},
  [13] = {.lex_state = 67},
  [14] = {.lex_state = 64},
  [15] = {.lex_state = 64},
  [16] = {.lex_state = 64},
  [17] = {.lex_state = 69},
  [18] = {.lex_state = 64},
  [19] = {.lex_state = 64},
  [20] = {.lex_state = 64},
  [21] = {.lex_state = 64},
  [22] = {.lex_state = 64},
  [23] = {.lex_state = 69},
  [24] = {.lex_state = 69},
  [25] = {.lex_state = 64},
  [26] = {.lex_state = 64},
  [27] = {.lex_state = 64},
  [28] = {.lex_state = 64},
  [29] = {.lex_state = 69},
  [30] = {.lex_state = 69},
  [31] = {.lex_state = 2},
  [32] = {.lex_state = 1},
  [33] = {.lex_state = 1},
  [34] = {.lex_state = 1},
  [35] = {.lex_state = 1},
  [36] = {.lex_state = 1},
  [37] = {.lex_state = 1},
  [38] = {.lex_state = 1},
  [39] = {.lex_state = 1},
  [40] = {.lex_state = 1},
  [41] = {.lex_state = 1},
  [42] = {.lex_state = 1},
  [43] = {.lex_state = 1},
  [44] = {.lex_state = 1},
  [45] = {.lex_state = 1},
  [46] = {.lex_state = 1},
  [47] = {.lex_state = 1},
  [48] = {.lex_state = 1},
  [49] = {.lex_state = 67},
  [50] = {.lex_state = 67},
  [51] = {.lex_state = 67},
  [52] = {.lex_state = 66},
  [53] = {.lex_state = 67},
  [54] = {.lex_state = 67},
  [55] = {.lex_state = 67},
  [56] = {.lex_state = 67},
  [57] = {.lex_state = 67},
  [58] = {.lex_state = 67},
  [59] = {.lex_state = 66},
  [60] = {.lex_state = 67},
  [61] = {.lex_state = 67},
  [62] = {.lex_state = 67},
  [63] = {.lex_state = 67},
  [64] = {.lex_state = 67},
  [65] = {.lex_state = 67},
  [66] = {.lex_state = 67},
  [67] = {.lex_state = 66},
  [68] = {.lex_state = 67},
  [69] = {.lex_state = 67},
  [70] = {.lex_state = 67},
  [71] = {.lex_state = 66},
  [72] = {.lex_state = 67},
  [73] = {.lex_state = 67},
  [74] = {.lex_state = 67},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 69},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 69},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 69},
  [101] = {.lex_state = 69},
  [102] = {.lex_state = 69},
  [103] = {.lex_state = 64},
  [104] = {.lex_state = 67},
  [105] = {.lex_state = 67},
  [106] = {.lex_state = 67},
  [107] = {.lex_state = 4},
  [108] = {.lex_state = 67},
  [109] = {.lex_state = 4},
  [110] = {.lex_state = 4},
  [111] = {.lex_state = 4},
  [112] = {.lex_state = 4},
  [113] = {.lex_state = 67},
  [114] = {.lex_state = 4},
  [115] = {.lex_state = 4},
  [116] = {.lex_state = 4},
  [117] = {.lex_state = 67},
  [118] = {.lex_state = 1},
  [119] = {.lex_state = 67},
  [120] = {.lex_state = 1},
  [121] = {.lex_state = 4},
  [122] = {.lex_state = 0},
  [123] = {.lex_state = 4},
  [124] = {.lex_state = 67},
  [125] = {.lex_state = 0},
  [126] = {.lex_state = 1},
  [127] = {.lex_state = 0},
  [128] = {.lex_state = 0},
  [129] = {.lex_state = 4},
  [130] = {.lex_state = 0},
  [131] = {.lex_state = 4},
  [132] = {.lex_state = 4},
  [133] = {.lex_state = 1},
  [134] = {.lex_state = 3},
  [135] = {.lex_state = 3},
  [136] = {.lex_state = 1},
  [137] = {.lex_state = 5},
  [138] = {.lex_state = 1},
  [139] = {.lex_state = 4},
  [140] = {.lex_state = 5},
  [141] = {.lex_state = 1},
  [142] = {.lex_state = 3},
  [143] = {.lex_state = 1},
  [144] = {.lex_state = 5},
  [145] = {.lex_state = 3},
  [146] = {.lex_state = 3},
  [147] = {.lex_state = 5},
  [148] = {.lex_state = 5},
  [149] = {.lex_state = 3},
  [150] = {.lex_state = 1},
  [151] = {.lex_state = 5},
  [152] = {.lex_state = 3},
  [153] = {.lex_state = 1},
  [154] = {.lex_state = 5},
  [155] = {.lex_state = 0},
  [156] = {.lex_state = 0},
  [157] = {.lex_state = 0},
  [158] = {.lex_state = 0},
  [159] = {.lex_state = 1},
  [160] = {.lex_state = 0},
  [161] = {.lex_state = 0},
  [162] = {.lex_state = 1},
  [163] = {.lex_state = 1},
  [164] = {.lex_state = 1},
  [165] = {.lex_state = 0},
  [166] = {.lex_state = 0},
  [167] = {.lex_state = 0},
  [168] = {.lex_state = 1},
  [169] = {.lex_state = 0},
  [170] = {.lex_state = 0},
  [171] = {.lex_state = 0},
  [172] = {.lex_state = 0},
  [173] = {.lex_state = 1},
  [174] = {.lex_state = 69},
  [175] = {.lex_state = 0},
  [176] = {.lex_state = 1},
  [177] = {.lex_state = 0},
  [178] = {.lex_state = 0},
  [179] = {.lex_state = 0},
  [180] = {.lex_state = 0},
  [181] = {.lex_state = 0},
  [182] = {.lex_state = 0},
  [183] = {.lex_state = 0},
  [184] = {.lex_state = 0},
  [185] = {.lex_state = 0},
  [186] = {.lex_state = 1},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_def] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_QMARK] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [sym_flag_name] = ACTIONS(1),
    [anon_sym_DOT_DOT_DOTrest] = ACTIONS(1),
    [anon_sym_int] = ACTIONS(1),
    [anon_sym_string] = ACTIONS(1),
    [anon_sym_path] = ACTIONS(1),
    [anon_sym_table] = ACTIONS(1),
    [anon_sym_unit] = ACTIONS(1),
    [anon_sym_number] = ACTIONS(1),
    [anon_sym_pattern] = ACTIONS(1),
    [anon_sym_range] = ACTIONS(1),
    [anon_sym_block] = ACTIONS(1),
    [anon_sym_any] = ACTIONS(1),
    [anon_sym_let] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [sym_number_literal] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_DOLLAR] = ACTIONS(1),
    [anon_sym_DOLLAR_LPAREN] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_PIPE_PIPE] = ACTIONS(1),
    [anon_sym_AMP_AMP] = ACTIONS(1),
    [anon_sym_BANG_EQ] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_GT_EQ] = ACTIONS(1),
    [anon_sym_LT_EQ] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_LT_LT] = ACTIONS(1),
    [anon_sym_GT_GT] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(185),
    [sym__statements] = STATE(184),
    [sym__statement] = STATE(119),
    [sym_function_definition] = STATE(119),
    [sym_variable_declaration] = STATE(119),
    [sym_command] = STATE(119),
    [sym_pipeline] = STATE(119),
    [sym_variable_deref] = STATE(28),
    [sym_command_substitution] = STATE(28),
    [sym_math_mode] = STATE(28),
    [sym_block] = STATE(119),
    [sym__math_expression] = STATE(28),
    [sym_parenthesized_math_expression] = STATE(28),
    [sym_binary_expression] = STATE(28),
    [aux_sym__statements_repeat1] = STATE(17),
    [ts_builtin_sym_end] = ACTIONS(5),
    [anon_sym_def] = ACTIONS(7),
    [anon_sym_LPAREN] = ACTIONS(9),
    [anon_sym_let] = ACTIONS(11),
    [sym_cmd_name] = ACTIONS(13),
    [sym_number_literal] = ACTIONS(15),
    [anon_sym_DOLLAR] = ACTIONS(17),
    [anon_sym_DOLLAR_LPAREN] = ACTIONS(19),
    [anon_sym_LBRACE] = ACTIONS(21),
    [sym_comment] = ACTIONS(3),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 12,
    ACTIONS(23), 1,
      anon_sym_LBRACK,
    ACTIONS(29), 1,
      anon_sym_DQUOTE,
    ACTIONS(31), 1,
      anon_sym_SQUOTE,
    ACTIONS(33), 1,
      anon_sym_DOLLAR,
    ACTIONS(35), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(37), 1,
      anon_sym_LBRACE,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(41), 1,
      anon_sym_LF,
    STATE(59), 1,
      sym_variable_deref,
    ACTIONS(27), 2,
      sym_number_literal,
      sym_word,
    ACTIONS(25), 4,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
    STATE(3), 10,
      sym__literal,
      sym__primary_expression,
      sym_string,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym_table,
      sym_array,
      sym_block,
      aux_sym_command_repeat1,
  [50] = 12,
    ACTIONS(23), 1,
      anon_sym_LBRACK,
    ACTIONS(29), 1,
      anon_sym_DQUOTE,
    ACTIONS(31), 1,
      anon_sym_SQUOTE,
    ACTIONS(33), 1,
      anon_sym_DOLLAR,
    ACTIONS(35), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(37), 1,
      anon_sym_LBRACE,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(47), 1,
      anon_sym_LF,
    STATE(59), 1,
      sym_variable_deref,
    ACTIONS(45), 2,
      sym_number_literal,
      sym_word,
    ACTIONS(43), 4,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
    STATE(4), 10,
      sym__literal,
      sym__primary_expression,
      sym_string,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym_table,
      sym_array,
      sym_block,
      aux_sym_command_repeat1,
  [100] = 12,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(49), 1,
      anon_sym_LBRACK,
    ACTIONS(57), 1,
      anon_sym_DQUOTE,
    ACTIONS(60), 1,
      anon_sym_SQUOTE,
    ACTIONS(63), 1,
      anon_sym_DOLLAR,
    ACTIONS(66), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(69), 1,
      anon_sym_LBRACE,
    ACTIONS(72), 1,
      anon_sym_LF,
    STATE(59), 1,
      sym_variable_deref,
    ACTIONS(54), 2,
      sym_number_literal,
      sym_word,
    ACTIONS(52), 4,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
    STATE(4), 10,
      sym__literal,
      sym__primary_expression,
      sym_string,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym_table,
      sym_array,
      sym_block,
      aux_sym_command_repeat1,
  [150] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_def,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_let,
    ACTIONS(15), 1,
      sym_number_literal,
    ACTIONS(17), 1,
      anon_sym_DOLLAR,
    ACTIONS(19), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    ACTIONS(74), 1,
      anon_sym_EQ,
    ACTIONS(76), 1,
      sym_cmd_name,
    STATE(24), 1,
      aux_sym__statements_repeat1,
    STATE(180), 1,
      sym__statements,
    STATE(28), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(105), 6,
      sym__statement,
      sym_function_definition,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_block,
  [203] = 12,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(78), 1,
      anon_sym_LBRACK,
    ACTIONS(84), 1,
      anon_sym_DQUOTE,
    ACTIONS(87), 1,
      anon_sym_SQUOTE,
    ACTIONS(90), 1,
      anon_sym_DOLLAR,
    ACTIONS(93), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(96), 1,
      anon_sym_LBRACE,
    STATE(71), 1,
      sym_variable_deref,
    ACTIONS(52), 2,
      anon_sym_PIPE,
      anon_sym_SEMI,
    ACTIONS(72), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(81), 2,
      sym_number_literal,
      sym_word,
    STATE(6), 10,
      sym__literal,
      sym__primary_expression,
      sym_string,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym_table,
      sym_array,
      sym_block,
      aux_sym_command_repeat1,
  [252] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_def,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_let,
    ACTIONS(15), 1,
      sym_number_literal,
    ACTIONS(17), 1,
      anon_sym_DOLLAR,
    ACTIONS(19), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    ACTIONS(76), 1,
      sym_cmd_name,
    ACTIONS(99), 1,
      anon_sym_RBRACE,
    STATE(24), 1,
      aux_sym__statements_repeat1,
    STATE(161), 1,
      sym__statements,
    STATE(28), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(105), 6,
      sym__statement,
      sym_function_definition,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_block,
  [305] = 12,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(101), 1,
      anon_sym_LBRACK,
    ACTIONS(105), 1,
      anon_sym_DQUOTE,
    ACTIONS(107), 1,
      anon_sym_SQUOTE,
    ACTIONS(109), 1,
      anon_sym_DOLLAR,
    ACTIONS(111), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(113), 1,
      anon_sym_LBRACE,
    STATE(71), 1,
      sym_variable_deref,
    ACTIONS(25), 2,
      anon_sym_PIPE,
      anon_sym_SEMI,
    ACTIONS(41), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(103), 2,
      sym_number_literal,
      sym_word,
    STATE(13), 10,
      sym__literal,
      sym__primary_expression,
      sym_string,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym_table,
      sym_array,
      sym_block,
      aux_sym_command_repeat1,
  [354] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_def,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_let,
    ACTIONS(15), 1,
      sym_number_literal,
    ACTIONS(17), 1,
      anon_sym_DOLLAR,
    ACTIONS(19), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    ACTIONS(76), 1,
      sym_cmd_name,
    ACTIONS(115), 1,
      anon_sym_EQ,
    STATE(24), 1,
      aux_sym__statements_repeat1,
    STATE(177), 1,
      sym__statements,
    STATE(28), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(105), 6,
      sym__statement,
      sym_function_definition,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_block,
  [407] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_def,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_let,
    ACTIONS(15), 1,
      sym_number_literal,
    ACTIONS(17), 1,
      anon_sym_DOLLAR,
    ACTIONS(19), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    ACTIONS(76), 1,
      sym_cmd_name,
    ACTIONS(117), 1,
      anon_sym_EQ,
    STATE(24), 1,
      aux_sym__statements_repeat1,
    STATE(178), 1,
      sym__statements,
    STATE(28), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(105), 6,
      sym__statement,
      sym_function_definition,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_block,
  [460] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_def,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_let,
    ACTIONS(15), 1,
      sym_number_literal,
    ACTIONS(17), 1,
      anon_sym_DOLLAR,
    ACTIONS(19), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    ACTIONS(76), 1,
      sym_cmd_name,
    ACTIONS(119), 1,
      anon_sym_RBRACE,
    STATE(24), 1,
      aux_sym__statements_repeat1,
    STATE(175), 1,
      sym__statements,
    STATE(28), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(105), 6,
      sym__statement,
      sym_function_definition,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_block,
  [513] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_def,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_let,
    ACTIONS(15), 1,
      sym_number_literal,
    ACTIONS(17), 1,
      anon_sym_DOLLAR,
    ACTIONS(19), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    ACTIONS(76), 1,
      sym_cmd_name,
    ACTIONS(121), 1,
      anon_sym_EQ,
    STATE(24), 1,
      aux_sym__statements_repeat1,
    STATE(171), 1,
      sym__statements,
    STATE(28), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(105), 6,
      sym__statement,
      sym_function_definition,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_block,
  [566] = 12,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(101), 1,
      anon_sym_LBRACK,
    ACTIONS(105), 1,
      anon_sym_DQUOTE,
    ACTIONS(107), 1,
      anon_sym_SQUOTE,
    ACTIONS(109), 1,
      anon_sym_DOLLAR,
    ACTIONS(111), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(113), 1,
      anon_sym_LBRACE,
    STATE(71), 1,
      sym_variable_deref,
    ACTIONS(43), 2,
      anon_sym_PIPE,
      anon_sym_SEMI,
    ACTIONS(47), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(123), 2,
      sym_number_literal,
      sym_word,
    STATE(6), 10,
      sym__literal,
      sym__primary_expression,
      sym_string,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym_table,
      sym_array,
      sym_block,
      aux_sym_command_repeat1,
  [615] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(125), 3,
      ts_builtin_sym_end,
      anon_sym_DOT,
      anon_sym_LF,
    ACTIONS(127), 19,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [645] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(129), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(131), 19,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [674] = 8,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(129), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(133), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(137), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(141), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(135), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(139), 4,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
    ACTIONS(131), 6,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
  [713] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_def,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_let,
    ACTIONS(13), 1,
      sym_cmd_name,
    ACTIONS(15), 1,
      sym_number_literal,
    ACTIONS(17), 1,
      anon_sym_DOLLAR,
    ACTIONS(19), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    STATE(23), 1,
      aux_sym__statements_repeat1,
    STATE(28), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(117), 6,
      sym__statement,
      sym_function_definition,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_block,
  [760] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(143), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(145), 19,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [789] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(147), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(149), 19,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [818] = 4,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(129), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(135), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(131), 16,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [849] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(151), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(153), 19,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [878] = 5,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(129), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(133), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(135), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(131), 14,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [911] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(155), 1,
      anon_sym_def,
    ACTIONS(158), 1,
      anon_sym_LPAREN,
    ACTIONS(161), 1,
      anon_sym_let,
    ACTIONS(164), 1,
      sym_cmd_name,
    ACTIONS(167), 1,
      sym_number_literal,
    ACTIONS(170), 1,
      anon_sym_DOLLAR,
    ACTIONS(173), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(176), 1,
      anon_sym_LBRACE,
    STATE(23), 1,
      aux_sym__statements_repeat1,
    STATE(28), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(124), 6,
      sym__statement,
      sym_function_definition,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_block,
  [958] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_def,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_let,
    ACTIONS(15), 1,
      sym_number_literal,
    ACTIONS(17), 1,
      anon_sym_DOLLAR,
    ACTIONS(19), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    ACTIONS(76), 1,
      sym_cmd_name,
    STATE(23), 1,
      aux_sym__statements_repeat1,
    STATE(28), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(113), 6,
      sym__statement,
      sym_function_definition,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_block,
  [1005] = 6,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(129), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(133), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(141), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(135), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(131), 12,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [1040] = 7,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(129), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(133), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(141), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(135), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(139), 4,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
    ACTIONS(131), 8,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [1077] = 9,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(179), 1,
      anon_sym_AMP_AMP,
    ACTIONS(129), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(133), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(137), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(141), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(135), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(139), 4,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
    ACTIONS(131), 5,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_PIPE_PIPE,
  [1118] = 10,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(179), 1,
      anon_sym_AMP_AMP,
    ACTIONS(185), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(133), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(137), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(141), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(181), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(135), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(139), 4,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
    ACTIONS(183), 4,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
  [1161] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_def,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_let,
    ACTIONS(13), 1,
      sym_cmd_name,
    ACTIONS(15), 1,
      sym_number_literal,
    ACTIONS(17), 1,
      anon_sym_DOLLAR,
    ACTIONS(19), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    STATE(28), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(104), 6,
      sym__statement,
      sym_function_definition,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_block,
  [1205] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_def,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_let,
    ACTIONS(15), 1,
      sym_number_literal,
    ACTIONS(17), 1,
      anon_sym_DOLLAR,
    ACTIONS(19), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    ACTIONS(76), 1,
      sym_cmd_name,
    STATE(28), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(104), 6,
      sym__statement,
      sym_function_definition,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_block,
  [1249] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(17), 1,
      anon_sym_DOLLAR,
    ACTIONS(19), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    ACTIONS(187), 1,
      anon_sym_LBRACK,
    ACTIONS(191), 1,
      anon_sym_DQUOTE,
    ACTIONS(193), 1,
      anon_sym_SQUOTE,
    STATE(103), 1,
      sym_variable_deref,
    ACTIONS(189), 2,
      sym_number_literal,
      sym_word,
    STATE(108), 9,
      sym__literal,
      sym__primary_expression,
      sym_string,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym_table,
      sym_array,
      sym_block,
  [1289] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(145), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(143), 14,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [1313] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(127), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(125), 14,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [1337] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(131), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(195), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(197), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(129), 9,
      anon_sym_RPAREN,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [1365] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(131), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(129), 14,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [1389] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(149), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(147), 14,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [1413] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(199), 1,
      anon_sym_RPAREN,
    ACTIONS(201), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(203), 1,
      anon_sym_AMP_AMP,
    ACTIONS(195), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(205), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(207), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(209), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(211), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(197), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [1451] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(203), 1,
      anon_sym_AMP_AMP,
    ACTIONS(129), 2,
      anon_sym_RPAREN,
      anon_sym_PIPE_PIPE,
    ACTIONS(195), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(205), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(207), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(209), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(211), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(197), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [1487] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(201), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(203), 1,
      anon_sym_AMP_AMP,
    ACTIONS(213), 1,
      anon_sym_RPAREN,
    ACTIONS(195), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(205), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(207), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(209), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(211), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(197), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [1525] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(153), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(151), 14,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [1549] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(131), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(195), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(211), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(197), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(129), 7,
      anon_sym_RPAREN,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
  [1579] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(201), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(203), 1,
      anon_sym_AMP_AMP,
    ACTIONS(215), 1,
      anon_sym_RPAREN,
    ACTIONS(195), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(205), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(207), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(209), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(211), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(197), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [1617] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(201), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(203), 1,
      anon_sym_AMP_AMP,
    ACTIONS(217), 1,
      anon_sym_RPAREN,
    ACTIONS(195), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(205), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(207), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(209), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(211), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(197), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [1655] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(201), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(203), 1,
      anon_sym_AMP_AMP,
    ACTIONS(219), 1,
      anon_sym_RPAREN,
    ACTIONS(195), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(205), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(207), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(209), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(211), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(197), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [1693] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(195), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(205), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(207), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(209), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(211), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(129), 3,
      anon_sym_RPAREN,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
    ACTIONS(197), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [1727] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(131), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(197), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(129), 11,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [1753] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(201), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(203), 1,
      anon_sym_AMP_AMP,
    ACTIONS(221), 1,
      anon_sym_RPAREN,
    ACTIONS(195), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(205), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(207), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(209), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(211), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(197), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [1791] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(195), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(207), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(209), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(211), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(197), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(129), 5,
      anon_sym_RPAREN,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [1823] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(223), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(225), 12,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [1845] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(227), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(229), 12,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [1867] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(231), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(233), 12,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [1889] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(125), 1,
      anon_sym_LF,
    ACTIONS(127), 13,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOT,
      anon_sym_DOLLAR,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [1911] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(235), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(237), 12,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [1933] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(239), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(241), 12,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [1955] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(243), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(245), 12,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [1977] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(247), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(249), 12,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [1999] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(251), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(253), 12,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2021] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(255), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(257), 12,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2043] = 4,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(261), 1,
      anon_sym_DOT,
    ACTIONS(263), 1,
      anon_sym_LF,
    ACTIONS(259), 12,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2067] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(255), 1,
      anon_sym_LF,
    ACTIONS(257), 12,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2088] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(247), 1,
      anon_sym_LF,
    ACTIONS(249), 12,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2109] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(227), 1,
      anon_sym_LF,
    ACTIONS(229), 12,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2130] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(231), 1,
      anon_sym_LF,
    ACTIONS(233), 12,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2151] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(239), 1,
      anon_sym_LF,
    ACTIONS(241), 12,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2172] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(243), 1,
      anon_sym_LF,
    ACTIONS(245), 12,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2193] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(223), 1,
      anon_sym_LF,
    ACTIONS(225), 12,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2214] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(125), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(127), 11,
      anon_sym_LBRACK,
      anon_sym_PIPE,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOT,
      anon_sym_DOLLAR,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_SEMI,
      anon_sym_LBRACE,
  [2235] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(143), 1,
      anon_sym_LF,
    ACTIONS(145), 12,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2256] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(251), 1,
      anon_sym_LF,
    ACTIONS(253), 12,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2277] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(151), 1,
      anon_sym_LF,
    ACTIONS(153), 12,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2298] = 4,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(265), 1,
      anon_sym_DOT,
    ACTIONS(263), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(259), 10,
      anon_sym_LBRACK,
      anon_sym_PIPE,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_SEMI,
      anon_sym_LBRACE,
  [2321] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(235), 1,
      anon_sym_LF,
    ACTIONS(237), 12,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2342] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(151), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(153), 10,
      anon_sym_LBRACK,
      anon_sym_PIPE,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_SEMI,
      anon_sym_LBRACE,
  [2362] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(143), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(145), 10,
      anon_sym_LBRACK,
      anon_sym_PIPE,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_SEMI,
      anon_sym_LBRACE,
  [2382] = 3,
    ACTIONS(3), 1,
      sym_comment,
    STATE(132), 1,
      sym_type,
    ACTIONS(267), 10,
      anon_sym_int,
      anon_sym_string,
      anon_sym_path,
      anon_sym_table,
      anon_sym_unit,
      anon_sym_number,
      anon_sym_pattern,
      anon_sym_range,
      anon_sym_block,
      anon_sym_any,
  [2401] = 3,
    ACTIONS(3), 1,
      sym_comment,
    STATE(121), 1,
      sym_type,
    ACTIONS(267), 10,
      anon_sym_int,
      anon_sym_string,
      anon_sym_path,
      anon_sym_table,
      anon_sym_unit,
      anon_sym_number,
      anon_sym_pattern,
      anon_sym_range,
      anon_sym_block,
      anon_sym_any,
  [2420] = 3,
    ACTIONS(3), 1,
      sym_comment,
    STATE(115), 1,
      sym_type,
    ACTIONS(267), 10,
      anon_sym_int,
      anon_sym_string,
      anon_sym_path,
      anon_sym_table,
      anon_sym_unit,
      anon_sym_number,
      anon_sym_pattern,
      anon_sym_range,
      anon_sym_block,
      anon_sym_any,
  [2439] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      anon_sym_DOLLAR,
    ACTIONS(19), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(269), 1,
      sym_number_literal,
    STATE(26), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2463] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      anon_sym_DOLLAR,
    ACTIONS(19), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(271), 1,
      sym_number_literal,
    STATE(27), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2487] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(273), 1,
      anon_sym_LPAREN,
    ACTIONS(275), 1,
      sym_number_literal,
    ACTIONS(277), 1,
      anon_sym_DOLLAR,
    ACTIONS(279), 1,
      anon_sym_DOLLAR_LPAREN,
    STATE(44), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2511] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(273), 1,
      anon_sym_LPAREN,
    ACTIONS(277), 1,
      anon_sym_DOLLAR,
    ACTIONS(279), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(281), 1,
      sym_number_literal,
    STATE(43), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2535] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(273), 1,
      anon_sym_LPAREN,
    ACTIONS(277), 1,
      anon_sym_DOLLAR,
    ACTIONS(279), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(283), 1,
      sym_number_literal,
    STATE(37), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2559] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      anon_sym_DOLLAR,
    ACTIONS(19), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(285), 1,
      sym_number_literal,
    STATE(25), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2583] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(273), 1,
      anon_sym_LPAREN,
    ACTIONS(277), 1,
      anon_sym_DOLLAR,
    ACTIONS(279), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(287), 1,
      sym_number_literal,
    STATE(39), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2607] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(273), 1,
      anon_sym_LPAREN,
    ACTIONS(277), 1,
      anon_sym_DOLLAR,
    ACTIONS(279), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(289), 1,
      sym_number_literal,
    STATE(42), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2631] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(295), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
    ACTIONS(291), 4,
      anon_sym_def,
      anon_sym_let,
      sym_cmd_name,
      anon_sym_DOLLAR,
    ACTIONS(293), 4,
      anon_sym_LPAREN,
      sym_number_literal,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_LBRACE,
  [2651] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(273), 1,
      anon_sym_LPAREN,
    ACTIONS(277), 1,
      anon_sym_DOLLAR,
    ACTIONS(279), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(297), 1,
      sym_number_literal,
    STATE(47), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2675] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      anon_sym_DOLLAR,
    ACTIONS(19), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(299), 1,
      sym_number_literal,
    STATE(16), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2699] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      anon_sym_DOLLAR,
    ACTIONS(19), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(301), 1,
      sym_number_literal,
    STATE(20), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2723] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      anon_sym_DOLLAR,
    ACTIONS(19), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(303), 1,
      sym_number_literal,
    STATE(15), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2747] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(17), 1,
      anon_sym_DOLLAR,
    ACTIONS(19), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(305), 1,
      sym_number_literal,
    STATE(22), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2771] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(307), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
    ACTIONS(291), 4,
      anon_sym_def,
      anon_sym_let,
      sym_cmd_name,
      anon_sym_DOLLAR,
    ACTIONS(293), 4,
      anon_sym_LPAREN,
      sym_number_literal,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_LBRACE,
  [2791] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(273), 1,
      anon_sym_LPAREN,
    ACTIONS(277), 1,
      anon_sym_DOLLAR,
    ACTIONS(279), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(309), 1,
      sym_number_literal,
    STATE(34), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2815] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(273), 1,
      anon_sym_LPAREN,
    ACTIONS(277), 1,
      anon_sym_DOLLAR,
    ACTIONS(279), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(311), 1,
      sym_number_literal,
    STATE(41), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2839] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(273), 1,
      anon_sym_LPAREN,
    ACTIONS(277), 1,
      anon_sym_DOLLAR,
    ACTIONS(279), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(313), 1,
      sym_number_literal,
    STATE(48), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2863] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(273), 1,
      anon_sym_LPAREN,
    ACTIONS(277), 1,
      anon_sym_DOLLAR,
    ACTIONS(279), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(315), 1,
      sym_number_literal,
    STATE(45), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2887] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(273), 1,
      anon_sym_LPAREN,
    ACTIONS(277), 1,
      anon_sym_DOLLAR,
    ACTIONS(279), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(317), 1,
      sym_number_literal,
    STATE(38), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2911] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(273), 1,
      anon_sym_LPAREN,
    ACTIONS(277), 1,
      anon_sym_DOLLAR,
    ACTIONS(279), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(319), 1,
      sym_number_literal,
    STATE(35), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2935] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(273), 1,
      anon_sym_LPAREN,
    ACTIONS(277), 1,
      anon_sym_DOLLAR,
    ACTIONS(279), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(321), 1,
      sym_number_literal,
    STATE(46), 6,
      sym_variable_deref,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2959] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(295), 1,
      ts_builtin_sym_end,
    ACTIONS(291), 4,
      anon_sym_def,
      anon_sym_let,
      sym_cmd_name,
      anon_sym_DOLLAR,
    ACTIONS(293), 4,
      anon_sym_LPAREN,
      sym_number_literal,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_LBRACE,
  [2978] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(307), 1,
      ts_builtin_sym_end,
    ACTIONS(291), 4,
      anon_sym_def,
      anon_sym_let,
      sym_cmd_name,
      anon_sym_DOLLAR,
    ACTIONS(293), 4,
      anon_sym_LPAREN,
      sym_number_literal,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_LBRACE,
  [2997] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(291), 4,
      anon_sym_def,
      anon_sym_let,
      sym_cmd_name,
      anon_sym_DOLLAR,
    ACTIONS(293), 4,
      anon_sym_LPAREN,
      sym_number_literal,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_LBRACE,
  [3013] = 4,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(323), 1,
      anon_sym_DOT,
    ACTIONS(263), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(259), 4,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
  [3030] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(325), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(327), 4,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
  [3044] = 6,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(331), 1,
      anon_sym_PIPE,
    ACTIONS(333), 1,
      anon_sym_SEMI,
    ACTIONS(335), 1,
      anon_sym_LF,
    STATE(92), 1,
      sym__terminator,
    ACTIONS(329), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [3064] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(337), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(339), 4,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
  [3078] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(341), 1,
      anon_sym_RBRACK,
    ACTIONS(343), 1,
      sym_flag_name,
    ACTIONS(345), 1,
      sym_identifier,
    STATE(112), 1,
      aux_sym_signature_repeat1,
    STATE(123), 2,
      sym_parameter,
      sym_flag,
  [3098] = 3,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(347), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(349), 4,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
  [3112] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(353), 1,
      anon_sym_COLON,
    ACTIONS(355), 1,
      anon_sym_LPAREN,
    ACTIONS(351), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      sym_identifier,
  [3128] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(343), 1,
      sym_flag_name,
    ACTIONS(345), 1,
      sym_identifier,
    ACTIONS(357), 1,
      anon_sym_RBRACK,
    STATE(107), 1,
      aux_sym_signature_repeat1,
    STATE(123), 2,
      sym_parameter,
      sym_flag,
  [3148] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(361), 1,
      anon_sym_COLON,
    ACTIONS(363), 1,
      anon_sym_QMARK,
    ACTIONS(359), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      sym_identifier,
  [3164] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(365), 1,
      anon_sym_RBRACK,
    ACTIONS(367), 1,
      sym_flag_name,
    ACTIONS(370), 1,
      sym_identifier,
    STATE(112), 1,
      aux_sym_signature_repeat1,
    STATE(123), 2,
      sym_parameter,
      sym_flag,
  [3184] = 6,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(331), 1,
      anon_sym_PIPE,
    ACTIONS(375), 1,
      anon_sym_SEMI,
    ACTIONS(377), 1,
      anon_sym_LF,
    STATE(86), 1,
      sym__terminator,
    ACTIONS(373), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [3204] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(381), 1,
      anon_sym_COLON,
    ACTIONS(379), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      sym_identifier,
  [3217] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(385), 1,
      anon_sym_QMARK,
    ACTIONS(383), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      sym_identifier,
  [3230] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(387), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_QMARK,
      sym_flag_name,
      sym_identifier,
  [3241] = 6,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(307), 1,
      ts_builtin_sym_end,
    ACTIONS(389), 1,
      anon_sym_PIPE,
    ACTIONS(391), 1,
      anon_sym_SEMI,
    ACTIONS(393), 1,
      anon_sym_LF,
    STATE(100), 1,
      sym__terminator,
  [3260] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(395), 1,
      anon_sym_LBRACK,
    ACTIONS(397), 1,
      anon_sym_RBRACK,
    ACTIONS(399), 1,
      sym_identifier,
    STATE(153), 1,
      aux_sym_column_header_repeat1,
    STATE(170), 1,
      sym_column_header,
  [3279] = 6,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(389), 1,
      anon_sym_PIPE,
    ACTIONS(401), 1,
      ts_builtin_sym_end,
    ACTIONS(403), 1,
      anon_sym_SEMI,
    ACTIONS(405), 1,
      anon_sym_LF,
    STATE(101), 1,
      sym__terminator,
  [3298] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(395), 1,
      anon_sym_LBRACK,
    ACTIONS(399), 1,
      sym_identifier,
    ACTIONS(407), 1,
      anon_sym_RBRACK,
    STATE(150), 1,
      aux_sym_column_header_repeat1,
    STATE(182), 1,
      sym_column_header,
  [3317] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(409), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      sym_identifier,
  [3327] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(411), 1,
      anon_sym_LBRACK,
    ACTIONS(413), 1,
      anon_sym_RBRACK,
    STATE(125), 2,
      sym_array,
      aux_sym_table_repeat1,
  [3341] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(415), 1,
      anon_sym_COMMA,
    ACTIONS(417), 3,
      anon_sym_RBRACK,
      sym_flag_name,
      sym_identifier,
  [3353] = 5,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(331), 1,
      anon_sym_PIPE,
    ACTIONS(419), 1,
      anon_sym_SEMI,
    ACTIONS(421), 1,
      anon_sym_LF,
    STATE(102), 1,
      sym__terminator,
  [3369] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(423), 1,
      anon_sym_LBRACK,
    ACTIONS(426), 1,
      anon_sym_RBRACK,
    STATE(125), 2,
      sym_array,
      aux_sym_table_repeat1,
  [3383] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(428), 1,
      anon_sym_DQUOTE,
    ACTIONS(430), 1,
      anon_sym_SQUOTE,
    ACTIONS(432), 1,
      sym_identifier,
    STATE(157), 1,
      sym_string,
  [3399] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(411), 1,
      anon_sym_LBRACK,
    ACTIONS(434), 1,
      anon_sym_RBRACK,
    STATE(125), 2,
      sym_array,
      aux_sym_table_repeat1,
  [3413] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(411), 1,
      anon_sym_LBRACK,
    ACTIONS(436), 1,
      anon_sym_RBRACK,
    STATE(122), 2,
      sym_array,
      aux_sym_table_repeat1,
  [3427] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(438), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      sym_identifier,
  [3437] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(411), 1,
      anon_sym_LBRACK,
    ACTIONS(440), 1,
      anon_sym_RBRACK,
    STATE(127), 2,
      sym_array,
      aux_sym_table_repeat1,
  [3451] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(442), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      sym_identifier,
  [3461] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(444), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      sym_identifier,
  [3471] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(399), 1,
      sym_identifier,
    ACTIONS(446), 1,
      anon_sym_RBRACK,
    STATE(143), 1,
      aux_sym_column_header_repeat1,
  [3484] = 4,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(448), 1,
      anon_sym_DQUOTE,
    ACTIONS(450), 1,
      sym_qouted_string_content,
    STATE(152), 1,
      aux_sym_string_repeat1,
  [3497] = 4,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(452), 1,
      anon_sym_DQUOTE,
    ACTIONS(454), 1,
      sym_qouted_string_content,
    STATE(146), 1,
      aux_sym_string_repeat1,
  [3510] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(399), 1,
      sym_identifier,
    ACTIONS(456), 1,
      anon_sym_RBRACK,
    STATE(138), 1,
      aux_sym_column_header_repeat1,
  [3523] = 4,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(452), 1,
      anon_sym_SQUOTE,
    ACTIONS(458), 1,
      sym_single_qouted_string_content,
    STATE(147), 1,
      aux_sym_string_repeat2,
  [3536] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(399), 1,
      sym_identifier,
    ACTIONS(460), 1,
      anon_sym_RBRACK,
    STATE(141), 1,
      aux_sym_column_header_repeat1,
  [3549] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(365), 3,
      anon_sym_RBRACK,
      sym_flag_name,
      sym_identifier,
  [3558] = 4,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(462), 1,
      anon_sym_SQUOTE,
    ACTIONS(464), 1,
      sym_single_qouted_string_content,
    STATE(148), 1,
      aux_sym_string_repeat2,
  [3571] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(466), 1,
      anon_sym_RBRACK,
    ACTIONS(468), 1,
      sym_identifier,
    STATE(141), 1,
      aux_sym_column_header_repeat1,
  [3584] = 4,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(462), 1,
      anon_sym_DQUOTE,
    ACTIONS(471), 1,
      sym_qouted_string_content,
    STATE(149), 1,
      aux_sym_string_repeat1,
  [3597] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(399), 1,
      sym_identifier,
    ACTIONS(473), 1,
      anon_sym_RBRACK,
    STATE(141), 1,
      aux_sym_column_header_repeat1,
  [3610] = 4,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(475), 1,
      anon_sym_SQUOTE,
    ACTIONS(477), 1,
      sym_single_qouted_string_content,
    STATE(140), 1,
      aux_sym_string_repeat2,
  [3623] = 4,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(475), 1,
      anon_sym_DQUOTE,
    ACTIONS(479), 1,
      sym_qouted_string_content,
    STATE(142), 1,
      aux_sym_string_repeat1,
  [3636] = 4,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(471), 1,
      sym_qouted_string_content,
    ACTIONS(481), 1,
      anon_sym_DQUOTE,
    STATE(149), 1,
      aux_sym_string_repeat1,
  [3649] = 4,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(464), 1,
      sym_single_qouted_string_content,
    ACTIONS(481), 1,
      anon_sym_SQUOTE,
    STATE(148), 1,
      aux_sym_string_repeat2,
  [3662] = 4,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(483), 1,
      anon_sym_SQUOTE,
    ACTIONS(485), 1,
      sym_single_qouted_string_content,
    STATE(148), 1,
      aux_sym_string_repeat2,
  [3675] = 4,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(488), 1,
      anon_sym_DQUOTE,
    ACTIONS(490), 1,
      sym_qouted_string_content,
    STATE(149), 1,
      aux_sym_string_repeat1,
  [3688] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(399), 1,
      sym_identifier,
    ACTIONS(493), 1,
      anon_sym_RBRACK,
    STATE(141), 1,
      aux_sym_column_header_repeat1,
  [3701] = 4,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(464), 1,
      sym_single_qouted_string_content,
    ACTIONS(495), 1,
      anon_sym_SQUOTE,
    STATE(148), 1,
      aux_sym_string_repeat2,
  [3714] = 4,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(471), 1,
      sym_qouted_string_content,
    ACTIONS(495), 1,
      anon_sym_DQUOTE,
    STATE(149), 1,
      aux_sym_string_repeat1,
  [3727] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(399), 1,
      sym_identifier,
    ACTIONS(497), 1,
      anon_sym_RBRACK,
    STATE(141), 1,
      aux_sym_column_header_repeat1,
  [3740] = 4,
    ACTIONS(39), 1,
      sym_comment,
    ACTIONS(448), 1,
      anon_sym_SQUOTE,
    ACTIONS(499), 1,
      sym_single_qouted_string_content,
    STATE(151), 1,
      aux_sym_string_repeat2,
  [3753] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(227), 2,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
  [3761] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(247), 2,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
  [3769] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(501), 1,
      anon_sym_LBRACK,
    STATE(158), 1,
      sym_signature,
  [3779] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    STATE(106), 1,
      sym_block,
  [3789] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(466), 2,
      anon_sym_RBRACK,
      sym_identifier,
  [3797] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(503), 1,
      anon_sym_SEMI,
  [3804] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(505), 1,
      anon_sym_RBRACE,
  [3811] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(507), 1,
      sym_identifier,
  [3818] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(509), 1,
      sym_identifier,
  [3825] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(511), 1,
      sym_identifier,
  [3832] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(243), 1,
      anon_sym_LBRACK,
  [3839] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(513), 1,
      anon_sym_RPAREN,
  [3846] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(223), 1,
      anon_sym_LBRACK,
  [3853] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(515), 1,
      sym_identifier,
  [3860] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(517), 1,
      anon_sym_LBRACE,
  [3867] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(519), 1,
      anon_sym_SEMI,
  [3874] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(521), 1,
      anon_sym_RPAREN,
  [3881] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(523), 1,
      anon_sym_COMMA,
  [3888] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(525), 1,
      sym_identifier,
  [3895] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(527), 1,
      sym_flag_shorthand_name,
  [3902] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(529), 1,
      anon_sym_RBRACE,
  [3909] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(531), 1,
      sym_identifier,
  [3916] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(533), 1,
      anon_sym_RPAREN,
  [3923] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(535), 1,
      anon_sym_RPAREN,
  [3930] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(537), 1,
      anon_sym_EQ,
  [3937] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(539), 1,
      anon_sym_RPAREN,
  [3944] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(541), 1,
      anon_sym_LBRACE,
  [3951] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(543), 1,
      anon_sym_SEMI,
  [3958] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(545), 1,
      anon_sym_SEMI,
  [3965] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(547), 1,
      ts_builtin_sym_end,
  [3972] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(549), 1,
      ts_builtin_sym_end,
  [3979] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(551), 1,
      sym_identifier,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 50,
  [SMALL_STATE(4)] = 100,
  [SMALL_STATE(5)] = 150,
  [SMALL_STATE(6)] = 203,
  [SMALL_STATE(7)] = 252,
  [SMALL_STATE(8)] = 305,
  [SMALL_STATE(9)] = 354,
  [SMALL_STATE(10)] = 407,
  [SMALL_STATE(11)] = 460,
  [SMALL_STATE(12)] = 513,
  [SMALL_STATE(13)] = 566,
  [SMALL_STATE(14)] = 615,
  [SMALL_STATE(15)] = 645,
  [SMALL_STATE(16)] = 674,
  [SMALL_STATE(17)] = 713,
  [SMALL_STATE(18)] = 760,
  [SMALL_STATE(19)] = 789,
  [SMALL_STATE(20)] = 818,
  [SMALL_STATE(21)] = 849,
  [SMALL_STATE(22)] = 878,
  [SMALL_STATE(23)] = 911,
  [SMALL_STATE(24)] = 958,
  [SMALL_STATE(25)] = 1005,
  [SMALL_STATE(26)] = 1040,
  [SMALL_STATE(27)] = 1077,
  [SMALL_STATE(28)] = 1118,
  [SMALL_STATE(29)] = 1161,
  [SMALL_STATE(30)] = 1205,
  [SMALL_STATE(31)] = 1249,
  [SMALL_STATE(32)] = 1289,
  [SMALL_STATE(33)] = 1313,
  [SMALL_STATE(34)] = 1337,
  [SMALL_STATE(35)] = 1365,
  [SMALL_STATE(36)] = 1389,
  [SMALL_STATE(37)] = 1413,
  [SMALL_STATE(38)] = 1451,
  [SMALL_STATE(39)] = 1487,
  [SMALL_STATE(40)] = 1525,
  [SMALL_STATE(41)] = 1549,
  [SMALL_STATE(42)] = 1579,
  [SMALL_STATE(43)] = 1617,
  [SMALL_STATE(44)] = 1655,
  [SMALL_STATE(45)] = 1693,
  [SMALL_STATE(46)] = 1727,
  [SMALL_STATE(47)] = 1753,
  [SMALL_STATE(48)] = 1791,
  [SMALL_STATE(49)] = 1823,
  [SMALL_STATE(50)] = 1845,
  [SMALL_STATE(51)] = 1867,
  [SMALL_STATE(52)] = 1889,
  [SMALL_STATE(53)] = 1911,
  [SMALL_STATE(54)] = 1933,
  [SMALL_STATE(55)] = 1955,
  [SMALL_STATE(56)] = 1977,
  [SMALL_STATE(57)] = 1999,
  [SMALL_STATE(58)] = 2021,
  [SMALL_STATE(59)] = 2043,
  [SMALL_STATE(60)] = 2067,
  [SMALL_STATE(61)] = 2088,
  [SMALL_STATE(62)] = 2109,
  [SMALL_STATE(63)] = 2130,
  [SMALL_STATE(64)] = 2151,
  [SMALL_STATE(65)] = 2172,
  [SMALL_STATE(66)] = 2193,
  [SMALL_STATE(67)] = 2214,
  [SMALL_STATE(68)] = 2235,
  [SMALL_STATE(69)] = 2256,
  [SMALL_STATE(70)] = 2277,
  [SMALL_STATE(71)] = 2298,
  [SMALL_STATE(72)] = 2321,
  [SMALL_STATE(73)] = 2342,
  [SMALL_STATE(74)] = 2362,
  [SMALL_STATE(75)] = 2382,
  [SMALL_STATE(76)] = 2401,
  [SMALL_STATE(77)] = 2420,
  [SMALL_STATE(78)] = 2439,
  [SMALL_STATE(79)] = 2463,
  [SMALL_STATE(80)] = 2487,
  [SMALL_STATE(81)] = 2511,
  [SMALL_STATE(82)] = 2535,
  [SMALL_STATE(83)] = 2559,
  [SMALL_STATE(84)] = 2583,
  [SMALL_STATE(85)] = 2607,
  [SMALL_STATE(86)] = 2631,
  [SMALL_STATE(87)] = 2651,
  [SMALL_STATE(88)] = 2675,
  [SMALL_STATE(89)] = 2699,
  [SMALL_STATE(90)] = 2723,
  [SMALL_STATE(91)] = 2747,
  [SMALL_STATE(92)] = 2771,
  [SMALL_STATE(93)] = 2791,
  [SMALL_STATE(94)] = 2815,
  [SMALL_STATE(95)] = 2839,
  [SMALL_STATE(96)] = 2863,
  [SMALL_STATE(97)] = 2887,
  [SMALL_STATE(98)] = 2911,
  [SMALL_STATE(99)] = 2935,
  [SMALL_STATE(100)] = 2959,
  [SMALL_STATE(101)] = 2978,
  [SMALL_STATE(102)] = 2997,
  [SMALL_STATE(103)] = 3013,
  [SMALL_STATE(104)] = 3030,
  [SMALL_STATE(105)] = 3044,
  [SMALL_STATE(106)] = 3064,
  [SMALL_STATE(107)] = 3078,
  [SMALL_STATE(108)] = 3098,
  [SMALL_STATE(109)] = 3112,
  [SMALL_STATE(110)] = 3128,
  [SMALL_STATE(111)] = 3148,
  [SMALL_STATE(112)] = 3164,
  [SMALL_STATE(113)] = 3184,
  [SMALL_STATE(114)] = 3204,
  [SMALL_STATE(115)] = 3217,
  [SMALL_STATE(116)] = 3230,
  [SMALL_STATE(117)] = 3241,
  [SMALL_STATE(118)] = 3260,
  [SMALL_STATE(119)] = 3279,
  [SMALL_STATE(120)] = 3298,
  [SMALL_STATE(121)] = 3317,
  [SMALL_STATE(122)] = 3327,
  [SMALL_STATE(123)] = 3341,
  [SMALL_STATE(124)] = 3353,
  [SMALL_STATE(125)] = 3369,
  [SMALL_STATE(126)] = 3383,
  [SMALL_STATE(127)] = 3399,
  [SMALL_STATE(128)] = 3413,
  [SMALL_STATE(129)] = 3427,
  [SMALL_STATE(130)] = 3437,
  [SMALL_STATE(131)] = 3451,
  [SMALL_STATE(132)] = 3461,
  [SMALL_STATE(133)] = 3471,
  [SMALL_STATE(134)] = 3484,
  [SMALL_STATE(135)] = 3497,
  [SMALL_STATE(136)] = 3510,
  [SMALL_STATE(137)] = 3523,
  [SMALL_STATE(138)] = 3536,
  [SMALL_STATE(139)] = 3549,
  [SMALL_STATE(140)] = 3558,
  [SMALL_STATE(141)] = 3571,
  [SMALL_STATE(142)] = 3584,
  [SMALL_STATE(143)] = 3597,
  [SMALL_STATE(144)] = 3610,
  [SMALL_STATE(145)] = 3623,
  [SMALL_STATE(146)] = 3636,
  [SMALL_STATE(147)] = 3649,
  [SMALL_STATE(148)] = 3662,
  [SMALL_STATE(149)] = 3675,
  [SMALL_STATE(150)] = 3688,
  [SMALL_STATE(151)] = 3701,
  [SMALL_STATE(152)] = 3714,
  [SMALL_STATE(153)] = 3727,
  [SMALL_STATE(154)] = 3740,
  [SMALL_STATE(155)] = 3753,
  [SMALL_STATE(156)] = 3761,
  [SMALL_STATE(157)] = 3769,
  [SMALL_STATE(158)] = 3779,
  [SMALL_STATE(159)] = 3789,
  [SMALL_STATE(160)] = 3797,
  [SMALL_STATE(161)] = 3804,
  [SMALL_STATE(162)] = 3811,
  [SMALL_STATE(163)] = 3818,
  [SMALL_STATE(164)] = 3825,
  [SMALL_STATE(165)] = 3832,
  [SMALL_STATE(166)] = 3839,
  [SMALL_STATE(167)] = 3846,
  [SMALL_STATE(168)] = 3853,
  [SMALL_STATE(169)] = 3860,
  [SMALL_STATE(170)] = 3867,
  [SMALL_STATE(171)] = 3874,
  [SMALL_STATE(172)] = 3881,
  [SMALL_STATE(173)] = 3888,
  [SMALL_STATE(174)] = 3895,
  [SMALL_STATE(175)] = 3902,
  [SMALL_STATE(176)] = 3909,
  [SMALL_STATE(177)] = 3916,
  [SMALL_STATE(178)] = 3923,
  [SMALL_STATE(179)] = 3930,
  [SMALL_STATE(180)] = 3937,
  [SMALL_STATE(181)] = 3944,
  [SMALL_STATE(182)] = 3951,
  [SMALL_STATE(183)] = 3958,
  [SMALL_STATE(184)] = 3965,
  [SMALL_STATE(185)] = 3972,
  [SMALL_STATE(186)] = 3979,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(126),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(173),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(186),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(120),
  [25] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_command, 1),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(145),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(144),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(176),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_command, 1),
  [43] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_command, 2),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_command, 2),
  [49] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2), SHIFT_REPEAT(120),
  [52] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2),
  [54] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2), SHIFT_REPEAT(4),
  [57] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2), SHIFT_REPEAT(145),
  [60] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2), SHIFT_REPEAT(144),
  [63] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2), SHIFT_REPEAT(176),
  [66] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2), SHIFT_REPEAT(9),
  [69] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2), SHIFT_REPEAT(7),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_command_repeat1, 2),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [76] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [78] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2), SHIFT_REPEAT(118),
  [81] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2), SHIFT_REPEAT(6),
  [84] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2), SHIFT_REPEAT(134),
  [87] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2), SHIFT_REPEAT(154),
  [90] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2), SHIFT_REPEAT(168),
  [93] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2), SHIFT_REPEAT(12),
  [96] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2), SHIFT_REPEAT(11),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [101] = {.entry = {.count = 1, .reusable = false}}, SHIFT(118),
  [103] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [105] = {.entry = {.count = 1, .reusable = false}}, SHIFT(134),
  [107] = {.entry = {.count = 1, .reusable = false}}, SHIFT(154),
  [109] = {.entry = {.count = 1, .reusable = false}}, SHIFT(168),
  [111] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [113] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [123] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_variable_deref, 2),
  [127] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_variable_deref, 2),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3, .production_id = 1),
  [131] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_expression, 3, .production_id = 1),
  [133] = {.entry = {.count = 1, .reusable = false}}, SHIFT(89),
  [135] = {.entry = {.count = 1, .reusable = false}}, SHIFT(90),
  [137] = {.entry = {.count = 1, .reusable = false}}, SHIFT(78),
  [139] = {.entry = {.count = 1, .reusable = false}}, SHIFT(83),
  [141] = {.entry = {.count = 1, .reusable = false}}, SHIFT(91),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_command_substitution, 3),
  [145] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_command_substitution, 3),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parenthesized_math_expression, 3),
  [149] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_parenthesized_math_expression, 3),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_math_mode, 4),
  [153] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_math_mode, 4),
  [155] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(126),
  [158] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(80),
  [161] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(173),
  [164] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(2),
  [167] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(28),
  [170] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(186),
  [173] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(10),
  [176] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(11),
  [179] = {.entry = {.count = 1, .reusable = false}}, SHIFT(88),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statement, 1),
  [183] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statement, 1),
  [185] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [189] = {.entry = {.count = 1, .reusable = false}}, SHIFT(108),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(154),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [197] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [207] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [219] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [221] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [223] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 2),
  [225] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 2),
  [227] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 3),
  [229] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array, 3),
  [231] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_path, 3),
  [233] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_value_path, 3),
  [235] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table, 4),
  [237] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_table, 4),
  [239] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 3),
  [241] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 3),
  [243] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3),
  [245] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 3),
  [247] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 2),
  [249] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array, 2),
  [251] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table, 5),
  [253] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_table, 5),
  [255] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2),
  [257] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 2),
  [259] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__primary_expression, 1),
  [261] = {.entry = {.count = 1, .reusable = false}}, SHIFT(164),
  [263] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__primary_expression, 1),
  [265] = {.entry = {.count = 1, .reusable = false}}, SHIFT(163),
  [267] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [269] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [271] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [273] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [275] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [277] = {.entry = {.count = 1, .reusable = false}}, SHIFT(162),
  [279] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [281] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [283] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [285] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [289] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [291] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2),
  [293] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2),
  [295] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statements, 3),
  [297] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [299] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [301] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [303] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [307] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statements, 2),
  [309] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [311] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [313] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [315] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [317] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [319] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [323] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [325] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pipeline, 3),
  [327] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pipeline, 3),
  [329] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statements, 1),
  [331] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [333] = {.entry = {.count = 1, .reusable = false}}, SHIFT(92),
  [335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [337] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 4, .production_id = 2),
  [339] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_definition, 4, .production_id = 2),
  [341] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [343] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [345] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [347] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_variable_declaration, 4, .production_id = 3),
  [349] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_variable_declaration, 4, .production_id = 3),
  [351] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag, 1),
  [353] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [355] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [357] = {.entry = {.count = 1, .reusable = true}}, SHIFT(169),
  [359] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 1),
  [361] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [363] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [365] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_signature_repeat1, 2),
  [367] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_signature_repeat1, 2), SHIFT_REPEAT(109),
  [370] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_signature_repeat1, 2), SHIFT_REPEAT(111),
  [373] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statements, 2),
  [375] = {.entry = {.count = 1, .reusable = false}}, SHIFT(86),
  [377] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [379] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag, 4),
  [381] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [383] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 3),
  [385] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [387] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1),
  [389] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [391] = {.entry = {.count = 1, .reusable = false}}, SHIFT(100),
  [393] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [395] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [397] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [399] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [401] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statements, 1),
  [403] = {.entry = {.count = 1, .reusable = false}}, SHIFT(101),
  [405] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [407] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [409] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag, 3),
  [411] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [413] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [415] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [417] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_signature_repeat1, 1),
  [419] = {.entry = {.count = 1, .reusable = false}}, SHIFT(102),
  [421] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [423] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_table_repeat1, 2), SHIFT_REPEAT(136),
  [426] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_repeat1, 2),
  [428] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [430] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [432] = {.entry = {.count = 1, .reusable = true}}, SHIFT(157),
  [434] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [436] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [438] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 2),
  [440] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [442] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 4),
  [444] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag, 6),
  [446] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [448] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [450] = {.entry = {.count = 1, .reusable = false}}, SHIFT(152),
  [452] = {.entry = {.count = 1, .reusable = false}}, SHIFT(167),
  [454] = {.entry = {.count = 1, .reusable = false}}, SHIFT(146),
  [456] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [458] = {.entry = {.count = 1, .reusable = false}}, SHIFT(147),
  [460] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [462] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [464] = {.entry = {.count = 1, .reusable = false}}, SHIFT(148),
  [466] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_column_header_repeat1, 2),
  [468] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_column_header_repeat1, 2), SHIFT_REPEAT(172),
  [471] = {.entry = {.count = 1, .reusable = false}}, SHIFT(149),
  [473] = {.entry = {.count = 1, .reusable = true}}, SHIFT(183),
  [475] = {.entry = {.count = 1, .reusable = false}}, SHIFT(66),
  [477] = {.entry = {.count = 1, .reusable = false}}, SHIFT(140),
  [479] = {.entry = {.count = 1, .reusable = false}}, SHIFT(142),
  [481] = {.entry = {.count = 1, .reusable = false}}, SHIFT(165),
  [483] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_repeat2, 2),
  [485] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_repeat2, 2), SHIFT_REPEAT(148),
  [488] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2),
  [490] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2), SHIFT_REPEAT(149),
  [493] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [495] = {.entry = {.count = 1, .reusable = false}}, SHIFT(55),
  [497] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [499] = {.entry = {.count = 1, .reusable = false}}, SHIFT(151),
  [501] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [503] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_column_header, 2),
  [505] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [507] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [509] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [511] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [513] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [515] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [517] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_signature, 2),
  [519] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [521] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [523] = {.entry = {.count = 1, .reusable = true}}, SHIFT(159),
  [525] = {.entry = {.count = 1, .reusable = true}}, SHIFT(179),
  [527] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [529] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [531] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [533] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [535] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [537] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [539] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [541] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_signature, 3),
  [543] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [545] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_column_header, 3),
  [547] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [549] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [551] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_nu(void) {
  static TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = (const uint16_t *)ts_parse_table,
    .small_parse_table = (const uint16_t *)ts_small_parse_table,
    .small_parse_table_map = (const uint32_t *)ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = (const TSFieldMapSlice *)ts_field_map_slices,
    .field_map_entries = (const TSFieldMapEntry *)ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = (const TSSymbol *)ts_alias_sequences,
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
