#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 297
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 105
#define ALIAS_COUNT 0
#define TOKEN_COUNT 67
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 11
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 13

enum {
  sym_word = 1,
  anon_sym_SEMI = 2,
  anon_sym_LF = 3,
  anon_sym_PIPE = 4,
  anon_sym_export = 5,
  anon_sym_def = 6,
  anon_sym_alias = 7,
  anon_sym_EQ = 8,
  anon_sym_LBRACK = 9,
  anon_sym_COMMA = 10,
  anon_sym_RBRACK = 11,
  anon_sym_COLON = 12,
  anon_sym_QMARK = 13,
  anon_sym_LPAREN = 14,
  anon_sym_RPAREN = 15,
  sym_flag_name = 16,
  sym_flag_shorthand_name = 17,
  anon_sym_DOT_DOT_DOTrest = 18,
  anon_sym_int = 19,
  anon_sym_string = 20,
  anon_sym_path = 21,
  anon_sym_table = 22,
  anon_sym_unit = 23,
  anon_sym_number = 24,
  anon_sym_pattern = 25,
  anon_sym_range = 26,
  anon_sym_block = 27,
  anon_sym_any = 28,
  anon_sym_let = 29,
  sym_number_literal = 30,
  anon_sym_DQUOTE = 31,
  aux_sym_string_token1 = 32,
  anon_sym_SQUOTE = 33,
  aux_sym_string_token2 = 34,
  anon_sym_BQUOTE = 35,
  aux_sym_string_token3 = 36,
  anon_sym_DOLLAR = 37,
  anon_sym_DOT = 38,
  aux_sym_file_path_token1 = 39,
  aux_sym_file_path_token2 = 40,
  anon_sym_DOT_DOT = 41,
  anon_sym_DOLLAR_LPAREN = 42,
  sym_identifier = 43,
  anon_sym_ = 44,
  anon_sym_LBRACE = 45,
  anon_sym_RBRACE = 46,
  anon_sym_DOT2 = 47,
  sym_comment = 48,
  anon_sym_PLUS = 49,
  anon_sym_DASH = 50,
  anon_sym_STAR = 51,
  anon_sym_SLASH = 52,
  anon_sym_PERCENT = 53,
  anon_sym_mod = 54,
  anon_sym_PIPE_PIPE = 55,
  anon_sym_AMP_AMP = 56,
  anon_sym_EQ_TILDE = 57,
  anon_sym_EQ_EQ = 58,
  anon_sym_BANG_EQ = 59,
  anon_sym_in = 60,
  anon_sym_GT = 61,
  anon_sym_GT_EQ = 62,
  anon_sym_LT_EQ = 63,
  anon_sym_LT = 64,
  anon_sym_LT_LT = 65,
  anon_sym_GT_GT = 66,
  sym_source_file = 67,
  sym__statements = 68,
  sym__terminator = 69,
  sym__statement = 70,
  sym_function_definition = 71,
  sym_alias = 72,
  sym_signature = 73,
  sym_parameter = 74,
  sym_flag = 75,
  sym_rest = 76,
  sym_type = 77,
  sym_variable_declaration = 78,
  sym_command = 79,
  sym__expression = 80,
  sym_string = 81,
  sym_value_path = 82,
  sym_file_path = 83,
  sym__flag_arg = 84,
  sym_range = 85,
  sym_command_substitution = 86,
  sym_math_mode = 87,
  sym_table = 88,
  sym_column_header = 89,
  sym_array = 90,
  sym_record_or_block = 91,
  sym_block = 92,
  sym__math_expression = 93,
  sym_parenthesized_math_expression = 94,
  sym_operator = 95,
  sym_binary_expression = 96,
  aux_sym__statements_repeat1 = 97,
  aux_sym_signature_repeat1 = 98,
  aux_sym_command_repeat1 = 99,
  aux_sym_value_path_repeat1 = 100,
  aux_sym_table_repeat1 = 101,
  aux_sym_column_header_repeat1 = 102,
  aux_sym_array_repeat1 = 103,
  aux_sym_record_or_block_repeat1 = 104,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_word] = "word",
  [anon_sym_SEMI] = ";",
  [anon_sym_LF] = "\n",
  [anon_sym_PIPE] = "|",
  [anon_sym_export] = "export",
  [anon_sym_def] = "def",
  [anon_sym_alias] = "alias",
  [anon_sym_EQ] = "=",
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
  [sym_number_literal] = "number_literal",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_string_token1] = "string_token1",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_string_token2] = "string_token2",
  [anon_sym_BQUOTE] = "`",
  [aux_sym_string_token3] = "string_token3",
  [anon_sym_DOLLAR] = "$",
  [anon_sym_DOT] = ".",
  [aux_sym_file_path_token1] = "file_path_token1",
  [aux_sym_file_path_token2] = "file_path_token2",
  [anon_sym_DOT_DOT] = "..",
  [anon_sym_DOLLAR_LPAREN] = "$(",
  [sym_identifier] = "identifier",
  [anon_sym_] = " ",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_DOT2] = ".",
  [sym_comment] = "comment",
  [anon_sym_PLUS] = "+",
  [anon_sym_DASH] = "-",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_PERCENT] = "%",
  [anon_sym_mod] = "mod",
  [anon_sym_PIPE_PIPE] = "||",
  [anon_sym_AMP_AMP] = "&&",
  [anon_sym_EQ_TILDE] = "=~",
  [anon_sym_EQ_EQ] = "==",
  [anon_sym_BANG_EQ] = "!=",
  [anon_sym_in] = "in",
  [anon_sym_GT] = ">",
  [anon_sym_GT_EQ] = ">=",
  [anon_sym_LT_EQ] = "<=",
  [anon_sym_LT] = "<",
  [anon_sym_LT_LT] = "<<",
  [anon_sym_GT_GT] = ">>",
  [sym_source_file] = "source_file",
  [sym__statements] = "_statements",
  [sym__terminator] = "_terminator",
  [sym__statement] = "_statement",
  [sym_function_definition] = "function_definition",
  [sym_alias] = "alias",
  [sym_signature] = "signature",
  [sym_parameter] = "parameter",
  [sym_flag] = "flag",
  [sym_rest] = "rest",
  [sym_type] = "type",
  [sym_variable_declaration] = "variable_declaration",
  [sym_command] = "command",
  [sym__expression] = "_expression",
  [sym_string] = "string",
  [sym_value_path] = "value_path",
  [sym_file_path] = "file_path",
  [sym__flag_arg] = "_flag_arg",
  [sym_range] = "range",
  [sym_command_substitution] = "command_substitution",
  [sym_math_mode] = "math_mode",
  [sym_table] = "table",
  [sym_column_header] = "column_header",
  [sym_array] = "array",
  [sym_record_or_block] = "record_or_block",
  [sym_block] = "block",
  [sym__math_expression] = "_math_expression",
  [sym_parenthesized_math_expression] = "parenthesized_math_expression",
  [sym_operator] = "operator",
  [sym_binary_expression] = "binary_expression",
  [aux_sym__statements_repeat1] = "_statements_repeat1",
  [aux_sym_signature_repeat1] = "signature_repeat1",
  [aux_sym_command_repeat1] = "command_repeat1",
  [aux_sym_value_path_repeat1] = "value_path_repeat1",
  [aux_sym_table_repeat1] = "table_repeat1",
  [aux_sym_column_header_repeat1] = "column_header_repeat1",
  [aux_sym_array_repeat1] = "array_repeat1",
  [aux_sym_record_or_block_repeat1] = "record_or_block_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_word] = sym_word,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_LF] = anon_sym_LF,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_export] = anon_sym_export,
  [anon_sym_def] = anon_sym_def,
  [anon_sym_alias] = anon_sym_alias,
  [anon_sym_EQ] = anon_sym_EQ,
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
  [sym_number_literal] = sym_number_literal,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_string_token1] = aux_sym_string_token1,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_string_token2] = aux_sym_string_token2,
  [anon_sym_BQUOTE] = anon_sym_BQUOTE,
  [aux_sym_string_token3] = aux_sym_string_token3,
  [anon_sym_DOLLAR] = anon_sym_DOLLAR,
  [anon_sym_DOT] = anon_sym_DOT,
  [aux_sym_file_path_token1] = aux_sym_file_path_token1,
  [aux_sym_file_path_token2] = aux_sym_file_path_token2,
  [anon_sym_DOT_DOT] = anon_sym_DOT_DOT,
  [anon_sym_DOLLAR_LPAREN] = anon_sym_DOLLAR_LPAREN,
  [sym_identifier] = sym_identifier,
  [anon_sym_] = anon_sym_,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_DOT2] = anon_sym_DOT,
  [sym_comment] = sym_comment,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [anon_sym_mod] = anon_sym_mod,
  [anon_sym_PIPE_PIPE] = anon_sym_PIPE_PIPE,
  [anon_sym_AMP_AMP] = anon_sym_AMP_AMP,
  [anon_sym_EQ_TILDE] = anon_sym_EQ_TILDE,
  [anon_sym_EQ_EQ] = anon_sym_EQ_EQ,
  [anon_sym_BANG_EQ] = anon_sym_BANG_EQ,
  [anon_sym_in] = anon_sym_in,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_GT_EQ] = anon_sym_GT_EQ,
  [anon_sym_LT_EQ] = anon_sym_LT_EQ,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_LT_LT] = anon_sym_LT_LT,
  [anon_sym_GT_GT] = anon_sym_GT_GT,
  [sym_source_file] = sym_source_file,
  [sym__statements] = sym__statements,
  [sym__terminator] = sym__terminator,
  [sym__statement] = sym__statement,
  [sym_function_definition] = sym_function_definition,
  [sym_alias] = sym_alias,
  [sym_signature] = sym_signature,
  [sym_parameter] = sym_parameter,
  [sym_flag] = sym_flag,
  [sym_rest] = sym_rest,
  [sym_type] = sym_type,
  [sym_variable_declaration] = sym_variable_declaration,
  [sym_command] = sym_command,
  [sym__expression] = sym__expression,
  [sym_string] = sym_string,
  [sym_value_path] = sym_value_path,
  [sym_file_path] = sym_file_path,
  [sym__flag_arg] = sym__flag_arg,
  [sym_range] = sym_range,
  [sym_command_substitution] = sym_command_substitution,
  [sym_math_mode] = sym_math_mode,
  [sym_table] = sym_table,
  [sym_column_header] = sym_column_header,
  [sym_array] = sym_array,
  [sym_record_or_block] = sym_record_or_block,
  [sym_block] = sym_block,
  [sym__math_expression] = sym__math_expression,
  [sym_parenthesized_math_expression] = sym_parenthesized_math_expression,
  [sym_operator] = sym_operator,
  [sym_binary_expression] = sym_binary_expression,
  [aux_sym__statements_repeat1] = aux_sym__statements_repeat1,
  [aux_sym_signature_repeat1] = aux_sym_signature_repeat1,
  [aux_sym_command_repeat1] = aux_sym_command_repeat1,
  [aux_sym_value_path_repeat1] = aux_sym_value_path_repeat1,
  [aux_sym_table_repeat1] = aux_sym_table_repeat1,
  [aux_sym_column_header_repeat1] = aux_sym_column_header_repeat1,
  [aux_sym_array_repeat1] = aux_sym_array_repeat1,
  [aux_sym_record_or_block_repeat1] = aux_sym_record_or_block_repeat1,
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
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_export] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_def] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_alias] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
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
  [sym_number_literal] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_BQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_token3] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_DOLLAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_file_path_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_file_path_token2] = {
    .visible = false,
    .named = false,
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
  [anon_sym_] = {
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
  [anon_sym_DOT2] = {
    .visible = true,
    .named = false,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
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
  [anon_sym_mod] = {
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
  [anon_sym_EQ_TILDE] = {
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
  [anon_sym_in] = {
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
  [sym__terminator] = {
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
  [sym_alias] = {
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
  [sym_file_path] = {
    .visible = true,
    .named = true,
  },
  [sym__flag_arg] = {
    .visible = false,
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
  [sym_record_or_block] = {
    .visible = true,
    .named = true,
  },
  [sym_block] = {
    .visible = true,
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
  [sym_operator] = {
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
  [aux_sym_array_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_record_or_block_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_alias_name = 1,
  field_arg = 2,
  field_cmd_name = 3,
  field_from = 4,
  field_func_name = 5,
  field_left = 6,
  field_name = 7,
  field_operator = 8,
  field_right = 9,
  field_to = 10,
  field_value = 11,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_alias_name] = "alias_name",
  [field_arg] = "arg",
  [field_cmd_name] = "cmd_name",
  [field_from] = "from",
  [field_func_name] = "func_name",
  [field_left] = "left",
  [field_name] = "name",
  [field_operator] = "operator",
  [field_right] = "right",
  [field_to] = "to",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
  [3] = {.index = 3, .length = 1},
  [4] = {.index = 4, .length = 2},
  [5] = {.index = 6, .length = 3},
  [6] = {.index = 9, .length = 2},
  [7] = {.index = 11, .length = 3},
  [8] = {.index = 14, .length = 1},
  [9] = {.index = 15, .length = 1},
  [10] = {.index = 16, .length = 2},
  [11] = {.index = 18, .length = 2},
  [12] = {.index = 20, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_cmd_name, 0},
  [1] =
    {field_cmd_name, 0},
    {field_cmd_name, 1},
  [3] =
    {field_arg, 0},
  [4] =
    {field_arg, 1, .inherited = true},
    {field_cmd_name, 0},
  [6] =
    {field_arg, 2, .inherited = true},
    {field_cmd_name, 0},
    {field_cmd_name, 1},
  [9] =
    {field_arg, 0, .inherited = true},
    {field_arg, 1, .inherited = true},
  [11] =
    {field_left, 0},
    {field_operator, 1},
    {field_right, 2},
  [14] =
    {field_func_name, 1},
  [15] =
    {field_alias_name, 1},
  [16] =
    {field_from, 0},
    {field_to, 2},
  [18] =
    {field_name, 1},
    {field_value, 3},
  [20] =
    {field_func_name, 2},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
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
      : (c <= ']' || (c < '{'
        ? c == '`'
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
        ? (c >= '-' && c <= '.')
        : c <= ';')
      : (c <= ']' || (c < '{'
        ? c == '`'
        : c <= '}')))));
}

static inline bool sym_word_character_set_3(int32_t c) {
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
      : (c <= ']' || (c >= '`' && c <= '}')))));
}

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(55);
      if (lookahead == '!') ADVANCE(106);
      if (lookahead == '"') ADVANCE(122);
      if (lookahead == '#') ADVANCE(178);
      if (lookahead == '$') ADVANCE(137);
      if (lookahead == '%') ADVANCE(188);
      if (lookahead == '&') ADVANCE(99);
      if (lookahead == '\'') ADVANCE(127);
      if (lookahead == '(') ADVANCE(83);
      if (lookahead == ')') ADVANCE(84);
      if (lookahead == '*') ADVANCE(184);
      if (lookahead == '+') ADVANCE(179);
      if (lookahead == ',') ADVANCE(75);
      if (lookahead == '-') ADVANCE(183);
      if (lookahead == '.') ADVANCE(140);
      if (lookahead == '/') ADVANCE(186);
      if (lookahead == ':') ADVANCE(79);
      if (lookahead == ';') ADVANCE(56);
      if (lookahead == '<') ADVANCE(200);
      if (lookahead == '=') ADVANCE(72);
      if (lookahead == '>') ADVANCE(196);
      if (lookahead == '?') ADVANCE(81);
      if (lookahead == '[') ADVANCE(73);
      if (lookahead == '\\') ADVANCE(47);
      if (lookahead == ']') ADVANCE(77);
      if (lookahead == '`') ADVANCE(132);
      if (lookahead == 'a') ADVANCE(113);
      if (lookahead == 'd') ADVANCE(109);
      if (lookahead == 'e') ADVANCE(120);
      if (lookahead == 'l') ADVANCE(110);
      if (lookahead == '{') ADVANCE(171);
      if (lookahead == '|') ADVANCE(64);
      if (lookahead == '}') ADVANCE(173);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(53)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(92);
      if (lookahead != 0) ADVANCE(121);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(58);
      if (lookahead == '!') ADVANCE(103);
      if (lookahead == '"') ADVANCE(123);
      if (lookahead == '#') ADVANCE(177);
      if (lookahead == '$') ADVANCE(138);
      if (lookahead == '%') ADVANCE(189);
      if (lookahead == '&') ADVANCE(98);
      if (lookahead == '\'') ADVANCE(128);
      if (lookahead == ')') ADVANCE(85);
      if (lookahead == '*') ADVANCE(185);
      if (lookahead == '+') ADVANCE(180);
      if (lookahead == '-') ADVANCE(182);
      if (lookahead == '.') ADVANCE(26);
      if (lookahead == '/') ADVANCE(187);
      if (lookahead == ';') ADVANCE(57);
      if (lookahead == '<') ADVANCE(199);
      if (lookahead == '=') ADVANCE(104);
      if (lookahead == '>') ADVANCE(195);
      if (lookahead == '?') ADVANCE(82);
      if (lookahead == '[') ADVANCE(74);
      if (lookahead == '\\') ADVANCE(34);
      if (lookahead == '`') ADVANCE(133);
      if (lookahead == '{') ADVANCE(172);
      if (lookahead == '|') ADVANCE(63);
      if (lookahead == '}') ADVANCE(174);
      if (lookahead == '(' ||
          lookahead == ']') ADVANCE(32);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(95);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(154);
      if (lookahead != 0) ADVANCE(105);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(60);
      if (lookahead == '!') ADVANCE(103);
      if (lookahead == '"') ADVANCE(123);
      if (lookahead == '#') ADVANCE(177);
      if (lookahead == '$') ADVANCE(138);
      if (lookahead == '%') ADVANCE(189);
      if (lookahead == '&') ADVANCE(98);
      if (lookahead == '\'') ADVANCE(128);
      if (lookahead == ')') ADVANCE(85);
      if (lookahead == '*') ADVANCE(185);
      if (lookahead == '+') ADVANCE(180);
      if (lookahead == '-') ADVANCE(182);
      if (lookahead == '.') ADVANCE(26);
      if (lookahead == '/') ADVANCE(187);
      if (lookahead == ';') ADVANCE(57);
      if (lookahead == '<') ADVANCE(199);
      if (lookahead == '=') ADVANCE(104);
      if (lookahead == '>') ADVANCE(195);
      if (lookahead == '[') ADVANCE(74);
      if (lookahead == '\\') ADVANCE(34);
      if (lookahead == '`') ADVANCE(133);
      if (lookahead == '{') ADVANCE(172);
      if (lookahead == '|') ADVANCE(63);
      if (lookahead == '}') ADVANCE(174);
      if (lookahead == '(' ||
          lookahead == ']') ADVANCE(32);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(2);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(95);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(154);
      if (lookahead != 0) ADVANCE(105);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(61);
      if (lookahead == '!') ADVANCE(106);
      if (lookahead == '"') ADVANCE(122);
      if (lookahead == '#') ADVANCE(178);
      if (lookahead == '$') ADVANCE(137);
      if (lookahead == '%') ADVANCE(188);
      if (lookahead == '&') ADVANCE(99);
      if (lookahead == '\'') ADVANCE(127);
      if (lookahead == '*') ADVANCE(184);
      if (lookahead == '+') ADVANCE(179);
      if (lookahead == '-') ADVANCE(183);
      if (lookahead == '.') ADVANCE(30);
      if (lookahead == '/') ADVANCE(186);
      if (lookahead == ':') ADVANCE(79);
      if (lookahead == ';') ADVANCE(56);
      if (lookahead == '<') ADVANCE(200);
      if (lookahead == '=') ADVANCE(107);
      if (lookahead == '>') ADVANCE(196);
      if (lookahead == '?') ADVANCE(81);
      if (lookahead == '[') ADVANCE(73);
      if (lookahead == '\\') ADVANCE(47);
      if (lookahead == '`') ADVANCE(132);
      if (lookahead == '{') ADVANCE(171);
      if (lookahead == '|') ADVANCE(64);
      if (lookahead == '}') ADVANCE(173);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(4);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(153);
      if (lookahead != 0 &&
          lookahead != '(' &&
          lookahead != ')' &&
          lookahead != ']') ADVANCE(121);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(61);
      if (lookahead == '!') ADVANCE(103);
      if (lookahead == '"') ADVANCE(123);
      if (lookahead == '#') ADVANCE(177);
      if (lookahead == '$') ADVANCE(138);
      if (lookahead == '%') ADVANCE(189);
      if (lookahead == '&') ADVANCE(98);
      if (lookahead == '\'') ADVANCE(128);
      if (lookahead == '*') ADVANCE(185);
      if (lookahead == '+') ADVANCE(180);
      if (lookahead == '-') ADVANCE(182);
      if (lookahead == '.') ADVANCE(26);
      if (lookahead == '/') ADVANCE(187);
      if (lookahead == ':') ADVANCE(80);
      if (lookahead == ';') ADVANCE(57);
      if (lookahead == '<') ADVANCE(199);
      if (lookahead == '=') ADVANCE(104);
      if (lookahead == '>') ADVANCE(195);
      if (lookahead == '?') ADVANCE(82);
      if (lookahead == '[') ADVANCE(74);
      if (lookahead == '\\') ADVANCE(34);
      if (lookahead == '`') ADVANCE(133);
      if (lookahead == '{') ADVANCE(172);
      if (lookahead == '|') ADVANCE(63);
      if (lookahead == '}') ADVANCE(174);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(4);
      if (lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ']') ADVANCE(32);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(95);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(154);
      if (lookahead != 0) ADVANCE(105);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(62);
      if (lookahead == '!') ADVANCE(103);
      if (lookahead == '"') ADVANCE(123);
      if (lookahead == '#') ADVANCE(177);
      if (lookahead == '$') ADVANCE(138);
      if (lookahead == '%') ADVANCE(189);
      if (lookahead == '&') ADVANCE(98);
      if (lookahead == '\'') ADVANCE(128);
      if (lookahead == ')') ADVANCE(85);
      if (lookahead == '*') ADVANCE(185);
      if (lookahead == '+') ADVANCE(180);
      if (lookahead == '-') ADVANCE(182);
      if (lookahead == '.') ADVANCE(35);
      if (lookahead == '/') ADVANCE(187);
      if (lookahead == ';') ADVANCE(57);
      if (lookahead == '<') ADVANCE(199);
      if (lookahead == '=') ADVANCE(104);
      if (lookahead == '>') ADVANCE(195);
      if (lookahead == '[') ADVANCE(74);
      if (lookahead == '\\') ADVANCE(34);
      if (lookahead == '`') ADVANCE(133);
      if (lookahead == '{') ADVANCE(172);
      if (lookahead == '|') ADVANCE(63);
      if (lookahead == '}') ADVANCE(174);
      if (lookahead == '(' ||
          lookahead == ']') ADVANCE(32);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(5);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(95);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(154);
      if (lookahead != 0) ADVANCE(105);
      END_STATE();
    case 6:
      if (lookahead == ' ') ADVANCE(169);
      if (lookahead == '!') ADVANCE(106);
      if (lookahead == '"') ADVANCE(122);
      if (lookahead == '#') ADVANCE(178);
      if (lookahead == '$') ADVANCE(137);
      if (lookahead == '%') ADVANCE(188);
      if (lookahead == '&') ADVANCE(99);
      if (lookahead == '\'') ADVANCE(127);
      if (lookahead == '*') ADVANCE(184);
      if (lookahead == '+') ADVANCE(179);
      if (lookahead == ',') ADVANCE(75);
      if (lookahead == '-') ADVANCE(183);
      if (lookahead == '.') ADVANCE(30);
      if (lookahead == '/') ADVANCE(186);
      if (lookahead == '<') ADVANCE(200);
      if (lookahead == '=') ADVANCE(107);
      if (lookahead == '>') ADVANCE(196);
      if (lookahead == '[') ADVANCE(73);
      if (lookahead == '\\') ADVANCE(47);
      if (lookahead == ']') ADVANCE(77);
      if (lookahead == '`') ADVANCE(132);
      if (lookahead == '{') ADVANCE(171);
      if (lookahead == '|') ADVANCE(44);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(153);
      if (lookahead != 0 &&
          lookahead != '(' &&
          lookahead != ')' &&
          lookahead != ';' &&
          lookahead != '}') ADVANCE(121);
      END_STATE();
    case 7:
      if (lookahead == ' ') ADVANCE(169);
      if (lookahead == '!') ADVANCE(103);
      if (lookahead == '"') ADVANCE(123);
      if (lookahead == '#') ADVANCE(177);
      if (lookahead == '$') ADVANCE(138);
      if (lookahead == '%') ADVANCE(189);
      if (lookahead == '&') ADVANCE(98);
      if (lookahead == '\'') ADVANCE(128);
      if (lookahead == '*') ADVANCE(185);
      if (lookahead == '+') ADVANCE(180);
      if (lookahead == ',') ADVANCE(76);
      if (lookahead == '-') ADVANCE(182);
      if (lookahead == '.') ADVANCE(26);
      if (lookahead == '/') ADVANCE(187);
      if (lookahead == '<') ADVANCE(199);
      if (lookahead == '=') ADVANCE(104);
      if (lookahead == '>') ADVANCE(195);
      if (lookahead == '[') ADVANCE(74);
      if (lookahead == '\\') ADVANCE(34);
      if (lookahead == ']') ADVANCE(78);
      if (lookahead == '`') ADVANCE(133);
      if (lookahead == '{') ADVANCE(172);
      if (lookahead == '|') ADVANCE(33);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') ADVANCE(7);
      if (lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ';' ||
          lookahead == '}') ADVANCE(32);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(95);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(154);
      if (lookahead != 0) ADVANCE(105);
      END_STATE();
    case 8:
      if (lookahead == ' ') ADVANCE(170);
      if (lookahead == '#') ADVANCE(178);
      if (lookahead == ',') ADVANCE(75);
      if (lookahead == '.') ADVANCE(139);
      if (lookahead == ';') ADVANCE(56);
      if (lookahead == ']') ADVANCE(77);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') SKIP(10)
      END_STATE();
    case 9:
      if (lookahead == ' ') ADVANCE(170);
      if (lookahead == '#') ADVANCE(178);
      if (lookahead == ',') ADVANCE(75);
      if (lookahead == '.') ADVANCE(29);
      if (lookahead == ']') ADVANCE(77);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') SKIP(9)
      END_STATE();
    case 10:
      if (lookahead == ' ') ADVANCE(170);
      if (lookahead == '#') ADVANCE(178);
      if (lookahead == ',') ADVANCE(75);
      if (lookahead == ';') ADVANCE(56);
      if (lookahead == ']') ADVANCE(77);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') SKIP(10)
      END_STATE();
    case 11:
      if (lookahead == '!') ADVANCE(106);
      if (lookahead == '"') ADVANCE(122);
      if (lookahead == '#') ADVANCE(178);
      if (lookahead == '$') ADVANCE(137);
      if (lookahead == '%') ADVANCE(188);
      if (lookahead == '&') ADVANCE(99);
      if (lookahead == '\'') ADVANCE(127);
      if (lookahead == '*') ADVANCE(184);
      if (lookahead == '+') ADVANCE(179);
      if (lookahead == '-') ADVANCE(183);
      if (lookahead == '.') ADVANCE(30);
      if (lookahead == '/') ADVANCE(186);
      if (lookahead == '<') ADVANCE(200);
      if (lookahead == '=') ADVANCE(107);
      if (lookahead == '>') ADVANCE(196);
      if (lookahead == '[') ADVANCE(73);
      if (lookahead == '\\') ADVANCE(47);
      if (lookahead == '`') ADVANCE(132);
      if (lookahead == '{') ADVANCE(171);
      if (lookahead == '|') ADVANCE(44);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(15);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(153);
      if (lookahead != 0 &&
          lookahead != '(' &&
          lookahead != ')' &&
          lookahead != ';' &&
          lookahead != ']' &&
          lookahead != '}') ADVANCE(121);
      END_STATE();
    case 12:
      if (lookahead == '!') ADVANCE(106);
      if (lookahead == '#') ADVANCE(178);
      if (lookahead == '%') ADVANCE(188);
      if (lookahead == '&') ADVANCE(99);
      if (lookahead == ')') ADVANCE(84);
      if (lookahead == '*') ADVANCE(184);
      if (lookahead == '+') ADVANCE(179);
      if (lookahead == ',') ADVANCE(75);
      if (lookahead == '-') ADVANCE(181);
      if (lookahead == '.') ADVANCE(139);
      if (lookahead == '/') ADVANCE(186);
      if (lookahead == '<') ADVANCE(200);
      if (lookahead == '=') ADVANCE(107);
      if (lookahead == '>') ADVANCE(196);
      if (lookahead == '[') ADVANCE(73);
      if (lookahead == '\\') ADVANCE(47);
      if (lookahead == ']') ADVANCE(77);
      if (lookahead == '|') ADVANCE(44);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(13)
      if (lookahead != 0 &&
          (lookahead < '"' || '(' < lookahead) &&
          lookahead != ';' &&
          lookahead != '`' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(121);
      END_STATE();
    case 13:
      if (lookahead == '!') ADVANCE(106);
      if (lookahead == '#') ADVANCE(178);
      if (lookahead == '%') ADVANCE(188);
      if (lookahead == '&') ADVANCE(99);
      if (lookahead == ')') ADVANCE(84);
      if (lookahead == '*') ADVANCE(184);
      if (lookahead == '+') ADVANCE(179);
      if (lookahead == ',') ADVANCE(75);
      if (lookahead == '-') ADVANCE(181);
      if (lookahead == '/') ADVANCE(186);
      if (lookahead == '<') ADVANCE(200);
      if (lookahead == '=') ADVANCE(107);
      if (lookahead == '>') ADVANCE(196);
      if (lookahead == '[') ADVANCE(73);
      if (lookahead == '\\') ADVANCE(47);
      if (lookahead == ']') ADVANCE(77);
      if (lookahead == '|') ADVANCE(44);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(13)
      if (lookahead != 0 &&
          (lookahead < '"' || '.' < lookahead) &&
          lookahead != ';' &&
          lookahead != '`' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(121);
      END_STATE();
    case 14:
      if (lookahead == '!') ADVANCE(106);
      if (lookahead == '#') ADVANCE(178);
      if (lookahead == '%') ADVANCE(188);
      if (lookahead == '&') ADVANCE(99);
      if (lookahead == ')') ADVANCE(84);
      if (lookahead == '*') ADVANCE(184);
      if (lookahead == '+') ADVANCE(179);
      if (lookahead == '-') ADVANCE(181);
      if (lookahead == '/') ADVANCE(186);
      if (lookahead == '<') ADVANCE(200);
      if (lookahead == '=') ADVANCE(107);
      if (lookahead == '>') ADVANCE(196);
      if (lookahead == '\\') ADVANCE(47);
      if (lookahead == '|') ADVANCE(44);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(14)
      if (lookahead != 0 &&
          (lookahead < '"' || '(' < lookahead) &&
          lookahead != '.' &&
          lookahead != ';' &&
          (lookahead < '[' || ']' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(121);
      END_STATE();
    case 15:
      if (lookahead == '!') ADVANCE(103);
      if (lookahead == '"') ADVANCE(123);
      if (lookahead == '#') ADVANCE(177);
      if (lookahead == '$') ADVANCE(138);
      if (lookahead == '%') ADVANCE(189);
      if (lookahead == '&') ADVANCE(98);
      if (lookahead == '\'') ADVANCE(128);
      if (lookahead == '*') ADVANCE(185);
      if (lookahead == '+') ADVANCE(180);
      if (lookahead == '-') ADVANCE(182);
      if (lookahead == '.') ADVANCE(26);
      if (lookahead == '/') ADVANCE(187);
      if (lookahead == '<') ADVANCE(199);
      if (lookahead == '=') ADVANCE(104);
      if (lookahead == '>') ADVANCE(195);
      if (lookahead == '[') ADVANCE(74);
      if (lookahead == '\\') ADVANCE(34);
      if (lookahead == '`') ADVANCE(133);
      if (lookahead == '{') ADVANCE(172);
      if (lookahead == '|') ADVANCE(33);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(15);
      if (lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ';' ||
          lookahead == ']' ||
          lookahead == '}') ADVANCE(32);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(95);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(154);
      if (lookahead != 0) ADVANCE(105);
      END_STATE();
    case 16:
      if (lookahead == '"') ADVANCE(122);
      if (lookahead == '#') ADVANCE(178);
      if (lookahead == '\'') ADVANCE(127);
      if (lookahead == '(') ADVANCE(83);
      if (lookahead == ',') ADVANCE(75);
      if (lookahead == '-') ADVANCE(24);
      if (lookahead == '.') ADVANCE(36);
      if (lookahead == ':') ADVANCE(79);
      if (lookahead == '?') ADVANCE(81);
      if (lookahead == '[') ADVANCE(73);
      if (lookahead == ']') ADVANCE(77);
      if (lookahead == '`') ADVANCE(132);
      if (lookahead == '}') ADVANCE(173);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(16)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(168);
      END_STATE();
    case 17:
      if (lookahead == '#') ADVANCE(178);
      if (lookahead == ',') ADVANCE(75);
      if (lookahead == '.') ADVANCE(29);
      if (lookahead == ']') ADVANCE(77);
      if (lookahead == '}') ADVANCE(173);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(17)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);
      END_STATE();
    case 18:
      if (lookahead == '#') ADVANCE(178);
      if (lookahead == '.') ADVANCE(139);
      if (lookahead == '}') ADVANCE(173);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(21)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);
      END_STATE();
    case 19:
      if (lookahead == '#') ADVANCE(178);
      if (lookahead == '\\') ADVANCE(47);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(19)
      if (lookahead != 0 &&
          (lookahead < '"' || '$' < lookahead) &&
          (lookahead < '\'' || ')' < lookahead) &&
          lookahead != '-' &&
          lookahead != '.' &&
          lookahead != ';' &&
          (lookahead < '[' || ']' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(121);
      END_STATE();
    case 20:
      if (lookahead == '#') ADVANCE(178);
      if (lookahead == 'd') ADVANCE(39);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(20)
      END_STATE();
    case 21:
      if (lookahead == '#') ADVANCE(178);
      if (lookahead == '}') ADVANCE(173);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(21)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);
      END_STATE();
    case 22:
      if (lookahead == '#') ADVANCE(124);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(126);
      END_STATE();
    case 23:
      if (lookahead == '#') ADVANCE(134);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(135);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(136);
      END_STATE();
    case 24:
      if (lookahead == '-') ADVANCE(45);
      END_STATE();
    case 25:
      if (lookahead == '.') ADVANCE(41);
      END_STATE();
    case 26:
      if (lookahead == '.') ADVANCE(145);
      if (lookahead == '/') ADVANCE(146);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(143);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(142);
      END_STATE();
    case 27:
      if (lookahead == '.') ADVANCE(142);
      END_STATE();
    case 28:
      if (lookahead == '.') ADVANCE(150);
      if (lookahead == '/') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 29:
      if (lookahead == '.') ADVANCE(148);
      END_STATE();
    case 30:
      if (lookahead == '.') ADVANCE(31);
      if (lookahead == '/') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 31:
      if (lookahead == '.') ADVANCE(31);
      if (lookahead == '/') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(147);
      END_STATE();
    case 32:
      if (lookahead == '.') ADVANCE(27);
      END_STATE();
    case 33:
      if (lookahead == '.') ADVANCE(27);
      if (lookahead == '|') ADVANCE(190);
      END_STATE();
    case 34:
      if (lookahead == '.') ADVANCE(101);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(121);
      END_STATE();
    case 35:
      if (lookahead == '.') ADVANCE(151);
      if (lookahead == '/') ADVANCE(146);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(143);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(142);
      END_STATE();
    case 36:
      if (lookahead == '.') ADVANCE(25);
      END_STATE();
    case 37:
      if (lookahead == '.') ADVANCE(144);
      if (lookahead == '/') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(147);
      END_STATE();
    case 38:
      if (lookahead == 'e') ADVANCE(42);
      END_STATE();
    case 39:
      if (lookahead == 'e') ADVANCE(40);
      END_STATE();
    case 40:
      if (lookahead == 'f') ADVANCE(67);
      END_STATE();
    case 41:
      if (lookahead == 'r') ADVANCE(38);
      END_STATE();
    case 42:
      if (lookahead == 's') ADVANCE(43);
      END_STATE();
    case 43:
      if (lookahead == 't') ADVANCE(89);
      END_STATE();
    case 44:
      if (lookahead == '|') ADVANCE(190);
      END_STATE();
    case 45:
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(86);
      END_STATE();
    case 46:
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 47:
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(121);
      END_STATE();
    case 48:
      if (eof) ADVANCE(55);
      if (lookahead == '\n') ADVANCE(58);
      if (lookahead == '!') ADVANCE(106);
      if (lookahead == '"') ADVANCE(122);
      if (lookahead == '#') ADVANCE(178);
      if (lookahead == '$') ADVANCE(137);
      if (lookahead == '%') ADVANCE(188);
      if (lookahead == '&') ADVANCE(99);
      if (lookahead == '\'') ADVANCE(127);
      if (lookahead == ')') ADVANCE(84);
      if (lookahead == '*') ADVANCE(184);
      if (lookahead == '+') ADVANCE(179);
      if (lookahead == '-') ADVANCE(183);
      if (lookahead == '.') ADVANCE(30);
      if (lookahead == '/') ADVANCE(186);
      if (lookahead == ';') ADVANCE(56);
      if (lookahead == '<') ADVANCE(200);
      if (lookahead == '=') ADVANCE(107);
      if (lookahead == '>') ADVANCE(196);
      if (lookahead == '?') ADVANCE(81);
      if (lookahead == '[') ADVANCE(73);
      if (lookahead == '\\') ADVANCE(47);
      if (lookahead == '`') ADVANCE(132);
      if (lookahead == '{') ADVANCE(171);
      if (lookahead == '|') ADVANCE(64);
      if (lookahead == '}') ADVANCE(173);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(153);
      if (lookahead != 0 &&
          lookahead != '(' &&
          lookahead != ']') ADVANCE(121);
      END_STATE();
    case 49:
      if (eof) ADVANCE(55);
      if (lookahead == '\n') ADVANCE(59);
      if (lookahead == '!') ADVANCE(106);
      if (lookahead == '#') ADVANCE(178);
      if (lookahead == '%') ADVANCE(188);
      if (lookahead == '&') ADVANCE(99);
      if (lookahead == ')') ADVANCE(84);
      if (lookahead == '*') ADVANCE(184);
      if (lookahead == '+') ADVANCE(179);
      if (lookahead == '-') ADVANCE(181);
      if (lookahead == '.') ADVANCE(139);
      if (lookahead == '/') ADVANCE(186);
      if (lookahead == ';') ADVANCE(56);
      if (lookahead == '<') ADVANCE(200);
      if (lookahead == '=') ADVANCE(107);
      if (lookahead == '>') ADVANCE(196);
      if (lookahead == '\\') ADVANCE(47);
      if (lookahead == '|') ADVANCE(64);
      if (lookahead == '}') ADVANCE(173);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(50)
      if (lookahead != 0 &&
          (lookahead < '"' || '(' < lookahead) &&
          (lookahead < '[' || ']' < lookahead) &&
          lookahead != '`' &&
          lookahead != '{') ADVANCE(121);
      END_STATE();
    case 50:
      if (eof) ADVANCE(55);
      if (lookahead == '\n') ADVANCE(59);
      if (lookahead == '!') ADVANCE(106);
      if (lookahead == '#') ADVANCE(178);
      if (lookahead == '%') ADVANCE(188);
      if (lookahead == '&') ADVANCE(99);
      if (lookahead == ')') ADVANCE(84);
      if (lookahead == '*') ADVANCE(184);
      if (lookahead == '+') ADVANCE(179);
      if (lookahead == '-') ADVANCE(181);
      if (lookahead == '/') ADVANCE(186);
      if (lookahead == ';') ADVANCE(56);
      if (lookahead == '<') ADVANCE(200);
      if (lookahead == '=') ADVANCE(107);
      if (lookahead == '>') ADVANCE(196);
      if (lookahead == '\\') ADVANCE(47);
      if (lookahead == '|') ADVANCE(64);
      if (lookahead == '}') ADVANCE(173);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(50)
      if (lookahead != 0 &&
          (lookahead < '"' || '(' < lookahead) &&
          lookahead != '.' &&
          (lookahead < '[' || ']' < lookahead) &&
          lookahead != '`' &&
          lookahead != '{') ADVANCE(121);
      END_STATE();
    case 51:
      if (eof) ADVANCE(55);
      if (lookahead == '\n') ADVANCE(60);
      if (lookahead == '!') ADVANCE(106);
      if (lookahead == '"') ADVANCE(122);
      if (lookahead == '#') ADVANCE(178);
      if (lookahead == '$') ADVANCE(137);
      if (lookahead == '%') ADVANCE(188);
      if (lookahead == '&') ADVANCE(99);
      if (lookahead == '\'') ADVANCE(127);
      if (lookahead == ')') ADVANCE(84);
      if (lookahead == '*') ADVANCE(184);
      if (lookahead == '+') ADVANCE(179);
      if (lookahead == '-') ADVANCE(183);
      if (lookahead == '.') ADVANCE(141);
      if (lookahead == '/') ADVANCE(186);
      if (lookahead == ';') ADVANCE(56);
      if (lookahead == '<') ADVANCE(200);
      if (lookahead == '=') ADVANCE(107);
      if (lookahead == '>') ADVANCE(196);
      if (lookahead == '[') ADVANCE(73);
      if (lookahead == '\\') ADVANCE(47);
      if (lookahead == '`') ADVANCE(132);
      if (lookahead == '{') ADVANCE(171);
      if (lookahead == '|') ADVANCE(64);
      if (lookahead == '}') ADVANCE(173);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(2);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(153);
      if (lookahead != 0 &&
          lookahead != '(' &&
          lookahead != ']') ADVANCE(121);
      END_STATE();
    case 52:
      if (eof) ADVANCE(55);
      if (lookahead == '\n') ADVANCE(62);
      if (lookahead == '!') ADVANCE(106);
      if (lookahead == '"') ADVANCE(122);
      if (lookahead == '#') ADVANCE(178);
      if (lookahead == '$') ADVANCE(137);
      if (lookahead == '%') ADVANCE(188);
      if (lookahead == '&') ADVANCE(99);
      if (lookahead == '\'') ADVANCE(127);
      if (lookahead == ')') ADVANCE(84);
      if (lookahead == '*') ADVANCE(184);
      if (lookahead == '+') ADVANCE(179);
      if (lookahead == '-') ADVANCE(183);
      if (lookahead == '.') ADVANCE(28);
      if (lookahead == '/') ADVANCE(186);
      if (lookahead == ';') ADVANCE(56);
      if (lookahead == '<') ADVANCE(200);
      if (lookahead == '=') ADVANCE(107);
      if (lookahead == '>') ADVANCE(196);
      if (lookahead == '[') ADVANCE(73);
      if (lookahead == '\\') ADVANCE(47);
      if (lookahead == '`') ADVANCE(132);
      if (lookahead == '{') ADVANCE(171);
      if (lookahead == '|') ADVANCE(64);
      if (lookahead == '}') ADVANCE(173);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(5);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(153);
      if (lookahead != 0 &&
          lookahead != '(' &&
          lookahead != ']') ADVANCE(121);
      END_STATE();
    case 53:
      if (eof) ADVANCE(55);
      if (lookahead == '!') ADVANCE(106);
      if (lookahead == '"') ADVANCE(122);
      if (lookahead == '#') ADVANCE(178);
      if (lookahead == '$') ADVANCE(137);
      if (lookahead == '%') ADVANCE(188);
      if (lookahead == '&') ADVANCE(99);
      if (lookahead == '\'') ADVANCE(127);
      if (lookahead == '(') ADVANCE(83);
      if (lookahead == ')') ADVANCE(84);
      if (lookahead == '*') ADVANCE(184);
      if (lookahead == '+') ADVANCE(179);
      if (lookahead == ',') ADVANCE(75);
      if (lookahead == '-') ADVANCE(183);
      if (lookahead == '.') ADVANCE(175);
      if (lookahead == '/') ADVANCE(186);
      if (lookahead == ':') ADVANCE(79);
      if (lookahead == ';') ADVANCE(56);
      if (lookahead == '<') ADVANCE(200);
      if (lookahead == '=') ADVANCE(72);
      if (lookahead == '>') ADVANCE(196);
      if (lookahead == '?') ADVANCE(81);
      if (lookahead == '[') ADVANCE(73);
      if (lookahead == '\\') ADVANCE(47);
      if (lookahead == ']') ADVANCE(77);
      if (lookahead == '`') ADVANCE(132);
      if (lookahead == 'a') ADVANCE(113);
      if (lookahead == 'd') ADVANCE(109);
      if (lookahead == 'e') ADVANCE(120);
      if (lookahead == 'l') ADVANCE(110);
      if (lookahead == '{') ADVANCE(171);
      if (lookahead == '|') ADVANCE(64);
      if (lookahead == '}') ADVANCE(173);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(53)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(92);
      if (lookahead != 0) ADVANCE(121);
      END_STATE();
    case 54:
      if (eof) ADVANCE(55);
      if (lookahead == '#') ADVANCE(178);
      if (lookahead == '$') ADVANCE(137);
      if (lookahead == '(') ADVANCE(83);
      if (lookahead == ')') ADVANCE(84);
      if (lookahead == '=') ADVANCE(71);
      if (lookahead == '[') ADVANCE(73);
      if (lookahead == 'a') ADVANCE(160);
      if (lookahead == 'd') ADVANCE(156);
      if (lookahead == 'e') ADVANCE(167);
      if (lookahead == 'l') ADVANCE(157);
      if (lookahead == '{') ADVANCE(171);
      if (lookahead == '}') ADVANCE(173);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(54)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(92);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(168);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_SEMI);
      if (lookahead == '.') ADVANCE(27);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(58);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(1);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(59);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(60);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(2);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(61);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(4);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(62);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(5);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '.') ADVANCE(27);
      if (lookahead == '|') ADVANCE(190);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '|') ADVANCE(190);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_export);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_export);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_def);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_def);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_alias);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_alias);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '~') ADVANCE(192);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      if (lookahead == '.') ADVANCE(27);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_COMMA);
      if (lookahead == '.') ADVANCE(27);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      if (lookahead == '.') ADVANCE(27);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == '.') ADVANCE(27);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_QMARK);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_QMARK);
      if (lookahead == '.') ADVANCE(27);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      if (lookahead == '.') ADVANCE(27);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym_flag_name);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(87);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(86);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(sym_flag_name);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(87);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym_flag_shorthand_name);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_DOT_DOT_DOTrest);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_let);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_let);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym_number_literal);
      if (lookahead == '.') ADVANCE(97);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(92);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym_number_literal);
      if (lookahead == '.') ADVANCE(31);
      if (lookahead == '/') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(93);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(147);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym_number_literal);
      if (lookahead == '.') ADVANCE(93);
      if (lookahead == '/') ADVANCE(100);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym_number_literal);
      if (lookahead == '.') ADVANCE(96);
      if (lookahead == '/') ADVANCE(100);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym_number_literal);
      if (lookahead == '.') ADVANCE(144);
      if (lookahead == '/') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(93);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(147);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym_number_literal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(97);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '&') ADVANCE(191);
      if (lookahead == '.') ADVANCE(27);
      if (lookahead == '\\') ADVANCE(47);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(121);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '&') ADVANCE(191);
      if (lookahead == '\\') ADVANCE(47);
      if (!sym_word_character_set_2(lookahead)) ADVANCE(121);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '.') ADVANCE(30);
      if (lookahead == '\\') ADVANCE(47);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      if (!sym_word_character_set_3(lookahead)) ADVANCE(121);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '.') ADVANCE(142);
      if (lookahead == '\\') ADVANCE(47);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(121);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '.') ADVANCE(31);
      if (lookahead == '/') ADVANCE(100);
      if (lookahead == '\\') ADVANCE(47);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(102);
      if (!sym_word_character_set_3(lookahead)) ADVANCE(121);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '.') ADVANCE(27);
      if (lookahead == '=') ADVANCE(194);
      if (lookahead == '\\') ADVANCE(47);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(121);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '.') ADVANCE(27);
      if (lookahead == '=') ADVANCE(193);
      if (lookahead == '\\') ADVANCE(47);
      if (lookahead == '~') ADVANCE(192);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(121);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '.') ADVANCE(27);
      if (lookahead == '\\') ADVANCE(47);
      if (!sym_word_character_set_1(lookahead)) ADVANCE(121);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '=') ADVANCE(194);
      if (lookahead == '\\') ADVANCE(47);
      if (!sym_word_character_set_2(lookahead)) ADVANCE(121);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '=') ADVANCE(193);
      if (lookahead == '\\') ADVANCE(47);
      if (lookahead == '~') ADVANCE(192);
      if (!sym_word_character_set_2(lookahead)) ADVANCE(121);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(47);
      if (lookahead == 'a') ADVANCE(117);
      if (!sym_word_character_set_2(lookahead)) ADVANCE(121);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(47);
      if (lookahead == 'e') ADVANCE(111);
      if (!sym_word_character_set_2(lookahead)) ADVANCE(121);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(47);
      if (lookahead == 'e') ADVANCE(118);
      if (!sym_word_character_set_2(lookahead)) ADVANCE(121);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(47);
      if (lookahead == 'f') ADVANCE(67);
      if (!sym_word_character_set_2(lookahead)) ADVANCE(121);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(47);
      if (lookahead == 'i') ADVANCE(108);
      if (!sym_word_character_set_2(lookahead)) ADVANCE(121);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(47);
      if (lookahead == 'l') ADVANCE(112);
      if (!sym_word_character_set_2(lookahead)) ADVANCE(121);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(47);
      if (lookahead == 'o') ADVANCE(116);
      if (!sym_word_character_set_2(lookahead)) ADVANCE(121);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(47);
      if (lookahead == 'p') ADVANCE(114);
      if (!sym_word_character_set_2(lookahead)) ADVANCE(121);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(47);
      if (lookahead == 'r') ADVANCE(119);
      if (!sym_word_character_set_2(lookahead)) ADVANCE(121);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(47);
      if (lookahead == 's') ADVANCE(69);
      if (!sym_word_character_set_2(lookahead)) ADVANCE(121);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(47);
      if (lookahead == 't') ADVANCE(90);
      if (!sym_word_character_set_2(lookahead)) ADVANCE(121);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(47);
      if (lookahead == 't') ADVANCE(65);
      if (!sym_word_character_set_2(lookahead)) ADVANCE(121);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(47);
      if (lookahead == 'x') ADVANCE(115);
      if (!sym_word_character_set_2(lookahead)) ADVANCE(121);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(47);
      if (!sym_word_character_set_2(lookahead)) ADVANCE(121);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      if (lookahead == '.') ADVANCE(27);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '\n') ADVANCE(126);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(124);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '#') ADVANCE(124);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(125);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(126);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(126);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      if (lookahead == '.') ADVANCE(27);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(aux_sym_string_token2);
      if (lookahead == '\n') ADVANCE(131);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(129);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(aux_sym_string_token2);
      if (lookahead == '#') ADVANCE(129);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(130);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(131);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(aux_sym_string_token2);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(131);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      if (lookahead == '.') ADVANCE(27);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(aux_sym_string_token3);
      if (lookahead == '\n') ADVANCE(136);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(134);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(aux_sym_string_token3);
      if (lookahead == '#') ADVANCE(134);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(135);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(136);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(aux_sym_string_token3);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(136);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      if (lookahead == '(') ADVANCE(152);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      if (lookahead == '(') ADVANCE(152);
      if (lookahead == '.') ADVANCE(27);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_DOT);
      if (lookahead == '.') ADVANCE(149);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(anon_sym_DOT);
      if (lookahead == '.') ADVANCE(31);
      if (lookahead == '/') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(aux_sym_file_path_token1);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(aux_sym_file_path_token1);
      if (lookahead == '.') ADVANCE(31);
      if (lookahead == '/') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(aux_sym_file_path_token1);
      if (lookahead == '.') ADVANCE(31);
      if (lookahead == '/') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(147);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(aux_sym_file_path_token1);
      if (lookahead == '.') ADVANCE(144);
      if (lookahead == '/') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(147);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(aux_sym_file_path_token1);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(aux_sym_file_path_token2);
      if (lookahead == '.') ADVANCE(31);
      if (lookahead == '/') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(147);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(anon_sym_DOT_DOT);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(anon_sym_DOT_DOT);
      if (lookahead == '.') ADVANCE(41);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_DOT_DOT);
      if (lookahead == '.') ADVANCE(31);
      if (lookahead == '/') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(147);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(anon_sym_DOT_DOT);
      if (lookahead == '.') ADVANCE(144);
      if (lookahead == '/') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(147);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(anon_sym_DOLLAR_LPAREN);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(168);
      if (lookahead == '.') ADVANCE(31);
      if (lookahead == '/') ADVANCE(100);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(153);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(168);
      if (lookahead == '.') ADVANCE(37);
      if (lookahead == '/') ADVANCE(100);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(153);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(164);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(168);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(158);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(165);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'f') ADVANCE(68);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(155);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(159);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(163);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(161);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(166);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(70);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(91);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(66);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'x') ADVANCE(162);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(168);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(anon_sym_);
      if (lookahead == ' ') ADVANCE(169);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') ADVANCE(7);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(anon_sym_);
      if (lookahead == ' ') ADVANCE(170);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      if (lookahead == '.') ADVANCE(27);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      if (lookahead == '.') ADVANCE(27);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(anon_sym_DOT2);
      if (lookahead == '.') ADVANCE(149);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead == '.') ADVANCE(142);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(178);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead == '.') ADVANCE(176);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(178);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(178);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '.') ADVANCE(27);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '-') ADVANCE(45);
      if (lookahead == '.') ADVANCE(27);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '-') ADVANCE(45);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '.') ADVANCE(27);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '.') ADVANCE(27);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '.') ADVANCE(27);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(anon_sym_EQ_TILDE);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(anon_sym_BANG_EQ);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '.') ADVANCE(27);
      if (lookahead == '=') ADVANCE(197);
      if (lookahead == '>') ADVANCE(202);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(197);
      if (lookahead == '>') ADVANCE(202);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '.') ADVANCE(27);
      if (lookahead == '<') ADVANCE(201);
      if (lookahead == '=') ADVANCE(198);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '<') ADVANCE(201);
      if (lookahead == '=') ADVANCE(198);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(anon_sym_LT_LT);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(anon_sym_GT_GT);
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
      if (lookahead == 'm') ADVANCE(4);
      if (lookahead == 'n') ADVANCE(5);
      if (lookahead == 'p') ADVANCE(6);
      if (lookahead == 'r') ADVANCE(7);
      if (lookahead == 's') ADVANCE(8);
      if (lookahead == 't') ADVANCE(9);
      if (lookahead == 'u') ADVANCE(10);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == 'n') ADVANCE(11);
      END_STATE();
    case 2:
      if (lookahead == 'l') ADVANCE(12);
      END_STATE();
    case 3:
      if (lookahead == 'n') ADVANCE(13);
      END_STATE();
    case 4:
      if (lookahead == 'o') ADVANCE(14);
      END_STATE();
    case 5:
      if (lookahead == 'u') ADVANCE(15);
      END_STATE();
    case 6:
      if (lookahead == 'a') ADVANCE(16);
      END_STATE();
    case 7:
      if (lookahead == 'a') ADVANCE(17);
      END_STATE();
    case 8:
      if (lookahead == 't') ADVANCE(18);
      END_STATE();
    case 9:
      if (lookahead == 'a') ADVANCE(19);
      END_STATE();
    case 10:
      if (lookahead == 'n') ADVANCE(20);
      END_STATE();
    case 11:
      if (lookahead == 'y') ADVANCE(21);
      END_STATE();
    case 12:
      if (lookahead == 'o') ADVANCE(22);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_in);
      if (lookahead == 't') ADVANCE(23);
      END_STATE();
    case 14:
      if (lookahead == 'd') ADVANCE(24);
      END_STATE();
    case 15:
      if (lookahead == 'm') ADVANCE(25);
      END_STATE();
    case 16:
      if (lookahead == 't') ADVANCE(26);
      END_STATE();
    case 17:
      if (lookahead == 'n') ADVANCE(27);
      END_STATE();
    case 18:
      if (lookahead == 'r') ADVANCE(28);
      END_STATE();
    case 19:
      if (lookahead == 'b') ADVANCE(29);
      END_STATE();
    case 20:
      if (lookahead == 'i') ADVANCE(30);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_any);
      END_STATE();
    case 22:
      if (lookahead == 'c') ADVANCE(31);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_int);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_mod);
      END_STATE();
    case 25:
      if (lookahead == 'b') ADVANCE(32);
      END_STATE();
    case 26:
      if (lookahead == 'h') ADVANCE(33);
      if (lookahead == 't') ADVANCE(34);
      END_STATE();
    case 27:
      if (lookahead == 'g') ADVANCE(35);
      END_STATE();
    case 28:
      if (lookahead == 'i') ADVANCE(36);
      END_STATE();
    case 29:
      if (lookahead == 'l') ADVANCE(37);
      END_STATE();
    case 30:
      if (lookahead == 't') ADVANCE(38);
      END_STATE();
    case 31:
      if (lookahead == 'k') ADVANCE(39);
      END_STATE();
    case 32:
      if (lookahead == 'e') ADVANCE(40);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_path);
      END_STATE();
    case 34:
      if (lookahead == 'e') ADVANCE(41);
      END_STATE();
    case 35:
      if (lookahead == 'e') ADVANCE(42);
      END_STATE();
    case 36:
      if (lookahead == 'n') ADVANCE(43);
      END_STATE();
    case 37:
      if (lookahead == 'e') ADVANCE(44);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_unit);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_block);
      END_STATE();
    case 40:
      if (lookahead == 'r') ADVANCE(45);
      END_STATE();
    case 41:
      if (lookahead == 'r') ADVANCE(46);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_range);
      END_STATE();
    case 43:
      if (lookahead == 'g') ADVANCE(47);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_table);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_number);
      END_STATE();
    case 46:
      if (lookahead == 'n') ADVANCE(48);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_string);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_pattern);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 54},
  [2] = {.lex_state = 48},
  [3] = {.lex_state = 51},
  [4] = {.lex_state = 51},
  [5] = {.lex_state = 51},
  [6] = {.lex_state = 51},
  [7] = {.lex_state = 3},
  [8] = {.lex_state = 6},
  [9] = {.lex_state = 6},
  [10] = {.lex_state = 6},
  [11] = {.lex_state = 6},
  [12] = {.lex_state = 6},
  [13] = {.lex_state = 6},
  [14] = {.lex_state = 6},
  [15] = {.lex_state = 11},
  [16] = {.lex_state = 11},
  [17] = {.lex_state = 11},
  [18] = {.lex_state = 11},
  [19] = {.lex_state = 51},
  [20] = {.lex_state = 51},
  [21] = {.lex_state = 51},
  [22] = {.lex_state = 52},
  [23] = {.lex_state = 51},
  [24] = {.lex_state = 51},
  [25] = {.lex_state = 51},
  [26] = {.lex_state = 51},
  [27] = {.lex_state = 51},
  [28] = {.lex_state = 51},
  [29] = {.lex_state = 51},
  [30] = {.lex_state = 51},
  [31] = {.lex_state = 51},
  [32] = {.lex_state = 51},
  [33] = {.lex_state = 51},
  [34] = {.lex_state = 51},
  [35] = {.lex_state = 51},
  [36] = {.lex_state = 51},
  [37] = {.lex_state = 54},
  [38] = {.lex_state = 54},
  [39] = {.lex_state = 54},
  [40] = {.lex_state = 54},
  [41] = {.lex_state = 54},
  [42] = {.lex_state = 54},
  [43] = {.lex_state = 54},
  [44] = {.lex_state = 54},
  [45] = {.lex_state = 54},
  [46] = {.lex_state = 54},
  [47] = {.lex_state = 54},
  [48] = {.lex_state = 54},
  [49] = {.lex_state = 54},
  [50] = {.lex_state = 49},
  [51] = {.lex_state = 54},
  [52] = {.lex_state = 49},
  [53] = {.lex_state = 49},
  [54] = {.lex_state = 49},
  [55] = {.lex_state = 49},
  [56] = {.lex_state = 49},
  [57] = {.lex_state = 49},
  [58] = {.lex_state = 49},
  [59] = {.lex_state = 49},
  [60] = {.lex_state = 49},
  [61] = {.lex_state = 49},
  [62] = {.lex_state = 49},
  [63] = {.lex_state = 49},
  [64] = {.lex_state = 49},
  [65] = {.lex_state = 49},
  [66] = {.lex_state = 49},
  [67] = {.lex_state = 49},
  [68] = {.lex_state = 49},
  [69] = {.lex_state = 49},
  [70] = {.lex_state = 49},
  [71] = {.lex_state = 49},
  [72] = {.lex_state = 49},
  [73] = {.lex_state = 49},
  [74] = {.lex_state = 12},
  [75] = {.lex_state = 12},
  [76] = {.lex_state = 12},
  [77] = {.lex_state = 12},
  [78] = {.lex_state = 12},
  [79] = {.lex_state = 12},
  [80] = {.lex_state = 12},
  [81] = {.lex_state = 12},
  [82] = {.lex_state = 12},
  [83] = {.lex_state = 12},
  [84] = {.lex_state = 12},
  [85] = {.lex_state = 12},
  [86] = {.lex_state = 14},
  [87] = {.lex_state = 14},
  [88] = {.lex_state = 14},
  [89] = {.lex_state = 14},
  [90] = {.lex_state = 14},
  [91] = {.lex_state = 14},
  [92] = {.lex_state = 14},
  [93] = {.lex_state = 14},
  [94] = {.lex_state = 14},
  [95] = {.lex_state = 14},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 54},
  [98] = {.lex_state = 54},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 0},
  [111] = {.lex_state = 0},
  [112] = {.lex_state = 0},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 0},
  [116] = {.lex_state = 54},
  [117] = {.lex_state = 19},
  [118] = {.lex_state = 19},
  [119] = {.lex_state = 19},
  [120] = {.lex_state = 19},
  [121] = {.lex_state = 16},
  [122] = {.lex_state = 16},
  [123] = {.lex_state = 16},
  [124] = {.lex_state = 49},
  [125] = {.lex_state = 49},
  [126] = {.lex_state = 16},
  [127] = {.lex_state = 16},
  [128] = {.lex_state = 16},
  [129] = {.lex_state = 16},
  [130] = {.lex_state = 49},
  [131] = {.lex_state = 49},
  [132] = {.lex_state = 49},
  [133] = {.lex_state = 49},
  [134] = {.lex_state = 49},
  [135] = {.lex_state = 16},
  [136] = {.lex_state = 49},
  [137] = {.lex_state = 49},
  [138] = {.lex_state = 16},
  [139] = {.lex_state = 16},
  [140] = {.lex_state = 8},
  [141] = {.lex_state = 16},
  [142] = {.lex_state = 16},
  [143] = {.lex_state = 8},
  [144] = {.lex_state = 16},
  [145] = {.lex_state = 17},
  [146] = {.lex_state = 16},
  [147] = {.lex_state = 16},
  [148] = {.lex_state = 16},
  [149] = {.lex_state = 8},
  [150] = {.lex_state = 8},
  [151] = {.lex_state = 16},
  [152] = {.lex_state = 16},
  [153] = {.lex_state = 8},
  [154] = {.lex_state = 8},
  [155] = {.lex_state = 8},
  [156] = {.lex_state = 8},
  [157] = {.lex_state = 0},
  [158] = {.lex_state = 0},
  [159] = {.lex_state = 8},
  [160] = {.lex_state = 8},
  [161] = {.lex_state = 8},
  [162] = {.lex_state = 8},
  [163] = {.lex_state = 8},
  [164] = {.lex_state = 0},
  [165] = {.lex_state = 0},
  [166] = {.lex_state = 49},
  [167] = {.lex_state = 8},
  [168] = {.lex_state = 0},
  [169] = {.lex_state = 8},
  [170] = {.lex_state = 8},
  [171] = {.lex_state = 0},
  [172] = {.lex_state = 8},
  [173] = {.lex_state = 8},
  [174] = {.lex_state = 8},
  [175] = {.lex_state = 0},
  [176] = {.lex_state = 18},
  [177] = {.lex_state = 8},
  [178] = {.lex_state = 18},
  [179] = {.lex_state = 16},
  [180] = {.lex_state = 16},
  [181] = {.lex_state = 18},
  [182] = {.lex_state = 9},
  [183] = {.lex_state = 8},
  [184] = {.lex_state = 0},
  [185] = {.lex_state = 0},
  [186] = {.lex_state = 16},
  [187] = {.lex_state = 8},
  [188] = {.lex_state = 16},
  [189] = {.lex_state = 0},
  [190] = {.lex_state = 8},
  [191] = {.lex_state = 0},
  [192] = {.lex_state = 0},
  [193] = {.lex_state = 8},
  [194] = {.lex_state = 8},
  [195] = {.lex_state = 8},
  [196] = {.lex_state = 16},
  [197] = {.lex_state = 16},
  [198] = {.lex_state = 0},
  [199] = {.lex_state = 8},
  [200] = {.lex_state = 8},
  [201] = {.lex_state = 8},
  [202] = {.lex_state = 8},
  [203] = {.lex_state = 8},
  [204] = {.lex_state = 16},
  [205] = {.lex_state = 8},
  [206] = {.lex_state = 8},
  [207] = {.lex_state = 8},
  [208] = {.lex_state = 0},
  [209] = {.lex_state = 16},
  [210] = {.lex_state = 8},
  [211] = {.lex_state = 16},
  [212] = {.lex_state = 16},
  [213] = {.lex_state = 8},
  [214] = {.lex_state = 18},
  [215] = {.lex_state = 8},
  [216] = {.lex_state = 16},
  [217] = {.lex_state = 0},
  [218] = {.lex_state = 16},
  [219] = {.lex_state = 16},
  [220] = {.lex_state = 16},
  [221] = {.lex_state = 16},
  [222] = {.lex_state = 16},
  [223] = {.lex_state = 16},
  [224] = {.lex_state = 0},
  [225] = {.lex_state = 0},
  [226] = {.lex_state = 16},
  [227] = {.lex_state = 0},
  [228] = {.lex_state = 0},
  [229] = {.lex_state = 16},
  [230] = {.lex_state = 0},
  [231] = {.lex_state = 0},
  [232] = {.lex_state = 16},
  [233] = {.lex_state = 130},
  [234] = {.lex_state = 16},
  [235] = {.lex_state = 54},
  [236] = {.lex_state = 0},
  [237] = {.lex_state = 16},
  [238] = {.lex_state = 22},
  [239] = {.lex_state = 0},
  [240] = {.lex_state = 0},
  [241] = {.lex_state = 0},
  [242] = {.lex_state = 0},
  [243] = {.lex_state = 23},
  [244] = {.lex_state = 0},
  [245] = {.lex_state = 0},
  [246] = {.lex_state = 0},
  [247] = {.lex_state = 0},
  [248] = {.lex_state = 0},
  [249] = {.lex_state = 0},
  [250] = {.lex_state = 16},
  [251] = {.lex_state = 0},
  [252] = {.lex_state = 0},
  [253] = {.lex_state = 16},
  [254] = {.lex_state = 0},
  [255] = {.lex_state = 0},
  [256] = {.lex_state = 54},
  [257] = {.lex_state = 0},
  [258] = {.lex_state = 0},
  [259] = {.lex_state = 0},
  [260] = {.lex_state = 0},
  [261] = {.lex_state = 0},
  [262] = {.lex_state = 0},
  [263] = {.lex_state = 0},
  [264] = {.lex_state = 0},
  [265] = {.lex_state = 16},
  [266] = {.lex_state = 0},
  [267] = {.lex_state = 16},
  [268] = {.lex_state = 16},
  [269] = {.lex_state = 16},
  [270] = {.lex_state = 20},
  [271] = {.lex_state = 0},
  [272] = {.lex_state = 0},
  [273] = {.lex_state = 0},
  [274] = {.lex_state = 16},
  [275] = {.lex_state = 0},
  [276] = {.lex_state = 0},
  [277] = {.lex_state = 16},
  [278] = {.lex_state = 0},
  [279] = {.lex_state = 0},
  [280] = {.lex_state = 0},
  [281] = {.lex_state = 22},
  [282] = {.lex_state = 130},
  [283] = {.lex_state = 23},
  [284] = {.lex_state = 0},
  [285] = {.lex_state = 0},
  [286] = {.lex_state = 22},
  [287] = {.lex_state = 130},
  [288] = {.lex_state = 23},
  [289] = {.lex_state = 0},
  [290] = {.lex_state = 16},
  [291] = {.lex_state = 22},
  [292] = {.lex_state = 130},
  [293] = {.lex_state = 23},
  [294] = {.lex_state = 0},
  [295] = {.lex_state = 0},
  [296] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_word] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_export] = ACTIONS(1),
    [anon_sym_def] = ACTIONS(1),
    [anon_sym_alias] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_QMARK] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [sym_flag_name] = ACTIONS(1),
    [sym_flag_shorthand_name] = ACTIONS(1),
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
    [sym_number_literal] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_BQUOTE] = ACTIONS(1),
    [anon_sym_DOLLAR] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_DOT_DOT] = ACTIONS(1),
    [anon_sym_DOLLAR_LPAREN] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_DOT2] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_mod] = ACTIONS(1),
    [anon_sym_PIPE_PIPE] = ACTIONS(1),
    [anon_sym_AMP_AMP] = ACTIONS(1),
    [anon_sym_EQ_TILDE] = ACTIONS(1),
    [anon_sym_BANG_EQ] = ACTIONS(1),
    [anon_sym_in] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_GT_EQ] = ACTIONS(1),
    [anon_sym_LT_EQ] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_LT_LT] = ACTIONS(1),
    [anon_sym_GT_GT] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(254),
    [sym__statements] = STATE(252),
    [sym__statement] = STATE(124),
    [sym_function_definition] = STATE(124),
    [sym_alias] = STATE(124),
    [sym_variable_declaration] = STATE(124),
    [sym_command] = STATE(124),
    [sym_value_path] = STATE(71),
    [sym_command_substitution] = STATE(71),
    [sym_math_mode] = STATE(124),
    [sym_table] = STATE(71),
    [sym_array] = STATE(71),
    [sym_record_or_block] = STATE(71),
    [sym__math_expression] = STATE(71),
    [sym_parenthesized_math_expression] = STATE(71),
    [sym_binary_expression] = STATE(71),
    [aux_sym__statements_repeat1] = STATE(49),
    [ts_builtin_sym_end] = ACTIONS(5),
    [anon_sym_export] = ACTIONS(7),
    [anon_sym_def] = ACTIONS(9),
    [anon_sym_alias] = ACTIONS(11),
    [anon_sym_EQ] = ACTIONS(13),
    [anon_sym_LBRACK] = ACTIONS(15),
    [anon_sym_LPAREN] = ACTIONS(17),
    [anon_sym_let] = ACTIONS(19),
    [sym_number_literal] = ACTIONS(21),
    [anon_sym_DOLLAR] = ACTIONS(23),
    [anon_sym_DOLLAR_LPAREN] = ACTIONS(25),
    [sym_identifier] = ACTIONS(27),
    [anon_sym_LBRACE] = ACTIONS(29),
    [sym_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 17,
    ACTIONS(37), 1,
      anon_sym_LBRACK,
    ACTIONS(39), 1,
      anon_sym_QMARK,
    ACTIONS(41), 1,
      sym_number_literal,
    ACTIONS(43), 1,
      anon_sym_DQUOTE,
    ACTIONS(45), 1,
      anon_sym_SQUOTE,
    ACTIONS(47), 1,
      anon_sym_BQUOTE,
    ACTIONS(49), 1,
      anon_sym_DOLLAR,
    ACTIONS(53), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(55), 1,
      anon_sym_LBRACE,
    ACTIONS(57), 1,
      sym_comment,
    STATE(6), 1,
      aux_sym_command_repeat1,
    ACTIONS(31), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(51), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(33), 4,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_word,
      sym_identifier,
    ACTIONS(35), 4,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
    STATE(36), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym_operator,
    ACTIONS(59), 18,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [87] = 16,
    ACTIONS(37), 1,
      anon_sym_LBRACK,
    ACTIONS(41), 1,
      sym_number_literal,
    ACTIONS(43), 1,
      anon_sym_DQUOTE,
    ACTIONS(45), 1,
      anon_sym_SQUOTE,
    ACTIONS(47), 1,
      anon_sym_BQUOTE,
    ACTIONS(49), 1,
      anon_sym_DOLLAR,
    ACTIONS(53), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(55), 1,
      anon_sym_LBRACE,
    ACTIONS(57), 1,
      sym_comment,
    STATE(5), 1,
      aux_sym_command_repeat1,
    ACTIONS(51), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(61), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(33), 4,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_word,
      sym_identifier,
    ACTIONS(63), 4,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
    STATE(36), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym_operator,
    ACTIONS(59), 18,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [171] = 16,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(72), 1,
      anon_sym_LBRACK,
    ACTIONS(75), 1,
      sym_number_literal,
    ACTIONS(78), 1,
      anon_sym_DQUOTE,
    ACTIONS(81), 1,
      anon_sym_SQUOTE,
    ACTIONS(84), 1,
      anon_sym_BQUOTE,
    ACTIONS(87), 1,
      anon_sym_DOLLAR,
    ACTIONS(93), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(96), 1,
      anon_sym_LBRACE,
    STATE(4), 1,
      aux_sym_command_repeat1,
    ACTIONS(65), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(90), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(67), 4,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_word,
      sym_identifier,
    ACTIONS(70), 4,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
    STATE(36), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym_operator,
    ACTIONS(99), 18,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [255] = 16,
    ACTIONS(37), 1,
      anon_sym_LBRACK,
    ACTIONS(41), 1,
      sym_number_literal,
    ACTIONS(43), 1,
      anon_sym_DQUOTE,
    ACTIONS(45), 1,
      anon_sym_SQUOTE,
    ACTIONS(47), 1,
      anon_sym_BQUOTE,
    ACTIONS(49), 1,
      anon_sym_DOLLAR,
    ACTIONS(53), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(55), 1,
      anon_sym_LBRACE,
    ACTIONS(57), 1,
      sym_comment,
    STATE(4), 1,
      aux_sym_command_repeat1,
    ACTIONS(51), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(102), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(33), 4,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_word,
      sym_identifier,
    ACTIONS(104), 4,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
    STATE(36), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym_operator,
    ACTIONS(59), 18,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [339] = 16,
    ACTIONS(37), 1,
      anon_sym_LBRACK,
    ACTIONS(41), 1,
      sym_number_literal,
    ACTIONS(43), 1,
      anon_sym_DQUOTE,
    ACTIONS(45), 1,
      anon_sym_SQUOTE,
    ACTIONS(47), 1,
      anon_sym_BQUOTE,
    ACTIONS(49), 1,
      anon_sym_DOLLAR,
    ACTIONS(53), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(55), 1,
      anon_sym_LBRACE,
    ACTIONS(57), 1,
      sym_comment,
    STATE(4), 1,
      aux_sym_command_repeat1,
    ACTIONS(51), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(106), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(33), 4,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_word,
      sym_identifier,
    ACTIONS(108), 4,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
    STATE(36), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym_operator,
    ACTIONS(59), 18,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [423] = 18,
    ACTIONS(31), 1,
      anon_sym_LF,
    ACTIONS(37), 1,
      anon_sym_LBRACK,
    ACTIONS(39), 1,
      anon_sym_QMARK,
    ACTIONS(41), 1,
      sym_number_literal,
    ACTIONS(43), 1,
      anon_sym_DQUOTE,
    ACTIONS(45), 1,
      anon_sym_SQUOTE,
    ACTIONS(47), 1,
      anon_sym_BQUOTE,
    ACTIONS(49), 1,
      anon_sym_DOLLAR,
    ACTIONS(53), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(55), 1,
      anon_sym_LBRACE,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(110), 1,
      anon_sym_COLON,
    STATE(6), 1,
      aux_sym_command_repeat1,
    ACTIONS(51), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(35), 3,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RBRACE,
    ACTIONS(33), 4,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_word,
      sym_identifier,
    STATE(36), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym_operator,
    ACTIONS(59), 18,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [511] = 19,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(114), 1,
      anon_sym_LBRACK,
    ACTIONS(116), 1,
      anon_sym_COMMA,
    ACTIONS(118), 1,
      anon_sym_RBRACK,
    ACTIONS(120), 1,
      sym_number_literal,
    ACTIONS(122), 1,
      anon_sym_DQUOTE,
    ACTIONS(124), 1,
      anon_sym_SQUOTE,
    ACTIONS(126), 1,
      anon_sym_BQUOTE,
    ACTIONS(128), 1,
      anon_sym_DOLLAR,
    ACTIONS(132), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(134), 1,
      anon_sym_,
    ACTIONS(136), 1,
      anon_sym_LBRACE,
    STATE(154), 1,
      aux_sym_array_repeat1,
    STATE(208), 1,
      aux_sym_column_header_repeat1,
    STATE(284), 1,
      sym_column_header,
    ACTIONS(130), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(112), 4,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_word,
      sym_identifier,
    STATE(140), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym_operator,
    ACTIONS(138), 18,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [600] = 18,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(114), 1,
      anon_sym_LBRACK,
    ACTIONS(120), 1,
      sym_number_literal,
    ACTIONS(122), 1,
      anon_sym_DQUOTE,
    ACTIONS(124), 1,
      anon_sym_SQUOTE,
    ACTIONS(126), 1,
      anon_sym_BQUOTE,
    ACTIONS(128), 1,
      anon_sym_DOLLAR,
    ACTIONS(132), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(134), 1,
      anon_sym_,
    ACTIONS(136), 1,
      anon_sym_LBRACE,
    ACTIONS(142), 1,
      anon_sym_COMMA,
    ACTIONS(144), 1,
      anon_sym_RBRACK,
    STATE(172), 1,
      aux_sym_array_repeat1,
    STATE(294), 1,
      sym_column_header,
    ACTIONS(130), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(140), 4,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_word,
      sym_identifier,
    STATE(162), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym_operator,
    ACTIONS(138), 18,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [686] = 18,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(114), 1,
      anon_sym_LBRACK,
    ACTIONS(120), 1,
      sym_number_literal,
    ACTIONS(122), 1,
      anon_sym_DQUOTE,
    ACTIONS(124), 1,
      anon_sym_SQUOTE,
    ACTIONS(126), 1,
      anon_sym_BQUOTE,
    ACTIONS(128), 1,
      anon_sym_DOLLAR,
    ACTIONS(132), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(134), 1,
      anon_sym_,
    ACTIONS(136), 1,
      anon_sym_LBRACE,
    ACTIONS(142), 1,
      anon_sym_COMMA,
    ACTIONS(148), 1,
      anon_sym_RBRACK,
    STATE(154), 1,
      aux_sym_array_repeat1,
    STATE(284), 1,
      sym_column_header,
    ACTIONS(130), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(146), 4,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_word,
      sym_identifier,
    STATE(153), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym_operator,
    ACTIONS(138), 18,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [772] = 18,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(114), 1,
      anon_sym_LBRACK,
    ACTIONS(120), 1,
      sym_number_literal,
    ACTIONS(122), 1,
      anon_sym_DQUOTE,
    ACTIONS(124), 1,
      anon_sym_SQUOTE,
    ACTIONS(126), 1,
      anon_sym_BQUOTE,
    ACTIONS(128), 1,
      anon_sym_DOLLAR,
    ACTIONS(132), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(134), 1,
      anon_sym_,
    ACTIONS(136), 1,
      anon_sym_LBRACE,
    ACTIONS(142), 1,
      anon_sym_COMMA,
    ACTIONS(152), 1,
      anon_sym_RBRACK,
    STATE(155), 1,
      aux_sym_array_repeat1,
    STATE(296), 1,
      sym_column_header,
    ACTIONS(130), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(150), 4,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_word,
      sym_identifier,
    STATE(163), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym_operator,
    ACTIONS(138), 18,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [858] = 18,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(114), 1,
      anon_sym_LBRACK,
    ACTIONS(120), 1,
      sym_number_literal,
    ACTIONS(122), 1,
      anon_sym_DQUOTE,
    ACTIONS(124), 1,
      anon_sym_SQUOTE,
    ACTIONS(126), 1,
      anon_sym_BQUOTE,
    ACTIONS(128), 1,
      anon_sym_DOLLAR,
    ACTIONS(132), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(134), 1,
      anon_sym_,
    ACTIONS(136), 1,
      anon_sym_LBRACE,
    ACTIONS(142), 1,
      anon_sym_COMMA,
    ACTIONS(156), 1,
      anon_sym_RBRACK,
    STATE(190), 1,
      aux_sym_array_repeat1,
    STATE(236), 1,
      sym_column_header,
    ACTIONS(130), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(154), 4,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_word,
      sym_identifier,
    STATE(187), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym_operator,
    ACTIONS(138), 18,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [944] = 18,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(114), 1,
      anon_sym_LBRACK,
    ACTIONS(120), 1,
      sym_number_literal,
    ACTIONS(122), 1,
      anon_sym_DQUOTE,
    ACTIONS(124), 1,
      anon_sym_SQUOTE,
    ACTIONS(126), 1,
      anon_sym_BQUOTE,
    ACTIONS(128), 1,
      anon_sym_DOLLAR,
    ACTIONS(132), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(134), 1,
      anon_sym_,
    ACTIONS(136), 1,
      anon_sym_LBRACE,
    ACTIONS(142), 1,
      anon_sym_COMMA,
    ACTIONS(160), 1,
      anon_sym_RBRACK,
    STATE(161), 1,
      aux_sym_array_repeat1,
    STATE(289), 1,
      sym_column_header,
    ACTIONS(130), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(158), 4,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_word,
      sym_identifier,
    STATE(173), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym_operator,
    ACTIONS(138), 18,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [1030] = 17,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(120), 1,
      sym_number_literal,
    ACTIONS(122), 1,
      anon_sym_DQUOTE,
    ACTIONS(124), 1,
      anon_sym_SQUOTE,
    ACTIONS(126), 1,
      anon_sym_BQUOTE,
    ACTIONS(128), 1,
      anon_sym_DOLLAR,
    ACTIONS(132), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(134), 1,
      anon_sym_,
    ACTIONS(136), 1,
      anon_sym_LBRACE,
    ACTIONS(142), 1,
      anon_sym_COMMA,
    ACTIONS(160), 1,
      anon_sym_RBRACK,
    ACTIONS(162), 1,
      anon_sym_LBRACK,
    STATE(161), 1,
      aux_sym_array_repeat1,
    ACTIONS(130), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(158), 4,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_word,
      sym_identifier,
    STATE(173), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym_operator,
    ACTIONS(138), 18,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [1113] = 15,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(120), 1,
      sym_number_literal,
    ACTIONS(122), 1,
      anon_sym_DQUOTE,
    ACTIONS(124), 1,
      anon_sym_SQUOTE,
    ACTIONS(126), 1,
      anon_sym_BQUOTE,
    ACTIONS(128), 1,
      anon_sym_DOLLAR,
    ACTIONS(136), 1,
      anon_sym_LBRACE,
    ACTIONS(162), 1,
      anon_sym_LBRACK,
    ACTIONS(168), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(130), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(164), 2,
      sym_word,
      sym_identifier,
    ACTIONS(166), 2,
      sym_flag_name,
      sym_flag_shorthand_name,
    ACTIONS(138), 9,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(170), 9,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    STATE(207), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym_operator,
  [1188] = 15,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(174), 1,
      anon_sym_LBRACK,
    ACTIONS(178), 1,
      sym_number_literal,
    ACTIONS(180), 1,
      anon_sym_DQUOTE,
    ACTIONS(182), 1,
      anon_sym_SQUOTE,
    ACTIONS(184), 1,
      anon_sym_BQUOTE,
    ACTIONS(186), 1,
      anon_sym_DOLLAR,
    ACTIONS(190), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(192), 1,
      anon_sym_LBRACE,
    ACTIONS(172), 2,
      sym_word,
      sym_identifier,
    ACTIONS(176), 2,
      sym_flag_name,
      sym_flag_shorthand_name,
    ACTIONS(188), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(194), 9,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(196), 9,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    STATE(228), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym_operator,
  [1263] = 15,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(120), 1,
      sym_number_literal,
    ACTIONS(122), 1,
      anon_sym_DQUOTE,
    ACTIONS(124), 1,
      anon_sym_SQUOTE,
    ACTIONS(126), 1,
      anon_sym_BQUOTE,
    ACTIONS(128), 1,
      anon_sym_DOLLAR,
    ACTIONS(136), 1,
      anon_sym_LBRACE,
    ACTIONS(162), 1,
      anon_sym_LBRACK,
    ACTIONS(168), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(130), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(198), 2,
      sym_word,
      sym_identifier,
    ACTIONS(200), 2,
      sym_flag_name,
      sym_flag_shorthand_name,
    ACTIONS(138), 9,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(170), 9,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    STATE(206), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym_operator,
  [1338] = 15,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(178), 1,
      sym_number_literal,
    ACTIONS(180), 1,
      anon_sym_DQUOTE,
    ACTIONS(182), 1,
      anon_sym_SQUOTE,
    ACTIONS(184), 1,
      anon_sym_BQUOTE,
    ACTIONS(204), 1,
      anon_sym_LBRACK,
    ACTIONS(208), 1,
      anon_sym_DOLLAR,
    ACTIONS(210), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(212), 1,
      anon_sym_LBRACE,
    ACTIONS(188), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(202), 2,
      sym_word,
      sym_identifier,
    ACTIONS(206), 2,
      sym_flag_name,
      sym_flag_shorthand_name,
    ACTIONS(194), 9,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(196), 9,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    STATE(229), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym_operator,
  [1413] = 5,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(218), 1,
      anon_sym_DOT,
    STATE(19), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(214), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(216), 36,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_DOLLAR,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [1465] = 5,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(225), 1,
      anon_sym_DOT,
    STATE(19), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(221), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(223), 36,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_DOLLAR,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [1517] = 5,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(225), 1,
      anon_sym_DOT,
    STATE(20), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(227), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(229), 36,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_DOLLAR,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [1569] = 4,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(235), 1,
      anon_sym_DOT_DOT,
    ACTIONS(231), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(233), 36,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_DOLLAR,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [1618] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(214), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(216), 37,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_DOLLAR,
      anon_sym_DOT,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [1665] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(237), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(239), 36,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_DOLLAR,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [1711] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(241), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(243), 36,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_DOLLAR,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [1757] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(245), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(247), 36,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_DOLLAR,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [1803] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(249), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(251), 36,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_DOLLAR,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [1849] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(253), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(255), 36,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_DOLLAR,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [1895] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(257), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(259), 36,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_DOLLAR,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [1941] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(261), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(263), 36,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_DOLLAR,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [1987] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(265), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(267), 36,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_DOLLAR,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [2033] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(269), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(271), 36,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_DOLLAR,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [2079] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(273), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(275), 36,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_DOLLAR,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [2125] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(277), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(279), 36,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_DOLLAR,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [2171] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(281), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(283), 36,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_DOLLAR,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [2217] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(285), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(287), 36,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_number_literal,
      sym_word,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
      anon_sym_BQUOTE,
      anon_sym_DOLLAR,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
      anon_sym_DOLLAR_LPAREN,
      sym_identifier,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [2263] = 19,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_export,
    ACTIONS(9), 1,
      anon_sym_def,
    ACTIONS(11), 1,
      anon_sym_alias,
    ACTIONS(13), 1,
      anon_sym_EQ,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(21), 1,
      sym_number_literal,
    ACTIONS(23), 1,
      anon_sym_DOLLAR,
    ACTIONS(25), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(29), 1,
      anon_sym_LBRACE,
    ACTIONS(289), 1,
      sym_identifier,
    ACTIONS(291), 1,
      anon_sym_RBRACE,
    STATE(49), 1,
      aux_sym__statements_repeat1,
    STATE(197), 1,
      aux_sym_record_or_block_repeat1,
    STATE(273), 1,
      sym__statements,
    STATE(124), 6,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_math_mode,
    STATE(71), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2333] = 19,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_export,
    ACTIONS(9), 1,
      anon_sym_def,
    ACTIONS(11), 1,
      anon_sym_alias,
    ACTIONS(13), 1,
      anon_sym_EQ,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(21), 1,
      sym_number_literal,
    ACTIONS(23), 1,
      anon_sym_DOLLAR,
    ACTIONS(25), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(29), 1,
      anon_sym_LBRACE,
    ACTIONS(289), 1,
      sym_identifier,
    ACTIONS(293), 1,
      anon_sym_RBRACE,
    STATE(49), 1,
      aux_sym__statements_repeat1,
    STATE(212), 1,
      aux_sym_record_or_block_repeat1,
    STATE(240), 1,
      sym__statements,
    STATE(124), 6,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_math_mode,
    STATE(71), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2403] = 19,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_export,
    ACTIONS(9), 1,
      anon_sym_def,
    ACTIONS(11), 1,
      anon_sym_alias,
    ACTIONS(13), 1,
      anon_sym_EQ,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(21), 1,
      sym_number_literal,
    ACTIONS(23), 1,
      anon_sym_DOLLAR,
    ACTIONS(25), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(29), 1,
      anon_sym_LBRACE,
    ACTIONS(289), 1,
      sym_identifier,
    ACTIONS(295), 1,
      anon_sym_RBRACE,
    STATE(49), 1,
      aux_sym__statements_repeat1,
    STATE(204), 1,
      aux_sym_record_or_block_repeat1,
    STATE(242), 1,
      sym__statements,
    STATE(124), 6,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_math_mode,
    STATE(71), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2473] = 19,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_export,
    ACTIONS(9), 1,
      anon_sym_def,
    ACTIONS(11), 1,
      anon_sym_alias,
    ACTIONS(13), 1,
      anon_sym_EQ,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(21), 1,
      sym_number_literal,
    ACTIONS(23), 1,
      anon_sym_DOLLAR,
    ACTIONS(25), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(29), 1,
      anon_sym_LBRACE,
    ACTIONS(289), 1,
      sym_identifier,
    ACTIONS(297), 1,
      anon_sym_RBRACE,
    STATE(49), 1,
      aux_sym__statements_repeat1,
    STATE(211), 1,
      aux_sym_record_or_block_repeat1,
    STATE(259), 1,
      sym__statements,
    STATE(124), 6,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_math_mode,
    STATE(71), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2543] = 19,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_export,
    ACTIONS(9), 1,
      anon_sym_def,
    ACTIONS(11), 1,
      anon_sym_alias,
    ACTIONS(13), 1,
      anon_sym_EQ,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(21), 1,
      sym_number_literal,
    ACTIONS(23), 1,
      anon_sym_DOLLAR,
    ACTIONS(25), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(29), 1,
      anon_sym_LBRACE,
    ACTIONS(289), 1,
      sym_identifier,
    ACTIONS(299), 1,
      anon_sym_RBRACE,
    STATE(49), 1,
      aux_sym__statements_repeat1,
    STATE(209), 1,
      aux_sym_record_or_block_repeat1,
    STATE(258), 1,
      sym__statements,
    STATE(124), 6,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_math_mode,
    STATE(71), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2613] = 18,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_export,
    ACTIONS(9), 1,
      anon_sym_def,
    ACTIONS(11), 1,
      anon_sym_alias,
    ACTIONS(13), 1,
      anon_sym_EQ,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(21), 1,
      sym_number_literal,
    ACTIONS(23), 1,
      anon_sym_DOLLAR,
    ACTIONS(25), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(27), 1,
      sym_identifier,
    ACTIONS(29), 1,
      anon_sym_LBRACE,
    ACTIONS(301), 1,
      anon_sym_RBRACE,
    STATE(49), 1,
      aux_sym__statements_repeat1,
    STATE(279), 1,
      sym__statements,
    STATE(124), 6,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_math_mode,
    STATE(71), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2680] = 17,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_export,
    ACTIONS(9), 1,
      anon_sym_def,
    ACTIONS(11), 1,
      anon_sym_alias,
    ACTIONS(13), 1,
      anon_sym_EQ,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(21), 1,
      sym_number_literal,
    ACTIONS(23), 1,
      anon_sym_DOLLAR,
    ACTIONS(25), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(27), 1,
      sym_identifier,
    ACTIONS(29), 1,
      anon_sym_LBRACE,
    STATE(49), 1,
      aux_sym__statements_repeat1,
    STATE(241), 1,
      sym__statements,
    STATE(124), 6,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_math_mode,
    STATE(71), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2744] = 17,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_export,
    ACTIONS(9), 1,
      anon_sym_def,
    ACTIONS(11), 1,
      anon_sym_alias,
    ACTIONS(13), 1,
      anon_sym_EQ,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(21), 1,
      sym_number_literal,
    ACTIONS(23), 1,
      anon_sym_DOLLAR,
    ACTIONS(25), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(27), 1,
      sym_identifier,
    ACTIONS(29), 1,
      anon_sym_LBRACE,
    STATE(49), 1,
      aux_sym__statements_repeat1,
    STATE(230), 1,
      sym__statements,
    STATE(124), 6,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_math_mode,
    STATE(71), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2808] = 17,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_export,
    ACTIONS(9), 1,
      anon_sym_def,
    ACTIONS(11), 1,
      anon_sym_alias,
    ACTIONS(13), 1,
      anon_sym_EQ,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(21), 1,
      sym_number_literal,
    ACTIONS(23), 1,
      anon_sym_DOLLAR,
    ACTIONS(25), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(27), 1,
      sym_identifier,
    ACTIONS(29), 1,
      anon_sym_LBRACE,
    STATE(49), 1,
      aux_sym__statements_repeat1,
    STATE(257), 1,
      sym__statements,
    STATE(124), 6,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_math_mode,
    STATE(71), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2872] = 17,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_export,
    ACTIONS(9), 1,
      anon_sym_def,
    ACTIONS(11), 1,
      anon_sym_alias,
    ACTIONS(13), 1,
      anon_sym_EQ,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(21), 1,
      sym_number_literal,
    ACTIONS(23), 1,
      anon_sym_DOLLAR,
    ACTIONS(25), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(27), 1,
      sym_identifier,
    ACTIONS(29), 1,
      anon_sym_LBRACE,
    STATE(49), 1,
      aux_sym__statements_repeat1,
    STATE(272), 1,
      sym__statements,
    STATE(124), 6,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_math_mode,
    STATE(71), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [2936] = 17,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_export,
    ACTIONS(9), 1,
      anon_sym_def,
    ACTIONS(11), 1,
      anon_sym_alias,
    ACTIONS(13), 1,
      anon_sym_EQ,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(21), 1,
      sym_number_literal,
    ACTIONS(23), 1,
      anon_sym_DOLLAR,
    ACTIONS(25), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(27), 1,
      sym_identifier,
    ACTIONS(29), 1,
      anon_sym_LBRACE,
    STATE(49), 1,
      aux_sym__statements_repeat1,
    STATE(239), 1,
      sym__statements,
    STATE(124), 6,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_math_mode,
    STATE(71), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [3000] = 16,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(303), 1,
      anon_sym_export,
    ACTIONS(306), 1,
      anon_sym_def,
    ACTIONS(309), 1,
      anon_sym_alias,
    ACTIONS(312), 1,
      anon_sym_EQ,
    ACTIONS(315), 1,
      anon_sym_LBRACK,
    ACTIONS(318), 1,
      anon_sym_LPAREN,
    ACTIONS(321), 1,
      anon_sym_let,
    ACTIONS(324), 1,
      sym_number_literal,
    ACTIONS(327), 1,
      anon_sym_DOLLAR,
    ACTIONS(330), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(333), 1,
      sym_identifier,
    ACTIONS(336), 1,
      anon_sym_LBRACE,
    STATE(48), 1,
      aux_sym__statements_repeat1,
    STATE(166), 6,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_math_mode,
    STATE(71), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [3061] = 16,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_export,
    ACTIONS(9), 1,
      anon_sym_def,
    ACTIONS(11), 1,
      anon_sym_alias,
    ACTIONS(13), 1,
      anon_sym_EQ,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(21), 1,
      sym_number_literal,
    ACTIONS(23), 1,
      anon_sym_DOLLAR,
    ACTIONS(25), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(27), 1,
      sym_identifier,
    ACTIONS(29), 1,
      anon_sym_LBRACE,
    STATE(48), 1,
      aux_sym__statements_repeat1,
    STATE(125), 6,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_math_mode,
    STATE(71), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [3122] = 5,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(339), 1,
      anon_sym_DOT,
    STATE(53), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(227), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(229), 22,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [3160] = 15,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_export,
    ACTIONS(9), 1,
      anon_sym_def,
    ACTIONS(11), 1,
      anon_sym_alias,
    ACTIONS(13), 1,
      anon_sym_EQ,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(21), 1,
      sym_number_literal,
    ACTIONS(23), 1,
      anon_sym_DOLLAR,
    ACTIONS(25), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(27), 1,
      sym_identifier,
    ACTIONS(29), 1,
      anon_sym_LBRACE,
    STATE(134), 6,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_math_mode,
    STATE(71), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [3218] = 5,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(341), 1,
      anon_sym_DOT,
    STATE(52), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(214), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(216), 22,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [3256] = 5,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(339), 1,
      anon_sym_DOT,
    STATE(52), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(221), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(223), 22,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [3294] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(214), 3,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_DOT,
    ACTIONS(216), 22,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [3327] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(344), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(346), 22,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [3359] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(281), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(283), 22,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [3391] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(261), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(263), 22,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [3423] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(249), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(251), 22,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [3455] = 10,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(356), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(358), 1,
      anon_sym_AMP_AMP,
    ACTIONS(348), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(352), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(364), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(350), 4,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
    ACTIONS(354), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(360), 4,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
    ACTIONS(362), 4,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [3501] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(237), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(239), 22,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [3533] = 10,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(356), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(358), 1,
      anon_sym_AMP_AMP,
    ACTIONS(352), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(364), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(366), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(354), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(360), 4,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
    ACTIONS(362), 4,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
    ACTIONS(368), 4,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [3579] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(245), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(247), 22,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [3611] = 5,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(344), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(352), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(354), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(346), 16,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [3647] = 6,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(344), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(352), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(364), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(354), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(346), 14,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [3685] = 7,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(344), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(352), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(364), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(354), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(362), 4,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
    ACTIONS(346), 10,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
  [3725] = 8,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(344), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(352), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(364), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(354), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(360), 4,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
    ACTIONS(362), 4,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
    ACTIONS(346), 6,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
  [3767] = 9,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(358), 1,
      anon_sym_AMP_AMP,
    ACTIONS(344), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(352), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(364), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(354), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(360), 4,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
    ACTIONS(362), 4,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
    ACTIONS(346), 5,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_PIPE_PIPE,
  [3811] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(257), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(259), 22,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [3843] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(265), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(267), 22,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [3875] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(277), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(279), 22,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [3907] = 10,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(356), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(358), 1,
      anon_sym_AMP_AMP,
    ACTIONS(352), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(364), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(370), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(354), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(360), 4,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
    ACTIONS(362), 4,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
    ACTIONS(372), 4,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [3953] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(374), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(376), 22,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [3985] = 4,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(344), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(354), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(346), 18,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [4019] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(378), 1,
      anon_sym_DOT,
    STATE(74), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(216), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(214), 19,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [4054] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(381), 1,
      anon_sym_DOT,
    STATE(74), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(223), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(221), 19,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [4089] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(381), 1,
      anon_sym_DOT,
    STATE(75), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(229), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(227), 19,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [4124] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(267), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(265), 20,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [4154] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(283), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(281), 20,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [4184] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(216), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(214), 20,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_DOT,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [4214] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(263), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(261), 20,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [4244] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(239), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(237), 19,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [4273] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(279), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(277), 19,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [4302] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(251), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(249), 19,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [4331] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(259), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(257), 19,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [4360] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(247), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(245), 19,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [4389] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(383), 1,
      anon_sym_RPAREN,
    ACTIONS(389), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(391), 1,
      anon_sym_AMP_AMP,
    ACTIONS(385), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(395), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(397), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(399), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(387), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(393), 4,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
  [4430] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(376), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(374), 17,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [4457] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(346), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(387), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(344), 13,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [4486] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(346), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(344), 17,
      anon_sym_RPAREN,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [4513] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(391), 1,
      anon_sym_AMP_AMP,
    ACTIONS(344), 2,
      anon_sym_RPAREN,
      anon_sym_PIPE_PIPE,
    ACTIONS(385), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(395), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(397), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(399), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(387), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(393), 4,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
  [4552] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(385), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(395), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(397), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(399), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(344), 3,
      anon_sym_RPAREN,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
    ACTIONS(387), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(393), 4,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
  [4589] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(385), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(395), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(397), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(399), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(387), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(344), 7,
      anon_sym_RPAREN,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
  [4624] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(389), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(391), 1,
      anon_sym_AMP_AMP,
    ACTIONS(401), 1,
      anon_sym_RPAREN,
    ACTIONS(385), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(395), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(397), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(399), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(387), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(393), 4,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
  [4665] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(346), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(385), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(399), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(387), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(344), 9,
      anon_sym_RPAREN,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
  [4698] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(346), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(385), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(387), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(344), 11,
      anon_sym_RPAREN,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
  [4729] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(23), 1,
      anon_sym_DOLLAR,
    ACTIONS(25), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(29), 1,
      anon_sym_LBRACE,
    ACTIONS(403), 1,
      sym_number_literal,
    ACTIONS(405), 1,
      anon_sym_DQUOTE,
    ACTIONS(407), 1,
      anon_sym_SQUOTE,
    ACTIONS(409), 1,
      anon_sym_BQUOTE,
    STATE(131), 1,
      sym_string,
    STATE(59), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [4773] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(411), 3,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
    ACTIONS(413), 6,
      anon_sym_export,
      anon_sym_def,
      anon_sym_alias,
      anon_sym_let,
      anon_sym_DOLLAR,
      sym_identifier,
    ACTIONS(415), 6,
      anon_sym_EQ,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      sym_number_literal,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_LBRACE,
  [4798] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(417), 3,
      ts_builtin_sym_end,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
    ACTIONS(413), 6,
      anon_sym_export,
      anon_sym_def,
      anon_sym_alias,
      anon_sym_let,
      anon_sym_DOLLAR,
      sym_identifier,
    ACTIONS(415), 6,
      anon_sym_EQ,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      sym_number_literal,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_LBRACE,
  [4823] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(186), 1,
      anon_sym_DOLLAR,
    ACTIONS(190), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(419), 1,
      anon_sym_LBRACK,
    ACTIONS(421), 1,
      anon_sym_LPAREN,
    ACTIONS(423), 1,
      sym_number_literal,
    ACTIONS(425), 1,
      anon_sym_LBRACE,
    STATE(90), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [4855] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(186), 1,
      anon_sym_DOLLAR,
    ACTIONS(190), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(419), 1,
      anon_sym_LBRACK,
    ACTIONS(421), 1,
      anon_sym_LPAREN,
    ACTIONS(425), 1,
      anon_sym_LBRACE,
    ACTIONS(427), 1,
      sym_number_literal,
    STATE(89), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [4887] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(186), 1,
      anon_sym_DOLLAR,
    ACTIONS(190), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(419), 1,
      anon_sym_LBRACK,
    ACTIONS(421), 1,
      anon_sym_LPAREN,
    ACTIONS(425), 1,
      anon_sym_LBRACE,
    ACTIONS(429), 1,
      sym_number_literal,
    STATE(88), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [4919] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(186), 1,
      anon_sym_DOLLAR,
    ACTIONS(190), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(419), 1,
      anon_sym_LBRACK,
    ACTIONS(421), 1,
      anon_sym_LPAREN,
    ACTIONS(425), 1,
      anon_sym_LBRACE,
    ACTIONS(431), 1,
      sym_number_literal,
    STATE(95), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [4951] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(186), 1,
      anon_sym_DOLLAR,
    ACTIONS(190), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(419), 1,
      anon_sym_LBRACK,
    ACTIONS(421), 1,
      anon_sym_LPAREN,
    ACTIONS(425), 1,
      anon_sym_LBRACE,
    ACTIONS(433), 1,
      sym_number_literal,
    STATE(94), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [4983] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(186), 1,
      anon_sym_DOLLAR,
    ACTIONS(190), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(419), 1,
      anon_sym_LBRACK,
    ACTIONS(421), 1,
      anon_sym_LPAREN,
    ACTIONS(425), 1,
      anon_sym_LBRACE,
    ACTIONS(435), 1,
      sym_number_literal,
    STATE(92), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [5015] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(186), 1,
      anon_sym_DOLLAR,
    ACTIONS(190), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(419), 1,
      anon_sym_LBRACK,
    ACTIONS(421), 1,
      anon_sym_LPAREN,
    ACTIONS(425), 1,
      anon_sym_LBRACE,
    ACTIONS(437), 1,
      sym_number_literal,
    STATE(91), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [5047] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(23), 1,
      anon_sym_DOLLAR,
    ACTIONS(25), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(29), 1,
      anon_sym_LBRACE,
    ACTIONS(439), 1,
      sym_number_literal,
    STATE(63), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [5079] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(186), 1,
      anon_sym_DOLLAR,
    ACTIONS(190), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(419), 1,
      anon_sym_LBRACK,
    ACTIONS(421), 1,
      anon_sym_LPAREN,
    ACTIONS(425), 1,
      anon_sym_LBRACE,
    ACTIONS(441), 1,
      sym_number_literal,
    STATE(93), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [5111] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(23), 1,
      anon_sym_DOLLAR,
    ACTIONS(25), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(29), 1,
      anon_sym_LBRACE,
    ACTIONS(443), 1,
      sym_number_literal,
    STATE(64), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [5143] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(23), 1,
      anon_sym_DOLLAR,
    ACTIONS(25), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(29), 1,
      anon_sym_LBRACE,
    ACTIONS(445), 1,
      sym_number_literal,
    STATE(65), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [5175] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(186), 1,
      anon_sym_DOLLAR,
    ACTIONS(190), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(419), 1,
      anon_sym_LBRACK,
    ACTIONS(421), 1,
      anon_sym_LPAREN,
    ACTIONS(425), 1,
      anon_sym_LBRACE,
    ACTIONS(447), 1,
      sym_number_literal,
    STATE(86), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [5207] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(23), 1,
      anon_sym_DOLLAR,
    ACTIONS(25), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(29), 1,
      anon_sym_LBRACE,
    ACTIONS(449), 1,
      sym_number_literal,
    STATE(73), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [5239] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(23), 1,
      anon_sym_DOLLAR,
    ACTIONS(25), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(29), 1,
      anon_sym_LBRACE,
    ACTIONS(451), 1,
      sym_number_literal,
    STATE(61), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [5271] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(23), 1,
      anon_sym_DOLLAR,
    ACTIONS(25), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(29), 1,
      anon_sym_LBRACE,
    ACTIONS(453), 1,
      sym_number_literal,
    STATE(55), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [5303] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(23), 1,
      anon_sym_DOLLAR,
    ACTIONS(25), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(29), 1,
      anon_sym_LBRACE,
    ACTIONS(455), 1,
      sym_number_literal,
    STATE(67), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [5335] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(23), 1,
      anon_sym_DOLLAR,
    ACTIONS(25), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(29), 1,
      anon_sym_LBRACE,
    ACTIONS(457), 1,
      sym_number_literal,
    STATE(66), 8,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_record_or_block,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [5367] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(413), 6,
      anon_sym_export,
      anon_sym_def,
      anon_sym_alias,
      anon_sym_let,
      anon_sym_DOLLAR,
      sym_identifier,
    ACTIONS(415), 6,
      anon_sym_EQ,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      sym_number_literal,
      anon_sym_DOLLAR_LPAREN,
      anon_sym_LBRACE,
  [5387] = 3,
    ACTIONS(3), 1,
      sym_comment,
    STATE(138), 1,
      sym_type,
    ACTIONS(459), 10,
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
  [5406] = 3,
    ACTIONS(3), 1,
      sym_comment,
    STATE(139), 1,
      sym_type,
    ACTIONS(459), 10,
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
  [5425] = 3,
    ACTIONS(3), 1,
      sym_comment,
    STATE(144), 1,
      sym_type,
    ACTIONS(459), 10,
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
  [5444] = 3,
    ACTIONS(3), 1,
      sym_comment,
    STATE(141), 1,
      sym_type,
    ACTIONS(459), 10,
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
  [5463] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(461), 1,
      anon_sym_RBRACK,
    ACTIONS(463), 1,
      sym_flag_name,
    ACTIONS(465), 1,
      anon_sym_DOT_DOT_DOTrest,
    ACTIONS(467), 1,
      sym_identifier,
    STATE(122), 1,
      aux_sym_signature_repeat1,
    STATE(146), 3,
      sym_parameter,
      sym_flag,
      sym_rest,
  [5487] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(463), 1,
      sym_flag_name,
    ACTIONS(465), 1,
      anon_sym_DOT_DOT_DOTrest,
    ACTIONS(467), 1,
      sym_identifier,
    ACTIONS(469), 1,
      anon_sym_RBRACK,
    STATE(123), 1,
      aux_sym_signature_repeat1,
    STATE(146), 3,
      sym_parameter,
      sym_flag,
      sym_rest,
  [5511] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(471), 1,
      anon_sym_RBRACK,
    ACTIONS(473), 1,
      sym_flag_name,
    ACTIONS(476), 1,
      anon_sym_DOT_DOT_DOTrest,
    ACTIONS(479), 1,
      sym_identifier,
    STATE(123), 1,
      aux_sym_signature_repeat1,
    STATE(146), 3,
      sym_parameter,
      sym_flag,
      sym_rest,
  [5535] = 6,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(482), 1,
      ts_builtin_sym_end,
    ACTIONS(486), 1,
      anon_sym_LF,
    STATE(98), 1,
      sym__terminator,
    ACTIONS(484), 2,
      anon_sym_SEMI,
      anon_sym_PIPE,
    ACTIONS(488), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [5556] = 6,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(417), 1,
      ts_builtin_sym_end,
    ACTIONS(492), 1,
      anon_sym_LF,
    STATE(97), 1,
      sym__terminator,
    ACTIONS(490), 2,
      anon_sym_SEMI,
      anon_sym_PIPE,
    ACTIONS(494), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [5577] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(498), 1,
      anon_sym_COLON,
    ACTIONS(500), 1,
      anon_sym_LPAREN,
    ACTIONS(496), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [5594] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(504), 1,
      anon_sym_COLON,
    ACTIONS(506), 1,
      anon_sym_QMARK,
    ACTIONS(502), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [5611] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(510), 1,
      anon_sym_COLON,
    ACTIONS(508), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [5625] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(514), 1,
      anon_sym_COLON,
    ACTIONS(512), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [5639] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(516), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(518), 4,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [5653] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(348), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(350), 4,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [5667] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(520), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(522), 4,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [5681] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(253), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(255), 4,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [5695] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(524), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(526), 4,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [5709] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(528), 6,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_QMARK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [5721] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(530), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(532), 4,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [5735] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(534), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(536), 4,
      anon_sym_SEMI,
      anon_sym_PIPE,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [5749] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(540), 1,
      anon_sym_QMARK,
    ACTIONS(538), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [5763] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(542), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [5774] = 6,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(116), 1,
      anon_sym_COMMA,
    ACTIONS(134), 1,
      anon_sym_,
    ACTIONS(544), 1,
      anon_sym_RBRACK,
    STATE(170), 1,
      aux_sym_array_repeat1,
    STATE(192), 1,
      aux_sym_column_header_repeat1,
  [5793] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(546), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [5804] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(548), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [5815] = 5,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(214), 1,
      anon_sym_,
    ACTIONS(550), 1,
      anon_sym_DOT,
    STATE(143), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(216), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5832] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(553), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [5843] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(555), 1,
      anon_sym_DOT_DOT,
    ACTIONS(231), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_identifier,
      anon_sym_RBRACE,
  [5856] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(557), 1,
      anon_sym_COMMA,
    ACTIONS(559), 4,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [5869] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(561), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [5880] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(563), 1,
      anon_sym_DQUOTE,
    ACTIONS(565), 1,
      anon_sym_SQUOTE,
    ACTIONS(567), 1,
      anon_sym_BQUOTE,
    ACTIONS(569), 1,
      sym_identifier,
    STATE(227), 1,
      sym_string,
  [5899] = 5,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(227), 1,
      anon_sym_,
    ACTIONS(571), 1,
      anon_sym_DOT,
    STATE(150), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(229), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5916] = 5,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(221), 1,
      anon_sym_,
    ACTIONS(571), 1,
      anon_sym_DOT,
    STATE(143), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(223), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [5933] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(253), 5,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_identifier,
      anon_sym_RBRACE,
  [5944] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(563), 1,
      anon_sym_DQUOTE,
    ACTIONS(565), 1,
      anon_sym_SQUOTE,
    ACTIONS(567), 1,
      anon_sym_BQUOTE,
    ACTIONS(573), 1,
      sym_identifier,
    STATE(225), 1,
      sym_string,
  [5963] = 5,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(134), 1,
      anon_sym_,
    ACTIONS(142), 1,
      anon_sym_COMMA,
    ACTIONS(575), 1,
      anon_sym_RBRACK,
    STATE(170), 1,
      aux_sym_array_repeat1,
  [5979] = 5,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(134), 1,
      anon_sym_,
    ACTIONS(142), 1,
      anon_sym_COMMA,
    ACTIONS(575), 1,
      anon_sym_RBRACK,
    STATE(156), 1,
      aux_sym_array_repeat1,
  [5995] = 5,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(134), 1,
      anon_sym_,
    ACTIONS(142), 1,
      anon_sym_COMMA,
    ACTIONS(577), 1,
      anon_sym_RBRACK,
    STATE(156), 1,
      aux_sym_array_repeat1,
  [6011] = 5,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(579), 1,
      anon_sym_COMMA,
    ACTIONS(582), 1,
      anon_sym_RBRACK,
    ACTIONS(584), 1,
      anon_sym_,
    STATE(156), 1,
      aux_sym_array_repeat1,
  [6027] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(587), 1,
      anon_sym_LBRACK,
    ACTIONS(589), 1,
      anon_sym_RBRACK,
    STATE(189), 2,
      sym_array,
      aux_sym_table_repeat1,
  [6041] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(587), 1,
      anon_sym_LBRACK,
    ACTIONS(591), 1,
      anon_sym_RBRACK,
    STATE(191), 2,
      sym_array,
      aux_sym_table_repeat1,
  [6055] = 5,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(134), 1,
      anon_sym_,
    ACTIONS(142), 1,
      anon_sym_COMMA,
    ACTIONS(593), 1,
      anon_sym_RBRACK,
    STATE(156), 1,
      aux_sym_array_repeat1,
  [6071] = 5,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(134), 1,
      anon_sym_,
    ACTIONS(142), 1,
      anon_sym_COMMA,
    ACTIONS(595), 1,
      anon_sym_RBRACK,
    STATE(156), 1,
      aux_sym_array_repeat1,
  [6087] = 5,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(134), 1,
      anon_sym_,
    ACTIONS(142), 1,
      anon_sym_COMMA,
    ACTIONS(597), 1,
      anon_sym_RBRACK,
    STATE(156), 1,
      aux_sym_array_repeat1,
  [6103] = 5,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(134), 1,
      anon_sym_,
    ACTIONS(142), 1,
      anon_sym_COMMA,
    ACTIONS(599), 1,
      anon_sym_RBRACK,
    STATE(177), 1,
      aux_sym_array_repeat1,
  [6119] = 5,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(134), 1,
      anon_sym_,
    ACTIONS(142), 1,
      anon_sym_COMMA,
    ACTIONS(577), 1,
      anon_sym_RBRACK,
    STATE(169), 1,
      aux_sym_array_repeat1,
  [6135] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(587), 1,
      anon_sym_LBRACK,
    ACTIONS(601), 1,
      anon_sym_RBRACK,
    STATE(175), 2,
      sym_array,
      aux_sym_table_repeat1,
  [6149] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(587), 1,
      anon_sym_LBRACK,
    ACTIONS(603), 1,
      anon_sym_RBRACK,
    STATE(164), 2,
      sym_array,
      aux_sym_table_repeat1,
  [6163] = 4,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(607), 1,
      anon_sym_LF,
    STATE(116), 1,
      sym__terminator,
    ACTIONS(605), 2,
      anon_sym_SEMI,
      anon_sym_PIPE,
  [6177] = 4,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(265), 1,
      anon_sym_,
    ACTIONS(609), 1,
      anon_sym_SEMI,
    ACTIONS(267), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6191] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(587), 1,
      anon_sym_LBRACK,
    ACTIONS(611), 1,
      anon_sym_RBRACK,
    STATE(175), 2,
      sym_array,
      aux_sym_table_repeat1,
  [6205] = 5,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(134), 1,
      anon_sym_,
    ACTIONS(142), 1,
      anon_sym_COMMA,
    ACTIONS(613), 1,
      anon_sym_RBRACK,
    STATE(156), 1,
      aux_sym_array_repeat1,
  [6221] = 5,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(134), 1,
      anon_sym_,
    ACTIONS(142), 1,
      anon_sym_COMMA,
    ACTIONS(615), 1,
      anon_sym_RBRACK,
    STATE(156), 1,
      aux_sym_array_repeat1,
  [6237] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(587), 1,
      anon_sym_LBRACK,
    ACTIONS(617), 1,
      anon_sym_RBRACK,
    STATE(168), 2,
      sym_array,
      aux_sym_table_repeat1,
  [6251] = 5,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(134), 1,
      anon_sym_,
    ACTIONS(142), 1,
      anon_sym_COMMA,
    ACTIONS(599), 1,
      anon_sym_RBRACK,
    STATE(156), 1,
      aux_sym_array_repeat1,
  [6267] = 5,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(134), 1,
      anon_sym_,
    ACTIONS(142), 1,
      anon_sym_COMMA,
    ACTIONS(597), 1,
      anon_sym_RBRACK,
    STATE(159), 1,
      aux_sym_array_repeat1,
  [6283] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(214), 2,
      anon_sym_DOT,
      anon_sym_,
    ACTIONS(216), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6295] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(619), 1,
      anon_sym_LBRACK,
    ACTIONS(622), 1,
      anon_sym_RBRACK,
    STATE(175), 2,
      sym_array,
      aux_sym_table_repeat1,
  [6309] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(624), 1,
      anon_sym_DOT,
    STATE(176), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(214), 2,
      sym_identifier,
      anon_sym_RBRACE,
  [6323] = 5,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(134), 1,
      anon_sym_,
    ACTIONS(142), 1,
      anon_sym_COMMA,
    ACTIONS(627), 1,
      anon_sym_RBRACK,
    STATE(156), 1,
      aux_sym_array_repeat1,
  [6339] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(629), 1,
      anon_sym_DOT,
    STATE(176), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(221), 2,
      sym_identifier,
      anon_sym_RBRACE,
  [6353] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(241), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_identifier,
      anon_sym_RBRACE,
  [6363] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(269), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_identifier,
      anon_sym_RBRACE,
  [6373] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(629), 1,
      anon_sym_DOT,
    STATE(178), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(227), 2,
      sym_identifier,
      anon_sym_RBRACE,
  [6387] = 4,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(231), 1,
      anon_sym_,
    ACTIONS(631), 1,
      anon_sym_DOT_DOT,
    ACTIONS(233), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6401] = 4,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(281), 1,
      anon_sym_,
    ACTIONS(633), 1,
      anon_sym_SEMI,
    ACTIONS(283), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6415] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(587), 1,
      anon_sym_LBRACK,
    ACTIONS(635), 1,
      anon_sym_RBRACK,
    STATE(185), 2,
      sym_array,
      aux_sym_table_repeat1,
  [6429] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(587), 1,
      anon_sym_LBRACK,
    ACTIONS(637), 1,
      anon_sym_RBRACK,
    STATE(175), 2,
      sym_array,
      aux_sym_table_repeat1,
  [6443] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(471), 4,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [6453] = 5,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(134), 1,
      anon_sym_,
    ACTIONS(142), 1,
      anon_sym_COMMA,
    ACTIONS(639), 1,
      anon_sym_RBRACK,
    STATE(160), 1,
      aux_sym_array_repeat1,
  [6469] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(273), 4,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_identifier,
      anon_sym_RBRACE,
  [6479] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(587), 1,
      anon_sym_LBRACK,
    ACTIONS(641), 1,
      anon_sym_RBRACK,
    STATE(175), 2,
      sym_array,
      aux_sym_table_repeat1,
  [6493] = 5,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(134), 1,
      anon_sym_,
    ACTIONS(142), 1,
      anon_sym_COMMA,
    ACTIONS(639), 1,
      anon_sym_RBRACK,
    STATE(156), 1,
      aux_sym_array_repeat1,
  [6509] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(587), 1,
      anon_sym_LBRACK,
    ACTIONS(643), 1,
      anon_sym_RBRACK,
    STATE(175), 2,
      sym_array,
      aux_sym_table_repeat1,
  [6523] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(645), 1,
      anon_sym_COMMA,
    ACTIONS(647), 1,
      anon_sym_RBRACK,
    STATE(198), 1,
      aux_sym_column_header_repeat1,
  [6536] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(261), 1,
      anon_sym_,
    ACTIONS(263), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6547] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(265), 1,
      anon_sym_,
    ACTIONS(267), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6558] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(277), 1,
      anon_sym_,
    ACTIONS(279), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6569] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(649), 1,
      sym_identifier,
    ACTIONS(652), 1,
      anon_sym_RBRACE,
    STATE(196), 1,
      aux_sym_record_or_block_repeat1,
  [6582] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(654), 1,
      sym_identifier,
    ACTIONS(656), 1,
      anon_sym_RBRACE,
    STATE(196), 1,
      aux_sym_record_or_block_repeat1,
  [6595] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(658), 1,
      anon_sym_COMMA,
    ACTIONS(661), 1,
      anon_sym_RBRACK,
    STATE(198), 1,
      aux_sym_column_header_repeat1,
  [6608] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(273), 1,
      anon_sym_,
    ACTIONS(275), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6619] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(281), 1,
      anon_sym_,
    ACTIONS(283), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6630] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(269), 1,
      anon_sym_,
    ACTIONS(271), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6641] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(241), 1,
      anon_sym_,
    ACTIONS(243), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6652] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(245), 1,
      anon_sym_,
    ACTIONS(247), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6663] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(654), 1,
      sym_identifier,
    ACTIONS(663), 1,
      anon_sym_RBRACE,
    STATE(196), 1,
      aux_sym_record_or_block_repeat1,
  [6676] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(237), 1,
      anon_sym_,
    ACTIONS(239), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6687] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(665), 1,
      anon_sym_,
    ACTIONS(582), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6698] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(665), 1,
      anon_sym_,
    ACTIONS(667), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6709] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(645), 1,
      anon_sym_COMMA,
    ACTIONS(670), 1,
      anon_sym_RBRACK,
    STATE(198), 1,
      aux_sym_column_header_repeat1,
  [6722] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(654), 1,
      sym_identifier,
    ACTIONS(672), 1,
      anon_sym_RBRACE,
    STATE(196), 1,
      aux_sym_record_or_block_repeat1,
  [6735] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(253), 1,
      anon_sym_,
    ACTIONS(255), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6746] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(654), 1,
      sym_identifier,
    ACTIONS(674), 1,
      anon_sym_RBRACE,
    STATE(196), 1,
      aux_sym_record_or_block_repeat1,
  [6759] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(654), 1,
      sym_identifier,
    ACTIONS(676), 1,
      anon_sym_RBRACE,
    STATE(196), 1,
      aux_sym_record_or_block_repeat1,
  [6772] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(257), 1,
      anon_sym_,
    ACTIONS(259), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6783] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(214), 3,
      anon_sym_DOT,
      sym_identifier,
      anon_sym_RBRACE,
  [6792] = 3,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(249), 1,
      anon_sym_,
    ACTIONS(251), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6803] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(249), 2,
      sym_identifier,
      anon_sym_RBRACE,
  [6811] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(678), 1,
      anon_sym_LBRACE,
    STATE(136), 1,
      sym_block,
  [6821] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(257), 2,
      sym_identifier,
      anon_sym_RBRACE,
  [6829] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(261), 2,
      sym_identifier,
      anon_sym_RBRACE,
  [6837] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(237), 2,
      sym_identifier,
      anon_sym_RBRACE,
  [6845] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(245), 2,
      sym_identifier,
      anon_sym_RBRACE,
  [6853] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(281), 2,
      sym_identifier,
      anon_sym_RBRACE,
  [6861] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(277), 2,
      sym_identifier,
      anon_sym_RBRACE,
  [6869] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(678), 1,
      anon_sym_LBRACE,
    STATE(132), 1,
      sym_block,
  [6879] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(680), 1,
      anon_sym_LBRACK,
    STATE(224), 1,
      sym_signature,
  [6889] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(265), 2,
      sym_identifier,
      anon_sym_RBRACE,
  [6897] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(680), 1,
      anon_sym_LBRACK,
    STATE(217), 1,
      sym_signature,
  [6907] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(661), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6915] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(682), 2,
      sym_identifier,
      anon_sym_RBRACE,
  [6923] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(684), 1,
      anon_sym_RPAREN,
  [6930] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(686), 1,
      sym_number_literal,
  [6937] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(688), 1,
      sym_identifier,
  [6944] = 2,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(690), 1,
      aux_sym_string_token2,
  [6951] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(692), 1,
      sym_identifier,
  [6958] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(694), 1,
      anon_sym_EQ,
  [6965] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(696), 1,
      anon_sym_SEMI,
  [6972] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(698), 1,
      sym_identifier,
  [6979] = 2,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(700), 1,
      aux_sym_string_token1,
  [6986] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(702), 1,
      anon_sym_RPAREN,
  [6993] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(676), 1,
      anon_sym_RBRACE,
  [7000] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(704), 1,
      anon_sym_RPAREN,
  [7007] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(663), 1,
      anon_sym_RBRACE,
  [7014] = 2,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(706), 1,
      aux_sym_string_token3,
  [7021] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(708), 1,
      anon_sym_DQUOTE,
  [7028] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(708), 1,
      anon_sym_SQUOTE,
  [7035] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(708), 1,
      anon_sym_BQUOTE,
  [7042] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(710), 1,
      sym_number_literal,
  [7049] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(712), 1,
      anon_sym_DQUOTE,
  [7056] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(712), 1,
      anon_sym_SQUOTE,
  [7063] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(714), 1,
      sym_identifier,
  [7070] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(712), 1,
      anon_sym_BQUOTE,
  [7077] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(716), 1,
      ts_builtin_sym_end,
  [7084] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(718), 1,
      sym_identifier,
  [7091] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(720), 1,
      ts_builtin_sym_end,
  [7098] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(722), 1,
      anon_sym_LBRACE,
  [7105] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(724), 1,
      anon_sym_EQ,
  [7112] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(726), 1,
      anon_sym_RPAREN,
  [7119] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(672), 1,
      anon_sym_RBRACE,
  [7126] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(674), 1,
      anon_sym_RBRACE,
  [7133] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(728), 1,
      anon_sym_DQUOTE,
  [7140] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(728), 1,
      anon_sym_SQUOTE,
  [7147] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(728), 1,
      anon_sym_BQUOTE,
  [7154] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(730), 1,
      anon_sym_DQUOTE,
  [7161] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(730), 1,
      anon_sym_SQUOTE,
  [7168] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(732), 1,
      sym_identifier,
  [7175] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(730), 1,
      anon_sym_BQUOTE,
  [7182] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(734), 1,
      sym_identifier,
  [7189] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(736), 1,
      sym_identifier,
  [7196] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(738), 1,
      sym_identifier,
  [7203] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(740), 1,
      anon_sym_def,
  [7210] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(742), 1,
      sym_number_literal,
  [7217] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(744), 1,
      anon_sym_RPAREN,
  [7224] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(656), 1,
      anon_sym_RBRACE,
  [7231] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(746), 1,
      sym_identifier,
  [7238] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(748), 1,
      anon_sym_COLON,
  [7245] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(750), 1,
      anon_sym_RPAREN,
  [7252] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(752), 1,
      sym_identifier,
  [7259] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(754), 1,
      anon_sym_SEMI,
  [7266] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(756), 1,
      anon_sym_RBRACE,
  [7273] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(758), 1,
      anon_sym_LBRACE,
  [7280] = 2,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(760), 1,
      aux_sym_string_token1,
  [7287] = 2,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(762), 1,
      aux_sym_string_token2,
  [7294] = 2,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(764), 1,
      aux_sym_string_token3,
  [7301] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(766), 1,
      anon_sym_SEMI,
  [7308] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(768), 1,
      sym_flag_shorthand_name,
  [7315] = 2,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(770), 1,
      aux_sym_string_token1,
  [7322] = 2,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(772), 1,
      aux_sym_string_token2,
  [7329] = 2,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(774), 1,
      aux_sym_string_token3,
  [7336] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(776), 1,
      anon_sym_SEMI,
  [7343] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(778), 1,
      sym_identifier,
  [7350] = 2,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(780), 1,
      aux_sym_string_token1,
  [7357] = 2,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(782), 1,
      aux_sym_string_token2,
  [7364] = 2,
    ACTIONS(57), 1,
      sym_comment,
    ACTIONS(784), 1,
      aux_sym_string_token3,
  [7371] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(786), 1,
      anon_sym_SEMI,
  [7378] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(788), 1,
      anon_sym_SEMI,
  [7385] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(790), 1,
      anon_sym_SEMI,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 87,
  [SMALL_STATE(4)] = 171,
  [SMALL_STATE(5)] = 255,
  [SMALL_STATE(6)] = 339,
  [SMALL_STATE(7)] = 423,
  [SMALL_STATE(8)] = 511,
  [SMALL_STATE(9)] = 600,
  [SMALL_STATE(10)] = 686,
  [SMALL_STATE(11)] = 772,
  [SMALL_STATE(12)] = 858,
  [SMALL_STATE(13)] = 944,
  [SMALL_STATE(14)] = 1030,
  [SMALL_STATE(15)] = 1113,
  [SMALL_STATE(16)] = 1188,
  [SMALL_STATE(17)] = 1263,
  [SMALL_STATE(18)] = 1338,
  [SMALL_STATE(19)] = 1413,
  [SMALL_STATE(20)] = 1465,
  [SMALL_STATE(21)] = 1517,
  [SMALL_STATE(22)] = 1569,
  [SMALL_STATE(23)] = 1618,
  [SMALL_STATE(24)] = 1665,
  [SMALL_STATE(25)] = 1711,
  [SMALL_STATE(26)] = 1757,
  [SMALL_STATE(27)] = 1803,
  [SMALL_STATE(28)] = 1849,
  [SMALL_STATE(29)] = 1895,
  [SMALL_STATE(30)] = 1941,
  [SMALL_STATE(31)] = 1987,
  [SMALL_STATE(32)] = 2033,
  [SMALL_STATE(33)] = 2079,
  [SMALL_STATE(34)] = 2125,
  [SMALL_STATE(35)] = 2171,
  [SMALL_STATE(36)] = 2217,
  [SMALL_STATE(37)] = 2263,
  [SMALL_STATE(38)] = 2333,
  [SMALL_STATE(39)] = 2403,
  [SMALL_STATE(40)] = 2473,
  [SMALL_STATE(41)] = 2543,
  [SMALL_STATE(42)] = 2613,
  [SMALL_STATE(43)] = 2680,
  [SMALL_STATE(44)] = 2744,
  [SMALL_STATE(45)] = 2808,
  [SMALL_STATE(46)] = 2872,
  [SMALL_STATE(47)] = 2936,
  [SMALL_STATE(48)] = 3000,
  [SMALL_STATE(49)] = 3061,
  [SMALL_STATE(50)] = 3122,
  [SMALL_STATE(51)] = 3160,
  [SMALL_STATE(52)] = 3218,
  [SMALL_STATE(53)] = 3256,
  [SMALL_STATE(54)] = 3294,
  [SMALL_STATE(55)] = 3327,
  [SMALL_STATE(56)] = 3359,
  [SMALL_STATE(57)] = 3391,
  [SMALL_STATE(58)] = 3423,
  [SMALL_STATE(59)] = 3455,
  [SMALL_STATE(60)] = 3501,
  [SMALL_STATE(61)] = 3533,
  [SMALL_STATE(62)] = 3579,
  [SMALL_STATE(63)] = 3611,
  [SMALL_STATE(64)] = 3647,
  [SMALL_STATE(65)] = 3685,
  [SMALL_STATE(66)] = 3725,
  [SMALL_STATE(67)] = 3767,
  [SMALL_STATE(68)] = 3811,
  [SMALL_STATE(69)] = 3843,
  [SMALL_STATE(70)] = 3875,
  [SMALL_STATE(71)] = 3907,
  [SMALL_STATE(72)] = 3953,
  [SMALL_STATE(73)] = 3985,
  [SMALL_STATE(74)] = 4019,
  [SMALL_STATE(75)] = 4054,
  [SMALL_STATE(76)] = 4089,
  [SMALL_STATE(77)] = 4124,
  [SMALL_STATE(78)] = 4154,
  [SMALL_STATE(79)] = 4184,
  [SMALL_STATE(80)] = 4214,
  [SMALL_STATE(81)] = 4244,
  [SMALL_STATE(82)] = 4273,
  [SMALL_STATE(83)] = 4302,
  [SMALL_STATE(84)] = 4331,
  [SMALL_STATE(85)] = 4360,
  [SMALL_STATE(86)] = 4389,
  [SMALL_STATE(87)] = 4430,
  [SMALL_STATE(88)] = 4457,
  [SMALL_STATE(89)] = 4486,
  [SMALL_STATE(90)] = 4513,
  [SMALL_STATE(91)] = 4552,
  [SMALL_STATE(92)] = 4589,
  [SMALL_STATE(93)] = 4624,
  [SMALL_STATE(94)] = 4665,
  [SMALL_STATE(95)] = 4698,
  [SMALL_STATE(96)] = 4729,
  [SMALL_STATE(97)] = 4773,
  [SMALL_STATE(98)] = 4798,
  [SMALL_STATE(99)] = 4823,
  [SMALL_STATE(100)] = 4855,
  [SMALL_STATE(101)] = 4887,
  [SMALL_STATE(102)] = 4919,
  [SMALL_STATE(103)] = 4951,
  [SMALL_STATE(104)] = 4983,
  [SMALL_STATE(105)] = 5015,
  [SMALL_STATE(106)] = 5047,
  [SMALL_STATE(107)] = 5079,
  [SMALL_STATE(108)] = 5111,
  [SMALL_STATE(109)] = 5143,
  [SMALL_STATE(110)] = 5175,
  [SMALL_STATE(111)] = 5207,
  [SMALL_STATE(112)] = 5239,
  [SMALL_STATE(113)] = 5271,
  [SMALL_STATE(114)] = 5303,
  [SMALL_STATE(115)] = 5335,
  [SMALL_STATE(116)] = 5367,
  [SMALL_STATE(117)] = 5387,
  [SMALL_STATE(118)] = 5406,
  [SMALL_STATE(119)] = 5425,
  [SMALL_STATE(120)] = 5444,
  [SMALL_STATE(121)] = 5463,
  [SMALL_STATE(122)] = 5487,
  [SMALL_STATE(123)] = 5511,
  [SMALL_STATE(124)] = 5535,
  [SMALL_STATE(125)] = 5556,
  [SMALL_STATE(126)] = 5577,
  [SMALL_STATE(127)] = 5594,
  [SMALL_STATE(128)] = 5611,
  [SMALL_STATE(129)] = 5625,
  [SMALL_STATE(130)] = 5639,
  [SMALL_STATE(131)] = 5653,
  [SMALL_STATE(132)] = 5667,
  [SMALL_STATE(133)] = 5681,
  [SMALL_STATE(134)] = 5695,
  [SMALL_STATE(135)] = 5709,
  [SMALL_STATE(136)] = 5721,
  [SMALL_STATE(137)] = 5735,
  [SMALL_STATE(138)] = 5749,
  [SMALL_STATE(139)] = 5763,
  [SMALL_STATE(140)] = 5774,
  [SMALL_STATE(141)] = 5793,
  [SMALL_STATE(142)] = 5804,
  [SMALL_STATE(143)] = 5815,
  [SMALL_STATE(144)] = 5832,
  [SMALL_STATE(145)] = 5843,
  [SMALL_STATE(146)] = 5856,
  [SMALL_STATE(147)] = 5869,
  [SMALL_STATE(148)] = 5880,
  [SMALL_STATE(149)] = 5899,
  [SMALL_STATE(150)] = 5916,
  [SMALL_STATE(151)] = 5933,
  [SMALL_STATE(152)] = 5944,
  [SMALL_STATE(153)] = 5963,
  [SMALL_STATE(154)] = 5979,
  [SMALL_STATE(155)] = 5995,
  [SMALL_STATE(156)] = 6011,
  [SMALL_STATE(157)] = 6027,
  [SMALL_STATE(158)] = 6041,
  [SMALL_STATE(159)] = 6055,
  [SMALL_STATE(160)] = 6071,
  [SMALL_STATE(161)] = 6087,
  [SMALL_STATE(162)] = 6103,
  [SMALL_STATE(163)] = 6119,
  [SMALL_STATE(164)] = 6135,
  [SMALL_STATE(165)] = 6149,
  [SMALL_STATE(166)] = 6163,
  [SMALL_STATE(167)] = 6177,
  [SMALL_STATE(168)] = 6191,
  [SMALL_STATE(169)] = 6205,
  [SMALL_STATE(170)] = 6221,
  [SMALL_STATE(171)] = 6237,
  [SMALL_STATE(172)] = 6251,
  [SMALL_STATE(173)] = 6267,
  [SMALL_STATE(174)] = 6283,
  [SMALL_STATE(175)] = 6295,
  [SMALL_STATE(176)] = 6309,
  [SMALL_STATE(177)] = 6323,
  [SMALL_STATE(178)] = 6339,
  [SMALL_STATE(179)] = 6353,
  [SMALL_STATE(180)] = 6363,
  [SMALL_STATE(181)] = 6373,
  [SMALL_STATE(182)] = 6387,
  [SMALL_STATE(183)] = 6401,
  [SMALL_STATE(184)] = 6415,
  [SMALL_STATE(185)] = 6429,
  [SMALL_STATE(186)] = 6443,
  [SMALL_STATE(187)] = 6453,
  [SMALL_STATE(188)] = 6469,
  [SMALL_STATE(189)] = 6479,
  [SMALL_STATE(190)] = 6493,
  [SMALL_STATE(191)] = 6509,
  [SMALL_STATE(192)] = 6523,
  [SMALL_STATE(193)] = 6536,
  [SMALL_STATE(194)] = 6547,
  [SMALL_STATE(195)] = 6558,
  [SMALL_STATE(196)] = 6569,
  [SMALL_STATE(197)] = 6582,
  [SMALL_STATE(198)] = 6595,
  [SMALL_STATE(199)] = 6608,
  [SMALL_STATE(200)] = 6619,
  [SMALL_STATE(201)] = 6630,
  [SMALL_STATE(202)] = 6641,
  [SMALL_STATE(203)] = 6652,
  [SMALL_STATE(204)] = 6663,
  [SMALL_STATE(205)] = 6676,
  [SMALL_STATE(206)] = 6687,
  [SMALL_STATE(207)] = 6698,
  [SMALL_STATE(208)] = 6709,
  [SMALL_STATE(209)] = 6722,
  [SMALL_STATE(210)] = 6735,
  [SMALL_STATE(211)] = 6746,
  [SMALL_STATE(212)] = 6759,
  [SMALL_STATE(213)] = 6772,
  [SMALL_STATE(214)] = 6783,
  [SMALL_STATE(215)] = 6792,
  [SMALL_STATE(216)] = 6803,
  [SMALL_STATE(217)] = 6811,
  [SMALL_STATE(218)] = 6821,
  [SMALL_STATE(219)] = 6829,
  [SMALL_STATE(220)] = 6837,
  [SMALL_STATE(221)] = 6845,
  [SMALL_STATE(222)] = 6853,
  [SMALL_STATE(223)] = 6861,
  [SMALL_STATE(224)] = 6869,
  [SMALL_STATE(225)] = 6879,
  [SMALL_STATE(226)] = 6889,
  [SMALL_STATE(227)] = 6897,
  [SMALL_STATE(228)] = 6907,
  [SMALL_STATE(229)] = 6915,
  [SMALL_STATE(230)] = 6923,
  [SMALL_STATE(231)] = 6930,
  [SMALL_STATE(232)] = 6937,
  [SMALL_STATE(233)] = 6944,
  [SMALL_STATE(234)] = 6951,
  [SMALL_STATE(235)] = 6958,
  [SMALL_STATE(236)] = 6965,
  [SMALL_STATE(237)] = 6972,
  [SMALL_STATE(238)] = 6979,
  [SMALL_STATE(239)] = 6986,
  [SMALL_STATE(240)] = 6993,
  [SMALL_STATE(241)] = 7000,
  [SMALL_STATE(242)] = 7007,
  [SMALL_STATE(243)] = 7014,
  [SMALL_STATE(244)] = 7021,
  [SMALL_STATE(245)] = 7028,
  [SMALL_STATE(246)] = 7035,
  [SMALL_STATE(247)] = 7042,
  [SMALL_STATE(248)] = 7049,
  [SMALL_STATE(249)] = 7056,
  [SMALL_STATE(250)] = 7063,
  [SMALL_STATE(251)] = 7070,
  [SMALL_STATE(252)] = 7077,
  [SMALL_STATE(253)] = 7084,
  [SMALL_STATE(254)] = 7091,
  [SMALL_STATE(255)] = 7098,
  [SMALL_STATE(256)] = 7105,
  [SMALL_STATE(257)] = 7112,
  [SMALL_STATE(258)] = 7119,
  [SMALL_STATE(259)] = 7126,
  [SMALL_STATE(260)] = 7133,
  [SMALL_STATE(261)] = 7140,
  [SMALL_STATE(262)] = 7147,
  [SMALL_STATE(263)] = 7154,
  [SMALL_STATE(264)] = 7161,
  [SMALL_STATE(265)] = 7168,
  [SMALL_STATE(266)] = 7175,
  [SMALL_STATE(267)] = 7182,
  [SMALL_STATE(268)] = 7189,
  [SMALL_STATE(269)] = 7196,
  [SMALL_STATE(270)] = 7203,
  [SMALL_STATE(271)] = 7210,
  [SMALL_STATE(272)] = 7217,
  [SMALL_STATE(273)] = 7224,
  [SMALL_STATE(274)] = 7231,
  [SMALL_STATE(275)] = 7238,
  [SMALL_STATE(276)] = 7245,
  [SMALL_STATE(277)] = 7252,
  [SMALL_STATE(278)] = 7259,
  [SMALL_STATE(279)] = 7266,
  [SMALL_STATE(280)] = 7273,
  [SMALL_STATE(281)] = 7280,
  [SMALL_STATE(282)] = 7287,
  [SMALL_STATE(283)] = 7294,
  [SMALL_STATE(284)] = 7301,
  [SMALL_STATE(285)] = 7308,
  [SMALL_STATE(286)] = 7315,
  [SMALL_STATE(287)] = 7322,
  [SMALL_STATE(288)] = 7329,
  [SMALL_STATE(289)] = 7336,
  [SMALL_STATE(290)] = 7343,
  [SMALL_STATE(291)] = 7350,
  [SMALL_STATE(292)] = 7357,
  [SMALL_STATE(293)] = 7364,
  [SMALL_STATE(294)] = 7371,
  [SMALL_STATE(295)] = 7378,
  [SMALL_STATE(296)] = 7385,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(270),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(148),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(290),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(269),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(267),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_command, 1, .production_id = 1),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [35] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_command, 1, .production_id = 1),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [41] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(286),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(287),
  [47] = {.entry = {.count = 1, .reusable = false}}, SHIFT(288),
  [49] = {.entry = {.count = 1, .reusable = false}}, SHIFT(253),
  [51] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [53] = {.entry = {.count = 1, .reusable = false}}, SHIFT(45),
  [55] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [57] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [59] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_command, 2, .production_id = 2),
  [63] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_command, 2, .production_id = 2),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 6),
  [67] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 6), SHIFT_REPEAT(36),
  [70] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 6),
  [72] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 6), SHIFT_REPEAT(9),
  [75] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 6), SHIFT_REPEAT(22),
  [78] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 6), SHIFT_REPEAT(286),
  [81] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 6), SHIFT_REPEAT(287),
  [84] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 6), SHIFT_REPEAT(288),
  [87] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 6), SHIFT_REPEAT(253),
  [90] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 6), SHIFT_REPEAT(25),
  [93] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 6), SHIFT_REPEAT(45),
  [96] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 6), SHIFT_REPEAT(41),
  [99] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 6), SHIFT_REPEAT(32),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_command, 3, .production_id = 5),
  [104] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_command, 3, .production_id = 5),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_command, 2, .production_id = 4),
  [108] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_command, 2, .production_id = 4),
  [110] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [112] = {.entry = {.count = 1, .reusable = false}}, SHIFT(140),
  [114] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [116] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [118] = {.entry = {.count = 1, .reusable = false}}, SHIFT(167),
  [120] = {.entry = {.count = 1, .reusable = false}}, SHIFT(182),
  [122] = {.entry = {.count = 1, .reusable = false}}, SHIFT(281),
  [124] = {.entry = {.count = 1, .reusable = false}}, SHIFT(282),
  [126] = {.entry = {.count = 1, .reusable = false}}, SHIFT(283),
  [128] = {.entry = {.count = 1, .reusable = false}}, SHIFT(232),
  [130] = {.entry = {.count = 1, .reusable = false}}, SHIFT(202),
  [132] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [136] = {.entry = {.count = 1, .reusable = false}}, SHIFT(38),
  [138] = {.entry = {.count = 1, .reusable = false}}, SHIFT(201),
  [140] = {.entry = {.count = 1, .reusable = false}}, SHIFT(162),
  [142] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [144] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [146] = {.entry = {.count = 1, .reusable = false}}, SHIFT(153),
  [148] = {.entry = {.count = 1, .reusable = false}}, SHIFT(194),
  [150] = {.entry = {.count = 1, .reusable = false}}, SHIFT(163),
  [152] = {.entry = {.count = 1, .reusable = false}}, SHIFT(226),
  [154] = {.entry = {.count = 1, .reusable = false}}, SHIFT(187),
  [156] = {.entry = {.count = 1, .reusable = false}}, SHIFT(69),
  [158] = {.entry = {.count = 1, .reusable = false}}, SHIFT(173),
  [160] = {.entry = {.count = 1, .reusable = false}}, SHIFT(77),
  [162] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [164] = {.entry = {.count = 1, .reusable = false}}, SHIFT(207),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(207),
  [168] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(201),
  [172] = {.entry = {.count = 1, .reusable = false}}, SHIFT(228),
  [174] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [176] = {.entry = {.count = 1, .reusable = true}}, SHIFT(228),
  [178] = {.entry = {.count = 1, .reusable = false}}, SHIFT(145),
  [180] = {.entry = {.count = 1, .reusable = false}}, SHIFT(238),
  [182] = {.entry = {.count = 1, .reusable = false}}, SHIFT(233),
  [184] = {.entry = {.count = 1, .reusable = false}}, SHIFT(243),
  [186] = {.entry = {.count = 1, .reusable = false}}, SHIFT(237),
  [188] = {.entry = {.count = 1, .reusable = false}}, SHIFT(179),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [192] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [194] = {.entry = {.count = 1, .reusable = false}}, SHIFT(180),
  [196] = {.entry = {.count = 1, .reusable = true}}, SHIFT(180),
  [198] = {.entry = {.count = 1, .reusable = false}}, SHIFT(206),
  [200] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
  [202] = {.entry = {.count = 1, .reusable = false}}, SHIFT(229),
  [204] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [206] = {.entry = {.count = 1, .reusable = true}}, SHIFT(229),
  [208] = {.entry = {.count = 1, .reusable = false}}, SHIFT(268),
  [210] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [212] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [214] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_value_path_repeat1, 2),
  [216] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_value_path_repeat1, 2),
  [218] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_value_path_repeat1, 2), SHIFT_REPEAT(265),
  [221] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_path, 3),
  [223] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_value_path, 3),
  [225] = {.entry = {.count = 1, .reusable = false}}, SHIFT(265),
  [227] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_path, 2),
  [229] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_value_path, 2),
  [231] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 1),
  [233] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__expression, 1),
  [235] = {.entry = {.count = 1, .reusable = false}}, SHIFT(231),
  [237] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record_or_block, 3),
  [239] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_record_or_block, 3),
  [241] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_file_path, 1),
  [243] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_file_path, 1),
  [245] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_command_substitution, 3),
  [247] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_command_substitution, 3),
  [249] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table, 5),
  [251] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_table, 5),
  [253] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3),
  [255] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 3),
  [257] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table, 4),
  [259] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_table, 4),
  [261] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 4),
  [263] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array, 4),
  [265] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 2),
  [267] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array, 2),
  [269] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operator, 1),
  [271] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_operator, 1),
  [273] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_range, 3, .production_id = 10),
  [275] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_range, 3, .production_id = 10),
  [277] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record_or_block, 2),
  [279] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_record_or_block, 2),
  [281] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 3),
  [283] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array, 3),
  [285] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_command_repeat1, 1, .production_id = 3),
  [287] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 1, .production_id = 3),
  [289] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [291] = {.entry = {.count = 1, .reusable = true}}, SHIFT(223),
  [293] = {.entry = {.count = 1, .reusable = true}}, SHIFT(195),
  [295] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [297] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [299] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [301] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [303] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(270),
  [306] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(148),
  [309] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(290),
  [312] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(112),
  [315] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(12),
  [318] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(110),
  [321] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(269),
  [324] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(71),
  [327] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(267),
  [330] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(44),
  [333] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(2),
  [336] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(40),
  [339] = {.entry = {.count = 1, .reusable = true}}, SHIFT(274),
  [341] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_value_path_repeat1, 2), SHIFT_REPEAT(274),
  [344] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3, .production_id = 7),
  [346] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_expression, 3, .production_id = 7),
  [348] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_variable_declaration, 4, .production_id = 11),
  [350] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_variable_declaration, 4, .production_id = 11),
  [352] = {.entry = {.count = 1, .reusable = false}}, SHIFT(111),
  [354] = {.entry = {.count = 1, .reusable = false}}, SHIFT(113),
  [356] = {.entry = {.count = 1, .reusable = false}}, SHIFT(114),
  [358] = {.entry = {.count = 1, .reusable = false}}, SHIFT(115),
  [360] = {.entry = {.count = 1, .reusable = false}}, SHIFT(109),
  [362] = {.entry = {.count = 1, .reusable = false}}, SHIFT(108),
  [364] = {.entry = {.count = 1, .reusable = false}}, SHIFT(106),
  [366] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_math_mode, 2),
  [368] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_math_mode, 2),
  [370] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statement, 1),
  [372] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statement, 1),
  [374] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parenthesized_math_expression, 3),
  [376] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_parenthesized_math_expression, 3),
  [378] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_value_path_repeat1, 2), SHIFT_REPEAT(250),
  [381] = {.entry = {.count = 1, .reusable = true}}, SHIFT(250),
  [383] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [385] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [387] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [389] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [391] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [393] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [395] = {.entry = {.count = 1, .reusable = false}}, SHIFT(103),
  [397] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [399] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [401] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [403] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [405] = {.entry = {.count = 1, .reusable = true}}, SHIFT(291),
  [407] = {.entry = {.count = 1, .reusable = true}}, SHIFT(292),
  [409] = {.entry = {.count = 1, .reusable = true}}, SHIFT(293),
  [411] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statements, 3),
  [413] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2),
  [415] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2),
  [417] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statements, 2),
  [419] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [421] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [423] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [425] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [427] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [429] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [431] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [433] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [435] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [437] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [439] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [441] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [443] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [445] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [447] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [449] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [451] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [453] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [455] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [457] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [459] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [461] = {.entry = {.count = 1, .reusable = true}}, SHIFT(255),
  [463] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [465] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [467] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [469] = {.entry = {.count = 1, .reusable = true}}, SHIFT(280),
  [471] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_signature_repeat1, 2),
  [473] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_signature_repeat1, 2), SHIFT_REPEAT(126),
  [476] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_signature_repeat1, 2), SHIFT_REPEAT(128),
  [479] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_signature_repeat1, 2), SHIFT_REPEAT(127),
  [482] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statements, 1),
  [484] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [486] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [488] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statements, 1),
  [490] = {.entry = {.count = 1, .reusable = false}}, SHIFT(97),
  [492] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [494] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statements, 2),
  [496] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag, 1),
  [498] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [500] = {.entry = {.count = 1, .reusable = true}}, SHIFT(285),
  [502] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 1),
  [504] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [506] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [508] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rest, 1),
  [510] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [512] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag, 4),
  [514] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [516] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2),
  [518] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 2),
  [520] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 5, .production_id = 12),
  [522] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_definition, 5, .production_id = 12),
  [524] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alias, 4, .production_id = 9),
  [526] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_alias, 4, .production_id = 9),
  [528] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1),
  [530] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 4, .production_id = 8),
  [532] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_definition, 4, .production_id = 8),
  [534] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 3),
  [536] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 3),
  [538] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 3),
  [540] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [542] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rest, 3),
  [544] = {.entry = {.count = 1, .reusable = false}}, SHIFT(183),
  [546] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag, 3),
  [548] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 4),
  [550] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_value_path_repeat1, 2), SHIFT_REPEAT(234),
  [553] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag, 6),
  [555] = {.entry = {.count = 1, .reusable = true}}, SHIFT(247),
  [557] = {.entry = {.count = 1, .reusable = true}}, SHIFT(186),
  [559] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_signature_repeat1, 1),
  [561] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 2),
  [563] = {.entry = {.count = 1, .reusable = true}}, SHIFT(238),
  [565] = {.entry = {.count = 1, .reusable = true}}, SHIFT(233),
  [567] = {.entry = {.count = 1, .reusable = true}}, SHIFT(243),
  [569] = {.entry = {.count = 1, .reusable = true}}, SHIFT(227),
  [571] = {.entry = {.count = 1, .reusable = true}}, SHIFT(234),
  [573] = {.entry = {.count = 1, .reusable = true}}, SHIFT(225),
  [575] = {.entry = {.count = 1, .reusable = false}}, SHIFT(200),
  [577] = {.entry = {.count = 1, .reusable = false}}, SHIFT(222),
  [579] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_array_repeat1, 2), SHIFT_REPEAT(17),
  [582] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_array_repeat1, 2),
  [584] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2), SHIFT_REPEAT(17),
  [587] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [589] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [591] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [593] = {.entry = {.count = 1, .reusable = false}}, SHIFT(80),
  [595] = {.entry = {.count = 1, .reusable = false}}, SHIFT(57),
  [597] = {.entry = {.count = 1, .reusable = false}}, SHIFT(78),
  [599] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [601] = {.entry = {.count = 1, .reusable = true}}, SHIFT(215),
  [603] = {.entry = {.count = 1, .reusable = true}}, SHIFT(213),
  [605] = {.entry = {.count = 1, .reusable = false}}, SHIFT(116),
  [607] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [609] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_column_header, 2),
  [611] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [613] = {.entry = {.count = 1, .reusable = false}}, SHIFT(219),
  [615] = {.entry = {.count = 1, .reusable = false}}, SHIFT(193),
  [617] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [619] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_table_repeat1, 2), SHIFT_REPEAT(14),
  [622] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_repeat1, 2),
  [624] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_value_path_repeat1, 2), SHIFT_REPEAT(277),
  [627] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [629] = {.entry = {.count = 1, .reusable = true}}, SHIFT(277),
  [631] = {.entry = {.count = 1, .reusable = false}}, SHIFT(271),
  [633] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_column_header, 3),
  [635] = {.entry = {.count = 1, .reusable = true}}, SHIFT(218),
  [637] = {.entry = {.count = 1, .reusable = true}}, SHIFT(216),
  [639] = {.entry = {.count = 1, .reusable = false}}, SHIFT(56),
  [641] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [643] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [645] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [647] = {.entry = {.count = 1, .reusable = true}}, SHIFT(278),
  [649] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_record_or_block_repeat1, 2), SHIFT_REPEAT(275),
  [652] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_record_or_block_repeat1, 2),
  [654] = {.entry = {.count = 1, .reusable = true}}, SHIFT(275),
  [656] = {.entry = {.count = 1, .reusable = true}}, SHIFT(220),
  [658] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_column_header_repeat1, 2), SHIFT_REPEAT(16),
  [661] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_column_header_repeat1, 2),
  [663] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [665] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2),
  [667] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_column_header_repeat1, 2), REDUCE(aux_sym_array_repeat1, 2),
  [670] = {.entry = {.count = 1, .reusable = true}}, SHIFT(295),
  [672] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [674] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [676] = {.entry = {.count = 1, .reusable = true}}, SHIFT(205),
  [678] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [680] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [682] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_record_or_block_repeat1, 3),
  [684] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [686] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [688] = {.entry = {.count = 1, .reusable = true}}, SHIFT(149),
  [690] = {.entry = {.count = 1, .reusable = true}}, SHIFT(264),
  [692] = {.entry = {.count = 1, .reusable = true}}, SHIFT(174),
  [694] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [696] = {.entry = {.count = 1, .reusable = true}}, SHIFT(157),
  [698] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [700] = {.entry = {.count = 1, .reusable = true}}, SHIFT(263),
  [702] = {.entry = {.count = 1, .reusable = true}}, SHIFT(203),
  [704] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [706] = {.entry = {.count = 1, .reusable = true}}, SHIFT(266),
  [708] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [710] = {.entry = {.count = 1, .reusable = true}}, SHIFT(188),
  [712] = {.entry = {.count = 1, .reusable = true}}, SHIFT(210),
  [714] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [716] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [718] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [720] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [722] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_signature, 2),
  [724] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [726] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [728] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [730] = {.entry = {.count = 1, .reusable = true}}, SHIFT(151),
  [732] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [734] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [736] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [738] = {.entry = {.count = 1, .reusable = true}}, SHIFT(256),
  [740] = {.entry = {.count = 1, .reusable = true}}, SHIFT(152),
  [742] = {.entry = {.count = 1, .reusable = true}}, SHIFT(199),
  [744] = {.entry = {.count = 1, .reusable = true}}, SHIFT(221),
  [746] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [748] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [750] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [752] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [754] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_column_header, 4),
  [756] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [758] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_signature, 3),
  [760] = {.entry = {.count = 1, .reusable = true}}, SHIFT(248),
  [762] = {.entry = {.count = 1, .reusable = true}}, SHIFT(249),
  [764] = {.entry = {.count = 1, .reusable = true}}, SHIFT(251),
  [766] = {.entry = {.count = 1, .reusable = true}}, SHIFT(165),
  [768] = {.entry = {.count = 1, .reusable = true}}, SHIFT(276),
  [770] = {.entry = {.count = 1, .reusable = true}}, SHIFT(244),
  [772] = {.entry = {.count = 1, .reusable = true}}, SHIFT(245),
  [774] = {.entry = {.count = 1, .reusable = true}}, SHIFT(246),
  [776] = {.entry = {.count = 1, .reusable = true}}, SHIFT(158),
  [778] = {.entry = {.count = 1, .reusable = true}}, SHIFT(235),
  [780] = {.entry = {.count = 1, .reusable = true}}, SHIFT(260),
  [782] = {.entry = {.count = 1, .reusable = true}}, SHIFT(261),
  [784] = {.entry = {.count = 1, .reusable = true}}, SHIFT(262),
  [786] = {.entry = {.count = 1, .reusable = true}}, SHIFT(171),
  [788] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_column_header, 3),
  [790] = {.entry = {.count = 1, .reusable = true}}, SHIFT(184),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_nu(void) {
  static const TSLanguage language = {
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
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
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
