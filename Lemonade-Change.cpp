// https://leetcode.com/problems/lemonade-change/description/

/*
At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

Note that you do not have any change in hand at first.

Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.
*/



class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f=0, t=0;

        for(int i=0; i<bills.size(); i++)
        {
            if(bills[i] == 5)
                f++;

            else if(bills[i] == 10)
            {
                if(f==0)
                    return false;

                f--;
                t++;
            }

            else if(bills[i] == 20)
            {
                if((t==0 && f<3) || (t!=0 && f==0))
                    return false;

                if(t!=0)
                {
                    t--;
                    f--;
                }
                else if(t==0)
                    f=f-3;
            }
        }
        return true;
    }
};
