package main

import (
	"fmt"
	"sort"
)

type Maximum3 struct {
	maximum1 int
	maximum2 int
	maximum3 int
	minimum1 int
	minimum2 int
}

func (this *Maximum3) init() {
	this.maximum1 = -1001
	this.maximum2 = -1001
	this.maximum3 = -1001

	this.minimum1 = 1001
	this.minimum2 = 1001
}

func (this *Maximum3) Result() int {
	max3 := this.maximum1 * this.maximum2 * this.maximum3
	min3 := this.maximum1 * this.minimum1 * this.minimum2

	if max3 > min3 {
		return max3
	}
	return min3
}

func (this *Maximum3) AddMax(v int) {
	if v > this.maximum1 {
		this.maximum3 = this.maximum2
		this.maximum2 = this.maximum1
		this.maximum1 = v
		return
	}
	if v > this.maximum2 {
		this.maximum3 = this.maximum2
		this.maximum2 = v
		return
	}
	if v > this.maximum3 {
		this.maximum3 = v
		return
	}
}

func (this *Maximum3) Add(v int) {
	this.AddMax(v)
	this.AddMin(v)
}

func (this *Maximum3) AddMin(v int) {
	if v < this.minimum1 {
		this.minimum2 = this.minimum1
		this.minimum1 = v
		return
	}
	if v < this.minimum2 {
		this.minimum2 = v
		return
	}
}

func maximumProduct(nums []int) int {
	obj := Maximum3{}
	obj.init()
	for i := 0; i < len(nums); i++ {
		obj.Add(nums[i])
	}
	return obj.Result()
}

func maximumProductSort(nums []int) int {
	sort.Ints(nums)
	size := len(nums)
	maximum1 := nums[0] * nums[1] * nums[size-1]
	maximum2 := nums[size-1] * nums[size-2] * nums[size-3]

	if maximum1 > maximum2 {
		return maximum1
	}
	return maximum2
}

func main() {

	fmt.Printf("hello world!\n")
}
