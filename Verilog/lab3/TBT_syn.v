/////////////////////////////////////////////////////////////
// Created by: Synopsys DC Expert(TM) in wire load mode
// Version   : K-2015.06-SP1
// Date      : Thu May  2 18:56:00 2019
/////////////////////////////////////////////////////////////


module adderSubtractor_0 ( a, b, cin, cout, sum );
  input [4:0] a;
  input [4:0] b;
  output [4:0] sum;
  input cin;
  output cout;
  wire   n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13;
  assign cout = 1'b0;

  XNOR2X1 U2 ( .A(n11), .B(n9), .Y(sum[1]) );
  XNOR2X1 U3 ( .A(n5), .B(n3), .Y(sum[3]) );
  XNOR2X1 U4 ( .A(n8), .B(n6), .Y(sum[2]) );
  XOR2X1 U5 ( .A(n1), .B(n2), .Y(sum[4]) );
  XOR2X1 U6 ( .A(a[0]), .B(n13), .Y(sum[0]) );
  OAI2BB1X1 U7 ( .A0N(a[0]), .A1N(b[0]), .B0(n12), .Y(n9) );
  OAI21XL U8 ( .A0(a[0]), .A1(b[0]), .B0(cin), .Y(n12) );
  AO22X1 U9 ( .A0(n6), .A1(a[2]), .B0(n7), .B1(b[2]), .Y(n3) );
  OR2X1 U10 ( .A(a[2]), .B(n6), .Y(n7) );
  XNOR2X1 U11 ( .A(a[1]), .B(b[1]), .Y(n11) );
  XNOR2X1 U12 ( .A(a[3]), .B(b[3]), .Y(n5) );
  XNOR2X1 U13 ( .A(a[2]), .B(b[2]), .Y(n8) );
  OAI2BB1X1 U14 ( .A0N(n9), .A1N(a[1]), .B0(n10), .Y(n6) );
  OAI21XL U15 ( .A0(a[1]), .A1(n9), .B0(b[1]), .Y(n10) );
  OAI2BB1X1 U16 ( .A0N(n3), .A1N(a[3]), .B0(n4), .Y(n1) );
  OAI21XL U17 ( .A0(a[3]), .A1(n3), .B0(b[3]), .Y(n4) );
  XOR2X1 U18 ( .A(b[4]), .B(a[4]), .Y(n2) );
  XOR2X1 U19 ( .A(cin), .B(b[0]), .Y(n13) );
endmodule


module adderSubtractor_4 ( a, b, cin, cout, sum );
  input [4:0] a;
  input [4:0] b;
  output [4:0] sum;
  input cin;
  output cout;
  wire   n14, n15, n16, n17, n18, n19, n20, n21, n22, n23, n24, n25, n26;
  assign cout = 1'b0;

  XNOR2X1 U2 ( .A(n22), .B(n24), .Y(sum[3]) );
  XNOR2X1 U3 ( .A(n19), .B(n21), .Y(sum[2]) );
  XNOR2X1 U4 ( .A(n16), .B(n18), .Y(sum[1]) );
  XOR2X1 U5 ( .A(a[0]), .B(n14), .Y(sum[0]) );
  XOR2X1 U6 ( .A(n26), .B(n25), .Y(sum[4]) );
  XNOR2X1 U7 ( .A(a[1]), .B(b[1]), .Y(n16) );
  OAI2BB1X1 U8 ( .A0N(a[0]), .A1N(b[0]), .B0(n15), .Y(n18) );
  OAI21XL U9 ( .A0(a[0]), .A1(b[0]), .B0(cin), .Y(n15) );
  AO22X1 U10 ( .A0(n21), .A1(a[2]), .B0(n20), .B1(b[2]), .Y(n24) );
  OR2X1 U11 ( .A(a[2]), .B(n21), .Y(n20) );
  XNOR2X1 U12 ( .A(a[3]), .B(b[3]), .Y(n22) );
  XNOR2X1 U13 ( .A(a[2]), .B(b[2]), .Y(n19) );
  OAI2BB1X1 U14 ( .A0N(n18), .A1N(a[1]), .B0(n17), .Y(n21) );
  OAI21XL U15 ( .A0(a[1]), .A1(n18), .B0(b[1]), .Y(n17) );
  OAI2BB1X1 U16 ( .A0N(n24), .A1N(a[3]), .B0(n23), .Y(n26) );
  OAI21XL U17 ( .A0(a[3]), .A1(n24), .B0(b[3]), .Y(n23) );
  XOR2X1 U18 ( .A(b[4]), .B(a[4]), .Y(n25) );
  XOR2X1 U19 ( .A(cin), .B(b[0]), .Y(n14) );
