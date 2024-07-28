// class Solution {
// public:
//     int maxArea(vector<int>& height)
//     {
//         int L =0; int R = height.size()-1;
//         int len = -1; int high = -1;
//         int mV =0; int mL = -1; int mR = -1;
//         int V =0;

//         while(L<R)
//         {
//             if(L>=height.size())
//                 break;
//             len = R - L;
//             if(height[L]>height[R])
//                 high  = height[R];
//             else high = height[L];

//             V = high * len;
//             if(V>mV)
//             {
//                 mL = L;
//                 mR = R;
//                 mV = V;
//             }

//             if(height[L]>height[R])
//                 R--;
//             else L++;

//         }
//         return mV;

//     }
// };

// https://leetcode.com/problems/container-with-most-water/?envType=study-plan-v2&envId=leetcode-75