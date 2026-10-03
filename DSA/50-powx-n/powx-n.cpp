class Solution {
public:
    double solve(double x, long long n) {
        if(n == 0) return 1.0;

        double res = solve(x, n / 2);

        if(n % 2 == 0) {
            return res * res;
        }
        else {
            return x * res * res;
        }
    }

    double myPow(double x, int n) {
        long long power = n;

        if(power < 0) {
            return 1.0 / solve(x, -power);
        }

        return solve(x, power);
    }
};