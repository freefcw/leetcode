package main

import (
	"fmt"
	"bytes"
)

// trie树优化也才144ms，不容易
type TreeNode struct {
	ch byte
	count int
	children []*TreeNode
}

func (tree *TreeNode)String() string {
	var buff bytes.Buffer
	fmt.Fprintf(&buff, "%d %d %v", tree.ch, tree.count, tree.children)
	return buff.String()
}

func (tree *TreeNode) getChild(ch byte) *TreeNode {
	for _, node := range tree.children {
		if node.ch == ch {
			return node
		}
	}
	return nil
}

func insertTree(root *TreeNode, s string) {
	if len(s) == 0 {
		root.count++
		return
	}
	node := root.getChild(s[0])
	if node != nil {
		insertTree(node, s[1:])
	} else {
		node = new(TreeNode)
		node.count = 0
		node.ch = s[0]
		node.children = make([]*TreeNode, 0)
		root.children = append(root.children, node)
		insertTree(node, s[1:])
	}
}

func numMatchingSubseq(S string, words []string) int {
	root := new(TreeNode)
	root.count = 0
	for _, word := range words {
		insertTree(root, word)
	}
	// fmt.Println(root)
	total := 0

	var nodesMap [27][]*TreeNode
	for i := 0; i < 27; i++ {
		nodesMap[i] = make([]*TreeNode, 0)
	}
	for _, node := range root.children {
		i := node.ch - 'a'
		nodesMap[i] = append(nodesMap[i], node)
	}

	for i := 0; i < len(S); i++ {
		ch := S[i]
		nodes := nodesMap[ch - 'a']
		nodesMap[ch - 'a'] = make([]*TreeNode, 0)

		for index := 0; index < len(nodes); index++ {
			node := nodes[index]
			total += nodes[index].count

			for _, subNode := range node.children {
				nodesMap[subNode.ch - 'a'] = append(nodesMap[subNode.ch - 'a'], subNode)
			}
		}
	}

	return total
}

func main() {
	ss := []string{"a", "bb", "acd", "ace", "d", "cde", "ce", "ec"}
	fmt.Println(numMatchingSubseq("abcde", ss))

	ss = []string{"ahjpjau","ja","ahbwzgqnuk","tnmlanowax"}
	fmt.Println(numMatchingSubseq("dsahjpjauf", ss))


	fmt.Printf("hello world!\n")
}
