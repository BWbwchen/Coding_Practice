module lab1_2 (a, b, c, aluctr, d, e);
    input a, b, c;
    input [1:0] aluctr;
    output d, e;
    
    // answer here is for d
    wire ans_a, ans_b, ans_c, ans_d;
    mux4_to_1 mux (.a_i(ans_a), 
                   .b_i(ans_b),
                   .c_i(ans_c),
                   .d_i(ans_d),
                   .sel_i(aluctr),
                   .q_o(d)
                    );


    // ans here
    // ans_a
    assign ans_a = a^b^c;
    // ans_b
    assign ans_b = a&b;
    // ans_c
    assign ans_c = ~(a|b);
    // ans_d
    assign ans_d = a^b;

    // output e 
    assign e = ~aluctr[0] & ~aluctr[1] & (a&b|b&c|a&c);
endmodule 
