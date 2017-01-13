#include <iostream>
#include <cstdio>

using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        cout << n <<endl;
        if (n == 1)
            return 0;
        if (n % 2 == 0)
            return 1 + integerReplacement(n / 2);
        else {
            if (n == 3) {
                return 2;
            }
            long long long_n = n;
            if ((n + 1) % 4 == 0)
                return 3 + integerReplacement((long_n + 1) / 4);
            else
                return 3 + integerReplacement((long_n - 1) / 4);
        }
    }
};

int main(){
    int N;
    scanf("%d", &N);
    int result;
    Solution sol;

    result = sol.integerReplacement(N);
    printf("%d", result);
}

