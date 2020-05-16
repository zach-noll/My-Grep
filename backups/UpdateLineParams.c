#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "Expression.h"

#include "UpdateLineParams.h"

#include "FindMatch.h"

void InitLineParams(Line_Params* updated_params)
{

  strcpy(updated_params->text, "");
  updated_params->match = false;
  updated_params->offset = 0;
  updated_params->line_num = 0;
  updated_params->A_lines_to_print = 0;
  updated_params->match_id = 0;
  updated_params->last_line = 0;
}

void UpdateLineNumber(Line_Params* text_parameters) { text_parameters->line_num++; }

void UpdateOffset(Line_Params* text_parameters) { text_parameters->offset += (int)strlen(text_parameters->text); }

void UpdateAnum(struct in_flags* flags, char* A_num, Line_Params* text_parameters)
{

  if (flags->A_flag == 1) {
    if (text_parameters->A_lines_to_print > 0) {
      text_parameters->A_lines_to_print--;
    }
    if (text_parameters->match == true) {
      text_parameters->A_lines_to_print = 1 + atoi(A_num);
    }
  }
}

void UpdateText(char* text, Line_Params* text_parameters) { strncpy(text_parameters->text, text, strlen(text) + 1); }

void UpdateFirstMatch(Line_Params* text_parameters)
{
  if (text_parameters->match == true) {
    switch (text_parameters->match_id) {
      case 0:
        text_parameters->match_id = 1;
        break;
      case 1:
        text_parameters->match_id = 2;
        break;
    }
  }
}

void UpdateParams(Expression_t* parsed_expression_array, struct in_flags* flags, char* text, char* A_num,
                  Line_Params* updated_params)
{

  UpdateOffset(updated_params);
  UpdateText(text, updated_params);
  UpdateMatch(parsed_expression_array, flags, text, updated_params);
  UpdateLineNumber(updated_params);
  UpdateAnum(flags, A_num, updated_params);
  UpdateFirstMatch(updated_params);
}
