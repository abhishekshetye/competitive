class Solution {
public:

    map<pair<int,int>, vector<int>> dp;
	
	vector<int> numsSameConsecDiff(int N, int K) {
		
		vector<int> ans;
		
        if (N == 1)
            ans.push_back(0);
        
		for(int i = 1; i <= 9; ++i) {
			vector<int> nums = calculate(i, K, N);
			ans.insert(ans.end(), nums.begin(), nums.end());
		}

		return ans;

	}

	vector<int> calculate(int first, int diff, int n) {

		vector<int> ans, otherVector, anotherVector;
		
		if (n <= 1) {
			ans.push_back(first);
			return ans;
		}
        
        if (dp.find(make_pair(first, n)) != dp.end()) //already processed
            return dp[make_pair(first, n)];

		int other = first - diff, another = first + diff;
		
		if (other >= 0) 
			otherVector = calculate(other, diff, n-1);

		if (other != another && another <= 9) 
			anotherVector = calculate(another, diff, n-1);

		for (int i = 0; i < otherVector.size(); ++i) 
			ans.push_back(first * pow(10, n - 1) + otherVector[i]);

		for (int i = 0; i < anotherVector.size(); ++i)
			ans.push_back(first * pow(10, n - 1) + anotherVector[i]);

        dp[make_pair(first, n)] = ans;
		return ans;
	}
};