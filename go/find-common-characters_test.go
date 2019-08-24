package leetcode

import (
	"testing"
)

func TestCommonChars(t *testing.T) {
	tests := []struct {
		input  []string
		expect []string
	}{
		{
			input:  []string{"bella", "label", "roller"},
			expect: []string{"e", "l", "l"},
		}, {
			input:  []string{"cool", "lock", "cook"},
			expect: []string{"c", "o"},
		},
	}

	for i, item := range tests {
		actual := commonChars(item.input)
		if !stringsEqual(actual, item.expect) {
			t.Fatalf("\n%d\nexpect %v\nactual %v\n", i, item.expect, actual)
		}
	}
}
