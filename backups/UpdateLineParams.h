#ifndef UPDATELINEPARAMS_H
#define UPDATELINEPARAMS_H

#define LINE_LENGTH 255  // tbd

struct in_flags {
  int i_flag, v_flag, c_flag, n_flag, b_flag, x_flag, A_flag, E_flag;
};

typedef struct {
  char text[LINE_LENGTH];
  bool match;
  int offset;
  int line_num;
  int A_lines_to_print;
  int match_id;
  int last_line;
} Line_Params;

char *MakeLowerCase(char *text);

void UpdateParams(Expression_t *parsed_expression_array, struct in_flags *flags, char *text, char *A_num,
                  Line_Params *updated_params);

struct in_flags *UpdateFlag(char flag, struct in_flags *flag_struct);

struct in_flags *InitFlags(struct in_flags *flags);

void InitLineParams(Line_Params *updated_params);

#endif
