class Solution {
public:
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
                
        /* Consider the mathematics way:
            There are n numbers, so there are 2^n possibilities. 
            e.g. n = 2, all possibilities:
            position  0 1 
            P         0 0 (number 0)
                      0 1         1       
                      1 0         2
                      1 1         3
            so we just need to go through all numbers (from 0 to 2^n), 
            and put the elements which are P=1 to a vector(that is one solution) 
            and then put all solutions to the return vector list. 
        */
        for (int index = 1; index < pow(2, length); index++)
        {
            int flag = index;
            subset.clear();
            for (int i = 0; i < length; i++)
            {
                if (!flag) break;
                if (flag & 1)
                    subset.push_back(S[i]);
                flag >>= 1;
            }
            res.push_back(subset);
        }
            
           
        return res;
    }
};
