#include <vector>

using namespace std;

class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        long res = 0;
        long sum1 = 0, sum2 = 0;
        // for(auto & i : nums1)
        //     sum1 += i;
        for (int i = 0; i < nums1.size(); i++)
            sum1 += nums1[i];
        for (int i = 0; i < nums2.size(); i++)
            sum2 += nums2[i];
        //res = (sum2 - sum1) / (int)nums2.size();
        res = sum2;
        res -= sum1;
        res /= (int)nums2.size();

        return res;
    }
};

int main(int argc, char * argv[]) 
{
    Solution wtf;

    std::vector<int> nums1 = {224,667,24,92,184,809,862,774,755,688,246,32,18,567,726,338,547,586,573,250,399,342,556,310,23,323,550,28,649,269,675,943,630,415,122,238,626,802,465,968,579,290,614,616};
    std::vector<int> nums2 = {574,226,637,544,561,20,16,110,12,762,614,676,714,956,567,257,311,234,326,790,604,238,618,453,387,850,555,403,602,663,743,655,212,330,80,298,11,6,797,172,538,535,278,931};
    auto res = wtf.addedInteger(nums1, nums2);
    return res;
}