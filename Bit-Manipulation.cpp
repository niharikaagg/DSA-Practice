// https://www.geeksforgeeks.org/problems/bit-manipulation-1666686020/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bit-manipulation

/*
Given a 32 bit unsigned integer num and an integer i. Perform following operations on the number - 

1. Get ith bit

2. Set ith bit

3. Clear ith bit

Note : For better understanding, we are starting bits from 1 instead 0. (1-based). You have to print space three space separated values ( as shown in output without a line break) and do not have to return anything.
*/



class Solution {
  public:
    void bitManipulation(int num, int i) {
        
        string bin = convertToBinary(num);
        int len = bin.length();
        
        if (len < i)    // add zeroes for padding
        {
            bin = string(i - len, '0') + bin;
            len = bin.length();
        }
        
        cout << bin[len-i] << " ";
        
        bin[len-i] = '1';
        int newNum = convertToDecimal(bin);
        cout << newNum << " ";
        
        bin[len-i] = '0';
        newNum = convertToDecimal(bin);
        cout << newNum;
        
    }
    
    string convertToBinary(int num)
    {
        string res = "";
        
        while(num!=0)
        {
            if(num%2 == 1)
                res += '1';
            else
                res += '0';
                
            num = num/2;
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
    
    int convertToDecimal(string str)
    {
        int num = 0;
        
        int len = str.length(), i, power=0;
        
        for(i=len-1; i>=0; i--)
        {
            if(str[i] == '1')
                num += pow(2, power);
            power++;
        }
        
        return num;
    }
};
