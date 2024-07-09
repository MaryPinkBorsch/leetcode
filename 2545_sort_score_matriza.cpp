// class Solution {
// public:
//     vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) 
//     {   
//         int prev_max = 100001;
       
//         vector<vector<int>> res;
//         res.resize(score.size());
//         for (int j =0;  j < score.size(); j++)
//         { 
           
//             int max = 0;
//             int m_idx = -1;
//             for (int i =0;  i < score.size(); i++)
//             {
//                 if(score[i][k]>max && score[i][k]<prev_max)
//                 {
//                     max = score[i][k];
//                     m_idx = i;
//                 }        

//             }
//             prev_max = max;
//             res[j].resize(score[m_idx].size());
//             for(int n =0; n < score[m_idx].size(); n++)
//             {
//                 res[j][n] = score[m_idx][n];
//             }
//         }
//         return res;
//     }
// };

// https://leetcode.com/problems/sort-the-students-by-their-kth-score/


//bonus

// class Solution1 {
// public:
//     vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) 
//     {
//         std::sort( score.begin(), score.end(), [&](const vector<int> & lhs, const vector<int> & rhs) {  return lhs[k] > rhs[k]; } );
//         return score;
//     }
// };