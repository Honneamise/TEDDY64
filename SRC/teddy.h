#ifndef TEDDY_H
#define TEDDY_H

void TeddyInit(int rows, int cols, char *font_file);

void TeddyClose();

void TeddyColors(int fgcolor, int bgcolor, int ctxcolor);

int TeddyRun();

void TeddyClear();

void TeddyAddChar(char c);

void TeddyAddLine(char *str);

char *TeddyReadLine();

#endif
