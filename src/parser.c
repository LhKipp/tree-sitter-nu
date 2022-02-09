#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 309
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 104
#define ALIAS_COUNT 0
#define TOKEN_COUNT 67
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 11
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 11

enum {
  sym_word = 1,
  anon_sym_export = 2,
  anon_sym_def = 3,
  anon_sym_alias = 4,
  anon_sym_EQ = 5,
  anon_sym_LBRACK = 6,
  anon_sym_COMMA = 7,
  anon_sym_RBRACK = 8,
  anon_sym_COLON = 9,
  anon_sym_QMARK = 10,
  anon_sym_LPAREN = 11,
  anon_sym_RPAREN = 12,
  sym_flag_name = 13,
  sym_flag_shorthand_name = 14,
  anon_sym_DOT_DOT_DOTrest = 15,
  anon_sym_int = 16,
  anon_sym_string = 17,
  anon_sym_path = 18,
  anon_sym_table = 19,
  anon_sym_unit = 20,
  anon_sym_number = 21,
  anon_sym_pattern = 22,
  anon_sym_range = 23,
  anon_sym_block = 24,
  anon_sym_any = 25,
  anon_sym_let = 26,
  sym_cmd_name = 27,
  anon_sym_PIPE = 28,
  sym_number_literal = 29,
  anon_sym_DQUOTE = 30,
  aux_sym_string_token1 = 31,
  anon_sym_SQUOTE = 32,
  aux_sym_string_token2 = 33,
  anon_sym_BQUOTE = 34,
  aux_sym_string_token3 = 35,
  anon_sym_DOLLAR = 36,
  anon_sym_DOT = 37,
  aux_sym_file_path_token1 = 38,
  aux_sym_file_path_token2 = 39,
  anon_sym_DOT_DOT = 40,
  anon_sym_DOLLAR_LPAREN = 41,
  sym_identifier = 42,
  anon_sym_SEMI = 43,
  anon_sym_ = 44,
  anon_sym_LBRACE = 45,
  anon_sym_RBRACE = 46,
  sym_comment = 47,
  anon_sym_LF = 48,
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
  sym__statement = 69,
  sym_function_definition = 70,
  sym_alias = 71,
  sym_signature = 72,
  sym_parameter = 73,
  sym_flag = 74,
  sym_rest = 75,
  sym_type = 76,
  sym_variable_declaration = 77,
  sym_command = 78,
  sym_pipeline = 79,
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
  sym_block = 91,
  sym__terminator = 92,
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
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_word] = "word",
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
  [sym_cmd_name] = "cmd_name",
  [anon_sym_PIPE] = "|",
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
  [anon_sym_SEMI] = ";",
  [anon_sym_] = " ",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [sym_comment] = "comment",
  [anon_sym_LF] = "\n",
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
  [sym_pipeline] = "pipeline",
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
  [sym_block] = "block",
  [sym__terminator] = "_terminator",
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
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_word] = sym_word,
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
  [sym_cmd_name] = sym_cmd_name,
  [anon_sym_PIPE] = anon_sym_PIPE,
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
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_] = anon_sym_,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [sym_comment] = sym_comment,
  [anon_sym_LF] = anon_sym_LF,
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
  [sym_pipeline] = sym_pipeline,
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
  [sym_block] = sym_block,
  [sym__terminator] = sym__terminator,
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
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
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
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 2},
  [4] = {.index = 4, .length = 2},
  [5] = {.index = 6, .length = 3},
  [6] = {.index = 9, .length = 1},
  [7] = {.index = 10, .length = 1},
  [8] = {.index = 11, .length = 2},
  [9] = {.index = 13, .length = 2},
  [10] = {.index = 15, .length = 1},
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
    {field_alias_name, 1},
  [11] =
    {field_from, 0},
    {field_to, 2},
  [13] =
    {field_name, 1},
    {field_value, 3},
  [15] =
    {field_func_name, 2},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static inline bool sym_word_character_set_1(int32_t c) {
  return (c < ';'
    ? (c < '\''
      ? (c < '"'
        ? c == 0
        : c <= '$')
      : (c <= ')' || (c >= '-' && c <= '.')))
    : (c <= ';' || (c < '{'
      ? (c < '`'
        ? (c >= '[' && c <= ']')
        : c <= '`')
      : (c <= '{' || c == '}'))));
}

static inline bool sym_word_character_set_2(int32_t c) {
  return (c < '-'
    ? (c < ' '
      ? (c < '\t'
        ? c == 0
        : (c <= '\n' || c == '\r'))
      : (c <= ' ' || (c < '\''
        ? (c >= '"' && c <= '$')
        : c <= ')')))
    : (c <= '-' || (c < '`'
      ? (c < '['
        ? c == ';'
        : c <= ']')
      : (c <= '`' || (c < '}'
        ? c == '{'
        : c <= '}')))));
}

static inline bool sym_word_character_set_3(int32_t c) {
  return (c < '-'
    ? (c < ' '
      ? (c < '\t'
        ? c == 0
        : (c <= '\n' || c == '\r'))
      : (c <= ' ' || (c < '\''
        ? (c >= '"' && c <= '$')
        : c <= ')')))
    : (c <= '.' || (c < '`'
      ? (c < '['
        ? c == ';'
        : c <= ']')
      : (c <= '`' || (c < '}'
        ? c == '{'
        : c <= '}')))));
}

static inline bool sym_word_character_set_4(int32_t c) {
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
        ? (c >= '`' && c <= '{')
        : c <= '}')))));
}

