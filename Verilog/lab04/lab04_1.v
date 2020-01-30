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


module lab4_1(
    input wire [15:0] SW,
    input wire clk,
    input wire reset,
    output wire [3:0] DIGIT,
    output wire [0:6] DISPLAY);


    wire my_clk;
    wire my_reset;

    
    reg [3:0] digit = 4'b1110;
    reg [3:0] next_digit = 4'b1110;
    reg [6:0] display = `ZERO;
    reg [6:0] next_display = `ZERO;

    reg [3:0] temp_value = 4'b0000;

    debounce a (.clk(clk), .pb(reset), .pb_debounced(my_reset));
    clock_divider  #(.n(13)) myclk (.clk(clk), .clk_div(my_clk));
    
    always @(posedge my_clk, posedge my_reset) begin
        if (my_reset == 1'b1) begin
            display <= `ZERO; // 0
        end
        else begin
            display <= next_display;
        end
        digit <= next_digit;
    end

// a little fucking delay problem
    always @(*)begin
        case (digit)
            4'b1110:begin 
                temp_value = SW[7:4];
                next_digit = {digit[2:0], digit[3]};
            end
            4'b1101:begin
                temp_value = SW[11:8];
                next_digit = {digit[2:0], digit[3]};
            end
            4'b1011:begin
                temp_value = SW[15:12];
                next_digit = {digit[2:0], digit[3]};
            end
            4'b0111:begin
                temp_value = SW[3:0];
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
            default:next_display = `NINE;
        endcase
    end


    assign DIGIT = digit;
    assign DISPLAY = display;



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
