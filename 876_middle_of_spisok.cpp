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
//     ListNode* middleNode(ListNode* head) 
//     {
//         ListNode* kot = head;
//         ListNode* ulitka = head;
//         while(kot != nullptr)
//         {   kot = kot->next;
//             if(kot == 0)
//              break;
//             ulitka = ulitka->next;
            
//             if(kot != nullptr)
//             {
//                 kot = kot->next;
//             }
//         }
//         return ulitka;
//     }
// };