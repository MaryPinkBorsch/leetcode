// class Solution {
// public:
//     bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
//     {
//         string slovo1;
//         string slovo2;

//         for(int i = 0; i< word1.size(); i++)
//         {
//             slovo1 += word1[i];
//         }

//         for(auto & element:word2) //!!!!!!!!!!!!!!!!!!!!!!!!
//         {
//             slovo2 += element; // аналог word2[i] (не обзяязательно писатьб элемент, но так проще)
//         }

//         if (slovo1.compare(slovo2)!= 0)
//             return false;
//         else
//             return true;
//     }
// };

//https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/