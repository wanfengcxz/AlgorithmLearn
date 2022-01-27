class Solution {
public:
    int translateNum(int num) {
        int a = 1, b = 1;
        int x, y = num%10;
        while(num!=0){
            num /= 10;
            x = num%10;
            int tmp = x*10+y;
            if (tmp >=10 && tmp<=25)
                tmp = a + b;
            else
                tmp = a;
            b = a;
            a = tmp;
            y = x;
        }
    return a;
    }
};