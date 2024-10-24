class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0; // in s
        int j = 0; // in t
        int s_length = s.length();
        int t_length = t.length();
        if(t_length < s_length) //then s can't be present in t
        return false;
        else
        {
            int  k = s_length;
            while(k>0 && i<s_length && j<t_length)
            {
                if(s[i] == t[j])//letter is a match
                {
                    i++;
                    k=k-1;
                }
                j++;
            }
            if(k==0)
            return true;
            else
            return false;
        }
    }
};