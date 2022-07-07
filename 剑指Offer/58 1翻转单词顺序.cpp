class Solution {
public:
    string reverseWords(string s) {
        vector<string> res;
        int end = s.size()-1;
        int count = 0;
        string res_str = "";
        while(end>=0){
            count = 0;
            while(end>=0&&s[end]!=' '){
                end--;
                count++;
            }
            if (count != 0)
                res_str += s.substr(end+1, count) + ' ';
            end--;
        }
        return res_str.substr(0,res_str.size()-1);
    }
};