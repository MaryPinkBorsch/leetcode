// class Solution {
// public:
//     int findPermutationDifference(string s, string t) 
//     {
//         int res = 0;
//         unordered_map <char, int> m1, m2;
//         for(int i=0; i<s.size();i++)
//         {
//             m1[s[i]] = i;
//         }
//         for(int i=0; i<t.size();i++)
//         {
//             m2[t[i]] = i;
//         }

//         for(int i=0; i<s.size();i++)
//         {
//             res+= abs(m1[s[i]] - m2[s[i]]);
//         }

//         return res;
        
//     }
// };

// https://leetcode.com/problems/permutation-difference-between-two-strings/description/