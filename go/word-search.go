package leetcode

var (
	bRows     int
	bColumns  int
	theWord   string
	wordIndex int
	bVisited  [][]bool
)

func exist(board [][]byte, word string) bool {
	bRows = len(board)
	if bRows == 0 {
		return false
	}
	bColumns = len(board[0])
	theWord = word

	for i := 0; i < bRows; i++ {
		for j := 0; j < bColumns; j++ {
			if board[i][j] == word[0] {
				wordIndex = 0
				resetVisited()
				if findWord(board, i, j) {
					return true
				}
			}
		}
	}
	return false
}

func resetVisited() {
	bVisited = make([][]bool, bRows)
	for i := 0; i < bRows; i++ {
		bVisited[i] = make([]bool, bColumns)
	}
}

func findWord(board [][]byte, i, j int) bool {
	if bVisited[i][j] {
		return false
	}
	if theWord[wordIndex] != board[i][j] {
		return false
	}
	bVisited[i][j] = true
	if wordIndex == len(theWord)-1 {
		// fmt.Printf("%v %d %d %d\n", theWord, wordIndex, i, j)
		return true
	}
	wordIndex++
	if i > 0 {
		if findWord(board, i-1, j) {
			return true
		}
	}
	if j > 0 {
		if findWord(board, i, j-1) {
			return true
		}
	}

	if i+1 < bRows {
		if findWord(board, i+1, j) {
			return true
		}
	}
	if j+1 < bColumns {
		if findWord(board, i, j+1) {
			return true
		}
	}
	wordIndex--
	bVisited[i][j] = false
	return false
}
