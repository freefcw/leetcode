package leetcode

// https://leetcode.com/problems/island-perimeter

func islandPerimeter(grid [][]int) int {
	perimeter := 0
	iRows := len(grid)
	if iRows == 0 {
		return 0
	}
	iColumns := len(grid[0])
	if iRows == 0 {
		return 0
	}
	for i := 0; i < iRows; i++ {
		for j := 0; j < iColumns; j++ {
			if grid[i][j] == 0 {
				continue
			}
			perimeter += 4
			if i > 0 && grid[i-1][j] == 1 {
				perimeter--
			}
			if j > 0 && grid[i][j-1] == 1 {
				perimeter--
			}
			if i+1 < iRows && grid[i+1][j] == 1 {
				perimeter--
			}
			if j+1 < iColumns && grid[i][j+1] == 1 {
				perimeter--
			}
		}
	}

	return perimeter
}
