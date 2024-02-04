// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     bool hasCycle(ListNode *head)
//     {
//         ListNode * Zayaz = head;
//         ListNode * Cherepaha = head;

//          if (head == 0)
//             return false;


//         while(true)
//         {
           
//             if (Zayaz->next == 0 || Zayaz->next->next == nullptr || Cherepaha->next == 0)
//                 return false;

//             Zayaz = Zayaz->next->next;
//             Cherepaha = Cherepaha->next;     

//             if (Zayaz == Cherepaha)
//                 return true;
//         }        
//     }
// };