#ifndef ILM_UTILS_H
#define ILM_UTILS_H

#include "ILM.h"

int ILM_skip_spaces(ILM *IL);

int ILM_read_until_blank(ILM *IL);

int ILM_read_until_is_digit(ILM *IL);

void ILM_line_clear(uint8_t *line);

int ILM_line_isempty(uint8_t *p);

int ILM_line_isnumber(uint8_t *p);

uint8_t *ILM_line_skipblanks(uint8_t *p);

uint8_t *ILM_line_skipspaces(uint8_t *p);

uint8_t *ILM_line_tokenend(uint8_t *p);

#endif