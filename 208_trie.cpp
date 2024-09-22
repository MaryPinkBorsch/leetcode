// class Trie {
// public:
//     Trie() {
        
//     }

//     struct TrieNode 
//     {
//         unordered_map <char, TrieNode*> children;
//         bool konez = false; // конец слова отмечается мной через флаг
        
//     };


//     TrieNode root;
    
//     void insert(string word) 
//     {
//         TrieNode * cur = &root;
//         for(int i =0; i < word.size(); i++)
//         {
//             auto it =cur->children.find(word[i]);
            
//             if(it == cur->children.end()) // если мы ne нашли букву
//             {
//                 cur->children[word[i]] = new TrieNode;
//             }
//             cur=cur->children[word[i]]; // cur = cur->next по нужной букве
//             if(i==word.size()-1)
//                 cur->konez = true;
//         }
        
//     }
    
//     bool search(string word) 
//     {
//         TrieNode * cur = &root;
//         for(int i =0; i < word.size(); i++)
//         {
//             auto it =cur->children.find(word[i]);
            
//             if(it == cur->children.end()) // если мы ne нашли букву
//             {
//                 return false;
//             }
//             cur=cur->children[word[i]]; // cur = cur->next по нужной букве

//             if(i==word.size()-1 && cur->konez==1)
//                 return true;
//         }
//         return false;
//     }
    
//     bool startsWith(string word) 
//     {
//         TrieNode * cur = &root;
//         for(int i =0; i < word.size(); i++)
//         {
//             auto it =cur->children.find(word[i]);
            
//             if(it == cur->children.end()) // если мы ne нашли букву
//             {
//                 return false;
//             }
//             cur=cur->children[word[i]]; // cur = cur->next по нужной букве
//         }
//         return true;

        
//     }
// };

// /**
//  * Your Trie object will be instantiated and called as such:
//  * Trie* obj = new Trie();
//  * obj->insert(word);
//  * bool param_2 = obj->search(word);
//  * bool param_3 = obj->startsWith(prefix);
//  */

// + ре9шение папы в лкоде

//https://leetcode.com/problems/implement-trie-prefix-tree/description/