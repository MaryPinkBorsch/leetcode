// class Solution {
// public:
//     unordered_map <int, int> hash_cash; 
//     int fib(int n) 
//     {        
//         if(n==0)
//             return 0;

//         if(n==1)
//             return 1;

//         if (hash_cash.find(n) == hash_cash.end())  // запоминаем промежуточные значения фибогаччи
                                                    //       чтоб не вычислять их повторно!
//         {
//             auto val = fib(n-1) + fib(n-2);
//             hash_cash[n] = val;
//             return val;
//         }
//         else
//             return hash_cash[n];
//     }
// };

// // cache 
// // fib(4) ==
// //    (fib(3) + fib(2)) ==
// // ((fib(2) + fib(1)) + (fib(1) + fib(0))) == 
// // (((fib(1)+fib(0))) + fib(1)) + (fib(1) + fib(0))) == 





// class Solution {
// public:
//     unordered_map<int, int> hash_cash;
//     int climbStairs(int n) {
//         if (n == 0)
//             return 0;

//         if (n == 1)
//             return 1;
//         if (n == 2)
//             return 2;
//         if (hash_cash.find(n) == hash_cash.end()) {
//             auto val = climbStairs(n - 1) + climbStairs(n - 2);
//             hash_cash[n] = val;
//             return val;
//         } else
//             return hash_cash[n];
//     }
// };