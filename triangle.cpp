class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.size() == 0) return 0;
        int size = triangle.size();
        vector<int> res (size);
        
        for (int i = 0; i < size; i++)
            res[i] = triangle[size - 1][i];
        
        for (int i = size - 2; i >= 0; i--)
            for (int j = 0; j <= i; j++)
            {
                int temp = res[j] > res[j+1] ? res[j+1] : res[j];
                res[j] = temp + triangle[i][j];
            }
        return res[0];
    }
};
