#define _GNU_SOURCE
#define LENGTH_OF_EXP_IN_BRACKETS 4

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "UpdateLineParams.h"

bool HandleRoundParanthesis(Expression_t *parsed_expression, char *text);

struct in_flags *InitFlags(struct in_flags *flags)
{
  flags->i_flag = 0;
  flags->v_flag = 0;
  flags->c_flag = 0;
  flags->n_flag = 0;
  flags->b_flag = 0;
  flags->x_flag = 0;
  flags->A_flag = 0;
  flags->E_flag = 0;
  return flags;
}

struct in_flags *UpdateFlag(char flag, struct in_flags *flag_struct)
{
  switch (flag) {
    case 'i':
      flag_struct->i_flag = 1;
      break;
    case 'v':
      flag_struct->v_flag = 1;
      break;
    case 'c':
      flag_struct->c_flag = 1;
      break;
    case 'n':
      flag_struct->n_flag = 1;
      break;
    case 'b':
      flag_struct->b_flag = 1;
      break;
    case 'x':
      flag_struct->x_flag = 1;
      break;
    case 'A':
      flag_struct->A_flag = 1;
      break;
    case 'E':
      flag_struct->E_flag = 1;
      break;
  }
  return flag_struct;
}

char *MakeLowerCase(char *text)
{
  unsigned i = 0;
  while (text[i] != '\0') {
    text[i] = tolower(text[i]);
    i++;
  }
  return text;
}

int ContinueScanning(const char *text, Expression_t *parsed_expression, int range_flag, int range_start, int range_end)
{

  if (*text != parsed_expression->value && parsed_expression->value != '.') {
    if (range_flag == 0) {
      return 0;
    } else {
      if ((*text) < range_start || (*text) > range_end) {
        return 0;
      }
    }
  } else {
    if (parsed_expression->expression_case == SQUARED) {
      return 0;
    }
  }
  return 1;
}

bool is_match_in_place(char *text, Expression_t *parsed_expression)
{

  unsigned char range_start = 0xff, range_end = 0xff;
  int range_flag;
  int offset;
  while (*text && parsed_expression->value != '\0') {
    range_flag = 0;
    offset = 1;
    switch (parsed_expression->expression_case) {
      case REGULAR_CHAR:
        break;
      case DOT:
        break;
      case ROUNDED:
        if (HandleRoundParanthesis(parsed_expression, text)) {
          return true;
        } else {
          break;
        }
      case SQUARED:
        range_start = parsed_expression[offset].value;
        offset += 2;
        range_end = parsed_expression[offset].value;
        range_flag = 1;
        parsed_expression += LENGTH_OF_EXP_IN_BRACKETS;
        break;
    }
    if (ContinueScanning(text, parsed_expression, range_flag, range_start, range_end) == 0) {
      return 0;
    }
    {
      text++;
      parsed_expression++;
    }
  }
  return (parsed_expression->value == '\0');
}
bool HandleRoundParanthesis(Expression_t *parsed_expression, char *text)
{
  bool left = 1, right = 0;
  Expression_t *fixed_expression_left;
  Expression_t *fixed_expression_right;
  fixed_expression_left = BuildNewExpressionStruct(parsed_expression, left);
  fixed_expression_right = BuildNewExpressionStruct(parsed_expression, right);
  bool is_match_left = is_match_in_place(text, fixed_expression_left);
  bool is_match_right = is_match_in_place(text, fixed_expression_right);
  if (is_match_left || is_match_right) {
    free(fixed_expression_left);
    free(fixed_expression_right);
    return true;
  }
  free(fixed_expression_left);
  free(fixed_expression_right);
  return false;
}

char *strstr_Ecase(struct in_flags *flags, char *text, Expression_t *parsed_expression)
{

  while (*text != '\0') {
    if (flags->i_flag == 1) {
      text = MakeLowerCase(text);
    }
    bool is_match = is_match_in_place(text, parsed_expression);
    if (is_match) {
      return text;
    }
    text++;
  }
  return NULL;
}

char *IsMatchInLine(struct in_flags *flags, char *text, Expression_t *parsed_expression_array)
{

  char *match_pos = NULL;

  int real_exp_len = FindParsedExpressionLength(parsed_expression_array);
  char *real_exp = malloc(real_exp_len);
  memset(real_exp, 0, real_exp_len);

  BuildExpressionFromStruct(parsed_expression_array, real_exp);

  if (flags->E_flag == 0) {

    if (flags->i_flag == 1) {
      match_pos = strcasestr(text, real_exp);
    } else {
      match_pos = strstr(text, real_exp);
    }
  }

  else {
    match_pos = strstr_Ecase(flags, text, parsed_expression_array);
  }
  free(real_exp);
  return match_pos;
}

void UpdateMatch(Expression_t *parsed_expression_array, struct in_flags *flags, char *text,
                 Line_Params *text_parameters)
{

  char *match_pos = IsMatchInLine(flags, text, parsed_expression_array);

  if (match_pos == NULL) {
    text_parameters->match = false;
  }
  if (match_pos != NULL) {

    if (flags->x_flag == 0) {
      text_parameters->match = true;
    }

    else {
      if (flags->x_flag == 1 && FindCleanExpLength(parsed_expression_array) == strlen(text_parameters->text) - 1) {
        text_parameters->match = true;
      }

      else {
        text_parameters->match = false;
      }
    }
  }
  if (flags->v_flag == 1) {
    text_parameters->match = !text_parameters->match;
  }
}
