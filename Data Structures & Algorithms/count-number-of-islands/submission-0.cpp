class Solution {
public:
    void counter(vector<vector<char>>&grid,vector<vector<bool>>&checker,int i,int j,int count){
      if(i>=grid.size()||i<0||j>=grid[0].size()||j<0){
        return;
      }
      if(grid[i][j]=='1'&&checker[i][j]==false){
        checker[i][j]=true;
       }
       else{
        return;
       }
       counter(grid,checker,i+1,j,count);
       counter(grid,checker,i-1,j,count);
       counter(grid,checker,i,j+1,count);
       counter(grid,checker,i,j-1,count);    
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>>checker(grid.size(),vector<bool>(grid[0].size(),false));
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'&&checker[i][j]==false){
                    counter(grid,checker,i,j,count);
                    count++;
                }
            }
        }
        return count;
    }
};
