// https://www.geeksforgeeks.org/problems/prefix-to-infix-conversion/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prefix-to-infix-conversion

/*
You are given a string S of size N that represents the prefix form of a valid mathematical expression. The string S contains only lowercase and uppercase alphabets as operands and the operators are +, -, *, /, %, and ^.Convert it to its infix form.
*/



class Solution {
  public:
    string preToInfix(string pre_exp) {
        string ans;
        stack<string> s;
        
        for(int i=pre_exp.length()-1; i>=0; i--)
        {
            char c = pre_exp[i];
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
                
                string temp = "(" + o1 + c + o2 + ")";
                
                s.push(temp);
            }
        }
        
        ans = s.top();
        
        return ans;
    }
};
