
#include <vector>
#include <iostream>
#include <string>

#include <stack>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// class Solution
// {
// public:
//     int pairSum(ListNode *head)
//     {
//         int sum = 0;
//         int max = 0;
//         ListNode *cur = head;
//         ListNode *cur2 = head;
//         int i = 0;
//         int n = 0;
//         while (cur != nullptr)
//         {
//             n++;
//             if (cur->next == nullptr)
//                 break;

//             cur = cur->next;
//         }
//         cur = head;
//         while (cur != nullptr)
//         {
//             if (cur->next == nullptr)
//                 break;
//             cur2 = head;
//             int count = 0;
//             while (count != (n - i - 1))
//             {
//                 if (cur2->next == nullptr)
//                     break;
//                 cur2 = cur2->next;
//                 count++;
//             }
//             sum = cur->val + cur2->val;
//             if (sum > max)
//                 max = sum;

//             cur = cur->next;
//             i++;
//         }
//         return max;
//     }
// };

class Solution
{
public:
    int pairSum(ListNode *head)
    {
        int sum = 0;
        int max = 0;
        ListNode *cur = head;
        ListNode *cur2 = head;
        int i = 0;
        int n = 0;
        while (cur != nullptr)
        {
            n++;
            if (cur->next == nullptr)
                break;

            cur = cur->next;
        }
        cur = head;
        stack<int> list2;
        int j = 0;
        while (j != n / 2)
        {
            j++;
            if (cur->next == nullptr)
                break;

            cur = cur->next;
        }
        while (j != n)
        {
            list2.push(cur->val);
            j++;
            if (cur->next == nullptr)
                break;

            cur = cur->next;
        }

        cur = head;
        while (i != n / 2)
        {
            sum = 0;
            sum += list2.top();
            sum += cur->val;
            if (sum > max)
                max = sum;

            if (cur->next == nullptr)
                break;

            cur = cur->next;
            list2.pop();

            i++;
        }

        return max;
    }
};

int main(int argc, char *argv[])
{
    ListNode *head = new ListNode();
    head->val = 5;
    ListNode *cur = head;
    //
    cur->next = new ListNode();
    cur = cur->next;
    cur->val = 4;

    cur->next = new ListNode();
    cur = cur->next;
    cur->val = 2;
    cur->next = new ListNode();
    cur = cur->next;
    cur->val = 1;
    cur = cur->next;

    {
        Solution w;
        w.pairSum(head);
    }
    return 0;
}