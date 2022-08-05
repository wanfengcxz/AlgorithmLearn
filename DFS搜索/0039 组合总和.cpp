// 错误写法
// 思想：每次都会从candidates中选择一个数（可重复选）
// 最终会有很多重复的结果
class Solution {
public:

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        DFS(ans, vector<int>(), candidates, 0, target);
        return ans;
    }

    void DFS(vector<vector<int>> &ans, vector<int> curr, vector<int> & candidates, int curr_sum, int target, bool isSelect){
        for(auto v:candidates){
            vector<int> tmp = curr;
            tmp.push_back(v);
            if (curr_sum+v == target){
                ans.push_back(tmp);
                return ;
            } else if (curr_sum+v < target){
                DFS(ans, tmp, candidates, curr_sum+v, target);
            } else {
                return ;
            }
        }
    }
};


/*
我的题解 192ms 官方4ms
相比于官方，我的题解可以优化的地方有：
1. 通过引用的方式来保存中间结果，减少了传参浪费的大量时间。每次传参重新拷贝一个vector然后再进行push_back可能会引起
重新分配内存来扩容，多次递归会重复扩容，耗费大量时间。因此采取引用的方式，内存不够时，进行扩容，接下来一段时间内
不会再扩容，然而对于新增的pop_back操作，耗费时间相比起来极少。
2. 通过target-candidates[idx]>=0来控制如果当前选择达标，才开启递归，而不是开启递归后再判断是否达标，节省了时间
3. push_back可以改用emplace_back
*/
class Solution {
public:

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        DFS(ans, vector<int>(), candidates, 0, target);
        return ans;
    }

    void DFS(vector<vector<int>> &ans, vector<int> curr, vector<int> & candidates, int idx, int target){
        if (idx == candidates.size())
            return;
        if (target == 0){
            ans.push_back(curr);
            return ;
        }
        if (target < 0)
            return ;
        DFS(ans, curr, candidates, idx+1, target);
        curr.push_back(candidates[idx]);
        DFS(ans, curr, candidates, idx,target-candidates[idx]);
    }
};

// 官方4ms
class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int idx) {
        if (idx == candidates.size()) {
            return;
        }
        if (target == 0) {
            ans.emplace_back(combine);
            return;
        }
        // 直接跳过
        dfs(candidates, target, ans, combine, idx + 1);
        // 选择当前数
        if (target - candidates[idx] >= 0) {
            combine.emplace_back(candidates[idx]);
            dfs(candidates, target - candidates[idx], ans, combine, idx);
            combine.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        dfs(candidates, target, ans, combine, 0);
        return ans;
    }
};