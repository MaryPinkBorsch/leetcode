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
//     ListNode* removeElements_rekursia(ListNode* head, int val, ListNode* prev)
//     {
//         // чтобы работала эта функция нужно сделать две вещи
//         // 1) рекурсивно вызвать себя же (возможно не один раз)
//         // 2) решить что возвращать в зависимости от каких условий
//         if(head==nullptr)
//             return nullptr;

        
//         if(head->val == val)
//         {
//            ListNode* tmp = head->next;
//            delete head;
//            head = 0;
//            if(prev)
//             prev->next = tmp;  
//             return removeElements_rekursia(tmp,val,prev);
//         }
//         else
//         {
//             prev = head;            
//             removeElements_rekursia( head->next,val,prev);
//             return head;
//         }       
//     }

//     ListNode* removeElements(ListNode* head, int val)
//     {

//        return removeElements_rekursia( head,val,nullptr);
        
//     }
// };