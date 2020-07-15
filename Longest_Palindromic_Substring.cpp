#include <string.h>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string tmp = "";
        int currentMaxLength = 0, subStringLength;
        int string_length = s.length();
        int start = 0;
        if (string_length == 0 || string_length == 1) return s;
        for (start; start < string_length; start++) {
            int  end = string_length;
            for (end; end > start; end--) {
                subStringLength = end - start;
                string secondSubString = s.substr(subStringLength / 2 + start + subStringLength % 2, subStringLength / 2);
                int secondSubStringLength = secondSubString.length();
                char swapChar;
                for (int i = 0; i < secondSubStringLength / 2; i++) {
                    swapChar = secondSubString[i];
                    secondSubString[i] = secondSubString[secondSubStringLength - 1 - i];
                    secondSubString[secondSubStringLength - 1 - i] = swapChar;
                }
                if (s.substr(start, subStringLength / 2) == secondSubString) {
                    if (subStringLength > currentMaxLength) {
                        currentMaxLength = subStringLength;
                        tmp = s.substr(start, subStringLength);
                        break;
                    }
                }
            }
        }
        return tmp;
    }
};

int main() {
    Solution sol;
    string s = "";
    s = sol.longestPalindrome("babad");
    cout << s << endl;
    return 0;
}