package leetcode

// two point
// the highest is the best, the higher may well, the product maybe maximum
// move pointer close to the highest for maximum
func maxArea(height []int) int {
	maximum := 0
	i := 0
	j := len(height) - 1
	for i < j {
		min := height[i]
		if height[j] < min {
			min = height[j]
		}
		current := min * (j - i)
		if current > maximum {
			maximum = current
		}
		if height[i] < height[j] {
			i++
		} else {
			j--
		}
	}
	return maximum
}

func maxAreaForce(height []int) int {
	maximum := 0
	for i := 0; i < len(height)-1; i++ {
		for j := i + 1; j < len(height); j++ {
			min := height[i]
			if height[j] < min {
				min = height[j]
			}
			current := min * (j - i)
			if current > maximum {
				maximum = current
			}
		}
	}
	return maximum
}
