package leetcode

import (
	"math"
	"testing"
)

func TestMyPow(t *testing.T) {
	tests := []struct {
		x      float64
		n      int
		expect float64
	}{
		{
			x:      2.00000,
			n:      10,
			expect: 1024.00000,
		}, {
			x:      2.10000,
			n:      3,
			expect: 9.26100,
		}, {
			x:      2.00000,
			n:      -2,
			expect: 0.25000,
		}, {
			x:      2.00000,
			n:      0,
			expect: 1.00000,
		}, {
			x:      100.00000,
			n:      1 << 31,
			expect: math.Inf(1),
		}, {
			x:      100.00000,
			n:      -1 << 31,
			expect: 0,
		}, {
			x:      1.00000,
			n:      -1 << 31,
			expect: 1,
		}, {
			x:      -1.00000,
			n:      -1 << 31,
			expect: 1,
		}, {
			x:      -1.00000,
			n:      -1<<31 + 1,
			expect: -1,
		}, {
			x:      -1.00000,
			n:      1,
			expect: -1,
		}, {
			x:      -2.00000,
			n:      2,
			expect: 4,
		},
	}
	for i, item := range tests {
		actual := myPow(item.x, item.n)
		if math.Abs(actual-item.expect) > 0.00001 {
			t.Fatalf("%d expect %f, actual %f", i, item.expect, actual)
		}
	}
}
