package algorithms

import (
	"fmt"
)

func Qsort(a []int, low, high int) {
	if low >= high {
		return
	}
	i := low + 1
	j := high - 1
	for i <= j {
		for a[i] <= a[low] {
			i++
			if i == high {
				break
			}
		}
		for a[j] > a[low] {
			j--
			if j == low {
				break
			}
		}

		if i >= j {
			break
		}
		a[i], a[j] = a[j], a[i]
		// j--
	}
	a[low], a[j] = a[j], a[low]
	Qsort(a, low, j)
	Qsort(a, j+1, high)
}
func main() {
	a := []int{4, 5, 6, 3, 35, 2}
	// a := []int{3, 2, 1, 5, 6, 4}
	// a := []int{7, 6, 5, 4, 3, 2, 1}
	Qsort(a, 0, len(a))
	fmt.Println(a)
}
