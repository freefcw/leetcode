package leetcode

import "testing"

func Test_exist(t *testing.T) {
	exampleBoard := [][]byte{
		[]byte{'A', 'B', 'C', 'E'},
		[]byte{'S', 'F', 'C', 'S'},
		[]byte{'A', 'D', 'E', 'E'},
	}
	tests := []struct {
		board  [][]byte
		word   string
		expect bool
	}{
		{
			board:  exampleBoard,
			word:   "ABCCED",
			expect: true,
		}, {
			board:  exampleBoard,
			word:   "SEE",
			expect: true,
		}, {
			board:  exampleBoard,
			word:   "ABCB",
			expect: false,
		}, {
			board: [][]byte{
				[]byte{'a', 'b'},
				[]byte{'c', 'd'},
			},
			word:   "cdba",
			expect: true,
		}, {
			board:  [][]byte{},
			word:   "ABCB",
			expect: false,
		},
	}

	for _, item := range tests {
		actual := exist(item.board, item.word)
		if actual != item.expect {
			t.Fatalf("find %s expect %t, actual %t", item.word, item.expect, actual)
		}
	}
}
