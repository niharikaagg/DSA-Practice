// https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=infix-to-postfix

/*
Given an infix expression in the form of string s. Convert this infix expression to a postfix expression.

Infix expression: The expression of the form a op b. When an operator is in between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -. Ignore the right associativity of ^.
*/



class Solution {
  public:
    int prec(char c)
    {
        if(c == '^') return 3;
        else if(c == '*' || c == '/') return 2;
        else if(c =='+' || c == '-') return 1;
        else return -1;
    }
    
    string infixToPostfix(string& s) {
        string ans;
        stack<char> st;
        
        for(int i=0; i<s.length(); i++)
        {
            char c = s[i];
            
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            {
                ans.push_back(c);
            }
            
            else if(c == '(')
            {
                st.push(c);
            }
            
            else if(c == ')')
            {
                while(st.top() != '(')
                {
                    ans.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
            
            else
            {
                while(!st.empty() && (prec(st.top()) >= prec(c)))
                {
                    ans.push_back(st.top());
                    st.pop();
                }
                st.push(c);
            }
        }
        
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};
