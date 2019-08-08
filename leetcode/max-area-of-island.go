package leetcode

var (
	rows        int
	columns     int
	mVisited    [][]bool
	currentArea int
	maxArea1    int
)

func maxAreaOfIsland(grid [][]int) int {
	rows = len(grid)
	if rows == 0 {
		return 0
	}
	columns = len(grid[0])
	mVisited = make([][]bool, rows)
	for i := 0; i < rows; i++ {
		mVisited[i] = make([]bool, columns)
	}

	maxArea1 = 0
	currentArea = 0

	for i := 0; i < rows; i++ {
		for j := 0; j < columns; j++ {
			if !mVisited[i][j] && grid[i][j] == 1 {
				currentArea = 0
				mdfs(grid, i, j)
			}
		}
	}

	return maxArea1
}

func mdfs(grid [][]int, i, j int) {
	if mVisited[i][j] || grid[i][j] == 0 {
		return
	}
	mVisited[i][j] = true
	currentArea++
	if currentArea > maxArea1 {
		maxArea1 = currentArea
	}
	if i > 0 {
		mdfs(grid, i-1, j)
	}
	if j > 0 {
		mdfs(grid, i, j-1)
	}
	if i < rows-1 {
		mdfs(grid, i+1, j)
	}
	if j < columns-1 {
		mdfs(grid, i, j+1)
	}
}
