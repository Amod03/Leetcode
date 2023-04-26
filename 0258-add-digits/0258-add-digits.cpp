class Solution {
public:
    int addDigits(int num) {
        if(num==0)
            return 0;
        int sum=0;
        while(num>9)
        {
        while(num)
        {
            int rem=num%10;
            sum=sum+rem;
            num=num/10;
        }
            num=sum;
            sum=0;
        }
        return num;
    }
};