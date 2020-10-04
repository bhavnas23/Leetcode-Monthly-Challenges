class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans = 0;
        if(k==0){
            map<int, int> mp;
            for(int i=0; i<nums.size(); ++i){
                mp[nums[i]]++;
            }
            for(auto i=mp.begin(); i!=mp.end(); ++i){
                if(i->second>=2)
                    ans++;
            }
        }
        else{
            map<int, int> mp;
            int n = nums.size();
            
            for(int i=0; i<n;){
                if(mp.find(nums[i])!=mp.end()){
                    int t = nums[i];
                    nums[i] = nums[n-1];
                    nums[n-1]=t;
                    n--;
                }
                else{
                    mp[nums[i]]++;
                    i++;
                }
                
            }
            for(int i=0; i<n; ++i){
                if(mp.find(nums[i]+k)!=mp.end()){
                    ans++;
                }
            }
        }
        return ans;
    }
};