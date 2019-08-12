package main

import (
    "fmt"
)

func sortArrayByParityII2(A []int) []int {
    lastOdd := 1
    lastEven := 0
    for i := 0; i < len(A); i++ {
        // fmt.Printf("%d %d %d\n", i, lastOdd, lastEven)
        // fmt.Println(A)
        if A[i] & 1 == 1 && i & 1 != 1 {
            for A[lastOdd] & 1 == 1 {
                lastOdd += 2
                if lastOdd > len(A) {
                    return A
                }
            }
            A[lastOdd], A[i] = A[i], A[lastOdd]
        }
        if A[i] & 1 == 0 && i & 1 != 0 {
            for A[lastEven] & 1 == 0 {
                lastEven += 2
                if lastEven > len(A) {
                    return A
                }
            }
            A[lastEven], A[i] = A[i], A[lastEven]
        }
    }
    return A
}

func sortArrayByParityII(A []int) []int {
    newA := make([]int, len(A))
    lastOdd := 1
    lastEven := 0
    for i := 0; i < len(A); i++ {
        if A[i] & 1 == 1 {
            newA[lastOdd] = A[i]
            lastOdd += 2
        } else {
            newA[lastEven] = A[i]
            lastEven += 2
        }
    }
    return newA
}

func main () {
    arr := []int{888,505,627,846}
    fmt.Println(sortArrayByParityII(arr))
}