package main

import (
    "fmt"
    "strconv"
)

func fizzBuzz(n int) []string {
    results := make([]string, n)
    next3 := 3
    next5 := 5
    for i := 0; i < n; i++ {
        ti := i + 1
        if ti == next3 && ti == next5 {
            next3 += 3
            next5 += 5
            results[i] = "FizzBuzz"
            continue
        }
        if ti == next3 {
            next3 += 3
            results[i] = "Fizz"
            continue
        }
        if ti == next5 {
            next5 += 5
            results[i] = "Buzz"
            continue
        }
        results[i] = strconv.FormatInt(int64(ti), 10)
    }

    return results
}

func main () {
    fmt.Println(fizzBuzz(31))
}