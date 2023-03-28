#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "sleep.h"
#include "string.h"

#define IIC_BASEADDRESS 	0x43C00000
#define REG0_OFFSET 		0
#define REG1_OFFSET 		4

u32 gpio_input_value = 0;
char buf_print[64] = {0};

int main()
{
    int i = 0;
    init_platform();

    while(1)
    {
	for(i=0; i<64; i++) buf_print[i] = 0;
    	gpio_input_value = Xil_In32(IIC_BASEADDRESS + REG1_OFFSET);
    	sprintf(buf_print, "input gpio_value = %d\r\n", gpio_input_value);
    	print(buf_print);

    	gpio_input_value = Xil_In32(IIC_BASEADDRESS + REG1_OFFSET);

    	if (gpio_input_value == 2)
    	{
    		Xil_Out32(IIC_BASEADDRESS + REG0_OFFSET, 0x0);
    		usleep(100000);

    		Xil_Out32(IIC_BASEADDRESS + REG0_OFFSET, 0x1);
    		usleep(100000);

    		Xil_Out32(IIC_BASEADDRESS + REG0_OFFSET, 0x2);
    		usleep(100000);

    		Xil_Out32(IIC_BASEADDRESS + REG0_OFFSET, 0x4);
    		usleep(100000);

    		Xil_Out32(IIC_BASEADDRESS + REG0_OFFSET, 0x8);
    		usleep(100000);

    	}
    	else if (gpio_input_value == 1)
    	{
    		Xil_Out32(IIC_BASEADDRESS + REG0_OFFSET, 0x8);
    		usleep(100000);

    		Xil_Out32(IIC_BASEADDRESS + REG0_OFFSET, 0x4);
    		usleep(100000);

    		Xil_Out32(IIC_BASEADDRESS + REG0_OFFSET, 0x2);
    		usleep(100000);

    		Xil_Out32(IIC_BASEADDRESS + REG0_OFFSET, 0x1);
    		usleep(100000);

    		Xil_Out32(IIC_BASEADDRESS + REG0_OFFSET, 0x0);
    		usleep(100000);
    	}
    	else if (gpio_input_value == 0)
    	{
    		Xil_Out32(IIC_BASEADDRESS + REG0_OFFSET, 0x9);
    	    usleep(100000);

    	    Xil_Out32(IIC_BASEADDRESS + REG0_OFFSET, 0x6);
    	    usleep(100000);

    	    Xil_Out32(IIC_BASEADDRESS + REG0_OFFSET, 0x0);
    	    usleep(100000);

    	    Xil_Out32(IIC_BASEADDRESS + REG0_OFFSET, 0x6);
    	    usleep(100000);

    	    Xil_Out32(IIC_BASEADDRESS + REG0_OFFSET, 0x9);
    	    usleep(100000);
    	}
    	else if(gpio_input_value == 3)
    	{
    		Xil_Out32(IIC_BASEADDRESS + REG0_OFFSET, 0xF);
    		usleep(100000);

    		Xil_Out32(IIC_BASEADDRESS + REG0_OFFSET, 0x0);
    		usleep(100000);
    	}
    }

    cleanup_platform();
    return 0;
}