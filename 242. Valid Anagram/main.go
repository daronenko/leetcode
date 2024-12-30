package task

func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

	counts := make([]int, 26)
	for i := 0; i < len(s); i++ {
		counts[int(s[i]-'a')]++
		counts[int(t[i]-'a')]--
	}

	for _, count := range counts {
		if count != 0 {
			return false
		}
	}

	return true
}
