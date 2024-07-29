#include <vector>
#include <unordered_set>
using namespace std;

// class Solution
// {
// public:
//     double findMaxAverage(vector<int> &nums, int k)
//     {
//         // double max = -9999;
//         // double sum = 0;
//         // int count = 0;
//         // for (int i = 0; i < nums.size()-k+1; i++)
//         // {
//         //     sum = 0;
//         //     count = 0;
//         //     for (int j = i; count < k && j < nums.size(); j++)
//         //     {
//         //         sum += nums[j];
//         //         count++;
//         //     }
//         //     if ((sum / k) > max)
//         //         max = sum / k;
//         // }

//         double max = 0;
//         double sum = 0;
//         double res = 0;
//         int count = 0;
//         if (nums.size() == 1)
//             return nums[0];

//         for (int j = 0; j < k; j++)
//         {
//             sum += nums[j];
//         }
//         res = sum / k;
//         if (res < 0)
//             max = -0.1;
//         for (int i = k; i < nums.size(); i++)
//         {
//             if (res > max && max >= 0 && res > 0)
//                 max = res;

//             if (max < 0 && res < 0 && res < max)
//                 max = res;

//             sum += (nums[i] - nums[i - k]);
//             res = sum / k;
//             if (res > max && max >= 0 && res > 0)
//                 max = res;

//             if (max < 0 && res < 0 && res < max)
//                 max = res;
//         }

//         if (res > max && max >= 0 && res > 0)
//             max = res;

//         if (max < 0 && res < 0 && res < max)
//             max = res;

//         return max;
//     }
// };

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        double max = 0;
        double sum = 0;
        double res = 0;

        if (nums.size() == 1)
            return nums[0];

        for (int j = 0; j < k; j++)
        {
            sum += nums[j];
        }
        max = sum / k;

        for (int i = 1; i <= nums.size() - k; i++)
        {
            sum += (nums[i + k - 1] - nums[i - 1]);
            res = sum / k;
            if (res > max)
                max = res;
        }
        return max;
    }
};

int main()
{
    Solution w;
    // vector<int> nums = {1, 12, -5, -6, 50, 3};
    // vector<int> nums = {0, 1, 1, 3, 3};
    // vector<int> nums = {8860, -853, 6534, 4477, -4589, 8646, -6155, -5577, -1656, -5779, -2619, -8604, -1358, -8009, 4983, 7063, 3104, -1560, 4080, 2763, 5616, -2375, 2848, 1394, -7173, -5225, -8244, -809, 8025, -4072, -4391, -9579, 1407, 6700, 2421, -6685, 5481, -1732, -8892, -6645, 3077, 3287, -4149, 8701, -4393, -9070, -1777, 2237, -3253, -506, -4931, -7366, -8132, 5406, -6300, -275, -1908, 67, 3569, 1433, -7262, -437, 8303, 4498, -379, 3054, -6285, 4203, 6908, 4433, 3077, 2288, 9733, -8067, 3007, 9725, 9669, 1362, -2561, -4225, 5442, -9006, -429, 160, -9234, -4444, 3586, -5711, -9506, -79, -4418, -4348, -5891};
    // vector<int> nums = {0, 4, 0, 3, 2};
    // vector<int> nums = {-6662, 5432, -8558, -8935, 8731, -3083, 4115, 9931, -4006, -3284, -3024, 1714, -2825, -2374, -2750, -959, 6516, 9356, 8040, -2169, -9490, -3068, 6299, 7823, -9767, 5751, -7897, 6680, -1293, -3486, -6785, 6337, -9158, -4183, 6240, -2846, -2588, -5458, -9576, -1501, -908, -5477, 7596, -8863, -4088, 7922, 8231, -4928, 7636, -3994, -243, -1327, 8425, -3468, -4218, -364, 4257, 5690, 1035, 6217, 8880, 4127, -6299, -1831, 2854, -4498, -6983, -677, 2216, -1938, 3348, 4099, 3591, 9076, 942, 4571, -4200, 7271, -6920, -1886, 662, 7844, 3658, -6562, -2106, -296, -3280, 8909, -8352, -9413, 3513, 1352, -8825};
    int k = 4;
    // vector<int> nums = {9, 7, 3, 5, 6, 2, 0, 8, 1, 9};
    vector<int> nums = {0, 1, 1, 3, 3};

    //[-6662,5432,-8558,-8935,8731,-3083,4115,9931,-4006,-3284,-3024,1714,-2825,-2374,-2750,-959,6516,9356,8040,-2169,-9490,-3068,6299,7823,-9767,5751,-7897,6680,-1293,-3486,-6785,6337,-9158,-4183,6240,-2846,-2588,-5458,-9576,-1501,-908,-5477,7596,-8863,-4088,7922,8231,-4928,7636,-3994,-243,-1327,8425,-3468,-4218,-364,4257,5690,1035,6217,8880,4127,-6299,-1831,2854,-4498,-6983,-677,2216,-1938,3348,4099,3591,9076,942,4571,-4200,7271,-6920,-1886,662,7844,3658,-6562,-2106,-296,-3280,8909,-8352,-9413,3513,1352,-8825]
    //[4,0,4,3,3]
    //[9,7,3,5,6,2,0,8,1,9]

    auto res = w.findMaxAverage(nums, k);

    return 0;
}

// class Solution {
// public:
//     double findMaxAverage(vector<int>& nums, int k) {
//         double max = 0;
//         double sum = 0;
//         double res = 0;
//         // int count = 0;
//         if (nums.size() == 1)
//             return nums[0];

//         for (int j = 0; j < k; j++) {
//             sum += nums[j];
//         }
//         max = sum / k;
//         for (int i = k; i < nums.size(); i++) {
//             sum += (nums[i] - nums[i - k]);
//             res = sum / k;
//             if (res > max && max >= 0 && res > 0)
//                 max = res;

//             if (max < 0 && res < 0 && res < max)
//                 max = res;
//         }
//         return max;
//     }
// };