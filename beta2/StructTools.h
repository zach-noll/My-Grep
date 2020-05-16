#ifndef STRUCTTOOLS_H
#define STRUCTTOOLS_H

#define LINE_LENGTH 255 //tbd
#include <stdbool.h>

typedef struct {

  int expression_case; //0 - 'any normal character', 1 - '.', 2 - '()', 3 - '[]'
  char value;

}Expression_t;


struct in_flags{
  int i_flag, v_flag, c_flag, n_flag, b_flag, x_flag, A_flag, E_flag;
};

typedef struct { //TBD - change name of typedef
  char text[LINE_LENGTH];
  bool match;
  int offset;
  int line_num;
  int A_lines_to_print;
  int match_id;
  int last_line;
}Params_t;

char *IsMatchInLine(struct in_flags *flags, char* text, Expression_t *parsed_expression_array, char *exp);

void UpdateParams(Expression_t *parsed_expression_array, 
  struct in_flags *flags, char *text, char *A_num, Params_t* updated_params,char *exp);

struct in_flags *UpdateFlag(char flag, struct in_flags *flag_struct);

struct in_flags *InitFlags(struct in_flags *flags);

void InitParams(Params_t *updated_params);


#endif