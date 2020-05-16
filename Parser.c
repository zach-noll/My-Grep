#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "IOfuncs.h"
#include "UpdateLineParams.h"

void ParseArguments(int argc, char *argv[], struct in_flags *flags, char **exp, char **filename, char **A_num)
{

  int path_flag = 0;
  bool updated = false;

  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      flags = UpdateFlag(argv[i][1], flags);

      if (flags->A_flag == 1 && updated == false) {
        *A_num = malloc(strlen(argv[i + 1]) + 1);
        strcpy(*A_num, argv[i + 1]);
        i++;
        updated = true;
      }
    } else if (path_flag == 0) {
      *exp = malloc(strlen(argv[i]) + 1);
      strcpy(*exp, argv[i]);
      path_flag = 1;
    } else if (path_flag == 1 && argv[i][0] != '-') {
      *filename = malloc(strlen(argv[i]) + 1);
      strcpy(*filename, argv[i]);
    }
  }
  return;
}

Expression_t *ParseExpression(struct in_flags *flags, char *expression_string)
{

  Expression_t *parsed_expression = malloc((strlen(expression_string) + 1) * sizeof(Expression_t));
  Expression_t character_struct;
  int exp_index = 0;

  for (unsigned int i = 0; i < strlen(expression_string) + 1; i++) {
    if (flags->i_flag == 0) {
      character_struct.value = expression_string[i];
    } else {
      character_struct.value = tolower(expression_string[i]);
    }
    if (expression_string[i] == '\\') {

      character_struct.expression_case = REGULAR_CHAR;
      character_struct.value = expression_string[i + 1];
      parsed_expression[exp_index] = character_struct;
      exp_index++;
      i++;
    }

    else {
      if (expression_string[i] == '.') {
        character_struct.expression_case = DOT;
      } else if (expression_string[i] == '(' || expression_string[i] == ')') {
        character_struct.expression_case = ROUNDED;
      } else if (expression_string[i] == '[' || expression_string[i] == ']') {
        character_struct.expression_case = SQUARED;
      } else {
        character_struct.expression_case = REGULAR_CHAR;
      }
      parsed_expression[exp_index] = character_struct;
      exp_index++;
    }
  }
  return parsed_expression;
}
