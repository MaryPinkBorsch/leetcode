
// struct pair_hash {
//     template <class T1, class T2>
//     std::size_t operator () (const std::pair<T1,T2> &p) const {
//         auto h1 = std::hash<T1>{}(p.first);
//         auto h2 = std::hash<T2>{}(p.second);

//         // Mainly for demonstration purposes, i.e. works but is overly simple
//         // In the real world, use sth. like boost.hash_combine
//         return h1 ^ h2;  
//     }
// };

// class Solution {
// public:

//     unordered_map <pair<int,int>, int, pair_hash> memo; //хурма для мемоизации
//     int uniquePaths(int m, int n) 
//     {
//         if (memo[{m,n}] != 0)
//             return memo[{m,n}];

//         int res = 0;
//         if (m == 1 && n == 1)
//             return 1;
//         if (m-1 > 0)
//             res += uniquePaths(m-1, n);
//         if (n-1 > 0)
//             res += uniquePaths(m, n-1);
        
//         memo[{m,n}] = res;
//         return res;
//     }
// };

// int main(int argc, char * argv[]) 
// {
//     Solution omg;
//     int res = omg.uniquePaths(3,2);
//     return res;
// }

//https://leetcode.com/problems/unique-paths/