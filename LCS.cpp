class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> num_set;
        
        for (int i = 0; i < num.size(); i++)
            num_set.insert(num[i]);
            
        int max_count = 0;
        for (int i = 0; i < num.size(); i++)
        {
            int cur = num[i];
            int count = 1;
            
            if (num_set.find(cur) != num_set.end()) 
            {
                num_set.erase(cur);
                while(num_set.find(--cur) != num_set.end())
                {
                    count++;
                    num_set.erase(cur);
                }
                
                cur = num[i];
                while(num_set.find(++cur) != num_set.end())
                {
                    count++;
                    num_set.erase(cur);
                }
                if (count > max_count)
                    max_count = count;
            }
        }
        return max_count;
    }
};
