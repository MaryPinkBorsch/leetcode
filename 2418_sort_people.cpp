#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution 
{
    void qsort_Mas(vector<string>& names, vector<int>& heights, int start, int finish)
    {
        bool swapped = false;
        if (finish - start < 2)
            return;
        int pivot = (heights[start] + heights[finish]) / 2;
        int L = start, R = finish;
        while (L < R)
        {
            while (heights[L] > pivot && L < R)
                L++;
            while (heights[R] < pivot && L < R)
                R--;
            if (L < R)
            {
                swapped = true;
                int tmp = heights[L];
                heights[L] = heights[R];
                heights[R] = tmp;
            }
            else
            {
                if (swapped == false)
                    return;
                qsort_Mas(names, heights, start, start + L); // ТУТ ЧО ТО НЕ РАБОТАЕТ С КУСОРТОМ НО НИЧЕГО 
                if (L != 0)
                    qsort_Mas(names, heights, start + L, finish);
            }
        }
    }

    void Bubble_sort(vector<string>& names, vector<int>& heights)
    {
        int len = heights.size();
        bool Sorted = false;
        do
        {
            Sorted = true;
            for (int i = 0; i < len -1; i++)
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
    vector<string> sortPeople1(vector<string>& names, vector<int>& heights) 
    {
        qsort_Mas(names, heights, 0, heights.size()-1);
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
    std::cout << endl;

    names = {"Masya", "Pusya", "Mami", "Papi"};
    heights = {167, 164, 170, 183};
    tmp.sortPeople1(names, heights);

    for (auto & name: names)
        std::cout << name << ", ";
    std::cout << endl;

    return 0;
}