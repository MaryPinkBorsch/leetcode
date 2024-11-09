// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> res = {};
        
//         sort(nums1.begin(), nums1.end());
//         sort(nums2.begin(), nums2.end());

//         unordered_map<int, int> map1;
//         unordered_map<int, int> map2;

//         for (int i = 0; i < nums1.size(); i++) {
//             map1[nums1[i]]++;
//         }
//         for (int i = 0; i < nums2.size(); i++) {
//             map2[nums2[i]]++;
//         }
//         for(auto & it: map1)
//         {
//             if(map2.find(it.first)!=0)
//                 res.push_back(it.first);
//         }
//         return res;
//     }
// };