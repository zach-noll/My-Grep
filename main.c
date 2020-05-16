#include <stdbool.h>
#include <stdlib.h>

#include "Expression.h"
#include "IOfuncs.h"
#include "Parser.h"
#include "UpdateLineParams.h"

void FreeMem(struct in_flags *flags, char *A_num, char *filename, char *exp, Expression_t *parsed_expression)
{

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

  ParseArguments(argc, argv, flags, &exp, &filename, &A_num);

  parsed_expression_array = ParseExpression(flags, exp);

  ReadLines(parsed_expression_array, filename, flags, A_num);

  FreeMem(flags, A_num, filename, exp, parsed_expression_array);

  return 0;
}
