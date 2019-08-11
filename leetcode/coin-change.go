package leetcode

import "sort"

func coinChange(coins []int, amount int) int {
	sort.Ints(coins)
	if amount == 0 {
		return 0
	}
	if len(coins) == 0 || coins[0] > amount {
		return -1
	}
	results := make([]int, amount+1)

	for i := 1; i <= amount; i++ {
		for _, coin := range coins {
			if coin > i {
				break
			}
			if coin == i {
				results[coin] = 1
				break
			}
			// coin < i
			// left no solution
			if results[i-coin] == 0 {
				continue
			}
			t := results[coin] + results[i-coin]
			// if solution not exist or less than prevous
			if results[i] == 0 || t < results[i] {
				results[i] = t
			}
		}
	}

	if results[amount] == 0 {
		return -1
	}
	return results[amount]
}
