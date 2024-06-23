//Find the Minimum Area to Cover All Ones I
//Leetcode 3195


class Solution {
    public int minimumArea(int[][] grid) {
        
        int minRow = 10000;
        int maxRow = -3;
        int minCol = 10000; 
        int maxCol = -3;

        int rows = grid.length;
        int cols = grid[0].length;


        for(int i = 0; i< rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j]==1){
                if(i<minRow) minRow = i;
                if(i>maxRow)maxRow=i;
                if(j<minCol)minCol=j;
                if(j>maxCol) maxCol = j;

                }
            }
        }

        int height = maxRow -minRow +1;
        int width = maxCol -minCol+1;

        return height*width;
    }
}
