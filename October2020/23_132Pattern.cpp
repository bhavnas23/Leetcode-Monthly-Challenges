class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();

        vector<int> minV(n);
        minV[0]=nums[0];
        for(int i=1; i<n; ++i)
            minV[i] = min(minV[i-1], nums[i]);
        stack<int> st;
        for(int i=n-1; i>0; --i){
            
            while(!st.empty() && st.top()<=minV[i-1])
                st.pop();
            if(!st.empty() && st.top()<nums[i])
                return true;
            st.push(nums[i]);
        }
        return false;        
    }
};
