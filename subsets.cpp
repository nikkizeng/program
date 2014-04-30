class Solution {
public:
    void getSubset(vector<int> &S, int index, int loop, vector<vector<int> > &vectorList, vector<int> v)
    {
        for (int i = index; i < S.size(); i++)
        {
            v.push_back(S[i]);
            if (loop == 1)
                vectorList.push_back(v);
            else
            {    
                if (i+1 < S.size())
                    getSubset(S, i+1, loop-1, vectorList, v);
            }
            v.pop_back();
        }
    }
    
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > res;
        vector<int> subset;
        res.push_back(subset);
       
        if (S.size() == 0)
            return res;
        int length = S.size();
       
        /* As the problem asks for non-descending order output */
        for (int i = 0; i < length; i++)
            for (int j = i+1; j < length; j++)
                if (S[i] > S[j])
                {
                    S[i] = S[i]^S[j];
                    S[j] = S[i]^S[j];
                    S[i] = S[i]^S[j];
                }
                
        for (int loop = 1; loop <= length; loop++)
            getSubset(S, 0, loop, res, subset);
           
        return res;
    }
};
