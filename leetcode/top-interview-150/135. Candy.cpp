class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);  // 모든 아이에게 1개의 사탕으로 시작

        // Forward pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            }
        }

        // Backward pass
        for (int i = n-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1] && candies[i] <= candies[i+1]) {
                candies[i] = candies[i+1] + 1;
            }
        }

        // 총 사탕 수 계산
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
