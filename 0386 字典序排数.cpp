class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int i = 1;
        for (int j = 0;j<=8;j++){
            int cur = i+j;
            if (cur <= n){
                ans.push_back(cur);
                add0_9(ans, cur*10, n);
            }
            else
                break;
        }

        return ans;
    }

    void add0_9(vector<int> &ans, int i, int n){
        for (int j = 0;j<=9;j++){
            int cur = i+j;
            if (cur <= n){
                ans.push_back(cur);
                add0_9(ans, cur*10, n);
            }
            else
                break;
        }
    }
};