package leetcode

import "testing"

func TestLengthOfLongestSubstring(t *testing.T) {
	tests := []struct {
		input  string
		expect int
	}{
		{
			input:  "aab",
			expect: 2,
		}, {
			input:  "abcabcbb",
			expect: 3,
		}, {
			input:  "bbbbb",
			expect: 1,
		}, {
			input:  "",
			expect: 0,
		}, {
			input:  "a",
			expect: 1,
		}, {
			input:  "azz",
			expect: 2,
		}, {
			input:  "pwwkew",
			expect: 3,
		}, {
			input:  "abcdefg",
			expect: 7,
		}, {
			input:  " ",
			expect: 1,
		},
	}
	for i, item := range tests {
		actual := lengthOfLongestSubstring(item.input)
		if actual != item.expect {
			t.Fatalf("%d expect %d, actual %d\n", i, item.expect, actual)
		}
	}
}
