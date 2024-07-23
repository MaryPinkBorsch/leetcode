// class Solution {
// public:
//     bool canConstruct(string ransomNote, string magazine) 
//     {
//         unordered_map <char, int> note;
//         unordered_map <char, int> magaz;

//         for(int i =0; i < ransomNote.size(); i++)
//         {
//             note[ransomNote[i]]++;
//         }
//         for(int i =0; i < magazine.size(); i++)
//         {
//             magaz[magazine[i]]++;
//         }
//         for(auto it = note.begin(); it!=note.end(); it++)
//         {
//             if(magaz[it->first] < it->second)
//                 return false;
//         }
//         return true;
//     }
// };

//https://leetcode.com/problems/ransom-note/description/