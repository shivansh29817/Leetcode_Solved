class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int i = 0;
        int j = 0;
        st.push(pushed[i]);
        while(i < pushed.size()){
            if(!st.empty() && popped[j] == st.top()){
                st.pop();
                j++;
            }
            else{
                st.push(pushed[i]);
                i++;
            }
        }
       while(j < popped.size()){
        if(!st.empty() && popped[j] == st.top()){
            st.pop();
            j++;
        }
        else{
            return false;
        }
       }
       return true;
    }
};