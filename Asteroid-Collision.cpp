// https://leetcode.com/problems/asteroid-collision/

/*
We are given an array asteroids of integers representing asteroids in a row. The indices of the asteroid in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
*/



class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int i=0; i<asteroids.size(); i++)
        {
            if(asteroids[i] > 0)    // push if +ve
                st.push(asteroids[i]);

            else    // -ve element
            {
                // while collision happens (unequal magnitude), incoming is larger
                while(!st.empty() && st.top() > 0 && abs(st.top()) < abs(asteroids[i]))
                    st.pop();

                if(!st.empty() && st.top() == abs(asteroids[i]))  // both top and incoming same
                    st.pop();

                else if(st.empty() || st.top() < 0)    // push -ve ones if the stack becomes empty or the top of stack has -ve 
                    st.push(asteroids[i]);
            }

        }

        vector<int> ans;

        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
