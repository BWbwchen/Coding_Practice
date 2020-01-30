`define C 7'b0110001
`define D 7'b0000001
`define E 7'b0110000
`define F 7'b0111000
`define G 7'b0100000
`define A 7'b0001000
`define B 7'b0000000
`define NOTHING 7'b1111111


module to_display (clk, bcd, digit, display);
	// bcd = min sec
    input [2:0] bcd;
	input clk;
	output [3:0] digit;
	output [6:0] display;

	wire clk_13;
    clock_divider  #(.n(13)) showclk (.clk(clk), .clk_div(clk_13));
    
    reg [3:0] digit = 4'b1110;
    reg [3:0] next_digit = 4'b1110;
    reg [6:0] display = `NOTHING;
    reg [6:0] next_display = `NOTHING;

    reg [2:0] temp_value = 4'b0000;
    always @(posedge clk_13) begin
        display <= next_display;
        digit <= next_digit;
    end

    always @(*)begin
        case (digit)
            4'b1110:begin 
                temp_value = 3'd7;
		        next_digit = {digit[2:0], digit[3]};
            end
            4'b1101:begin
                temp_value = 3'd7;
		        next_digit = {digit[2:0], digit[3]};
            end
            4'b1011:begin
                temp_value = 3'd7;
		        next_digit = {digit[2:0], digit[3]};
            end
            4'b0111:begin
                temp_value = bcd[2:0];
		        next_digit = {digit[2:0], digit[3]};
            end
        endcase
    end

    always @(*) begin
    	case (temp_value)
    		4'd0: next_display = `C;
    		4'd1: next_display = `D;
    		4'd2: next_display = `E;
    		4'd3: next_display = `F;
    		4'd4: next_display = `G;
    		4'd5: next_display = `A;
    		4'd6: next_display = `B;
    		4'd7: next_display = `NOTHING;
    		default:next_display = `NOTHING;
    	endcase
    end

    assign _digit = digit;
    assign _display = display;
endmodule