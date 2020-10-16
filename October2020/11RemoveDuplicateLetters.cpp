class Solution {
public:
    void print(stack<char> st){while(!st.empty()){cout<<st.top();st.pop();}cout<<endl;}
    string removeDuplicateLetters(string s) {
        vector<int> v(26, -1),  x(26,0);
        for(int i=0; i<s.size(); ++i){
            int c=s[i]-'a';
            v[c]=i;
        }
        stack<char> st;
        for(int i=0; i<s.size(); ++i){
            if(x[s[i]-'a']==0){if(!st.empty()){
                if(st.top()<=s[i]){
                    if( x[s[i]-'a']==0){
                        st.push(s[i]);
                        // v[s[i]-'a']--;
                        x[s[i]-'a']++;
                    }
                }
                else{
                    while(!st.empty() && st.top()>=s[i] && v[st.top()-'a']>=i){
                        char c = st.top();
                        x[c-'a']--;
                        // v[c-'a']++;
                        st.pop();
                    }
                    if(x[s[i]-'a']==0){
                        st.push(s[i]);
                        // v[s[i]-'a']--;
                        x[s[i]-'a']++;
                    }
                }
            }
            else{
                st.push(s[i]);
                // v[s[i]-'a']--;
                x[s[i]-'a']++;
            }}print(st);
        }
        string ans="";
        while(!st.empty()){
            ans = st.top()+ans;st.pop();
        }
        return ans;
    }
};
