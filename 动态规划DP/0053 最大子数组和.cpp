/**
    
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max=nums[0];
        int preMax=nums[0];
        for(int i=1;i<nums.size();i++){
            if (nums[i]>preMax+nums[i])
                preMax=nums[i];
            else
                preMax=nums[i]+preMax;
            max=preMax>max?preMax:max;
        }
        return max;
    }
};