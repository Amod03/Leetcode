class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        return false;
        else{
            long long a,b;
            b=0;
            a=x;
            while(a>0)
            {
                long long d=a%10;
                b=b*10+d;
            
                a=a/10;
            }
            if(x==b)
            return true;
            else 
            return false;
        }
    }
};