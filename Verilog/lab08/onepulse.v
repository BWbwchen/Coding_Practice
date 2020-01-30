module onepulse(signal, clk, op);
    input signal, clk;
    output op;
    
    reg op;
    reg delay;
    
    always @(posedge clk) begin
        if((signal == 1) & (delay == 0)) op <= 1;
        else op <= 0; 
        delay = signal;
    end
endmodule