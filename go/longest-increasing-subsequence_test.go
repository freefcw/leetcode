package leetcode

import "testing"

func Test_LengthOfLIS(t *testing.T) {
	tests := []struct {
		input  []int
		expect int
	}{
		{
			input:  []int{10, 9, 2, 5, 3, 7, 101, 18},
			expect: 4,
		}, {
			input:  []int{2, 2, 2, 2, 2, 2, 2, 2},
			expect: 1,
		}, {
			input:  []int{1, 2},
			expect: 2,
		},
	}
	for _, item := range tests {
		actual := lengthOfLIS(item.input)
		if actual != item.expect {
			t.Fatalf("%v expect %d, actual %d\n", item.input, item.expect, actual)
		}
	}
}