endmodule


module adderSubtractor_3 ( a, b, cin, cout, sum );
  input [4:0] a;
  input [4:0] b;
  output [4:0] sum;
  input cin;
  output cout;
  wire   n14, n15, n16, n17, n18, n19, n20, n21, n22, n23, n24, n25, n26;
  assign cout = 1'b0;

  OAI21XL U2 ( .A0(a[3]), .A1(n24), .B0(b[3]), .Y(n23) );
  AO22X1 U3 ( .A0(n21), .A1(a[2]), .B0(n20), .B1(b[2]), .Y(n24) );
  OR2X1 U4 ( .A(a[2]), .B(n21), .Y(n20) );
  OAI2BB1X1 U5 ( .A0N(a[0]), .A1N(b[0]), .B0(n15), .Y(n18) );
  OAI21XL U6 ( .A0(a[0]), .A1(b[0]), .B0(cin), .Y(n15) );
  OAI2BB1X1 U7 ( .A0N(n18), .A1N(a[1]), .B0(n17), .Y(n21) );
  OAI21XL U8 ( .A0(a[1]), .A1(n18), .B0(b[1]), .Y(n17) );
  XOR2X1 U9 ( .A(n26), .B(n25), .Y(sum[4]) );
  XOR2X1 U10 ( .A(b[4]), .B(a[4]), .Y(n25) );
  OAI2BB1X1 U11 ( .A0N(n24), .A1N(a[3]), .B0(n23), .Y(n26) );
  XNOR2X1 U12 ( .A(n22), .B(n24), .Y(sum[3]) );
  XNOR2X1 U13 ( .A(a[3]), .B(b[3]), .Y(n22) );
  XNOR2X1 U14 ( .A(n19), .B(n21), .Y(sum[2]) );
  XNOR2X1 U15 ( .A(a[2]), .B(b[2]), .Y(n19) );
  XNOR2X1 U16 ( .A(n16), .B(n18), .Y(sum[1]) );
  XNOR2X1 U17 ( .A(a[1]), .B(b[1]), .Y(n16) );
  XOR2X1 U18 ( .A(a[0]), .B(n14), .Y(sum[0]) );
  XOR2X1 U19 ( .A(cin), .B(b[0]), .Y(n14) );
endmodule


module adderSubtractor_2 ( a, b, cin, cout, sum );
  input [4:0] a;
  input [4:0] b;
  output [4:0] sum;
  input cin;
  output cout;
  wire   n14, n15, n16, n17, n18, n19, n20, n21, n22, n23, n24, n25, n26;
  assign cout = 1'b0;

  XNOR2X1 U2 ( .A(n22), .B(n24), .Y(sum[3]) );
  XNOR2X1 U3 ( .A(n19), .B(n21), .Y(sum[2]) );
  XNOR2X1 U4 ( .A(n16), .B(n18), .Y(sum[1]) );
  XOR2X1 U5 ( .A(a[0]), .B(n14), .Y(sum[0]) );
  XOR2X1 U6 ( .A(n26), .B(n25), .Y(sum[4]) );
  XNOR2X1 U7 ( .A(a[2]), .B(b[2]), .Y(n19) );
  XNOR2X1 U8 ( .A(a[1]), .B(b[1]), .Y(n16) );
  XNOR2X1 U9 ( .A(a[3]), .B(b[3]), .Y(n22) );
  AO22X1 U10 ( .A0(n21), .A1(a[2]), .B0(n20), .B1(b[2]), .Y(n24) );
  OR2X1 U11 ( .A(a[2]), .B(n21), .Y(n20) );
  OAI2BB1X1 U12 ( .A0N(a[0]), .A1N(b[0]), .B0(n15), .Y(n18) );
  OAI21XL U13 ( .A0(a[0]), .A1(b[0]), .B0(cin), .Y(n15) );
  OAI2BB1X1 U14 ( .A0N(n18), .A1N(a[1]), .B0(n17), .Y(n21) );
  OAI21XL U15 ( .A0(a[1]), .A1(n18), .B0(b[1]), .Y(n17) );
  OAI2BB1X1 U16 ( .A0N(n24), .A1N(a[3]), .B0(n23), .Y(n26) );
  OAI21XL U17 ( .A0(a[3]), .A1(n24), .B0(b[3]), .Y(n23) );
  XOR2X1 U18 ( .A(b[4]), .B(a[4]), .Y(n25) );
  XOR2X1 U19 ( .A(cin), .B(b[0]), .Y(n14) );
