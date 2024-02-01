/**
 * Definition for singly-linked list.*/
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
/**/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* list3 = nullptr;

        if(list1 == nullptr && list2 == nullptr)
        {
            return list3;
        }
        if(list1 != nullptr && list2 == nullptr)
        {
            return list1;
        }
        if(list1 == nullptr && list2 != nullptr)
        {
            return list2;
        }

        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        ListNode res;
        ListNode* cur3 = &res;
        //list3->val = list1->val < list2->val ? list1->val : list2->val;
        while(cur1 != nullptr && cur2 != nullptr)
        {     
            cur3->next = new ListNode;
            if (cur1->val <= cur2->val)
            {
                cur3->next->val = cur1->val;
                cur1 = cur1->next;
            }
            else
            {
                cur3->next->val = cur2->val;
                cur2 = cur2->next;
            }
            cur3 = cur3->next;
        }
        if(cur1 != nullptr && cur2 == nullptr)
        {
           while(cur1 != nullptr)
           {
                cur3->next = new ListNode;
                cur3->next->val = cur1->val;
                cur1 = cur1->next;
                cur3 = cur3->next;
           }
        }

        if(cur2 != nullptr && cur1 == nullptr)
        {
           while(cur2 != nullptr)
           {
                cur3->next = new ListNode;
                cur3->next->val = cur2->val;
                cur2 = cur2->next;
                cur3 = cur3->next;
           }
        }
        return res.next;
    }
};

int main(int argc, char* arg[]) 
{
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    Solution wtf;
    ListNode * merged = wtf.mergeTwoLists(list1, list2);
    return 0;
}