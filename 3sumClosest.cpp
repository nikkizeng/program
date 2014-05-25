class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
		int sum = 0, bestSum = 0;
		for (int i = 0; i < 3; i++)
			bestSum += num[i];

		for (int i = 0; i < num.size() - 2; i++)
			for (int j = i + 1; j < num.size() - 1; j++)
				for (int k = j + 1; k < num.size(); k++)
				{
					sum = num[i] + num[j] + num[k];
					if (abs(sum - target) < abs(bestSum - target))
					{
						bestSum = sum;
						if (bestSum == target)
						    return bestSum;
					}
				}
		return bestSum;
	}
};
