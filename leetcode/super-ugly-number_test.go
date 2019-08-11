package leetcode

import "testing"

func Test_nthSuperUglyNumber(t *testing.T) {
	tests := []struct {
		n      int
		primes []int
		expect int
	}{
		{
			n:      55,
			primes: []int{7, 13, 17, 19, 23, 29, 31, 41, 47, 53},
			expect: 961,
		}, {
			n:      15,
			primes: []int{2, 3, 11, 13, 23, 29, 31, 41, 47, 53, 59, 61, 67, 79, 97, 101, 103, 107, 109, 137},
			expect: 24,
		}, {
			n:      4,
			primes: []int{2, 3, 5},
			expect: 4,
		}, {
			n:      12,
			primes: []int{2, 7, 13, 19},
			expect: 32,
		}, {
			n:      1,
			primes: []int{2, 3, 5},
			expect: 1,
		}, {
			n:      2,
			primes: []int{2, 3, 5},
			expect: 2,
		}, {
			n:      15,
			primes: []int{3, 5, 7, 11, 19, 23, 29, 41, 43, 47},
			expect: 35,
		}, {
			n:      950,
			primes: []int{2, 11, 17, 19, 23, 29, 31, 41, 53, 59, 67, 73, 79, 89, 101, 127, 137, 139, 149, 163, 167, 179, 181, 191, 197, 223, 239, 241, 251, 263},
			expect: 12788,
		}, {
			n:      100000,
			primes: []int{7, 19, 29, 37, 41, 47, 53, 59, 61, 79, 83, 89, 101, 103, 109, 127, 131, 137, 139, 157, 167, 179, 181, 199, 211, 229, 233, 239, 241, 251},
			expect: 1092889481,
		},
	}

	for i, item := range tests {
		actual := nthSuperUglyNumber(item.n, item.primes)
		if actual != item.expect {
			t.Fatalf("%d, expect %d, actual %d\n", i, item.expect, actual)
		}
	}
}
