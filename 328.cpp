
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
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == 0)
            return nullptr;
        ListNode *head2 = new ListNode(head->val);
        ListNode *cur = head;
        head2->next = new ListNode;
        ListNode *cur2 = head2->next;
        int i = 1;
        if (head->next == nullptr)
            return head;
        cur = cur->next;
        int n = 0;
        while (cur != nullptr)
        {
            if (i % 2 == 0)
            {
                // cur2 = new ListNode;
                cur2->val = cur->val;
                cur2->next = new ListNode;
                cur2 = cur2->next;
            }
            i++;
            n++;
            if (cur->next == 0)
                break;

            cur = cur->next;
        }
        i = 0;
        cur = head;
        while (cur != nullptr)
        {
            if (i % 2 != 0)
            {
                // cur2 = new ListNode;
                cur2->val = cur->val;
                if (i == n - 1 || cur->next == nullptr)
                    break;
                cur2->next = new ListNode;
                cur2 = cur2->next;
            }
            i++;
            if (cur->next == 0)
                break;

            cur = cur->next;
        }
        // if (cur2->val == 0)
        //     cur2 = nullptr;
        return head2;
    }
};

int main(int argc, char *argv[])
{
    ListNode *head = new ListNode();
    head->val = 1;
    ListNode *cur = head;
    //
    cur->next = new ListNode();
    cur = cur->next;
    cur->val = 2;

    cur->next = new ListNode();
    cur = cur->next;
    cur->val = 3;

    cur->next = new ListNode();
    cur = cur->next;
    cur->val = 4;

    cur->next = new ListNode();
    cur = cur->next;
    cur->val = 5;

    {
        Solution w;
        w.oddEvenList(head);
    }
    return 0;
}

// https://leetcode.com/problems/odd-even-linked-list/?envType=study-plan-v2&envId=leetcode-75