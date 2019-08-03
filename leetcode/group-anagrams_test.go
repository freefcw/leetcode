package leetcode

import (
	"sort"
	"testing"
)

func compareStringSlice(a []string, b []string) bool {
	if len(a) != len(b) {
		return false
	}
	for i := 0; i < len(a); i++ {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}

func Test_genKey(t *testing.T) {
	tables := []struct {
		input  string
		expect string
	}{
		{
			input:  "abc",
			expect: "11100000000000000000000000",
		}, {
			input:  "aaaz",
			expect: "30000000000000000000000001",
		},
	}
	for _, item := range tables {
		actual := genKey(item.input)
		if actual != item.expect {
			t.Errorf("expect: %s\n, actual: %s\n", item.expect, actual)
		}
	}
}

func Test_groupAnagrams(t *testing.T) {
	tables := []struct {
		input  []string
		expect [][]string
	}{
		{
			input:  []string{},
			expect: [][]string{},
		}, {
			input:  []string{"abc"},
			expect: [][]string{[]string{"abc"}},
		}, {
			input: []string{"eat", "tea", "tan", "ate", "nat", "bat"},
			expect: [][]string{
				[]string{"ate", "eat", "tea"},
				[]string{"nat", "tan"},
				[]string{"bat"},
			},
		},
	}
	for _, item := range tables {
		actual := groupAnagrams(item.input)
		for _, val := range actual {
			sort.Strings(val)
			for i := 0; i < len(item.expect); i++ {
				if val[0] == item.expect[i][0] {
					if !compareStringSlice(val, item.expect[i]) {
						t.Errorf("expect %v, actual %v\n", item.expect, actual)
					}
				}
			}
		}
	}
}

func Test_sortString(t *testing.T) {
	tables := []struct {
		input  string
		expect string
	}{
		{
			input:  "abc",
			expect: "abc",
		}, {
			input:  "cba",
			expect: "abc",
		}, {
			input:  "bbbb",
			expect: "bbbb",
		},
	}

	for _, item := range tables {
		actual := sortString(item.input)
		if actual != item.expect {
			t.Errorf("%s, expect: %s\n actual: %s\n", item.input, item.expect, actual)
		}
	}
}
