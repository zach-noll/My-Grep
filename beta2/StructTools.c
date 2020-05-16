#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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

void InitParams(Params_t *updated_params){

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

void UpdateMatch(Expression_t *parsed_expression_array, struct in_flags *flags,
 char* text, Params_t* text_parameters,char *exp)
{

  char *match_pos = IsMatchInLine(flags, text, parsed_expression_array, exp);

  
  if (match_pos == NULL){
    text_parameters->match = false;

  }
  if(match_pos != NULL){

    if(flags->x_flag == 0)
      text_parameters->match = true;

    else if(flags->x_flag == 1 && strlen(exp) == strlen(text_parameters->text)-1)
      text_parameters->match = true;

    else text_parameters->match = false;
  }
  if(flags->v_flag == 1)
    text_parameters->match = !text_parameters->match;
}

void UpdateLineNumber(Params_t* text_parameters){
  text_parameters->line_num++;
}


void UpdateOffset(Params_t* text_parameters){
  text_parameters->offset += (int)strlen(text_parameters->text);
}

void UpdateAnum(struct in_flags *flags, char *A_num, Params_t* text_parameters){

  if(flags->A_flag == 1){
    if( text_parameters->A_lines_to_print > 0 )//&& text_parameters->match == false)
      text_parameters->A_lines_to_print--;
    if(text_parameters->match == true)
      text_parameters->A_lines_to_print = 1+ atoi(A_num);
  }
}

void UpdateText(char* text, Params_t* text_parameters){
  strncpy(text_parameters->text, text, strlen(text)+1);

}


void UpdateFirstMatch(Params_t* text_parameters){
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
char *text, char *A_num, Params_t* updated_params,char *exp ){

  UpdateOffset(updated_params);
  UpdateText(text, updated_params);
  UpdateMatch(parsed_expression_array, flags, text, updated_params,exp);
  UpdateLineNumber(updated_params);
  UpdateAnum(flags, A_num, updated_params);
  UpdateFirstMatch(updated_params);

}
