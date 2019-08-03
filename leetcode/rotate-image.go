package leetcode

func rotate(matrix [][]int) {
	sideLength := len(matrix)
	if sideLength == 0 {
		return
	}
	sideLength--
	for i := 0; i < sideLength; i++ {
		for j := i; j < sideLength-i; j++ {
			t := matrix[i][j]
			matrix[i][j] = matrix[sideLength-j][i]
			matrix[sideLength-j][i] = matrix[sideLength-i][sideLength-j]
			matrix[sideLength-i][sideLength-j] = matrix[j][sideLength-i]
			matrix[j][sideLength-i] = t
		}
	}
}
