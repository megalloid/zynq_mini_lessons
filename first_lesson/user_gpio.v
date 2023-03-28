`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/23/2023 01:50:55 PM
// Design Name: 
// Module Name: user_gpio
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module user_gpio(
        // from fpga pin
        input wire [1:0]gpio_input,
        
        // to fpga pin
        output wire [3:0]gpio_output,
        
        // to zynq read
        output wire [1:0]zynq_gpio_input,
        
        // from zynq write
        input wire [3:0]zynq_gpio_output
    );
    
    assign gpio_input[1:0] = zynq_gpio_input[1:0];
    assign gpio_output[3:0] = zynq_gpio_output[3:0];


endmodule
