#define _GNU_SOURCE

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


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
		  parsed_expression+=4*sizeof(Expression_t)/8;//4 zach
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

char* strstr_Ecase(char *text, Expression_t *parsed_expression){
	while(*text != '\0')
	{
	  bool is_match = is_match_in_place(text,parsed_expression);
	  if(is_match){
		  return text;
	  }
	  text++;
	}
	return NULL;
}

char *IsMatchInLine(struct in_flags *flags, char* text, Expression_t *parsed_expression_array, char *exp){

  char* match_pos = NULL;

  if(flags->E_flag == 0){

    if (flags->i_flag == 1)  match_pos = strcasestr(text, exp);
    else  match_pos = strstr(text, exp);
  }

  else{
	match_pos = strstr_Ecase(text, parsed_expression_array);
    }
  return match_pos;
}