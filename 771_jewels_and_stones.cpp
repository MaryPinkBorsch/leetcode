// class Solution {
// public:
//     int numJewelsInStones(string jewels, string stones) 
//     {
//         int res = 0;
//         for(int i = 0; i < stones.size(); i++)
//         {
//             for(int j = 0; j < jewels.size(); j++)
//             {
//                 if(stones[i] == jewels[j])
//                 {
//                     res++;
//                     break;
//                 }
                   
//             }
//         }
//         return res;
//     }
// };


#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) 
    {
        // int res = 0;
        // for(int i = 0; i < stones.size(); i++)
        // {
        //     for(int j = 0; j < jewels.size(); j++)
        //     {
        //         if(stones[i] == jewels[j])
        //         {
        //             res++;
        //             break;
        //         }                   
        //     }
        // }
        
        std::unordered_set<char> jewels_set;
        for(int j = 0; j < jewels.size(); j++)
        {
           jewels_set.insert(jewels[j]);                 
        }
        int res = 0;

        for(int i = 0; i < stones.size(); i++)
        {
            if(jewels_set.find(stones[i]) != jewels_set.end())
                res++;
            // пытались найти наш камень в драгоценных камнях
            //если не вернут итератор конца то значит нашли такой джевел

        }
        return res;
    }
};