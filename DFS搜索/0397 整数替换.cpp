// 最原版
class Solution {
public:
    int integerReplacement(int n) {
        int min_num = 9999;
        dfs(min_num, n, 0);
        return min_num;
    }

    void dfs(int &min_num, int n, int curr_num){
        if (curr_num < min_num){
            if (n == 1){
                min_num = curr_num;
                return ;
            }
        } else
            return ;
        if (n%2 == 0)
            dfs(min_num, n/2, curr_num+1);
        else {
            dfs(min_num, n+1, curr_num+1);
            dfs(min_num, n-1, curr_num+1);
        }
    }
};

// 增加47-51 防止n溢出 将n/2改为n>>1
class Solution {
public:
    int integerReplacement(int n) {
        int min_num = 9999;
        dfs(min_num, n, 0);
        return min_num;
    }

    void dfs(int &min_num, int n, int curr_num){
        if (curr_num < min_num){
            if (n == 1){
                min_num = curr_num;
                return ;
            }
        } else
            return ;
        if (n%2 == 0)
            dfs(min_num, n/2, curr_num+1);
        else {
            if (n == 2147483647){
                dfs(min_num, n>>1, curr_num+2);
                dfs(min_num, n>>1+1, curr_num+2);
                return ;
            }
            dfs(min_num, n+1, curr_num+1);
            dfs(min_num, n-1, curr_num+1);
        }
    }
};

// 
class Solution {
public:

    int integerReplacement(int n) {
        if (n == 1)
            return 0;
        if (n%2 == 0)
            return 1+integerReplacement(n>>1);
        else{
            return 2+min(integerReplacement(n/2+1), integerReplacement(n/2));
        }

    }

};

// 记忆化搜索 把递归中重复计算的数据记录下来
class Solution {
public:
    unordered_map<int, int> memo;

    int integerReplacement(int n) {
        if (n == 1)
            return 0;
        if (memo.count(n) > 0)
            return memo[n];
        if (n%2 == 0){
            memo[n] = 1+integerReplacement(n>>1);
            return memo[n];
        }
        else{
            memo[n] = 2+min(integerReplacement(n/2+1), integerReplacement(n/2));
            return memo[n];
        }

    }

};