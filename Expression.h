#ifndef EXPRESSION_H
#define EXPRESSION_H

enum exp_case { REGULAR_CHAR, DOT, ROUNDED, SQUARED };

typedef struct {

  enum exp_case expression_case;
  char value;

} Expression_t;

int FindParsedExpressionLength(Expression_t *parsed_expression);

Expression_t *BuildNewExpressionStruct(Expression_t *parsed_expression, int left);

unsigned FindCleanExpLength(Expression_t *parsed_expression_array);

void BuildExpressionFromStruct(Expression_t *parsed_expression, char *exp);

#endif
