package leetcode

import "testing"

func Test_findMaxForm(t *testing.T) {
	tests := []struct {
		input  []string
		m      int
		n      int
		expect int
	}{
		{
			input:  []string{"10", "0001", "111001", "1", "0", "11000"},
			m:      5,
			n:      3,
			expect: 4,
		}, {
			input:  []string{"10", "0001", "111001", "1", "0"},
			m:      0,
			n:      1,
			expect: 1,
		}, {
			input:  []string{"10", "0001", "111001", "1", "0"},
			m:      1,
			n:      1,
			expect: 2,
		}, {
			input:  []string{"10", "0", "1"},
			m:      1,
			n:      1,
			expect: 2,
		}, {
			input:  []string{"10", "0001", "111001", "1", "0"},
			m:      3,
			n:      4,
			expect: 3,
		},
	}

	for i, item := range tests {
		actual := findMaxForm(item.input, item.m, item.n)
		if actual != item.expect {
			t.Fatalf("%d expect %d, actual %d", i, item.expect, actual)
		}
	}
}
