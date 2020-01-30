`define LEFT 1'b1
`define RIGHT 1'b0

module lab03_3 (clk, rst, en, dir, led);
	input clk, rst, en, dir;
	output [15:0] led;
// light	
	reg [15:0] one = 16'b1000000000000000;
	reg [15:0] three = 16'b1110000000000000;
	wire [15:0] next_one ;
	wire [15:0] next_three; 
	wire one_clk, three_clk;
// light position
	wire [15:0] temp_one;
	wire [15:0] temp_three;
	assign temp_one = one;
	assign temp_three = three;

	clock_divider  #(.n(23)) myclk (.clk(clk), .clk_div(one_clk));
	clock_divider  #(.n(26)) myclk2 (.clk(clk), .clk_div(three_clk));

	one_shift for_one (.clk(one_clk), .en(en), .dir(dir), .three_data(temp_three), .one_data(temp_one), .out(next_one));
	shift three_shift (.en(en), .dir(dir), .data(temp_three), .out(next_three));



	always @(posedge three_clk or posedge rst) begin
		if (rst == 1'b1) three <= 16'b1110000000000000;
		else begin 
			three <= next_three;
		end
	end

	always @(posedge one_clk or posedge rst) begin
		if (rst == 1'b1) one <= 16'b1000000000000000;
		else begin 
			one <= next_one;
		end
	end

	assign led = one | three;
endmodule 

module one_shift (clk, en, dir, three_data, one_data, out);
	input clk, en, dir;
	input [15:0] three_data, one_data;
	output [15:0] out;
// left  to right

	reg my_dir = `RIGHT; 
	wire [15:0] next_one;
	wire temp_dir;

	wire [15:0] shift_right;
	wire [15:0] shift_left;
	
	wire [15:0] middle_shift_right;
	wire [15:0] middle_shift_left;
	

	shift temp (.en(en), .dir(temp_dir), .data(one_data), .out(next_one));

	always @(posedge clk) begin
	// collision
		if ((shift_left == 16'b0) && (shift_right != 16'b0) )begin
			// collision from left
			my_dir = `LEFT;
		end 
		else if ((shift_left != 16'b0) && (shift_right == 16'b0) ) begin
			// collsion from right
			my_dir = `RIGHT;
		end
		else if ((middle_shift_left != 16'b0) && (middle_shift_right != 16'b0) ) begin
			my_dir = ~my_dir;
		end
		else begin
			my_dir = my_dir;
		end
	end

	assign shift_right = {one_data[0], one_data[15:1]}&three_data;
	assign shift_left = {one_data[14:0], one_data[15]}&three_data;
    
    assign middle_shift_right = {next_one[0], next_one[15:1]}&three_data;
	assign middle_shift_left = {next_one[14:0], next_one[15]}&three_data;
	
	assign temp_dir = my_dir;
	assign out = next_one;

endmodule

