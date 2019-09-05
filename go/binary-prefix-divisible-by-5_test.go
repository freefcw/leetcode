package leetcode

import "testing"

func TestPrefixesDivBy5(t *testing.T) {
	tests := []struct {
		input  []int
		expect []bool
	}{
		{
			input:  []int{0},
			expect: []bool{true},
		}, {
			input:  []int{1},
			expect: []bool{false},
		}, {
			input:  []int{0, 1, 1},
			expect: []bool{true, false, false},
		}, {
			input:  []int{1, 1, 1},
			expect: []bool{false, false, false},
		}, {
			input:  []int{0, 1, 1, 1, 1, 1},
			expect: []bool{true, false, false, false, true, false},
		}, {
			input:  []int{1, 1, 1, 0, 1},
			expect: []bool{false, false, false, false, false},
		},
	}

	for i, item := range tests {
		actual := prefixesDivBy5(item.input)
		if !boolsEqual(item.expect, actual) {
			t.Errorf("%d\nexpect %v,\nactual %v", i, item.expect, actual)
		}
	}
}
