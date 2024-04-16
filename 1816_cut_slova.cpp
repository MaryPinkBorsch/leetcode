// class Solution {
// public:
//     string truncateSentence(string s, int k) 
//     {
//         int counter = 0;
//         int spaces = 0;
//         while(counter < s.size())
//         {
//             if(s[counter]== ' ')
//                 spaces++;
//             if(spaces == k)
//             {
//                 s.resize(counter);
//                 break;
//             }
//             counter++;
//         }
//         return s;
//     }
// };