class Solution {
public:

    double f(double x,long long n){
        if(n == 0) return 1.0;
        if(n == 1) return x;

        if(n%2 == 0){
            double res = f(x,n/2);
            return res*res;
        }

        else{
            double res = f(x,(n-1)/2);
            return x*res*res;
        }
    }

    double myPow(double x, int n) {
        long long num = n;
        if(num < 0){
            return (1.0/f(x,-num));
        }
        else{
            return f(x,num);
        }
    }
};
