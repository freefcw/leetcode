package leetcode

import "testing"

func Test_CoinChange(t *testing.T) {
	tests := []struct {
		coins  []int
		amount int
		expect int
	}{
		{
			coins:  []int{1, 2, 5},
			amount: 11,
			expect: 3,
		}, {
			coins:  []int{5, 2, 1},
			amount: 13,
			expect: 4,
		}, {
			coins:  []int{2},
			amount: 3,
			expect: -1,
		}, {
			coins:  []int{2},
			amount: 5,
			expect: -1,
		}, {
			coins:  []int{2},
			amount: 6,
			expect: 3,
		}, {
			coins:  []int{1},
			amount: 0,
			expect: 0,
		}, {
			coins:  []int{2},
			amount: 1,
			expect: -1,
		},
	}

	for i, item := range tests {
		actual := coinChange(item.coins, item.amount)
		if actual != item.expect {
			t.Fatalf("%d expect %d, actual %d\n", i, item.expect, actual)
		}
	}
}
