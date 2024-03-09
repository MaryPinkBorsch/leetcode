#include <vector>
#include <unordered_set>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution2
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        vector<ListNode *> stack_A;
        vector<ListNode *> stack_B;
        ListNode *curA = headA;
        ListNode *curB = headB;

        while (curA != nullptr)
        {
            stack_A.push_back(curA);
            curA = curA->next;
        }
        while (curB != nullptr)
        {
            stack_B.push_back(curB);
            curB = curB->next;
        }
        ListNode *res = nullptr;
        while (stack_A.back() == stack_B.back() && (stack_A.empty() == false) && (stack_B.empty() == false))
        {
            res = stack_A.back();
            stack_A.pop_back();
            stack_B.pop_back();
        }
        if ((stack_A.empty() || stack_B.empty()) && res == nullptr)
        {
            return nullptr;
        }
        else
            return res;
    }
};

class Solution1
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *curA = headA;
        while (curA != nullptr)
        {
            ListNode *curB = headB;
            while (curB != nullptr)
            {
                if (curA == curB)
                    return curA;

                curB = curB->next;
            }
            curA = curA->next;
        }
        return nullptr;
    }
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> uniq_ptr;
        ListNode *curA = headA;
        ListNode *curB = headB;
        ListNode *res = nullptr;
        while (curA != nullptr || curB != nullptr)
        {
            if (curA != nullptr)
            {
                if (uniq_ptr.insert(curA).second == false)
                    return curA; // инсерт в унордеред сет возвращает пару
                                 // итератор и булл
                // если булл == ложь то такой элемент уже встречался в сете
                // (пересечение!)
                curA = curA->next;
            }
            if (curB != nullptr)
            {
                if (uniq_ptr.insert(curB).second == false)
                    return curB; // инсерт в унордеред сет возвращает пару
                                 // итератор и булл
                // если булл == ложь то такой элемент уже встречался в сете
                // (пересечение!)
                curB = curB->next;
            }
        }
        return nullptr;

        return res;
    }
};

int main(int argc, char *argv[])
{
    {
        ListNode *ListA = new ListNode(4);
        ListA->next = new ListNode(1);

        ListNode *ListB = new ListNode(5);
        ListB->next = new ListNode(6);
        ListB->next->next = new ListNode(1);

        ListNode *ListC = new ListNode(8);
        ListC->next = new ListNode(4);
        ListC->next->next = new ListNode(5);

        ListB->next->next->next = ListC;
        ListA->next->next = ListC;

        Solution1 tmp;
        auto res = tmp.getIntersectionNode(ListA, ListB);
    }

    {
        ListNode *ListC = new ListNode(1);
        ListNode *ListA = ListC;
        ListNode *ListB = ListC;

        Solution2 tmp;
        auto res = tmp.getIntersectionNode(ListA, ListB);
    }

    return 0;
}