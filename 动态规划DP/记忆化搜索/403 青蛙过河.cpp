// DFS 暴力搜索 超时
class Solution {
public:
    unordered_map<int, int> map;

    bool canCross(vector<int>& stones) {
        for(int i=0;i<stones.size();i++)
            map[stones[i]] = i;
        if (map.count(1) <= 0)
            return false;
        return DFS(stones, 1, 1);
    }   

    bool DFS(vector<int>&stones, int i, int pre_step){
        if (i == stones.size()-1) return true;
        for(int k = -1;k<=1;k++){
            int step = pre_step + k;
            if (step == 0)
                continue;
            int next = stones[i]+step;
            if (map.count(next) > 0){
                bool tmp = DFS(stones, map[next], step);
                if (tmp) return true;
            }
        }
        return false;
    }
};

// 记忆化搜索（带备忘录版本） 版本1
class Solution {
public:
    unordered_map<int, int> map;

    bool canCross(vector<int>& stones) {
        int size = stones.size();
        vector<unordered_map<int, bool>> dp(size, unordered_map<int, bool>());
        for(int i=0;i<stones.size();i++)
            map[stones[i]] = i;
        if (map.count(1) <= 0)
            return false;
        return DFS(stones, 1, 1, dp);
    }   

    bool DFS(vector<int>&stones, int i, int pre_step, vector<unordered_map<int, bool>> &dp){
        if (i == stones.size()-1) return true;
        for(int k = -1;k<=1;k++){
            int step = pre_step + k;
            if (step == 0)
                continue;
            int next = stones[i]+step;
            if (map.count(next) > 0){
                bool tmp;
                if (dp[map[next]].count(step)>0)
                    tmp = dp[map[next]][step] == true;
                else{
                    tmp = DFS(stones, map[next], step, dp);
                    dp[map[next]][step] = tmp;
                }
                if (tmp) return true;
            }

        }
        return false;
    }
};

// 记忆化搜索（带备忘录版本） 版本1
class Solution {
public:
    unordered_map<int, int> map;

    bool canCross(vector<int>& stones) {
        int size = stones.size();
        vector<unordered_map<int, bool>> dp(size, unordered_map<int, bool>());
        for(int i=0;i<stones.size();i++)
            map[stones[i]] = i;
        if (map.count(1) <= 0)
            return false;
        return DFS(stones, 1, 1, dp);
    }   

    bool DFS(vector<int>&stones, int i, int pre_step, vector<unordered_map<int, bool>> &dp){
        if (i == stones.size()-1) return true;
        if (dp[i].count(pre_step))
            return dp[i][pre_step];
        for(int k = -1;k<=1;k++){
            int step = pre_step + k;
            if (step == 0)
                continue;
            int next = stones[i]+step;
            if (map.count(next) > 0){
                bool tmp = DFS(stones, map[next], step, dp);
                if (tmp) {
                    dp[i][pre_step] = true;
                    return true;
                }
            }
        }
        dp[i][pre_step] = false;
        return false;
    }
};