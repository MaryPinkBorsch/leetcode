// class Solution {
// public:
//     int findContentChildren(vector<int>& g, vector<int>& s) 
//     {
//         sort(g.begin(), g.end());
//         sort(s.begin(), s.end());

//         int p1 =0;
//         int p2=0;
//         int res=0;

//         while(p1<g.size())
//         {
//             while(p2<s.size() && s[p2]<g[p1])
//             {
//                 p2++;
//             }
//             if(p2==s.size())
//                 return res;
//             else
//             {
//                 res++;
//                 p1++;
//                 p2++;
//             }

//         }
//         return res;
        
//     }
// };