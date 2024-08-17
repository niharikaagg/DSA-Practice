// https://leetcode.com/problems/valid-parentheses/description/

/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
*/



class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for(int i=0; i<s.length(); i++)
        {
            char c = s[i];

            if(stk.empty() && (c==')'||c==']'||c=='}'))
                return false;

            if(c=='('||c=='['||c=='{')
                stk.push(c);

            else if(c==')'&&stk.top()=='(' || c==']'&&stk.top()=='[' || 
            c=='}'&&stk.top()=='{')
                stk.pop();

            else
                return false;
        }
        
        if(!stk.empty())
            return false;
        
        return true;
    }
};