endmodule


module adderSubtractor_1 ( a, b, cin, cout, sum );
  input [4:0] a;
  input [4:0] b;
  output [4:0] sum;
  input cin;
  output cout;
  wire   n14, n15, n16, n17, n18, n19, n20, n21, n22, n23, n24, n25, n26;
  assign cout = 1'b0;

  AO22X1 U2 ( .A0(n21), .A1(a[2]), .B0(n20), .B1(b[2]), .Y(n24) );
  OR2X1 U3 ( .A(a[2]), .B(n21), .Y(n20) );
  OAI2BB1X1 U4 ( .A0N(a[0]), .A1N(b[0]), .B0(n15), .Y(n18) );
  OAI21XL U5 ( .A0(a[0]), .A1(b[0]), .B0(cin), .Y(n15) );
  OAI2BB1X1 U6 ( .A0N(n18), .A1N(a[1]), .B0(n17), .Y(n21) );
  OAI21XL U7 ( .A0(a[1]), .A1(n18), .B0(b[1]), .Y(n17) );
  XOR2X1 U8 ( .A(n26), .B(n25), .Y(sum[4]) );
  XOR2X1 U9 ( .A(b[4]), .B(a[4]), .Y(n25) );
  OAI2BB1X1 U10 ( .A0N(n24), .A1N(a[3]), .B0(n23), .Y(n26) );
  XNOR2X1 U11 ( .A(n22), .B(n24), .Y(sum[3]) );
  XNOR2X1 U12 ( .A(a[3]), .B(b[3]), .Y(n22) );
  XNOR2X1 U13 ( .A(n19), .B(n21), .Y(sum[2]) );
  XNOR2X1 U14 ( .A(a[2]), .B(b[2]), .Y(n19) );
  XNOR2X1 U15 ( .A(n16), .B(n18), .Y(sum[1]) );
  XNOR2X1 U16 ( .A(a[1]), .B(b[1]), .Y(n16) );
  XOR2X1 U17 ( .A(a[0]), .B(n14), .Y(sum[0]) );
  XOR2X1 U18 ( .A(cin), .B(b[0]), .Y(n14) );
  OAI21XL U19 ( .A0(a[3]), .A1(n24), .B0(b[3]), .Y(n23) );
endmodule


