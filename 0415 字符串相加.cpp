class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size()-1, j = num2.size()-1;
        int add = 0;
        string res = "";
        while(i>=0 || j>=0 || add == 1){
            int x = i>=0?num1[i]-'0':0;
            int y = j>=0?num2[j]-'0':0;
            int z = x + y + add;
            res += z%10+'0';
            add = z/10;
            i--, j--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};