class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int res = 0;
        for(auto v: nums)
            res ^= v;
        int div = 1;
        while((div&res) == 0)
            div <<= 1;
        int x = 0, y = 0; 
        for(auto v:nums){
            if ((v&div) == 0)
                x ^= v;
            else
                y ^= v;
        }
        return vector<int>{x, y};
    }
};