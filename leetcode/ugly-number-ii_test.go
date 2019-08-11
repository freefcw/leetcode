package leetcode

import "testing"

func Test_nthUglyNumber(t *testing.T) {
	tests := []struct {
		n      int
		expect int
	}{
		{
			n:      10,
			expect: 12,
		},
	}

	for i, item := range tests {
		actual := nthUglyNumber(item.n)
		if actual != item.expect {
			t.Fatalf("%d, expect %d, actual %d\n", i, item.expect, actual)
		}
	}
}
