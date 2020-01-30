// state
`define INITIAL 2'b00
`define DEPOSIT 2'b01
`define BUY 	2'b10
`define CHANGE 	2'b11

//display
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
`define T       7'b1110000
`define O       7'b1100010
`define H       7'b1101000
`define A       7'b0000010
`define R       7'b1111010
`define D       7'b1000010

module  lab05 (clk, rst,  money_5,  money_10,  cancel,  drink_A, drink_B, drop_money, enough_A, enough_B, DIGIT, DISPLAY);
	input  clk;
	input  rst;
	input  money_5;
	input  money_10;
	input  cancel;
	input  drink_A;
	input  drink_B;
	output [9:0] drop_money;
	output enough_A;
	output enough_B;
	output [3:0] DIGIT;
	output [0:6] DISPLAY;

	// for my state
	wire clk_16, clk_26, clk_28;
	clock_divider #(.n(16)) myclk_16 (.clk(clk), .clk_div(clk_16));
	clock_divider #(.n(26)) myclk_26 (.clk(clk), .clk_div(clk_26));
	clock_divider #(.n(28)) myclk_28 (.clk(clk), .clk_div(clk_28));

	reg 	[1:0] state = `INITIAL;
	reg 	[1:0] count_drink_A = 2'd0;
	reg 	[1:0] count_drink_B = 2'd0;
	// my counter
	reg [6:0] now_charge = 7'd0;
	wire [6:0] next_charge;
	mycounter my (	.clk(clk),
					.state(state),
					.counter_A(count_drink_A),
					.counter_B(count_drink_B),
					.money_10(money_10), 
					.money_5(money_5), 
					.cancel(cancel), 
					.drink_A(drink_A), 
					.drink_B(drink_B), 
					.now_charge(now_charge), 
					.next_charge(next_charge));

	// my state
	wire 	[1:0] next_state;
	wire 	[1:0] next_drink_A;
	wire 	[1:0] next_drink_B;

	state_cl mystate (	.clk(clk), 
						.now_state(state), 
						.cancel(cancel), 
						.drink_A(drink_A), 
						.drink_B(drink_B),
						.count_drink_A(count_drink_A), 
						.count_drink_B(count_drink_B), 
						.money(now_charge), 
						.next_drink_A(next_drink_A), 
						.next_drink_B(next_drink_B), 
						.next_state(next_state));

	reg my_counter_clk;
	always @(*) begin
		if (state == `INITIAL ||state == `BUY || state == `CHANGE) my_counter_clk = clk_26;
		else my_counter_clk = clk_16;
	end

	reg my_state_clk;
	always @(*) begin
		if (state == `BUY) my_state_clk = clk_28;
		else if (state == `CHANGE) my_state_clk = clk_26;
		else my_state_clk = clk_16;
	end

	// my state
	always @(posedge my_state_clk or posedge rst) begin
		if (rst) begin
			state <= `INITIAL;	
			count_drink_A <= 2'd0;
			count_drink_B <= 2'd0;
		end
		else begin
			state <= next_state;		
			count_drink_A <= next_drink_A;
			count_drink_B <= next_drink_B;
		end
	end

	// because that fuck cycle
	reg [6:0] fuck;
	always @(posedge clk_26) begin
		fuck <= now_charge;
	end
	// my counter 
	always @(posedge my_counter_clk or posedge rst) begin
		if (rst) begin	
			now_charge <= 7'd0;	
		end
		else begin
			now_charge <= next_charge;	
		end
	end



	wire [7:0] bcd_charge;
	convert_to_bcd convert_charge (.number(now_charge), .bcd(bcd_charge));

	wire [15:0] to_print;
	pre_deal_display all (.state(state), .counter_bcd(bcd_charge), .count_drink_A(count_drink_A), .count_drink_B(count_drink_B), .left(to_print));

	to_diplay kk (.clk(clk), .bcd(to_print), .digit(DIGIT), .display(DISPLAY));	

	led_light light (.state(state), .pre(fuck), .money(now_charge), .enough({enough_A, enough_B}), .led(drop_money));
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

module convert_to_bcd (number, bcd);
	input [6:0] number;
	output [7:0] bcd;
	assign bcd[3:0] = number%10;
	assign bcd[7:4] = number/10;
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

module led_light (pre, money, state, enough, led);
	input 	[6:0] pre;
	input 	[6:0] money;
	input 	[1:0] state;
	output 	[1:0] enough;
	output 	[9:0] led;

	reg [1:0] temp_enough = 2'b0;
	reg [9:0] temp_led = 10'b0;

	// enough
	always @(*) begin
		case (state)
			`INITIAL:begin
				temp_enough = 2'b0;
			end
			`DEPOSIT:begin
				if (money >= 7'd25) temp_enough = 2'b11;
				else if (money >= 7'd20) temp_enough = 2'b10;
				else temp_enough = 2'b0; 
			end
			`BUY :begin
				temp_enough = 2'b0;
			end
			`CHANGE :begin
				temp_enough = 2'b0;
			end
		endcase
	end
	// led
	always @(*) begin
		case (state)
			`INITIAL:begin
				temp_led = 10'b0;	
			end
			`DEPOSIT:begin
				temp_led = 10'b0;
			end
			`BUY :begin
				temp_led = 10'b0;	
			end
			`CHANGE :begin
				if (pre >= 7'd10) temp_led = 10'b1111111111;
				else if (pre >= 7'd5) temp_led = 10'b1111100000;
				else temp_led = 10'b0;
			end
		endcase
	end
	assign enough = temp_enough;
	assign led = temp_led;
endmodule 

module pre_deal_display (state, counter_bcd, count_drink_A, count_drink_B, left);
	input 	[1:0] state;
	input 	[7:0] counter_bcd;
	input 	[1:0] count_drink_A;
	input 	[1:0] count_drink_B;
	output 	[15:0] left;

	reg [15:0] temp_ans;


	always @(*) begin
		if (state == `INITIAL) temp_ans = 16'b0;
		else if (state == `DEPOSIT) begin
			if (count_drink_A == 2'd1) temp_ans = {8'b00100000, counter_bcd};
			else if (count_drink_B == 2'd1) temp_ans = {8'b00100101, counter_bcd};
			else temp_ans = {8'b00000000, counter_bcd};
		end
		else if (state == `BUY) begin
			if (count_drink_A == 2'd2) temp_ans = 16'b1010101110111011; // tooo 
			else temp_ans = 16'b1100110111101111; // hard
		end
		else temp_ans = {8'b00000000, counter_bcd};
	end
	assign left = temp_ans;
endmodule

module mycounter (clk, state, counter_A, counter_B, money_10, money_5, cancel, drink_A, drink_B, now_charge, next_charge);
	input 	clk;
	input 	money_10;
	input 	money_5;
	input 	[1:0] counter_A;
	input 	[1:0] counter_B;
	input 	cancel;
	input 	drink_A; // $20
	input 	drink_B; // $25
	input 	[1:0] state;
	input 	[6:0] now_charge;

	output  [6:0] next_charge;

	wire clk_16;
	clock_divider #(.n(16))	myclk_16 (.clk(clk), 	.clk_div(clk_16));
	wire de_money_10, de_money_5, de_cancel, de_drink_A, de_drink_B;
	debounce myde_money_10 	(.clk(clk_16), 	.pb(money_10), 	.pb_debounced(de_money_10));
	debounce myde_money_5 	(.clk(clk_16), 	.pb(money_5), 	.pb_debounced(de_money_5));
	debounce myde_cancel 	(.clk(clk_16), 	.pb(cancel), 	.pb_debounced(de_cancel));
	debounce myde_drink_A 	(.clk(clk_16), 	.pb(drink_A), 	.pb_debounced(de_drink_A));
	debounce myde_drink_B 	(.clk(clk_16), 	.pb(drink_B), 	.pb_debounced(de_drink_B));
	wire _money_10, _money_5, _cancel, _drink_A, _drink_B;
	onepulse myone_money_10	(.clk(clk_16), 	.pb_debounced(de_money_10), .pb_1pulse(_money_10));
	onepulse myone_money_5	(.clk(clk_16), 	.pb_debounced(de_money_5), 	.pb_1pulse(_money_5));
	onepulse myone_cancel	(.clk(clk_16), 	.pb_debounced(de_cancel), 	.pb_1pulse(_cancel));
	onepulse myone_drink_A	(.clk(clk_16), 	.pb_debounced(de_drink_A), 	.pb_1pulse(_drink_A));
	onepulse myone_drink_B	(.clk(clk_16), 	.pb_debounced(de_drink_B), 	.pb_1pulse(_drink_B));

	reg [6:0] temp_ans = 7'd0;

	always @(*) begin
		if (state == `INITIAL) begin
			temp_ans = 7'd0;
		end
		else if (state == `DEPOSIT) begin
			if (_money_10 == 1'b1) begin
				if (now_charge >= 7'd90) temp_ans = now_charge;
				else temp_ans = now_charge + 7'd10;
			end
			else if (_money_5 == 1'b1) begin
				if (now_charge >= 7'd95) temp_ans = now_charge;
				else temp_ans = now_charge + 7'd5;
			end
			else begin
				if (counter_A == 2'd2) begin
					if (now_charge >= 7'd20) temp_ans = now_charge - 7'd20;
					else temp_ans = now_charge;
				end
				else if (counter_B == 2'd2) begin
					if (now_charge >= 7'd25) temp_ans = now_charge - 7'd25;
					else temp_ans = now_charge;
				end
				else temp_ans = now_charge;
			end
		end	
		else if (state == `BUY) begin
			temp_ans = now_charge;
		end
		else if (state == `CHANGE) begin
			if (now_charge >= 7'd10) temp_ans = now_charge - 7'd10;
			else if (now_charge >= 7'd5) temp_ans = now_charge - 7'd5;
			else temp_ans = 7'd0;
		end
	end
	
	assign next_charge = temp_ans;
endmodule

module onepulse(pb_debounced, clk, pb_1pulse);
	input pb_debounced;
	input clk;
	output pb_1pulse;
	reg pb_1pulse;
	reg pb_debounced_delay;
	always@(posedge clk) begin
		if(pb_debounced== 1'b1 & pb_debounced_delay== 1'b0) pb_1pulse <= 1'b1;
		else pb_1pulse <= 1'b0;
		pb_debounced_delay<= pb_debounced;
	end
endmodule

module state_cl (clk, now_state, cancel, drink_A, drink_B, count_drink_A, count_drink_B, money, next_drink_A, next_drink_B, next_state);
	input 	clk;
	input 	cancel;
	input 	[1:0] now_state;
	input 	drink_A;
	input 	drink_B;
	input 	[1:0] count_drink_A;
	input 	[1:0] count_drink_B;
	input 	[6:0] money;
	output 	[1:0] next_drink_A;
	output 	[1:0] next_drink_B;
	output 	[1:0] next_state;

	wire clk_16;
	clock_divider #(.n(16))	myclk_16 (.clk(clk), 	.clk_div(clk_16));
	wire de_cancel, de_drink_A, de_drink_B;
	debounce myde_cancel 	(.clk(clk_16), 	.pb(cancel), 	.pb_debounced(de_cancel));
	debounce myde_drink_A 	(.clk(clk_16), 	.pb(drink_A), 	.pb_debounced(de_drink_A));
	debounce myde_drink_B 	(.clk(clk_16), 	.pb(drink_B), 	.pb_debounced(de_drink_B));
	wire _cancel, _drink_A, _drink_B;
	onepulse myone_cancel	(.clk(clk_16), 	.pb_debounced(de_cancel), 	.pb_1pulse(_cancel));
	onepulse myone_drink_A	(.clk(clk_16), 	.pb_debounced(de_drink_A), 	.pb_1pulse(_drink_A));
	onepulse myone_drink_B	(.clk(clk_16), 	.pb_debounced(de_drink_B), 	.pb_1pulse(_drink_B));

	reg [1:0] temp_ans;
	reg [1:0] temp_A;
	reg [1:0] temp_B;


	always @(*) begin
		if (_cancel == 1'b1 && now_state == `DEPOSIT) begin
			temp_ans = `CHANGE;	
			temp_A = 2'd0;
			temp_B = 2'd0;
		end
		else if (_cancel == 1'b0) begin
			if (now_state == `INITIAL) begin
				temp_ans = `DEPOSIT;
				temp_A = 2'd0;
				temp_B = 2'd0;
			end
			else if (now_state == `DEPOSIT) begin
				if (count_drink_A == 2'd1 && _drink_A == 1'b1) begin
					if (money >= 7'd20) begin 
						temp_A = 2'd2;
						temp_B = 2'd0;
						temp_ans = now_state; 
					end
					else begin
						temp_A = 2'd0;
						temp_B = 2'd0;
						temp_ans = now_state; 
					end
				end
				else if (count_drink_B == 2'd1 && _drink_B == 1'b1) begin
					if (money >= 7'd25) begin 
						temp_A = 2'd0;
						temp_B = 2'd2;
						temp_ans = now_state; 
					end
					else begin
						temp_A = 2'd0;
						temp_B = 2'd0;
						temp_ans = now_state; 
					end
				end
				else if (count_drink_A == 2'd2) begin
					temp_A = 2'd2;
					temp_B = 2'd0;
					temp_ans = `BUY; 
				end
				else if (count_drink_B == 2'd2) begin
					temp_A = 2'd0;
					temp_B = 2'd2;
					temp_ans = `BUY; 
				end
				else if (_drink_A == 1'b1) begin
					temp_A = count_drink_A + 2'd1;
					temp_B = 2'd0;
					temp_ans = now_state; 
				end
				else if (_drink_B == 1'b1) begin
					temp_A = 2'd0;
					temp_B = count_drink_B + 2'd1;
					temp_ans = now_state; 
				end
				else begin
					temp_A = count_drink_A;
					temp_B = count_drink_B;
					temp_ans = now_state; 
				end
			end
			else if (now_state == `BUY) begin
				temp_ans = `CHANGE;
			end
			else if (now_state == `CHANGE) begin
				if (money == 7'd0) temp_ans = `INITIAL;
				else temp_ans = now_state;	
			end
		end
	end

	assign next_state = temp_ans;
	assign next_drink_A = temp_A;
	assign next_drink_B = temp_B;
endmodule 

module to_diplay (clk, bcd, digit, display);
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
            4'd10:next_display = `T;
            4'd11:next_display = `O;
            4'd12:next_display = `H;
            4'd13:next_display = `A;
            4'd14:next_display = `R;
            4'd15:next_display = `D;
    		default:next_display = `NINE;
    	endcase
    end

    assign _digit = digit;
    assign _display = display;
endmodule