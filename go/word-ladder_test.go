package leetcode

import "testing"

func TestLadderLength(t *testing.T) {
	tests := []struct {
		beginWord string
		endWord   string
		words     []string
		expect    int
	}{
		{
			beginWord: "hit",
			endWord:   "cog",
			words:     []string{"hot", "dot", "dog", "lot", "log", "cog"},
			expect:    5,
		}, {
			beginWord: "hit",
			endWord:   "cog",
			words:     []string{"hot", "dot", "dog", "lot", "log"},
			expect:    0,
		}, {
			beginWord: "a",
			endWord:   "c",
			words:     []string{"a", "b", "c"},
			expect:    2,
		},
	}
	for i, item := range tests {
		actual := ladderLength(item.beginWord, item.endWord, item.words)
		if actual != item.expect {
			t.Fatalf("%d expect %d actual %d\n", i, item.expect, actual)
		}
	}
}
