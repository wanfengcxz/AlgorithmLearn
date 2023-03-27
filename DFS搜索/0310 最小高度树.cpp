// 暴力DFS n=5001超时
class Solution {
public:
    unordered_map<int, vector<int>> all;

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        for(vector<int> tmp:edges){
            all[tmp[0]].emplace_back(tmp[1]);
            all[tmp[1]].emplace_back(tmp[0]);
        }

        vector<int> ans;
        int min_height = 9999999;
        for(int i = 0;i<n;i++){
            vector<bool> isVisited(n ,false);
            int height = 0;
            dfs(i, 0, height, isVisited);
            if (height == min_height)
                ans.emplace_back(i);
            if (height < min_height){
                min_height = height;
                ans.clear();
                ans.emplace_back(i);
            }
        }
        return ans;

    }

    void dfs(int root, int curr_height, int &height, vector<bool> &isVisited){
        isVisited[root] = true;
        vector<int> &ajdEdges = all[root];
        bool isEnd = true;
        for(auto v:ajdEdges){
            if (!isVisited[v]){
                isEnd = false;
                dfs(v, curr_height+1, height, isVisited);
            }
        }
        // 访问到叶子结点
        if (isEnd){
            if (curr_height > height)
                height = curr_height;
        }
    }
};

// 加入剪枝进行优化 n=10002超时
class Solution {
public:
    unordered_map<int, vector<int>> all;

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        for(vector<int> tmp:edges){
            all[tmp[0]].emplace_back(tmp[1]);
            all[tmp[1]].emplace_back(tmp[0]);
        }

        vector<int> ans;
        int min_height = 9999999;
        for(int i = 0;i<n;i++){
            vector<bool> isVisited(n ,false);
            int height = 0;
            dfs(i, 0, height, isVisited, min_height);
            if (height == min_height)
                ans.emplace_back(i);
            if (height < min_height){
                min_height = height;
                ans.clear();
                ans.emplace_back(i);
            }
        }
        return ans;

    }

    void dfs(int root, int curr_height, int &height, vector<bool> &isVisited, int &min_height){
        if (min_height < curr_height){
            height = curr_height;
            return ;
        }
        isVisited[root] = true;
        vector<int> &ajdEdges = all[root];
        bool isEnd = true;
        for(auto v:ajdEdges){
            if (!isVisited[v]){
                isEnd = false;
                dfs(v, curr_height+1, height, isVisited, min_height);
            }
        }
        // 访问到叶子结点
        if (isEnd){
            if (curr_height > height)
                height = curr_height;
        }
    }
};