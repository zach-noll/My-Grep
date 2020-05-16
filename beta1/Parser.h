#ifndef PARSER_H
#define PARSER_H



void ParseArguments(int argc, char *argv[], struct in_flags *flags, char **exp, char **filename, char **A_num);

Expression_t * ParseExpression(char *expression_string);

void BuildLineToPrint(struct in_flags *flags, Params_t text_parameters, char *line_to_print);

#endif