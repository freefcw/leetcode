package main

import (
	"fmt"
)

var theMatrix [][]int
var target int

func search(x0, y0, x1, y1 int) bool {
	// fmt.Printf("%d %d %d %d\n", x0, y0, x1, y1)
	midx := (x0 + x1) / 2
	midy := (y0 + y1) / 2
	if x0 >= len(theMatrix) || x1 >= len(theMatrix) || y0 >= len(theMatrix[0]) || y1 >= len(theMatrix[0]) {
		return false
	}
	if x0 < 0 || x1 < 0 || y0 < 0 || y1 < 0 {
		return false
	}

	if target == theMatrix[midx][midy] {
		return true
	}
	if x1-x0 <= 1 && y1-y0 <= 1 {
		if theMatrix[x0][y0] == target {
			return true
		}
		if theMatrix[x1][y1] == target {
			return true
		}
		if theMatrix[x1][y0] == target {
			return true
		}
		if theMatrix[x0][y1] == target {
			return true
		}
		return false
	}

	found := false
	if target <= theMatrix[midx][midy] {
		found = search(x0, y0, midx, midy)
		if found {
			return true
		}
		found = search(midx+1, y0, x1, midy-1)
		if found {
			return true
		}
		found = search(x0, midy+1, midx-1, y1)
		if found {
			return true
		}
		return false
	}

	found = search(midx+1, y0, x1, midy-1)
	if found {
		return true
	}
	found = search(x0, midy+1, midx-1, y1)
	if found {
		return true
	}

	return search(midx, midy, x1, y1)
}

func searchMatrix(matrix [][]int, a int) bool {
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return false
	}
	// if len(matrix) == 1 && len(matrix[0]) > 0 &&
	theMatrix = matrix
	target = a
	return search(0, 0, len(matrix)-1, len(matrix[0])-1)
}

func main() {

	// a := []int{4, 3, 2, 7, 8, 2, 3, 1}
	// theMatrix := [][]int{
	// 	{1, 3, 5, 7},
	// 	{10, 11, 16, 20},
	// 	{23, 30, 34, 50},
	// }
	// theMatrix := [][]int{
	// 	{1, 2, 3, 4, 5},
	// 	{6, 7, 8, 9, 10},
	// 	{11, 12, 13, 14, 15},
	// 	{16, 17, 18, 19, 20},
	// 	{21, 22, 23, 24, 25},
	// }

	theMatrix := [][]int{
		{1, 3, 5},
	}
	fmt.Println(searchMatrix(theMatrix, -1))

	fmt.Printf("hello world!\n")
}
