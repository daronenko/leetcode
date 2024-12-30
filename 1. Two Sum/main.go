package main

import "fmt"

func twoSum(nums []int, target int) []int {
	diffs := make(map[int]int, len(nums))
	for i, num := range nums {
		diff := target - num
		if _, exists := diffs[diff]; exists {
			return []int{diffs[diff], i}
		} else {
			diffs[num] = i
		}
	}

	return []int{}
}

func main() {
	nums := []int{3, 2, 4}
	target := 6
	fmt.Println(twoSum(nums, target))
}
