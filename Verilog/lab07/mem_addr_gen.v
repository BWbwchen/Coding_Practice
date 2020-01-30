`define LEFT    1'b0 
`define RIGHT   1'b1 
module mem_addr_gen_1(
    input clk,
    input rst,
    input en,
    input dir,
    input [9:0] h_cnt,
    input [9:0] v_cnt,
    output [16:0] pixel_addr
    );
    
    reg [9:0] delta;
    // scroll up
    // assign pixel_addr = ((h_cnt>>1)+320*(v_cnt>>1)+ delta*320 )% 76800;  //640*480 --> 320*240 
    assign pixel_addr = (((h_cnt>>1)+delta)%320+320*(v_cnt>>1))% 76800;  //640*480 --> 320*240 

    always @ (posedge clk or posedge rst) begin
        if(rst)
            delta <= 0;
        else if (en == 1'b0)
            delta <= delta;
        else if(dir == `LEFT)
            if (delta < 319) delta <= delta + 1;
            else delta <= 0;
        else if (dir == `RIGHT)
            if (delta > 0) delta <= delta - 1;
            else delta <= 319;
        else
            delta <= 0;
   end
    
endmodule
