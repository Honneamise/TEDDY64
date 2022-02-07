#ifndef ILM_H
#define ILM_H

//includes
#include "stdint.h"

//defines
#define MEMORY_SIZE         0xFFFF
#define STACK_SIZE          0xFF
#define LINE_SIZE           0x40
#define MAX_LINES           0xFF
#define LINES_STACK_SIZE    0xFF
#define AESTK_SIZE          0xFF

#define ILM_COLLECTOR_POINT 0x02
#define ILM_EXECUTOR_POINT  0x0A

#define VARIABLES_SIZE      0x1A
#define VARIABLE_OFFSET     0x41

typedef struct ILM
{
    uint8_t VMODE;

	uint16_t PC;
    
    uint8_t MEM[MEMORY_SIZE];
    
    uint8_t SP;
    
    uint16_t STACK[STACK_SIZE];
	
    uint8_t LBUF[LINE_SIZE];

    uint8_t CURSOR_LINE;

    uint8_t CURSOR; 

    uint8_t LINES[MAX_LINES][LINE_SIZE];

    uint8_t LINES_SP;

    uint8_t LINES_STACK[LINES_STACK_SIZE];

    uint8_t AESTK_SP;

    int AESTK[AESTK_SIZE];

    int VARIABLES[VARIABLES_SIZE];

}ILM;

/**********/
void ILM_EXIT(char *str, ...);

void ILM_error(ILM *IL, char *str);

void ILM_init(ILM *IL);

void ILM_reset(ILM *IL);

void ILM_execute(ILM *IL);

void ILM_execute_ins(ILM *IL);

void ILM_NOP(ILM *IL);
void ILM_TST(ILM *IL);
void ILM_CALL(ILM *IL);
void ILM_RTN(ILM *IL);
void ILM_DONE(ILM *IL);
void ILM_JMP(ILM *IL);
void ILM_PRS(ILM *IL);
void ILM_PRN(ILM *IL);
void ILM_SPC(ILM *IL);
void ILM_NLINE(ILM *IL);
void ILM_NXT(ILM *IL);
void ILM_XFER(ILM *IL);
void ILM_SAV(ILM *IL);
void ILM_RSTR(ILM *IL);
void ILM_CMPR(ILM *IL);
void ILM_LIT(ILM *IL);
void ILM_INNUM(ILM *IL);
void ILM_FIN(ILM *IL);
void ILM_ERR(ILM *IL);
void ILM_ADD(ILM *IL);
void ILM_SUB(ILM *IL);
void ILM_NEG(ILM *IL);
void ILM_MUL(ILM *IL);
void ILM_DIV(ILM *IL);
void ILM_STORE(ILM *IL);
void ILM_TSTV(ILM *IL);
void ILM_TSTN(ILM *IL);
void ILM_IND(ILM *IL);
void ILM_LST(ILM *IL);
void ILM_INIT(ILM *IL);
void ILM_GETLINE(ILM *IL);
void ILM_TSTL(ILM *IL);
void ILM_INSRT(ILM *IL);
void ILM_XINIT(ILM *IL);
void ILM_MODE(ILM *IL);

#endif