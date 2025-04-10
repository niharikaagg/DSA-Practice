// https://www.geeksforgeeks.org/problems/postfix-to-prefix-conversion/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=postfix-to-prefix-conversion

/*
You are given a string that represents the postfix form of a valid mathematical expression. Convert it to its prefix form.
*/



class Solution {
  public:
    string postToPre(string post_exp) {
        string ans;
        stack<string> s;
        
        for(int i=0; i<post_exp.length(); i++)
        {
            char c = post_exp[i];
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
                
                string temp = c + o2 + o1;
                
                s.push(temp);
            }
        }
        
        ans = s.top();
        
        return ans;
    }
};
