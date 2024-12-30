package task

func maxProfit(prices []int) int {
	maxProfit := 0
	minPrice := prices[0]

	for _, price := range prices[1:] {
		if price < minPrice {
			minPrice = price
		} else if currentProfit := price - minPrice; currentProfit > maxProfit {
			maxProfit = price - minPrice
		}
	}

	return maxProfit
}
