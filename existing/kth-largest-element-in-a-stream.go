package main

import (
	"fmt"
	"sort"
)

// 二分查找版本，居然比堆排序的版本还快一些
type KthLargest struct {
	data []int
	size int
	pos  int
}

func Constructor(k int, nums []int) KthLargest {
	ks := KthLargest{}
	ks.data = make([]int, k)
	ks.pos = k
	ks.size = len(nums)
	if ks.size > k {
		ks.size = k
	}

	length := len(nums)
	sort.Ints(nums)
	for i := 0; i < ks.size; i++ {
		ks.data[i] = nums[length-i-1]
	}
	return ks
}

func binarySearch(nums []int, target int, low, high int) int {
	if low >= high {
		return high
	}
	// fmt.Printf("bs: %d %d %d\n", target, nums[low], nums[high])
	if low+1 == high && target <= nums[low] && target >= nums[high] {
		return high
	}
	mid := (low + high) / 2
	if nums[mid] == target {
		return mid
	}
	if target <= nums[mid] {
		return binarySearch(nums, target, mid, high)
	}
	if target >= nums[mid] {
		return binarySearch(nums, target, low, mid)
	}
	return -1
}

func (this *KthLargest) Add(val int) int {
	// fmt.Printf("%v %d\n", this.data, val)
	if this.size == this.pos && val < this.data[this.size-1] {
		return this.data[this.pos-1]
	}
	if this.size < this.pos {
		this.data[this.pos-1] = val
		this.size++
	}
	pos := -1
	if val >= this.data[0] {
		pos = 0
	}
	if val < this.data[this.pos-1] {
		pos = this.pos
	}
	if pos == -1 {
		pos = binarySearch(this.data, val, 0, this.pos-1)
		// fmt.Printf("pos: %d %d\n", val, pos)
	}

	if pos > -1 && pos < this.pos {
		for j := this.pos - 1; j > pos; j-- {
			this.data[j] = this.data[j-1]
		}
		this.data[pos] = val
	}
	// fmt.Printf("%v", this.data)
	return this.data[this.pos-1]
}
func main() {
	obj := Constructor(1, []int{})
	fmt.Println(obj.Add(-3))
	fmt.Println(obj.Add(-2))
	fmt.Println(obj.Add(-2))
	fmt.Println(obj.Add(0))
	fmt.Println(obj.Add(4))
}
