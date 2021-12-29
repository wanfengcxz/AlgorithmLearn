class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0 || (x%10==0)&&(x!=0) )
            return false;
        int reverseNum = 0;
        while(x>reverseNum){
            reverseNum *= 10;
            reverseNum += x%10;
            x /= 10;
        }    
        return (x==reverseNum) || (reverseNum/10==x);
    }

    //   bool isPalindrome(int x) {
    //     if (x == 0)
    //         return true;
    //     // 小于0或者个位数为0
    //     if (x<0||x%10==0)
    //         return false;

    //     int reverseNum = 0;
    //     int tmp=0;
    //     while(x>reverseNum){
    //         tmp = x%10;
    //         reverseNum += tmp;
    //         if (x == reverseNum)
    //             return true;
    //         x = x/10;
    //         if (x == reverseNum)
    //             return true;
    //         reverseNum *= 10;
    //     }
    //     return x==reverseNum;
    // }

    //    bool isPalindrome(int x) {
    //     string s = to_string(x);
    //     int size = s.size();
    //     for(int i=0;i<size/2;i++){
    //         if (s[i]!=s[size-1-i])
    //             return false;
    //     }
    //     return true;
    // }
};