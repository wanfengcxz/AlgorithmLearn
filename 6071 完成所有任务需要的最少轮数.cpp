// unordered_map的遍历
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> record;
        for (int &i:tasks){
            if (record.count(i) <= 0)
                record[i] = 1;
            else
                record[i]++;
        }
        int ans = 0;
        for (auto &[_, val]:record){
            if (val == 1) return -1;
            else if (val%3 == 0) ans += val/3;
            else if (val%3 == 1) ans += (val-4)/3+2;
            else ans += (val+1)/3;
        }
        return ans;
    }
};