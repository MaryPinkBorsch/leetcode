// class Solution {
// public:
//     int maxVowels(string s, int k) {
//         int max = 0;
//         int cur = 0;
//         for (int i = 0; i < k; i++) {
//             if (s[i] == 'a' || s[i] == 'o' || s[i] == 'i' || s[i] == 'e' ||
//                 s[i] == 'u')
//                 cur++;
//         }
//         if (cur > max)
//             max = cur;
//         for (int i = 1; i < s.size() - k +1; i++) {
//             if (s[i - 1] == 'a' || s[i - 1] == 'o' || s[i - 1] == 'i' ||
//                 s[i - 1] == 'e' || s[i - 1] == 'u')
//                 cur--; // техника Sliding window

//             if (s[i + k - 1] == 'a' || s[i - 1 + k] == 'o' ||
//                 s[i + k - 1] == 'i' || s[i + k - 1] == 'e' ||
//                 s[i - 1 + k] == 'u')
//                 cur++;

//             if (cur > max)
//                 max = cur;
//         }
//         return max;
//     }
// };

// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/?envType=study-plan-v2&envId=leetcode-75