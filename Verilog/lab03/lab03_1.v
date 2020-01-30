module lab03_1 (clk, rst, en, dir, led);
	input clk, rst, en, dir;
	output [15:0] led;
	
	reg [15:0] light = 16'b1000000000000000;
	reg [15:0] next_light;
	wire my_clk;
	clock_divider  #(.n(26)) myclk (.clk(clk), .clk_div(my_clk));

	always @(posedge my_clk or posedge rst) begin
		if (rst == 1'b1) light = 16'b1000000000000000;
		else light = next_light; 
	end
	// control
	always @(*) begin
		if (en == 1'b1) begin
			if (dir == 1'b1) begin
				next_light = {light[14:0], light[15]};
			end
			else if (dir == 1'b0) begin
				next_light = {light[0], light[15:1]};
			end
		end
		else next_light = light;
	end


	assign led = light;

endmodule 