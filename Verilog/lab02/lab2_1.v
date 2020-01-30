module lab2_1 (clk, rst_n, en, dir, in, data, out);
    input clk, rst_n, en, dir, in;
    input [3:0] data;
    output [3:0] out;
    reg [3:0] next_out = 4'b0000, temp_out;
    reg carry_out;

    always @(*)begin
        temp_out <= next_out;
    end
        

    always @(posedge clk, negedge rst_n)begin
        if (rst_n == 1'b0) next_out = 4'b0000;
        else if (en == 1'b0) next_out = next_out; 
        else begin 
            if (in == 1'b0) begin 
                if (dir == 1'b1) {carry_out, next_out} = {1'b0, next_out} + 5'b00001;
                else {carry_out, next_out} = {1'b0, next_out} - 5'b00001;
            end 
            else next_out = data;
        end
    end

    assign out = temp_out;

endmodule
