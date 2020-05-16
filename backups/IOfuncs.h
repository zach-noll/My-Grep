#ifndef IOFUNCS_H
#define IOFUNCS_H

void ReadLines(Expression_t *parsed_expression_array, char *filename, struct in_flags *flags, char *A_num);
void BuildLineToPrint(struct in_flags *flags, Line_Params text_parameters, char *line_to_print);
#endif