// https://www.geeksforgeeks.org/problems/prefix-to-postfix-conversion/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prefix-to-postfix-conversion

/*
You are given a string that represents the prefix form of a valid mathematical expression. Convert it to its postfix form.
*/



class Solution {
  public:
    string preToPost(string pre_exp) {
        string ans;
        stack<string> s;
        
        for(int i=pre_exp.length()-1; i>=0; i--)
        {
            char c = pre_exp[i];
            string str(1, c);
            
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            {
                s.push(str);
            }
            
            else
            {
                string o1 = s.top();
                s.pop();
                string o2 = s.top();
                s.pop();
                
                string temp = o1 + o2 + c;
                
                s.push(temp);
            }
        }
        
        ans = s.top();
        
        return ans;
    }
};
