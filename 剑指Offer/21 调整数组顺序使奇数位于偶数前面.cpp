class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        int tmp=0;
        while(low<high){
            while(low<high && (nums[high]&1)==0) --high;
            while(low<high && (nums[low]&1)==1) ++low;
            tmp = nums[high];
            nums[high] = nums[low];
            nums[low] = tmp;
        }
        return nums;
    }
};

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        partition(nums, 0, nums.size()-1);
        return nums;
    }

    void partition(vector<int> &nums, int s, int e){
        if (s<e){
            int low = s, high = e;
            int pivot = nums[low];
            while(low<high){
                while(low<high && nums[high]%2==0) --high;
                nums[low] = nums[high];
                while(low<high && nums[low]%2==1) ++low;
                nums[high] = nums[low];
            }
            nums[low] = pivot;
        }
    }
};
