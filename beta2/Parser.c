#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "StructTools.h"




void ParseArguments(int argc, char *argv[], struct in_flags *flags, char **exp, char **filename, char **A_num){

  int path_flag = 0;
  bool updated = false;

  for (int i = 1; i<argc; i++){
    if(argv[i][0] == '-'){
      flags = UpdateFlag(argv[i][1], flags);

      if (flags->A_flag ==1 && updated == false) {
	*A_num = malloc(strlen(argv[i+1])+1);
	strcpy(*A_num,argv[i+1]);
	i++;
	updated = true;
      }
    }
    else if(path_flag == 0) {
      *exp = malloc(strlen(argv[i])+1);
      strcpy(*exp, argv[i]);
      path_flag=1;
    }
    else if(path_flag == 1 && argv[i][0] != '-') {
      *filename = malloc(strlen(argv[i])+1);
      strcpy(*filename, argv[i]);
    }

  }
  return;
}



Expression_t * ParseExpression(char *expression_string){

  Expression_t *parsed_expression = malloc((strlen(expression_string)+1)*sizeof(Expression_t));
  Expression_t character_struct;
  int exp_index = 0;

  for(unsigned int i=0; i<strlen(expression_string)+1; i++){
    character_struct.value = expression_string[i];
      if(expression_string[i] == '\\'){
	
        character_struct.expression_case = 0;
        character_struct.value = expression_string[i+1];
        parsed_expression[exp_index] = character_struct;
	exp_index++;
        i++;
        }
        
      else{
        if(expression_string[i] == '.') character_struct.expression_case = 1;
        else if(expression_string[i] == '(' || expression_string[i] == ')' ) character_struct.expression_case = 2;
        else if(expression_string[i] == '[' || expression_string[i] == ']' ) character_struct.expression_case = 3;
        else character_struct.expression_case = 0;
        parsed_expression[exp_index] = character_struct;
	exp_index++;
      }
      
    
  }
  return parsed_expression;
}

void BuildLineToPrint(struct in_flags *flags, Params_t text_parameters, char *line_to_print){

  if(flags->A_flag == 0){

    if(flags->n_flag == 1)
      sprintf(line_to_print, "%d:", text_parameters.line_num);

    if(flags->b_flag == 1)
      sprintf(line_to_print, "%s%d:",  line_to_print, text_parameters.offset);
  }


  else if (text_parameters.A_lines_to_print > 0){
    //print format for match (d:d:text)
    //print format for no match (d-d-text)
    
    
    if(flags->n_flag == 1){
      if(text_parameters.match == true)
	sprintf(line_to_print, "%d:", text_parameters.line_num);
      else sprintf(line_to_print, "%s%d-",  line_to_print, text_parameters.line_num);
    }
    if(flags->b_flag == 1){
      if(text_parameters.match == true)
	sprintf(line_to_print, "%s%d:",  line_to_print, text_parameters.offset);
      else sprintf(line_to_print, "%s%d-",  line_to_print, text_parameters.offset);
    }
  }

}
