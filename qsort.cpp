#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <vector>

#include <string>

#include <chrono>

using namespace std;

// fib(6) == fib(4) + fib(5) == (fib(2) + fib(3)) + (fib(3) + fib(4)) == (1 + (1 + 1)) + ((1 + 1) + (1 + (1 + 1))) == 8
int fib(int a)
{
    if (a == 0) // fib(0)
        return 0;
    if (a == 1) // fib(1)
        return 1;
    if (a == 2) // fib(2)
        return 1;
    return fib(a - 2) + fib(a - 1); // fib(n) = fib(n-2) + fib(n-1)
}

void print(int *x, unsigned int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << ' ';
    }
    cout << endl;
}
void MASYA_shake(int *A, unsigned int len)
{
    bool sorted = false;
    int right = len - 1;
    int left = 0;

    while (sorted == false)
    {
        sorted = true;
        for (int i = 0; i < len - 1; i++)
        {
            if (A[i] > A[i + 1])
            {
                int tmp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = tmp;
                sorted = false;
            }
        }
        left++;
        if (sorted == true)
            break;

        for (int i = right; i > left; i--)
        {
            if (A[i] < A[i - 1])
            {
                int tmp = A[i];
                A[i] = A[i - 1];
                A[i - 1] = tmp;
                sorted = false;
            }
        }
        right--;
    }
}

void qsort_Mas(vector<string> &names, vector<int> &heights, int start, int finish)
    {
        if (finish - start < 1)
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
                swap(heights[L], heights[R]);
                swap(names[L], names[R]);
            }
            else
            {
                if (L > start)
                    qsort_Mas(names, heights, start, L - 1);
                if (L != 0)
                    qsort_Mas(names, heights, L, finish);
            }
        }
    }

int main(int argc, char *argv[])
{

    // const auto start{std::chrono::steady_clock::now()};
    // const auto end{std::chrono::steady_clock::now()};
    // const std::chrono::duration<double> elapsed_seconds{end - start};

    // std::cout << "Elapsed time: " << std::endl;
    int *p_int = nullptr;
    p_int = new int[100];
    for (int i = 0; i < 100; i++)
    {
        p_int[i] = 100 - i;
    }

    print(p_int, 100);
    cout << endl;

    {
        auto t_start = std::chrono::high_resolution_clock::now();
        MASYA_shake(p_int, 100);
        auto t_end = std::chrono::high_resolution_clock::now();
        std::cout << std::fixed << "Shaker Elapsed time: " << std::chrono::duration<double>(t_end - t_start).count() << " sec" << std::endl;
    }

    print(p_int, 100);

    // int fib20 = fib(20);
    // cout << fib20 << endl;
    cout << endl;
    for (int i = 0; i < 100; i++)
    {
        p_int[i] = 100 - i;
    }
    print(p_int, 100);
    {
        auto t_start = std::chrono::high_resolution_clock::now();
      //  qsort_Mas(p_int, 100);
        auto t_end = std::chrono::high_resolution_clock::now();
        std::cout << std::fixed << "QSort Elapsed time: " << std::chrono::duration<double>(t_end - t_start).count() << " sec" << std::endl;
    }
    print(p_int, 100);
    cout << endl;

    delete[] p_int;
    return 0;
}
