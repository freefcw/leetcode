package leetcode

// https://leetcode.com/problems/valid-sudoku/

func isValidSudokuRow(row []byte) bool {
	var exist [10]int
	for i := 0; i < 9; i++ {
		k := row[i]
		if k == '.' {
			continue
		}
		r := k - '1'
		if exist[r] == 1 {
			return false
		}
		exist[r] = 1
	}
	return true
}

func isValidSudokuColumn(board [][]byte, column int) bool {
	var exist [10]int
	for i := 0; i < 9; i++ {
		k := board[i][column]
		if k == '.' {
			continue
		}
		r := k - '0'
		if exist[r] == 1 {
			return false
		}
		exist[r] = 1
	}
	return true
}
func isValidSudokuGrid9(board [][]byte, top, left int) bool {
	var exist [10]int
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			k := board[top+i][left+j]
			if k == '.' {
				continue
			}
			r := k - '0'
			if exist[r] == 1 {
				return false
			}
			exist[r] = 1
		}
	}
	return true
}

func isValidSudoku(board [][]byte) bool {
	for i := 0; i < 9; i++ {
		if !isValidSudokuRow(board[i]) {
			return false
		}
	}
	for i := 0; i < 9; i++ {
		if !isValidSudokuColumn(board, i) {
			return false
		}
	}
	for _, i := range []int{0, 3, 6} {
		for _, j := range []int{0, 3, 6} {
			if !isValidSudokuGrid9(board, i, j) {
				return false
			}
		}
	}
	return true
}
