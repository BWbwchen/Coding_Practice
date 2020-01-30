module lab1_3 (a, b, c, aluctr, d, e);
    input a, b, c;
    input [1:0] aluctr;
    output d, e;
    
    // answer here is for d
    reg ans_a, ans_b, ans_c, ans_d, e;
    mux4_to_1 mux (.a_i(ans_a), 
                   .b_i(ans_b),
                   .c_i(ans_c),
                   .d_i(ans_d),
                   .sel_i(aluctr),
                   .q_o(d)
                    );

    always @(a or b or c or aluctr[0] or aluctr[1]) begin
        ans_a = a^b^c;
        ans_b = a&b;
        ans_c = ~(a|b);
        ans_d = a^b;
        e = ~aluctr[0] & ~aluctr[1] & (a&b|b&c|a&c); 
    end
endmodule 
