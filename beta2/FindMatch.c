#define _GNU_SOURCE

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//TBD - stdio only for debug
#include <stdio.h>

#include "StructTools.h"



bool is_match_in_place(char *text, Expression_t *parsed_expression){

	unsigned char range_start = 0xff, range_end = 0xff;
	int range_flag;
	int offset;
	while(*text && parsed_expression->value != '\0' )
	{
	  range_flag = 0;
	  offset = 1;
	  switch(parsed_expression->expression_case){

		case 0:
		  break;
		case 1:
		  break;
		case 2:
		  
		  break;
		case 3:
		  range_start = parsed_expression[offset].value;
		  offset+=2;
		  range_end = parsed_expression[offset].value;
		  range_flag = 1;
		  parsed_expression+=4*sizeof(Expression_t)/8;//TBD check if sizeof is needed 4 zach
		  break;
	  }

	  if(*text != parsed_expression->value && parsed_expression->value != '.'){

	    if(range_flag == 0)
	      return 0;

	    else if((*text) < range_start || (*text) >= range_end)
	      return 0;
	    
	  }
	  
	  text++;
	  parsed_expression++;
	}
	return (parsed_expression->value == '\0');
}

char* strstr_Ecase(struct in_flags *flags, char *text, Expression_t *parsed_expression){
	
     
  while(*text != '\0')
	{
    if(flags->i_flag == 1) *text = tolower(*text);
	  bool is_match = is_match_in_place(text,parsed_expression);
	  if(is_match){
		  return text;
	  }
	  text++;
	}
	return NULL;
}

void BuildExpressionFromStruct(Expression_t *parsed_expression, char *exp) //TBD LINE_LENGTH
{
  int exp_length = 0;
  //char* exp=malloc(exp_length+1);
  unsigned i=0;
  while (parsed_expression[i].value != 0){
    exp_length++;
    i++;
  }

  for(i=0; i< exp_length; i++)
   {
	exp[i] = parsed_expression[i].value;
   }
   exp[exp_length] = '\0';
}

char *IsMatchInLine(struct in_flags *flags, char* text, Expression_t *parsed_expression_array, char *exp){

  char* match_pos = NULL;
  char real_exp[LINE_LENGTH];
  BuildExpressionFromStruct(parsed_expression_array, real_exp);

  //strcpy(real_exp, exp1);
  //for(int i=0 ;i<LINE_LENGTH; i++) printf("%c", real_exp[i]);
  //printf("exp is: %s\n", real_exp);
  if(flags->E_flag == 0){

    if (flags->i_flag == 1)  match_pos = strcasestr(text, real_exp);
    else  match_pos = strstr(text, real_exp);
  }

  else{
	match_pos = strstr_Ecase(flags, text, parsed_expression_array);
    }
  //free(exp1);
  return match_pos;
}
