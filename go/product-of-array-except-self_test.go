package leetcode

import "testing"

func Test_productExceptSelf(t *testing.T) {
	tables := []struct {
		input  []int
		expect []int
	}{
		{
			input:  []int{1, 2, 3, 4},
			expect: []int{24, 12, 8, 6},
		}, {
			input:  []int{0, 0},
			expect: []int{0, 0},
		}, {
			input:  []int{0, 1},
			expect: []int{1, 0},
		}, {
			input:  []int{1, 0},
			expect: []int{0, 1},
		}, {
			input:  []int{1, 0, 1},
			expect: []int{0, 1, 0},
		},
	}
	for _, item := range tables {
		actual := productExceptSelf(item.input)
		for i := 0; i < len(actual); i++ {
			if actual[i] != item.expect[i] {
				t.Errorf("expect: %v\n, actual: %v\n", item.expect, actual)
				break
			}
		}
	}
}
