// 模拟 空间复杂度O(n)
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> c_index;
        for (int i = 0;i<s.size();i++)
            if (c == s[i])
                c_index.push_back(i);

        int j = 0;
        int i = 0;
        int tmp;
        int index_size = c_index.size();
        vector<int> ans;
        // 0和最后一个 分开讨论
        // j = 0
        while(i<=c_index[j]){
            ans.push_back(c_index[j]-i);
            i++;
        }
        j++;
        for (;j!=index_size;){
            if (i<=c_index[j]){
                tmp = (c_index[j]-i)>(i-c_index[j-1])?(i-c_index[j-1]):(c_index[j]-i);
                ans.push_back(tmp);
                i++;
            }
            else
                j++;
        }
        // 最后一个
        while(i<s.size()){
            ans.push_back(i-c_index[j-1]);
            i++;
        }
        return ans;
    }
};

// 正反遍历
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int size = s.size();
        vector<int> ans = vector<int>(size, size);
        
        int last = -size;
        for(int i = 0;i<size;i++){
            if (s[i] == c){
                ans[i] = 0;
                last = i;
            } else {
                ans[i] = min(ans[i], i-last);
            }
        }

        last = 2*size;
        for(int i = size-1;i>=0;i--){
            if (s[i] == c)
                last = i;
            else
                ans[i] = min(ans[i], last-i);
        }
        return ans;
    }
};