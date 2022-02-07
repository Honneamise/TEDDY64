#include "ILM.h"
#include "ILM_utils.h"
#include "T20.h"

/**********/
int main(void)
{
    T20Init(0x24, LINE_SIZE, 0);

    T20Colors(0x7C70DA, 0x3E31A2, 0x7C70DA);

    T20AddLine("TEDDY 64");
    
    T20AddLine("ver. 1.0");

    ILM IL = {0};

    ILM_init(&IL);

    ILM_execute(&IL);

    T20Close();

    return 0;
}