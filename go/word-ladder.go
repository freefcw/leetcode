package leetcode

var (
	llWordRelation WordRelation
	llVisited      map[string]bool
)

type WordRelation map[string][]string

func (wr WordRelation) AddRelate(word, relation string) {
	entry, ok := wr[word]
	if !ok {
		entry = make([]string, 0, 8)
	}
	entry = append(entry, relation)
	wr[word] = entry
}

func (wr WordRelation) GetRelate(word string) ([]string, bool) {
	entry, ok := wr[word]

	return entry, ok
}

func isLadder(s1, s2 string) bool {
	diff := 0
	for i := 0; i < len(s1); i++ {
		if s1[i] != s2[i] {
			diff++
		}
		if diff > 1 {
			return false
		}
	}

	return true
}

func bfs(beginWord, endWord string, pendingWords []string, level int) int {
	// fmt.Printf("level %d, pending %v\n", level, pendingWords)
	if len(pendingWords) == 0 {
		return 0
	}
	newPendingWords := make([]string, 0, len(pendingWords))
	for i := 0; i < len(pendingWords); i++ {
		if pendingWords[i] == endWord {
			return level + 2
		}
	}

	for i := 0; i < len(pendingWords); i++ {
		llVisited[pendingWords[i]] = true
		entries, ok := llWordRelation.GetRelate(pendingWords[i])
		if !ok {
			continue
		}
		for _, word := range entries {
			if llVisited[word] {
				continue
			}
			if word == endWord {
				return level + 3
			}
			newPendingWords = append(newPendingWords, word)
		}
	}
	return bfs(beginWord, endWord, newPendingWords, level+1)
}

func ladderLength(beginWord string, endWord string, wordList []string) int {
	llWordRelation = make(WordRelation)
	pendingWords := make([]string, 0, 8)
	endInWordList := false
	for i := 0; i < len(wordList); i++ {
		if wordList[i] == endWord {
			endInWordList = true
		}

		for j := i + 1; j < len(wordList); j++ {
			if isLadder(wordList[i], wordList[j]) {
				llWordRelation.AddRelate(wordList[i], wordList[j])
				llWordRelation.AddRelate(wordList[j], wordList[i])
			}
		}
		if isLadder(beginWord, wordList[i]) {
			pendingWords = append(pendingWords, wordList[i])
		}
	}
	if !endInWordList {
		return 0
	}

	llVisited = make(map[string]bool)

	return bfs(beginWord, endWord, pendingWords, 0)
}
