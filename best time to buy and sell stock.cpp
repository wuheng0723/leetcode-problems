class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1)
			return 0;
        int maxP = 0;
        for (int i = 0; i < prices.size() - 1; i++)
            for (int j = i + 1; j < prices.size(); j++)
                if (prices[j] - prices[i] > maxP)
                    maxP = prices[j] - prices[i];
        return maxP;
    }
};