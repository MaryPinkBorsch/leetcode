// class Solution {
// public:
// Solution() // ЧИТ ДЛЯ СКОРОСТИ!!!!!!!!
//      {
//          ios_base::sync_with_stdio(false);
//          cin.tie(NULL);
//          cout.tie(NULL);
//      } 
//     bool canVisitAllRooms(vector<vector<int>>& rooms) 
//     {
//         vector<int> front; // типо уже открытые комнаты
//         vector<int> visited; // обозначим посещали ли мы эту комнату
//         visited.resize(rooms.size(), 0);
        
//         front.push_back(0); // дедлаем не пустым фронт (внутри нуль)
//         while(!front.empty()) // не забыть это условие выхода!
//         {
//             vector<int> next_front;
//             for(int i =0; i < front.size(); i++) // смотрим какие есть в распоряжении комнаты
//             {
//                 if(visited[front[i]]==1) // уже были в комнате
//                     continue;
//                 else
//                 {
//                     visited[front[i]]=1;

//                     for(int j =0; j < rooms[front[i]].size(); j++)   // идем по ключам в только что открытой комнате
//                     {
//                         if( visited[rooms[front[i]][j]] ==0) // берем текущий ключ и пытаемся узнать, были ли мы в той комнате уже
//                             next_front.push_back(rooms[front[i]][j]); // добавляем ключ к новой комнате в некст фронт
                        
//                     }

//                 }
//             }
//             front = next_front; // обязательно для БФС BFS
            
//         }
//         for(int i =0; i < visited.size(); i++)
//         {
//             if(visited[i]==0)
//                 return false;
//         }
//         return true;

//     }
// };

//https://leetcode.com/problems/keys-and-rooms/description/?envType=study-plan-v2&envId=leetcode-75