// class Solution {
// public:
//     bool canPlaceFlowers(vector<int>& flowerbed, int n) 
//     {
//         int c1=0; // считавем кол-во цветов которые можно посадитьб в клубку
//         int c2=1; // считаем кол-во подряд идущих пустых мест вв клубме

//         for(int i =0; i < flowerbed.size(); i++)
//         {
//             if(flowerbed[i] == 0)
//                 c2++;
//             else
//                 c2=0;
//             if(c2 == 3)
//             {
//                 c1++;
//                 c2=1;
//             }

//         }
//         if(c2==2)
//             c1++;

//         if(c1>=n)
//             return true;
//         else
//             return false;
//     }
// };

//https://leetcode.com/problems/can-place-flowers/description/