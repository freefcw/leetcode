package leetcode

import "testing"

func Test_heightChecker(t *testing.T) {
	tests := []struct {
		input  []int
		expect int
	}{
		{
			input:  []int{1, 1, 4, 2, 1, 3},
			expect: 3,
		}, {
			input:  []int{1, 1, 4, 2, 3, 3},
			expect: 3,
		}, {
			input:  []int{1, 1, 4, 2, 3, 1},
			expect: 2,
		},
	}

	for _, item := range tests {
		actual := heightChecker(item.input)
		if actual != item.expect {
			t.Fatalf("%v expect %d, actual %d", item.input, item.expect, actual)
		}
	}
}
