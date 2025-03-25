// https://leetcode.com/problems/flood-fill/description/

/*
You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.
*/



class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color)
            return image;
        
        int m = image.size();
        int n = image[0].size();
        
        stack<pair<int, int>> s;

        s.push({sr, sc});

        int xCor[4] = {-1, 1, 0, 0};
        int yCor[4] = {0, 0, -1, 1};

        int c = image[sr][sc];

        while(!s.empty())
        {
            int x = s.top().first;
            int y = s.top().second;

            s.pop();

            image[x][y] = color;

            for(int i=0; i<4; i++)
            {
                int newX = x + xCor[i];
                int newY = y + yCor[i];

                if(newX>=0 && newX<m && newY>=0 && newY<n && image[newX][newY] == c)
                {
                    s.push({newX, newY});
                }
            }
        }

        return image;
    }
};
