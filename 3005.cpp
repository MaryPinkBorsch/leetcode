// class Solution {
// public:
//     int maxFrequencyElements(vector<int>& nums) 
//     {
//         unordered_map<int, int> tab;
//         int res = 0;
//         for (int i = 0; i < nums.size(); i++) 
//         {
//             tab[nums[i]]++;
//         }
//         int max = 0;
//         for(auto it = tab.begin(); it != tab.end(); ++it) \\\\!!!!!!!!!!!!!
//         {
//             // it->first - ключ элемента (число)
//             // it->second - значение элемента (частота)
//             if(max<it->second)
//                 max = it->second;
//         }
//         for(auto it = tab.begin(); it != tab.end(); ++it) 
//         {            
//             if(max==it->second)
//                 res+=max;
//         }
//         return res;
//     }
// };