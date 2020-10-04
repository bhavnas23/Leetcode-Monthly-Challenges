class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> s;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]>0)
                s.insert(nums[i]);
        }
        for(int i=1; i<=nums.size(); ++i)
            if(s.find(i)==s.end())
                return i;
        return nums.size()+1;
    }
};