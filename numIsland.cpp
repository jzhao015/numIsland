class Solution {
public:
    int result=0;
    void island(vector<vector<char>>& grid,int i,int j,int n,int m){
        if(i<0 ||i==n||j<0||j==m) // check if the grid is at boundry. 
        return;
 //check if the grid are traversed(when it's equal to 2) or not yet(when it's equal to 1)
        if(grid[i][j]=='0' || grid[i][j]=='2') 
            return;
        grid[i][j]='2'; //2 represents the island has been traversed. 
        // recursively go through all the directions. 
        island(grid,i,j-1,n,m);  //goes to left
        island(grid,i,j+1,n,m);  //goes to right
        island(grid,i-1,j,n,m);  //top
        island(grid,i+1,j,n,m);  //down
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //loop through the grid. 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //if encounter one, then increase the result and mark the island to 2. 
                if(grid[i][j]=='1'){ 
                result++;
                island(grid,i,j,n,m);
                }
            }
        }
        return result;
    }
};
