class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n<=0)
            return false;
        // 注意这里的运算符优先级 == > &
        if ((n&n-1) == 0)
            return true;
        else 
            return false;
    }

    //  bool isPowerOfTwo(int n) {
    //     if (n==1)
    //         return true;
    //     if (n<=0)
    //         return false;
    //     while (n%2!=1){
    //         if (n == 2)
    //             return true;
    //         n = n >> 1;
    //     }
    //     return false;
    // }
};