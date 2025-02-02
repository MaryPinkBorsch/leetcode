// class Solution {
// public:
//     std::vector<string> split_string(std::string& s) {
//         std::vector<string> res;
//         string tmp;
//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] != ' ')
//                 tmp += s[i];
//             else {
//                 res.push_back(tmp);
//                 tmp = "";
//             }
//         }
//         res.push_back(tmp);

//         return res;
//     }

//     bool wordPattern(string pattern, string s) {
//         unordered_map<char, string> mapa;
//         unordered_map<string, char> map2;
//         std::vector<string> s_words = split_string(s);

//         if (pattern.size() != s_words.size())
//             return false;
//         for (int i = 0; i < pattern.size(); i++) {
//             if (mapa.find(pattern[i]) != mapa.end()) 
//             {
//                 if (s_words[i] != mapa[pattern[i]])
//                     return false;
//             } 
//             else 
//             {
//                 if(map2.find(s_words[i])== map2.end())
//                 {
//                     mapa[pattern[i]] = s_words[i];
//                     map2[s_words[i]] =pattern[i];

//                 }
//                 else
//                  return false;
                
                
//             }
//         }
//         return true;
//     }
// };

//https://leetcode.com/problems/word-pattern/description/