class Solution {
public:
    string digitSum(string s, int k) {
        int size = s.size();
        string res = s;
        string tmp;
            while(size > k){
                res = s;
                s.clear();
                while(size!=0){
                    int divide_bound = size>k?k:size;
                    tmp = res.substr(0, divide_bound);
                    res.erase(0, divide_bound);
                    size = res.size();
                    s += getSum(tmp);
                }
                size = s.size();
            }
        return s;
    }

    string getSum(string str){
        int number = 0;
        for(char ch:str){
            number += int(ch-'0');
        }
        return to_string(number);
    }
};

// 递归
class Solution {
public:
    string digitSum(string s, int k) {
        int size = s.size();
        if (size > k){
            string tmp;
            string res;
            while(size!=0){
                int divide_bound = size>k?k:size;
                tmp = s.substr(0, divide_bound);
                s.erase(0, divide_bound);
                size = s.size();
                res += getSum(tmp);
            }
            return digitSum(res, k);
        } else {
            return s;
        }
    }

    string getSum(string str){
        int number = 0;
        for(char ch:str){
            number += int(ch-'0');
        }
        return to_string(number);
    }
};


// 优化
class Solution {
public:
    string digitSum(string s, int k) {
        int size = s.size();
        if (size > k){
            string tmp;
            string res;
            // 优化
            for (int i = 0;i<size;i+=k){
                int divide_bound = size>=i+k?k:i+k-size;
                tmp = s.substr(i, k);
                res += getSum(tmp);
            }
            return digitSum(res, k);
        } else {
            return s;
        }
    }

    string getSum(string str){
        int number = 0;
        for(char ch:str){
            number += int(ch-'0');
        }
        return to_string(number);
    }
};
