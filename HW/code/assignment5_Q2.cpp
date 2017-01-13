#include <iostream>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int length = s.length();
        int *dataStack = new int [length];
        int dataPointer = 0;
        char *opStack = new char [length / 2];
        int opPointer = 0;

        for (int i = 0; i < length; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                int value = 0;
                while (s[i] >= '0' && s[i] <= '9') {
                    value = value * 10 + s[i] - '0';
                    ++i;
                }
                dataStack[dataPointer++] = value;
            }
            if (s[i] == ' ')
                continue;
            if (s[i] == '(') {
                opStack[opPointer++] = s[i];
            }
            else if (s[i] == '+' || s[i] == '-'){
                while (opPointer != 0 && opStack[opPointer - 1] != '(') {
                    if (opStack[--opPointer] == '+') {
                        int num2 = dataStack[--dataPointer];
                        int num1 = dataStack[--dataPointer];
                        dataStack[dataPointer++] = num1 + num2;
                    }
                    else {
                        int num2 = dataStack[--dataPointer];
                        int num1 = dataStack[--dataPointer];
                        dataStack[dataPointer++] = num1 - num2;
                    }
                }
                opStack[opPointer++] = s[i];
            }
            else if (s[i] == ')') {
                while (opPointer != 0 && opStack[opPointer - 1] != '(') {
                    if (opStack[--opPointer] == '+') {
                        int num2 = dataStack[--dataPointer];
                        int num1 = dataStack[--dataPointer];
                        dataStack[dataPointer++] = num1 + num2;
                    }
                    else {
                        int num2 = dataStack[--dataPointer];
                        int num1 = dataStack[--dataPointer];
                        dataStack[dataPointer++] = num1 - num2;
                    }
                }
                --opPointer;
            }
        }
        while (opPointer != 0) {
            if (opStack[--opPointer] == '+') {
                int num2 = dataStack[--dataPointer];
                int num1 = dataStack[--dataPointer];
                dataStack[dataPointer++] = num1 + num2;
            }
            else {
                int num2 = dataStack[--dataPointer];
                int num1 = dataStack[--dataPointer];
                dataStack[dataPointer++] = num1 - num2;
            }
        }
        return dataStack[0];
    }
};

int main() {
    string s;
    getline(cin, s);
    int result;
    Solution sol;

    result = sol.calculate(s);
    cout << result;
}
