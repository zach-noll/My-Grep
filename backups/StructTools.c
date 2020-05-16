#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// TBD stdio for debug only
#include <stdio.h>
#include "StructTools.h"
#include "FindMatch.h"

struct in_flags *InitFlags(struct in_flags *flags){
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

void InitParams(Line_Params *updated_params){

  strcpy(updated_params->text,""); 
  updated_params->match=false; 
  updated_params->offset=0;
  updated_params->line_num=0;
  updated_params->A_lines_to_print=0; 
  updated_params->match_id=0; 
  updated_params->last_line=0;

}

struct in_flags *UpdateFlag(char flag, struct in_flags *flag_struct){
  switch (flag){
  case 'i': flag_struct->i_flag = 1;
    break;
  case 'v': flag_struct->v_flag = 1;
    break;
  case 'c': flag_struct->c_flag = 1;
    break;
  case 'n': flag_struct->n_flag = 1;
    break;
  case 'b': flag_struct->b_flag = 1;
    break;
  case 'x': flag_struct->x_flag = 1;
    break;
  case 'A': flag_struct->A_flag = 1;
    break;
  case 'E': flag_struct->E_flag = 1;
    break;
  }
  return flag_struct;
}

int FindParsedExpressionLength(Expression_t *parsed_expression){
  int i=0;
  while(parsed_expression[i].value != '\0'){
	  i++;
  }
  return i+1;
}

Expression_t * BuildNewExpressionStruct(Expression_t *parsed_expression, int left){

  int length = FindParsedExpressionLength(parsed_expression);
  Expression_t *new_exp_arr_left = malloc(sizeof (parsed_expression)*length);
  Expression_t *new_exp_arr_right = malloc(sizeof (parsed_expression)*length);
  int i = 1;
  int index_left = 0, index_right = 0;
  while(parsed_expression[i].value != '|'){
    new_exp_arr_left[index_left] = parsed_expression[i];
    i++;
    index_left++;
  }
  i++;
  while(parsed_expression[i].value != ')') {
    new_exp_arr_right[index_right] = parsed_expression[i];
    i++;
    index_right++;
  }
  i++;
  while(parsed_expression[i].value != '\0'){
    new_exp_arr_left[index_left]=parsed_expression[i];
    new_exp_arr_right[index_right]=parsed_expression[i];
    i++;
    index_left++;
    index_right++;
  }

  new_exp_arr_left[index_left] = parsed_expression[i];
  new_exp_arr_right[index_right] = parsed_expression[i];

  if(left==1){
    free(new_exp_arr_right);
    return new_exp_arr_left;
  }
  else{
    free(new_exp_arr_left);
    return new_exp_arr_right;
  }
}

unsigned FindCleanExpLength(Expression_t *parsed_expression_array)
{
  unsigned i=0, length=0;
  while(parsed_expression_array[i].value != '\0'){
    if(parsed_expression_array[i].expression_case == 0 || parsed_expression_array[i].expression_case == 1){
      if(parsed_expression_array[i].expression_case != '-'){
        length++;
      }
    }
    if(parsed_expression_array[i].expression_case == 3){
      length--;
    }
    i++;
  }
  return length;
}


void UpdateMatch(Expression_t *parsed_expression_array, struct in_flags *flags,
 char* text, Line_Params* text_parameters)
{

  char *match_pos = IsMatchInLine(flags, text, parsed_expression_array);

  
  if (match_pos == NULL){
    text_parameters->match = false;

  }
  if(match_pos != NULL){

    if(flags->x_flag == 0){
      text_parameters->match = true;
    }
    
    else {
      if(flags->x_flag == 1 && FindCleanExpLength(parsed_expression_array) == strlen(text_parameters->text)-1){
        text_parameters->match = true;
      }
    

    else{
      text_parameters->match = false;
    }
    }
  }
  if(flags->v_flag == 1){
    text_parameters->match = !text_parameters->match;
  }
}

void UpdateLineNumber(Line_Params* text_parameters){
  text_parameters->line_num++;
}


void UpdateOffset(Line_Params* text_parameters){
  text_parameters->offset += (int)strlen(text_parameters->text);
}

void UpdateAnum(struct in_flags *flags, char *A_num, Line_Params* text_parameters){

  if(flags->A_flag == 1){
    if( text_parameters->A_lines_to_print > 0 ){
      text_parameters->A_lines_to_print--;
    }
    if(text_parameters->match == true){
      text_parameters->A_lines_to_print = 1+ atoi(A_num);
    }
  }
}

void UpdateText(char* text, Line_Params* text_parameters){
  strncpy(text_parameters->text, text, strlen(text)+1);

}


void UpdateFirstMatch(Line_Params* text_parameters){
  if(text_parameters->match == true)
  {
	  switch(text_parameters->match_id){
	    case 0:
  		text_parameters->match_id = 1;
  		break;
  	  case 1:
  		text_parameters->match_id = 2;
  		break;
	  }
  }

}

void UpdateParams(Expression_t *parsed_expression_array, struct in_flags *flags, 
char *text, char *A_num, Line_Params* updated_params){

  UpdateOffset(updated_params);
  UpdateText(text, updated_params);
  UpdateMatch(parsed_expression_array, flags, text, updated_params);
  UpdateLineNumber(updated_params);
  UpdateAnum(flags, A_num, updated_params);
  UpdateFirstMatch(updated_params);

}
