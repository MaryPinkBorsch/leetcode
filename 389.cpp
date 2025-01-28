// class Solution {
// public:
//     char findTheDifference(string s, string t) 
//     {
//         unordered_map<char,int> m1;
//         unordered_map<char,int> m2;
//         for(int i =0; i < s.size(); i++)
//         {
//             m1[s[i]]++;
//         }
//         for(int i =0; i < t.size(); i++)
//         {
//             m2[t[i]]++;
//         }
//         for( auto & it: m2)
//         {
//             if(m1.find(it.first)== m1.end())
//                 return it.first;
            
//             if(m1[it.first]< it.second)
//                 return it.first;
//         }
//     return 'a';    
//     }
// };

//https://leetcode.com/problems/find-the-difference/description/