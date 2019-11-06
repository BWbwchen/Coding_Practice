#!/usr/bin/python3

row_1 = 8
col_1 = 8
row_2 = 8
col_2 = 8


for a_row in range(row_1) :
    for a_col in range(col_1) :
        for b_row in range(row_2) :
            for b_col in range(col_2) :
                string_1 = chr(a_row+97) + chr(a_col+49)
                string_2 = chr(b_row+97) + chr(b_col+49)
                print (string_1 + " " + string_2)

