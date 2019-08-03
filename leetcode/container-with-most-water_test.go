package leetcode

import "testing"

func Test_maxArea(t *testing.T) {
	input := []int{1, 8, 6, 2, 5, 4, 8, 3, 7}
	result := maxArea(input)
	if result != 49 {
		t.Errorf("expect: 49, actual: %d", result)
	}
}

func Test_maxArea_low(t *testing.T) {
	input := []int{1, 5, 6, 2, 5, 4, 8, 3, 7}
	result := maxArea(input)
	if result != 36 {
		t.Errorf("expect: 49, actual: %d", result)
	}
}

func Test_maxArea_top(t *testing.T) {
	input := []int{1, 5, 26, 2, 165, 4, 8, 3, 7}
	result := maxArea(input)
	if result != 52 {
		t.Errorf("expect: 49, actual: %d", result)
	}
}

func Test_maxArea_relate(t *testing.T) {
	input := []int{1, 5, 26, 222, 165, 4, 8, 3, 7}
	result := maxArea(input)
	if result != 165 {
		t.Errorf("expect: 49, actual: %d", result)
	}
}
