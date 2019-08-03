package leetcode

import "testing"

func Test_merge_none(t *testing.T) {
	data := [][]int{
		[]int{1, 2},
		[]int{3, 6},
		[]int{8, 10},
		[]int{15, 18},
	}
	result := merge(data)
	actual := pairs_array(result)
	expect := "[[1,2][3,6][8,10][15,18]]"

	if actual != expect {
		t.Errorf("expect: %s, actual: %s", expect, actual)
	}
}

func Test_merge_front(t *testing.T) {
	data := [][]int{
		[]int{1, 3},
		[]int{2, 6},
		[]int{8, 10},
		[]int{15, 18},
	}
	result := merge(data)
	actual := pairs_array(result)
	expect := "[[1,6][8,10][15,18]]"

	if actual != expect {
		t.Errorf("expect: %s, actual: %s", expect, actual)
	}
}

func Test_merge_all(t *testing.T) {
	data := [][]int{
		[]int{1, 4},
		[]int{4, 5},
		[]int{5, 6},
	}
	result := merge(data)
	actual := pairs_array(result)
	expect := "[[1,6]]"

	if actual != expect {
		t.Errorf("expect: %s, actual: %s", expect, actual)
	}
}

func Test_merge_inner(t *testing.T) {
	data := [][]int{
		[]int{1, 4},
		[]int{2, 3},
	}
	result := merge(data)
	actual := pairs_array(result)
	expect := "[[1,4]]"

	if actual != expect {
		t.Errorf("expect: %s, actual: %s", expect, actual)
	}
}
