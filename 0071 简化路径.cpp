class Solution {
public:
    string simplifyPath(string path) {
        auto split = [](const string &s, char delim) -> vector<string> {
            string tmp;
            vector<string> res;
            for (auto ch:s){
                if (ch == delim){
                    if (tmp != "")
                        res.push_back(tmp);
                    tmp = "";
                    continue;
                }
                else 
                    tmp += ch;
            }
            res.push_back(tmp);
            return res;
        };

        vector<string> names = split(path, '/');
        vector<string> st;
        string res;
        for (auto str:names){
            if (str == ".."){
                if (!st.empty())
                    st.pop_back();
            }
            else if (str == "." || str == "")
                continue;
            else{
                st.push_back(str);
            }
        }
        if (st.empty())
            res = '/';
        else{
            for (auto str:st){
                res += '/' + str;
            }
        }
        return res;

    }
};


/*
    关于move()
    https://blog.csdn.net/p942005405/article/details/84644069  
*/
class Solution {
public:
    string simplifyPath(string path) {
        auto split = [](const string& s, char delim) -> vector<string> {
            vector<string> ans;
            string cur;
            for (char ch: s) {
                if (ch == delim) {
                    ans.push_back(move(cur));
                    cur.clear();
                }
                else {
                    cur += ch;
                }
            }
            ans.push_back(move(cur));
            return ans;
        };

        vector<string> names = split(path, '/');
        vector<string> stack;
        for (string& name: names) {
            if (name == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            }
            else if (!name.empty() && name != ".") {
                stack.push_back(move(name));
            }
        }
        string ans;
        if (stack.empty()) {
            ans = "/";
        }
        else {
            for (string& name: stack) {
                ans += "/" + move(name);
            }
        }
        return ans;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/simplify-path/solution/jian-hua-lu-jing-by-leetcode-solution-aucq/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。