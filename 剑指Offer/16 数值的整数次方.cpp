// O(n)
class Solution {
public:
    double myPow(double x, int n){
        if (n==0)
            return 1;
        else if (n>0)
            return x*myPow(x, n-1);
        else 
            return (1/x)*myPow(x, n+1);
    }
};


// O(logn)
class Solution {
public:
    double myPow(double x, int n){
        if (n == 0)
            return 1;
        long int m = n;
        double res = 1.0;
        if (n < 0){
            x = 1/x;
            m = -m;
        }
        // while(m!=0){
        //     if (m%2==0)
        //         x *= x;
        //     else{
        //         res *= x;
        //         x *= x;
        //     }
        //     m /= 2;
        // }
        // 使用位运算进行加速
        while(m>0){
            if ((m&1)==1) res*=x;
            x *= x;
            m >>= 1;
        }
        return res;
    }
};