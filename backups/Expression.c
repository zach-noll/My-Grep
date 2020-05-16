#include <stdbool.h>
#include <stdlib.h>

#include "Expression.h"

#include "UpdateLineParams.h"

int FindParsedExpressionLength(Expression_t *parsed_expression)
{
  int i = 0;
  while (parsed_expression[i].value != '\0') {
    i++;
  }
  return i + 1;
}

Expression_t *BuildNewExpressionStruct(Expression_t *parsed_expression, int left)
{

  int length = FindParsedExpressionLength(parsed_expression);
  Expression_t *new_exp_arr_left = malloc(sizeof(parsed_expression) * length);
  Expression_t *new_exp_arr_right = malloc(sizeof(parsed_expression) * length);
  int i = 1;
  int index_left = 0, index_right = 0;
  while (parsed_expression[i].value != '|') {
    new_exp_arr_left[index_left] = parsed_expression[i];
    i++;
    index_left++;
  }
  i++;
  while (parsed_expression[i].value != ')') {
    new_exp_arr_right[index_right] = parsed_expression[i];
    i++;
    index_right++;
  }
  i++;
  while (parsed_expression[i].value != '\0') {
    new_exp_arr_left[index_left] = parsed_expression[i];
    new_exp_arr_right[index_right] = parsed_expression[i];
    i++;
    index_left++;
    index_right++;
  }

  new_exp_arr_left[index_left] = parsed_expression[i];
  new_exp_arr_right[index_right] = parsed_expression[i];

  if (left == 1) {
    free(new_exp_arr_right);
    return new_exp_arr_left;
  } else {
    free(new_exp_arr_left);
    return new_exp_arr_right;
  }
}

unsigned FindCleanExpLength(Expression_t *parsed_expression_array)
{
  unsigned i = 0, length = 0;
  while (parsed_expression_array[i].value != '\0') {
    bool regular_char_case = parsed_expression_array[i].expression_case == REGULAR_CHAR;
    bool dot_case = parsed_expression_array[i].expression_case == DOT;
    if (regular_char_case || dot_case) {
      if (parsed_expression_array[i].expression_case != '-') {
        length++;
      }
    }
    if (parsed_expression_array[i].expression_case == SQUARED) {
      length--;
    }
    i++;
  }
  return length;
}

void BuildExpressionFromStruct(Expression_t *parsed_expression, char *exp)  // TBD LINE_LENGTH
{
  int exp_length = 0;
  unsigned i = 0;
  while (parsed_expression[i].value != 0) {
    exp_length++;
    i++;
  }

  for (i = 0; i < (unsigned)exp_length; i++) {
    exp[i] = parsed_expression[i].value;
  }
  exp[exp_length] = '\0';
}
