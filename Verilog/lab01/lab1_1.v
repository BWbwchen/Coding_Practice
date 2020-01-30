module lab1_1 (a, b, c, aluctr, d, e);
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
    wire xor_temp_1;
    myxor xxxor  (.a(a), .b(b), .out(xor_temp_1));
    myxor xxxor1 (.a(xor_temp_1), .b(c), .out(ans_a));
    // ans_b
    and aand (ans_b, a, b);
    // ans_c
    nor nnor (ans_c, a, b);
    // ans_d
    myxor xxxor2 (.a(a), .b(b), .out(ans_d));


    // output e 
    wire [1:0] not_sel;
    wire and_ab, and_bc, and_ac, or_temp_1, or_temp_2;
    wire temp_ans_1;
    not nnot (not_sel[1], aluctr[1]);
    not nnot1 (not_sel[0], aluctr[0]);
    and and1 (and_ab, a, b);
    and and2 (and_bc, b, c);
    and and3 (and_ac, a, c);
    or oor (or_temp_1, and_ab, and_bc); 
    or oor1 (or_temp_2, or_temp_1, and_ac); 
    and aand1 (temp_ans_1, or_temp_2, not_sel[0]);
    and aand2 (e, temp_ans_1, not_sel[1]);
endmodule 
