#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution 
{
    void Bubble_sort(vector<string>& names, vector<int>& heights)
    {
        int len = heights.size();
        bool Sorted = false;
        do
        {
            Sorted = true;
            for (int i = 0; i < len - 1; i++)
            {
                if (heights[i] < heights[i + 1])
                {
                    int tmp = heights[i];
                    heights[i] = heights[i + 1];
                    heights[i + 1] = tmp;
                    swap(names[i], names[i+1]);

                    Sorted = false;
                }
            }
        } while (Sorted == false);
    }
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) 
    {
        Bubble_sort(names, heights);
        return names;
    }
};

int main(int argc, char * argv[]) 
{
    Solution tmp;
    std::vector<std::string> names = {"Masya", "Pusya", "Mami", "Papi"};
    std::vector<int> heights = {167, 164, 170, 183};
    tmp.sortPeople(names, heights);

    for (auto & name: names)
        std::cout << name << ", ";

    return 0;
}