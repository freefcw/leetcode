package leetcode

import "testing"

func TestLongestPalindrome(t *testing.T) {
	tests := []struct {
		input  string
		expect string
	}{
		{
			input:  "bananas",
			expect: "anana",
		}, {
			input:  "babad",
			expect: "bab",
		}, {
			input:  "ccc",
			expect: "ccc",
		}, {
			input:  "cbbd",
			expect: "bb",
		}, {
			input:  "abcdefg",
			expect: "a",
		}, {
			input:  "bbbbbb",
			expect: "bbbbbb",
		}, {
			input:  "abababac",
			expect: "abababa",
		}, {
			input:  "abababab",
			expect: "abababa",
		}, {
			input:  "aaaabbbbbb",
			expect: "bbbbbb",
		}, {
			input:  "abcdcba",
			expect: "abcdcba",
		}, {
			input:  "",
			expect: "",
		}, {
			input:  "a",
			expect: "a",
		},
	}

	for i, item := range tests {
		actual := longestPalindrome2(item.input)
		if actual != item.expect {
			t.Fatalf("%d expect %s, actual %s", i, item.expect, actual)
		}
	}
}
