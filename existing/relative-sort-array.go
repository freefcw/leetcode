func relativeSortArray(arr1 []int, arr2 []int) []int {
	sort.Ints(arr1)
	if len(arr2) == 0 {
		return arr1
	}
	result := make([]int, 0)
	for i := 0; i < len(arr2); i++ {
		current := arr2[i]
		for k := 0; k < len(arr1); k++ {
			if arr1[k] == current {
				result = append(result, current)
				arr1[k] = -1
			}
			if arr1[k] > current {
				break
			}
		}
	}

	for i := 0; i < len(arr1); i++ {
		if arr1[i] == -1 {
			continue
		}
		result = append(result, arr1[i])
	}

	return result
}