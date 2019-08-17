package leetcode

// https://leetcode.com/problems/number-of-islands/

var (
	total  int
	width  int
	height int
)

const (
	unVisited = 0
	visited   = 1
)

var visitedMark [][]int

func numIslands(grid [][]byte) int {
	height = len(grid)
	if height == 0 {
		return 0
	}
	width = len(grid[0])
	visitedMark = make([][]int, height)
	for i := 0; i < height; i++ {
		visitedMark[i] = make([]int, width)
	}
	total = 0

	for i := 0; i < height; i++ {
		for k := 0; k < width; k++ {
			if grid[i][k] == '1' && visitedMark[i][k] == unVisited {
				dfs(grid, i, k)
				total++
			}
		}
	}

	return total
}

func dfs(grid [][]byte, x, y int) {
	if x == height || y == width || x < 0 || y < 0 {
		return
	}
	if visitedMark[x][y] == visited {
		return
	}
	visitedMark[x][y] = visited
	if grid[x][y] == '0' {
		return
	}

	dfs(grid, x-1, y)
	dfs(grid, x, y-1)
	dfs(grid, x+1, y)
	dfs(grid, x, y+1)
}
