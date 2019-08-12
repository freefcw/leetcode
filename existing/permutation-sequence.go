package main

import (
	"fmt"
	"bytes"
)

var nn []int
var nums []int

func initial(n int) {
	nn = make([]int, n + 1)
	nums = make([]int, n + 1)
	nn[0] = 1
	for i := 1; i <= n; i++ {
		nn[i] = nn[i - 1] * i
		nums[i] = i
	}
	// fmt.Println(nn)
}

func getPermutation(n int, k int) string {
	initial(n)
	dfs(1, n, k - 1)
	var buff bytes.Buffer
	for i := 1; i <= n; i++ {
		fmt.Fprintf(&buff, "%d", nums[i])
	}
	
	return buff.String()
}

func dfs(level, n, k int) {
	if n == 1 {
		return
	}
	s := 0
	left := k % nn[n - 1]
	if k >= nn[n - 1] {
		s = k / nn[n - 1]
	}
	// fmt.Printf("nn[%d]: %d s => %d\n",n-1, nn[n-1], s);
	// fmt.Printf("level %d, k %d\n", level, k)
	
	if s > 0 && level + s < len(nums){
		t := nums[level + s]
		for i := level + s; i > level; i-- {
			nums[i] = nums[i-1]
		}
		nums[level] = t
	}

	// fmt.Println(nums)
	dfs(level + 1, n - 1, left)
}


func main() {
	for i := 1; i < 4 * 3 * 2 + 1; i++ {

		fmt.Printf("%02d %s\n", i, getPermutation(4, i))
	}
	

	fmt.Printf("hello world!\n")
}
