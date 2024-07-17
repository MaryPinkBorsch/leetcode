#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> findIntersectionValues(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> map1;
        for (int i = 0; i < nums1.size(); i++)
        {
            map1[nums1[i]] += 1; // создаем хэш таблтцу с ключами - значениями из массива
            // и значениями - кол-во вхождения этого числа в данный массив (для первого)
        }
        unordered_map<int, int> map2;
        for (int i = 0; i < nums2.size(); i++)
        {
            map2[nums2[i]] += 1; // создаем хэш таблтцу с ключами - значениями из массива
            // и значениями - кол-во вхождения этого числа в данный массив (для 2)
        }
        int ans1 = 0;
        int ans2 = 0;

        // map2:
        // 1->1
        // 2->1

        // map1:
        // 2->2
        // 3->1

        for (auto it = map2.begin(); it != map2.end(); it++) // !!!! идем по элементам мар2
        {
            if (map1.find(it->first) != map1.end()) // чтобы избежать добавления новых элеметов с нулем вхождений
                ans1 += map1[it->first];
        }

        for (auto it = map1.begin(); it != map1.end(); it++) // !!!! идем по элементам мар1
        {
            if (map2.find(it->first) != map2.end())
                ans2 += map2[it->first];
        }
        vector<int> res;
        res.push_back(ans1);
        res.push_back(ans2);

        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution wiw;

    vector<int> nums1 = {2, 3, 2};
    vector<int> nums2 = {1, 2};

    vector<int> res = wiw.findIntersectionValues(nums1, nums2);

    return 0;
}

//https://leetcode.com/problems/find-common-elements-between-two-arrays/submissions/1324033321/