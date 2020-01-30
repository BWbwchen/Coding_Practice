`define NONE 1'b0
`define ONCE 1'b1
module player_control (
	input clk,
	input reset,
	input _play,
	input _repeat,
	input _music,
	input [11:0] LEN,
	output reg [11:0] ibeat,
	output now_state
);
    reg [11:0] next_ibeat;

    wire fuck_zero_to_one, fuck_one_to_zero;
    onepulse zero_to_one (
    	.clk(clk),
    	.signal(_music),
    	.op(fuck_zero_to_one)
    );

    onepulse one_to_zero (
    	.clk(clk),
    	.signal(~_music),
    	.op(fuck_one_to_zero)
    );

	always @(posedge clk, posedge reset) begin
		if (reset)
			ibeat <= 0;
		else begin
			if (fuck_zero_to_one == 1'b1 || fuck_one_to_zero == 1'b1) ibeat <= 0;
            else ibeat <= next_ibeat;
		end
	end


	// state for repeat
	reg state = `NONE;
	always @(posedge clk or posedge reset) begin
		if (reset) begin
			state <= `NONE;	
		end
		else begin
			if (_repeat	== 1'b1) begin
				if (state == `NONE && (ibeat == LEN-1)) state <= `ONCE;
				else state <= state;
			end
			else state <= `NONE;
		end
	end

    always @* begin
    	if (_play == 1'b1) begin
			if (_repeat == 1'b0) begin
				if (ibeat + 1 < LEN) next_ibeat = ibeat + 1;
				else next_ibeat = 12'd0; 
			end
			else begin
				if (state == `NONE) next_ibeat = (ibeat + 1 < LEN) ? (ibeat + 1) : 12'd0;
				else next_ibeat	= ibeat;
			end
        end
        else next_ibeat = ibeat;
    end

    assign now_state = state;
endmodule