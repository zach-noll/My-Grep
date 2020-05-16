#ifndef FINDMATCH_H
#define FINDMATCH_H

#include "Expression.h"
#include "UpdateLineParams.h"

void UpdateMatch(Expression_t *parsed_expression_array, struct in_flags *flags, char *text,
                 Line_Params *text_parameters);

#endif
