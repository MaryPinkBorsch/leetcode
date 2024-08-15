
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
    ListNode *deleteMiddle(ListNode *head)
    {
        ListNode *cur = head;
        if (!cur)
            return nullptr;

        int n = 0;
        int i = 0;
        while (cur != 0)
        {
            n++;
            if (cur->next == 0)
                break;
            cur = cur->next;
        }
        if(n==1)
            return nullptr;
        cur = head;
        while (i != (n / 2) - 1)
        {
            i++;
            cur = cur->next;
        }
        ListNode *tmp = cur->next->next;

        delete cur->next;
        cur->next = tmp;

        return head;
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
    cur = cur->next;

    {
        Solution w;
        w.deleteMiddle(head);
    }
    return 0;
}