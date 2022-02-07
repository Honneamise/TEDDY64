#ifndef T20_H
#define T20_H

void T20Init(int rows, int cols, char *font_file);

void T20Close();

void T20Colors(int fgcolor, int bgcolor, int ctxcolor);

int T20Run();

void T20Clear();

void T20AddLine(char *str);

char *T20ReadLine();

void T20AddChar(char c);//extra function

#endif
