#include<vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        unordered_map <int, int> table;
        for(int i = 0; i < arr.size();i++)
        {
            table[arr[i]]++;
        }
        for(auto it = table.begin(); it!= table.end(); it++)
        {
            for(auto it2 = (table.begin());it2!= table.end(); it2++)
            {
                if(it->second == it2->second && it!=it2)
                    return false;
            }
        }
        return true;

        
    }
};

class Solution2 {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        unordered_map <int, int> table;
        unordered_set <int> freq;
       
        for(int i = 0; i < arr.size();i++)
        {
            table[arr[i]]++;
        }
        for(auto it = table.begin(); it!= table.end(); it++)
        {
            auto it2 = freq.find(it->second);
            if (it2 == freq.end()) 
            {
                freq.insert(it->second);
            }
            else
                return false;
        }
        return true;

        
    }
};