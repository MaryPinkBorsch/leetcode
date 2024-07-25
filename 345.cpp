// class Solution {
// public:
//     string reverseVowels(string s) 
//     {
//         int L = 0;
//         int R = s.size() -1;
//         while(L<R)
//         {

//             while(L < s.size() && s[L]!= 'a' && s[L]!= 'e' && s[L]!= 'i' && s[L]!= 'o'&& s[L]!= 'u' &&
//             s[L]!= 'A' && s[L]!= 'E' && s[L]!= 'I' && s[L]!= 'O'&& s[L]!= 'U')
//             {
//               L++;                
//             }
//             while(R >= 0 && s[R]!= 'a' && s[R]!= 'e' && s[R]!= 'i' && s[R]!= 'o'&& s[R]!= 'u' &&
//             s[R]!= 'A' && s[R]!= 'E' && s[R]!= 'I' && s[R]!= 'O'&& s[R]!= 'U')
//             {
//               R--;                
//             }

//             if(L>= R)
//                 break;
//             swap(s[L], s[R]);
//             L++;
//             R--;
//         }
//       return s;  
//     }
    
// };

//https://leetcode.com/problems/reverse-vowels-of-a-string/?envType=study-plan-v2&envId=leetcode-75