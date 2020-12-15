package main

import (
    "fmt";
)


func main () {
    var n int
    fmt.Scan(&n)
    for n > 0 {
        n--
        var x int
        fmt.Scan(&x)
        c := 2
        for c <= x {
            fmt.Print(c, " ")
            c++
        }
        fmt.Println(1)
    }
}