static inline bool sym_word_character_set_5(int32_t c) {
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

static inline bool sym_word_character_set_6(int32_t c) {
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

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(48);
      if (lookahead == '!') ADVANCE(107);
      if (lookahead == '"') ADVANCE(124);
      if (lookahead == '#') ADVANCE(170);
      if (lookahead == '$') ADVANCE(139);
      if (lookahead == '%') ADVANCE(183);
      if (lookahead == '&') ADVANCE(99);
      if (lookahead == '\'') ADVANCE(129);
      if (lookahead == '(') ADVANCE(65);
      if (lookahead == ')') ADVANCE(66);
      if (lookahead == '*') ADVANCE(179);
      if (lookahead == '+') ADVANCE(174);
      if (lookahead == ',') ADVANCE(59);
      if (lookahead == '-') ADVANCE(178);
      if (lookahead == '.') ADVANCE(142);
      if (lookahead == '/') ADVANCE(181);
      if (lookahead == ':') ADVANCE(63);
      if (lookahead == ';') ADVANCE(160);
      if (lookahead == '<') ADVANCE(195);
      if (lookahead == '=') ADVANCE(56);
      if (lookahead == '>') ADVANCE(191);
      if (lookahead == '?') ADVANCE(64);
      if (lookahead == '[') ADVANCE(57);
      if (lookahead == '\\') ADVANCE(41);
      if (lookahead == ']') ADVANCE(61);
      if (lookahead == '`') ADVANCE(134);
      if (lookahead == 'a') ADVANCE(114);
      if (lookahead == 'd') ADVANCE(110);
      if (lookahead == 'e') ADVANCE(121);
      if (lookahead == 'l') ADVANCE(111);
      if (lookahead == '{') ADVANCE(164);
      if (lookahead == '|') ADVANCE(91);
      if (lookahead == '}') ADVANCE(166);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(46)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(92);
      if (lookahead != 0) ADVANCE(123);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(171);
      if (lookahead == '!') ADVANCE(103);
      if (lookahead == '"') ADVANCE(125);
      if (lookahead == '#') ADVANCE(169);
      if (lookahead == '$') ADVANCE(140);
      if (lookahead == '%') ADVANCE(184);
      if (lookahead == '&') ADVANCE(98);
      if (lookahead == '\'') ADVANCE(130);
      if (lookahead == ')') ADVANCE(67);
      if (lookahead == '*') ADVANCE(180);
      if (lookahead == '+') ADVANCE(175);
      if (lookahead == '-') ADVANCE(177);
      if (lookahead == '.') ADVANCE(24);
      if (lookahead == '/') ADVANCE(182);
      if (lookahead == ';') ADVANCE(161);
      if (lookahead == '<') ADVANCE(194);
      if (lookahead == '=') ADVANCE(104);
      if (lookahead == '>') ADVANCE(190);
      if (lookahead == '[') ADVANCE(58);
      if (lookahead == '\\') ADVANCE(27);
      if (lookahead == '`') ADVANCE(135);
      if (lookahead == '{') ADVANCE(165);
      if (lookahead == '|') ADVANCE(90);
      if (lookahead == '}') ADVANCE(167);
      if (lookahead == '(' ||
          lookahead == ']') ADVANCE(30);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(95);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      if (lookahead != 0) ADVANCE(106);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(173);
      if (lookahead == '!') ADVANCE(103);
      if (lookahead == '"') ADVANCE(125);
      if (lookahead == '#') ADVANCE(169);
      if (lookahead == '$') ADVANCE(140);
      if (lookahead == '%') ADVANCE(184);
      if (lookahead == '&') ADVANCE(98);
      if (lookahead == '\'') ADVANCE(130);
      if (lookahead == ')') ADVANCE(67);
      if (lookahead == '*') ADVANCE(180);
      if (lookahead == '+') ADVANCE(175);
      if (lookahead == '-') ADVANCE(177);
      if (lookahead == '.') ADVANCE(28);
      if (lookahead == '/') ADVANCE(182);
      if (lookahead == ';') ADVANCE(161);
      if (lookahead == '<') ADVANCE(194);
      if (lookahead == '=') ADVANCE(104);
      if (lookahead == '>') ADVANCE(190);
      if (lookahead == '[') ADVANCE(58);
      if (lookahead == '\\') ADVANCE(27);
      if (lookahead == '`') ADVANCE(135);
      if (lookahead == '{') ADVANCE(165);
      if (lookahead == '|') ADVANCE(90);
      if (lookahead == '}') ADVANCE(167);
      if (lookahead == '(' ||
          lookahead == ']') ADVANCE(30);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(2);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(95);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      if (lookahead != 0) ADVANCE(106);
      END_STATE();
    case 3:
      if (lookahead == ' ') ADVANCE(162);
      if (lookahead == '!') ADVANCE(107);
      if (lookahead == '"') ADVANCE(124);
      if (lookahead == '#') ADVANCE(170);
      if (lookahead == '$') ADVANCE(139);
      if (lookahead == '%') ADVANCE(183);
      if (lookahead == '&') ADVANCE(99);
      if (lookahead == '\'') ADVANCE(129);
      if (lookahead == '*') ADVANCE(179);
      if (lookahead == '+') ADVANCE(174);
      if (lookahead == ',') ADVANCE(59);
      if (lookahead == '-') ADVANCE(178);
      if (lookahead == '.') ADVANCE(23);
      if (lookahead == '/') ADVANCE(181);
      if (lookahead == '<') ADVANCE(195);
      if (lookahead == '=') ADVANCE(108);
      if (lookahead == '>') ADVANCE(191);
      if (lookahead == '[') ADVANCE(57);
      if (lookahead == '\\') ADVANCE(41);
      if (lookahead == ']') ADVANCE(61);
      if (lookahead == '`') ADVANCE(134);
      if (lookahead == '{') ADVANCE(164);
      if (lookahead == '|') ADVANCE(122);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') ADVANCE(4);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      if (lookahead != 0 &&
          lookahead != '(' &&
          lookahead != ')' &&
          lookahead != ';' &&
          lookahead != '}') ADVANCE(123);
      END_STATE();
    case 4:
      if (lookahead == ' ') ADVANCE(162);
      if (lookahead == '!') ADVANCE(103);
      if (lookahead == '"') ADVANCE(125);
      if (lookahead == '#') ADVANCE(169);
      if (lookahead == '$') ADVANCE(140);
      if (lookahead == '%') ADVANCE(184);
      if (lookahead == '&') ADVANCE(98);
      if (lookahead == '\'') ADVANCE(130);
      if (lookahead == '*') ADVANCE(180);
      if (lookahead == '+') ADVANCE(175);
      if (lookahead == ',') ADVANCE(60);
      if (lookahead == '-') ADVANCE(177);
      if (lookahead == '.') ADVANCE(24);
      if (lookahead == '/') ADVANCE(182);
      if (lookahead == '<') ADVANCE(194);
      if (lookahead == '=') ADVANCE(104);
      if (lookahead == '>') ADVANCE(190);
      if (lookahead == '[') ADVANCE(58);
      if (lookahead == '\\') ADVANCE(27);
      if (lookahead == ']') ADVANCE(62);
      if (lookahead == '`') ADVANCE(135);
      if (lookahead == '{') ADVANCE(165);
      if (lookahead == '|') ADVANCE(105);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') ADVANCE(4);
      if (lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ';' ||
          lookahead == '}') ADVANCE(30);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(95);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      if (lookahead != 0) ADVANCE(106);
      END_STATE();
    case 5:
      if (lookahead == ' ') ADVANCE(163);
      if (lookahead == '#') ADVANCE(170);
      if (lookahead == ',') ADVANCE(59);
      if (lookahead == '.') ADVANCE(141);
      if (lookahead == ';') ADVANCE(160);
      if (lookahead == ']') ADVANCE(61);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') SKIP(7)
      END_STATE();
    case 6:
      if (lookahead == ' ') ADVANCE(163);
      if (lookahead == '#') ADVANCE(170);
      if (lookahead == ',') ADVANCE(59);
      if (lookahead == '.') ADVANCE(21);
      if (lookahead == ']') ADVANCE(61);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') SKIP(6)
      END_STATE();
    case 7:
      if (lookahead == ' ') ADVANCE(163);
      if (lookahead == '#') ADVANCE(170);
      if (lookahead == ',') ADVANCE(59);
      if (lookahead == ';') ADVANCE(160);
      if (lookahead == ']') ADVANCE(61);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') SKIP(7)
      END_STATE();
    case 8:
      if (lookahead == '!') ADVANCE(107);
      if (lookahead == '"') ADVANCE(124);
      if (lookahead == '#') ADVANCE(170);
      if (lookahead == '$') ADVANCE(139);
      if (lookahead == '%') ADVANCE(183);
      if (lookahead == '&') ADVANCE(99);
      if (lookahead == '\'') ADVANCE(129);
      if (lookahead == '*') ADVANCE(179);
      if (lookahead == '+') ADVANCE(174);
      if (lookahead == '-') ADVANCE(178);
      if (lookahead == '.') ADVANCE(23);
      if (lookahead == '/') ADVANCE(181);
      if (lookahead == '<') ADVANCE(195);
      if (lookahead == '=') ADVANCE(108);
      if (lookahead == '>') ADVANCE(191);
      if (lookahead == '[') ADVANCE(57);
      if (lookahead == '\\') ADVANCE(41);
      if (lookahead == '`') ADVANCE(134);
      if (lookahead == '{') ADVANCE(164);
      if (lookahead == '|') ADVANCE(122);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(12);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      if (lookahead != 0 &&
          lookahead != '(' &&
          lookahead != ')' &&
          lookahead != ';' &&
          lookahead != ']' &&
          lookahead != '}') ADVANCE(123);
      END_STATE();
    case 9:
      if (lookahead == '!') ADVANCE(107);
      if (lookahead == '#') ADVANCE(170);
      if (lookahead == '%') ADVANCE(183);
      if (lookahead == '&') ADVANCE(99);
      if (lookahead == ')') ADVANCE(66);
      if (lookahead == '*') ADVANCE(179);
      if (lookahead == '+') ADVANCE(174);
      if (lookahead == ',') ADVANCE(59);
      if (lookahead == '-') ADVANCE(176);
      if (lookahead == '.') ADVANCE(141);
      if (lookahead == '/') ADVANCE(181);
      if (lookahead == '<') ADVANCE(195);
      if (lookahead == '=') ADVANCE(108);
      if (lookahead == '>') ADVANCE(191);
      if (lookahead == '[') ADVANCE(57);
      if (lookahead == '\\') ADVANCE(41);
      if (lookahead == ']') ADVANCE(61);
      if (lookahead == '|') ADVANCE(122);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(10)
      if (lookahead != 0 &&
          (lookahead < '"' || '(' < lookahead) &&
          lookahead != ';' &&
          lookahead != '`' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(123);
      END_STATE();
    case 10:
      if (lookahead == '!') ADVANCE(107);
      if (lookahead == '#') ADVANCE(170);
      if (lookahead == '%') ADVANCE(183);
      if (lookahead == '&') ADVANCE(99);
      if (lookahead == ')') ADVANCE(66);
      if (lookahead == '*') ADVANCE(179);
      if (lookahead == '+') ADVANCE(174);
      if (lookahead == ',') ADVANCE(59);
      if (lookahead == '-') ADVANCE(176);
      if (lookahead == '/') ADVANCE(181);
      if (lookahead == '<') ADVANCE(195);
      if (lookahead == '=') ADVANCE(108);
      if (lookahead == '>') ADVANCE(191);
      if (lookahead == '[') ADVANCE(57);
      if (lookahead == '\\') ADVANCE(41);
      if (lookahead == ']') ADVANCE(61);
      if (lookahead == '|') ADVANCE(122);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(10)
      if (lookahead != 0 &&
          (lookahead < '"' || '.' < lookahead) &&
          lookahead != ';' &&
          lookahead != '`' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(123);
      END_STATE();
    case 11:
      if (lookahead == '!') ADVANCE(107);
      if (lookahead == '#') ADVANCE(170);
      if (lookahead == '%') ADVANCE(183);
      if (lookahead == '&') ADVANCE(99);
      if (lookahead == ')') ADVANCE(66);
      if (lookahead == '*') ADVANCE(179);
      if (lookahead == '+') ADVANCE(174);
      if (lookahead == '-') ADVANCE(176);
      if (lookahead == '/') ADVANCE(181);
      if (lookahead == '<') ADVANCE(195);
      if (lookahead == '=') ADVANCE(108);
      if (lookahead == '>') ADVANCE(191);
      if (lookahead == '\\') ADVANCE(41);
      if (lookahead == '|') ADVANCE(122);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(11)
      if (lookahead != 0 &&
          (lookahead < '"' || '(' < lookahead) &&
          lookahead != '.' &&
          lookahead != ';' &&
          (lookahead < '[' || ']' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(123);
      END_STATE();
    case 12:
      if (lookahead == '!') ADVANCE(103);
      if (lookahead == '"') ADVANCE(125);
      if (lookahead == '#') ADVANCE(169);
      if (lookahead == '$') ADVANCE(140);
      if (lookahead == '%') ADVANCE(184);
      if (lookahead == '&') ADVANCE(98);
      if (lookahead == '\'') ADVANCE(130);
      if (lookahead == '*') ADVANCE(180);
      if (lookahead == '+') ADVANCE(175);
      if (lookahead == '-') ADVANCE(177);
      if (lookahead == '.') ADVANCE(24);
      if (lookahead == '/') ADVANCE(182);
      if (lookahead == '<') ADVANCE(194);
      if (lookahead == '=') ADVANCE(104);
      if (lookahead == '>') ADVANCE(190);
      if (lookahead == '[') ADVANCE(58);
      if (lookahead == '\\') ADVANCE(27);
      if (lookahead == '`') ADVANCE(135);
      if (lookahead == '{') ADVANCE(165);
      if (lookahead == '|') ADVANCE(105);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(12);
      if (lookahead == '(' ||
          lookahead == ')' ||
          lookahead == ';' ||
          lookahead == ']' ||
          lookahead == '}') ADVANCE(30);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(95);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      if (lookahead != 0) ADVANCE(106);
      END_STATE();
    case 13:
      if (lookahead == '"') ADVANCE(124);
      if (lookahead == '#') ADVANCE(170);
      if (lookahead == '\'') ADVANCE(129);
      if (lookahead == '(') ADVANCE(65);
      if (lookahead == ',') ADVANCE(59);
      if (lookahead == '-') ADVANCE(18);
      if (lookahead == '.') ADVANCE(31);
      if (lookahead == ':') ADVANCE(63);
      if (lookahead == '?') ADVANCE(64);
      if (lookahead == ']') ADVANCE(61);
      if (lookahead == '`') ADVANCE(134);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(13)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(158);
      END_STATE();
    case 14:
      if (lookahead == '#') ADVANCE(170);
      if (lookahead == '\\') ADVANCE(41);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(14)
      if (!sym_word_character_set_1(lookahead)) ADVANCE(123);
      END_STATE();
    case 15:
      if (lookahead == '#') ADVANCE(170);
      if (lookahead == 'd') ADVANCE(33);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(15)
      END_STATE();
    case 16:
      if (lookahead == '#') ADVANCE(136);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(138);
      END_STATE();
    case 17:
      if (lookahead == '#') ADVANCE(126);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(127);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(128);
      END_STATE();
    case 18:
      if (lookahead == '-') ADVANCE(38);
      END_STATE();
    case 19:
      if (lookahead == '.') ADVANCE(151);
      END_STATE();
    case 20:
      if (lookahead == '.') ADVANCE(35);
      END_STATE();
    case 21:
      if (lookahead == '.') ADVANCE(150);
      END_STATE();
    case 22:
      if (lookahead == '.') ADVANCE(22);
      if (lookahead == '/') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(149);
      END_STATE();
    case 23:
      if (lookahead == '.') ADVANCE(22);
      if (lookahead == '/') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(23);
      END_STATE();
    case 24:
      if (lookahead == '.') ADVANCE(147);
      if (lookahead == '/') ADVANCE(148);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(144);
      END_STATE();
    case 25:
      if (lookahead == '.') ADVANCE(144);
      END_STATE();
    case 26:
      if (lookahead == '.') ADVANCE(152);
      if (lookahead == '/') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(23);
      END_STATE();
    case 27:
      if (lookahead == '.') ADVANCE(101);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(123);
      END_STATE();
    case 28:
      if (lookahead == '.') ADVANCE(153);
      if (lookahead == '/') ADVANCE(148);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(144);
      END_STATE();
    case 29:
      if (lookahead == '.') ADVANCE(145);
      if (lookahead == '/') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(149);
      END_STATE();
    case 30:
      if (lookahead == '.') ADVANCE(25);
      END_STATE();
    case 31:
      if (lookahead == '.') ADVANCE(20);
      END_STATE();
    case 32:
      if (lookahead == 'e') ADVANCE(36);
      END_STATE();
    case 33:
      if (lookahead == 'e') ADVANCE(34);
      END_STATE();
    case 34:
      if (lookahead == 'f') ADVANCE(51);
      END_STATE();
    case 35:
      if (lookahead == 'r') ADVANCE(32);
      END_STATE();
    case 36:
      if (lookahead == 's') ADVANCE(37);
      END_STATE();
    case 37:
      if (lookahead == 't') ADVANCE(71);
      END_STATE();
    case 38:
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 39:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(159);
      END_STATE();
    case 40:
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(23);
      END_STATE();
    case 41:
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ') ADVANCE(123);
      END_STATE();
    case 42:
      if (eof) ADVANCE(48);
      if (lookahead == '\n') ADVANCE(171);
      if (lookahead == '!') ADVANCE(107);
      if (lookahead == '"') ADVANCE(124);
      if (lookahead == '#') ADVANCE(170);
      if (lookahead == '$') ADVANCE(139);
      if (lookahead == '%') ADVANCE(183);
      if (lookahead == '&') ADVANCE(99);
      if (lookahead == '\'') ADVANCE(129);
      if (lookahead == ')') ADVANCE(66);
      if (lookahead == '*') ADVANCE(179);
      if (lookahead == '+') ADVANCE(174);
      if (lookahead == '-') ADVANCE(178);
      if (lookahead == '.') ADVANCE(143);
      if (lookahead == '/') ADVANCE(181);
      if (lookahead == ';') ADVANCE(160);
      if (lookahead == '<') ADVANCE(195);
      if (lookahead == '=') ADVANCE(108);
      if (lookahead == '>') ADVANCE(191);
      if (lookahead == '[') ADVANCE(57);
      if (lookahead == '\\') ADVANCE(41);
      if (lookahead == '`') ADVANCE(134);
      if (lookahead == '{') ADVANCE(164);
      if (lookahead == '|') ADVANCE(91);
      if (lookahead == '}') ADVANCE(166);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      if (lookahead != 0 &&
          lookahead != '(' &&
          lookahead != ']') ADVANCE(123);
      END_STATE();
    case 43:
      if (eof) ADVANCE(48);
      if (lookahead == '\n') ADVANCE(172);
      if (lookahead == '!') ADVANCE(107);
      if (lookahead == '#') ADVANCE(170);
      if (lookahead == '%') ADVANCE(183);
      if (lookahead == '&') ADVANCE(99);
      if (lookahead == ')') ADVANCE(66);
      if (lookahead == '*') ADVANCE(179);
      if (lookahead == '+') ADVANCE(174);
      if (lookahead == '-') ADVANCE(176);
      if (lookahead == '.') ADVANCE(141);
      if (lookahead == '/') ADVANCE(181);
      if (lookahead == ';') ADVANCE(160);
      if (lookahead == '<') ADVANCE(195);
      if (lookahead == '=') ADVANCE(108);
      if (lookahead == '>') ADVANCE(191);
      if (lookahead == '\\') ADVANCE(41);
      if (lookahead == '|') ADVANCE(91);
      if (lookahead == '}') ADVANCE(166);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(44)
      if (lookahead != 0 &&
          (lookahead < '"' || '(' < lookahead) &&
          (lookahead < '[' || ']' < lookahead) &&
          lookahead != '`' &&
          lookahead != '{') ADVANCE(123);
      END_STATE();
    case 44:
      if (eof) ADVANCE(48);
      if (lookahead == '\n') ADVANCE(172);
      if (lookahead == '!') ADVANCE(107);
      if (lookahead == '#') ADVANCE(170);
      if (lookahead == '%') ADVANCE(183);
      if (lookahead == '&') ADVANCE(99);
      if (lookahead == ')') ADVANCE(66);
      if (lookahead == '*') ADVANCE(179);
      if (lookahead == '+') ADVANCE(174);
      if (lookahead == '-') ADVANCE(176);
      if (lookahead == '/') ADVANCE(181);
      if (lookahead == ';') ADVANCE(160);
      if (lookahead == '<') ADVANCE(195);
      if (lookahead == '=') ADVANCE(108);
      if (lookahead == '>') ADVANCE(191);
      if (lookahead == '\\') ADVANCE(41);
      if (lookahead == '|') ADVANCE(91);
      if (lookahead == '}') ADVANCE(166);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(44)
      if (lookahead != 0 &&
          (lookahead < '"' || '(' < lookahead) &&
          lookahead != '.' &&
          (lookahead < '[' || ']' < lookahead) &&
          lookahead != '`' &&
          lookahead != '{') ADVANCE(123);
      END_STATE();
    case 45:
      if (eof) ADVANCE(48);
      if (lookahead == '\n') ADVANCE(173);
      if (lookahead == '!') ADVANCE(107);
      if (lookahead == '"') ADVANCE(124);
      if (lookahead == '#') ADVANCE(170);
      if (lookahead == '$') ADVANCE(139);
      if (lookahead == '%') ADVANCE(183);
      if (lookahead == '&') ADVANCE(99);
      if (lookahead == '\'') ADVANCE(129);
      if (lookahead == ')') ADVANCE(66);
      if (lookahead == '*') ADVANCE(179);
      if (lookahead == '+') ADVANCE(174);
      if (lookahead == '-') ADVANCE(178);
      if (lookahead == '.') ADVANCE(26);
      if (lookahead == '/') ADVANCE(181);
      if (lookahead == ';') ADVANCE(160);
      if (lookahead == '<') ADVANCE(195);
      if (lookahead == '=') ADVANCE(108);
      if (lookahead == '>') ADVANCE(191);
      if (lookahead == '[') ADVANCE(57);
      if (lookahead == '\\') ADVANCE(41);
      if (lookahead == '`') ADVANCE(134);
      if (lookahead == '{') ADVANCE(164);
      if (lookahead == '|') ADVANCE(91);
      if (lookahead == '}') ADVANCE(166);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(2);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('_' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      if (lookahead != 0 &&
          lookahead != '(' &&
          lookahead != ']') ADVANCE(123);
      END_STATE();
    case 46:
      if (eof) ADVANCE(48);
      if (lookahead == '!') ADVANCE(107);
      if (lookahead == '"') ADVANCE(124);
      if (lookahead == '#') ADVANCE(170);
      if (lookahead == '$') ADVANCE(139);
      if (lookahead == '%') ADVANCE(183);
      if (lookahead == '&') ADVANCE(99);
      if (lookahead == '\'') ADVANCE(129);
      if (lookahead == '(') ADVANCE(65);
      if (lookahead == ')') ADVANCE(66);
      if (lookahead == '*') ADVANCE(179);
      if (lookahead == '+') ADVANCE(174);
      if (lookahead == ',') ADVANCE(59);
      if (lookahead == '-') ADVANCE(178);
      if (lookahead == '.') ADVANCE(19);
      if (lookahead == '/') ADVANCE(181);
      if (lookahead == ':') ADVANCE(63);
      if (lookahead == ';') ADVANCE(160);
      if (lookahead == '<') ADVANCE(195);
      if (lookahead == '=') ADVANCE(56);
      if (lookahead == '>') ADVANCE(191);
      if (lookahead == '?') ADVANCE(64);
      if (lookahead == '[') ADVANCE(57);
      if (lookahead == '\\') ADVANCE(41);
      if (lookahead == ']') ADVANCE(61);
      if (lookahead == '`') ADVANCE(134);
      if (lookahead == 'a') ADVANCE(114);
      if (lookahead == 'd') ADVANCE(110);
      if (lookahead == 'e') ADVANCE(121);
      if (lookahead == 'l') ADVANCE(111);
      if (lookahead == '{') ADVANCE(164);
      if (lookahead == '|') ADVANCE(91);
      if (lookahead == '}') ADVANCE(166);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(46)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(92);
      if (lookahead != 0) ADVANCE(123);
      END_STATE();
    case 47:
      if (eof) ADVANCE(48);
      if (lookahead == '#') ADVANCE(170);
      if (lookahead == '$') ADVANCE(139);
      if (lookahead == '(') ADVANCE(65);
      if (lookahead == ')') ADVANCE(66);
      if (lookahead == ',') ADVANCE(59);
      if (lookahead == '.') ADVANCE(21);
      if (lookahead == '=') ADVANCE(55);
      if (lookahead == '[') ADVANCE(57);
      if (lookahead == ']') ADVANCE(61);
      if (lookahead == 'a') ADVANCE(80);
      if (lookahead == 'd') ADVANCE(76);
      if (lookahead == 'e') ADVANCE(87);
      if (lookahead == 'l') ADVANCE(77);
      if (lookahead == '}') ADVANCE(166);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(47)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(92);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_export);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_export);
      if (lookahead == '?') ADVANCE(74);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(89);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_def);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_def);
      if (lookahead == '?') ADVANCE(74);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(89);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_alias);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_alias);
      if (lookahead == '?') ADVANCE(74);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(89);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '~') ADVANCE(187);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      if (lookahead == '.') ADVANCE(25);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_COMMA);
      if (lookahead == '.') ADVANCE(25);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      if (lookahead == '.') ADVANCE(25);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_QMARK);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      if (lookahead == '.') ADVANCE(25);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_flag_name);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(69);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(68);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_flag_name);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(69);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_flag_shorthand_name);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_DOT_DOT_DOTrest);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_let);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_let);
      if (lookahead == '?') ADVANCE(74);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(89);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_cmd_name);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_cmd_name);
      if (lookahead == '?') ADVANCE(74);
      if (lookahead == 'a') ADVANCE(84);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(89);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_cmd_name);
      if (lookahead == '?') ADVANCE(74);
      if (lookahead == 'e') ADVANCE(78);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(89);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_cmd_name);
      if (lookahead == '?') ADVANCE(74);
      if (lookahead == 'e') ADVANCE(85);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(89);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_cmd_name);
      if (lookahead == '?') ADVANCE(74);
      if (lookahead == 'f') ADVANCE(52);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(89);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_cmd_name);
      if (lookahead == '?') ADVANCE(74);
      if (lookahead == 'i') ADVANCE(75);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(89);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_cmd_name);
      if (lookahead == '?') ADVANCE(74);
      if (lookahead == 'l') ADVANCE(79);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(89);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_cmd_name);
      if (lookahead == '?') ADVANCE(74);
      if (lookahead == 'o') ADVANCE(83);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(89);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_cmd_name);
      if (lookahead == '?') ADVANCE(74);
      if (lookahead == 'p') ADVANCE(81);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(89);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_cmd_name);
      if (lookahead == '?') ADVANCE(74);
      if (lookahead == 'r') ADVANCE(86);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(89);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_cmd_name);
      if (lookahead == '?') ADVANCE(74);
      if (lookahead == 's') ADVANCE(54);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(89);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym_cmd_name);
      if (lookahead == '?') ADVANCE(74);
      if (lookahead == 't') ADVANCE(73);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(89);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym_cmd_name);
      if (lookahead == '?') ADVANCE(74);
      if (lookahead == 't') ADVANCE(50);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(89);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(sym_cmd_name);
      if (lookahead == '?') ADVANCE(74);
      if (lookahead == 'x') ADVANCE(82);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(89);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym_cmd_name);
      if (lookahead == '?') ADVANCE(74);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9')) ADVANCE(89);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym_cmd_name);
      if (lookahead == '?') ADVANCE(74);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(89);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '.') ADVANCE(25);
      if (lookahead == '|') ADVANCE(185);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '|') ADVANCE(185);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym_number_literal);
      if (lookahead == '.') ADVANCE(97);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(92);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym_number_literal);
      if (lookahead == '.') ADVANCE(22);
      if (lookahead == '/') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(93);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(149);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym_number_literal);
      if (lookahead == '.') ADVANCE(93);
      if (lookahead == '/') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(100);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym_number_literal);
      if (lookahead == '.') ADVANCE(96);
      if (lookahead == '/') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(100);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym_number_literal);
      if (lookahead == '.') ADVANCE(145);
      if (lookahead == '/') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(93);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(149);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym_number_literal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(97);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '&') ADVANCE(186);
      if (lookahead == '.') ADVANCE(25);
      if (lookahead == '\\') ADVANCE(41);
      if (!sym_word_character_set_2(lookahead)) ADVANCE(123);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '&') ADVANCE(186);
      if (lookahead == '\\') ADVANCE(41);
      if (!sym_word_character_set_3(lookahead)) ADVANCE(123);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '.') ADVANCE(22);
      if (lookahead == '/') ADVANCE(102);
      if (lookahead == '\\') ADVANCE(41);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(100);
      if (!sym_word_character_set_4(lookahead)) ADVANCE(123);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '.') ADVANCE(144);
      if (lookahead == '\\') ADVANCE(41);
      if (!sym_word_character_set_2(lookahead)) ADVANCE(123);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '.') ADVANCE(23);
      if (lookahead == '\\') ADVANCE(41);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(100);
      if (!sym_word_character_set_4(lookahead)) ADVANCE(123);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '.') ADVANCE(25);
      if (lookahead == '=') ADVANCE(189);
      if (lookahead == '\\') ADVANCE(41);
      if (!sym_word_character_set_2(lookahead)) ADVANCE(123);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '.') ADVANCE(25);
      if (lookahead == '=') ADVANCE(188);
      if (lookahead == '\\') ADVANCE(41);
      if (lookahead == '~') ADVANCE(187);
      if (!sym_word_character_set_2(lookahead)) ADVANCE(123);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '.') ADVANCE(25);
      if (lookahead == '\\') ADVANCE(41);
      if (lookahead == '|') ADVANCE(185);
      if (!sym_word_character_set_5(lookahead)) ADVANCE(123);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '.') ADVANCE(25);
      if (lookahead == '\\') ADVANCE(41);
      if (!sym_word_character_set_2(lookahead)) ADVANCE(123);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '=') ADVANCE(189);
      if (lookahead == '\\') ADVANCE(41);
      if (!sym_word_character_set_3(lookahead)) ADVANCE(123);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '=') ADVANCE(188);
      if (lookahead == '\\') ADVANCE(41);
      if (lookahead == '~') ADVANCE(187);
      if (!sym_word_character_set_3(lookahead)) ADVANCE(123);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(41);
      if (lookahead == 'a') ADVANCE(118);
      if (!sym_word_character_set_3(lookahead)) ADVANCE(123);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(41);
      if (lookahead == 'e') ADVANCE(112);
      if (!sym_word_character_set_3(lookahead)) ADVANCE(123);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(41);
      if (lookahead == 'e') ADVANCE(119);
      if (!sym_word_character_set_3(lookahead)) ADVANCE(123);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(41);
      if (lookahead == 'f') ADVANCE(51);
      if (!sym_word_character_set_3(lookahead)) ADVANCE(123);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(41);
      if (lookahead == 'i') ADVANCE(109);
      if (!sym_word_character_set_3(lookahead)) ADVANCE(123);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(41);
      if (lookahead == 'l') ADVANCE(113);
      if (!sym_word_character_set_3(lookahead)) ADVANCE(123);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(41);
      if (lookahead == 'o') ADVANCE(117);
      if (!sym_word_character_set_3(lookahead)) ADVANCE(123);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(41);
      if (lookahead == 'p') ADVANCE(115);
      if (!sym_word_character_set_3(lookahead)) ADVANCE(123);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(41);
      if (lookahead == 'r') ADVANCE(120);
      if (!sym_word_character_set_3(lookahead)) ADVANCE(123);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(41);
      if (lookahead == 's') ADVANCE(53);
      if (!sym_word_character_set_3(lookahead)) ADVANCE(123);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(41);
      if (lookahead == 't') ADVANCE(72);
      if (!sym_word_character_set_3(lookahead)) ADVANCE(123);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(41);
      if (lookahead == 't') ADVANCE(49);
      if (!sym_word_character_set_3(lookahead)) ADVANCE(123);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(41);
      if (lookahead == 'x') ADVANCE(116);
      if (!sym_word_character_set_3(lookahead)) ADVANCE(123);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(41);
      if (lookahead == '|') ADVANCE(185);
      if (!sym_word_character_set_6(lookahead)) ADVANCE(123);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_word);
      if (lookahead == '\\') ADVANCE(41);
      if (!sym_word_character_set_3(lookahead)) ADVANCE(123);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      if (lookahead == '.') ADVANCE(25);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '\n') ADVANCE(128);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(126);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '#') ADVANCE(126);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(127);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(128);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(128);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      if (lookahead == '.') ADVANCE(25);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(aux_sym_string_token2);
      if (lookahead == '\n') ADVANCE(133);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(131);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(aux_sym_string_token2);
      if (lookahead == '#') ADVANCE(131);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(132);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(133);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(aux_sym_string_token2);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(133);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      if (lookahead == '.') ADVANCE(25);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(aux_sym_string_token3);
      if (lookahead == '\n') ADVANCE(138);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(136);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(aux_sym_string_token3);
      if (lookahead == '#') ADVANCE(136);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(138);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(aux_sym_string_token3);
      if (lookahead != 0 &&
          lookahead != '`') ADVANCE(138);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      if (lookahead == '(') ADVANCE(154);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      if (lookahead == '(') ADVANCE(154);
      if (lookahead == '.') ADVANCE(25);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(anon_sym_DOT);
      if (lookahead == '.') ADVANCE(151);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(anon_sym_DOT);
      if (lookahead == '.') ADVANCE(22);
      if (lookahead == '/') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(23);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(aux_sym_file_path_token1);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(aux_sym_file_path_token1);
      if (lookahead == '.') ADVANCE(22);
      if (lookahead == '/') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(149);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(aux_sym_file_path_token1);
      if (lookahead == '.') ADVANCE(22);
      if (lookahead == '/') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(23);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(aux_sym_file_path_token1);
      if (lookahead == '.') ADVANCE(145);
      if (lookahead == '/') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(149);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(aux_sym_file_path_token1);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(23);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(aux_sym_file_path_token2);
      if (lookahead == '.') ADVANCE(22);
      if (lookahead == '/') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(149);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_DOT_DOT);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(anon_sym_DOT_DOT);
      if (lookahead == '.') ADVANCE(35);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(anon_sym_DOT_DOT);
      if (lookahead == '.') ADVANCE(22);
      if (lookahead == '/') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(149);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(anon_sym_DOT_DOT);
      if (lookahead == '.') ADVANCE(145);
      if (lookahead == '/') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(149);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(anon_sym_DOLLAR_LPAREN);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(39);
      if (lookahead == '.') ADVANCE(22);
      if (lookahead == '/') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(156);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(39);
      if (lookahead == '.') ADVANCE(22);
      if (lookahead == '/') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(156);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(39);
      if (lookahead == '.') ADVANCE(29);
      if (lookahead == '/') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(156);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(155);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(39);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(159);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(158);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '-') ADVANCE(39);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(159);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(anon_sym_SEMI);
      if (lookahead == '.') ADVANCE(25);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(anon_sym_);
      if (lookahead == ' ') ADVANCE(162);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') ADVANCE(4);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(anon_sym_);
      if (lookahead == ' ') ADVANCE(163);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      if (lookahead == '.') ADVANCE(25);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      if (lookahead == '.') ADVANCE(25);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead == '.') ADVANCE(144);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(170);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead == '.') ADVANCE(168);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(170);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(170);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(171);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(1);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(172);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(173);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(2);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '.') ADVANCE(25);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '-') ADVANCE(38);
      if (lookahead == '.') ADVANCE(25);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(70);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '-') ADVANCE(38);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(70);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '.') ADVANCE(25);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '.') ADVANCE(25);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '.') ADVANCE(25);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(anon_sym_EQ_TILDE);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(anon_sym_BANG_EQ);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '.') ADVANCE(25);
      if (lookahead == '=') ADVANCE(192);
      if (lookahead == '>') ADVANCE(197);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(192);
      if (lookahead == '>') ADVANCE(197);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '.') ADVANCE(25);
      if (lookahead == '<') ADVANCE(196);
      if (lookahead == '=') ADVANCE(193);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '<') ADVANCE(196);
      if (lookahead == '=') ADVANCE(193);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(anon_sym_LT_LT);
      END_STATE();
    case 197:
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
  [1] = {.lex_state = 47},
  [2] = {.lex_state = 42},
  [3] = {.lex_state = 3},
  [4] = {.lex_state = 42},
  [5] = {.lex_state = 42},
  [6] = {.lex_state = 3},
  [7] = {.lex_state = 3},
  [8] = {.lex_state = 3},
  [9] = {.lex_state = 42},
  [10] = {.lex_state = 3},
  [11] = {.lex_state = 3},
  [12] = {.lex_state = 42},
  [13] = {.lex_state = 42},
  [14] = {.lex_state = 3},
  [15] = {.lex_state = 8},
  [16] = {.lex_state = 8},
  [17] = {.lex_state = 8},
  [18] = {.lex_state = 42},
  [19] = {.lex_state = 42},
  [20] = {.lex_state = 42},
  [21] = {.lex_state = 42},
  [22] = {.lex_state = 42},
  [23] = {.lex_state = 42},
  [24] = {.lex_state = 42},
  [25] = {.lex_state = 45},
  [26] = {.lex_state = 45},
  [27] = {.lex_state = 42},
  [28] = {.lex_state = 42},
  [29] = {.lex_state = 42},
  [30] = {.lex_state = 42},
  [31] = {.lex_state = 42},
  [32] = {.lex_state = 42},
  [33] = {.lex_state = 42},
  [34] = {.lex_state = 42},
  [35] = {.lex_state = 42},
  [36] = {.lex_state = 42},
  [37] = {.lex_state = 42},
  [38] = {.lex_state = 42},
  [39] = {.lex_state = 42},
  [40] = {.lex_state = 42},
  [41] = {.lex_state = 42},
  [42] = {.lex_state = 42},
  [43] = {.lex_state = 42},
  [44] = {.lex_state = 42},
  [45] = {.lex_state = 42},
  [46] = {.lex_state = 42},
  [47] = {.lex_state = 42},
  [48] = {.lex_state = 42},
  [49] = {.lex_state = 42},
  [50] = {.lex_state = 42},
  [51] = {.lex_state = 42},
  [52] = {.lex_state = 42},
  [53] = {.lex_state = 42},
  [54] = {.lex_state = 47},
  [55] = {.lex_state = 47},
  [56] = {.lex_state = 47},
  [57] = {.lex_state = 47},
  [58] = {.lex_state = 47},
  [59] = {.lex_state = 47},
  [60] = {.lex_state = 47},
  [61] = {.lex_state = 47},
  [62] = {.lex_state = 47},
  [63] = {.lex_state = 47},
  [64] = {.lex_state = 47},
  [65] = {.lex_state = 47},
  [66] = {.lex_state = 43},
  [67] = {.lex_state = 47},
  [68] = {.lex_state = 43},
  [69] = {.lex_state = 43},
  [70] = {.lex_state = 47},
  [71] = {.lex_state = 47},
  [72] = {.lex_state = 47},
  [73] = {.lex_state = 47},
  [74] = {.lex_state = 43},
  [75] = {.lex_state = 43},
  [76] = {.lex_state = 43},
  [77] = {.lex_state = 43},
  [78] = {.lex_state = 43},
  [79] = {.lex_state = 43},
  [80] = {.lex_state = 43},
  [81] = {.lex_state = 43},
  [82] = {.lex_state = 43},
  [83] = {.lex_state = 43},
  [84] = {.lex_state = 43},
  [85] = {.lex_state = 43},
  [86] = {.lex_state = 43},
  [87] = {.lex_state = 43},
  [88] = {.lex_state = 43},
  [89] = {.lex_state = 43},
  [90] = {.lex_state = 43},
  [91] = {.lex_state = 43},
  [92] = {.lex_state = 9},
  [93] = {.lex_state = 9},
  [94] = {.lex_state = 9},
  [95] = {.lex_state = 9},
  [96] = {.lex_state = 9},
  [97] = {.lex_state = 9},
  [98] = {.lex_state = 9},
  [99] = {.lex_state = 9},
  [100] = {.lex_state = 9},
  [101] = {.lex_state = 9},
  [102] = {.lex_state = 11},
  [103] = {.lex_state = 11},
  [104] = {.lex_state = 11},
  [105] = {.lex_state = 11},
  [106] = {.lex_state = 11},
  [107] = {.lex_state = 11},
  [108] = {.lex_state = 11},
  [109] = {.lex_state = 11},
  [110] = {.lex_state = 11},
  [111] = {.lex_state = 11},
  [112] = {.lex_state = 0},
  [113] = {.lex_state = 47},
  [114] = {.lex_state = 47},
  [115] = {.lex_state = 0},
  [116] = {.lex_state = 0},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 0},
  [122] = {.lex_state = 47},
  [123] = {.lex_state = 0},
  [124] = {.lex_state = 0},
  [125] = {.lex_state = 0},
  [126] = {.lex_state = 0},
  [127] = {.lex_state = 0},
  [128] = {.lex_state = 0},
  [129] = {.lex_state = 0},
  [130] = {.lex_state = 0},
  [131] = {.lex_state = 0},
  [132] = {.lex_state = 0},
  [133] = {.lex_state = 47},
  [134] = {.lex_state = 14},
  [135] = {.lex_state = 14},
  [136] = {.lex_state = 14},
  [137] = {.lex_state = 47},
  [138] = {.lex_state = 14},
  [139] = {.lex_state = 13},
  [140] = {.lex_state = 13},
  [141] = {.lex_state = 13},
  [142] = {.lex_state = 13},
  [143] = {.lex_state = 13},
  [144] = {.lex_state = 43},
  [145] = {.lex_state = 43},
  [146] = {.lex_state = 13},
  [147] = {.lex_state = 43},
  [148] = {.lex_state = 43},
  [149] = {.lex_state = 43},
  [150] = {.lex_state = 43},
  [151] = {.lex_state = 43},
  [152] = {.lex_state = 43},
  [153] = {.lex_state = 43},
  [154] = {.lex_state = 13},
  [155] = {.lex_state = 13},
  [156] = {.lex_state = 13},
  [157] = {.lex_state = 13},
  [158] = {.lex_state = 5},
  [159] = {.lex_state = 13},
  [160] = {.lex_state = 13},
  [161] = {.lex_state = 43},
  [162] = {.lex_state = 13},
  [163] = {.lex_state = 5},
  [164] = {.lex_state = 43},
  [165] = {.lex_state = 43},
  [166] = {.lex_state = 5},
  [167] = {.lex_state = 13},
  [168] = {.lex_state = 13},
  [169] = {.lex_state = 5},
  [170] = {.lex_state = 13},
  [171] = {.lex_state = 13},
  [172] = {.lex_state = 0},
  [173] = {.lex_state = 0},
  [174] = {.lex_state = 43},
  [175] = {.lex_state = 43},
  [176] = {.lex_state = 5},
  [177] = {.lex_state = 5},
  [178] = {.lex_state = 5},
  [179] = {.lex_state = 5},
  [180] = {.lex_state = 5},
  [181] = {.lex_state = 0},
  [182] = {.lex_state = 6},
  [183] = {.lex_state = 5},
  [184] = {.lex_state = 5},
  [185] = {.lex_state = 5},
  [186] = {.lex_state = 5},
  [187] = {.lex_state = 0},
  [188] = {.lex_state = 0},
  [189] = {.lex_state = 5},
  [190] = {.lex_state = 5},
  [191] = {.lex_state = 5},
  [192] = {.lex_state = 0},
  [193] = {.lex_state = 0},
  [194] = {.lex_state = 0},
  [195] = {.lex_state = 5},
  [196] = {.lex_state = 5},
  [197] = {.lex_state = 0},
  [198] = {.lex_state = 5},
  [199] = {.lex_state = 0},
  [200] = {.lex_state = 5},
  [201] = {.lex_state = 13},
  [202] = {.lex_state = 5},
  [203] = {.lex_state = 0},
  [204] = {.lex_state = 5},
  [205] = {.lex_state = 5},
  [206] = {.lex_state = 5},
  [207] = {.lex_state = 0},
  [208] = {.lex_state = 5},
  [209] = {.lex_state = 47},
  [210] = {.lex_state = 5},
  [211] = {.lex_state = 5},
  [212] = {.lex_state = 5},
  [213] = {.lex_state = 5},
  [214] = {.lex_state = 5},
  [215] = {.lex_state = 5},
  [216] = {.lex_state = 5},
  [217] = {.lex_state = 0},
  [218] = {.lex_state = 0},
  [219] = {.lex_state = 5},
  [220] = {.lex_state = 5},
  [221] = {.lex_state = 5},
  [222] = {.lex_state = 0},
  [223] = {.lex_state = 5},
  [224] = {.lex_state = 5},
  [225] = {.lex_state = 0},
  [226] = {.lex_state = 0},
  [227] = {.lex_state = 0},
  [228] = {.lex_state = 0},
  [229] = {.lex_state = 0},
  [230] = {.lex_state = 0},
  [231] = {.lex_state = 0},
  [232] = {.lex_state = 0},
  [233] = {.lex_state = 0},
  [234] = {.lex_state = 0},
  [235] = {.lex_state = 0},
  [236] = {.lex_state = 13},
  [237] = {.lex_state = 0},
  [238] = {.lex_state = 0},
  [239] = {.lex_state = 0},
  [240] = {.lex_state = 0},
  [241] = {.lex_state = 0},
  [242] = {.lex_state = 0},
  [243] = {.lex_state = 0},
  [244] = {.lex_state = 0},
  [245] = {.lex_state = 13},
  [246] = {.lex_state = 0},
  [247] = {.lex_state = 47},
  [248] = {.lex_state = 0},
  [249] = {.lex_state = 0},
  [250] = {.lex_state = 0},
  [251] = {.lex_state = 0},
  [252] = {.lex_state = 0},
  [253] = {.lex_state = 0},
  [254] = {.lex_state = 0},
  [255] = {.lex_state = 0},
  [256] = {.lex_state = 0},
  [257] = {.lex_state = 13},
  [258] = {.lex_state = 0},
  [259] = {.lex_state = 13},
  [260] = {.lex_state = 13},
  [261] = {.lex_state = 16},
  [262] = {.lex_state = 0},
  [263] = {.lex_state = 0},
  [264] = {.lex_state = 0},
  [265] = {.lex_state = 0},
  [266] = {.lex_state = 47},
  [267] = {.lex_state = 0},
  [268] = {.lex_state = 0},
  [269] = {.lex_state = 13},
  [270] = {.lex_state = 0},
  [271] = {.lex_state = 17},
  [272] = {.lex_state = 0},
  [273] = {.lex_state = 0},
  [274] = {.lex_state = 13},
  [275] = {.lex_state = 13},
  [276] = {.lex_state = 0},
  [277] = {.lex_state = 13},
  [278] = {.lex_state = 0},
  [279] = {.lex_state = 0},
  [280] = {.lex_state = 0},
  [281] = {.lex_state = 0},
  [282] = {.lex_state = 0},
  [283] = {.lex_state = 13},
  [284] = {.lex_state = 0},
  [285] = {.lex_state = 13},
  [286] = {.lex_state = 0},
  [287] = {.lex_state = 47},
  [288] = {.lex_state = 15},
  [289] = {.lex_state = 17},
  [290] = {.lex_state = 17},
  [291] = {.lex_state = 132},
  [292] = {.lex_state = 16},
  [293] = {.lex_state = 0},
  [294] = {.lex_state = 132},
  [295] = {.lex_state = 17},
  [296] = {.lex_state = 132},
  [297] = {.lex_state = 16},
  [298] = {.lex_state = 0},
  [299] = {.lex_state = 13},
  [300] = {.lex_state = 17},
  [301] = {.lex_state = 132},
  [302] = {.lex_state = 16},
  [303] = {.lex_state = 0},
  [304] = {.lex_state = 0},
  [305] = {.lex_state = 13},
  [306] = {.lex_state = 132},
  [307] = {.lex_state = 16},
  [308] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_word] = ACTIONS(1),
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
    [anon_sym_PIPE] = ACTIONS(1),
    [sym_number_literal] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_BQUOTE] = ACTIONS(1),
    [anon_sym_DOLLAR] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
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
    [sym_source_file] = STATE(273),
    [sym__statements] = STATE(258),
    [sym__statement] = STATE(161),
    [sym_function_definition] = STATE(161),
    [sym_alias] = STATE(161),
    [sym_variable_declaration] = STATE(161),
    [sym_command] = STATE(161),
    [sym_pipeline] = STATE(161),
    [sym_value_path] = STATE(91),
    [sym_command_substitution] = STATE(91),
    [sym_math_mode] = STATE(161),
    [sym_table] = STATE(91),
    [sym_array] = STATE(91),
    [sym__math_expression] = STATE(91),
    [sym_parenthesized_math_expression] = STATE(91),
    [sym_binary_expression] = STATE(91),
    [aux_sym__statements_repeat1] = STATE(67),
    [ts_builtin_sym_end] = ACTIONS(5),
    [anon_sym_export] = ACTIONS(7),
    [anon_sym_def] = ACTIONS(9),
    [anon_sym_alias] = ACTIONS(11),
    [anon_sym_EQ] = ACTIONS(13),
    [anon_sym_LBRACK] = ACTIONS(15),
    [anon_sym_LPAREN] = ACTIONS(17),
    [anon_sym_let] = ACTIONS(19),
    [sym_cmd_name] = ACTIONS(21),
    [sym_number_literal] = ACTIONS(23),
    [anon_sym_DOLLAR] = ACTIONS(25),
    [anon_sym_DOLLAR_LPAREN] = ACTIONS(27),
    [sym_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 16,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(35), 1,
      sym_number_literal,
    ACTIONS(37), 1,
      anon_sym_DQUOTE,
    ACTIONS(39), 1,
      anon_sym_SQUOTE,
    ACTIONS(41), 1,
      anon_sym_BQUOTE,
    ACTIONS(43), 1,
      anon_sym_DOLLAR,
    ACTIONS(47), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(49), 1,
      anon_sym_LBRACE,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(53), 1,
      anon_sym_LF,
    STATE(5), 1,
      aux_sym_command_repeat1,
    ACTIONS(45), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(29), 4,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_word,
      sym_identifier,
    ACTIONS(33), 4,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
    STATE(40), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_block,
      sym_operator,
    ACTIONS(55), 18,
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
  [83] = 19,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(59), 1,
      anon_sym_LBRACK,
    ACTIONS(61), 1,
      anon_sym_COMMA,
    ACTIONS(63), 1,
      anon_sym_RBRACK,
    ACTIONS(65), 1,
      sym_number_literal,
    ACTIONS(67), 1,
      anon_sym_DQUOTE,
    ACTIONS(69), 1,
      anon_sym_SQUOTE,
    ACTIONS(71), 1,
      anon_sym_BQUOTE,
    ACTIONS(73), 1,
      anon_sym_DOLLAR,
    ACTIONS(77), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(79), 1,
      anon_sym_,
    ACTIONS(81), 1,
      anon_sym_LBRACE,
    STATE(176), 1,
      aux_sym_array_repeat1,
    STATE(222), 1,
      aux_sym_column_header_repeat1,
    STATE(293), 1,
      sym_column_header,
    ACTIONS(75), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(57), 4,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_word,
      sym_identifier,
    STATE(169), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_block,
      sym_operator,
    ACTIONS(83), 18,
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
  [172] = 16,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(88), 1,
      anon_sym_LBRACK,
    ACTIONS(93), 1,
      sym_number_literal,
    ACTIONS(96), 1,
      anon_sym_DQUOTE,
    ACTIONS(99), 1,
      anon_sym_SQUOTE,
    ACTIONS(102), 1,
      anon_sym_BQUOTE,
    ACTIONS(105), 1,
      anon_sym_DOLLAR,
    ACTIONS(111), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(114), 1,
      anon_sym_LBRACE,
    ACTIONS(117), 1,
      anon_sym_LF,
    STATE(4), 1,
      aux_sym_command_repeat1,
    ACTIONS(108), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(85), 4,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_word,
      sym_identifier,
    ACTIONS(91), 4,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
    STATE(40), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_block,
      sym_operator,
    ACTIONS(119), 18,
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
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(35), 1,
      sym_number_literal,
    ACTIONS(37), 1,
      anon_sym_DQUOTE,
    ACTIONS(39), 1,
      anon_sym_SQUOTE,
    ACTIONS(41), 1,
      anon_sym_BQUOTE,
    ACTIONS(43), 1,
      anon_sym_DOLLAR,
    ACTIONS(47), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(49), 1,
      anon_sym_LBRACE,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(124), 1,
      anon_sym_LF,
    STATE(4), 1,
      aux_sym_command_repeat1,
    ACTIONS(45), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(29), 4,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_word,
      sym_identifier,
    ACTIONS(122), 4,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
    STATE(40), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_block,
      sym_operator,
    ACTIONS(55), 18,
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
  [338] = 18,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(59), 1,
      anon_sym_LBRACK,
    ACTIONS(65), 1,
      sym_number_literal,
    ACTIONS(67), 1,
      anon_sym_DQUOTE,
    ACTIONS(69), 1,
      anon_sym_SQUOTE,
    ACTIONS(71), 1,
      anon_sym_BQUOTE,
    ACTIONS(73), 1,
      anon_sym_DOLLAR,
    ACTIONS(77), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(79), 1,
      anon_sym_,
    ACTIONS(81), 1,
      anon_sym_LBRACE,
    ACTIONS(128), 1,
      anon_sym_COMMA,
    ACTIONS(130), 1,
      anon_sym_RBRACK,
    STATE(176), 1,
      aux_sym_array_repeat1,
    STATE(293), 1,
      sym_column_header,
    ACTIONS(75), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(126), 4,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_word,
      sym_identifier,
    STATE(196), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_block,
      sym_operator,
    ACTIONS(83), 18,
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
  [424] = 18,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(59), 1,
      anon_sym_LBRACK,
    ACTIONS(65), 1,
      sym_number_literal,
    ACTIONS(67), 1,
      anon_sym_DQUOTE,
    ACTIONS(69), 1,
      anon_sym_SQUOTE,
    ACTIONS(71), 1,
      anon_sym_BQUOTE,
    ACTIONS(73), 1,
      anon_sym_DOLLAR,
    ACTIONS(77), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(79), 1,
      anon_sym_,
    ACTIONS(81), 1,
      anon_sym_LBRACE,
    ACTIONS(128), 1,
      anon_sym_COMMA,
    ACTIONS(134), 1,
      anon_sym_RBRACK,
    STATE(186), 1,
      aux_sym_array_repeat1,
    STATE(246), 1,
      sym_column_header,
    ACTIONS(75), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(132), 4,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_word,
      sym_identifier,
    STATE(183), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_block,
      sym_operator,
    ACTIONS(83), 18,
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
  [510] = 18,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(59), 1,
      anon_sym_LBRACK,
    ACTIONS(65), 1,
      sym_number_literal,
    ACTIONS(67), 1,
      anon_sym_DQUOTE,
    ACTIONS(69), 1,
      anon_sym_SQUOTE,
    ACTIONS(71), 1,
      anon_sym_BQUOTE,
    ACTIONS(73), 1,
      anon_sym_DOLLAR,
    ACTIONS(77), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(79), 1,
      anon_sym_,
    ACTIONS(81), 1,
      anon_sym_LBRACE,
    ACTIONS(128), 1,
      anon_sym_COMMA,
    ACTIONS(138), 1,
      anon_sym_RBRACK,
    STATE(190), 1,
      aux_sym_array_repeat1,
    STATE(308), 1,
      sym_column_header,
    ACTIONS(75), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(136), 4,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_word,
      sym_identifier,
    STATE(191), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_block,
      sym_operator,
    ACTIONS(83), 18,
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
  [596] = 16,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(142), 1,
      anon_sym_LBRACK,
    ACTIONS(144), 1,
      sym_number_literal,
    ACTIONS(146), 1,
      anon_sym_DQUOTE,
    ACTIONS(148), 1,
      anon_sym_SQUOTE,
    ACTIONS(150), 1,
      anon_sym_BQUOTE,
    ACTIONS(152), 1,
      anon_sym_DOLLAR,
    ACTIONS(156), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(158), 1,
      anon_sym_LBRACE,
    STATE(12), 1,
      aux_sym_command_repeat1,
    ACTIONS(33), 2,
      anon_sym_PIPE,
      anon_sym_SEMI,
    ACTIONS(53), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(154), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(140), 4,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_word,
      sym_identifier,
    STATE(48), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_block,
      sym_operator,
    ACTIONS(160), 18,
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
  [678] = 18,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(59), 1,
      anon_sym_LBRACK,
    ACTIONS(65), 1,
      sym_number_literal,
    ACTIONS(67), 1,
      anon_sym_DQUOTE,
    ACTIONS(69), 1,
      anon_sym_SQUOTE,
    ACTIONS(71), 1,
      anon_sym_BQUOTE,
    ACTIONS(73), 1,
      anon_sym_DOLLAR,
    ACTIONS(77), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(79), 1,
      anon_sym_,
    ACTIONS(81), 1,
      anon_sym_LBRACE,
    ACTIONS(128), 1,
      anon_sym_COMMA,
    ACTIONS(164), 1,
      anon_sym_RBRACK,
    STATE(195), 1,
      aux_sym_array_repeat1,
    STATE(303), 1,
      sym_column_header,
    ACTIONS(75), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(162), 4,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_word,
      sym_identifier,
    STATE(204), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_block,
      sym_operator,
    ACTIONS(83), 18,
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
  [764] = 18,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(59), 1,
      anon_sym_LBRACK,
    ACTIONS(65), 1,
      sym_number_literal,
    ACTIONS(67), 1,
      anon_sym_DQUOTE,
    ACTIONS(69), 1,
      anon_sym_SQUOTE,
    ACTIONS(71), 1,
      anon_sym_BQUOTE,
    ACTIONS(73), 1,
      anon_sym_DOLLAR,
    ACTIONS(77), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(79), 1,
      anon_sym_,
    ACTIONS(81), 1,
      anon_sym_LBRACE,
    ACTIONS(128), 1,
      anon_sym_COMMA,
    ACTIONS(168), 1,
      anon_sym_RBRACK,
    STATE(205), 1,
      aux_sym_array_repeat1,
    STATE(298), 1,
      sym_column_header,
    ACTIONS(75), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(166), 4,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_word,
      sym_identifier,
    STATE(177), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_block,
      sym_operator,
    ACTIONS(83), 18,
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
  [850] = 16,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(142), 1,
      anon_sym_LBRACK,
    ACTIONS(144), 1,
      sym_number_literal,
    ACTIONS(146), 1,
      anon_sym_DQUOTE,
    ACTIONS(148), 1,
      anon_sym_SQUOTE,
    ACTIONS(150), 1,
      anon_sym_BQUOTE,
    ACTIONS(152), 1,
      anon_sym_DOLLAR,
    ACTIONS(156), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(158), 1,
      anon_sym_LBRACE,
    STATE(13), 1,
      aux_sym_command_repeat1,
    ACTIONS(122), 2,
      anon_sym_PIPE,
      anon_sym_SEMI,
    ACTIONS(124), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(154), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(140), 4,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_word,
      sym_identifier,
    STATE(48), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_block,
      sym_operator,
    ACTIONS(160), 18,
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
  [932] = 16,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(173), 1,
      anon_sym_LBRACK,
    ACTIONS(176), 1,
      sym_number_literal,
    ACTIONS(179), 1,
      anon_sym_DQUOTE,
    ACTIONS(182), 1,
      anon_sym_SQUOTE,
    ACTIONS(185), 1,
      anon_sym_BQUOTE,
    ACTIONS(188), 1,
      anon_sym_DOLLAR,
    ACTIONS(194), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(197), 1,
      anon_sym_LBRACE,
    STATE(13), 1,
      aux_sym_command_repeat1,
    ACTIONS(91), 2,
      anon_sym_PIPE,
      anon_sym_SEMI,
    ACTIONS(117), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(191), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(170), 4,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_word,
      sym_identifier,
    STATE(48), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_block,
      sym_operator,
    ACTIONS(200), 18,
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
  [1014] = 17,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_number_literal,
    ACTIONS(67), 1,
      anon_sym_DQUOTE,
    ACTIONS(69), 1,
      anon_sym_SQUOTE,
    ACTIONS(71), 1,
      anon_sym_BQUOTE,
    ACTIONS(73), 1,
      anon_sym_DOLLAR,
    ACTIONS(77), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(79), 1,
      anon_sym_,
    ACTIONS(81), 1,
      anon_sym_LBRACE,
    ACTIONS(128), 1,
      anon_sym_COMMA,
    ACTIONS(168), 1,
      anon_sym_RBRACK,
    ACTIONS(203), 1,
      anon_sym_LBRACK,
    STATE(205), 1,
      aux_sym_array_repeat1,
    ACTIONS(75), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(166), 4,
      sym_flag_name,
      sym_flag_shorthand_name,
      sym_word,
      sym_identifier,
    STATE(177), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_block,
      sym_operator,
    ACTIONS(83), 18,
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
  [1097] = 15,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(207), 1,
      anon_sym_LBRACK,
    ACTIONS(211), 1,
      sym_number_literal,
    ACTIONS(213), 1,
      anon_sym_DQUOTE,
    ACTIONS(215), 1,
      anon_sym_SQUOTE,
    ACTIONS(217), 1,
      anon_sym_BQUOTE,
    ACTIONS(219), 1,
      anon_sym_DOLLAR,
    ACTIONS(223), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(225), 1,
      anon_sym_LBRACE,
    ACTIONS(205), 2,
      sym_word,
      sym_identifier,
    ACTIONS(209), 2,
      sym_flag_name,
      sym_flag_shorthand_name,
    ACTIONS(221), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(227), 9,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(229), 9,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    STATE(231), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_block,
      sym_operator,
  [1172] = 15,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_number_literal,
    ACTIONS(67), 1,
      anon_sym_DQUOTE,
    ACTIONS(69), 1,
      anon_sym_SQUOTE,
    ACTIONS(71), 1,
      anon_sym_BQUOTE,
    ACTIONS(73), 1,
      anon_sym_DOLLAR,
    ACTIONS(81), 1,
      anon_sym_LBRACE,
    ACTIONS(203), 1,
      anon_sym_LBRACK,
    ACTIONS(235), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(75), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(231), 2,
      sym_word,
      sym_identifier,
    ACTIONS(233), 2,
      sym_flag_name,
      sym_flag_shorthand_name,
    ACTIONS(83), 9,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(237), 9,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    STATE(221), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_block,
      sym_operator,
  [1247] = 15,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(65), 1,
      sym_number_literal,
    ACTIONS(67), 1,
      anon_sym_DQUOTE,
    ACTIONS(69), 1,
      anon_sym_SQUOTE,
    ACTIONS(71), 1,
      anon_sym_BQUOTE,
    ACTIONS(73), 1,
      anon_sym_DOLLAR,
    ACTIONS(81), 1,
      anon_sym_LBRACE,
    ACTIONS(203), 1,
      anon_sym_LBRACK,
    ACTIONS(235), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(75), 2,
      aux_sym_file_path_token1,
      aux_sym_file_path_token2,
    ACTIONS(239), 2,
      sym_word,
      sym_identifier,
    ACTIONS(241), 2,
      sym_flag_name,
      sym_flag_shorthand_name,
    ACTIONS(83), 9,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
      anon_sym_in,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(237), 9,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    STATE(223), 11,
      sym__expression,
      sym_string,
      sym_value_path,
      sym_file_path,
      sym__flag_arg,
      sym_range,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym_block,
      sym_operator,
  [1322] = 5,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(245), 1,
      anon_sym_DOT,
    ACTIONS(247), 1,
      anon_sym_LF,
    STATE(19), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(243), 36,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
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
  [1373] = 5,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(251), 1,
      anon_sym_DOT,
    ACTIONS(254), 1,
      anon_sym_LF,
    STATE(19), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(249), 36,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
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
  [1424] = 5,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(245), 1,
      anon_sym_DOT,
    ACTIONS(258), 1,
      anon_sym_LF,
    STATE(18), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(256), 36,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
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
  [1475] = 5,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(260), 1,
      anon_sym_DOT,
    STATE(22), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(258), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(256), 34,
      anon_sym_LBRACK,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
      anon_sym_LBRACE,
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
  [1525] = 5,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(260), 1,
      anon_sym_DOT,
    STATE(24), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(247), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(243), 34,
      anon_sym_LBRACK,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
      anon_sym_LBRACE,
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
  [1575] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(254), 1,
      anon_sym_LF,
    ACTIONS(249), 37,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
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
  [1621] = 5,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(262), 1,
      anon_sym_DOT,
    STATE(24), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(254), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(249), 34,
      anon_sym_LBRACK,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
      anon_sym_LBRACE,
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
  [1671] = 4,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(267), 1,
      anon_sym_DOT_DOT,
    ACTIONS(269), 1,
      anon_sym_LF,
    ACTIONS(265), 36,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
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
  [1719] = 4,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(271), 1,
      anon_sym_DOT_DOT,
    ACTIONS(269), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(265), 34,
      anon_sym_LBRACK,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
      anon_sym_LBRACE,
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
  [1766] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(275), 1,
      anon_sym_LF,
    ACTIONS(273), 36,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
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
  [1811] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(279), 1,
      anon_sym_LF,
    ACTIONS(277), 36,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
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
  [1856] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(283), 1,
      anon_sym_LF,
    ACTIONS(281), 36,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
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
  [1901] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(287), 1,
      anon_sym_LF,
    ACTIONS(285), 36,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
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
  [1946] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(291), 1,
      anon_sym_LF,
    ACTIONS(289), 36,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
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
  [1991] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(295), 1,
      anon_sym_LF,
    ACTIONS(293), 36,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
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
  [2036] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(254), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(249), 35,
      anon_sym_LBRACK,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
      anon_sym_LBRACE,
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
  [2081] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(299), 1,
      anon_sym_LF,
    ACTIONS(297), 36,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
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
  [2126] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(303), 1,
      anon_sym_LF,
    ACTIONS(301), 36,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
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
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(307), 1,
      anon_sym_LF,
    ACTIONS(305), 36,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
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
  [2216] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(311), 1,
      anon_sym_LF,
    ACTIONS(309), 36,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
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
  [2261] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(315), 1,
      anon_sym_LF,
    ACTIONS(313), 36,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
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
  [2306] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(319), 1,
      anon_sym_LF,
    ACTIONS(317), 36,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
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
  [2351] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(323), 1,
      anon_sym_LF,
    ACTIONS(321), 36,
      anon_sym_LBRACK,
      anon_sym_RPAREN,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
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
  [2396] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(295), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(293), 34,
      anon_sym_LBRACK,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
      anon_sym_LBRACE,
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
  [2440] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(319), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(317), 34,
      anon_sym_LBRACK,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
      anon_sym_LBRACE,
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
  [2484] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(275), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(273), 34,
      anon_sym_LBRACK,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
      anon_sym_LBRACE,
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
  [2528] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(291), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(289), 34,
      anon_sym_LBRACK,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
      anon_sym_LBRACE,
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
  [2572] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(283), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(281), 34,
      anon_sym_LBRACK,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
      anon_sym_LBRACE,
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
  [2616] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(299), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(297), 34,
      anon_sym_LBRACK,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
      anon_sym_LBRACE,
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
  [2660] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(315), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(313), 34,
      anon_sym_LBRACK,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
      anon_sym_LBRACE,
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
  [2704] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(323), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(321), 34,
      anon_sym_LBRACK,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
      anon_sym_LBRACE,
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
  [2748] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(303), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(301), 34,
      anon_sym_LBRACK,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
      anon_sym_LBRACE,
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
  [2792] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(307), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(305), 34,
      anon_sym_LBRACK,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
      anon_sym_LBRACE,
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
  [2836] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(311), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(309), 34,
      anon_sym_LBRACK,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
      anon_sym_LBRACE,
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
  [2880] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(279), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(277), 34,
      anon_sym_LBRACK,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
      anon_sym_LBRACE,
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
  [2924] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(287), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(285), 34,
      anon_sym_LBRACK,
      sym_flag_name,
      sym_flag_shorthand_name,
      anon_sym_PIPE,
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
      anon_sym_SEMI,
      anon_sym_LBRACE,
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
  [2968] = 17,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_export,
    ACTIONS(9), 1,
      anon_sym_def,
    ACTIONS(13), 1,
      anon_sym_EQ,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(23), 1,
      sym_number_literal,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(27), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(325), 1,
      anon_sym_alias,
    ACTIONS(327), 1,
      sym_cmd_name,
    ACTIONS(329), 1,
      anon_sym_RBRACE,
    STATE(65), 1,
      aux_sym__statements_repeat1,
    STATE(255), 1,
      sym__statements,
    STATE(91), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(152), 7,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_math_mode,
  [3032] = 17,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_export,
    ACTIONS(9), 1,
      anon_sym_def,
    ACTIONS(13), 1,
      anon_sym_EQ,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(23), 1,
      sym_number_literal,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(27), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(325), 1,
      anon_sym_alias,
    ACTIONS(327), 1,
      sym_cmd_name,
    ACTIONS(331), 1,
      anon_sym_RBRACE,
    STATE(65), 1,
      aux_sym__statements_repeat1,
    STATE(282), 1,
      sym__statements,
    STATE(91), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(152), 7,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_math_mode,
  [3096] = 17,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_export,
    ACTIONS(9), 1,
      anon_sym_def,
    ACTIONS(13), 1,
      anon_sym_EQ,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(23), 1,
      sym_number_literal,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(27), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(325), 1,
      anon_sym_alias,
    ACTIONS(327), 1,
      sym_cmd_name,
    ACTIONS(333), 1,
      anon_sym_RBRACE,
    STATE(65), 1,
      aux_sym__statements_repeat1,
    STATE(268), 1,
      sym__statements,
    STATE(91), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(152), 7,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_math_mode,
  [3160] = 17,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_export,
    ACTIONS(9), 1,
      anon_sym_def,
    ACTIONS(13), 1,
      anon_sym_EQ,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(23), 1,
      sym_number_literal,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(27), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(325), 1,
      anon_sym_alias,
    ACTIONS(327), 1,
      sym_cmd_name,
    ACTIONS(335), 1,
      anon_sym_RBRACE,
    STATE(65), 1,
      aux_sym__statements_repeat1,
    STATE(241), 1,
      sym__statements,
    STATE(91), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(152), 7,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_math_mode,
  [3224] = 17,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_export,
    ACTIONS(9), 1,
      anon_sym_def,
    ACTIONS(13), 1,
      anon_sym_EQ,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(23), 1,
      sym_number_literal,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(27), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(325), 1,
      anon_sym_alias,
    ACTIONS(327), 1,
      sym_cmd_name,
    ACTIONS(337), 1,
      anon_sym_RBRACE,
    STATE(65), 1,
      aux_sym__statements_repeat1,
    STATE(254), 1,
      sym__statements,
    STATE(91), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(152), 7,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_math_mode,
  [3288] = 16,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_export,
    ACTIONS(9), 1,
      anon_sym_def,
    ACTIONS(13), 1,
      anon_sym_EQ,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(23), 1,
      sym_number_literal,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(27), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(325), 1,
      anon_sym_alias,
    ACTIONS(327), 1,
      sym_cmd_name,
    STATE(65), 1,
      aux_sym__statements_repeat1,
    STATE(248), 1,
      sym__statements,
    STATE(91), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(152), 7,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_math_mode,
  [3349] = 16,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_export,
    ACTIONS(9), 1,
      anon_sym_def,
    ACTIONS(13), 1,
      anon_sym_EQ,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(23), 1,
      sym_number_literal,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(27), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(325), 1,
      anon_sym_alias,
    ACTIONS(327), 1,
      sym_cmd_name,
    STATE(65), 1,
      aux_sym__statements_repeat1,
    STATE(272), 1,
      sym__statements,
    STATE(91), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(152), 7,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_math_mode,
  [3410] = 16,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_export,
    ACTIONS(9), 1,
      anon_sym_def,
    ACTIONS(13), 1,
      anon_sym_EQ,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(23), 1,
      sym_number_literal,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(27), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(325), 1,
      anon_sym_alias,
    ACTIONS(327), 1,
      sym_cmd_name,
    STATE(65), 1,
      aux_sym__statements_repeat1,
    STATE(249), 1,
      sym__statements,
    STATE(91), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(152), 7,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_math_mode,
  [3471] = 16,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_export,
    ACTIONS(9), 1,
      anon_sym_def,
    ACTIONS(13), 1,
      anon_sym_EQ,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(23), 1,
      sym_number_literal,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(27), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(325), 1,
      anon_sym_alias,
    ACTIONS(327), 1,
      sym_cmd_name,
    STATE(65), 1,
      aux_sym__statements_repeat1,
    STATE(278), 1,
      sym__statements,
    STATE(91), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(152), 7,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_math_mode,
  [3532] = 16,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_export,
    ACTIONS(9), 1,
      anon_sym_def,
    ACTIONS(13), 1,
      anon_sym_EQ,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(23), 1,
      sym_number_literal,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(27), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(325), 1,
      anon_sym_alias,
    ACTIONS(327), 1,
      sym_cmd_name,
    STATE(65), 1,
      aux_sym__statements_repeat1,
    STATE(263), 1,
      sym__statements,
    STATE(91), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(152), 7,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_math_mode,
  [3593] = 15,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(339), 1,
      anon_sym_export,
    ACTIONS(342), 1,
      anon_sym_def,
    ACTIONS(345), 1,
      anon_sym_alias,
    ACTIONS(348), 1,
      anon_sym_EQ,
    ACTIONS(351), 1,
      anon_sym_LBRACK,
    ACTIONS(354), 1,
      anon_sym_LPAREN,
    ACTIONS(357), 1,
      anon_sym_let,
    ACTIONS(360), 1,
      sym_cmd_name,
    ACTIONS(363), 1,
      sym_number_literal,
    ACTIONS(366), 1,
      anon_sym_DOLLAR,
    ACTIONS(369), 1,
      anon_sym_DOLLAR_LPAREN,
    STATE(64), 1,
      aux_sym__statements_repeat1,
    STATE(91), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(175), 7,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_math_mode,
  [3651] = 15,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_export,
    ACTIONS(9), 1,
      anon_sym_def,
    ACTIONS(13), 1,
      anon_sym_EQ,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(23), 1,
      sym_number_literal,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(27), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(325), 1,
      anon_sym_alias,
    ACTIONS(327), 1,
      sym_cmd_name,
    STATE(64), 1,
      aux_sym__statements_repeat1,
    STATE(91), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(153), 7,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_math_mode,
  [3709] = 5,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(372), 1,
      anon_sym_DOT,
    STATE(66), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(254), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(249), 22,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
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
  [3747] = 15,
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
      sym_cmd_name,
    ACTIONS(23), 1,
      sym_number_literal,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(27), 1,
      anon_sym_DOLLAR_LPAREN,
    STATE(64), 1,
      aux_sym__statements_repeat1,
    STATE(91), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(164), 7,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_math_mode,
  [3805] = 5,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(375), 1,
      anon_sym_DOT,
    STATE(69), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(258), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(256), 22,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
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
  [3843] = 5,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(375), 1,
      anon_sym_DOT,
    STATE(66), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(247), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(243), 22,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
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
  [3881] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_export,
    ACTIONS(9), 1,
      anon_sym_def,
    ACTIONS(13), 1,
      anon_sym_EQ,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(23), 1,
      sym_number_literal,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(27), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(325), 1,
      anon_sym_alias,
    ACTIONS(327), 1,
      sym_cmd_name,
    STATE(91), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(151), 7,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_math_mode,
  [3936] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      anon_sym_export,
    ACTIONS(9), 1,
      anon_sym_def,
    ACTIONS(13), 1,
      anon_sym_EQ,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(19), 1,
      anon_sym_let,
    ACTIONS(23), 1,
      sym_number_literal,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(27), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(325), 1,
      anon_sym_alias,
    ACTIONS(327), 1,
      sym_cmd_name,
    STATE(91), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(165), 7,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_math_mode,
  [3991] = 14,
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
      sym_cmd_name,
    ACTIONS(23), 1,
      sym_number_literal,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(27), 1,
      anon_sym_DOLLAR_LPAREN,
    STATE(91), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(151), 7,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_math_mode,
  [4046] = 14,
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
      sym_cmd_name,
    ACTIONS(23), 1,
      sym_number_literal,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(27), 1,
      anon_sym_DOLLAR_LPAREN,
    STATE(91), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
    STATE(174), 7,
      sym__statement,
      sym_function_definition,
      sym_alias,
      sym_variable_declaration,
      sym_command,
      sym_pipeline,
      sym_math_mode,
  [4101] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(254), 3,
      ts_builtin_sym_end,
      anon_sym_DOT,
      anon_sym_LF,
    ACTIONS(249), 22,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
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
  [4134] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(377), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(379), 22,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
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
  [4166] = 6,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(377), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(381), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(385), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(383), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(379), 14,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
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
  [4204] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(387), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(389), 22,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
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
  [4236] = 10,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(395), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(397), 1,
      anon_sym_AMP_AMP,
    ACTIONS(381), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(385), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(391), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(383), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(393), 4,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
    ACTIONS(399), 4,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
    ACTIONS(401), 4,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
  [4282] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(275), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(273), 22,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
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
  [4314] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(283), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(281), 22,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
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
  [4346] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(311), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(309), 22,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
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
  [4378] = 4,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(377), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(383), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(379), 18,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
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
  [4412] = 9,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(397), 1,
      anon_sym_AMP_AMP,
    ACTIONS(377), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(381), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(385), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(383), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(399), 4,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
    ACTIONS(401), 4,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
    ACTIONS(379), 5,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_PIPE_PIPE,
  [4456] = 8,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(377), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(381), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(385), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(383), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(399), 4,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
    ACTIONS(401), 4,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
    ACTIONS(379), 6,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
  [4498] = 7,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(377), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(381), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(385), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(383), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(401), 4,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
    ACTIONS(379), 10,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
  [4538] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(287), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(285), 22,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
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
  [4570] = 5,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(377), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(381), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(383), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(379), 16,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
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
  [4606] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(295), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(293), 22,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
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
  [4638] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(319), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(317), 22,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
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
  [4670] = 10,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(395), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(397), 1,
      anon_sym_AMP_AMP,
    ACTIONS(381), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(385), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(403), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(383), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(399), 4,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
    ACTIONS(401), 4,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
    ACTIONS(405), 4,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
  [4716] = 10,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(395), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(397), 1,
      anon_sym_AMP_AMP,
    ACTIONS(381), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(385), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(407), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(383), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(399), 4,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
    ACTIONS(401), 4,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
    ACTIONS(409), 4,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
  [4762] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(411), 1,
      anon_sym_DOT,
    STATE(93), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(256), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(258), 19,
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
  [4797] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(411), 1,
      anon_sym_DOT,
    STATE(94), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(243), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(247), 19,
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
  [4832] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(413), 1,
      anon_sym_DOT,
    STATE(94), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(249), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(254), 19,
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
  [4867] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(249), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(254), 20,
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
  [4897] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(273), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(275), 20,
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
  [4927] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(293), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(295), 20,
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
  [4957] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(285), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(287), 20,
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
  [4987] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(309), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(311), 19,
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
  [5016] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(317), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(319), 19,
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
  [5045] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(281), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(283), 19,
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
  [5074] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(379), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(416), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(377), 13,
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
  [5103] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(418), 1,
      anon_sym_RPAREN,
    ACTIONS(422), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(424), 1,
      anon_sym_AMP_AMP,
    ACTIONS(420), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(428), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(430), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(432), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(416), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(426), 4,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
  [5144] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(422), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(424), 1,
      anon_sym_AMP_AMP,
    ACTIONS(434), 1,
      anon_sym_RPAREN,
    ACTIONS(420), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(428), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(430), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(432), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(416), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(426), 4,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
  [5185] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(424), 1,
      anon_sym_AMP_AMP,
    ACTIONS(377), 2,
      anon_sym_RPAREN,
      anon_sym_PIPE_PIPE,
    ACTIONS(420), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(428), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(430), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(432), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(416), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(426), 4,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
  [5224] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(379), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(377), 17,
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
  [5251] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(379), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(420), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(416), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(377), 11,
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
  [5282] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(379), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(420), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(432), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(416), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(377), 9,
      anon_sym_RPAREN,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
  [5315] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(420), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(428), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(430), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(432), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(416), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(377), 7,
      anon_sym_RPAREN,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
  [5350] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(420), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(428), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(430), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(432), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(377), 3,
      anon_sym_RPAREN,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
    ACTIONS(416), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_mod,
    ACTIONS(426), 4,
      anon_sym_EQ_TILDE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_in,
  [5387] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(389), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(387), 17,
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
  [5414] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(27), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(436), 1,
      sym_number_literal,
    ACTIONS(438), 1,
      anon_sym_DQUOTE,
    ACTIONS(440), 1,
      anon_sym_SQUOTE,
    ACTIONS(442), 1,
      anon_sym_BQUOTE,
    STATE(147), 1,
      sym_string,
    STATE(78), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [5454] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(448), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
    ACTIONS(446), 5,
      anon_sym_EQ,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      sym_number_literal,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(444), 6,
      anon_sym_export,
      anon_sym_def,
      anon_sym_alias,
      anon_sym_let,
      sym_cmd_name,
      anon_sym_DOLLAR,
  [5477] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(450), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
    ACTIONS(446), 5,
      anon_sym_EQ,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      sym_number_literal,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(444), 6,
      anon_sym_export,
      anon_sym_def,
      anon_sym_alias,
      anon_sym_let,
      sym_cmd_name,
      anon_sym_DOLLAR,
  [5500] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_DOLLAR,
    ACTIONS(223), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(452), 1,
      anon_sym_LBRACK,
    ACTIONS(454), 1,
      anon_sym_LPAREN,
    ACTIONS(456), 1,
      sym_number_literal,
    STATE(103), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [5528] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_DOLLAR,
    ACTIONS(223), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(452), 1,
      anon_sym_LBRACK,
    ACTIONS(454), 1,
      anon_sym_LPAREN,
    ACTIONS(458), 1,
      sym_number_literal,
    STATE(102), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [5556] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(27), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(460), 1,
      sym_number_literal,
    STATE(75), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [5584] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(27), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(462), 1,
      sym_number_literal,
    STATE(84), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [5612] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(27), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(464), 1,
      sym_number_literal,
    STATE(83), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [5640] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(27), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(466), 1,
      sym_number_literal,
    STATE(90), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [5668] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(27), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(468), 1,
      sym_number_literal,
    STATE(82), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [5696] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(450), 1,
      ts_builtin_sym_end,
    ACTIONS(446), 5,
      anon_sym_EQ,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      sym_number_literal,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(444), 6,
      anon_sym_export,
      anon_sym_def,
      anon_sym_alias,
      anon_sym_let,
      sym_cmd_name,
      anon_sym_DOLLAR,
  [5718] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_DOLLAR,
    ACTIONS(223), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(452), 1,
      anon_sym_LBRACK,
    ACTIONS(454), 1,
      anon_sym_LPAREN,
    ACTIONS(470), 1,
      sym_number_literal,
    STATE(106), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [5746] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_DOLLAR,
    ACTIONS(223), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(452), 1,
      anon_sym_LBRACK,
    ACTIONS(454), 1,
      anon_sym_LPAREN,
    ACTIONS(472), 1,
      sym_number_literal,
    STATE(105), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [5774] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(27), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(474), 1,
      sym_number_literal,
    STATE(85), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [5802] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(27), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(476), 1,
      sym_number_literal,
    STATE(76), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [5830] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(15), 1,
      anon_sym_LBRACK,
    ACTIONS(17), 1,
      anon_sym_LPAREN,
    ACTIONS(25), 1,
      anon_sym_DOLLAR,
    ACTIONS(27), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(478), 1,
      sym_number_literal,
    STATE(87), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [5858] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_DOLLAR,
    ACTIONS(223), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(452), 1,
      anon_sym_LBRACK,
    ACTIONS(454), 1,
      anon_sym_LPAREN,
    ACTIONS(480), 1,
      sym_number_literal,
    STATE(110), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [5886] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_DOLLAR,
    ACTIONS(223), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(452), 1,
      anon_sym_LBRACK,
    ACTIONS(454), 1,
      anon_sym_LPAREN,
    ACTIONS(482), 1,
      sym_number_literal,
    STATE(109), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [5914] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_DOLLAR,
    ACTIONS(223), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(452), 1,
      anon_sym_LBRACK,
    ACTIONS(454), 1,
      anon_sym_LPAREN,
    ACTIONS(484), 1,
      sym_number_literal,
    STATE(108), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [5942] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_DOLLAR,
    ACTIONS(223), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(452), 1,
      anon_sym_LBRACK,
    ACTIONS(454), 1,
      anon_sym_LPAREN,
    ACTIONS(486), 1,
      sym_number_literal,
    STATE(107), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [5970] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(219), 1,
      anon_sym_DOLLAR,
    ACTIONS(223), 1,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(452), 1,
      anon_sym_LBRACK,
    ACTIONS(454), 1,
      anon_sym_LPAREN,
    ACTIONS(488), 1,
      sym_number_literal,
    STATE(104), 7,
      sym_value_path,
      sym_command_substitution,
      sym_table,
      sym_array,
      sym__math_expression,
      sym_parenthesized_math_expression,
      sym_binary_expression,
  [5998] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(448), 1,
      ts_builtin_sym_end,
    ACTIONS(446), 5,
      anon_sym_EQ,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      sym_number_literal,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(444), 6,
      anon_sym_export,
      anon_sym_def,
      anon_sym_alias,
      anon_sym_let,
      sym_cmd_name,
      anon_sym_DOLLAR,
  [6020] = 3,
    ACTIONS(3), 1,
      sym_comment,
    STATE(146), 1,
      sym_type,
    ACTIONS(490), 10,
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
  [6039] = 3,
    ACTIONS(3), 1,
      sym_comment,
    STATE(171), 1,
      sym_type,
    ACTIONS(490), 10,
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
  [6058] = 3,
    ACTIONS(3), 1,
      sym_comment,
    STATE(157), 1,
      sym_type,
    ACTIONS(490), 10,
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
  [6077] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(446), 5,
      anon_sym_EQ,
      anon_sym_LBRACK,
      anon_sym_LPAREN,
      sym_number_literal,
      anon_sym_DOLLAR_LPAREN,
    ACTIONS(444), 6,
      anon_sym_export,
      anon_sym_def,
      anon_sym_alias,
      anon_sym_let,
      sym_cmd_name,
      anon_sym_DOLLAR,
  [6096] = 3,
    ACTIONS(3), 1,
      sym_comment,
    STATE(168), 1,
      sym_type,
    ACTIONS(490), 10,
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
  [6115] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(492), 1,
      anon_sym_RBRACK,
    ACTIONS(494), 1,
      sym_flag_name,
    ACTIONS(496), 1,
      anon_sym_DOT_DOT_DOTrest,
    ACTIONS(498), 1,
      sym_identifier,
    STATE(141), 1,
      aux_sym_signature_repeat1,
    STATE(162), 3,
      sym_parameter,
      sym_flag,
      sym_rest,
  [6139] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(494), 1,
      sym_flag_name,
    ACTIONS(496), 1,
      anon_sym_DOT_DOT_DOTrest,
    ACTIONS(498), 1,
      sym_identifier,
    ACTIONS(500), 1,
      anon_sym_RBRACK,
    STATE(139), 1,
      aux_sym_signature_repeat1,
    STATE(162), 3,
      sym_parameter,
      sym_flag,
      sym_rest,
  [6163] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(502), 1,
      anon_sym_RBRACK,
    ACTIONS(504), 1,
      sym_flag_name,
    ACTIONS(507), 1,
      anon_sym_DOT_DOT_DOTrest,
    ACTIONS(510), 1,
      sym_identifier,
    STATE(141), 1,
      aux_sym_signature_repeat1,
    STATE(162), 3,
      sym_parameter,
      sym_flag,
      sym_rest,
  [6187] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(515), 1,
      anon_sym_COLON,
    ACTIONS(517), 1,
      anon_sym_LPAREN,
    ACTIONS(513), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [6204] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(521), 1,
      anon_sym_COLON,
    ACTIONS(523), 1,
      anon_sym_QMARK,
    ACTIONS(519), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [6221] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(525), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(527), 4,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
  [6235] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(303), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(301), 4,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
  [6249] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(531), 1,
      anon_sym_QMARK,
    ACTIONS(529), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [6263] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(391), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(393), 4,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
  [6277] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(279), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(277), 4,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
  [6291] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(315), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(313), 4,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
  [6305] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(533), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(535), 4,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
  [6319] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(537), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
    ACTIONS(539), 4,
      anon_sym_RPAREN,
      anon_sym_PIPE,
      anon_sym_SEMI,
      anon_sym_RBRACE,
  [6333] = 6,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(543), 1,
      anon_sym_PIPE,
    ACTIONS(545), 1,
      anon_sym_SEMI,
    ACTIONS(547), 1,
      anon_sym_LF,
    STATE(114), 1,
      sym__terminator,
    ACTIONS(541), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [6353] = 6,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(543), 1,
      anon_sym_PIPE,
    ACTIONS(551), 1,
      anon_sym_SEMI,
    ACTIONS(553), 1,
      anon_sym_LF,
    STATE(113), 1,
      sym__terminator,
    ACTIONS(549), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACE,
  [6373] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(555), 6,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      anon_sym_QMARK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [6385] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(559), 1,
      anon_sym_COLON,
    ACTIONS(557), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [6399] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(563), 1,
      anon_sym_COLON,
    ACTIONS(561), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [6413] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(565), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [6424] = 5,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(247), 1,
      anon_sym_,
    ACTIONS(567), 1,
      anon_sym_DOT,
    STATE(163), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(243), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6441] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(569), 1,
      anon_sym_DQUOTE,
    ACTIONS(571), 1,
      anon_sym_SQUOTE,
    ACTIONS(573), 1,
      anon_sym_BQUOTE,
    ACTIONS(575), 1,
      sym_identifier,
    STATE(227), 1,
      sym_string,
  [6460] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(577), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [6471] = 6,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(579), 1,
      ts_builtin_sym_end,
    ACTIONS(581), 1,
      anon_sym_PIPE,
    ACTIONS(583), 1,
      anon_sym_SEMI,
    ACTIONS(585), 1,
      anon_sym_LF,
    STATE(122), 1,
      sym__terminator,
  [6490] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(587), 1,
      anon_sym_COMMA,
    ACTIONS(589), 4,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [6503] = 5,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(254), 1,
      anon_sym_,
    ACTIONS(591), 1,
      anon_sym_DOT,
    STATE(163), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(249), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6520] = 6,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(450), 1,
      ts_builtin_sym_end,
    ACTIONS(581), 1,
      anon_sym_PIPE,
    ACTIONS(594), 1,
      anon_sym_SEMI,
    ACTIONS(596), 1,
      anon_sym_LF,
    STATE(133), 1,
      sym__terminator,
  [6539] = 4,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(543), 1,
      anon_sym_PIPE,
    ACTIONS(600), 1,
      anon_sym_LF,
    ACTIONS(598), 3,
      anon_sym_RPAREN,
      anon_sym_SEMI,
      anon_sym_RBRACE,
  [6554] = 5,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(258), 1,
      anon_sym_,
    ACTIONS(567), 1,
      anon_sym_DOT,
    STATE(158), 1,
      aux_sym_value_path_repeat1,
    ACTIONS(256), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6571] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(569), 1,
      anon_sym_DQUOTE,
    ACTIONS(571), 1,
      anon_sym_SQUOTE,
    ACTIONS(573), 1,
      anon_sym_BQUOTE,
    ACTIONS(602), 1,
      sym_identifier,
    STATE(230), 1,
      sym_string,
  [6590] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(604), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [6601] = 6,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(61), 1,
      anon_sym_COMMA,
    ACTIONS(79), 1,
      anon_sym_,
    ACTIONS(606), 1,
      anon_sym_RBRACK,
    STATE(178), 1,
      aux_sym_array_repeat1,
    STATE(218), 1,
      aux_sym_column_header_repeat1,
  [6620] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(608), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [6631] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(610), 5,
      anon_sym_COMMA,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [6642] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(612), 1,
      anon_sym_LBRACK,
    ACTIONS(614), 1,
      anon_sym_RBRACK,
    STATE(192), 2,
      sym_array,
      aux_sym_table_repeat1,
  [6656] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(612), 1,
      anon_sym_LBRACK,
    ACTIONS(616), 1,
      anon_sym_RBRACK,
    STATE(199), 2,
      sym_array,
      aux_sym_table_repeat1,
  [6670] = 4,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(581), 1,
      anon_sym_PIPE,
    ACTIONS(598), 1,
      anon_sym_SEMI,
    ACTIONS(600), 2,
      ts_builtin_sym_end,
      anon_sym_LF,
  [6684] = 5,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(543), 1,
      anon_sym_PIPE,
    ACTIONS(618), 1,
      anon_sym_SEMI,
    ACTIONS(620), 1,
      anon_sym_LF,
    STATE(137), 1,
      sym__terminator,
  [6700] = 5,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(79), 1,
      anon_sym_,
    ACTIONS(128), 1,
      anon_sym_COMMA,
    ACTIONS(622), 1,
      anon_sym_RBRACK,
    STATE(200), 1,
      aux_sym_array_repeat1,
  [6716] = 5,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(79), 1,
      anon_sym_,
    ACTIONS(128), 1,
      anon_sym_COMMA,
    ACTIONS(624), 1,
      anon_sym_RBRACK,
    STATE(202), 1,
      aux_sym_array_repeat1,
  [6732] = 5,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(79), 1,
      anon_sym_,
    ACTIONS(128), 1,
      anon_sym_COMMA,
    ACTIONS(626), 1,
      anon_sym_RBRACK,
    STATE(200), 1,
      aux_sym_array_repeat1,
  [6748] = 4,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(287), 1,
      anon_sym_,
    ACTIONS(628), 1,
      anon_sym_SEMI,
    ACTIONS(285), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6762] = 4,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(275), 1,
      anon_sym_,
    ACTIONS(630), 1,
      anon_sym_SEMI,
    ACTIONS(273), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6776] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(612), 1,
      anon_sym_LBRACK,
    ACTIONS(632), 1,
      anon_sym_RBRACK,
    STATE(197), 2,
      sym_array,
      aux_sym_table_repeat1,
  [6790] = 4,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(269), 1,
      anon_sym_,
    ACTIONS(634), 1,
      anon_sym_DOT_DOT,
    ACTIONS(265), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [6804] = 5,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(79), 1,
      anon_sym_,
    ACTIONS(128), 1,
      anon_sym_COMMA,
    ACTIONS(636), 1,
      anon_sym_RBRACK,
    STATE(198), 1,
      aux_sym_array_repeat1,
  [6820] = 5,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(79), 1,
      anon_sym_,
    ACTIONS(128), 1,
      anon_sym_COMMA,
    ACTIONS(638), 1,
      anon_sym_RBRACK,
    STATE(200), 1,
      aux_sym_array_repeat1,
  [6836] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(249), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
    ACTIONS(254), 2,
      anon_sym_DOT,
      anon_sym_,
  [6848] = 5,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(79), 1,
      anon_sym_,
    ACTIONS(128), 1,
      anon_sym_COMMA,
    ACTIONS(636), 1,
      anon_sym_RBRACK,
    STATE(200), 1,
      aux_sym_array_repeat1,
  [6864] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(612), 1,
      anon_sym_LBRACK,
    ACTIONS(640), 1,
      anon_sym_RBRACK,
    STATE(193), 2,
      sym_array,
      aux_sym_table_repeat1,
  [6878] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(612), 1,
      anon_sym_LBRACK,
    ACTIONS(642), 1,
      anon_sym_RBRACK,
    STATE(187), 2,
      sym_array,
      aux_sym_table_repeat1,
  [6892] = 5,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(79), 1,
      anon_sym_,
    ACTIONS(128), 1,
      anon_sym_COMMA,
    ACTIONS(644), 1,
      anon_sym_RBRACK,
    STATE(200), 1,
      aux_sym_array_repeat1,
  [6908] = 5,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(79), 1,
      anon_sym_,
    ACTIONS(128), 1,
      anon_sym_COMMA,
    ACTIONS(646), 1,
      anon_sym_RBRACK,
    STATE(200), 1,
      aux_sym_array_repeat1,
  [6924] = 5,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(79), 1,
      anon_sym_,
    ACTIONS(128), 1,
      anon_sym_COMMA,
    ACTIONS(646), 1,
      anon_sym_RBRACK,
    STATE(189), 1,
      aux_sym_array_repeat1,
  [6940] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(612), 1,
      anon_sym_LBRACK,
    ACTIONS(648), 1,
      anon_sym_RBRACK,
    STATE(193), 2,
      sym_array,
      aux_sym_table_repeat1,
  [6954] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(650), 1,
      anon_sym_LBRACK,
    ACTIONS(653), 1,
      anon_sym_RBRACK,
    STATE(193), 2,
      sym_array,
      aux_sym_table_repeat1,
  [6968] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(612), 1,
      anon_sym_LBRACK,
    ACTIONS(655), 1,
      anon_sym_RBRACK,
    STATE(203), 2,
      sym_array,
      aux_sym_table_repeat1,
  [6982] = 5,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(79), 1,
      anon_sym_,
    ACTIONS(128), 1,
      anon_sym_COMMA,
    ACTIONS(657), 1,
      anon_sym_RBRACK,
    STATE(200), 1,
      aux_sym_array_repeat1,
  [6998] = 5,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(79), 1,
      anon_sym_,
    ACTIONS(128), 1,
      anon_sym_COMMA,
    ACTIONS(622), 1,
      anon_sym_RBRACK,
    STATE(178), 1,
      aux_sym_array_repeat1,
  [7014] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(612), 1,
      anon_sym_LBRACK,
    ACTIONS(659), 1,
      anon_sym_RBRACK,
    STATE(193), 2,
      sym_array,
      aux_sym_table_repeat1,
  [7028] = 5,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(79), 1,
      anon_sym_,
    ACTIONS(128), 1,
      anon_sym_COMMA,
    ACTIONS(661), 1,
      anon_sym_RBRACK,
    STATE(200), 1,
      aux_sym_array_repeat1,
  [7044] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(612), 1,
      anon_sym_LBRACK,
    ACTIONS(663), 1,
      anon_sym_RBRACK,
    STATE(193), 2,
      sym_array,
      aux_sym_table_repeat1,
  [7058] = 5,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(665), 1,
      anon_sym_COMMA,
    ACTIONS(668), 1,
      anon_sym_RBRACK,
    ACTIONS(670), 1,
      anon_sym_,
    STATE(200), 1,
      aux_sym_array_repeat1,
  [7074] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(502), 4,
      anon_sym_RBRACK,
      sym_flag_name,
      anon_sym_DOT_DOT_DOTrest,
      sym_identifier,
  [7084] = 5,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(79), 1,
      anon_sym_,
    ACTIONS(128), 1,
      anon_sym_COMMA,
    ACTIONS(673), 1,
      anon_sym_RBRACK,
    STATE(200), 1,
      aux_sym_array_repeat1,
  [7100] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(612), 1,
      anon_sym_LBRACK,
    ACTIONS(675), 1,
      anon_sym_RBRACK,
    STATE(193), 2,
      sym_array,
      aux_sym_table_repeat1,
  [7114] = 5,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(79), 1,
      anon_sym_,
    ACTIONS(128), 1,
      anon_sym_COMMA,
    ACTIONS(657), 1,
      anon_sym_RBRACK,
    STATE(184), 1,
      aux_sym_array_repeat1,
  [7130] = 5,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(79), 1,
      anon_sym_,
    ACTIONS(128), 1,
      anon_sym_COMMA,
    ACTIONS(624), 1,
      anon_sym_RBRACK,
    STATE(200), 1,
      aux_sym_array_repeat1,
  [7146] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(307), 1,
      anon_sym_,
    ACTIONS(305), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7157] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(677), 1,
      anon_sym_COMMA,
    ACTIONS(680), 1,
      anon_sym_RBRACK,
    STATE(207), 1,
      aux_sym_column_header_repeat1,
  [7170] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(279), 1,
      anon_sym_,
    ACTIONS(277), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7181] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(682), 1,
      anon_sym_DOT_DOT,
    ACTIONS(269), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7192] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(287), 1,
      anon_sym_,
    ACTIONS(285), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7203] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(319), 1,
      anon_sym_,
    ACTIONS(317), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7214] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(311), 1,
      anon_sym_,
    ACTIONS(309), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7225] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(295), 1,
      anon_sym_,
    ACTIONS(293), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7236] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(299), 1,
      anon_sym_,
    ACTIONS(297), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7247] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(315), 1,
      anon_sym_,
    ACTIONS(313), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7258] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(291), 1,
      anon_sym_,
    ACTIONS(289), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7269] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(315), 3,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7278] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(684), 1,
      anon_sym_COMMA,
    ACTIONS(686), 1,
      anon_sym_RBRACK,
    STATE(207), 1,
      aux_sym_column_header_repeat1,
  [7291] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(283), 1,
      anon_sym_,
    ACTIONS(281), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7302] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(275), 1,
      anon_sym_,
    ACTIONS(273), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7313] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(691), 1,
      anon_sym_,
    ACTIONS(688), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7324] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(684), 1,
      anon_sym_COMMA,
    ACTIONS(693), 1,
      anon_sym_RBRACK,
    STATE(207), 1,
      aux_sym_column_header_repeat1,
  [7337] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(691), 1,
      anon_sym_,
    ACTIONS(668), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7348] = 3,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(303), 1,
      anon_sym_,
    ACTIONS(301), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7359] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(307), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7367] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(303), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7375] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(695), 1,
      anon_sym_LBRACK,
    STATE(228), 1,
      sym_signature,
  [7385] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(697), 1,
      anon_sym_LBRACE,
    STATE(150), 1,
      sym_block,
  [7395] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(697), 1,
      anon_sym_LBRACE,
    STATE(144), 1,
      sym_block,
  [7405] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(695), 1,
      anon_sym_LBRACK,
    STATE(229), 1,
      sym_signature,
  [7415] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(680), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7423] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(291), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7431] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(299), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7439] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(279), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [7447] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(699), 1,
      anon_sym_BQUOTE,
  [7454] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(701), 1,
      sym_identifier,
  [7461] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(703), 1,
      anon_sym_DQUOTE,
  [7468] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(703), 1,
      anon_sym_SQUOTE,
  [7475] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(703), 1,
      anon_sym_BQUOTE,
  [7482] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(705), 1,
      sym_number_literal,
  [7489] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(707), 1,
      anon_sym_RBRACE,
  [7496] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(709), 1,
      sym_number_literal,
  [7503] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(711), 1,
      anon_sym_SEMI,
  [7510] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(713), 1,
      anon_sym_LBRACE,
  [7517] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(715), 1,
      sym_identifier,
  [7524] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(717), 1,
      anon_sym_SEMI,
  [7531] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(719), 1,
      anon_sym_EQ,
  [7538] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(721), 1,
      anon_sym_RPAREN,
  [7545] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(723), 1,
      anon_sym_RPAREN,
  [7552] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(725), 1,
      anon_sym_DQUOTE,
  [7559] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(725), 1,
      anon_sym_SQUOTE,
  [7566] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(725), 1,
      anon_sym_BQUOTE,
  [7573] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(727), 1,
      sym_number_literal,
  [7580] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(729), 1,
      anon_sym_RBRACE,
  [7587] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(731), 1,
      anon_sym_RBRACE,
  [7594] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(733), 1,
      sym_flag_shorthand_name,
  [7601] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(735), 1,
      sym_identifier,
  [7608] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(737), 1,
      ts_builtin_sym_end,
  [7615] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(739), 1,
      sym_identifier,
  [7622] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(741), 1,
      sym_identifier,
  [7629] = 2,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(743), 1,
      aux_sym_string_token3,
  [7636] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(745), 1,
      anon_sym_LBRACE,
  [7643] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(747), 1,
      anon_sym_RPAREN,
  [7650] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(699), 1,
      anon_sym_DQUOTE,
  [7657] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(699), 1,
      anon_sym_SQUOTE,
  [7664] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(749), 1,
      anon_sym_EQ,
  [7671] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(751), 1,
      sym_number_literal,
  [7678] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(753), 1,
      anon_sym_RBRACE,
  [7685] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(755), 1,
      sym_identifier,
  [7692] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(757), 1,
      anon_sym_SEMI,
  [7699] = 2,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(759), 1,
      aux_sym_string_token1,
  [7706] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(761), 1,
      anon_sym_RPAREN,
  [7713] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(763), 1,
      ts_builtin_sym_end,
  [7720] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(765), 1,
      sym_identifier,
  [7727] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(767), 1,
      sym_identifier,
  [7734] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(769), 1,
      anon_sym_RPAREN,
  [7741] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(771), 1,
      sym_identifier,
  [7748] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(773), 1,
      anon_sym_RPAREN,
  [7755] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(775), 1,
      anon_sym_DQUOTE,
  [7762] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(775), 1,
      anon_sym_SQUOTE,
  [7769] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(775), 1,
      anon_sym_BQUOTE,
  [7776] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(777), 1,
      anon_sym_RBRACE,
  [7783] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(779), 1,
      sym_identifier,
  [7790] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(781), 1,
      anon_sym_DQUOTE,
  [7797] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(783), 1,
      sym_identifier,
  [7804] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(781), 1,
      anon_sym_SQUOTE,
  [7811] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(785), 1,
      anon_sym_EQ,
  [7818] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(787), 1,
      anon_sym_def,
  [7825] = 2,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(789), 1,
      aux_sym_string_token1,
  [7832] = 2,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(791), 1,
      aux_sym_string_token1,
  [7839] = 2,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(793), 1,
      aux_sym_string_token2,
  [7846] = 2,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(795), 1,
      aux_sym_string_token3,
  [7853] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(797), 1,
      anon_sym_SEMI,
  [7860] = 2,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(799), 1,
      aux_sym_string_token2,
  [7867] = 2,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(801), 1,
      aux_sym_string_token1,
  [7874] = 2,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(803), 1,
      aux_sym_string_token2,
  [7881] = 2,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(805), 1,
      aux_sym_string_token3,
  [7888] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(807), 1,
      anon_sym_SEMI,
  [7895] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(809), 1,
      sym_identifier,
  [7902] = 2,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(811), 1,
      aux_sym_string_token1,
  [7909] = 2,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(813), 1,
      aux_sym_string_token2,
  [7916] = 2,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(815), 1,
      aux_sym_string_token3,
  [7923] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(817), 1,
      anon_sym_SEMI,
  [7930] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(781), 1,
      anon_sym_BQUOTE,
  [7937] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(819), 1,
      sym_identifier,
  [7944] = 2,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(821), 1,
      aux_sym_string_token2,
  [7951] = 2,
    ACTIONS(51), 1,
      sym_comment,
    ACTIONS(823), 1,
      aux_sym_string_token3,
  [7958] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(825), 1,
      anon_sym_SEMI,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 83,
  [SMALL_STATE(4)] = 172,
  [SMALL_STATE(5)] = 255,
  [SMALL_STATE(6)] = 338,
  [SMALL_STATE(7)] = 424,
  [SMALL_STATE(8)] = 510,
  [SMALL_STATE(9)] = 596,
  [SMALL_STATE(10)] = 678,
  [SMALL_STATE(11)] = 764,
  [SMALL_STATE(12)] = 850,
  [SMALL_STATE(13)] = 932,
  [SMALL_STATE(14)] = 1014,
  [SMALL_STATE(15)] = 1097,
  [SMALL_STATE(16)] = 1172,
  [SMALL_STATE(17)] = 1247,
  [SMALL_STATE(18)] = 1322,
  [SMALL_STATE(19)] = 1373,
  [SMALL_STATE(20)] = 1424,
  [SMALL_STATE(21)] = 1475,
  [SMALL_STATE(22)] = 1525,
  [SMALL_STATE(23)] = 1575,
  [SMALL_STATE(24)] = 1621,
  [SMALL_STATE(25)] = 1671,
  [SMALL_STATE(26)] = 1719,
  [SMALL_STATE(27)] = 1766,
  [SMALL_STATE(28)] = 1811,
  [SMALL_STATE(29)] = 1856,
  [SMALL_STATE(30)] = 1901,
  [SMALL_STATE(31)] = 1946,
  [SMALL_STATE(32)] = 1991,
  [SMALL_STATE(33)] = 2036,
  [SMALL_STATE(34)] = 2081,
  [SMALL_STATE(35)] = 2126,
  [SMALL_STATE(36)] = 2171,
  [SMALL_STATE(37)] = 2216,
  [SMALL_STATE(38)] = 2261,
  [SMALL_STATE(39)] = 2306,
  [SMALL_STATE(40)] = 2351,
  [SMALL_STATE(41)] = 2396,
  [SMALL_STATE(42)] = 2440,
  [SMALL_STATE(43)] = 2484,
  [SMALL_STATE(44)] = 2528,
  [SMALL_STATE(45)] = 2572,
  [SMALL_STATE(46)] = 2616,
  [SMALL_STATE(47)] = 2660,
  [SMALL_STATE(48)] = 2704,
  [SMALL_STATE(49)] = 2748,
  [SMALL_STATE(50)] = 2792,
  [SMALL_STATE(51)] = 2836,
  [SMALL_STATE(52)] = 2880,
  [SMALL_STATE(53)] = 2924,
  [SMALL_STATE(54)] = 2968,
  [SMALL_STATE(55)] = 3032,
  [SMALL_STATE(56)] = 3096,
  [SMALL_STATE(57)] = 3160,
  [SMALL_STATE(58)] = 3224,
  [SMALL_STATE(59)] = 3288,
  [SMALL_STATE(60)] = 3349,
  [SMALL_STATE(61)] = 3410,
  [SMALL_STATE(62)] = 3471,
  [SMALL_STATE(63)] = 3532,
  [SMALL_STATE(64)] = 3593,
  [SMALL_STATE(65)] = 3651,
  [SMALL_STATE(66)] = 3709,
  [SMALL_STATE(67)] = 3747,
  [SMALL_STATE(68)] = 3805,
  [SMALL_STATE(69)] = 3843,
  [SMALL_STATE(70)] = 3881,
  [SMALL_STATE(71)] = 3936,
  [SMALL_STATE(72)] = 3991,
  [SMALL_STATE(73)] = 4046,
  [SMALL_STATE(74)] = 4101,
  [SMALL_STATE(75)] = 4134,
  [SMALL_STATE(76)] = 4166,
  [SMALL_STATE(77)] = 4204,
  [SMALL_STATE(78)] = 4236,
  [SMALL_STATE(79)] = 4282,
  [SMALL_STATE(80)] = 4314,
  [SMALL_STATE(81)] = 4346,
  [SMALL_STATE(82)] = 4378,
  [SMALL_STATE(83)] = 4412,
  [SMALL_STATE(84)] = 4456,
  [SMALL_STATE(85)] = 4498,
  [SMALL_STATE(86)] = 4538,
  [SMALL_STATE(87)] = 4570,
  [SMALL_STATE(88)] = 4606,
  [SMALL_STATE(89)] = 4638,
  [SMALL_STATE(90)] = 4670,
  [SMALL_STATE(91)] = 4716,
  [SMALL_STATE(92)] = 4762,
  [SMALL_STATE(93)] = 4797,
  [SMALL_STATE(94)] = 4832,
  [SMALL_STATE(95)] = 4867,
  [SMALL_STATE(96)] = 4897,
  [SMALL_STATE(97)] = 4927,
  [SMALL_STATE(98)] = 4957,
  [SMALL_STATE(99)] = 4987,
  [SMALL_STATE(100)] = 5016,
  [SMALL_STATE(101)] = 5045,
  [SMALL_STATE(102)] = 5074,
  [SMALL_STATE(103)] = 5103,
  [SMALL_STATE(104)] = 5144,
  [SMALL_STATE(105)] = 5185,
  [SMALL_STATE(106)] = 5224,
  [SMALL_STATE(107)] = 5251,
  [SMALL_STATE(108)] = 5282,
  [SMALL_STATE(109)] = 5315,
  [SMALL_STATE(110)] = 5350,
  [SMALL_STATE(111)] = 5387,
  [SMALL_STATE(112)] = 5414,
  [SMALL_STATE(113)] = 5454,
  [SMALL_STATE(114)] = 5477,
  [SMALL_STATE(115)] = 5500,
  [SMALL_STATE(116)] = 5528,
  [SMALL_STATE(117)] = 5556,
  [SMALL_STATE(118)] = 5584,
  [SMALL_STATE(119)] = 5612,
  [SMALL_STATE(120)] = 5640,
  [SMALL_STATE(121)] = 5668,
  [SMALL_STATE(122)] = 5696,
  [SMALL_STATE(123)] = 5718,
  [SMALL_STATE(124)] = 5746,
  [SMALL_STATE(125)] = 5774,
  [SMALL_STATE(126)] = 5802,
  [SMALL_STATE(127)] = 5830,
  [SMALL_STATE(128)] = 5858,
  [SMALL_STATE(129)] = 5886,
  [SMALL_STATE(130)] = 5914,
  [SMALL_STATE(131)] = 5942,
  [SMALL_STATE(132)] = 5970,
  [SMALL_STATE(133)] = 5998,
  [SMALL_STATE(134)] = 6020,
  [SMALL_STATE(135)] = 6039,
  [SMALL_STATE(136)] = 6058,
  [SMALL_STATE(137)] = 6077,
  [SMALL_STATE(138)] = 6096,
  [SMALL_STATE(139)] = 6115,
  [SMALL_STATE(140)] = 6139,
  [SMALL_STATE(141)] = 6163,
  [SMALL_STATE(142)] = 6187,
  [SMALL_STATE(143)] = 6204,
  [SMALL_STATE(144)] = 6221,
  [SMALL_STATE(145)] = 6235,
  [SMALL_STATE(146)] = 6249,
  [SMALL_STATE(147)] = 6263,
  [SMALL_STATE(148)] = 6277,
  [SMALL_STATE(149)] = 6291,
  [SMALL_STATE(150)] = 6305,
  [SMALL_STATE(151)] = 6319,
  [SMALL_STATE(152)] = 6333,
  [SMALL_STATE(153)] = 6353,
  [SMALL_STATE(154)] = 6373,
  [SMALL_STATE(155)] = 6385,
  [SMALL_STATE(156)] = 6399,
  [SMALL_STATE(157)] = 6413,
  [SMALL_STATE(158)] = 6424,
  [SMALL_STATE(159)] = 6441,
  [SMALL_STATE(160)] = 6460,
  [SMALL_STATE(161)] = 6471,
  [SMALL_STATE(162)] = 6490,
  [SMALL_STATE(163)] = 6503,
  [SMALL_STATE(164)] = 6520,
  [SMALL_STATE(165)] = 6539,
  [SMALL_STATE(166)] = 6554,
  [SMALL_STATE(167)] = 6571,
  [SMALL_STATE(168)] = 6590,
  [SMALL_STATE(169)] = 6601,
  [SMALL_STATE(170)] = 6620,
  [SMALL_STATE(171)] = 6631,
  [SMALL_STATE(172)] = 6642,
  [SMALL_STATE(173)] = 6656,
  [SMALL_STATE(174)] = 6670,
  [SMALL_STATE(175)] = 6684,
  [SMALL_STATE(176)] = 6700,
  [SMALL_STATE(177)] = 6716,
  [SMALL_STATE(178)] = 6732,
  [SMALL_STATE(179)] = 6748,
  [SMALL_STATE(180)] = 6762,
  [SMALL_STATE(181)] = 6776,
  [SMALL_STATE(182)] = 6790,
  [SMALL_STATE(183)] = 6804,
  [SMALL_STATE(184)] = 6820,
  [SMALL_STATE(185)] = 6836,
  [SMALL_STATE(186)] = 6848,
  [SMALL_STATE(187)] = 6864,
  [SMALL_STATE(188)] = 6878,
  [SMALL_STATE(189)] = 6892,
  [SMALL_STATE(190)] = 6908,
  [SMALL_STATE(191)] = 6924,
  [SMALL_STATE(192)] = 6940,
  [SMALL_STATE(193)] = 6954,
  [SMALL_STATE(194)] = 6968,
  [SMALL_STATE(195)] = 6982,
  [SMALL_STATE(196)] = 6998,
  [SMALL_STATE(197)] = 7014,
  [SMALL_STATE(198)] = 7028,
  [SMALL_STATE(199)] = 7044,
  [SMALL_STATE(200)] = 7058,
  [SMALL_STATE(201)] = 7074,
  [SMALL_STATE(202)] = 7084,
  [SMALL_STATE(203)] = 7100,
  [SMALL_STATE(204)] = 7114,
  [SMALL_STATE(205)] = 7130,
  [SMALL_STATE(206)] = 7146,
  [SMALL_STATE(207)] = 7157,
  [SMALL_STATE(208)] = 7170,
  [SMALL_STATE(209)] = 7181,
  [SMALL_STATE(210)] = 7192,
  [SMALL_STATE(211)] = 7203,
  [SMALL_STATE(212)] = 7214,
  [SMALL_STATE(213)] = 7225,
  [SMALL_STATE(214)] = 7236,
  [SMALL_STATE(215)] = 7247,
  [SMALL_STATE(216)] = 7258,
  [SMALL_STATE(217)] = 7269,
  [SMALL_STATE(218)] = 7278,
  [SMALL_STATE(219)] = 7291,
  [SMALL_STATE(220)] = 7302,
  [SMALL_STATE(221)] = 7313,
  [SMALL_STATE(222)] = 7324,
  [SMALL_STATE(223)] = 7337,
  [SMALL_STATE(224)] = 7348,
  [SMALL_STATE(225)] = 7359,
  [SMALL_STATE(226)] = 7367,
  [SMALL_STATE(227)] = 7375,
  [SMALL_STATE(228)] = 7385,
  [SMALL_STATE(229)] = 7395,
  [SMALL_STATE(230)] = 7405,
  [SMALL_STATE(231)] = 7415,
  [SMALL_STATE(232)] = 7423,
  [SMALL_STATE(233)] = 7431,
  [SMALL_STATE(234)] = 7439,
  [SMALL_STATE(235)] = 7447,
  [SMALL_STATE(236)] = 7454,
  [SMALL_STATE(237)] = 7461,
  [SMALL_STATE(238)] = 7468,
  [SMALL_STATE(239)] = 7475,
  [SMALL_STATE(240)] = 7482,
  [SMALL_STATE(241)] = 7489,
  [SMALL_STATE(242)] = 7496,
  [SMALL_STATE(243)] = 7503,
  [SMALL_STATE(244)] = 7510,
  [SMALL_STATE(245)] = 7517,
  [SMALL_STATE(246)] = 7524,
  [SMALL_STATE(247)] = 7531,
  [SMALL_STATE(248)] = 7538,
  [SMALL_STATE(249)] = 7545,
  [SMALL_STATE(250)] = 7552,
  [SMALL_STATE(251)] = 7559,
  [SMALL_STATE(252)] = 7566,
  [SMALL_STATE(253)] = 7573,
  [SMALL_STATE(254)] = 7580,
  [SMALL_STATE(255)] = 7587,
  [SMALL_STATE(256)] = 7594,
  [SMALL_STATE(257)] = 7601,
  [SMALL_STATE(258)] = 7608,
  [SMALL_STATE(259)] = 7615,
  [SMALL_STATE(260)] = 7622,
  [SMALL_STATE(261)] = 7629,
  [SMALL_STATE(262)] = 7636,
  [SMALL_STATE(263)] = 7643,
  [SMALL_STATE(264)] = 7650,
  [SMALL_STATE(265)] = 7657,
  [SMALL_STATE(266)] = 7664,
  [SMALL_STATE(267)] = 7671,
  [SMALL_STATE(268)] = 7678,
  [SMALL_STATE(269)] = 7685,
  [SMALL_STATE(270)] = 7692,
  [SMALL_STATE(271)] = 7699,
  [SMALL_STATE(272)] = 7706,
  [SMALL_STATE(273)] = 7713,
  [SMALL_STATE(274)] = 7720,
  [SMALL_STATE(275)] = 7727,
  [SMALL_STATE(276)] = 7734,
  [SMALL_STATE(277)] = 7741,
  [SMALL_STATE(278)] = 7748,
  [SMALL_STATE(279)] = 7755,
  [SMALL_STATE(280)] = 7762,
  [SMALL_STATE(281)] = 7769,
  [SMALL_STATE(282)] = 7776,
  [SMALL_STATE(283)] = 7783,
  [SMALL_STATE(284)] = 7790,
  [SMALL_STATE(285)] = 7797,
  [SMALL_STATE(286)] = 7804,
  [SMALL_STATE(287)] = 7811,
  [SMALL_STATE(288)] = 7818,
  [SMALL_STATE(289)] = 7825,
  [SMALL_STATE(290)] = 7832,
  [SMALL_STATE(291)] = 7839,
  [SMALL_STATE(292)] = 7846,
  [SMALL_STATE(293)] = 7853,
  [SMALL_STATE(294)] = 7860,
  [SMALL_STATE(295)] = 7867,
  [SMALL_STATE(296)] = 7874,
  [SMALL_STATE(297)] = 7881,
  [SMALL_STATE(298)] = 7888,
  [SMALL_STATE(299)] = 7895,
  [SMALL_STATE(300)] = 7902,
  [SMALL_STATE(301)] = 7909,
  [SMALL_STATE(302)] = 7916,
  [SMALL_STATE(303)] = 7923,
  [SMALL_STATE(304)] = 7930,
  [SMALL_STATE(305)] = 7937,
  [SMALL_STATE(306)] = 7944,
  [SMALL_STATE(307)] = 7951,
  [SMALL_STATE(308)] = 7958,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(288),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(159),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(299),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(275),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(260),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [33] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_command, 1, .production_id = 1),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(300),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(301),
  [41] = {.entry = {.count = 1, .reusable = false}}, SHIFT(302),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(274),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [47] = {.entry = {.count = 1, .reusable = false}}, SHIFT(62),
  [49] = {.entry = {.count = 1, .reusable = false}}, SHIFT(58),
  [51] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_command, 1, .production_id = 1),
  [55] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [57] = {.entry = {.count = 1, .reusable = false}}, SHIFT(169),
  [59] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [61] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [63] = {.entry = {.count = 1, .reusable = false}}, SHIFT(179),
  [65] = {.entry = {.count = 1, .reusable = false}}, SHIFT(182),
  [67] = {.entry = {.count = 1, .reusable = false}}, SHIFT(290),
  [69] = {.entry = {.count = 1, .reusable = false}}, SHIFT(291),
  [71] = {.entry = {.count = 1, .reusable = false}}, SHIFT(292),
  [73] = {.entry = {.count = 1, .reusable = false}}, SHIFT(283),
  [75] = {.entry = {.count = 1, .reusable = false}}, SHIFT(216),
  [77] = {.entry = {.count = 1, .reusable = false}}, SHIFT(60),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [81] = {.entry = {.count = 1, .reusable = false}}, SHIFT(54),
  [83] = {.entry = {.count = 1, .reusable = false}}, SHIFT(214),
  [85] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(40),
  [88] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(8),
  [91] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4),
  [93] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(25),
  [96] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(300),
  [99] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(301),
  [102] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(302),
  [105] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(274),
  [108] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(31),
  [111] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(62),
  [114] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(58),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4),
  [119] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(34),
  [122] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_command, 2, .production_id = 3),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_command, 2, .production_id = 3),
  [126] = {.entry = {.count = 1, .reusable = false}}, SHIFT(196),
  [128] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [130] = {.entry = {.count = 1, .reusable = false}}, SHIFT(210),
  [132] = {.entry = {.count = 1, .reusable = false}}, SHIFT(183),
  [134] = {.entry = {.count = 1, .reusable = false}}, SHIFT(86),
  [136] = {.entry = {.count = 1, .reusable = false}}, SHIFT(191),
  [138] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [140] = {.entry = {.count = 1, .reusable = false}}, SHIFT(48),
  [142] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [144] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [146] = {.entry = {.count = 1, .reusable = false}}, SHIFT(295),
  [148] = {.entry = {.count = 1, .reusable = false}}, SHIFT(296),
  [150] = {.entry = {.count = 1, .reusable = false}}, SHIFT(297),
  [152] = {.entry = {.count = 1, .reusable = false}}, SHIFT(259),
  [154] = {.entry = {.count = 1, .reusable = false}}, SHIFT(44),
  [156] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [158] = {.entry = {.count = 1, .reusable = false}}, SHIFT(57),
  [160] = {.entry = {.count = 1, .reusable = false}}, SHIFT(46),
  [162] = {.entry = {.count = 1, .reusable = false}}, SHIFT(204),
  [164] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [166] = {.entry = {.count = 1, .reusable = false}}, SHIFT(177),
  [168] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [170] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(48),
  [173] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(10),
  [176] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(26),
  [179] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(295),
  [182] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(296),
  [185] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(297),
  [188] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(259),
  [191] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(44),
  [194] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(63),
  [197] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(57),
  [200] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 2, .production_id = 4), SHIFT_REPEAT(46),
  [203] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [205] = {.entry = {.count = 1, .reusable = false}}, SHIFT(231),
  [207] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(231),
  [211] = {.entry = {.count = 1, .reusable = false}}, SHIFT(209),
  [213] = {.entry = {.count = 1, .reusable = false}}, SHIFT(289),
  [215] = {.entry = {.count = 1, .reusable = false}}, SHIFT(294),
  [217] = {.entry = {.count = 1, .reusable = false}}, SHIFT(261),
  [219] = {.entry = {.count = 1, .reusable = false}}, SHIFT(245),
  [221] = {.entry = {.count = 1, .reusable = false}}, SHIFT(232),
  [223] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [225] = {.entry = {.count = 1, .reusable = false}}, SHIFT(55),
  [227] = {.entry = {.count = 1, .reusable = false}}, SHIFT(233),
  [229] = {.entry = {.count = 1, .reusable = true}}, SHIFT(233),
  [231] = {.entry = {.count = 1, .reusable = false}}, SHIFT(221),
  [233] = {.entry = {.count = 1, .reusable = true}}, SHIFT(221),
  [235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [237] = {.entry = {.count = 1, .reusable = true}}, SHIFT(214),
  [239] = {.entry = {.count = 1, .reusable = false}}, SHIFT(223),
  [241] = {.entry = {.count = 1, .reusable = true}}, SHIFT(223),
  [243] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_value_path, 3),
  [245] = {.entry = {.count = 1, .reusable = false}}, SHIFT(285),
  [247] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_path, 3),
  [249] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_value_path_repeat1, 2),
  [251] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_value_path_repeat1, 2), SHIFT_REPEAT(285),
  [254] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_value_path_repeat1, 2),
  [256] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_value_path, 2),
  [258] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_path, 2),
  [260] = {.entry = {.count = 1, .reusable = false}}, SHIFT(305),
  [262] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_value_path_repeat1, 2), SHIFT_REPEAT(305),
  [265] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__expression, 1),
  [267] = {.entry = {.count = 1, .reusable = false}}, SHIFT(253),
  [269] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 1),
  [271] = {.entry = {.count = 1, .reusable = false}}, SHIFT(240),
  [273] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array, 3),
  [275] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 3),
  [277] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 3),
  [279] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 3),
  [281] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_command_substitution, 3),
  [283] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_command_substitution, 3),
  [285] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array, 2),
  [287] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 2),
  [289] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_file_path, 1),
  [291] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_file_path, 1),
  [293] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_array, 4),
  [295] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array, 4),
  [297] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_operator, 1),
  [299] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operator, 1),
  [301] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block, 2),
  [303] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block, 2),
  [305] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_range, 3, .production_id = 8),
  [307] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_range, 3, .production_id = 8),
  [309] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_table, 4),
  [311] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table, 4),
  [313] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 3),
  [315] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3),
  [317] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_table, 5),
  [319] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_table, 5),
  [321] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_command_repeat1, 1, .production_id = 2),
  [323] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_command_repeat1, 1, .production_id = 2),
  [325] = {.entry = {.count = 1, .reusable = false}}, SHIFT(236),
  [327] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(224),
  [331] = {.entry = {.count = 1, .reusable = true}}, SHIFT(226),
  [333] = {.entry = {.count = 1, .reusable = true}}, SHIFT(145),
  [335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [337] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [339] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(288),
  [342] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(159),
  [345] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(236),
  [348] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(120),
  [351] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(7),
  [354] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(115),
  [357] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(275),
  [360] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(2),
  [363] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(91),
  [366] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(260),
  [369] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2), SHIFT_REPEAT(59),
  [372] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_value_path_repeat1, 2), SHIFT_REPEAT(277),
  [375] = {.entry = {.count = 1, .reusable = true}}, SHIFT(277),
  [377] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3, .production_id = 5),
  [379] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_expression, 3, .production_id = 5),
  [381] = {.entry = {.count = 1, .reusable = false}}, SHIFT(121),
  [383] = {.entry = {.count = 1, .reusable = false}}, SHIFT(117),
  [385] = {.entry = {.count = 1, .reusable = false}}, SHIFT(127),
  [387] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parenthesized_math_expression, 3),
  [389] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_parenthesized_math_expression, 3),
  [391] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_variable_declaration, 4, .production_id = 9),
  [393] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_variable_declaration, 4, .production_id = 9),
  [395] = {.entry = {.count = 1, .reusable = false}}, SHIFT(119),
  [397] = {.entry = {.count = 1, .reusable = false}}, SHIFT(118),
  [399] = {.entry = {.count = 1, .reusable = false}}, SHIFT(125),
  [401] = {.entry = {.count = 1, .reusable = false}}, SHIFT(126),
  [403] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_math_mode, 2),
  [405] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_math_mode, 2),
  [407] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statement, 1),
  [409] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statement, 1),
  [411] = {.entry = {.count = 1, .reusable = true}}, SHIFT(257),
  [413] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_value_path_repeat1, 2), SHIFT_REPEAT(257),
  [416] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [418] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [420] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [422] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [424] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [426] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [428] = {.entry = {.count = 1, .reusable = false}}, SHIFT(130),
  [430] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [432] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [434] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [436] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [438] = {.entry = {.count = 1, .reusable = true}}, SHIFT(271),
  [440] = {.entry = {.count = 1, .reusable = true}}, SHIFT(306),
  [442] = {.entry = {.count = 1, .reusable = true}}, SHIFT(307),
  [444] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__statements_repeat1, 2),
  [446] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__statements_repeat1, 2),
  [448] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statements, 3),
  [450] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statements, 2),
  [452] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [454] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [456] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [458] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [460] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [462] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [464] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [466] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [468] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [470] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [472] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [474] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [476] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [478] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [480] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [482] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [484] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [486] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [488] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [490] = {.entry = {.count = 1, .reusable = true}}, SHIFT(154),
  [492] = {.entry = {.count = 1, .reusable = true}}, SHIFT(262),
  [494] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [496] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [498] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [500] = {.entry = {.count = 1, .reusable = true}}, SHIFT(244),
  [502] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_signature_repeat1, 2),
  [504] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_signature_repeat1, 2), SHIFT_REPEAT(142),
  [507] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_signature_repeat1, 2), SHIFT_REPEAT(155),
  [510] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_signature_repeat1, 2), SHIFT_REPEAT(143),
  [513] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag, 1),
  [515] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [517] = {.entry = {.count = 1, .reusable = true}}, SHIFT(256),
  [519] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 1),
  [521] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [523] = {.entry = {.count = 1, .reusable = true}}, SHIFT(170),
  [525] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 5, .production_id = 10),
  [527] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_definition, 5, .production_id = 10),
  [529] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 3),
  [531] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [533] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 4, .production_id = 6),
  [535] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_definition, 4, .production_id = 6),
  [537] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pipeline, 3),
  [539] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pipeline, 3),
  [541] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statements, 1),
  [543] = {.entry = {.count = 1, .reusable = false}}, SHIFT(70),
  [545] = {.entry = {.count = 1, .reusable = false}}, SHIFT(114),
  [547] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [549] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__statements, 2),
  [551] = {.entry = {.count = 1, .reusable = false}}, SHIFT(113),
  [553] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [555] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1),
  [557] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rest, 1),
  [559] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [561] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag, 4),
  [563] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [565] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag, 6),
  [567] = {.entry = {.count = 1, .reusable = true}}, SHIFT(269),
  [569] = {.entry = {.count = 1, .reusable = true}}, SHIFT(289),
  [571] = {.entry = {.count = 1, .reusable = true}}, SHIFT(294),
  [573] = {.entry = {.count = 1, .reusable = true}}, SHIFT(261),
  [575] = {.entry = {.count = 1, .reusable = true}}, SHIFT(227),
  [577] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 4),
  [579] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statements, 1),
  [581] = {.entry = {.count = 1, .reusable = false}}, SHIFT(72),
  [583] = {.entry = {.count = 1, .reusable = false}}, SHIFT(122),
  [585] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [587] = {.entry = {.count = 1, .reusable = true}}, SHIFT(201),
  [589] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_signature_repeat1, 1),
  [591] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_value_path_repeat1, 2), SHIFT_REPEAT(269),
  [594] = {.entry = {.count = 1, .reusable = false}}, SHIFT(133),
  [596] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [598] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_alias, 4, .production_id = 7),
  [600] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_alias, 4, .production_id = 7),
  [602] = {.entry = {.count = 1, .reusable = true}}, SHIFT(230),
  [604] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_rest, 3),
  [606] = {.entry = {.count = 1, .reusable = false}}, SHIFT(180),
  [608] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 2),
  [610] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_flag, 3),
  [612] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [614] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [616] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [618] = {.entry = {.count = 1, .reusable = false}}, SHIFT(137),
  [620] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [622] = {.entry = {.count = 1, .reusable = false}}, SHIFT(220),
  [624] = {.entry = {.count = 1, .reusable = false}}, SHIFT(96),
  [626] = {.entry = {.count = 1, .reusable = false}}, SHIFT(213),
  [628] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_column_header, 2),
  [630] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_column_header, 3),
  [632] = {.entry = {.count = 1, .reusable = true}}, SHIFT(212),
  [634] = {.entry = {.count = 1, .reusable = false}}, SHIFT(242),
  [636] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [638] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [640] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [642] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [644] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [646] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [648] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [650] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_table_repeat1, 2), SHIFT_REPEAT(14),
  [653] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_table_repeat1, 2),
  [655] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [657] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [659] = {.entry = {.count = 1, .reusable = true}}, SHIFT(211),
  [661] = {.entry = {.count = 1, .reusable = false}}, SHIFT(88),
  [663] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [665] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_array_repeat1, 2), SHIFT_REPEAT(17),
  [668] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_array_repeat1, 2),
  [670] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2), SHIFT_REPEAT(17),
  [673] = {.entry = {.count = 1, .reusable = false}}, SHIFT(97),
  [675] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [677] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_column_header_repeat1, 2), SHIFT_REPEAT(15),
  [680] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_column_header_repeat1, 2),
  [682] = {.entry = {.count = 1, .reusable = true}}, SHIFT(267),
  [684] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [686] = {.entry = {.count = 1, .reusable = true}}, SHIFT(270),
  [688] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_column_header_repeat1, 2), REDUCE(aux_sym_array_repeat1, 2),
  [691] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_array_repeat1, 2),
  [693] = {.entry = {.count = 1, .reusable = true}}, SHIFT(243),
  [695] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [697] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [699] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [701] = {.entry = {.count = 1, .reusable = true}}, SHIFT(287),
  [703] = {.entry = {.count = 1, .reusable = true}}, SHIFT(215),
  [705] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [707] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [709] = {.entry = {.count = 1, .reusable = true}}, SHIFT(206),
  [711] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_column_header, 3),
  [713] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_signature, 2),
  [715] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [717] = {.entry = {.count = 1, .reusable = true}}, SHIFT(194),
  [719] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [721] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [723] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [725] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [727] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [729] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [731] = {.entry = {.count = 1, .reusable = true}}, SHIFT(208),
  [733] = {.entry = {.count = 1, .reusable = true}}, SHIFT(276),
  [735] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [737] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [739] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [741] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [743] = {.entry = {.count = 1, .reusable = true}}, SHIFT(304),
  [745] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_signature, 3),
  [747] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [749] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [751] = {.entry = {.count = 1, .reusable = true}}, SHIFT(225),
  [753] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [755] = {.entry = {.count = 1, .reusable = true}}, SHIFT(185),
  [757] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_column_header, 4),
  [759] = {.entry = {.count = 1, .reusable = true}}, SHIFT(279),
  [761] = {.entry = {.count = 1, .reusable = true}}, SHIFT(219),
  [763] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [765] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [767] = {.entry = {.count = 1, .reusable = true}}, SHIFT(247),
  [769] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [771] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [773] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [775] = {.entry = {.count = 1, .reusable = true}}, SHIFT(149),
  [777] = {.entry = {.count = 1, .reusable = true}}, SHIFT(234),
  [779] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [781] = {.entry = {.count = 1, .reusable = true}}, SHIFT(217),
  [783] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [785] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [787] = {.entry = {.count = 1, .reusable = true}}, SHIFT(167),
  [789] = {.entry = {.count = 1, .reusable = true}}, SHIFT(284),
  [791] = {.entry = {.count = 1, .reusable = true}}, SHIFT(237),
  [793] = {.entry = {.count = 1, .reusable = true}}, SHIFT(238),
  [795] = {.entry = {.count = 1, .reusable = true}}, SHIFT(239),
  [797] = {.entry = {.count = 1, .reusable = true}}, SHIFT(181),
  [799] = {.entry = {.count = 1, .reusable = true}}, SHIFT(286),
  [801] = {.entry = {.count = 1, .reusable = true}}, SHIFT(250),
  [803] = {.entry = {.count = 1, .reusable = true}}, SHIFT(251),
  [805] = {.entry = {.count = 1, .reusable = true}}, SHIFT(252),
  [807] = {.entry = {.count = 1, .reusable = true}}, SHIFT(173),
  [809] = {.entry = {.count = 1, .reusable = true}}, SHIFT(266),
  [811] = {.entry = {.count = 1, .reusable = true}}, SHIFT(264),
  [813] = {.entry = {.count = 1, .reusable = true}}, SHIFT(265),
  [815] = {.entry = {.count = 1, .reusable = true}}, SHIFT(235),
  [817] = {.entry = {.count = 1, .reusable = true}}, SHIFT(172),
  [819] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [821] = {.entry = {.count = 1, .reusable = true}}, SHIFT(280),
  [823] = {.entry = {.count = 1, .reusable = true}}, SHIFT(281),
  [825] = {.entry = {.count = 1, .reusable = true}}, SHIFT(188),
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
