class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long currp=1;
        int s=0, e=0;
        int ans=0;
        while(s<=e && e<nums.size()){
                currp = currp*nums[e];
                
            while(currp>=k && s<e){
                currp/=nums[s];
                s++;
            }
            if(currp<k)
                ans+=e-s+1;
            e++;
        }
        return ans;        
    }
};