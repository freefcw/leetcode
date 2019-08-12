package main

import (
    "fmt"
)

func duplicateZeros(arr []int)  {
    length := len(arr)
    zerosCount := 0
    i :=0
    for ; i + zerosCount < length; i++ {
        if arr[i] == 0 {
            zerosCount++
        }
    }
    if zerosCount == 0 {
        return
    }
    singleZero := i + zerosCount - length
    i--
    backlookup := i
    pos := length - 1
    for pos >= 0 && backlookup >= 0 {
        // fmt.Printf("%d %d %v\n", pos, backlookup, arr)
        arr[pos] = arr[backlookup]
        if (arr[backlookup] == 0 && pos >= 0) {
            if singleZero == 0 {
                pos--
                arr[pos] = 0
            } else {
                singleZero--
            }
        }
        backlookup--
        pos--
    }
}

func main () {
    // arr := []int{1,0,2,3,0,4,0,5,0}
    // arr := []int{1,5,2,0,6,8,0,6,0}
    arr := []int{9,9,9,4,8,0,0,3,7,2,0,0,0,0,9,1,0,0,1,1,0,5,6,3,1,6,0,0,2,3,4,7,0,3,9,3,6,5,8,9,1,1,3,2,0,0,7,3,3,0,5,7,0,8,1,9,6,3,0,8,8,8,8,0,0,5,0,0,0,3,7,7,7,7,5,1,0,0,8,0,0}
    duplicateZeros(arr)
    fmt.Println(arr)
}