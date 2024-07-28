// class Solution {
// public:
//     bool isSubsequence(string s, string t)
//     {
//         int p1 =0;
//         int p2 =0;
//         for(int i = 0; i < s.size(); i++)
//         {
//             if(p1>=s.size())
//                 return false;
//             while(1)
//             {
//                 if(p2>=t.size())
//                     return false;

//                 if(s[p1]==t[p2])
//                 {
//                     p2++;
//                     break;
//                 }
//                 p2++;
//             }
//             p1++;
//         }
//         return true;

//     }
// };

// https://leetcode.com/problems/is-subsequence/?envType=study-plan-v2&envId=leetcode-75