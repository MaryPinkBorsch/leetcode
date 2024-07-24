// class Solution {
// public:
//     string gcdOfStrings(string str1, string str2) 
//     {
//         vector <string> prefixs;
//         string str;

//         int counter =0;
//         while(counter<str1.size() && counter<str2.size())
//         {   
//             if(str1[counter] == str2[counter]) 
//             {
//                 str+= str1[counter];
//                 prefixs.push_back(str);
//                 counter++;
//             }
//             else break;
//         }
//         for(int i = prefixs.size() - 1; i >=0 ; i--)
//         {
//             if(hren_divisible(str1, prefixs[i]) && hren_divisible(str2, prefixs[i]))
//                 return prefixs[i];
//         }
//         return "";
//     }
    
//     bool hren_divisible(string s, string t)
//     {
//         if(s.size() % t.size() != 0 )
//             return false;
//         int count = s.size() / t.size();

//         for(int i =0; i < count; i++)
//         {
//             for(int j =0; j <  t.size(); j++)
//             {
//                 if(s[j+i*t.size()]!=t[j])
//                     return false;
//             } 
//         }
//         return true;

//     }
// };