// class Solution {
// public:
//     int mostWordsFound(vector<string>& sentences) 
//     {
//         int max = 0;
//         for(int i = 0; i < sentences.size(); i++)
//         {
//             int counter = 0;
//             for(int j = 0; j < sentences[i].size(); j++)
//             {
//                 if(sentences[i][j] == ' ')
//                     counter++;
//             }
//             if(counter>max)
//                 max = counter;

//         }
//         return max + 1; // так как мы считаем пробелы а кол-во слов = кол-во проблов +1
        
//     }
// };
