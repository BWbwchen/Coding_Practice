`define TO_LEFT 2'b00 
`define TO_DOWN 2'b01 
`define ROUND 	2'b10 
`define INITIAL	2'b11 
module mem_addr_gen_2(
    input clk,
    input rst,
    input split,
    input shift,
    input [9:0] h_cnt,
    input [9:0] v_cnt,
    output [16:0] pixel_addr,
    output show_black
    );

    reg [9:0] delta;
    reg [9:0] h_delta;
    reg [9:0] v_delta;
    
	//state 
	reg [1:0] state;
	always @(posedge clk or posedge rst) begin
		if (rst) begin
			state <= `INITIAL;
			delta <= 0;
			v_delta <= 0;
			h_delta <= 0;
		end
		else begin
			delta <= delta;
			v_delta <= v_delta;
			h_delta <= h_delta;
			if (state == `INITIAL) begin
				if (split) state <= `ROUND;
				else if (shift) state <= `TO_LEFT;
				else state <= `INITIAL;
			end
			else if (state == `TO_LEFT) begin
				if (delta < 319) begin
					state <= `TO_LEFT;
					delta <= delta + 1;
				end
				else begin
					delta <= 0;
					state <= `TO_DOWN;
				end
			end
			else if (state == `TO_DOWN) begin
				if (delta < 239) begin
					state <= `TO_DOWN;
					delta <= delta + 1;
				end
				else begin
					delta <= 0;
					state <= `INITIAL;
				end
			end
			else begin
				// split
				if (h_delta < 159) begin
					h_delta <= h_delta + 1;
					v_delta <= v_delta + 1;
					state <= state;
				end
	            else begin
	            	h_delta <= 0;
	            	v_delta <= 0;
	            	state <= `INITIAL;
            	end
			end
		end
	end

	reg ans;
	always @(*) begin
		case (state)
			`INITIAL : begin
				ans = 1'b0;
			end
			`TO_LEFT : begin
				if ((319 - (h_cnt>>1)) <= delta ) ans = 1'b1;
				else ans = 1'b0;
			end
			`TO_DOWN : begin
				if ((v_cnt>>1) <= delta) ans = 1'b0;
				else ans = 1'b1;
			end
			`ROUND   : begin
				if ((h_cnt>>1)==160 && (v_cnt>>1)>119) begin
					ans = 1'b1;
				end
				// up left
				else if (((h_cnt>>1) <= 159) && ((v_cnt>>1) <= 119)) begin
					if (v_delta >= 120) ans = 1'b1;
					else if ((119 - (v_cnt>>1)) <= v_delta) ans = 1'b1;
					else ans = 1'b0;
				end
				// down right
				else if (((h_cnt>>1) > 159) && ((v_cnt>>1) > 119)) begin
					if (v_delta >= 120) ans = 1'b1;
					else if (((v_cnt>>1) - 120) <= v_delta) ans = 1'b1;
					else ans = 1'b0;
				end
				// up right
				else if (((h_cnt>>1) > 159) && ((v_cnt>>1) <= 119)) begin
					if (((h_cnt>>1) - 160) <= h_delta) ans = 1'b1;
					else ans = 1'b0;
				end
				// down left
				else if (((h_cnt>>1) <= 159) && ((v_cnt>>1) > 119)) begin
					if ((159 - (h_cnt>>1)) <= h_delta) ans = 1'b1;
					else ans = 1'b0;
				end
				else ans = 1'b1;
			end
		endcase
	end

	reg [16:0] round_addr;
	always @(*) begin
		if (state == `ROUND) begin
			// up left
			if (((h_cnt>>1) <= 159) && ((v_cnt>>1) <= 119)) begin
				round_addr = ((h_cnt>>1)+320*(v_cnt>>1) + 320*v_delta)% 76800;
			end
			// down right
			else if (((h_cnt>>1) > 159) && ((v_cnt>>1) > 119)) begin
				round_addr = ((h_cnt>>1)+320*(v_cnt>>1) - 320*v_delta)% 76800;
			end
			// up right
			else if (((h_cnt>>1) > 159) && ((v_cnt>>1) <= 119)) begin
				//round_addr = ((h_cnt>>1)+320*(v_cnt>>1) - h_delta)% 76800;
				round_addr = (((h_cnt>>1)-h_delta)%160+160+320*(v_cnt>>1))% 76800;
			end
			// down left
			else if (((h_cnt>>1) <= 159) && ((v_cnt>>1) > 119)) begin
				//round_addr = ((h_cnt>>1)+320*(v_cnt>>1) + h_delta)% 76800;
				round_addr = (((h_cnt>>1)+h_delta)%160+320*(v_cnt>>1))% 76800;
			end
			else round_addr = 17'b0;
		end
		else round_addr = 17'b0;
	end

    // scroll up
    // assign pixel_addr = ((h_cnt>>1)+320*(v_cnt>>1)+ delta*320 )% 76800;  //640*480 --> 320*240 
    assign pixel_addr = (state != `ROUND) ? ((h_cnt>>1)+320*(v_cnt>>1))% 76800 : round_addr;  //640*480 --> 320*240 
    assign show_black = ans;
   
endmodule
