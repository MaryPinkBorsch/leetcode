// #include <unordered_map>
// #include <string>

// class Solution {
// public:
//     string decodeMessage(string key, string message)
//     {

//         unordered_map<char, char> cipher;
//         // используя клчи (буквы в кеу)  заполним хэш таблицу шифром
//         // соотнесем каждой букве в кеу букву алфавита
//         // пройдемся по мессаджу и расшифруем через хэш таблицу

//         int counter = 0;
//         cipher[' '] = ' ';
//         for(int i = 0; i < key.size(); i++)
//         {
//             if(cipher.find(key[i]) == cipher.end())
//             {
//                 cipher[key[i]] = 'a' + counter; // буква = число, поэтому мы начинаем присваивать от буквы а в англ и до конца
//                 counter++;
//             }
//         }

//         string res;
//         res.resize(message.size());
//         for(int i = 0; i <message.size(); i++)
//         {
//             res[i] = cipher[message[i]];
//         }
//         return res;

//     }
// };