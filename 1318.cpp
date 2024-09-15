// class Solution {
// public:
//     int minFlips1(int a, int b, int c) //папина версия
//     {
//         int ored = a | b;
//         int anded = a & b;
//         int xored = ored ^ c;
//         return __builtin_popcount(xored) + __builtin_popcount(xored & anded);
//     }
//     void int_to_array(int x, vector<int>& arr_x) 
//     {
//         for (int i = 0; i < 32; ++i) 
//         {
//             // 1 << i => сдвигаеися на Итый бит и через побитовое И узнаем что на Итой позиции у числа х
//             if (x & (1 << i)) // выставлен ли i-тый бит в числе x
//                 arr_x[i] = 1;
//             else
//                 arr_x[i] = 0;
//         }
//     }
//     int minFlips(int a, int b, int c) //масина версия
//     {
//         vector<int> arr_a;
//         vector<int> arr_b;
//         vector<int> arr_c;

//         arr_a.resize(32);
//         arr_b.resize(32);
//         arr_c.resize(32);
//         int res = 0;
        
//         int_to_array(a, arr_a);
//         int_to_array(b, arr_b);
//         int_to_array(c, arr_c);

//         for (int i = 0; i < 32; ++i) 
//         {
//             if(arr_c[i]==0)
//             {
//                 if(arr_a[i]!=0)
//                     res++;
//                 if(arr_b[i]!=0)
//                     res++;
//             }
//             else
//             {
//                 if(arr_a[i]!=1 && arr_b[i]!=1)
//                     res+=1;
//             }
//         }
//         return res;
//     }
// };