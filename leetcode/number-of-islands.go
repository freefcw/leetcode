package leetcode

// https://leetcode.com/problems/number-of-islands/

var (
	total  int
	width  int
	height int
)

func numIslands(grid [][]byte) int {
	height = len(grid)
	if height == 0 {
		return 0
	}
	width = len(grid[0])
	total = 0
	return total
}

func dfs(grid [][]int, x, y int) {

}
