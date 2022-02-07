#include "ILM.h"
#include "ILM_utils.h"
#include "teddy.h"

/**********/
int main(void)
{
    TeddyInit(0x24, LINE_SIZE, 0);

    TeddyColors(0x7C70DA, 0x3E31A2, 0x7C70DA);

    TeddyAddLine("TEDDY 64");
    TeddyAddLine("ver. 1.0");

    ILM IL = {0};

    ILM_load_file(&IL,"intp.o");

    ILM_execute(&IL);

    TeddyClose();

    return 0;
}