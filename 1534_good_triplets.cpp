// class Solution {
// public:
//     int countGoodTriplets(vector<int>& arr, int a, int b, int c) 
//     {
//         int res =0;

//         for(int i =0; i < arr.size() - 2; i++)
//         {
//             for( int j = i + 1; j < arr.size() - 1; j++)
//             {
//                 if(abs(arr[i] - arr[j]) > a)
//                     continue;
//                 for(int k = j +1; k < arr.size(); k++)
//                 {
//                     if(abs(arr[j] - arr[k]) > b)
//                         continue;
                    
//                     if(abs(arr[i] - arr[k]) <= c)
//                         res++;

//                 }
//             }
//         }

//         return res;
//     }
// };

//https://leetcode.com/problems/count-good-triplets/description/