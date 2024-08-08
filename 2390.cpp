// class Solution {
// public:
//     string removeStars(string s) {
//         // string ss;
//         // int count = 0;
//         // ss.reserve(s.size());
//         // for(int i = 0; i < s.size(); i++)
//         // {
//         //     if(s[i]!='*')
//         //     {
//         //         ss.push_back(s[i]);
//         //         count++;
//         //     }
//         //     else
//         //     {
//         //         if(ss.size()==0)
//         //             continue;
//         //         else
//         //         {
//         //             ss.erase(1, ss.size() - count);
//         //             count--;
//         //         }

//         //     }
//         // }
//         // return ss;

//         stack<char> ss;
//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] != '*') {
//                 ss.push(s[i]);
//             } else {
//                 if (ss.size() != 0)
//                     ss.pop();
//                 else
//                     continue;
//             }
//         }

//         string ans = "";
//         while (!ss.empty()) {  // код их инета как из стека запихать в строку
//             ans += ss.top();
//             ss.pop();
//         }
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };

//https://leetcode.com/problems/removing-stars-from-a-string/?envType=study-plan-v2&envId=leetcode-75