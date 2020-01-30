module one_digit_gray_counter (clk, rst_n, en, dir, gray, cout);
    input clk, rst_n, en, dir;
    output [3:0] gray;
    output cout;

    reg [3:0] temp_out, next_out;
    reg [3:0] counter_out = 4'b0000;
    reg temp_cout = 1'b0;
    reg for_overflow;

    always @(*) begin
        temp_out = next_out;
        if (counter_out == 4'b1111 && dir == 1'b1 || counter_out == 4'b0000 && dir == 1'b0) temp_cout = 1'b1;
        else temp_cout = 1'b0;
    end

    always @(negedge clk or negedge rst_n) begin
        if (rst_n == 1'b0) {temp_cout, counter_out} = 5'b00000;
        else if (en == 1'b0) {temp_out, counter_out} = {temp_out, counter_out};
        else begin
            if (dir == 1'b1) begin
                {for_overflow, counter_out} = {1'b0, counter_out} + 5'b00001;
            end
            else begin
                {for_overflow, counter_out} = {1'b0, counter_out} - 5'b00001;
            end
        end
    end

    always @(*) begin
        case (counter_out) 
            4'b0000: next_out = 4'b0000;
            4'b0001: next_out = 4'b0001;
            4'b0010: next_out = 4'b0011;
            4'b0011: next_out = 4'b0010;
            4'b0100: next_out = 4'b0110;
            4'b0101: next_out = 4'b0111;
            4'b0110: next_out = 4'b0101;
            4'b0111: next_out = 4'b0100;
            4'b1000: next_out = 4'b1100;
            4'b1001: next_out = 4'b1101;
            4'b1010: next_out = 4'b1111;
            4'b1011: next_out = 4'b1110;
            4'b1100: next_out = 4'b1010;
            4'b1101: next_out = 4'b1011;
            4'b1110: next_out = 4'b1001;
            4'b1111: next_out = 4'b1000;
            default : next_out = 4'b0000;
        endcase
    end


    assign gray = temp_out;
    assign cout = temp_cout;

endmodule



module lab2_2 (clk, rst_n, en, dir, gray, cout);
    input clk, rst_n, en, dir;
    output [7:0] gray;
    output cout; 

    wire cout_from_below;
    wire cout_big;
    reg temp_cout;
    
    one_digit_gray_counter right (.clk(clk), .rst_n(rst_n), .en(en), .dir(dir), .gray(gray[3:0]), .cout(cout_from_below));
    one_digit_gray_counter left  (.clk(clk), .rst_n(rst_n), .en(cout_from_below), .dir(dir), .gray(gray[7:4]), .cout(cout_big));
    always @(*)begin
        if ((gray == 8'b10001000 && dir == 1'b1) || (gray == 8'b00000000 && dir == 1'b0)) temp_cout = 1'b1;
        else temp_cout = 1'b0;
    end
    
    assign cout = temp_cout;

endmodule