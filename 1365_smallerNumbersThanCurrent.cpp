#include <vector>
using namespace std;
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums)
    {
        // vector<int> result;
        // result.resize(nums.size());
        // for(int i = 0; i < nums.size(); i++)
        // {
        //     for(int j = 0; j < nums.size(); j++)
        //     {
        //         if(i==j)
        //             continue;
        //         if(nums[j]<nums[i])
        //             result[i]++;                
        //     }
        // }
        // return result;        
    }
};

// #include <unordered_map>
// class Solution {
// public:
//     vector<int> smallerNumbersThanCurrent(vector<int>& nums)
//     {   
//         vector<int> result;
//         result.resize(nums.size());
//         unordered_map <int,int> idx;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             idx[nums[i]]++; // если мы натыкаемся на такое число еще раз мы ++ его счетчик в идкс            
//         }

//         for(int i = 0; i < nums.size(); i++)
//         {
//             for(auto & item : idx) //проход по всем элементам хэш мапа 
//             {
//                 if(nums[i] == item.first) // item.first - это ключ = число которое лежит в нумсах
//                     continue;
//                 if(nums[i] > item.first)
//                     result[i]+= item.second;                
//             }
//         }
//         return result;  

       
//     }
// };