#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "StructTools.h"
#include "Parser.h"

void PrintLineFiller(Params_t* text_parameters, char *A_num)
{
  bool ok = false;
  int line_difference = text_parameters->line_num - text_parameters->last_line;
    if(line_difference > (int)atoi(A_num)) 
      ok = true;
    if(text_parameters->match == true && text_parameters->line_num > 1) 
      if(text_parameters->match_id == 2 && ok)
	printf("--\n");
}

void PrintLine(struct in_flags *flags, Params_t* text_parameters, char *A_num){

  char line_to_print[LINE_LENGTH] = { 0 };

  BuildLineToPrint(flags, *text_parameters, line_to_print);

  if(flags->A_flag == 0){
    if(text_parameters->match == true) {
      strcat(line_to_print, text_parameters->text);
      printf("%s", line_to_print);
    }
  }
  else{
    PrintLineFiller(text_parameters, A_num);
    if(text_parameters->A_lines_to_print > 0){
      strcat(line_to_print, text_parameters->text);
      printf("%s", line_to_print);
      text_parameters->last_line = text_parameters->line_num;
    }

  }
}

void ReadLines(Expression_t *parsed_expression_array, char *filename, struct in_flags *flags, char *A_num, char *exp){

  FILE *fptr = NULL;
  char text[LINE_LENGTH] = { 0 };
  int num_of_matched_lines = 0;
  

  Params_t updated_params;

  InitParams(&updated_params);

  if(filename == NULL) fptr = stdin;
  else fptr = fopen(filename, "r"); //add case for NULL pointer

  while(fgets(text, LINE_LENGTH, fptr) != NULL){

    UpdateParams(parsed_expression_array, flags, text,A_num, &updated_params, exp);

    if(flags->c_flag == 0) PrintLine(flags, &updated_params, A_num);

    else{
      if(flags->v_flag == 0 && updated_params.match == true)
	num_of_matched_lines++;
    }
  }

  if(flags->c_flag == 1) printf("%d\n", num_of_matched_lines);
  
}

