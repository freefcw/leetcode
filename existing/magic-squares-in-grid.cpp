package main

import (
	"fmt"
)

func isMagic(grid [][]int, rowIndex int, colIndex int) bool {
	var isNumberExist [16]int
	referSum := grid[rowIndex][colIndex] + grid[rowIndex+1][colIndex+1] + grid[rowIndex+2][colIndex+2]
	referSum2 := grid[rowIndex+2][colIndex] + grid[rowIndex+1][colIndex+1] + grid[rowIndex][colIndex+2]

	if referSum != referSum2 {
		return false
	}
	for row := 0; row < 3; row++ {
		sum := 0
		for col := 0; col < 3; col++ {
			val := grid[rowIndex+row][colIndex+col]
			if isNumberExist[val] == 0 {
				isNumberExist[val] = 1
				sum += val
			} else {
				return false
			}
		}
		if sum != referSum {
			return false
		}
	}
	for col := 0; col < 3; col++ {
		sum := 0
		for row := 0; row < 3; row++ {
			sum += grid[rowIndex+row][colIndex+col]
		}
		if sum != referSum {
			return false
		}
	}
	for i := 1; i < 10; i++ {
		if isNumberExist[i] != 1 {
			return false
		}
	}

	return true
}

func numMagicSquaresInside(grid [][]int) int {
	totalMagic := 0
	for row := 0; row < len(grid)-2; row++ {
		for col := 0; col < len(grid[row])-2; col++ {
			if isMagic(grid, row, col) {
				totalMagic++
			}
		}
	}
	return totalMagic
}

func main() {
	grids := make([][]int, 3)
	grids[0] = []int{4, 3, 8, 4}
	grids[1] = []int{9, 5, 1, 9}
	grids[2] = []int{2, 7, 6, 2}

	fmt.Printf("%d\n", numMagicSquaresInside(grids))
	fmt.Printf("%t\n", isMagic(grids, 0, 0))

	fmt.Printf("hello world!\n")
}
