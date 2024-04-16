// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */

// class Solution {
// public:    
//     bool isPalindromeRecursive(ListNode* head, ListNode*& head_copy)
//     {
//         bool val = true;
//         if (head->next)
//         {
//             val &= isPalindromeRecursive(head->next, head_copy);
//         }
//         val &= head->val == head_copy->val;
//         head_copy = head_copy->next;
//         return val;
//     }
//     bool isPalindrome(ListNode* head)
//     {
//         ListNode* head_copy = head;
//         return isPalindromeRecursive(head, head_copy);
//     }
// };

// class Solution1 {
// public:

//     ListNode* makeReverseList(ListNode* head, ListNode*& prev) 
//     {
//         ListNode* newNode = new ListNode(head->val);
//         newNode->next = prev;
//         if (head->next) 
//         {
//             prev = newNode;
//             return makeReverseList(head->next, prev);
//         }
//         else 
//         {
//             return newNode;
//         }
//     }

//     bool check_lists_recursive(ListNode* head1, ListNode* head2) 
//     {
//         if (head1 && head2 && head1->val == head2->val) 
//         {
//             return check_lists_recursive(head1->next, head2->next);
//         }
//         else if ((head1 && !head2) || (head2 && !head1) || (head1 && head2 && (head1->val != head2->val)))
//             return false;
//         else // !head1 && !head2
//             return true;
//     }


//     bool isPalindrome(ListNode* head)
//     {
//         ListNode* prev = nullptr;
//         ListNode* rev_head = makeReverseList(head, prev);
//         return check_lists_recursive(head, rev_head);
//     }
// };