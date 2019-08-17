package leetcode

import (
	"testing"
)

func Test_remove_deplicates(t *testing.T) {
	tables := []struct {
		input    []int
		expect   int
		modified []int
	}{
		{
			input:    []int{1, 1, 1, 2, 2, 3},
			expect:   5,
			modified: []int{1, 1, 2, 2, 3},
		}, {
			input:    []int{0},
			expect:   1,
			modified: []int{0},
		}, {
			input:    []int{0, 0, 0, 1, 1, 1, 2, 3, 3},
			expect:   7,
			modified: []int{0, 0, 1, 1, 2, 3, 3},
		}, {
			input:    []int{0, 0, 1, 1, 1, 1, 2, 3, 3},
			expect:   7,
			modified: []int{0, 0, 1, 1, 2, 3, 3},
		},
	}
	for _, item := range tables {
		actual := removeDuplicates(item.input)
		if actual != item.expect {
			t.Errorf("expect %d actual %d\n", item.expect, actual)
		}
		for i := 0; i < len(item.modified); i++ {
			if item.modified[i] != item.input[i] {
				t.Errorf("expect %v, actual %v", item.modified, item.input)
			}
		}
	}
}
