#include <stdlib.h>
#include "StructTools.h"
#include "Parser.h"
#include "IOfuncs.h"

void FreeMem(struct in_flags *flags, char *A_num, char *filename, char *exp, Expression_t *parsed_expression){
  
  free(A_num);

  free(flags);

  free(filename);

  free(exp);

  free(parsed_expression);
}

int main(int argc, char *argv[])
{

  struct in_flags *flags = malloc(sizeof(struct in_flags));

  char *exp = NULL; 
  char *filename = NULL;
  char *A_num = NULL;

  Expression_t *parsed_expression_array = NULL; 

  InitFlags(flags);

  ParseArguments(argc, argv, flags, &exp, &filename, &A_num);//double level of indirection, kind of confusing

  parsed_expression_array = ParseExpression(exp);
  
  ReadLines(parsed_expression_array, filename, flags, A_num, exp);

  FreeMem(flags, A_num, filename, exp, parsed_expression_array);

  return 0;
}
