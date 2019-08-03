package algorithms

import "testing"

func Test_Qsort(t *testing.T) {
	tables := []struct {
		input  []int
		expect []int
	}{
		{
			input:  []int{1, 2, 3, 4, 5, 6, 7, 8, 9},
			expect: []int{1, 2, 3, 4, 5, 6, 7, 8, 9},
		}, {
			input:  []int{9, 8, 7, 6, 5, 4, 3, 2, 1},
			expect: []int{1, 2, 3, 4, 5, 6, 7, 8, 9},
		}, {
			input:  []int{9, 9, 9, 6, 6, 6, 3, 2, 1},
			expect: []int{1, 2, 3, 6, 6, 6, 9, 9, 9},
		}, {
			input:  []int{97, 98, 99},
			expect: []int{97, 98, 99},
		},
	}
	for _, item := range tables {
		Qsort(item.input, 0, len(item.input))
		for i := 0; i < len(item.input); i++ {
			if item.input[i] != item.expect[i] {
				t.Errorf("expect %v, actual %v\n", item.expect, item.input)
			}
		}
	}
}
