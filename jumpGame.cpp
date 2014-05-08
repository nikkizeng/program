class Solution {
public:
    bool goEnd(int A[], int n, int index)
    {
        if (index >= n-1) return true;
        
        int step = A[index];
        bool flag = false;
        for (int i = index+1; i < n && i <= index+step; i++)
        {
            flag = goEnd(A, n, i);
            if (flag)
                return true;
        }
        return false;
    }
    
    bool canJump(int A[], int n) {
        if (n == 0) return true;
        
        return goEnd(A, n, 0);
    }
};