module TBT ( clk, rst, start, data, en, addr, fin, result );
  input [4:0] data;
  output [4:0] addr;
  output [4:0] result;
  input clk, rst, start;
  output en, fin;
  wire   now, state, N21, N35, n8, n9, n12, n16, n17, n18, n19, n20, n21, n22,
         n23, n24, n25, n26, n27, n29, n30, n31, n32, n33, n34, n35, n36, n37,
         n38, n39, n40, n42, n43, n44, n45, n46, n47, n48, n49, n50, n51, n52,
         n53, n54, n55, n57, n58, n59, n60;
  wire   [4:0] leng;
  wire   [4:0] ans;
  wire   [4:0] next_num;
  wire   [4:0] ans_N1;
  wire   [4:0] num_Plus;
  assign en = 1'b1;

  adderSubtractor_0 a1 ( .a(ans), .b({1'b0, 1'b0, 1'b0, 1'b0, 1'b1}), .cin(
        1'b0) );
  adderSubtractor_4 a2 ( .a(ans), .b({1'b0, 1'b0, 1'b0, 1'b1, 1'b0}), .cin(
        1'b0) );
  adderSubtractor_3 a3 ( .a(ans), .b({1'b1, 1'b1, 1'b1, 1'b1, 1'b1}), .cin(
        1'b0), .sum(ans_N1) );
  adderSubtractor_2 a4 ( .a(ans), .b({1'b1, 1'b1, 1'b1, 1'b1, 1'b0}), .cin(
        1'b0) );
  adderSubtractor_1 a5 ( .a(addr), .b({1'b0, 1'b0, 1'b0, 1'b0, 1'b1}), .cin(
        1'b0), .sum(num_Plus) );
  DFFSX1 now_reg ( .D(n39), .CK(clk), .SN(n55), .Q(now), .QN(n44) );
  DFFRX1 \leng_reg[0]  ( .D(n37), .CK(clk), .RN(n55), .Q(leng[0]), .QN(n26) );
  DFFRX1 \leng_reg[4]  ( .D(n38), .CK(clk), .RN(n55), .Q(leng[4]), .QN(n27) );
  DFFRX1 \leng_reg[2]  ( .D(n35), .CK(clk), .RN(n55), .QN(n24) );
  DFFRX1 \leng_reg[3]  ( .D(n34), .CK(clk), .RN(n55), .QN(n23) );
  DFFRX1 \leng_reg[1]  ( .D(n36), .CK(clk), .RN(n55), .Q(leng[1]), .QN(n25) );
  DFFSX1 \num_reg[2]  ( .D(next_num[2]), .CK(clk), .SN(n55), .Q(addr[2]) );
  DFFSX1 \num_reg[3]  ( .D(next_num[3]), .CK(clk), .SN(n55), .Q(addr[3]) );
  DFFSX1 \num_reg[0]  ( .D(next_num[0]), .CK(clk), .SN(n55), .Q(addr[0]) );
  DFFSX1 \num_reg[4]  ( .D(next_num[4]), .CK(clk), .SN(n55), .Q(addr[4]), .QN(
        n43) );
  DFFRX1 \ans_reg[4]  ( .D(n29), .CK(clk), .RN(n55), .Q(ans[4]), .QN(n18) );
  DFFRX1 state_reg ( .D(n40), .CK(clk), .RN(n55), .Q(state) );
  DFFSX1 \num_reg[1]  ( .D(next_num[1]), .CK(clk), .SN(n55), .Q(addr[1]), .QN(
        n42) );
  DFFRX1 \ans_reg[2]  ( .D(n31), .CK(clk), .RN(n55), .Q(ans[2]), .QN(n20) );
  DFFRX1 \ans_reg[1]  ( .D(n32), .CK(clk), .RN(n55), .Q(ans[1]), .QN(n21) );
  DFFRX1 \ans_reg[3]  ( .D(n30), .CK(clk), .RN(n55), .Q(ans[3]), .QN(n19) );
  DFFRX1 \ans_reg[0]  ( .D(n33), .CK(clk), .RN(n55), .Q(ans[0]), .QN(n22) );
  CLKINVX1 U38 ( .A(n12), .Y(n57) );
  CLKINVX1 U39 ( .A(n8), .Y(fin) );
  OAI2BB2XL U40 ( .B0(n18), .B1(n16), .A0N(ans_N1[4]), .A1N(n16), .Y(n29) );
  NAND2BX1 U41 ( .AN(state), .B(start), .Y(n12) );
  OAI22XL U42 ( .A0(n23), .A1(n57), .B0(n12), .B1(n59), .Y(n34) );
  OAI22XL U43 ( .A0(n25), .A1(n57), .B0(n12), .B1(n60), .Y(n36) );
  OAI22XL U44 ( .A0(n27), .A1(n57), .B0(n12), .B1(n58), .Y(n38) );
  AND4X1 U45 ( .A(N21), .B(n9), .C(state), .D(now), .Y(n16) );
  OAI2BB2XL U46 ( .B0(n19), .B1(n16), .A0N(ans_N1[3]), .A1N(n16), .Y(n30) );
  OAI2BB2XL U47 ( .B0(n20), .B1(n16), .A0N(ans_N1[2]), .A1N(n16), .Y(n31) );
  OAI2BB2XL U48 ( .B0(n21), .B1(n16), .A0N(ans_N1[1]), .A1N(n16), .Y(n32) );
  OAI2BB2XL U49 ( .B0(n22), .B1(n16), .A0N(ans_N1[0]), .A1N(n16), .Y(n33) );
  OAI2BB2XL U50 ( .B0(n24), .B1(n57), .A0N(data[2]), .A1N(n57), .Y(n35) );
  OAI2BB2XL U51 ( .B0(n26), .B1(n57), .A0N(data[0]), .A1N(n57), .Y(n37) );
  OAI2BB1X1 U52 ( .A0N(num_Plus[4]), .A1N(state), .B0(n40), .Y(next_num[4]) );
  OAI2BB1X1 U53 ( .A0N(num_Plus[3]), .A1N(state), .B0(n40), .Y(next_num[3]) );
  OAI2BB1X1 U54 ( .A0N(num_Plus[2]), .A1N(state), .B0(n40), .Y(next_num[2]) );
  OAI2BB1X1 U55 ( .A0N(num_Plus[1]), .A1N(state), .B0(n40), .Y(next_num[1]) );
  OAI21XL U56 ( .A0(n9), .A1(n44), .B0(state), .Y(n39) );
  OR2X1 U57 ( .A(state), .B(start), .Y(n40) );
  OAI2BB1X1 U58 ( .A0N(num_Plus[0]), .A1N(state), .B0(n40), .Y(next_num[0]) );
  NAND2X1 U59 ( .A(start), .B(N35), .Y(n8) );
  CLKINVX1 U60 ( .A(rst), .Y(n55) );
  AND4X1 U61 ( .A(n17), .B(n60), .C(n59), .D(n58), .Y(n9) );
  XOR2X1 U62 ( .A(data[2]), .B(data[0]), .Y(n17) );
  NOR2X1 U63 ( .A(n22), .B(n8), .Y(result[0]) );
  NOR2X1 U64 ( .A(n21), .B(n8), .Y(result[1]) );
  NOR2X1 U65 ( .A(n20), .B(n8), .Y(result[2]) );
  NOR2X1 U66 ( .A(n19), .B(n8), .Y(result[3]) );
  NOR2X1 U67 ( .A(n18), .B(n8), .Y(result[4]) );
  CLKINVX1 U68 ( .A(data[4]), .Y(n58) );
  CLKINVX1 U69 ( .A(data[3]), .Y(n59) );
  CLKINVX1 U70 ( .A(data[1]), .Y(n60) );
  NAND2X1 U71 ( .A(addr[2]), .B(n24), .Y(n54) );
  NAND2X1 U72 ( .A(addr[3]), .B(n23), .Y(n53) );
  NOR2BX1 U73 ( .AN(addr[0]), .B(leng[0]), .Y(n45) );
  OAI22XL U74 ( .A0(addr[1]), .A1(n45), .B0(n45), .B1(n25), .Y(n46) );
  OAI21XL U75 ( .A0(leng[4]), .A1(n43), .B0(n46), .Y(n52) );
  NOR2BX1 U76 ( .AN(leng[0]), .B(addr[0]), .Y(n48) );
  AO21X1 U77 ( .A0(n42), .A1(n48), .B0(leng[1]), .Y(n47) );
  OAI211X1 U78 ( .A0(n48), .A1(n42), .B0(n47), .C0(n54), .Y(n49) );
  OAI221XL U79 ( .A0(addr[2]), .A1(n24), .B0(addr[3]), .B1(n23), .C0(n49), .Y(
        n50) );
  OAI211X1 U80 ( .A0(leng[4]), .A1(n43), .B0(n50), .C0(n53), .Y(n51) );
  OAI2BB1X1 U81 ( .A0N(n43), .A1N(leng[4]), .B0(n51), .Y(N21) );
  NOR4BBX1 U82 ( .AN(n54), .BN(n53), .C(n52), .D(N21), .Y(N35) );
endmodule

