class Solution {
public:
    int searchSmall(int A[], int first, int last, int target)
    {
        if (first > last)
            return -1;
        int mid = (first + last)/2;
        if (target < A[mid])
            return searchSmall(A, first, mid - 1, target);
        else if (target > A[mid])
        {
            if (mid + 1 <= last && A[mid + 1] == target)
                return (mid + 1);
            return searchSmall(A, mid + 1, last, target);
        }
        else
        {
            if ((mid == first) || (mid - 1 >= first && A[mid - 1] < target))
                return mid;
            return searchSmall(A, first, mid - 1, target);
        }
    }

    int searchBig(int A[], int first, int last, int target)
    {
        if (first > last)
            return -1;
        int mid = (first + last)/2;
        if (target > A[mid])
            return searchBig(A, mid + 1, last, target);
        else if (target < A[mid])
        {
            if (mid - 1 >= first && A[mid - 1] == target)
                return mid - 1;
            return searchBig(A, first, mid - 1, target);
        }
        else
        {
            if ((mid == last) || (mid + 1 <= last && A[mid + 1] > target))
                return mid;
            return searchBig(A, mid + 1, last, target);
        }
    }

    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res;
        if (n==0)
        {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
    
        res.resize(2);
        res[0] = searchSmall(A, 0, n-1, target);
        res[1] = searchBig(A, 0, n-1, target);
        return res;
    }
};
