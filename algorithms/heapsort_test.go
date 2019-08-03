package algorithms

import (
	"testing"
)

func Test_heapsort(t *testing.T) {
	arr := []int{3, 2, 1, 5, 6, 4, 0}
	HeapSort(arr)
	for i := 0; i < 7; i++ {
		if arr[i] != i {
			t.Errorf("expect %d, actual %d\n", arr[i], i)
		}
	}
}
