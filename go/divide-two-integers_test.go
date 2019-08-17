package leetcode

import (
	"testing"
)

func Test_findMaxLess(t *testing.T) {
	mids = []int{0, 3, 6, 12, 24, 48}
	tests := []struct {
		target int
		expect int
	}{
		{
			target: 25,
			expect: 4,
		}, {
			target: 3,
			expect: 1,
		}, {
			target: 49,
			expect: 5,
		},
	}
	for _, item := range tests {
		actual := findMaxLess(item.target, 0, len(mids))
		if actual != item.expect {
			t.Fatalf("%d, expect %d, actual %d\n", item.target, item.expect, actual)
		}
	}
}

func TestDivide(t *testing.T) {
	tests := []struct {
		a      int
		b      int
		expect int
	}{
		{
			a:      10,
			b:      3,
			expect: 3,
		}, {
			a:      1,
			b:      2,
			expect: 0,
		}, {
			a:      0,
			b:      1,
			expect: 0,
		}, {
			a:      1000,
			b:      3,
			expect: 333,
		}, {
			a:      7,
			b:      -3,
			expect: -2,
		}, {
			a:      7,
			b:      -2,
			expect: -3,
		}, {
			a:      -1,
			b:      -1,
			expect: 1,
		}, {
			a:      1,
			b:      -1,
			expect: -1,
		}, {
			a:      1<<31 - 1,
			b:      -1,
			expect: -2147483647,
		}, {
			a:      (-1) << 31,
			b:      -1,
			expect: 2147483647,
		},
	}

	for _, item := range tests {
		actual := divide(item.a, item.b)
		if item.expect != actual {
			t.Fatalf("%d/%d expect %d, actual %d", item.a, item.b, item.expect, actual)
		}
	}
}
