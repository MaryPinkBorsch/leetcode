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
// int gcd(int a, int b) {
//         // Find Minimum of a and b
//         int result = min(a, b);
//         while (result > 0) 
//         {
//             if (a % result == 0 && b % result == 0) 
//             {
//                 break;
//             }
//             result--;
//         }

//         // Return gcd of a and b
//         return result;
//     }

//     ListNode* insertGreatestCommonDivisors(ListNode* head)
//     {
//         ListNode* cur = new ListNode;
//         cur = head;
//         while(cur->next!=nullptr)
//         {
//             ListNode* tmp;
//             tmp = cur->next;

//             int a = cur->val;
//             int b = cur->next->val;
//             int c =gcd(a,b);
//             ListNode* add = new ListNode;
//             add->val = c;
            
//             cur->next = add;
//             add->next = tmp;
//             // delete tmp;

//             cur = tmp;

//         }
//         return head;
//     }

// };