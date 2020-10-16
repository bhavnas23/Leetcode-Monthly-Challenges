class Solution {
public:
    int robK(vector<int> & a, int s, int e){
        if(s>e)
            return 0;
        int incl=a[s], excl=0;
        for(int i=s+1; i<=e;++i){
            excl = max(incl, excl+a[i]);
            int tmp = incl;
            incl = excl;
            excl=tmp;
        }
        return max(incl, excl);
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        int a1=robK(nums, 0, nums.size()-2);
        int a2=robK(nums, 1, nums.size()-1);
        return max(a1, a2);
    }
};
