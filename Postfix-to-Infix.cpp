// https://www.geeksforgeeks.org/problems/postfix-to-infix-conversion/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=postfix-to-prefix-conversion

/*
You are given a string that represents the postfix form of a valid mathematical expression. Convert it to its infix form.
*/



class Solution {
  public:
    string postToInfix(string exp) {
        string ans;
        stack<string> s;
        
        for(int i=0; i<exp.length(); i++)
        {
            char c = exp[i];
            string str(1, c);  // creates a string of length 1 with character 'c'
            
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
                
                string temp = "(" + o2 + c + o1 + ")";
                
                s.push(temp);
            }
        }
        
        ans = s.top();
        
        return ans;
    }
};
