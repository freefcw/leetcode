package leetcode

import "testing"

func Test_numComponents(t *testing.T) {
	tests := []struct {
		input  []int
		g      []int
		expect int
	}{
		{
			input:  []int{0, 1, 2, 3},
			g:      []int{0, 1, 3},
			expect: 2,
		}, {
			input:  []int{0, 1, 2, 3, 4},
			g:      []int{0, 3, 1, 4},
			expect: 2,
		}, {
			input:  []int{0, 1, 2, 3, 4, 5, 6, 7},
			g:      []int{0, 5, 1, 4, 7},
			expect: 3,
		},
	}

	for _, item := range tests {
		input := createLinkedList(item.input)
		actual := numComponents(input, item.g)
		if actual != item.expect {
			t.Fatalf("%v expect %d, actual %d\n", item.input, item.expect, actual)
		}
	}
}
