package leetcode

import (
	"bytes"
	"fmt"
	"testing"
)

func pairsArray(nums [][]int) string {
	var buff bytes.Buffer

	fmt.Fprintf(&buff, "[")
	for i := 0; i < len(nums); i++ {
		fmt.Fprintf(&buff, "[%d,%d]", nums[i][0], nums[i][1])
	}
	fmt.Fprintf(&buff, "]")

	return buff.String()
}

func Test_pairs_array(t *testing.T) {
	data := [][]int{
		[]int{2, 5},
		[]int{6, 7},
		[]int{8, 9},
	}
	ret := pairsArray(data)
	expect := "[[2,5][6,7][8,9]]"
	if ret != expect {
		t.Errorf("expect: %s, actual: %s", expect, ret)
	}
}
func Test_insert_before(t *testing.T) {
	data := [][]int{
		[]int{2, 5},
		[]int{6, 7},
		[]int{8, 9},
	}
	newInterval := []int{0, 1}

	result := insert(data, newInterval)
	actual := pairsArray(result)
	expect := "[[0,1][2,5][6,7][8,9]]"
	if actual != expect {
		t.Errorf("expect: %s, actual: %s", expect, actual)
	}
}

func Test_insert_tail(t *testing.T) {
	data := [][]int{
		[]int{2, 5},
		[]int{6, 7},
		[]int{8, 9},
	}
	newInterval := []int{10, 11}

	result := insert(data, newInterval)
	actual := pairsArray(result)
	expect := "[[2,5][6,7][8,9][10,11]]"
	if actual != expect {
		t.Errorf("expect: %s, actual: %s", expect, actual)
	}
}

func Test_insert_mid(t *testing.T) {
	data := [][]int{
		[]int{2, 5},
		[]int{8, 9},
	}
	newInterval := []int{6, 7}

	result := insert(data, newInterval)
	actual := pairsArray(result)
	expect := "[[2,5][6,7][8,9]]"
	if actual != expect {
		t.Errorf("expect: %s, actual: %s", expect, actual)
	}
}

func Test_insert_merge_mid(t *testing.T) {
	data := [][]int{
		[]int{1, 3},
		[]int{6, 9},
	}
	newInterval := []int{2, 5}

	result := insert(data, newInterval)
	actual := pairsArray(result)
	expect := "[[1,5][6,9]]"
	if actual != expect {
		t.Errorf("expect: %s, actual: %s", expect, actual)
	}
}

func Test_insert_merge_before(t *testing.T) {
	data := [][]int{
		[]int{1, 3},
		[]int{6, 9},
	}
	newInterval := []int{0, 2}

	result := insert(data, newInterval)
	actual := pairsArray(result)
	expect := "[[0,3][6,9]]"
	if actual != expect {
		t.Errorf("expect: %s, actual: %s", expect, actual)
	}
}

func Test_insert_merge_after(t *testing.T) {
	data := [][]int{
		[]int{1, 3},
		[]int{6, 9},
	}
	newInterval := []int{8, 12}

	result := insert(data, newInterval)
	actual := pairsArray(result)
	expect := "[[1,3][6,12]]"
	if actual != expect {
		t.Errorf("expect: %s, actual: %s", expect, actual)
	}
}

func Test_adjacent_none(t *testing.T) {
	a := []int{1, 2}
	b := []int{3, 4}
	if isAdjacent(a, b) == true {
		t.Errorf("%v should not adjacent %v", a, b)
	}
}
func Test_adjacent_before(t *testing.T) {
	a := []int{1, 3}
	b := []int{3, 4}
	if isAdjacent(a, b) == false {
		t.Errorf("%v should adjacent %v", a, b)
	}
}
func Test_adjacent_after(t *testing.T) {
	a := []int{2, 5}
	b := []int{3, 6}
	if isAdjacent(a, b) == false {
		t.Errorf("%v should adjacent %v", a, b)
	}
}
func Test_adjacent_inner(t *testing.T) {
	a := []int{5, 8}
	b := []int{3, 16}
	if isAdjacent(a, b) == false {
		t.Errorf("%v should adjacent %v", a, b)
	}
}
