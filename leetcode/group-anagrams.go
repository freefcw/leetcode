package leetcode

func genKey(s string) string {
	numbers := make([]byte, 26)
	for i := 0; i < len(numbers); i++ {
		numbers[i] = '0'
	}
	for i := 0; i < len(s); i++ {
		key := s[i] - 'a'
		numbers[key]++
	}

	return string(numbers)
}

// use key generate for hash
func groupAnagrams(strs []string) [][]string {
	hashmap := make(map[string][]string)
	for _, val := range strs {
		s := genKey(val)
		if _, ok := hashmap[s]; !ok {
			hashmap[s] = make([]string, 0, 2)
		}
		hashmap[s] = append(hashmap[s], val)
	}
	result := make([][]string, 0, len(hashmap))
	for _, val := range hashmap {
		result = append(result, val)
	}

	return result
}

// ----------------- sort ------------

func sortByte(buff []byte, low, high int) {
	if low >= high {
		return
	}
	i := low + 1
	j := high - 1
	for i <= j {
		for buff[i] <= buff[low] {
			i++
			if i >= high {
				break
			}
		}
		for buff[j] > buff[low] {
			j--
			if low >= j {
				break
			}
		}
		if i >= j {
			break
		}
		buff[i], buff[j] = buff[j], buff[i]
		j--
	}
	buff[low], buff[j] = buff[j], buff[low]
	sortByte(buff, low, j)
	sortByte(buff, j+1, high)
}

func sortString(s string) string {
	buff := []byte(s)
	sortByte(buff, 0, len(buff))
	return string(buff)
}

// use sort
func groupAnagrams2(strs []string) [][]string {
	hashmap := make(map[string][]string)
	for _, val := range strs {
		s := sortString(val)
		if _, ok := hashmap[s]; !ok {
			hashmap[s] = make([]string, 0, 2)
		}
		hashmap[s] = append(hashmap[s], val)
	}
	result := make([][]string, 0, len(hashmap))
	for _, val := range hashmap {
		result = append(result, val)
	}

	return result
}
