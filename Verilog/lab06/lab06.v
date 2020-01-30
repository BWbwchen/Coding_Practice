// display
`define ZERO    7'b0000001
`define ONE     7'b1001111 
`define TWO     7'b0010010 
`define THREE   7'b0000110
`define FOUR    7'b1001100 
`define FIVE    7'b0100100 
`define SIX     7'b0100000 
`define SEVEN   7'b0001111
`define EIGHT   7'b0000000
`define NINE    7'b0000100 
`define DASH    7'b1111110
`define NOTHING 7'b1111111

// state
`define INITIAL 3'b000
`define SHOW 	3'b001
`define INPUT 	3'b010
`define JUDGE 	3'b011
`define WIN 	3'b100

// judge
`define ENTER	9'b0_0101_1010
`define YES 	1'b1
`define NO 		1'b0



module lab06 (
	output wire [0:6] DISPLAY,
	output wire [3:0] DIGIT,
	output wire [15:0] LED,
	inout wire PS2_DATA,
	inout wire PS2_CLK,
	input wire rst,
	input wire clk,
	input wire start,
	input wire cheat
	);

	wire clk_16;
	clock_divider #(.n(16)) my_clk_16 (.clk(clk), .clk_div(clk_16));

	wire de_start;
	debounce for_start (.clk(clk), .pb(start), .pb_debounced(de_start));

	wire [511:0] key_down;
	wire [8:0] last_change;
	wire key_valid;	
	KeyboardDecoder a (.rst(rst), 
					   .clk(clk),
					   .PS2_DATA(PS2_DATA), 
					   .PS2_CLK(PS2_CLK), 
					   .key_down(key_down), 
					   .last_change(last_change),
					   .key_valid(key_valid) );


	wire [6:0] random_num;
	random my_ran (.clk(clk), .start(de_start), .random_num(random_num));

	wire [6:0] left;
	wire [6:0] right;
	wire [2:0] now_state;
	wire [7:0] guess_num;
	wire [13:0] left_and_right;

	judge b (.clk(clk),
			 .rst(rst), 
			 .en(de_start),
			 .key_valid(key_valid), 
			 .key_down(key_down), 
			 .last_change(last_change),
			 .random_num(random_num), 
			 .now_state(now_state),
			 .guess_num(guess_num),
			 .limit(left_and_right) );

	wire [15:0] bcd;
	display_choose d_choose (.state(now_state),
							 .left(left_and_right[13:7]),
							 .right(left_and_right[6:0]),
							 .guess(guess_num),
							 .cheat(cheat),
							 .random(random_num),
							 .bcd(bcd));

	display c (.clk(clk), 
			   .bcd(bcd), 
			   .display(DISPLAY), 
			   .digit(DIGIT) );

	assign LED = (now_state == 3'b100) ? 16'b1111111111111111 : 16'b0;
	


	//add your design here
endmodule
module debounce (clk, pb, pb_debounced);
    input clk;
    input pb;
    output pb_debounced;

    reg[3:0] shift_reg;   
    // use shift_regto filter thebounce 
    always@(posedge clk) begin
        shift_reg[3:1] <= shift_reg[2:0];
        shift_reg[0] <= pb;
    end
    assign pb_debounced = ((shift_reg== 4'b1111) ? 1'b1 : 1'b0);
endmodule
module display (clk, bcd, digit, display);
    // bcd = min sec
    input [15:0] bcd;
    input clk;
    output [3:0] digit;
    output [6:0] display;

    wire clk_13;
    clock_divider  #(.n(13)) showclk (.clk(clk), .clk_div(clk_13));
    
    reg [3:0] digit = 4'b1110;
    reg [3:0] next_digit = 4'b1110;
    reg [6:0] display = `ZERO;
    reg [6:0] next_display = `ZERO;

    reg [3:0] temp_value = 4'b0000;
    always @(posedge clk_13) begin
        display <= next_display;
        digit <= next_digit;
    end

    always @(*)begin
        case (digit)
            4'b1110:begin 
                temp_value = bcd[7:4];
                next_digit = {digit[2:0], digit[3]};
            end
            4'b1101:begin
                temp_value = bcd[11:8];
                next_digit = {digit[2:0], digit[3]};
            end
            4'b1011:begin
                temp_value = bcd[15:12];
                next_digit = {digit[2:0], digit[3]};
            end
            4'b0111:begin
                temp_value = bcd[3:0];
                next_digit = {digit[2:0], digit[3]};
            end
        endcase
    end

    always @(*) begin
        case (temp_value)
            4'd0: next_display = `ZERO;
            4'd1: next_display = `ONE;
            4'd2: next_display = `TWO;
            4'd3: next_display = `THREE;
            4'd4: next_display = `FOUR;
            4'd5: next_display = `FIVE;
            4'd6: next_display = `SIX;
            4'd7: next_display = `SEVEN;
            4'd8: next_display = `EIGHT;
            4'd9: next_display = `NINE;
            4'd10:next_display = `DASH;
            4'd11:next_display = `NOTHING;
            default:next_display = `NOTHING;
        endcase
    end

    assign _digit = digit;
    assign _display = display;
endmodule
module display_choose (
	input [2:0] state,
	input [6:0] left,
	input [6:0] right,
	input [7:0] guess,
	input cheat,
	input [6:0] random,
	output [15:0] bcd );

	reg [15:0] to_show = 16'd0;
	always @(*) begin 
		if (cheat == 1'b1 && state == `SHOW) begin
			to_show[15:12] = random/10;
			to_show[11:8] = random%10;
			to_show[7:0] = 8'b1011_1011;	
		end
		else begin
			if (state == `INITIAL) begin
				to_show = 16'b1010_1010_1010_1010; // ----
			end
			else if (state == `SHOW) begin
				to_show[3:0] = right%10;
				to_show[7:4] = right/10;
				to_show[11:8] = left%10;
				to_show[15:12] = left/10;
			end 
			else if (state == `INPUT) begin
				// _ _ 8 8
				to_show[15:8] = 8'b1011_1011;
				to_show[7:4] = guess[7:4];
				to_show[3:0] = guess[3:0];
			end
			else if (state == `JUDGE) begin
				to_show[3:0] = right%10;
				to_show[7:4] = right/10;
				to_show[11:8] = left%10;
				to_show[15:12] = left/10;
			end
			else begin
				to_show[3:0] = right%10;
				to_show[7:4] = right/10;
				to_show[11:8] = left%10;
				to_show[15:12] = left/10;
			end
		end
	end

	assign bcd = to_show;
endmodule
module judge (
	input clk,
	input rst,
	input key_valid,
	input en,
	input [511:0] key_down,
	input [8:0] last_change,
	input [6:0] random_num,
	output [2:0] now_state, 
	output [13:0] limit, 
	output [7:0] guess_num
	);

	reg [6:0] left;
	reg [6:0] right;
	reg [6:0] next_left;
	reg [6:0] next_right;
	always @(posedge clk or posedge rst) begin
		if(rst) begin
			 left <= 7'd0;
			 right <= 7'd99;
		end else begin
			 left <= next_left;
			 right <= next_right;
		end
	end

	wire clk_25;
	clock_divider #(.n(25)) my_clk_16 (.clk(clk), .clk_div(clk_25));
	reg state_clk;
	always @(*) begin
		if (state == `WIN) state_clk = clk_25;
		else state_clk = clk;
	end

	reg [2:0] state;
	reg [2:0] next_state;
	always @(posedge state_clk or posedge rst) begin
		if (rst) state <= `INITIAL;
		else state <= next_state;
	end

	// input 
	reg [3:0] _in;
	always @(*) begin 
		case (last_change) 
			9'b0_0111_0000 : _in = 4'd0;
			9'b0_0110_1001 : _in = 4'd1;
			9'b0_0111_0010 : _in = 4'd2;
			9'b0_0111_1010 : _in = 4'd3;
			9'b0_0110_1011 : _in = 4'd4;
			9'b0_0111_0011 : _in = 4'd5;
			9'b0_0111_0100 : _in = 4'd6;
			9'b0_0110_1100 : _in = 4'd7;
			9'b0_0111_0101 : _in = 4'd8;
			9'b0_0111_1101 : _in = 4'd9;
			default : _in = 4'd10;
		endcase
	end

	reg [7:0] guess = 8'd0;
	reg [7:0] next_guess = 8'd0;
	//guess ff
	always @(posedge clk or posedge rst) begin
		if (rst) guess <= 8'b10111011;
		else if (state != `INPUT && next_state != `INPUT) guess <= 8'b10111011;
		else guess <= next_guess;
	end

	wire [6:0] guess_decimal;
	always @(*) begin
		next_guess = guess;
		case (state) 
			`INITIAL : begin
				if (en) next_state = `SHOW;
				else next_state = `INITIAL;		
			end
			`SHOW : begin
				if (key_valid && (key_down[9'b0_0111_0000] == 1'b1 ||
								  key_down[9'b0_0110_1001] == 1'b1 ||
								  key_down[9'b0_0111_0010] == 1'b1 ||
								  key_down[9'b0_0111_1010] == 1'b1 ||
								  key_down[9'b0_0110_1011] == 1'b1 ||
								  key_down[9'b0_0111_0011] == 1'b1 ||
								  key_down[9'b0_0111_0100] == 1'b1 ||
								  key_down[9'b0_0110_1100] == 1'b1 ||
								  key_down[9'b0_0111_0101] == 1'b1 ||
								  key_down[9'b0_0111_1101] == 1'b1   )) begin
								  	next_state = `INPUT;
								  	next_guess = {guess[3:0], _in};
								  end 
				else next_state <= `SHOW;
			end
			`INPUT : begin
				if (key_valid && key_down[last_change] == 1'b1) begin
					if (key_down[`ENTER] == 1'b1) begin
						next_state = `JUDGE;
						next_guess = guess;
					end
					else begin
						next_state = `INPUT;
						if (_in != 4'd10) next_guess = {guess[3:0], _in};
						else next_guess = guess;
					end
				end 
				else next_state = `INPUT;
			end
			`JUDGE : begin
				if (guess_decimal == random_num) next_state = `WIN;
				else next_state = `SHOW;
			end
			`WIN : begin
				next_state = `INITIAL;
			end
		endcase
	end

	assign guess_decimal = guess[7:4]*10 + guess[3:0];
	// left and right
	always @(*) begin 
		case (state) 
			`INITIAL : begin
				next_left = 7'd0;
				next_right = 7'd99;
			end 
			`SHOW : begin  
				next_left = left;
				next_right = right;
			end
			`INPUT : begin
				next_left = left;
				next_right = right;
			end
			`JUDGE : begin
				if (guess_decimal == random_num) begin
					next_left = random_num;
					next_right = random_num;
				end
				else begin
					if ((left < guess_num) && (guess_decimal < right)) begin
						if (guess_decimal < random_num) begin
							next_left = guess_decimal;
							next_right = right;
						end
						else begin
							next_left = left;
							next_right = guess_decimal;
						end
					end
					else begin
						next_left = left;
						next_right = right;
					end
				end
			end
			`WIN : begin
				next_left = left;
				next_right = right;
			end
		endcase 
	end

	assign now_state = state;
	assign limit = {left, right};
	assign guess_num = guess;
endmodule 
module KeyboardDecoder(
	output reg [511:0] key_down,
	output wire [8:0] last_change,
	output reg key_valid,
	inout wire PS2_DATA,
	inout wire PS2_CLK,
	input wire rst,
	input wire clk
    );
    
    parameter [1:0] INIT			= 2'b00;
    parameter [1:0] WAIT_FOR_SIGNAL = 2'b01;
    parameter [1:0] GET_SIGNAL_DOWN = 2'b10;
    parameter [1:0] WAIT_RELEASE    = 2'b11;
    
	parameter [7:0] IS_INIT			= 8'hAA;
    parameter [7:0] IS_EXTEND		= 8'hE0;
    parameter [7:0] IS_BREAK		= 8'hF0;
    
    reg [9:0] key;		// key = {been_extend, been_break, key_in}
    reg [1:0] state;
    reg been_ready, been_extend, been_break;
    
    wire [7:0] key_in;
    wire is_extend;
    wire is_break;
    wire valid;
    wire err;
    
    wire [511:0] key_decode = 1 << last_change;
    assign last_change = {key[9], key[7:0]};
    
    KeyboardCtrl_0 inst (
		.key_in(key_in),
		.is_extend(is_extend),
		.is_break(is_break),
		.valid(valid),
		.err(err),
		.PS2_DATA(PS2_DATA),
		.PS2_CLK(PS2_CLK),
		.rst(rst),
		.clk(clk)
	);
	
	OnePulse op (
		.signal_single_pulse(pulse_been_ready),
		.signal(been_ready),
		.clock(clk)
	);
    
    always @ (posedge clk, posedge rst) begin
    	if (rst) begin
    		state <= INIT;
    		been_ready  <= 1'b0;
    		been_extend <= 1'b0;
    		been_break  <= 1'b0;
    		key <= 10'b0_0_0000_0000;
    	end else begin
    		state <= state;
			been_ready  <= been_ready;
			been_extend <= (is_extend) ? 1'b1 : been_extend;
			been_break  <= (is_break ) ? 1'b1 : been_break;
			key <= key;
    		case (state)
    			INIT : begin
    					if (key_in == IS_INIT) begin
    						state <= WAIT_FOR_SIGNAL;
    						been_ready  <= 1'b0;
							been_extend <= 1'b0;
							been_break  <= 1'b0;
							key <= 10'b0_0_0000_0000;
    					end else begin
    						state <= INIT;
    					end
    				end
    			WAIT_FOR_SIGNAL : begin
    					if (valid == 0) begin
    						state <= WAIT_FOR_SIGNAL;
    						been_ready <= 1'b0;
    					end else begin
    						state <= GET_SIGNAL_DOWN;
    					end
    				end
    			GET_SIGNAL_DOWN : begin
						state <= WAIT_RELEASE;
						key <= {been_extend, been_break, key_in};
						been_ready  <= 1'b1;
    				end
    			WAIT_RELEASE : begin
    					if (valid == 1) begin
    						state <= WAIT_RELEASE;
    					end else begin
    						state <= WAIT_FOR_SIGNAL;
    						been_extend <= 1'b0;
    						been_break  <= 1'b0;
    					end
    				end
    			default : begin
    					state <= INIT;
						been_ready  <= 1'b0;
						been_extend <= 1'b0;
						been_break  <= 1'b0;
						key <= 10'b0_0_0000_0000;
    				end
    		endcase
    	end
    end
    
    always @ (posedge clk, posedge rst) begin
    	if (rst) begin
    		key_valid <= 1'b0;
    		key_down <= 511'b0;
    	end else if (key_decode[last_change] && pulse_been_ready) begin
    		key_valid <= 1'b1;
    		if (key[8] == 0) begin
    			key_down <= key_down | key_decode;
    		end else begin
    			key_down <= key_down & (~key_decode);
    		end
    	end else begin
    		key_valid <= 1'b0;
			key_down <= key_down;
    	end
    end
endmodule
module OnePulse (
	output reg signal_single_pulse,
	input wire signal,
	input wire clock
	);
	
	reg signal_delay;

	always @(posedge clock) begin
		if (signal == 1'b1 & signal_delay == 1'b0)
		  signal_single_pulse <= 1'b1;
		else
		  signal_single_pulse <= 1'b0;

		signal_delay <= signal;
	end
endmodule
module random (clk, start, random_num);
    input clk;
    input start;
    output [6:0] random_num;

    reg [25:0] count = 0;
    wire [25:0] next_count;

    always @(posedge clk) begin
        count= next_count ;
    end
    reg [6:0] ans = 7'd1;
    always @(posedge clk) begin
        if (start == 1'b1) begin
           ans <= ((7'd0 < count[6:0]) && (count[6:0] < 7'd99)) ? count[6:0] : {1'b0, count[5:0]}; 
        end
        else begin
            ans <= ans;
        end 
    end

    assign next_count = count + 1;
    assign random_num = ans;    
endmodule 
module clock_divider(clk, clk_div);
    parameter n = 26;
    input clk;
    output clk_div;

    reg [n-1:0] count = 0;
    wire [n-1:0] next_count;

    always @(posedge clk) begin
        count= next_count ;
    end

    assign next_count = count + 1;
    assign clk_div = count[n-1];    
endmodule