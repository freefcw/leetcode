package leetcode

import "testing"

func Test_reverseList(t *testing.T) {
	tests := []struct {
		input  []int
		expect []int
	}{
		{
			input:  []int{1, 2, 3},
			expect: []int{3, 2, 1},
		}, {
			input:  []int{},
			expect: []int{},
		},
	}
	for _, item := range tests {
		input := createLinkedList(item.input)
		actual := reverseList(input)

		if !compareLinkedList(actual, createLinkedList(item.expect)) {
			t.Fatalf("%v is failed\n", item.input)
		}
	}
}

func Test_reverseKGroup(t *testing.T) {
	tests := []struct {
		input  []int
		k      int
		expect []int
	}{
		{
			input:  []int{1, 2, 3, 4, 5, 6},
			k:      2,
			expect: []int{2, 1, 4, 3, 6, 5},
		}, {
			input:  []int{1, 2, 3, 4, 5},
			k:      2,
			expect: []int{2, 1, 4, 3, 5},
		}, {
			input:  []int{1, 2, 3, 4, 5},
			k:      3,
			expect: []int{3, 2, 1, 4, 5},
		}, {
			input:  []int{},
			k:      3,
			expect: []int{},
		},
	}
	for _, item := range tests {
		input := createLinkedList(item.input)
		actual := reverseKGroup(input, item.k)

		actualNums := linkedList2array(actual)
		if !intsEqual(actualNums, item.expect) {
			t.Fatalf("%v is failed, expect %v, actual %v\n",
				item.input, item.expect, actualNums)
		}
	}
}
