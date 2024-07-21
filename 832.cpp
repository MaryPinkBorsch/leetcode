// class Solution {
// public:
//     vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) 
//     {
//         for(int i=0; i < image.size(); i++)
//         {
//             for(int j =0; j< image[i].size()/2; j++)
//             {
//                 swap(image[i][j], image[i][image.size() - 1 - j]);
//                 if( image[i][j]==0)
//                     image[i][j] = 1;
//                 else
//                     image[i][j] = 0;


//                 if( image[i][image.size() - 1 - j]==0)
//                     image[i][image.size() - 1 - j] = 1;
//                 else
//                     image[i][image.size() - 1 - j] = 0;
//             }


//             if(image.size() % 2 != 0)
//             {
//                 if( image[i][image[i].size()/2 ]==0)
//                     image[i][image[i].size()/2 ] = 1;
//                 else
//                     image[i][image[i].size()/2 ] = 0;
//             }
//         }
        
//         return image;
//     }
// };

//https://leetcode.com/problems/flipping-an-image/