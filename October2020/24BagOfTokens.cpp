class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int n=tokens.size(); 
        int s = 0, e = n-1;
        int ans = 0, cs = 0;
        sort(tokens.begin(), tokens.end());
        while(s<=e){
            if(tokens[s]<=P){
                P-=tokens[s];
                s++;
                cs++;
                ans = max(cs, ans);
            }
            else if(tokens[e]>=P && cs>0){
                P+=tokens[e];
                e--;
                cs--;
                ans = max(cs, ans);
            }
            else
                break;
        }
        ans = max(cs, ans);
        return ans;
    }
};
