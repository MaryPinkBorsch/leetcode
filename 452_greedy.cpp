// class Solution {
// public:
//     Solution() {
//         std::ios_base::sync_with_stdio(false);
//         std::cin.tie(NULL);
//         std::cout.tie(NULL);
//     }
//     int findMinArrowShots(vector<vector<int>>& points) {
//         std::sort(points.begin(), points.end());
//          int res = 0;
//          // весь 1й шар заисали в пересечения
//          int start = points[0][0]; // начало пересечения 2х (или более) шариков
//          int end = points[0][1]; // конец пересечения
//          for (int i = 1; i < points.size(); ++i) 
//          {
//             if (points[i][0] > end) // нет пересечения текущего общего пересечения с Итым шаром
//             {
//                 ++res; // стреляем в все пересекающиеся до этого шары
//                 start = points[i][0]; // ставим новым общим пересечением текущий Итый шар
//                 end = points[i][1];
//             }
//             else 
//             {
//                 //сужаем общее пересечение так чтобы оно включало Итый шар
//                 start = std::max(start, points[i][0]);
//                 end = std::min(end, points[i][1]);
//                 // пересечение = общая часть у всех шаров до этого
//             }
//          }
//          return res+1; // последний выстрел для всех накопленных шаров
//     }
// };