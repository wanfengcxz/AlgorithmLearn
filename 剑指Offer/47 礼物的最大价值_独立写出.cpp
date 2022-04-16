// x,y
// f(x,y) = max(f(x-1,y), f(x,y-1))+f(x,y)
// 如果矩阵过大会超时
// 重复求值了
// 可以使用矩阵进行保存中间值
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 1;i<m;i++){
            grid[i][0] += grid[i-1][0];
        }    
        for (int i = 1;i<n;i++){
            grid[0][i] += grid[0][i-1];
        }
        return maxValueRecursion(grid,m-1, n-1);
    }

    int maxValueRecursion(vector<vector<int>>& grid, int x, int y){
        if (x==0 || y==0)
            return grid[x][y];
        else{
            int maxValue = max(maxValueRecursion(grid, x-1, y),maxValueRecursion(grid, x, y-1));
            return grid[x][y]+maxValue;
        }
    }
};

// 正解
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // 先计算上边缘和左边缘的最大价值
        for (int i = 1;i<m;i++){
            grid[i][0] += grid[i-1][0];
        }    
        for (int i = 1;i<n;i++){
            grid[0][i] += grid[0][i-1];
        }  
        for (int i = 1;i<m;i++){
            for (int j = 1;j<n;j++){
                grid[i][j] = max(grid[i-1][j], grid[i][j-1])+grid[i][j];
            }
        }
        return grid[m-1][n-1];
    }
};