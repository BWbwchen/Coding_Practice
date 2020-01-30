module my_vol_control (clk, rst, up, down, vol);
	input clk;
	input rst;
	input up;
	input down;
	output [2:0] vol;

	wire de_up;
	wire de_down;
	wire my_up;
	wire my_down;

	//debounce my_up (.clk(clk), .pb(up), .pb_debounced(de_up));
	//onepulse my_up_one (.clk(clk), .signal(de_up), .op(my_up));
	onepulse my_up_one (.clk(clk), .signal(up), .op(my_up));
	//debounce my_down (.clk(clk), .pb(down), .pb_debounced(de_down));
	//onepulse my_down_one (.clk(clk), .signal(de_down), .op(my_down));
	onepulse my_down_one (.clk(clk), .signal(down), .op(my_down));

	reg [2:0] ans;
	always @(posedge clk or posedge rst) begin
		if (rst) begin
			ans <= 3'd3;			
		end
		else begin
			if (my_up == 1'b1 && ans + 1 <= 3'd5) ans <= ans + 1;
			else if (my_down == 1'b1 && ans - 1 >= 3'd1) ans <= ans - 1;
			else ans <= ans;
		end
	end

	assign vol = ans;

endmodule