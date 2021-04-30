#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 195
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 91
#define ALIAS_COUNT 0
#define TOKEN_COUNT 57
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 8
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 8

enum {
  sym_word = 1,
  anon_sym_def = 2,
  anon_sym_LBRACK = 3,
  anon_sym_COMMA = 4,
  anon_sym_RBRACK = 5,
  anon_sym_COLON = 6,
  anon_sym_QMARK = 7,
  anon_sym_LPAREN = 8,
  anon_sym_RPAREN = 9,
  sym_flag_name = 10,
  sym_flag_shorthand_name = 11,
  anon_sym_DOT_DOT_DOTrest = 12,
  anon_sym_int = 13,
  anon_sym_string = 14,
  anon_sym_path = 15,
  anon_sym_table = 16,
  anon_sym_unit = 17,
  anon_sym_number = 18,
  anon_sym_pattern = 19,
  anon_sym_range = 20,
  anon_sym_block = 21,
  anon_sym_any = 22,
  anon_sym_let = 23,
  anon_sym_EQ = 24,
  anon_sym_PIPE = 25,
  sym_number_literal = 26,
  anon_sym_DQUOTE = 27,
  anon_sym_SQUOTE = 28,
  sym_qouted_string_content = 29,
  sym_single_qouted_string_content = 30,
  anon_sym_DOLLAR = 31,
  anon_sym_DOT = 32,
  sym_file_path = 33,
  anon_sym_DOT_DOT = 34,
  anon_sym_DOLLAR_LPAREN = 35,
  sym_identifier = 36,
  anon_sym_SEMI = 37,
  anon_sym_LBRACE = 38,
  anon_sym_RBRACE = 39,
  sym_comment = 40,
  anon_sym_LF = 41,
  anon_sym_PLUS = 42,
  anon_sym_DASH = 43,
  anon_sym_STAR = 44,
  anon_sym_SLASH = 45,
  anon_sym_PERCENT = 46,
  anon_sym_PIPE_PIPE = 47,
  anon_sym_AMP_AMP = 48,
  anon_sym_EQ_EQ = 49,
  anon_sym_BANG_EQ = 50,
  anon_sym_GT = 51,
  anon_sym_GT_EQ = 52,
  anon_sym_LT_EQ = 53,
  anon_sym_LT = 54,
  anon_sym_LT_LT = 55,
  anon_sym_GT_GT = 56,
  sym_source_file = 57,
  sym__statements = 58,
  sym__statement = 59,
  sym_function_definition = 60,
  sym_signature = 61,
  sym_parameter = 62,
  sym_flag = 63,
  sym_rest = 64,
  sym_type = 65,
  sym_variable_declaration = 66,
  sym_command = 67,
  sym_pipeline = 68,
  sym__expression = 69,
  sym_string = 70,
  sym_value_path = 71,
  sym_range = 72,
  sym_command_substitution = 73,
  sym_math_mode = 74,
  sym_table = 75,
  sym_column_header = 76,
  sym_array = 77,
  sym_block = 78,
  sym__terminator = 79,
  sym__math_expression = 80,
  sym_parenthesized_math_expression = 81,
  sym_binary_expression = 82,
  aux_sym__statements_repeat1 = 83,
  aux_sym_signature_repeat1 = 84,
  aux_sym_command_repeat1 = 85,
  aux_sym_string_repeat1 = 86,
  aux_sym_string_repeat2 = 87,
  aux_sym_value_path_repeat1 = 88,
  aux_sym_table_repeat1 = 89,
  aux_sym_column_header_repeat1 = 90,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_word] = "word",
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
  [anon_sym_PIPE] = "|",
  [sym_number_literal] = "number_literal",
  [anon_sym_DQUOTE] = "\"",
  [anon_sym_SQUOTE] = "'",
  [sym_qouted_string_content] = "qouted_string_content",
  [sym_single_qouted_string_content] = "single_qouted_string_content",
  [anon_sym_DOLLAR] = "$",
  [anon_sym_DOT] = ".",
  [sym_file_path] = "file_path",
  [anon_sym_DOT_DOT] = "..",
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
  [sym_rest] = "rest",
  [sym_type] = "type",
  [sym_variable_declaration] = "variable_declaration",
  [sym_command] = "command",
  [sym_pipeline] = "pipeline",
  [sym__expression] = "_expression",
  [sym_string] = "string",
  [sym_value_path] = "value_path",
  [sym_range] = "range",
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
  [aux_sym_value_path_repeat1] = "value_path_repeat1",
  [aux_sym_table_repeat1] = "table_repeat1",
  [aux_sym_column_header_repeat1] = "column_header_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_word] = sym_word,
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
  [anon_sym_PIPE] = anon_sym_PIPE,
  [sym_number_literal] = sym_number_literal,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [sym_qouted_string_content] = sym_qouted_string_content,
  [sym_single_qouted_string_content] = sym_single_qouted_string_content,
  [anon_sym_DOLLAR] = anon_sym_DOLLAR,
  [anon_sym_DOT] = anon_sym_DOT,
  [sym_file_path] = sym_file_path,
  [anon_sym_DOT_DOT] = anon_sym_DOT_DOT,
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
  [sym_rest] = sym_rest,
  [sym_type] = sym_type,
  [sym_variable_declaration] = sym_variable_declaration,
  [sym_command] = sym_command,
  [sym_pipeline] = sym_pipeline,
  [sym__expression] = sym__expression,
  [sym_string] = sym_string,
  [sym_value_path] = sym_value_path,
  [sym_range] = sym_range,
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
  [aux_sym_value_path_repeat1] = aux_sym_value_path_repeat1,
  [aux_sym_table_repeat1] = aux_sym_table_repeat1,
  [aux_sym_column_header_repeat1] = aux_sym_column_header_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_word] = {
    .visible = true,
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
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [sym_number_literal] = {
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
  [anon_sym_DOLLAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [sym_file_path] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DOT_DOT] = {
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
  [sym_rest] = {
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
  [sym__expression] = {
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
  [sym_range] = {
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
  [aux_sym_value_path_repeat1] = {
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
  field_arg = 1,
  field_cmd_name = 2,
  field_func_name = 3,
  field_left = 4,
  field_name = 5,
  field_operator = 6,
  field_right = 7,
  field_value = 8,
};

static const char *ts_field_names[] = {
  [0] = NULL,
  [field_arg] = "arg",
  [field_cmd_name] = "cmd_name",
  [field_func_name] = "func_name",
  [field_left] = "left",
  [field_name] = "name",
  [field_operator] = "operator",
  [field_right] = "right",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 2},
  [4] = {.index = 4, .length = 2},
  [5] = {.index = 6, .length = 3},
  [6] = {.index = 9, .length = 1},
  [7] = {.index = 10, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_cmd_name, 0},
  [1] =
    {field_arg, 0},
  [2] =
    {field_arg, 1, .inherited = true},
    {field_cmd_name, 0},
  [4] =
    {field_arg, 0, .inherited = true},
    {field_arg, 1, .inherited = true},
  [6] =
    {field_left, 0},
    {field_operator, 1},
    {field_right, 2},
  [9] =
    {field_func_name, 1},
  [10] =
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
  return (c < '\''
    ? (c < '\r'
      ? (c < '\t'
        ? c == 0
        : c <= '\n')
      : (c <= '\r' || (c < '"'
        ? c == ' '
        : c <= '$')))
    : (c <= ')' || (c < '['
      ? (c < ';'
        ? c == '-'
        : c <= ';')
      : (c <= ']' || (c < '}'
        ? c == '{'
        : c <= '}')))));
}

static inline bool sym_word_character_set_2(int32_t c) {
  return (c < '\''
    ? (c < '\r'
      ? (c < '\t'
        ? c == 0
        : c <= '\n')
      : (c <= '\r' || (c < '"'
        ? c == ' '
        : c <= '$')))
    : (c <= ')' || (c < '['
      ? (c < ';'
        ? c == '-'
        : c <= ';')
      : (c <= ']' || (c >= '{' && c <= '}')))));
}

static inline bool sym_file_path_character_set_1(int32_t c) {
  return (c < '-'
    ? (c < ' '
      ? (c < '\r'
        ? (c >= '\t' && c <= '\n')
        : c <= '\r')
      : (c <= ' ' || (c < '\''
        ? (c >= '"' && c <= '$')
        : c <= ')')))
    : (c <= '-' || (c < '{'
      ? (c < '['
        ? c == ';'
        : c <= ']')
      : (c <= '{' || c == '}'))));
}

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(32);
      if (lookahead == '!') ADVANCE(63);
      if (lookahead == '"') ADVANCE(73);
      if (lookahead == '#') ADVANCE(103);
      if (lookahead == '$') ADVANCE(81);
      if (lookahead == '%') ADVANCE(114);
      if (lookahead == '&') ADVANCE(61);
      if (lookahead == '\'') ADVANCE(74);
      if (lookahead == '(') ADVANCE(43);
      if (lookahead == ')') ADVANCE(44);
      if (lookahead == '*') ADVANCE(110);
      if (lookahead == '+') ADVANCE(106);
      if (lookahead == ',') ADVANCE(37);
      if (lookahead == '-') ADVANCE(108);
      if (lookahead == '.') ADVANCE(83);
      if (lookahead == '/') ADVANCE(112);
      if (lookahead == ':') ADVANCE(40);
      if (lookahead == ';') ADVANCE(98);
      if (lookahead == '<') ADVANCE(129);
      if (lookahead == '=') ADVANCE(53);
      if (lookahead == '>') ADVANCE(123);
      if (lookahead == '?') ADVANCE(42);
      if (lookahead == '[') ADVANCE(35);
      if (lookahead == '\\') ADVANCE(11);
      if (lookahead == ']') ADVANCE(38);
      if (lookahead == 'd') ADVANCE(64);
      if (lookahead == 'l') ADVANCE(65);
      if (lookahead == '{') ADVANCE(99);
      if (lookahead == '|') ADVANCE(55);
      if (lookahead == '}') ADVANCE(100);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(57);
      if (lookahead != 0) ADVANCE(72);
      END_STATE();
    case 1:
      if (lookahead == '!') ADVANCE(13);
      if (lookahead == '"') ADVANCE(73);
      if (lookahead == '#') ADVANCE(103);
      if (lookahead == '%') ADVANCE(113);
      if (lookahead == '&') ADVANCE(7);
      if (lookahead == '\'') ADVANCE(74);
      if (lookahead == ')') ADVANCE(44);
      if (lookahead == '*') ADVANCE(109);
      if (lookahead == '+') ADVANCE(105);
      if (lookahead == '-') ADVANCE(107);
      if (lookahead == '.') ADVANCE(82);
      if (lookahead == '/') ADVANCE(111);
      if (lookahead == '<') ADVANCE(130);
      if (lookahead == '=') ADVANCE(14);
      if (lookahead == '>') ADVANCE(124);
      if (lookahead == '[') ADVANCE(35);
      if (lookahead == ']') ADVANCE(38);
      if (lookahead == '|') ADVANCE(19);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(96);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(73);
      if (lookahead == '#') ADVANCE(103);
      if (lookahead == '$') ADVANCE(81);
      if (lookahead == '\'') ADVANCE(74);
      if (lookahead == '.') ADVANCE(86);
      if (lookahead == '[') ADVANCE(35);
      if (lookahead == '\\') ADVANCE(12);
      if (lookahead == '{') ADVANCE(99);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(58);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(96);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(73);
      if (lookahead == '#') ADVANCE(75);
      if (lookahead == '\\') ADVANCE(27);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(76);
      if (lookahead != 0) ADVANCE(77);
      END_STATE();
    case 4:
      if (lookahead == '#') ADVANCE(103);
      if (lookahead == '(') ADVANCE(43);
      if (lookahead == ',') ADVANCE(36);
      if (lookahead == '-') ADVANCE(8);
      if (lookahead == '.') ADVANCE(10);
      if (lookahead == ':') ADVANCE(39);
      if (lookahead == '?') ADVANCE(41);
      if (lookahead == ']') ADVANCE(38);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(96);
      END_STATE();
    case 5:
      if (lookahead == '#') ADVANCE(103);
      if (lookahead == '\\') ADVANCE(25);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(5)
      if (lookahead != 0 &&
          (lookahead < '"' || '$' < lookahead) &&
          (lookahead < '\'' || ')' < lookahead) &&
          lookahead != '-' &&
          lookahead != ';' &&
          (lookahead < '[' || ']' < lookahead) &&
          lookahead != '{' &&
          lookahead != '}') ADVANCE(72);
      END_STATE();
    case 6:
      if (lookahead == '#') ADVANCE(78);
      if (lookahead == '\'') ADVANCE(74);
      if (lookahead == '\\') ADVANCE(26);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(79);
      if (lookahead != 0) ADVANCE(80);
      END_STATE();
    case 7:
      if (lookahead == '&') ADVANCE(117);
      END_STATE();
    case 8:
      if (lookahead == '-') ADVANCE(22);
      END_STATE();
    case 9:
      if (lookahead == '.') ADVANCE(16);
      END_STATE();
    case 10:
      if (lookahead == '.') ADVANCE(9);
      END_STATE();
    case 11:
      if (lookahead == '/') ADVANCE(62);
      if (lookahead == '\\') ADVANCE(62);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(88);
      if (lookahead != 0) ADVANCE(62);
      END_STATE();
    case 12:
      if (lookahead == '/') ADVANCE(21);
      if (lookahead == '\\') ADVANCE(21);
      if (lookahead != 0) ADVANCE(88);
      END_STATE();
    case 13:
      if (lookahead == '=') ADVANCE(121);
      END_STATE();
    case 14:
      if (lookahead == '=') ADVANCE(119);
      END_STATE();
    case 15:
      if (lookahead == 'e') ADVANCE(17);
      END_STATE();
    case 16:
      if (lookahead == 'r') ADVANCE(15);
      END_STATE();
    case 17:
      if (lookahead == 's') ADVANCE(18);
      END_STATE();
    case 18:
      if (lookahead == 't') ADVANCE(48);
      END_STATE();
    case 19:
      if (lookahead == '|') ADVANCE(115);
      END_STATE();
    case 20:
      if (lookahead == '/' ||
          lookahead == '\\') ADVANCE(62);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(88);
      if (lookahead != 0) ADVANCE(62);
      END_STATE();
    case 21:
      if (lookahead == '/' ||
          lookahead == '\\') ADVANCE(21);
      if (lookahead != 0) ADVANCE(88);
      END_STATE();
    case 22:
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 23:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(47);
      END_STATE();
    case 24:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(97);
      END_STATE();
    case 25:
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(72);
      END_STATE();
    case 26:
      if (lookahead != 0) ADVANCE(80);
      END_STATE();
    case 27:
      if (lookahead != 0) ADVANCE(77);
      END_STATE();
    case 28:
      if (eof) ADVANCE(32);
      if (lookahead == '\n') ADVANCE(104);
      if (lookahead == '!') ADVANCE(13);
      if (lookahead == '"') ADVANCE(73);
      if (lookahead == '#') ADVANCE(103);
      if (lookahead == '$') ADVANCE(81);
      if (lookahead == '%') ADVANCE(113);
      if (lookahead == '&') ADVANCE(7);
      if (lookahead == '\'') ADVANCE(74);
      if (lookahead == ')') ADVANCE(44);
      if (lookahead == '*') ADVANCE(109);
      if (lookahead == '+') ADVANCE(105);
      if (lookahead == '-') ADVANCE(107);
      if (lookahead == '.') ADVANCE(84);
      if (lookahead == '/') ADVANCE(111);
      if (lookahead == ';') ADVANCE(98);
      if (lookahead == '<') ADVANCE(130);
      if (lookahead == '=') ADVANCE(14);
      if (lookahead == '>') ADVANCE(124);
      if (lookahead == '[') ADVANCE(35);
      if (lookahead == '\\') ADVANCE(12);
      if (lookahead == '{') ADVANCE(99);
      if (lookahead == '|') ADVANCE(56);
      if (lookahead == '}') ADVANCE(100);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(28)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(58);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(96);
      END_STATE();
    case 29:
      if (eof) ADVANCE(32);
      if (lookahead == '\n') ADVANCE(104);
      if (lookahead == '!') ADVANCE(13);
      if (lookahead == '"') ADVANCE(73);
      if (lookahead == '#') ADVANCE(103);
      if (lookahead == '$') ADVANCE(81);
      if (lookahead == '%') ADVANCE(113);
      if (lookahead == '&') ADVANCE(7);
      if (lookahead == '\'') ADVANCE(74);
      if (lookahead == ')') ADVANCE(44);
      if (lookahead == '*') ADVANCE(109);
      if (lookahead == '+') ADVANCE(105);
      if (lookahead == '-') ADVANCE(107);
      if (lookahead == '.') ADVANCE(86);
      if (lookahead == '/') ADVANCE(111);
      if (lookahead == ';') ADVANCE(98);
      if (lookahead == '<') ADVANCE(130);
      if (lookahead == '=') ADVANCE(14);
      if (lookahead == '>') ADVANCE(124);
      if (lookahead == '[') ADVANCE(35);
      if (lookahead == '\\') ADVANCE(12);
      if (lookahead == '{') ADVANCE(99);
      if (lookahead == '|') ADVANCE(56);
      if (lookahead == '}') ADVANCE(100);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(29)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(58);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(96);
      END_STATE();
    case 30:
      if (eof) ADVANCE(32);
      if (lookahead == '\n') ADVANCE(104);
      if (lookahead == '"') ADVANCE(73);
      if (lookahead == '#') ADVANCE(103);
      if (lookahead == '$') ADVANCE(81);
      if (lookahead == '\'') ADVANCE(74);
      if (lookahead == ')') ADVANCE(44);
      if (lookahead == '.') ADVANCE(87);
      if (lookahead == ';') ADVANCE(98);
      if (lookahead == '[') ADVANCE(35);
      if (lookahead == '\\') ADVANCE(12);
      if (lookahead == '{') ADVANCE(99);
      if (lookahead == '|') ADVANCE(54);
      if (lookahead == '}') ADVANCE(100);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(30)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(58);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(96);
      END_STATE();
    case 31:
      if (eof) ADVANCE(32);
      if (lookahead == '#') ADVANCE(103);
      if (lookahead == '$') ADVANCE(81);
      if (lookahead == '(') ADVANCE(43);
      if (lookahead == ')') ADVANCE(44);
      if (lookahead == ',') ADVANCE(36);
      if (lookahead == '-') ADVANCE(23);
      if (lookahead == '=') ADVANCE(52);
      if (lookahead == 'd') ADVANCE(92);
      if (lookahead == 'l') ADVANCE(93);
      if (lookahead == '{') ADVANCE(99);
      if (lookahead == '}') ADVANCE(100);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(31)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(58);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(96);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_def);
      if (lookahead == '-') ADVANCE(24);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(97);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(96);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_def);
      if (lookahead == '\\') ADVANCE(25);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_COMMA);
      if (lookahead == '\\') ADVANCE(25);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == '\\') ADVANCE(25);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_QMARK);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_QMARK);
      if (lookahead == '\\') ADVANCE(25);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_flag_name);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(46);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(45);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_flag_name);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(46);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_flag_shorthand_name);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_DOT_DOT_DOTrest);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_DOT_DOT_DOTrest);
      if (lookahead == '\\') ADVANCE(25);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_let);
      if (lookahead == '-') ADVANCE(24);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(97);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(96);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_let);
      if (lookahead == '\\') ADVANCE(25);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(120);
      if (lookahead == '\\') ADVANCE(25);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '\\') ADVANCE(25);
      if (lookahead == '|') ADVANCE(116);
      if (!sym_word_character_set_2(lookahead)) ADVANCE(72);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '|') ADVANCE(115);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_number_literal);
      if (lookahead == '.') ADVANCE(59);
      if (lookahead == '\\') ADVANCE(25);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(57);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_number_literal);
      if (lookahead == '.') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(58);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_number_literal);
      if (lookahead == '\\') ADVANCE(25);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(59);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_number_literal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(60);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '&') ADVANCE(118);
      if (lookahead == '\\') ADVANCE(25);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '/') ADVANCE(62);
      if (lookahead == '\\') ADVANCE(20);
      if (sym_file_path_character_set_1(lookahead)) ADVANCE(88);
      if (lookahead != 0) ADVANCE(62);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '=') ADVANCE(122);
      if (lookahead == '\\') ADVANCE(25);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(25);
      if (lookahead == 'e') ADVANCE(67);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(25);
      if (lookahead == 'e') ADVANCE(70);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(25);
      if (lookahead == 'e') ADVANCE(69);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(25);
      if (lookahead == 'f') ADVANCE(34);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(25);
      if (lookahead == 'r') ADVANCE(66);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(25);
      if (lookahead == 's') ADVANCE(71);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(25);
      if (lookahead == 't') ADVANCE(51);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(25);
      if (lookahead == 't') ADVANCE(49);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(25);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_qouted_string_content);
      if (lookahead == '\n') ADVANCE(77);
      if (lookahead == '\\') ADVANCE(102);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(75);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_qouted_string_content);
      if (lookahead == '"') ADVANCE(73);
      if (lookahead == '#') ADVANCE(75);
      if (lookahead == '\\') ADVANCE(27);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(76);
      if (lookahead != 0) ADVANCE(77);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_qouted_string_content);
      if (lookahead == '\\') ADVANCE(27);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(77);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_single_qouted_string_content);
      if (lookahead == '\n') ADVANCE(80);
      if (lookahead == '\\') ADVANCE(101);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(78);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_single_qouted_string_content);
      if (lookahead == '#') ADVANCE(78);
      if (lookahead == '\'') ADVANCE(74);
      if (lookahead == '\\') ADVANCE(26);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(79);
      if (lookahead != 0) ADVANCE(80);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_single_qouted_string_content);
      if (lookahead == '\\') ADVANCE(26);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(80);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      if (lookahead == '(') ADVANCE(91);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_DOT);
      if (lookahead == '.') ADVANCE(90);
      if (lookahead == '\\') ADVANCE(25);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_DOT);
      if (lookahead == '.') ADVANCE(85);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym_file_path);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym_file_path);
      if (lookahead == '.') ADVANCE(85);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(sym_file_path);
      if (lookahead == '.') ADVANCE(89);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym_file_path);
      if (lookahead == '/' ||
          lookahead == '\\') ADVANCE(21);
      if (lookahead != 0) ADVANCE(88);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_DOT_DOT);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_DOT_DOT);
      if (lookahead == '.') ADVANCE(68);
      if (lookahead == '\\') ADVANCE(25);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_DOLLAR_LPAREN);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(24);
      if (lookahead == 'e') ADVANCE(94);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(97);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(96);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(24);
      if (lookahead == 'e') ADVANCE(95);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(97);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(96);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(24);
      if (lookahead == 'f') ADVANCE(33);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(97);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(96);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(24);
      if (lookahead == 't') ADVANCE(50);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(97);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(96);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(24);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(97);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(96);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(24);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(97);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead == '\n') ADVANCE(80);
      if (lookahead != 0) ADVANCE(78);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead == '\n') ADVANCE(77);
      if (lookahead != 0) ADVANCE(75);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(103);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(104);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '\\') ADVANCE(25);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '-') ADVANCE(22);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '\\') ADVANCE(25);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '\\') ADVANCE(25);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '\\') ADVANCE(25);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
      if (lookahead == '\\') ADVANCE(25);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      if (lookahead == '\\') ADVANCE(25);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      if (lookahead == '\\') ADVANCE(25);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_BANG_EQ);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_BANG_EQ);
      if (lookahead == '\\') ADVANCE(25);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(126);
      if (lookahead == '>') ADVANCE(134);
      if (lookahead == '\\') ADVANCE(25);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(125);
      if (lookahead == '>') ADVANCE(133);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      if (lookahead == '\\') ADVANCE(25);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      if (lookahead == '\\') ADVANCE(25);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '<') ADVANCE(132);
      if (lookahead == '=') ADVANCE(128);
      if (lookahead == '\\') ADVANCE(25);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '<') ADVANCE(131);
      if (lookahead == '=') ADVANCE(127);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(anon_sym_LT_LT);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(anon_sym_LT_LT);
      if (lookahead == '\\') ADVANCE(25);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_GT_GT);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(anon_sym_GT_GT);
      if (lookahead == '\\') ADVANCE(25);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(72);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (lookahead == 'a') ADVANCE(1);
      if (lookahead == 'b') ADVANCE(2);
      if (lookahead == 'i') ADVANCE(3);
      if (lookahead == 'n') ADVANCE(4);
      if (lookahead == 'p') ADVANCE(5);
      if (lookahead == 'r') ADVANCE(6);
      if (lookahead == 's') ADVANCE(7);
      if (lookahead == 't') ADVANCE(8);
      if (lookahead == 'u') ADVANCE(9);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == 'n') ADVANCE(10);
      END_STATE();
    case 2:
      if (lookahead == 'l') ADVANCE(11);
      END_STATE();
    case 3:
      if (lookahead == 'n') ADVANCE(12);
      END_STATE();
    case 4:
      if (lookahead == 'u') ADVANCE(13);
      END_STATE();
    case 5:
      if (lookahead == 'a') ADVANCE(14);
      END_STATE();
    case 6:
      if (lookahead == 'a') ADVANCE(15);
      END_STATE();
    case 7:
      if (lookahead == 't') ADVANCE(16);
      END_STATE();
    case 8:
      if (lookahead == 'a') ADVANCE(17);
      END_STATE();
    case 9:
      if (lookahead == 'n') ADVANCE(18);
      END_STATE();
    case 10:
      if (lookahead == 'y') ADVANCE(19);
      END_STATE();
    case 11:
      if (lookahead == 'o') ADVANCE(20);
      END_STATE();
    case 12:
      if (lookahead == 't') ADVANCE(21);
      END_STATE();
    case 13:
      if (lookahead == 'm') ADVANCE(22);
      END_STATE();
    case 14:
      if (lookahead == 't') ADVANCE(23);
      END_STATE();
    case 15:
      if (lookahead == 'n') ADVANCE(24);
      END_STATE();
    case 16:
      if (lookahead == 'r') ADVANCE(25);
      END_STATE();
    case 17:
      if (lookahead == 'b') ADVANCE(26);
      END_STATE();
    case 18:
      if (lookahead == 'i') ADVANCE(27);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_any);
      END_STATE();
    case 20:
      if (lookahead == 'c') ADVANCE(28);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_int);
      END_STATE();
    case 22:
      if (lookahead == 'b') ADVANCE(29);
      END_STATE();
    case 23:
      if (lookahead == 'h') ADVANCE(30);
      if (lookahead == 't') ADVANCE(31);
      END_STATE();
    case 24:
      if (lookahead == 'g') ADVANCE(32);
      END_STATE();
    case 25:
      if (lookahead == 'i') ADVANCE(33);
      END_STATE();
    case 26:
      if (lookahead == 'l') ADVANCE(34);
      END_STATE();
    case 27:
      if (lookahead == 't') ADVANCE(35);
      END_STATE();
    case 28:
      if (lookahead == 'k') ADVANCE(36);
      END_STATE();
    case 29:
      if (lookahead == 'e') ADVANCE(37);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_path);
      END_STATE();
    case 31:
      if (lookahead == 'e') ADVANCE(38);
      END_STATE();
    case 32:
      if (lookahead == 'e') ADVANCE(39);
      END_STATE();
    case 33:
      if (lookahead == 'n') ADVANCE(40);
      END_STATE();
    case 34:
      if (lookahead == 'e') ADVANCE(41);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_unit);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_block);
      END_STATE();
    case 37:
      if (lookahead == 'r') ADVANCE(42);
      END_STATE();
    case 38:
      if (lookahead == 'r') ADVANCE(43);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_range);
      END_STATE();
    case 40:
      if (lookahead == 'g') ADVANCE(44);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_table);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_number);
      END_STATE();
    case 43:
      if (lookahead == 'n') ADVANCE(45);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_string);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_pattern);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 31},
  [2] = {.lex_state = 28},
  [3] = {.lex_state = 28},
  [4] = {.lex_state = 28},
  [5] = {.lex_state = 28},
  [6] = {.lex_state = 29},
  [7] = {.lex_state = 29},
  [8] = {.lex_state = 29},
  [9] = {.lex_state = 29},
  [10] = {.lex_state = 29},
  [11] = {.lex_state = 31},
  [12] = {.lex_state = 31},
  [13] = {.lex_state = 29},
  [14] = {.lex_state = 31},
  [15] = {.lex_state = 29},
  [16] = {.lex_state = 31},
  [17] = {.lex_state = 31},
  [18] = {.lex_state = 29},
  [19] = {.lex_state = 28},
  [20] = {.lex_state = 28},
  [21] = {.lex_state = 28},
  [22] = {.lex_state = 28},
  [23] = {.lex_state = 28},
  [24] = {.lex_state = 28},
  [25] = {.lex_state = 28},
  [26] = {.lex_state = 31},
  [27] = {.lex_state = 28},
  [28] = {.lex_state = 31},
  [29] = {.lex_state = 31},
  [30] = {.lex_state = 28},
  [31] = {.lex_state = 31},
  [32] = {.lex_state = 31},
  [33] = {.lex_state = 1},
  [34] = {.lex_state = 2},
  [35] = {.lex_state = 1},
  [36] = {.lex_state = 1},
  [37] = {.lex_state = 1},
  [38] = {.lex_state = 28},
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
  [49] = {.lex_state = 30},
  [50] = {.lex_state = 1},
  [51] = {.lex_state = 1},
  [52] = {.lex_state = 1},
  [53] = {.lex_state = 28},
  [54] = {.lex_state = 28},
  [55] = {.lex_state = 1},
  [56] = {.lex_state = 1},
  [57] = {.lex_state = 29},
  [58] = {.lex_state = 29},
  [59] = {.lex_state = 29},
  [60] = {.lex_state = 28},
  [61] = {.lex_state = 29},
  [62] = {.lex_state = 29},
  [63] = {.lex_state = 29},
  [64] = {.lex_state = 30},
  [65] = {.lex_state = 29},
  [66] = {.lex_state = 29},
  [67] = {.lex_state = 29},
  [68] = {.lex_state = 29},
  [69] = {.lex_state = 29},
  [70] = {.lex_state = 29},
  [71] = {.lex_state = 29},
  [72] = {.lex_state = 29},
  [73] = {.lex_state = 29},
  [74] = {.lex_state = 29},
  [75] = {.lex_state = 29},
  [76] = {.lex_state = 29},
  [77] = {.lex_state = 29},
  [78] = {.lex_state = 29},
  [79] = {.lex_state = 29},
  [80] = {.lex_state = 29},
  [81] = {.lex_state = 5},
  [82] = {.lex_state = 5},
  [83] = {.lex_state = 5},
  [84] = {.lex_state = 5},
  [85] = {.lex_state = 31},
  [86] = {.lex_state = 31},
  [87] = {.lex_state = 31},
  [88] = {.lex_state = 31},
  [89] = {.lex_state = 31},
  [90] = {.lex_state = 31},
  [91] = {.lex_state = 31},
  [92] = {.lex_state = 31},
  [93] = {.lex_state = 31},
  [94] = {.lex_state = 31},
  [95] = {.lex_state = 31},
  [96] = {.lex_state = 31},
  [97] = {.lex_state = 31},
  [98] = {.lex_state = 31},
  [99] = {.lex_state = 31},
  [100] = {.lex_state = 31},
  [101] = {.lex_state = 31},
  [102] = {.lex_state = 31},
  [103] = {.lex_state = 31},
  [104] = {.lex_state = 31},
  [105] = {.lex_state = 31},
  [106] = {.lex_state = 31},
  [107] = {.lex_state = 31},
  [108] = {.lex_state = 31},
  [109] = {.lex_state = 4},
  [110] = {.lex_state = 4},
  [111] = {.lex_state = 4},
  [112] = {.lex_state = 4},
  [113] = {.lex_state = 4},
  [114] = {.lex_state = 4},
  [115] = {.lex_state = 4},
  [116] = {.lex_state = 28},
  [117] = {.lex_state = 28},
  [118] = {.lex_state = 28},
  [119] = {.lex_state = 28},
  [120] = {.lex_state = 4},
  [121] = {.lex_state = 4},
  [122] = {.lex_state = 28},
  [123] = {.lex_state = 4},
  [124] = {.lex_state = 4},
  [125] = {.lex_state = 4},
  [126] = {.lex_state = 1},
  [127] = {.lex_state = 4},
  [128] = {.lex_state = 28},
  [129] = {.lex_state = 1},
  [130] = {.lex_state = 28},
  [131] = {.lex_state = 4},
  [132] = {.lex_state = 4},
  [133] = {.lex_state = 0},
  [134] = {.lex_state = 1},
  [135] = {.lex_state = 0},
  [136] = {.lex_state = 4},
  [137] = {.lex_state = 28},
  [138] = {.lex_state = 0},
  [139] = {.lex_state = 0},
  [140] = {.lex_state = 0},
  [141] = {.lex_state = 6},
  [142] = {.lex_state = 1},
  [143] = {.lex_state = 1},
  [144] = {.lex_state = 6},
  [145] = {.lex_state = 3},
  [146] = {.lex_state = 3},
  [147] = {.lex_state = 1},
  [148] = {.lex_state = 6},
  [149] = {.lex_state = 3},
  [150] = {.lex_state = 1},
  [151] = {.lex_state = 6},
  [152] = {.lex_state = 3},
  [153] = {.lex_state = 3},
  [154] = {.lex_state = 6},
  [155] = {.lex_state = 1},
  [156] = {.lex_state = 1},
  [157] = {.lex_state = 6},
  [158] = {.lex_state = 6},
  [159] = {.lex_state = 1},
  [160] = {.lex_state = 3},
  [161] = {.lex_state = 3},
  [162] = {.lex_state = 0},
  [163] = {.lex_state = 0},
  [164] = {.lex_state = 0},
  [165] = {.lex_state = 0},
  [166] = {.lex_state = 1},
  [167] = {.lex_state = 0},
  [168] = {.lex_state = 1},
  [169] = {.lex_state = 0},
  [170] = {.lex_state = 0},
  [171] = {.lex_state = 0},
  [172] = {.lex_state = 1},
  [173] = {.lex_state = 1},
  [174] = {.lex_state = 1},
  [175] = {.lex_state = 0},
  [176] = {.lex_state = 31},
  [177] = {.lex_state = 31},
  [178] = {.lex_state = 0},
  [179] = {.lex_state = 0},
  [180] = {.lex_state = 0},
  [181] = {.lex_state = 0},
  [182] = {.lex_state = 31},
  [183] = {.lex_state = 0},
  [184] = {.lex_state = 31},
  [185] = {.lex_state = 0},
  [186] = {.lex_state = 1},
  [187] = {.lex_state = 1},
  [188] = {.lex_state = 31},
  [189] = {.lex_state = 0},
  [190] = {.lex_state = 1},
  [191] = {.lex_state = 0},
  [192] = {.lex_state = 0},
  [193] = {.lex_state = 0},
  [194] = {.lex_state = 0},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_word] = ACTIONS(1),
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
    [anon_sym_DOLLAR] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [sym_file_path] = ACTIONS(1),
    [anon_sym_DOT_DOT] = ACTIONS(1),
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
    [anon_sym_EQ_EQ] = ACTIONS(1),
    [anon_sym_BANG_EQ] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_GT_EQ] = ACTIONS(1),
    [anon_sym_LT_EQ] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_LT_LT] = ACTIONS(1),
    [anon_sym_GT_GT] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(175),
    [sym__statements] = STATE(180),
    [sym__statement] = STATE(128),
    [sym_function_definition] = STATE(128),
    [sym_variable_declaration] = STATE(128),
    [sym_command] = STATE(128),
    [sym_pipeline] = STATE(128),
    [sym_value_path] = STATE(27),
    [sym_command_substitution] = STATE(27),
    [sym_math_mode] = STATE(27),
    [sym_block] = STATE(128),
    [sym__math_expression] = STATE(27),
    [sym_parenthesized_math_expression] = STATE(27),
    [sym_binary_expression] = STATE(27),
    [aux_sym__statements_repeat1] = STATE(26),
    [ts_builtin_sym_end] = ACTIONS(5),
    [anon_sym_def] = ACTIONS(7),
    [anon_sym_LPAREN] = ACTIONS(9),
    [anon_sym_let] = ACTIONS(11),
    [sym_number_literal] = ACTIONS(13),
    [anon_sym_DOLLAR] = ACTIONS(15),
    [anon_sym_DOLLAR_LPAREN] = ACTIONS(17),
    [sym_identifier] = ACTIONS(19),
    [anon_sym_LBRACE] = ACTIONS(21),
    [sym_comment] = ACTIONS(3),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(29), 1,
      sym_comment,
    STATE(4), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(23), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(25), 28,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
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
  [44] = 5,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(35), 1,
      anon_sym_DOT,
    STATE(3), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(31), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(33), 28,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
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
  [88] = 5,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(29), 1,
      sym_comment,
    STATE(3), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(38), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(40), 28,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
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
  [132] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(31), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(33), 29,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      anon_sym_DOT,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
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
  [171] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(42), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(44), 28,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
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
  [209] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(46), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(48), 28,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
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
  [247] = 13,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(50), 1,
      anon_sym_LBRACK,
    ACTIONS(54), 1,
      sym_number_literal,
    ACTIONS(56), 1,
      anon_sym_DQUOTE,
    ACTIONS(58), 1,
      anon_sym_SQUOTE,
    ACTIONS(60), 1,
      anon_sym_DOLLAR,
    ACTIONS(64), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(66), 1,
      anon_sym_LBRACE,
    ACTIONS(68), 1,
      anon_sym_LF,
    STATE(9), 1,
      aux_sym_command_repeat1,
    ACTIONS(62), 2,
      sym_file_path,
      sym_identifier,
    ACTIONS(52), 4,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
    STATE(75), 9,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_range,
      sym_command_substitution,
      sym_math_mode,
      sym_table,
      sym_array,
      sym_block,
  [299] = 13,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(50), 1,
      anon_sym_LBRACK,
    ACTIONS(54), 1,
      sym_number_literal,
    ACTIONS(56), 1,
      anon_sym_DQUOTE,
    ACTIONS(58), 1,
      anon_sym_SQUOTE,
    ACTIONS(60), 1,
      anon_sym_DOLLAR,
    ACTIONS(64), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(66), 1,
      anon_sym_LBRACE,
    ACTIONS(72), 1,
      anon_sym_LF,
    STATE(10), 1,
      aux_sym_command_repeat1,
    ACTIONS(62), 2,
      sym_file_path,
      sym_identifier,
    ACTIONS(70), 4,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
    STATE(75), 9,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_range,
      sym_command_substitution,
      sym_math_mode,
      sym_table,
      sym_array,
      sym_block,
  [351] = 13,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(74), 1,
      anon_sym_LBRACK,
    ACTIONS(79), 1,
      sym_number_literal,
    ACTIONS(82), 1,
      anon_sym_DQUOTE,
    ACTIONS(85), 1,
      anon_sym_SQUOTE,
    ACTIONS(88), 1,
      anon_sym_DOLLAR,
    ACTIONS(94), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(97), 1,
      anon_sym_LBRACE,
    ACTIONS(100), 1,
      anon_sym_LF,
    STATE(10), 1,
      aux_sym_command_repeat1,
    ACTIONS(91), 2,
      sym_file_path,
      sym_identifier,
    ACTIONS(77), 4,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
    STATE(75), 9,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_range,
      sym_command_substitution,
      sym_math_mode,
      sym_table,
      sym_array,
      sym_block,
  [403] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_def,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_let,
    ACTIONS(13), 1,
      sym_number_literal,
    ACTIONS(15), 1,
      anon_sym_DOLLAR,
    ACTIONS(17), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    ACTIONS(102), 1,
      anon_sym_EQ,
    ACTIONS(104), 1,
      sym_identifier,
    STATE(29), 1,
      aux_sym__statements_repeat1,
    STATE(183), 1,
      sym__statements,
    STATE(27), 6,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(122), 6,
      sym__statement,
      sym_function_definition,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_block,
  [456] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_def,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_let,
    ACTIONS(13), 1,
      sym_number_literal,
    ACTIONS(15), 1,
      anon_sym_DOLLAR,
    ACTIONS(17), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    ACTIONS(104), 1,
      sym_identifier,
    ACTIONS(106), 1,
      anon_sym_EQ,
    STATE(29), 1,
      aux_sym__statements_repeat1,
    STATE(169), 1,
      sym__statements,
    STATE(27), 6,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(122), 6,
      sym__statement,
      sym_function_definition,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_block,
  [509] = 13,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(108), 1,
      anon_sym_LBRACK,
    ACTIONS(111), 1,
      sym_number_literal,
    ACTIONS(114), 1,
      anon_sym_DQUOTE,
    ACTIONS(117), 1,
      anon_sym_SQUOTE,
    ACTIONS(120), 1,
      anon_sym_DOLLAR,
    ACTIONS(126), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(129), 1,
      anon_sym_LBRACE,
    STATE(13), 1,
      aux_sym_command_repeat1,
    ACTIONS(77), 2,
      anon_sym_PIPE,
      anon_sym_SEMI,
    ACTIONS(100), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(123), 2,
      sym_file_path,
      sym_identifier,
    STATE(80), 9,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_range,
      sym_command_substitution,
      sym_math_mode,
      sym_table,
      sym_array,
      sym_block,
  [560] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_def,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_let,
    ACTIONS(13), 1,
      sym_number_literal,
    ACTIONS(15), 1,
      anon_sym_DOLLAR,
    ACTIONS(17), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    ACTIONS(104), 1,
      sym_identifier,
    ACTIONS(132), 1,
      anon_sym_EQ,
    STATE(29), 1,
      aux_sym__statements_repeat1,
    STATE(185), 1,
      sym__statements,
    STATE(27), 6,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(122), 6,
      sym__statement,
      sym_function_definition,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_block,
  [613] = 13,
    ACTIONS(15), 1,
      anon_sym_DOLLAR,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(134), 1,
      anon_sym_LBRACK,
    ACTIONS(136), 1,
      sym_number_literal,
    ACTIONS(138), 1,
      anon_sym_DQUOTE,
    ACTIONS(140), 1,
      anon_sym_SQUOTE,
    ACTIONS(144), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(146), 1,
      anon_sym_LBRACE,
    STATE(18), 1,
      aux_sym_command_repeat1,
    ACTIONS(52), 2,
      anon_sym_PIPE,
      anon_sym_SEMI,
    ACTIONS(68), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(142), 2,
      sym_file_path,
      sym_identifier,
    STATE(80), 9,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_range,
      sym_command_substitution,
      sym_math_mode,
      sym_table,
      sym_array,
      sym_block,
  [664] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_def,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_let,
    ACTIONS(13), 1,
      sym_number_literal,
    ACTIONS(15), 1,
      anon_sym_DOLLAR,
    ACTIONS(17), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    ACTIONS(104), 1,
      sym_identifier,
    ACTIONS(148), 1,
      anon_sym_RBRACE,
    STATE(29), 1,
      aux_sym__statements_repeat1,
    STATE(191), 1,
      sym__statements,
    STATE(27), 6,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(122), 6,
      sym__statement,
      sym_function_definition,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_block,
  [717] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_def,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_let,
    ACTIONS(13), 1,
      sym_number_literal,
    ACTIONS(15), 1,
      anon_sym_DOLLAR,
    ACTIONS(17), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    ACTIONS(104), 1,
      sym_identifier,
    ACTIONS(150), 1,
      anon_sym_RBRACE,
    STATE(29), 1,
      aux_sym__statements_repeat1,
    STATE(171), 1,
      sym__statements,
    STATE(27), 6,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(122), 6,
      sym__statement,
      sym_function_definition,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_block,
  [770] = 13,
    ACTIONS(15), 1,
      anon_sym_DOLLAR,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(134), 1,
      anon_sym_LBRACK,
    ACTIONS(136), 1,
      sym_number_literal,
    ACTIONS(138), 1,
      anon_sym_DQUOTE,
    ACTIONS(140), 1,
      anon_sym_SQUOTE,
    ACTIONS(144), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(146), 1,
      anon_sym_LBRACE,
    STATE(13), 1,
      aux_sym_command_repeat1,
    ACTIONS(70), 2,
      anon_sym_PIPE,
      anon_sym_SEMI,
    ACTIONS(72), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(142), 2,
      sym_file_path,
      sym_identifier,
    STATE(80), 9,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_range,
      sym_command_substitution,
      sym_math_mode,
      sym_table,
      sym_array,
      sym_block,
  [821] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(152), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(154), 19,
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
  [850] = 9,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(164), 1,
      anon_sym_AMP_AMP,
    ACTIONS(156), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(160), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(166), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(170), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(162), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(168), 4,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
    ACTIONS(158), 5,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_PIPE_PIPE,
  [891] = 5,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(156), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(160), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(162), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(158), 14,
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
  [924] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(156), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(158), 19,
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
  [953] = 8,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(156), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(160), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(166), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(170), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(162), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(168), 4,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
    ACTIONS(158), 6,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
  [992] = 7,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(156), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(160), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(170), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(162), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(168), 4,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
    ACTIONS(158), 8,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [1029] = 4,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(156), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(162), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(158), 16,
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
  [1060] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_def,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_let,
    ACTIONS(13), 1,
      sym_number_literal,
    ACTIONS(15), 1,
      anon_sym_DOLLAR,
    ACTIONS(17), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(19), 1,
      sym_identifier,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    STATE(28), 1,
      aux_sym__statements_repeat1,
    STATE(27), 6,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(130), 6,
      sym__statement,
      sym_function_definition,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_block,
  [1107] = 10,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(164), 1,
      anon_sym_AMP_AMP,
    ACTIONS(176), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(160), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(166), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(170), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(172), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(162), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(168), 4,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
    ACTIONS(174), 4,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
  [1150] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(178), 1,
      anon_sym_def,
    ACTIONS(181), 1,
      anon_sym_LPAREN,
    ACTIONS(184), 1,
      anon_sym_let,
    ACTIONS(187), 1,
      sym_number_literal,
    ACTIONS(190), 1,
      anon_sym_DOLLAR,
    ACTIONS(193), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(196), 1,
      sym_identifier,
    ACTIONS(199), 1,
      anon_sym_LBRACE,
    STATE(28), 1,
      aux_sym__statements_repeat1,
    STATE(27), 6,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(137), 6,
      sym__statement,
      sym_function_definition,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_block,
  [1197] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_def,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_let,
    ACTIONS(13), 1,
      sym_number_literal,
    ACTIONS(15), 1,
      anon_sym_DOLLAR,
    ACTIONS(17), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    ACTIONS(104), 1,
      sym_identifier,
    STATE(28), 1,
      aux_sym__statements_repeat1,
    STATE(27), 6,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(119), 6,
      sym__statement,
      sym_function_definition,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_block,
  [1244] = 6,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(156), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(160), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(170), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(162), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(158), 12,
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
  [1279] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_def,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_let,
    ACTIONS(13), 1,
      sym_number_literal,
    ACTIONS(15), 1,
      anon_sym_DOLLAR,
    ACTIONS(17), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(19), 1,
      sym_identifier,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    STATE(27), 6,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(118), 6,
      sym__statement,
      sym_function_definition,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_block,
  [1323] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_def,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(11), 1,
      anon_sym_let,
    ACTIONS(13), 1,
      sym_number_literal,
    ACTIONS(15), 1,
      anon_sym_DOLLAR,
    ACTIONS(17), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    ACTIONS(104), 1,
      sym_identifier,
    STATE(27), 6,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(118), 6,
      sym__statement,
      sym_function_definition,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_block,
  [1367] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(202), 1,
      anon_sym_DOT,
    STATE(33), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(33), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(31), 14,
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
  [1397] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(15), 1,
      anon_sym_DOLLAR,
    ACTIONS(17), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    ACTIONS(205), 1,
      anon_sym_LBRACK,
    ACTIONS(207), 1,
      sym_number_literal,
    ACTIONS(209), 1,
      anon_sym_DQUOTE,
    ACTIONS(211), 1,
      anon_sym_SQUOTE,
    ACTIONS(213), 2,
      sym_file_path,
      sym_identifier,
    STATE(116), 9,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_range,
      sym_command_substitution,
      sym_math_mode,
      sym_table,
      sym_array,
      sym_block,
  [1437] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(215), 1,
      anon_sym_DOT,
    STATE(33), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(40), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(38), 14,
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
  [1467] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(215), 1,
      anon_sym_DOT,
    STATE(35), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(25), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(23), 14,
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
  [1497] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(33), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(31), 15,
      anon_sym_RPAREN,
      anon_sym_DOT,
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
  [1522] = 5,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(38), 1,
      anon_sym_LF,
    ACTIONS(217), 1,
      anon_sym_DOT,
    STATE(54), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(40), 13,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [1550] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(154), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(152), 14,
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
  [1574] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(158), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(156), 14,
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
  [1598] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(48), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(46), 14,
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
  [1622] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(158), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(219), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(156), 11,
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
  [1648] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(221), 1,
      anon_sym_RPAREN,
    ACTIONS(225), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(227), 1,
      anon_sym_AMP_AMP,
    ACTIONS(223), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(229), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(231), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(233), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(219), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [1686] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(227), 1,
      anon_sym_AMP_AMP,
    ACTIONS(156), 2,
      anon_sym_RPAREN,
      anon_sym_PIPE_PIPE,
    ACTIONS(223), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(229), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(231), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(233), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(219), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [1722] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(223), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(229), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(231), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(233), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(156), 3,
      anon_sym_RPAREN,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
    ACTIONS(219), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [1756] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(223), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(231), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(233), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(219), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(156), 5,
      anon_sym_RPAREN,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
  [1788] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(158), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(223), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(219), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(156), 7,
      anon_sym_RPAREN,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
  [1818] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(225), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(227), 1,
      anon_sym_AMP_AMP,
    ACTIONS(237), 1,
      anon_sym_RPAREN,
    ACTIONS(223), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(229), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(231), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(233), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(219), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [1856] = 4,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(243), 1,
      anon_sym_DOT_DOT,
    ACTIONS(239), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(241), 13,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [1882] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(158), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(223), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(219), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(156), 9,
      anon_sym_RPAREN,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [1910] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(225), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(227), 1,
      anon_sym_AMP_AMP,
    ACTIONS(245), 1,
      anon_sym_RPAREN,
    ACTIONS(223), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(229), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(231), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(233), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(219), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [1948] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(44), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(42), 14,
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
  [1972] = 5,
    ACTIONS(23), 1,
      anon_sym_LF,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(217), 1,
      anon_sym_DOT,
    STATE(38), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(25), 13,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2000] = 5,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_LF,
    ACTIONS(247), 1,
      anon_sym_DOT,
    STATE(54), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(33), 13,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2028] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(225), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(227), 1,
      anon_sym_AMP_AMP,
    ACTIONS(250), 1,
      anon_sym_RPAREN,
    ACTIONS(223), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(229), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(231), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(233), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(219), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [2066] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(225), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(227), 1,
      anon_sym_AMP_AMP,
    ACTIONS(252), 1,
      anon_sym_RPAREN,
    ACTIONS(223), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(229), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(231), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(233), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(219), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
  [2104] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(254), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(256), 13,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2127] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(258), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(260), 13,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2150] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(262), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(264), 13,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2173] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(31), 1,
      anon_sym_LF,
    ACTIONS(33), 14,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      anon_sym_DOT,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2196] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(266), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(268), 13,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2219] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(270), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(272), 13,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2242] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(274), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(276), 13,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2265] = 4,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(239), 1,
      anon_sym_LF,
    ACTIONS(278), 1,
      anon_sym_DOT_DOT,
    ACTIONS(241), 13,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2290] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(280), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(282), 13,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2313] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(284), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(286), 13,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2336] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(288), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(290), 13,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2359] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(262), 1,
      anon_sym_LF,
    ACTIONS(264), 13,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2381] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(274), 1,
      anon_sym_LF,
    ACTIONS(276), 13,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2403] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(42), 1,
      anon_sym_LF,
    ACTIONS(44), 13,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2425] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(288), 1,
      anon_sym_LF,
    ACTIONS(290), 13,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2447] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(270), 1,
      anon_sym_LF,
    ACTIONS(272), 13,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2469] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(266), 1,
      anon_sym_LF,
    ACTIONS(268), 13,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2491] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(284), 1,
      anon_sym_LF,
    ACTIONS(286), 13,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2513] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(294), 1,
      anon_sym_LF,
    ACTIONS(292), 13,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2535] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(258), 1,
      anon_sym_LF,
    ACTIONS(260), 13,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2557] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(280), 1,
      anon_sym_LF,
    ACTIONS(282), 13,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2579] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(46), 1,
      anon_sym_LF,
    ACTIONS(48), 13,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2601] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(254), 1,
      anon_sym_LF,
    ACTIONS(256), 13,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
  [2623] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(294), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(292), 11,
      anon_sym_LBRACK,
      anon_sym_PIPE,
      sym_number_literal,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_DOLLAR,
      sym_file_path,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_SEMI,
      anon_sym_LBRACE,
  [2644] = 3,
    ACTIONS(3), 1,
      sym_comment,
    STATE(115), 1,
      sym_type,
    ACTIONS(296), 10,
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
  [2663] = 3,
    ACTIONS(3), 1,
      sym_comment,
    STATE(124), 1,
      sym_type,
    ACTIONS(296), 10,
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
  [2682] = 3,
    ACTIONS(3), 1,
      sym_comment,
    STATE(127), 1,
      sym_type,
    ACTIONS(296), 10,
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
  [2701] = 3,
    ACTIONS(3), 1,
      sym_comment,
    STATE(131), 1,
      sym_type,
    ACTIONS(296), 10,
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
  [2720] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(15), 1,
      anon_sym_DOLLAR,
    ACTIONS(17), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(298), 1,
      sym_number_literal,
    STATE(30), 6,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2744] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(15), 1,
      anon_sym_DOLLAR,
    ACTIONS(17), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(300), 1,
      sym_number_literal,
    STATE(25), 6,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2768] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(302), 1,
      anon_sym_LPAREN,
    ACTIONS(304), 1,
      sym_number_literal,
    ACTIONS(306), 1,
      anon_sym_DOLLAR,
    ACTIONS(308), 1,
      anon_sym_DOLLAR_LPAREN,
    STATE(51), 6,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2792] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(302), 1,
      anon_sym_LPAREN,
    ACTIONS(306), 1,
      anon_sym_DOLLAR,
    ACTIONS(308), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(310), 1,
      sym_number_literal,
    STATE(56), 6,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2816] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(15), 1,
      anon_sym_DOLLAR,
    ACTIONS(17), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(312), 1,
      sym_number_literal,
    STATE(22), 6,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2840] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(302), 1,
      anon_sym_LPAREN,
    ACTIONS(306), 1,
      anon_sym_DOLLAR,
    ACTIONS(308), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(314), 1,
      sym_number_literal,
    STATE(44), 6,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2864] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(302), 1,
      anon_sym_LPAREN,
    ACTIONS(306), 1,
      anon_sym_DOLLAR,
    ACTIONS(308), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(316), 1,
      sym_number_literal,
    STATE(48), 6,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2888] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(322), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
    ACTIONS(318), 4,
      anon_sym_def,
      anon_sym_let,
      anon_sym_DOLLAR,
      sym_identifier,
    ACTIONS(320), 4,
      anon_sym_LPAREN,
      sym_number_literal,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_LBRACE,
  [2908] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(302), 1,
      anon_sym_LPAREN,
    ACTIONS(306), 1,
      anon_sym_DOLLAR,
    ACTIONS(308), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(324), 1,
      sym_number_literal,
    STATE(43), 6,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2932] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(302), 1,
      anon_sym_LPAREN,
    ACTIONS(306), 1,
      anon_sym_DOLLAR,
    ACTIONS(308), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(326), 1,
      sym_number_literal,
    STATE(40), 6,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2956] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(302), 1,
      anon_sym_LPAREN,
    ACTIONS(306), 1,
      anon_sym_DOLLAR,
    ACTIONS(308), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(328), 1,
      sym_number_literal,
    STATE(50), 6,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2980] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(302), 1,
      anon_sym_LPAREN,
    ACTIONS(306), 1,
      anon_sym_DOLLAR,
    ACTIONS(308), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(330), 1,
      sym_number_literal,
    STATE(45), 6,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [3004] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(15), 1,
      anon_sym_DOLLAR,
    ACTIONS(17), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(332), 1,
      sym_number_literal,
    STATE(21), 6,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [3028] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(302), 1,
      anon_sym_LPAREN,
    ACTIONS(306), 1,
      anon_sym_DOLLAR,
    ACTIONS(308), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(334), 1,
      sym_number_literal,
    STATE(47), 6,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [3052] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(302), 1,
      anon_sym_LPAREN,
    ACTIONS(306), 1,
      anon_sym_DOLLAR,
    ACTIONS(308), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(336), 1,
      sym_number_literal,
    STATE(55), 6,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [3076] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(302), 1,
      anon_sym_LPAREN,
    ACTIONS(306), 1,
      anon_sym_DOLLAR,
    ACTIONS(308), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(338), 1,
      sym_number_literal,
    STATE(46), 6,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [3100] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(15), 1,
      anon_sym_DOLLAR,
    ACTIONS(17), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(340), 1,
      sym_number_literal,
    STATE(24), 6,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [3124] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(15), 1,
      anon_sym_DOLLAR,
    ACTIONS(17), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(342), 1,
      sym_number_literal,
    STATE(20), 6,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [3148] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_LPAREN,
    ACTIONS(15), 1,
      anon_sym_DOLLAR,
    ACTIONS(17), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(344), 1,
      sym_number_literal,
    STATE(23), 6,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [3172] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(346), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
    ACTIONS(318), 4,
      anon_sym_def,
      anon_sym_let,
      anon_sym_DOLLAR,
      sym_identifier,
    ACTIONS(320), 4,
      anon_sym_LPAREN,
      sym_number_literal,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_LBRACE,
  [3192] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(302), 1,
      anon_sym_LPAREN,
    ACTIONS(306), 1,
      anon_sym_DOLLAR,
    ACTIONS(308), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(348), 1,
      sym_number_literal,
    STATE(42), 6,
      sym_value_path,
      sym_command_substitution,
      sym_math_mode,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [3216] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(346), 1,
      ts_builtin_sym_end,
    ACTIONS(318), 4,
      anon_sym_def,
      anon_sym_let,
      anon_sym_DOLLAR,
      sym_identifier,
    ACTIONS(320), 4,
      anon_sym_LPAREN,
      sym_number_literal,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_LBRACE,
  [3235] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(322), 1,
      ts_builtin_sym_end,
    ACTIONS(318), 4,
      anon_sym_def,
      anon_sym_let,
      anon_sym_DOLLAR,
      sym_identifier,
    ACTIONS(320), 4,
      anon_sym_LPAREN,
      sym_number_literal,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_LBRACE,
  [3254] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(318), 4,
      anon_sym_def,
      anon_sym_let,
      anon_sym_DOLLAR,
      sym_identifier,
    ACTIONS(320), 4,
      anon_sym_LPAREN,
      sym_number_literal,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_LBRACE,
  [3270] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(350), 1,
      anon_sym_RBRACK,
    ACTIONS(352), 1,
      sym_flag_name,
    ACTIONS(355), 1,
      anon_sym_DOT_DOT_DOTrest,
    ACTIONS(358), 1,
      sym_identifier,
    STATE(109), 1,
      aux_sym_signature_repeat1,
    STATE(125), 3,
      sym_parameter,
      sym_flag,
      sym_rest,
  [3294] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(361), 1,
      anon_sym_RBRACK,
    ACTIONS(363), 1,
      sym_flag_name,
    ACTIONS(365), 1,
      anon_sym_DOT_DOT_DOTrest,
    ACTIONS(367), 1,
      sym_identifier,
    STATE(109), 1,
      aux_sym_signature_repeat1,
    STATE(125), 3,
      sym_parameter,
      sym_flag,
      sym_rest,
  [3318] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(363), 1,
      sym_flag_name,
    ACTIONS(365), 1,
      anon_sym_DOT_DOT_DOTrest,
    ACTIONS(367), 1,
      sym_identifier,
    ACTIONS(369), 1,
      anon_sym_RBRACK,
    STATE(110), 1,
      aux_sym_signature_repeat1,
    STATE(125), 3,
      sym_parameter,
      sym_flag,
      sym_rest,
  [3342] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(373), 1,
      anon_sym_COLON,
    ACTIONS(375), 1,
      anon_sym_LPAREN,
    ACTIONS(371), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [3359] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(379), 1,
      anon_sym_COLON,
    ACTIONS(381), 1,
      anon_sym_QMARK,
    ACTIONS(377), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [3376] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(385), 1,
      anon_sym_COLON,
    ACTIONS(383), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [3390] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(389), 1,
      anon_sym_QMARK,
    ACTIONS(387), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [3404] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(391), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(393), 4,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
  [3418] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(395), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(397), 4,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
  [3432] = 3,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(399), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(401), 4,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
  [3446] = 6,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(405), 1,
      anon_sym_PIPE,
    ACTIONS(407), 1,
      anon_sym_SEMI,
    ACTIONS(409), 1,
      anon_sym_LF,
    STATE(92), 1,
      sym__terminator,
    ACTIONS(403), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [3466] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(411), 6,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_QMARK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [3478] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(415), 1,
      anon_sym_COLON,
    ACTIONS(413), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [3492] = 6,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(405), 1,
      anon_sym_PIPE,
    ACTIONS(419), 1,
      anon_sym_SEMI,
    ACTIONS(421), 1,
      anon_sym_LF,
    STATE(104), 1,
      sym__terminator,
    ACTIONS(417), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [3512] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(423), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [3523] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(425), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [3534] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(427), 1,
      anon_sym_COMMA,
    ACTIONS(429), 4,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [3547] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(431), 1,
      anon_sym_LBRACK,
    ACTIONS(433), 1,
      anon_sym_RBRACK,
    ACTIONS(435), 1,
      sym_identifier,
    STATE(142), 1,
      aux_sym_column_header_repeat1,
    STATE(179), 1,
      sym_column_header,
  [3566] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(437), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [3577] = 6,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(439), 1,
      ts_builtin_sym_end,
    ACTIONS(441), 1,
      anon_sym_PIPE,
    ACTIONS(443), 1,
      anon_sym_SEMI,
    ACTIONS(445), 1,
      anon_sym_LF,
    STATE(106), 1,
      sym__terminator,
  [3596] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(431), 1,
      anon_sym_LBRACK,
    ACTIONS(435), 1,
      sym_identifier,
    ACTIONS(447), 1,
      anon_sym_RBRACK,
    STATE(156), 1,
      aux_sym_column_header_repeat1,
    STATE(192), 1,
      sym_column_header,
  [3615] = 6,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(346), 1,
      ts_builtin_sym_end,
    ACTIONS(441), 1,
      anon_sym_PIPE,
    ACTIONS(449), 1,
      anon_sym_SEMI,
    ACTIONS(451), 1,
      anon_sym_LF,
    STATE(107), 1,
      sym__terminator,
  [3634] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(453), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [3645] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(455), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [3656] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(457), 1,
      anon_sym_LBRACK,
    ACTIONS(460), 1,
      anon_sym_RBRACK,
    STATE(133), 2,
      sym_array,
      aux_sym_table_repeat1,
  [3670] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(462), 1,
      anon_sym_DQUOTE,
    ACTIONS(464), 1,
      anon_sym_SQUOTE,
    ACTIONS(466), 1,
      sym_identifier,
    STATE(165), 1,
      sym_string,
  [3686] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(468), 1,
      anon_sym_LBRACK,
    ACTIONS(470), 1,
      anon_sym_RBRACK,
    STATE(133), 2,
      sym_array,
      aux_sym_table_repeat1,
  [3700] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(350), 4,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [3710] = 5,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(405), 1,
      anon_sym_PIPE,
    ACTIONS(472), 1,
      anon_sym_SEMI,
    ACTIONS(474), 1,
      anon_sym_LF,
    STATE(108), 1,
      sym__terminator,
  [3726] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(468), 1,
      anon_sym_LBRACK,
    ACTIONS(476), 1,
      anon_sym_RBRACK,
    STATE(139), 2,
      sym_array,
      aux_sym_table_repeat1,
  [3740] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(468), 1,
      anon_sym_LBRACK,
    ACTIONS(478), 1,
      anon_sym_RBRACK,
    STATE(133), 2,
      sym_array,
      aux_sym_table_repeat1,
  [3754] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(468), 1,
      anon_sym_LBRACK,
    ACTIONS(480), 1,
      anon_sym_RBRACK,
    STATE(135), 2,
      sym_array,
      aux_sym_table_repeat1,
  [3768] = 4,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(482), 1,
      anon_sym_SQUOTE,
    ACTIONS(484), 1,
      sym_single_qouted_string_content,
    STATE(157), 1,
      aux_sym_string_repeat2,
  [3781] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(435), 1,
      sym_identifier,
    ACTIONS(486), 1,
      anon_sym_RBRACK,
    STATE(150), 1,
      aux_sym_column_header_repeat1,
  [3794] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(435), 1,
      sym_identifier,
    ACTIONS(488), 1,
      anon_sym_RBRACK,
    STATE(150), 1,
      aux_sym_column_header_repeat1,
  [3807] = 4,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(490), 1,
      anon_sym_SQUOTE,
    ACTIONS(492), 1,
      sym_single_qouted_string_content,
    STATE(144), 1,
      aux_sym_string_repeat2,
  [3820] = 4,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(495), 1,
      anon_sym_DQUOTE,
    ACTIONS(497), 1,
      sym_qouted_string_content,
    STATE(161), 1,
      aux_sym_string_repeat1,
  [3833] = 4,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(499), 1,
      anon_sym_DQUOTE,
    ACTIONS(501), 1,
      sym_qouted_string_content,
    STATE(146), 1,
      aux_sym_string_repeat1,
  [3846] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(435), 1,
      sym_identifier,
    ACTIONS(504), 1,
      anon_sym_RBRACK,
    STATE(150), 1,
      aux_sym_column_header_repeat1,
  [3859] = 4,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(506), 1,
      anon_sym_SQUOTE,
    ACTIONS(508), 1,
      sym_single_qouted_string_content,
    STATE(144), 1,
      aux_sym_string_repeat2,
  [3872] = 4,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(506), 1,
      anon_sym_DQUOTE,
    ACTIONS(510), 1,
      sym_qouted_string_content,
    STATE(146), 1,
      aux_sym_string_repeat1,
  [3885] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(512), 1,
      anon_sym_RBRACK,
    ACTIONS(514), 1,
      sym_identifier,
    STATE(150), 1,
      aux_sym_column_header_repeat1,
  [3898] = 4,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(517), 1,
      anon_sym_SQUOTE,
    ACTIONS(519), 1,
      sym_single_qouted_string_content,
    STATE(148), 1,
      aux_sym_string_repeat2,
  [3911] = 4,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(517), 1,
      anon_sym_DQUOTE,
    ACTIONS(521), 1,
      sym_qouted_string_content,
    STATE(149), 1,
      aux_sym_string_repeat1,
  [3924] = 4,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(510), 1,
      sym_qouted_string_content,
    ACTIONS(523), 1,
      anon_sym_DQUOTE,
    STATE(146), 1,
      aux_sym_string_repeat1,
  [3937] = 4,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(495), 1,
      anon_sym_SQUOTE,
    ACTIONS(525), 1,
      sym_single_qouted_string_content,
    STATE(158), 1,
      aux_sym_string_repeat2,
  [3950] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(435), 1,
      sym_identifier,
    ACTIONS(527), 1,
      anon_sym_RBRACK,
    STATE(147), 1,
      aux_sym_column_header_repeat1,
  [3963] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(435), 1,
      sym_identifier,
    ACTIONS(529), 1,
      anon_sym_RBRACK,
    STATE(150), 1,
      aux_sym_column_header_repeat1,
  [3976] = 4,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(508), 1,
      sym_single_qouted_string_content,
    ACTIONS(523), 1,
      anon_sym_SQUOTE,
    STATE(144), 1,
      aux_sym_string_repeat2,
  [3989] = 4,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(508), 1,
      sym_single_qouted_string_content,
    ACTIONS(531), 1,
      anon_sym_SQUOTE,
    STATE(144), 1,
      aux_sym_string_repeat2,
  [4002] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(435), 1,
      sym_identifier,
    ACTIONS(533), 1,
      anon_sym_RBRACK,
    STATE(143), 1,
      aux_sym_column_header_repeat1,
  [4015] = 4,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(482), 1,
      anon_sym_DQUOTE,
    ACTIONS(535), 1,
      sym_qouted_string_content,
    STATE(153), 1,
      aux_sym_string_repeat1,
  [4028] = 4,
    ACTIONS(29), 1,
      sym_comment,
    ACTIONS(510), 1,
      sym_qouted_string_content,
    ACTIONS(531), 1,
      anon_sym_DQUOTE,
    STATE(146), 1,
      aux_sym_string_repeat1,
  [4041] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(274), 2,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
  [4049] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(270), 2,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
  [4057] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(21), 1,
      anon_sym_LBRACE,
    STATE(117), 1,
      sym_block,
  [4067] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(537), 1,
      anon_sym_LBRACK,
    STATE(164), 1,
      sym_signature,
  [4077] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(512), 2,
      anon_sym_RBRACK,
      sym_identifier,
  [4085] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(539), 1,
      anon_sym_LBRACE,
  [4092] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(541), 1,
      sym_identifier,
  [4099] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(543), 1,
      anon_sym_RPAREN,
  [4106] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(545), 1,
      anon_sym_LBRACE,
  [4113] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(547), 1,
      anon_sym_RBRACE,
  [4120] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(549), 1,
      sym_identifier,
  [4127] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(551), 1,
      sym_identifier,
  [4134] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(553), 1,
      sym_identifier,
  [4141] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(555), 1,
      ts_builtin_sym_end,
  [4148] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(557), 1,
      anon_sym_COMMA,
  [4155] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(559), 1,
      sym_number_literal,
  [4162] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(561), 1,
      anon_sym_RPAREN,
  [4169] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(563), 1,
      anon_sym_SEMI,
  [4176] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(565), 1,
      ts_builtin_sym_end,
  [4183] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(280), 1,
      anon_sym_LBRACK,
  [4190] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(567), 1,
      sym_number_literal,
  [4197] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(569), 1,
      anon_sym_RPAREN,
  [4204] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(571), 1,
      anon_sym_EQ,
  [4211] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(573), 1,
      anon_sym_RPAREN,
  [4218] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(575), 1,
      sym_identifier,
  [4225] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(577), 1,
      sym_identifier,
  [4232] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(579), 1,
      sym_flag_shorthand_name,
  [4239] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(254), 1,
      anon_sym_LBRACK,
  [4246] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(581), 1,
      sym_identifier,
  [4253] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(583), 1,
      anon_sym_RBRACE,
  [4260] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(585), 1,
      anon_sym_SEMI,
  [4267] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(587), 1,
      anon_sym_SEMI,
  [4274] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(589), 1,
      anon_sym_SEMI,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 44,
  [SMALL_STATE(4)] = 88,
  [SMALL_STATE(5)] = 132,
  [SMALL_STATE(6)] = 171,
  [SMALL_STATE(7)] = 209,
  [SMALL_STATE(8)] = 247,
  [SMALL_STATE(9)] = 299,
  [SMALL_STATE(10)] = 351,
  [SMALL_STATE(11)] = 403,
  [SMALL_STATE(12)] = 456,
  [SMALL_STATE(13)] = 509,
  [SMALL_STATE(14)] = 560,
  [SMALL_STATE(15)] = 613,
  [SMALL_STATE(16)] = 664,
  [SMALL_STATE(17)] = 717,
  [SMALL_STATE(18)] = 770,
  [SMALL_STATE(19)] = 821,
  [SMALL_STATE(20)] = 850,
  [SMALL_STATE(21)] = 891,
  [SMALL_STATE(22)] = 924,
  [SMALL_STATE(23)] = 953,
  [SMALL_STATE(24)] = 992,
  [SMALL_STATE(25)] = 1029,
  [SMALL_STATE(26)] = 1060,
  [SMALL_STATE(27)] = 1107,
  [SMALL_STATE(28)] = 1150,
  [SMALL_STATE(29)] = 1197,
  [SMALL_STATE(30)] = 1244,
  [SMALL_STATE(31)] = 1279,
  [SMALL_STATE(32)] = 1323,
  [SMALL_STATE(33)] = 1367,
  [SMALL_STATE(34)] = 1397,
  [SMALL_STATE(35)] = 1437,
  [SMALL_STATE(36)] = 1467,
  [SMALL_STATE(37)] = 1497,
  [SMALL_STATE(38)] = 1522,
  [SMALL_STATE(39)] = 1550,
  [SMALL_STATE(40)] = 1574,
  [SMALL_STATE(41)] = 1598,
  [SMALL_STATE(42)] = 1622,
  [SMALL_STATE(43)] = 1648,
  [SMALL_STATE(44)] = 1686,
  [SMALL_STATE(45)] = 1722,
  [SMALL_STATE(46)] = 1756,
  [SMALL_STATE(47)] = 1788,
  [SMALL_STATE(48)] = 1818,
  [SMALL_STATE(49)] = 1856,
  [SMALL_STATE(50)] = 1882,
  [SMALL_STATE(51)] = 1910,
  [SMALL_STATE(52)] = 1948,
  [SMALL_STATE(53)] = 1972,
  [SMALL_STATE(54)] = 2000,
  [SMALL_STATE(55)] = 2028,
  [SMALL_STATE(56)] = 2066,
  [SMALL_STATE(57)] = 2104,
  [SMALL_STATE(58)] = 2127,
  [SMALL_STATE(59)] = 2150,
  [SMALL_STATE(60)] = 2173,
  [SMALL_STATE(61)] = 2196,
  [SMALL_STATE(62)] = 2219,
  [SMALL_STATE(63)] = 2242,
  [SMALL_STATE(64)] = 2265,
  [SMALL_STATE(65)] = 2290,
  [SMALL_STATE(66)] = 2313,
  [SMALL_STATE(67)] = 2336,
  [SMALL_STATE(68)] = 2359,
  [SMALL_STATE(69)] = 2381,
  [SMALL_STATE(70)] = 2403,
  [SMALL_STATE(71)] = 2425,
  [SMALL_STATE(72)] = 2447,
  [SMALL_STATE(73)] = 2469,
  [SMALL_STATE(74)] = 2491,
  [SMALL_STATE(75)] = 2513,
  [SMALL_STATE(76)] = 2535,
  [SMALL_STATE(77)] = 2557,
  [SMALL_STATE(78)] = 2579,
  [SMALL_STATE(79)] = 2601,
  [SMALL_STATE(80)] = 2623,
  [SMALL_STATE(81)] = 2644,
  [SMALL_STATE(82)] = 2663,
  [SMALL_STATE(83)] = 2682,
  [SMALL_STATE(84)] = 2701,
  [SMALL_STATE(85)] = 2720,
  [SMALL_STATE(86)] = 2744,
  [SMALL_STATE(87)] = 2768,
  [SMALL_STATE(88)] = 2792,
  [SMALL_STATE(89)] = 2816,
  [SMALL_STATE(90)] = 2840,
  [SMALL_STATE(91)] = 2864,
  [SMALL_STATE(92)] = 2888,
  [SMALL_STATE(93)] = 2908,
  [SMALL_STATE(94)] = 2932,
  [SMALL_STATE(95)] = 2956,
  [SMALL_STATE(96)] = 2980,
  [SMALL_STATE(97)] = 3004,
  [SMALL_STATE(98)] = 3028,
  [SMALL_STATE(99)] = 3052,
  [SMALL_STATE(100)] = 3076,
  [SMALL_STATE(101)] = 3100,
  [SMALL_STATE(102)] = 3124,
  [SMALL_STATE(103)] = 3148,
  [SMALL_STATE(104)] = 3172,
  [SMALL_STATE(105)] = 3192,
  [SMALL_STATE(106)] = 3216,
  [SMALL_STATE(107)] = 3235,
  [SMALL_STATE(108)] = 3254,
  [SMALL_STATE(109)] = 3270,
  [SMALL_STATE(110)] = 3294,
  [SMALL_STATE(111)] = 3318,
  [SMALL_STATE(112)] = 3342,
  [SMALL_STATE(113)] = 3359,
  [SMALL_STATE(114)] = 3376,
  [SMALL_STATE(115)] = 3390,
  [SMALL_STATE(116)] = 3404,
  [SMALL_STATE(117)] = 3418,
  [SMALL_STATE(118)] = 3432,
  [SMALL_STATE(119)] = 3446,
  [SMALL_STATE(120)] = 3466,
  [SMALL_STATE(121)] = 3478,
  [SMALL_STATE(122)] = 3492,
  [SMALL_STATE(123)] = 3512,
  [SMALL_STATE(124)] = 3523,
  [SMALL_STATE(125)] = 3534,
  [SMALL_STATE(126)] = 3547,
  [SMALL_STATE(127)] = 3566,
  [SMALL_STATE(128)] = 3577,
  [SMALL_STATE(129)] = 3596,
  [SMALL_STATE(130)] = 3615,
  [SMALL_STATE(131)] = 3634,
  [SMALL_STATE(132)] = 3645,
  [SMALL_STATE(133)] = 3656,
  [SMALL_STATE(134)] = 3670,
  [SMALL_STATE(135)] = 3686,
  [SMALL_STATE(136)] = 3700,
  [SMALL_STATE(137)] = 3710,
  [SMALL_STATE(138)] = 3726,
  [SMALL_STATE(139)] = 3740,
  [SMALL_STATE(140)] = 3754,
  [SMALL_STATE(141)] = 3768,
  [SMALL_STATE(142)] = 3781,
  [SMALL_STATE(143)] = 3794,
  [SMALL_STATE(144)] = 3807,
  [SMALL_STATE(145)] = 3820,
  [SMALL_STATE(146)] = 3833,
  [SMALL_STATE(147)] = 3846,
  [SMALL_STATE(148)] = 3859,
  [SMALL_STATE(149)] = 3872,
  [SMALL_STATE(150)] = 3885,
  [SMALL_STATE(151)] = 3898,
  [SMALL_STATE(152)] = 3911,
  [SMALL_STATE(153)] = 3924,
  [SMALL_STATE(154)] = 3937,
  [SMALL_STATE(155)] = 3950,
  [SMALL_STATE(156)] = 3963,
  [SMALL_STATE(157)] = 3976,
  [SMALL_STATE(158)] = 3989,
  [SMALL_STATE(159)] = 4002,
  [SMALL_STATE(160)] = 4015,
  [SMALL_STATE(161)] = 4028,
  [SMALL_STATE(162)] = 4041,
  [SMALL_STATE(163)] = 4049,
  [SMALL_STATE(164)] = 4057,
  [SMALL_STATE(165)] = 4067,
  [SMALL_STATE(166)] = 4077,
  [SMALL_STATE(167)] = 4085,
  [SMALL_STATE(168)] = 4092,
  [SMALL_STATE(169)] = 4099,
  [SMALL_STATE(170)] = 4106,
  [SMALL_STATE(171)] = 4113,
  [SMALL_STATE(172)] = 4120,
  [SMALL_STATE(173)] = 4127,
  [SMALL_STATE(174)] = 4134,
  [SMALL_STATE(175)] = 4141,
  [SMALL_STATE(176)] = 4148,
  [SMALL_STATE(177)] = 4155,
  [SMALL_STATE(178)] = 4162,
  [SMALL_STATE(179)] = 4169,
  [SMALL_STATE(180)] = 4176,
  [SMALL_STATE(181)] = 4183,
  [SMALL_STATE(182)] = 4190,
  [SMALL_STATE(183)] = 4197,
  [SMALL_STATE(184)] = 4204,
  [SMALL_STATE(185)] = 4211,
  [SMALL_STATE(186)] = 4218,
  [SMALL_STATE(187)] = 4225,
  [SMALL_STATE(188)] = 4232,
  [SMALL_STATE(189)] = 4239,
  [SMALL_STATE(190)] = 4246,
  [SMALL_STATE(191)] = 4253,
  [SMALL_STATE(192)] = 4260,
  [SMALL_STATE(193)] = 4267,
  [SMALL_STATE(194)] = 4274,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(134),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(190),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(187),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_path, 2),
  [25] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_value_path, 2),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(173),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_value_path_repeat1, 2),
  [33] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_value_path_repeat1, 2),
  [35] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_value_path_repeat1, 2), SHIFT_REPEAT(173),
  [38] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_path, 3),
  [40] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_value_path, 3),
  [42] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_math_mode, 4),
  [44] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_math_mode, 4),
  [46] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_command_substitution, 3),
  [48] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_command_substitution, 3),
  [50] = {.entry = {.count = 1, .reusable = false}}, SHIFT(129),
  [52] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_command, 1, .production_id = 1),
  [54] = {.entry = {.count = 1, .reusable = false}}, SHIFT(64),
  [56] = {.entry = {.count = 1, .reusable = false}}, SHIFT(152),
  [58] = {.entry = {.count = 1, .reusable = false}}, SHIFT(151),
  [60] = {.entry = {.count = 1, .reusable = false}}, SHIFT(168),
  [62] = {.entry = {.count = 1, .reusable = false}}, SHIFT(75),
  [64] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [66] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_command, 1, .production_id = 1),
  [70] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_command, 2, .production_id = 3),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_command, 2, .production_id = 3),
  [74] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(129),
  [77] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4),
  [79] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(64),
  [82] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(152),
  [85] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(151),
  [88] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(168),
  [91] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(75),
  [94] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(11),
  [97] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(17),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4),
  [102] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [104] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [108] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(126),
  [111] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(49),
  [114] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(145),
  [117] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(154),
  [120] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(187),
  [123] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(80),
  [126] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(14),
  [129] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(16),
  [132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [134] = {.entry = {.count = 1, .reusable = false}}, SHIFT(126),
  [136] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [138] = {.entry = {.count = 1, .reusable = false}}, SHIFT(145),
  [140] = {.entry = {.count = 1, .reusable = false}}, SHIFT(154),
  [142] = {.entry = {.count = 1, .reusable = false}}, SHIFT(80),
  [144] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [146] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [150] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parenthesized_math_expression, 3),
  [154] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_parenthesized_math_expression, 3),
  [156] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3, .production_id = 5),
  [158] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_expression, 3, .production_id = 5),
  [160] = {.entry = {.count = 1, .reusable = false}}, SHIFT(86),
  [162] = {.entry = {.count = 1, .reusable = false}}, SHIFT(89),
  [164] = {.entry = {.count = 1, .reusable = false}}, SHIFT(103),
  [166] = {.entry = {.count = 1, .reusable = false}}, SHIFT(101),
  [168] = {.entry = {.count = 1, .reusable = false}}, SHIFT(85),
  [170] = {.entry = {.count = 1, .reusable = false}}, SHIFT(97),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statement, 1),
  [174] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statement, 1),
  [176] = {.entry = {.count = 1, .reusable = false}}, SHIFT(102),
  [178] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(134),
  [181] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(87),
  [184] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(190),
  [187] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(27),
  [190] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(187),
  [193] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(14),
  [196] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(8),
  [199] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(16),
  [202] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_value_path_repeat1, 2), SHIFT_REPEAT(174),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(145),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(154),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [217] = {.entry = {.count = 1, .reusable = false}}, SHIFT(186),
  [219] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [221] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [223] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [225] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [227] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [229] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [231] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [233] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [237] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [239] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 1),
  [241] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__expression, 1),
  [243] = {.entry = {.count = 1, .reusable = false}}, SHIFT(182),
  [245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [247] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_value_path_repeat1, 2), SHIFT_REPEAT(186),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [254] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3),
  [256] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 3),
  [258] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table, 5),
  [260] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_table, 5),
  [262] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_range, 3),
  [264] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_range, 3),
  [266] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table, 4),
  [268] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_table, 4),
  [270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 2),
  [272] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array, 2),
  [274] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 3),
  [276] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array, 3),
  [278] = {.entry = {.count = 1, .reusable = false}}, SHIFT(177),
  [280] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 2),
  [282] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 2),
  [284] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2),
  [286] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 2),
  [288] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 3),
  [290] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 3),
  [292] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 1, .production_id = 2),
  [294] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_command_repeat1, 1, .production_id = 2),
  [296] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [298] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [300] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [302] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [304] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [306] = {.entry = {.count = 1, .reusable = false}}, SHIFT(172),
  [308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [312] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [314] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [316] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [318] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2),
  [320] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2),
  [322] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statements, 3),
  [324] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [326] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [328] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [330] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [332] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [336] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [340] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [342] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [344] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [346] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statements, 2),
  [348] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [350] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_signature_repeat1, 2),
  [352] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_signature_repeat1, 2), SHIFT_REPEAT(112),
  [355] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_signature_repeat1, 2), SHIFT_REPEAT(121),
  [358] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_signature_repeat1, 2), SHIFT_REPEAT(113),
  [361] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [363] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [365] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [367] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [369] = {.entry = {.count = 1, .reusable = true}}, SHIFT(170),
  [371] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag, 1),
  [373] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [375] = {.entry = {.count = 1, .reusable = true}}, SHIFT(188),
  [377] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 1),
  [379] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [381] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [383] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag, 4),
  [385] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [387] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 3),
  [389] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [391] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_variable_declaration, 4, .production_id = 7),
  [393] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_variable_declaration, 4, .production_id = 7),
  [395] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 4, .production_id = 6),
  [397] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_definition, 4, .production_id = 6),
  [399] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pipeline, 3),
  [401] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pipeline, 3),
  [403] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statements, 2),
  [405] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [407] = {.entry = {.count = 1, .reusable = false}}, SHIFT(92),
  [409] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [411] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1),
  [413] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rest, 1),
  [415] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [417] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statements, 1),
  [419] = {.entry = {.count = 1, .reusable = false}}, SHIFT(104),
  [421] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [423] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 4),
  [425] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rest, 3),
  [427] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [429] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_signature_repeat1, 1),
  [431] = {.entry = {.count = 1, .reusable = true}}, SHIFT(159),
  [433] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [435] = {.entry = {.count = 1, .reusable = true}}, SHIFT(176),
  [437] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag, 6),
  [439] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statements, 1),
  [441] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [443] = {.entry = {.count = 1, .reusable = false}}, SHIFT(106),
  [445] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [447] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [449] = {.entry = {.count = 1, .reusable = false}}, SHIFT(107),
  [451] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [453] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag, 3),
  [455] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 2),
  [457] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_table_repeat1, 2), SHIFT_REPEAT(155),
  [460] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_repeat1, 2),
  [462] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [464] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [466] = {.entry = {.count = 1, .reusable = true}}, SHIFT(165),
  [468] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [470] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [472] = {.entry = {.count = 1, .reusable = false}}, SHIFT(108),
  [474] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [476] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [478] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [480] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [482] = {.entry = {.count = 1, .reusable = false}}, SHIFT(181),
  [484] = {.entry = {.count = 1, .reusable = false}}, SHIFT(157),
  [486] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [488] = {.entry = {.count = 1, .reusable = true}}, SHIFT(194),
  [490] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_repeat2, 2),
  [492] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_repeat2, 2), SHIFT_REPEAT(144),
  [495] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [497] = {.entry = {.count = 1, .reusable = false}}, SHIFT(161),
  [499] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2),
  [501] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2), SHIFT_REPEAT(146),
  [504] = {.entry = {.count = 1, .reusable = true}}, SHIFT(162),
  [506] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [508] = {.entry = {.count = 1, .reusable = false}}, SHIFT(144),
  [510] = {.entry = {.count = 1, .reusable = false}}, SHIFT(146),
  [512] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_column_header_repeat1, 2),
  [514] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_column_header_repeat1, 2), SHIFT_REPEAT(176),
  [517] = {.entry = {.count = 1, .reusable = false}}, SHIFT(77),
  [519] = {.entry = {.count = 1, .reusable = false}}, SHIFT(148),
  [521] = {.entry = {.count = 1, .reusable = false}}, SHIFT(149),
  [523] = {.entry = {.count = 1, .reusable = false}}, SHIFT(189),
  [525] = {.entry = {.count = 1, .reusable = false}}, SHIFT(158),
  [527] = {.entry = {.count = 1, .reusable = true}}, SHIFT(163),
  [529] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [531] = {.entry = {.count = 1, .reusable = false}}, SHIFT(57),
  [533] = {.entry = {.count = 1, .reusable = true}}, SHIFT(193),
  [535] = {.entry = {.count = 1, .reusable = false}}, SHIFT(153),
  [537] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [539] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_signature, 3),
  [541] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [543] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [545] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_signature, 2),
  [547] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [549] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [551] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [553] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [555] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [557] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [559] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [561] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [563] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [565] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [567] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [569] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [571] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [573] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [575] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [577] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [579] = {.entry = {.count = 1, .reusable = true}}, SHIFT(178),
  [581] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
  [583] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [585] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [587] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_column_header, 2),
  [589] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_column_header, 3),
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
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_word,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
