// class Solution {
// public:
//     string destCity(vector<vector<string>>& paths) 
//     {
//         struct Flag
//         {
//             bool left = false;
//             bool right = false;
//         };
        
//         unordered_map<string, Flag> mapp;
//         for(int i =0; i<paths.size(); i++)
//         {
//             mapp[paths[i][0]].left = true;
//             mapp[paths[i][1]].right = true;
//         }

//         for(auto it = mapp.begin(); it != mapp.end(); it++)
//         {
//             if(it->second.left == false && it->second.right == true )
//                 return it->first;
//         }
//         return "";
//     }
// };

//https://leetcode.com/problems/destination-city/description/