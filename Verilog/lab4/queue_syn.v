/////////////////////////////////////////////////////////////
// Created by: Synopsys DC Expert(TM) in wire load mode
// Version   : K-2015.06-SP1
// Date      : Fri May 24 23:12:02 2019
/////////////////////////////////////////////////////////////


module queue ( clk, reset, go, cmd, r_num, ready, w_en, r_en, full, 
        almost_full, empty, almost_empty, error, w_num, addr );
  input [17:0] cmd;
  input [15:0] r_num;
  output [15:0] w_num;
  output [4:0] addr;
  input clk, reset, go;
  output ready, w_en, r_en, full, almost_full, empty, almost_empty, error;
  wire   state, N25, N26, N27, N28, N30, N31, N32, N33, N34, N37, N38, N39,
         N40, N42, N43, N44, N45, N46, n2, n3, n4, n5, n7, n8, n10, n12, n14,
         n16, n17, n18, n20, n21, n22, n24, n25, n26, n27, n28, n29, n30, n31,
         n32, n33, n34, n35, n36, n37, n38, n39, n40, n43, n44, n46, n47, n48,
         n49, n50, n51, n52, n53, n54, n55, n56, n57, n58, n59, n60, n61, n62,
         n63, n64, n65, n67, n68, n70, n71, n72, n73, n74, n75, n76, n77, n78,
         n79, n80, n81, n82, n83, n84, n85, n86, n87, n88, n89, n90, n91, n92,
         n93, n94, n95, n96, n97, n98, n99, n100, n102, n103, n104, n105, n106,
         n107, n108, n109, n110, n111, n112, n113, n114, n115, n116, n117,
         n118, n119, n120, n121, n122, n123, n124, n125, n126, n127, n128,
         n129, n130, n131, n132, n133, n134, n135, n136, n137, n143, n144,
         n145, n146, n147, n148, n149, n150, n151, n152, n153, n154, n155,
         n156, n157, n159, n160, n163;
  wire   [4:0] head;
  wire   [4:0] tail;
  wire   [5:0] count;
  wire   [4:2] \add_115/carry ;
  wire   [5:2] \r323/carry ;
  wire   [4:2] \r322/carry ;

  DFFRX1 ren_reg ( .D(n136), .CK(clk), .RN(n156), .Q(r_en), .QN(n78) );
  DFFRX1 wen_reg ( .D(n127), .CK(clk), .RN(n156), .Q(w_en), .QN(n72) );
  DFFRX1 \num_reg[9]  ( .D(n118), .CK(clk), .RN(n156), .Q(w_num[9]), .QN(n100)
         );
  DFFRX1 \num_reg[8]  ( .D(n117), .CK(clk), .RN(n156), .Q(w_num[8]), .QN(n99)
         );
  DFFRX1 \num_reg[7]  ( .D(n116), .CK(clk), .RN(n156), .Q(w_num[7]), .QN(n98)
         );
  DFFRX1 \num_reg[6]  ( .D(n115), .CK(clk), .RN(n156), .Q(w_num[6]), .QN(n97)
         );
  DFFRX1 \num_reg[5]  ( .D(n114), .CK(clk), .RN(n156), .Q(w_num[5]), .QN(n96)
         );
  DFFRX1 \num_reg[4]  ( .D(n113), .CK(clk), .RN(n156), .Q(w_num[4]), .QN(n95)
         );
  DFFRX1 \num_reg[3]  ( .D(n112), .CK(clk), .RN(n156), .Q(w_num[3]), .QN(n94)
         );
  DFFRX1 \num_reg[2]  ( .D(n111), .CK(clk), .RN(n156), .Q(w_num[2]), .QN(n93)
         );
  DFFRX1 \num_reg[1]  ( .D(n110), .CK(clk), .RN(n156), .Q(w_num[1]), .QN(n92)
         );
  DFFRX1 \num_reg[15]  ( .D(n109), .CK(clk), .RN(n156), .Q(w_num[15]), .QN(n91) );
  DFFRX1 \num_reg[14]  ( .D(n108), .CK(clk), .RN(n156), .Q(w_num[14]), .QN(n90) );
  DFFRX1 \num_reg[13]  ( .D(n107), .CK(clk), .RN(n156), .Q(w_num[13]), .QN(n89) );
  DFFRX1 \num_reg[12]  ( .D(n106), .CK(clk), .RN(n156), .Q(w_num[12]), .QN(n88) );
  DFFRX1 \num_reg[11]  ( .D(n105), .CK(clk), .RN(n156), .Q(w_num[11]), .QN(n87) );
  DFFRX1 \num_reg[10]  ( .D(n104), .CK(clk), .RN(n156), .Q(w_num[10]), .QN(n86) );
  DFFRX1 \num_reg[0]  ( .D(n103), .CK(clk), .RN(n156), .Q(w_num[0]), .QN(n85)
         );
  DFFRX1 _error_reg ( .D(n102), .CK(clk), .RN(n156), .Q(error), .QN(n84) );
  DFFSX1 \head_reg[4]  ( .D(n131), .CK(clk), .SN(n156), .Q(head[4]), .QN(n73)
         );
  DFFSX1 \head_reg[3]  ( .D(n135), .CK(clk), .SN(n156), .Q(head[3]), .QN(n77)
         );
  DFFSX1 \head_reg[1]  ( .D(n133), .CK(clk), .SN(n156), .Q(head[1]), .QN(n75)
         );
  DFFSX1 \head_reg[2]  ( .D(n132), .CK(clk), .SN(n156), .Q(head[2]), .QN(n74)
         );
  DFFSX1 \tail_reg[4]  ( .D(n122), .CK(clk), .SN(n156), .Q(tail[4]), .QN(n145)
         );
  DFFRX1 is_pop_prev_reg ( .D(n130), .CK(clk), .RN(n156), .QN(n82) );
  DFFRX1 \count_reg[4]  ( .D(n121), .CK(clk), .RN(n156), .Q(count[4]), .QN(n71) );
  DFFRX1 \count_reg[2]  ( .D(n120), .CK(clk), .RN(n156), .Q(count[2]), .QN(n79) );
  DFFRX1 \count_reg[3]  ( .D(n119), .CK(clk), .RN(n156), .Q(count[3]), .QN(n70) );
  DFFSX1 \head_reg[0]  ( .D(n134), .CK(clk), .SN(n156), .Q(head[0]), .QN(n76)
         );
  DFFRX1 \count_reg[5]  ( .D(n128), .CK(clk), .RN(n156), .Q(count[5]), .QN(n80) );
  DFFSX1 \tail_reg[2]  ( .D(n126), .CK(clk), .SN(n156), .Q(tail[2]), .QN(n147)
         );
  DFFSX1 \tail_reg[1]  ( .D(n124), .CK(clk), .SN(n156), .Q(tail[1]), .QN(n146)
         );
  DFFSX1 \tail_reg[3]  ( .D(n123), .CK(clk), .SN(n156), .Q(tail[3]), .QN(n148)
         );
  DFFRX1 \count_reg[1]  ( .D(n129), .CK(clk), .RN(n156), .Q(count[1]), .QN(n81) );
  DFFSX1 \tail_reg[0]  ( .D(n125), .CK(clk), .SN(n156), .Q(tail[0]), .QN(n149)
         );
  DFFRX1 \count_reg[0]  ( .D(n137), .CK(clk), .RN(n156), .Q(count[0]), .QN(n83) );
  DFFRX1 state_reg ( .D(1'b1), .CK(clk), .RN(n156), .Q(state), .QN(n144) );
  AND2X2 U119 ( .A(n40), .B(n159), .Y(n143) );
  OAI31XL U120 ( .A0(full), .A1(cmd[16]), .A2(ready), .B0(state), .Y(n17) );
  AND2X2 U121 ( .A(n64), .B(n43), .Y(n55) );
  CLKBUFX3 U122 ( .A(n21), .Y(n150) );
  NOR2BX1 U123 ( .AN(n43), .B(n157), .Y(n21) );
  NOR2X1 U124 ( .A(n160), .B(n157), .Y(n40) );
  NOR2BX1 U125 ( .AN(n64), .B(n20), .Y(n57) );
  AND2X2 U126 ( .A(n3), .B(n17), .Y(n8) );
  CLKINVX1 U127 ( .A(n17), .Y(n157) );
  NAND2X1 U128 ( .A(n157), .B(n54), .Y(n64) );
  NOR2X1 U129 ( .A(n18), .B(n157), .Y(n5) );
  CLKINVX1 U130 ( .A(n46), .Y(n163) );
  NAND2X1 U131 ( .A(n18), .B(n68), .Y(n43) );
  CLKINVX1 U132 ( .A(n68), .Y(n160) );
  CLKINVX1 U133 ( .A(n44), .Y(empty) );
  CLKINVX1 U134 ( .A(n4), .Y(full) );
  OA21XL U135 ( .A0(n159), .A1(n144), .B0(n160), .Y(n65) );
  NAND3X1 U136 ( .A(state), .B(n159), .C(cmd[16]), .Y(n20) );
  NAND2X1 U137 ( .A(state), .B(n54), .Y(n48) );
  NAND3X1 U138 ( .A(n83), .B(n163), .C(n80), .Y(n44) );
  NAND4X1 U139 ( .A(n70), .B(n71), .C(n79), .D(n81), .Y(n46) );
  NAND3X1 U140 ( .A(n163), .B(count[5]), .C(n83), .Y(n4) );
  NAND4X1 U141 ( .A(cmd[16]), .B(n44), .C(go), .D(n159), .Y(n54) );
  OAI21XL U142 ( .A0(n79), .A1(n55), .B0(n61), .Y(n120) );
  AOI22X1 U143 ( .A0(N43), .A1(n57), .B0(N31), .B1(n58), .Y(n61) );
  OAI21XL U144 ( .A0(n71), .A1(n55), .B0(n59), .Y(n121) );
  AOI22X1 U145 ( .A0(N45), .A1(n57), .B0(N33), .B1(n58), .Y(n59) );
  OAI21XL U146 ( .A0(n80), .A1(n55), .B0(n56), .Y(n128) );
  AOI22X1 U147 ( .A0(N46), .A1(n57), .B0(N34), .B1(n58), .Y(n56) );
  OAI21XL U148 ( .A0(n81), .A1(n55), .B0(n62), .Y(n129) );
  AOI22X1 U149 ( .A0(N42), .A1(n57), .B0(N30), .B1(n58), .Y(n62) );
  OAI21XL U150 ( .A0(n83), .A1(n55), .B0(n63), .Y(n137) );
  AOI22X1 U151 ( .A0(n83), .A1(n57), .B0(n83), .B1(n58), .Y(n63) );
  NOR2X1 U152 ( .A(n144), .B(cmd[16]), .Y(n68) );
  NOR2X1 U153 ( .A(cmd[16]), .B(n18), .Y(n3) );
  AND3X2 U154 ( .A(n3), .B(n64), .C(state), .Y(n58) );
  AND2X2 U155 ( .A(n82), .B(cmd[17]), .Y(n18) );
  OAI2BB2XL U156 ( .B0(n82), .B1(n48), .A0N(n48), .A1N(state), .Y(n130) );
  OAI2BB2XL U157 ( .B0(go), .B1(n84), .A0N(go), .A1N(n67), .Y(n102) );
  OAI221XL U158 ( .A0(n44), .A1(n20), .B0(n4), .B1(n160), .C0(n43), .Y(n67) );
  OAI21XL U159 ( .A0(n70), .A1(n55), .B0(n60), .Y(n119) );
  AOI22X1 U160 ( .A0(N44), .A1(n57), .B0(N32), .B1(n58), .Y(n60) );
  OAI21XL U161 ( .A0(n150), .A1(n85), .B0(n39), .Y(n103) );
  AOI22X1 U162 ( .A0(cmd[0]), .A1(n143), .B0(r_num[0]), .B1(n151), .Y(n39) );
  OAI21XL U163 ( .A0(n150), .A1(n86), .B0(n38), .Y(n104) );
  AOI22X1 U164 ( .A0(cmd[10]), .A1(n143), .B0(r_num[10]), .B1(n151), .Y(n38)
         );
  OAI21XL U165 ( .A0(n150), .A1(n87), .B0(n37), .Y(n105) );
  AOI22X1 U166 ( .A0(cmd[11]), .A1(n143), .B0(r_num[11]), .B1(n151), .Y(n37)
         );
  OAI21XL U167 ( .A0(n150), .A1(n88), .B0(n36), .Y(n106) );
  AOI22X1 U168 ( .A0(cmd[12]), .A1(n143), .B0(r_num[12]), .B1(n151), .Y(n36)
         );
  OAI21XL U169 ( .A0(n150), .A1(n89), .B0(n35), .Y(n107) );
  AOI22X1 U170 ( .A0(cmd[13]), .A1(n143), .B0(r_num[13]), .B1(n151), .Y(n35)
         );
  OAI21XL U171 ( .A0(n150), .A1(n90), .B0(n34), .Y(n108) );
  AOI22X1 U172 ( .A0(cmd[14]), .A1(n143), .B0(r_num[14]), .B1(n151), .Y(n34)
         );
  OAI21XL U173 ( .A0(n150), .A1(n91), .B0(n33), .Y(n109) );
  AOI22X1 U174 ( .A0(cmd[15]), .A1(n143), .B0(r_num[15]), .B1(n151), .Y(n33)
         );
  OAI21XL U175 ( .A0(n150), .A1(n92), .B0(n32), .Y(n110) );
  AOI22X1 U176 ( .A0(cmd[1]), .A1(n143), .B0(r_num[1]), .B1(n151), .Y(n32) );
  OAI21XL U177 ( .A0(n150), .A1(n93), .B0(n31), .Y(n111) );
  AOI22X1 U178 ( .A0(cmd[2]), .A1(n143), .B0(r_num[2]), .B1(n151), .Y(n31) );
  OAI21XL U179 ( .A0(n150), .A1(n94), .B0(n30), .Y(n112) );
  AOI22X1 U180 ( .A0(cmd[3]), .A1(n143), .B0(r_num[3]), .B1(n151), .Y(n30) );
  OAI21XL U181 ( .A0(n150), .A1(n95), .B0(n29), .Y(n113) );
  AOI22X1 U182 ( .A0(cmd[4]), .A1(n143), .B0(r_num[4]), .B1(n151), .Y(n29) );
  OAI21XL U183 ( .A0(n150), .A1(n96), .B0(n28), .Y(n114) );
  AOI22X1 U184 ( .A0(cmd[5]), .A1(n143), .B0(r_num[5]), .B1(n151), .Y(n28) );
  OAI21XL U185 ( .A0(n150), .A1(n97), .B0(n27), .Y(n115) );
  AOI22X1 U186 ( .A0(cmd[6]), .A1(n143), .B0(r_num[6]), .B1(n151), .Y(n27) );
  OAI21XL U187 ( .A0(n150), .A1(n98), .B0(n26), .Y(n116) );
  AOI22X1 U188 ( .A0(cmd[7]), .A1(n143), .B0(r_num[7]), .B1(n151), .Y(n26) );
  OAI21XL U189 ( .A0(n150), .A1(n99), .B0(n25), .Y(n117) );
  AOI22X1 U190 ( .A0(cmd[8]), .A1(n143), .B0(r_num[8]), .B1(n151), .Y(n25) );
  OAI21XL U191 ( .A0(n150), .A1(n100), .B0(n22), .Y(n118) );
  AOI22X1 U192 ( .A0(cmd[9]), .A1(n143), .B0(r_num[9]), .B1(n151), .Y(n22) );
  CLKBUFX3 U193 ( .A(n24), .Y(n151) );
  NOR3BXL U194 ( .AN(n40), .B(n159), .C(n82), .Y(n24) );
  ADDHXL U195 ( .A(tail[1]), .B(tail[0]), .CO(\r322/carry [2]), .S(N25) );
  ADDHXL U196 ( .A(count[1]), .B(count[0]), .CO(\r323/carry [2]), .S(N30) );
  ADDHXL U197 ( .A(head[1]), .B(head[0]), .CO(\add_115/carry [2]), .S(N37) );
  ADDHXL U198 ( .A(tail[2]), .B(\r322/carry [2]), .CO(\r322/carry [3]), .S(N26) );
  ADDHXL U199 ( .A(count[3]), .B(\r323/carry [3]), .CO(\r323/carry [4]), .S(
        N32) );
  ADDHXL U200 ( .A(count[2]), .B(\r323/carry [2]), .CO(\r323/carry [3]), .S(
        N31) );
  ADDHXL U201 ( .A(head[2]), .B(\add_115/carry [2]), .CO(\add_115/carry [3]), 
        .S(N38) );
  OAI32X1 U202 ( .A0(n20), .A1(ready), .A2(empty), .B0(go), .B1(n78), .Y(n136)
         );
  OAI211X1 U203 ( .A0(n73), .A1(n48), .B0(n49), .C0(state), .Y(n131) );
  NAND2X1 U204 ( .A(N40), .B(n48), .Y(n49) );
  OAI211X1 U205 ( .A0(n74), .A1(n48), .B0(n51), .C0(state), .Y(n132) );
  NAND2X1 U206 ( .A(N38), .B(n48), .Y(n51) );
  OAI211X1 U207 ( .A0(n75), .A1(n48), .B0(n52), .C0(state), .Y(n133) );
  NAND2X1 U208 ( .A(N37), .B(n48), .Y(n52) );
  OAI211X1 U209 ( .A0(n76), .A1(n48), .B0(n53), .C0(state), .Y(n134) );
  NAND2X1 U210 ( .A(n76), .B(n48), .Y(n53) );
  OAI211X1 U211 ( .A0(n77), .A1(n48), .B0(n50), .C0(state), .Y(n135) );
  NAND2X1 U212 ( .A(N39), .B(n48), .Y(n50) );
  OAI211X1 U213 ( .A0(n5), .A1(n149), .B0(n16), .C0(state), .Y(n125) );
  NAND2X1 U214 ( .A(n149), .B(n8), .Y(n16) );
  OAI211X1 U215 ( .A0(n5), .A1(n148), .B0(n10), .C0(state), .Y(n123) );
  NAND2X1 U216 ( .A(N27), .B(n8), .Y(n10) );
  OAI211X1 U217 ( .A0(n5), .A1(n146), .B0(n14), .C0(state), .Y(n124) );
  NAND2X1 U218 ( .A(N25), .B(n8), .Y(n14) );
  OAI211X1 U219 ( .A0(n5), .A1(n147), .B0(n12), .C0(state), .Y(n126) );
  NAND2X1 U220 ( .A(N26), .B(n8), .Y(n12) );
  OAI211X1 U221 ( .A0(n5), .A1(n145), .B0(n7), .C0(state), .Y(n122) );
  NAND2X1 U222 ( .A(N28), .B(n8), .Y(n7) );
  ADDHXL U223 ( .A(tail[3]), .B(\r322/carry [3]), .CO(\r322/carry [4]), .S(N27) );
  ADDHXL U224 ( .A(head[3]), .B(\add_115/carry [3]), .CO(\add_115/carry [4]), 
        .S(N39) );
  ADDHXL U225 ( .A(count[4]), .B(\r323/carry [4]), .CO(\r323/carry [5]), .S(
        N33) );
  OAI21XL U226 ( .A0(go), .A1(n72), .B0(n2), .Y(n127) );
  NAND4X1 U227 ( .A(state), .B(n3), .C(n4), .D(go), .Y(n2) );
  INVX3 U228 ( .A(reset), .Y(n156) );
  OAI22XL U229 ( .A0(n76), .A1(n20), .B0(n65), .B1(n149), .Y(addr[0]) );
  OAI22XL U230 ( .A0(n75), .A1(n20), .B0(n65), .B1(n146), .Y(addr[1]) );
  OAI22XL U231 ( .A0(n74), .A1(n20), .B0(n65), .B1(n147), .Y(addr[2]) );
  OAI22XL U232 ( .A0(n77), .A1(n20), .B0(n65), .B1(n148), .Y(addr[3]) );
  OAI22XL U233 ( .A0(n73), .A1(n20), .B0(n65), .B1(n145), .Y(addr[4]) );
  NOR4X1 U234 ( .A(n47), .B(count[5]), .C(n81), .D(n83), .Y(almost_full) );
  OR3X2 U235 ( .A(n71), .B(n70), .C(n79), .Y(n47) );
  NOR3X1 U236 ( .A(count[5]), .B(n83), .C(n46), .Y(almost_empty) );
  CLKINVX1 U237 ( .A(cmd[17]), .Y(n159) );
  CLKINVX1 U238 ( .A(go), .Y(ready) );
  XOR2X1 U239 ( .A(\r322/carry [4]), .B(tail[4]), .Y(N28) );
  XOR2X1 U240 ( .A(\r323/carry [5]), .B(count[5]), .Y(N34) );
  XOR2X1 U241 ( .A(\add_115/carry [4]), .B(head[4]), .Y(N40) );
  NAND2BX1 U242 ( .AN(count[1]), .B(n83), .Y(n152) );
  OAI2BB1X1 U243 ( .A0N(count[0]), .A1N(count[1]), .B0(n152), .Y(N42) );
  NOR2X1 U244 ( .A(n152), .B(count[2]), .Y(n153) );
  AO21X1 U245 ( .A0(n152), .A1(count[2]), .B0(n153), .Y(N43) );
  NAND2X1 U246 ( .A(n153), .B(n70), .Y(n154) );
  OAI21XL U247 ( .A0(n153), .A1(n70), .B0(n154), .Y(N44) );
  XNOR2X1 U248 ( .A(count[4]), .B(n154), .Y(N45) );
  NOR2X1 U249 ( .A(count[4]), .B(n154), .Y(n155) );
  XOR2X1 U250 ( .A(count[5]), .B(n155), .Y(N46) );
endmodule

