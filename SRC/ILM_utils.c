//std
#include "ctype.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//ilm
#include "ILM.h"


/**********/
int ILM_skip_spaces(ILM *IL)
{
    while( IL->CURSOR<LINE_SIZE && IL->LINES[IL->CURSOR_LINE][IL->CURSOR]!=0 && 
        ( IL->LINES[IL->CURSOR_LINE][IL->CURSOR]==' ' ||  IL->LINES[IL->CURSOR_LINE][IL->CURSOR]=='\t' ))
    {
        IL->CURSOR++;
    }

    if(IL->CURSOR == LINE_SIZE || IL->LINES[IL->CURSOR_LINE][IL->CURSOR] == 0) { return -1; }
    
    return 0;
}

/**********/
int ILM_read_until_blank(ILM *IL)
{
    while( IL->CURSOR<LINE_SIZE && IL->LINES[IL->CURSOR_LINE][IL->CURSOR]!=0 && 
     IL->LINES[IL->CURSOR_LINE][IL->CURSOR]!=' ' &&  IL->LINES[IL->CURSOR_LINE][IL->CURSOR]!='\t'
    &&  IL->LINES[IL->CURSOR_LINE][IL->CURSOR]!='\r' &&  IL->LINES[IL->CURSOR_LINE][IL->CURSOR]!='\n' )
    {
        IL->CURSOR++;
    }

    if(IL->CURSOR == LINE_SIZE || IL->LINES[IL->CURSOR_LINE][IL->CURSOR] == 0) { return -1; }
    
    return 0;
}

/**********/
int ILM_read_until_is_digit(ILM *IL)
{
    while( IL->CURSOR<LINE_SIZE && IL->LINES[IL->CURSOR_LINE][IL->CURSOR]!=0 && 
     isdigit(IL->LINES[IL->CURSOR_LINE][IL->CURSOR]) ) 
    {
        IL->CURSOR++;
    }

    if(IL->CURSOR == LINE_SIZE || IL->LINES[IL->CURSOR_LINE][IL->CURSOR] == 0) { return -1; }
    
    return 0;
}


/**********/
void ILM_line_clear(uint8_t *line)
{
    memset(line,0x00,LINE_SIZE);
}

/**********/
int ILM_line_isempty(uint8_t *p)
{
	int len = strlen((char*)p);

	int res = 1;

	for(int i=0;i<len;i++)
	{
		if( p[i]!=0 && p[i]!=' ' && p[i]!='\t' && p[i]!='\r' && p[i]!='\n') { res=0; break; }

		else {  res=1; }
	}

	return res;
}

/**********/
int ILM_line_isnumber(uint8_t *p)
{
	int len = strlen((char*)p);

	int res = 0;

	for(int i=0;i<len;i++)
	{
		if(isdigit(p[i])) { res = 1; }
		else { res=0; break;}
	}

	return res;
}


/**********/
uint8_t *ILM_line_skipblanks(uint8_t *p)
{
	if(p==NULL){ return NULL; }

	while( (*p!=0) && ( *p==' ' || *p=='\t' || *p=='\r' || *p=='\n' ))
	{
		p++;
	}

	if(*p==0){ return NULL; }

	return p;
}

/**********/
uint8_t *ILM_line_skipspaces(uint8_t *p)
{
	if(p==NULL){ return NULL; }

	while( (*p!=0) && ( *p==' ' || *p=='\t'))
	{
		p++;
	}

	if(*p==0){ return NULL; }

	return p;
}

/**********/
uint8_t *ILM_line_tokenend(uint8_t *p)
{
	if(p==NULL){ return NULL; }
	
	while((*p!=0) && ( *p!=' ' && *p!='\t' && *p!='\r' && *p!='\n' ))
	{
		p++;
	}

	return p;
}
