package leetcode

func nthSuperUglyNumber(n int, primes []int) int {
	nums := make([]int, 1, n+1)
	nums[0] = 1
	primePos := make([]int, len(primes))

	i := 0
	for i < n {
		for j := 0; j < len(primes); j++ {
			if primes[j]*nums[primePos[j]] <= nums[i] {
				primePos[j]++
			}
		}
		min := maxInt32
		for j := 0; j < len(primes); j++ {
			a := primes[j] * nums[primePos[j]]
			if a < min {
				min = a
			}
		}
		nums = append(nums, min)
		i++
	}
	return nums[n-1]
}
