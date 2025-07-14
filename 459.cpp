// // class Solution {
// // public:
// //     bool repeatedSubstringPattern(string s) {
// //         int n = s.size();
        

// //         for (int prefix_size = 1; prefix_size <= n / 2; prefix_size++) {
// //             if (n % prefix_size != 0)
// //                 continue;
// //             bool found = true;
// //             for (int i = 0; i < n; i++) 
// //             {
// //                 if (s[i] != s[i % prefix_size]) 
// //                 {
// //                     found = false;
// //                     break;
// //                 }
// //             }
// //             if(found)
// //                 return true;
// //         }
// //         return false;
// //     }
// // };

// https://leetcode.com/problems/repeated-substring-pattern/description/?envType=study-plan-v2&envId=programming-skills