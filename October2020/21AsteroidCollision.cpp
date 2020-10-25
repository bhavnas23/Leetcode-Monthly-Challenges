class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> s;
        vector<int> ans;
        for(int i=0; i<a.size(); ++i){
            if(s.empty() || a[i]>0){
                s.push(a[i]);
            }
            else{
                bool fl = false;
                while(!s.empty()&&s.top()>0){
                    if(abs(a[i])>s.top())
                        s.pop();
                    else {
                        if(abs(a[i])==s.top())
                            s.pop();
                        fl=true;
                        break;
                    }
                }
                if(!fl){
                    s.push(a[i]);
                }
            }
        }        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }   
};
