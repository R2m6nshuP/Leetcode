class Solution {
public:
    int addDigits(int num) {
        int sum=0;
        do{
            sum=0;
            while(num){
                sum+=num%10;
                num/=10;
            }
            num=sum;
        }while(sum/10>=1);
        return sum;
    }
};