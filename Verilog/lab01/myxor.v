module myxor (out, a, b); 
    input a, b;
    output out;

    wire not_a, not_b, temp_1, temp_2;

    not _a (not_a, a);
    not _b (not_b, b);
    and _temp1 (temp_1, not_a, b);
    and _temp2 (temp_2, a, not_b);
    or ans (out, temp_1, temp_2);
endmodule
