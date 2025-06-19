#include <iostream>
#include <algorithm>
using namespace std;

int longestPalindrome(const string& str) {
    int n = str.length();
    int dp[1000][1000];

    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i < n - len + 1; ++i) {
            int j = i + len - 1;

            if (str[i] == str[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else {
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
    }

    return dp[0][n - 1];
}

int minDeletionsForPalindrome(const string& str) {
    int n = str.length();
    int longestPalin = longestPalindrome(str);

    return n - longestPalin;
}

string buildPalindrome(const string& str) {
    string revStr = str;
    reverse(revStr.begin(), revStr.end());

    return str + revStr.substr(minDeletionsForPalindrome(str));
}

int main() {
    string str;
    cout << "Insert the string: ";
    cin >> str;

    string palindrome = buildPalindrome(str);
    cout << "Max. length palindrome: " << palindrome << endl;

    return 0;
}