// 栈
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> star;
        stack<int> left;

        for(int i = 0;i<s.size();i++){
            if (s[i] == '(')
                left.push(i);
            else if (s[i] == ')'){
                if (!left.empty()){
                    left.pop();
                }else{
                    if (!star.empty()){
                        star.pop();
                    } else{
                        return false;
                    }
                }
            }
            else {
                star.push(i);
            }
        }

        while(!star.empty() && !left.empty()){
            if (star.top() < left.top())
                return false;
            else{
                star.pop();
                left.pop();
            }
        }
        return left.empty();
    }
};


// 动态规划
class Solution {
public:
    bool checkValidString(string s) {
        int size = s.size();
        vector<vector<bool>> dp(size, vector<bool>(size, false));

        for(int i = 0;i<size;i++)
            if  (s[i] == '*')
                dp[i][i] = true;

        for(int i = 0;i<size-1;i++){
            char c1 = s[i];
            char c2 = s[i+1];
            dp[i][i+1] = (c1 == '(' || c1 == '*') && (c2 == ')' || c2 == '*');
            // dp[i][i+1] = (c1=='(' && c2==')') || (c1=='*' && c2=='*') || (c1=='*' && c1==')') || (c1=='(' && c2=='*');
        }
        for(int len = 2;len<size;len++){
            for(int i = 0;i<size-len;i++){
                int j = i+len;
                char c1 = s[i];
                char c2 = s[i+len];
                dp[i][j] = dp[i+1][j-1] && (c1 == '(' || c1 == '*') && (c2 == ')' || c2 == '*');
                for(int k = i;k<j && !dp[i][j];k++){
                    dp[i][j] = dp[i][k] && dp[k+1][j];
                }
            }
        }
        return dp[0][size-1];            
    }
};
