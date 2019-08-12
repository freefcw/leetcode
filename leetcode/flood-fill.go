package leetcode

// https://leetcode.com/problems/flood-fill/

var (
	oldColor     int
	floodRows    int
	floodColumns int
	floodVisited [][]bool
)

func floodDFS(image [][]int, i int, j int, newColor int) {
	if image[i][j] != oldColor {
		return
	}
	image[i][j] = newColor
	floodVisited[i][j] = true
	if i > 0 && !floodVisited[i-1][j] {
		floodDFS(image, i-1, j, newColor)
	}
	if j > 0 && !floodVisited[i][j-1] {
		floodDFS(image, i, j-1, newColor)
	}
	if i+1 < floodRows && !floodVisited[i+1][j] {
		floodDFS(image, i+1, j, newColor)
	}
	if j+1 < floodColumns && !floodVisited[i][j+1] {
		floodDFS(image, i, j+1, newColor)
	}
	return
}

func floodFill(image [][]int, sr int, sc int, newColor int) [][]int {
	floodRows = len(image)
	if len(image) == 0 {
		return image
	}
	floodColumns = len(image[0])
	oldColor = image[sr][sc]
	if newColor == oldColor {
		return image
	}
	floodVisited = make([][]bool, floodRows)
	for i := 0; i < floodRows; i++ {
		floodVisited[i] = make([]bool, floodColumns)
	}
	floodDFS(image, sr, sc, newColor)

	return image
}
