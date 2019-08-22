package leetcode

import "testing"

func TestLongestPalindromeSubseq(t *testing.T) {
	tests := []struct {
		input  string
		expect int
	}{
		{
			input:  "bbbab",
			expect: 4,
		}, {
			input:  "cbbd",
			expect: 2,
		}, {
			input:  "abcabcba",
			expect: 7,
		}, {
			input:  "",
			expect: 0,
		}, {
			input:  "a",
			expect: 1,
		}, {
			input:  "aa",
			expect: 2,
		}, {
			input:  "euazbipzncptldueeuechubrcourfpftcebikrxhybkymimgvldiwqvkszfycvqyvtiwfckexmowcxztkfyzqovbtmzpxojfofbvwnncajvrvdbvjhcrameamcfmcoxryjukhpljwszknhiypvyskmsujkuggpztltpgoczafmfelahqwjbhxtjmebnymdyxoeodqmvkxittxjnlltmoobsgzdfhismogqfpfhvqnxeuosjqqalvwhsidgiavcatjjgeztrjuoixxxoznklcxolgpuktirmduxdywwlbikaqkqajzbsjvdgjcnbtfksqhquiwnwflkldgdrqrnwmshdpykicozfowmumzeuznolmgjlltypyufpzjpuvucmesnnrwppheizkapovoloneaxpfinaontwtdqsdvzmqlgkdxlbeguackbdkftzbnynmcejtwudocemcfnuzbttcoew",
			expect: 159,
		},
	}

	for _, item := range tests {
		actual := longestPalindromeSubseq(item.input)
		if actual != item.expect {
			t.Fatalf("%s expect %d, actual %d\n", item.input, item.expect, actual)
		}
	}
}
