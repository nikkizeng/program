class Solution {
public:
    int findClosest(vector<int> &num, int target, int curIndex, int number, int sum, int bestSum)
    {
        if (number == 3)
        {
            if (abs(sum - target) < abs(bestSum - target))
                bestSum = sum;
            return bestSum;
        }
        for (int i = curIndex + 1; i < num.size(); i++)
        {
            bestSum = findClosest(num, target, i, number + 1, sum + num[i], bestSum);
            if (bestSum == target)
                return bestSum;
        }
        return bestSum;
    }

    int threeSumClosest(vector<int> &num, int target) {
        int bestSum = 0;
        for (int i = 0; i < 3; i++)
            bestSum += num[i];
            
        for (int i = 0; i < num.size() - 2; i++)
        {
            bestSum = findClosest(num, target, i, 1, num[i], bestSum);
            if (bestSum == target)
                return bestSum;
        }
        return bestSum;
    }
};
