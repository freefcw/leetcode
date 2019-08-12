package main

import (
	"fmt"
)

var theMatrix [][]int
var target int

func binarySearchRow(low, high int) int {
	mid := (low + high) / 2
	// fmt.Printf("ROW mid: %d, low: %d, high: %d\n", mid, low, high)
	if low >= high {
		return low
	}
	if target < theMatrix[mid][0] {
		if mid == 0 {
			return 0
		}
		return binarySearchRow(low, mid - 1)
	}
	if target < theMatrix[mid + 1][0] {
		if mid + 1 > len(theMatrix) {
			return mid
		}
		return mid
	}
	
	return binarySearchRow(mid + 1, high)
}

func binarySearch(nums []int, low, high int) bool {
	mid := (low + high) / 2
	// fmt.Printf("mid: %d, low: %d, high: %d\n", mid, low, high)
	if target == nums[mid] {
		return true
	}
	if low >= high {
		return false
	}
	if target > nums[mid] {
		return binarySearch(nums, mid + 1, high)
	}
	return binarySearch(nums, low, mid - 1)
}

func searchMatrix(matrix [][]int, a int) bool {
    if len(matrix) == 0 || len(matrix[0]) == 0 {
		return false
	}
	theMatrix = matrix
	target = a
	row := binarySearchRow(0, len(matrix) - 1)
	if a < matrix[row][0] {
		return false
	}
	return binarySearch(matrix[row], 0, len(matrix[row]) - 1)
}

func main() {

	// a := []int{4, 3, 2, 7, 8, 2, 3, 1}
	theMatrix = [][]int{
		{1,   3,  5,  7},
  		{10, 11, 16, 20},
  		{23, 30, 34, 50},
	}
	theMatrix = [][]int{
		{1},
		{3},
	}

	// target = 9
	fmt.Println(searchMatrix(theMatrix, 0))

	fmt.Printf("hello world!\n")
}
