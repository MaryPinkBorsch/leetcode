#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
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

void qsort_Mas(int *A, unsigned int len)
{
    if (len < 2)
        return;
    int pivot = (A[0] + A[len - 1]) / 2;
    int L = 0, R = len - 1;
    while (L < R)
    {
        while (A[L] < pivot && L < R)
            L++;
        while (A[R] > pivot && L < R)
            R--;
        if (L < R)
        {
            int tmp = A[L];
            A[L] = A[R];
            A[R] = tmp;
        }
        else
        {
            qsort_Mas(A, L);
            if (L != 0)
                qsort_Mas(A + L, len - L);
        }
    }
}

int main(int argc, char *argv[])
{
    int *p_int = nullptr;
    p_int = new int[100];
    for (int i = 0; i < 100; i++)
    {
        p_int[i] = 100 - i;
    }

    // print(p_int, 100);
    // cout << endl;
    // MASYA_shake(p_int, 100);
    // print(p_int, 100);

    // int fib20 = fib(20);
    // cout << fib20 << endl;
    cout << endl;
    // for (int i = 0; i < 100; i++)
    // {
    //     p_int[i] = 100 - i;
    // }
    print(p_int, 100);
    qsort_Mas(p_int, 100);
    print(p_int, 100);
    cout << endl;

    delete[] p_int;
    return 0;
}
