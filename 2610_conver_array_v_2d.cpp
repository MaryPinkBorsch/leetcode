// class Solution {
// public:
//     vector<vector<int>> findMatrix(vector<int>& nums) 
//     {
//         unordered_map<int, int> map1;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             map1[nums[i]] += 1; // создаем хэш таблтцу с ключами - значениями из массива
//             // и значениями - кол-во вхождения этого числа в данный массив 
//         }
//         vector<vector<int>> res;
        
//         while(1)
//         {
//             vector<int> row;
//             for (auto it = map1.begin(); it != map1.end(); it++) // !!!! идем по элементам мар
//             {
//                 if(it->second != 0) // если кол-во вхождений не 0 то надо добавить в ряд (ров) и уменьшить на 1 их количество вхождений
//                 {
//                     row.push_back(it->first); // кладем число
//                     it->second -= 1; // уменьшаем их кол-во вхождений (типо уже заполнили в маассив)
//                 }
//             }
//             if(row.size() != 0)
//                 res.push_back(row);
//             else 
//                 break;
//         }

//         return res;
//     }
// };

//https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/