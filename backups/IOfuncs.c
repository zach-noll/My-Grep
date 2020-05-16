#define PREFIX_LENGTH 6

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Expression.h"

#include "UpdateLineParams.h"

#include "Parser.h"

void PrintLineFiller(Line_Params *text_parameters, char *A_num)
{
  bool ok = false;
  int line_difference = text_parameters->line_num - text_parameters->last_line;
  if (line_difference >= (int)atoi(A_num)) {
    ok = true;
  }
  if (text_parameters->match == true && text_parameters->line_num > 1) {
    if (text_parameters->match_id == 2 && ok) {
      printf("--\n");
    }
  }
}

void PrintLine(struct in_flags *flags, Line_Params *text_parameters, char *A_num)
{

  char *line_to_print = malloc(strlen(text_parameters->text) + PREFIX_LENGTH);
  memset(line_to_print, 0, strlen(text_parameters->text) + PREFIX_LENGTH);

  BuildLineToPrint(flags, *text_parameters, line_to_print);

  if (flags->A_flag == 0) {
    if (text_parameters->match == true) {
      strcat(line_to_print, text_parameters->text);
      printf("%s", line_to_print);
    }
  } else {
    PrintLineFiller(text_parameters, A_num);
    if (text_parameters->A_lines_to_print > 0) {
      strcat(line_to_print, text_parameters->text);
      printf("%s", line_to_print);
      text_parameters->last_line = text_parameters->line_num;
    }
  }
  free(line_to_print);
}

void ReadLines(Expression_t *parsed_expression_array, char *filename, struct in_flags *flags, char *A_num)
{

  FILE *fptr = NULL;
  char text[LINE_LENGTH] = {0};
  int num_of_matched_lines = 0;

  Line_Params updated_params;

  InitLineParams(&updated_params);

  if (filename == NULL) {
    fptr = stdin;
  } else {
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
      fprintf(stderr, "Error in opening %s file\n", filename);
      return;
    }
  }

  while (fgets(text, LINE_LENGTH, fptr) != NULL) {

    UpdateParams(parsed_expression_array, flags, text, A_num, &updated_params);

    if (flags->c_flag == 0) {
      PrintLine(flags, &updated_params, A_num);
    } else {
      if (flags->v_flag == 0 && updated_params.match == true) {
        num_of_matched_lines++;
      }
    }
  }

  if (flags->c_flag == 1) {
    printf("%d\n", num_of_matched_lines);
  }
  fclose(fptr);
}

void BuildLineToPrint(struct in_flags *flags, Line_Params text_parameters, char *line_to_print)
{

  if (flags->A_flag == 0) {

    if (flags->n_flag == 1) {
      sprintf(line_to_print, "%d:", text_parameters.line_num);
    }

    if (flags->b_flag == 1) {
      sprintf(line_to_print, "%s%d:", line_to_print, text_parameters.offset);
    }
  }

  else if (text_parameters.A_lines_to_print > 0) {
    if (flags->n_flag == 1) {
      if (text_parameters.match == true) {
        sprintf(line_to_print, "%d:", text_parameters.line_num);
      } else {
        sprintf(line_to_print, "%s%d-", line_to_print, text_parameters.line_num);
      }
    }
    if (flags->b_flag == 1) {
      if (text_parameters.match == true) {
        sprintf(line_to_print, "%s%d:", line_to_print, text_parameters.offset);
      } else {
        sprintf(line_to_print, "%s%d-", line_to_print, text_parameters.offset);
      }
    }
  }
}
