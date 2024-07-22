// class Solution2 {
// public:
//     vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
//     {
//         unordered_set <int> hset;
//         vector<int> C;
//         C.resize(A.size());
//         for(int i = 0; i < A.size(); i++)
//         {
//             hset.insert(A[i]);
//             hset.insert(B[i]);

//             C[i] = ( i + 1 )*2 - hset.size(); // ( i + 1 )*2 ===> если бы всеее
//             // элементы А отличались от всех элементов В
//             // hset.size() ---> кол-во элементов, которые есть или в А или в В 
//             // или в обоих (он хранит уникальные элементы)

//             // Т. о. их разница = кол-во элементов которые есть и в А и в В

//         }
//         return C;
//     }
// };



// // можно было создать массив частот, где отмечается сколько раз видели число в обоих массивах - если частота = 2 ---> res++
// //итого нашли кол-во повторяющихся чисел до I индекса вкл-но

// class Solution {
// public:
//     vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
//     {
//         vector<int> C;
//         vector<int> freq;
//         C.resize(A.size());
//         C[0] = 0;
//         freq.resize(A.size()+1);
//         for(int i = 0; i < A.size(); i++)
//         {
//             if(i>0)
//                 C[i] = C[i-1];
//             freq[A[i]]++;
//             if( freq[A[i]] == 2)
//                 C[i]++;

//             freq[B[i]]++;
//             if( freq[B[i]] == 2)
//                 C[i]++;
//         }
//         return C;

//     }

// };