package others

func division5(k int) int {
	count := 0
	for {
		if k%5 != 0 {
			break
		}
		count++
		k = k / 5
	}

	return count
}

func numberOfZeros(n int) int {
	cached := make([]int, n+1)

	sum := 0
	for i := 1; i <= n; i++ {
		count := division5(i)
		cached[i] = count
		cached[i] += cached[i-1]
		sum += cached[i]
	}

	return sum
}
