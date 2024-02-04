// #include <vector>

// using namespace std;
// class Solution {
// public:
//     bool isValid(string s) 
//     {
//         std::vector<char> stak;
//         for (int i = 0; i < s.size(); i++)
//         {
//             char tmp = s[i];
//             if (tmp == '(' || tmp == '[' || tmp == '{' )
//             {
//                 stak.push_back(tmp);
//             }
//             else if(stak.size() == 0)
//             {
//                 return false;
//             }
//             else 
//             {
//                 if(tmp == ')' && stak.back() == '(')
//                 {
//                     stak.pop_back();
//                     continue;
//                 }
//                 if(tmp == ']' && stak.back() == '[')
//                 {
//                     stak.pop_back();
//                     continue;
//                 }
//                 if(tmp == '}' && stak.back() == '{')
//                 {
//                     stak.pop_back();
//                     continue;
//                 }
//                 return false;

//             }



//         }
//         if (stak.size() == 0)
//             return true;
//         else
//             return false;
//     }
// };