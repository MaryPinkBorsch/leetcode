// class Solution {
// public:
//     Solution() {
//         std::ios_base::sync_with_stdio(false);
//         std::cin.tie(NULL);
//         std::cout.tie(NULL);
//     }
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         vector<int> res;
//         const int num_temps = temperatures.size();
//         res.resize(num_temps);
//         std::stack<int> colder_days;
//         int i = 0;
//         while (i < num_temps) 
//         {
//             //  если стек более холодных дней пуст
//             //или текущий день еще холоднее предыдущего самого холодного дня
//             //кладем в стек его  и и++ - увеличиваем счетчик дней
//             if (colder_days.empty() || temperatures[i] <= temperatures[colder_days.top()]) 
//             {
//                 colder_days.push(i);
//                 i++;
//             }
//             else 
//             {
//                 //запишем что для предыдущего самого холодного дня (вершина стека) кол-во дней до потепления это И (счетчик) минус вершина стека (номер самого холодного дня)  
//                 res[colder_days.top()] = i - colder_days.top();
//                 colder_days.pop();
//                 // И не ++, таким образом подряд идущие холодные дни (текущий их теплее) будут записываться ответ в рез
//             }
//         }
//         return res;
//     }
// };