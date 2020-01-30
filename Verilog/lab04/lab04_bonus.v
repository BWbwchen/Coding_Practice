`define ZERO 7'b0000001
`define ONE 7'b1001111 
`define TWO 7'b0010010 
`define THREE 7'b0000110
`define FOUR 7'b1001100 
`define FIVE 7'b0100100 
`define SIX 7'b0100000 
`define SEVEN 7'b0001111
`define EIGHT 7'b0000000
`define NINE 7'b0000100 

`define SETTING 1'b0
`define COUNT 1'b1


module lab4_bonus(
	input wire en,
	input wire reset,
	input wire clk,
	input wire mode,
	input wire min_plus,
	input wire sec_plus,
	output wire [3:0] DIGIT,
	output wire [0:6] DISPLAY,
	output wire stop);



	wire my_clk;
	real_clock myclk (.clk(clk), .clk_div(my_clk));
	wire counter_clk;
	clock_divider  #(.n(19)) counterclk (.clk(clk), .clk_div(counter_clk));

	reg [11:0] now_time = 12'b0;
	wire [11:0] next_time;

	time_counter mytime (._clk(counter_clk), ._reset(reset), .now_time(now_time), ._en(en), ._mode(mode), ._min_plus(min_plus), ._sec_plus(sec_plus), .time_next(next_time), ._stop(stop));

	reg fuck_clk;

	always @(*) begin
		if (mode == `SETTING) fuck_clk = counter_clk;
		else fuck_clk = my_clk;
	end


	always @(posedge fuck_clk, posedge reset) begin
		if (reset) begin
			now_time <= 12'b0;
		end
		else begin
			now_time <= next_time;
		end
	end

	// convert 
	wire [7:0] min;
	wire [7:0] sec;
	convert_to_time_bcd myconvert(._time(now_time), ._min(min), ._sec(sec));


	// display
	wire [3:0] digit;
	wire [6:0] display;
	to_diplay my_dispaly(.clk(clk), .reset(reset), .bcd({min, sec}), ._digit(digit), ._display(display));

	assign DIGIT = digit;
	assign DISPLAY = display;






endmodule

module real_clock (clk, clk_div);
	input clk;
	output clk_div;

	reg [26:0] count = 27'd0;
	wire [26:0] next_count;
	reg clock = 1'b0;

	always @(posedge clk) begin
		count <= next_count;
	end

	always @(*) begin
		if (count == 27'd50000000) clock = 1'b1;
		else if (count == 27'd100000000) clock = 1'b0;
		else clock = clock;
	end

	assign next_count = (count == 27'd100000000) ? 27'd0 : count + 1;
	assign clk_div = clock;
endmodule