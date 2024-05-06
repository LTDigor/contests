#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

struct pair_hash {
    inline size_t operator()(const pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

unordered_map<pair<int, int>, pair<int, string>, pair_hash> memo;

string repeat(int mult, const string & substr) {
    string repeatedString = "";
    for (int i = 0; i < mult; ++i) {
        repeatedString += substr;
    }
    return repeatedString;
 }
string construct(int mult, const string & substr) {
    if (to_string(mult).length() + 2 + substr.length() > mult * substr.length()) {
        return repeat(mult, substr);
    }
    return to_string(mult) + "(" + substr + ")";
}

pair<int, string> compress(const string & s, int left, int right) {
    if (memo.find({left, right}) != memo.end()) {
        return memo[{left, right}];
    }
    if (right == left) {
        return {1, string(1, s[left])};
    }
    int mult = 1;
    string substr = s;
    string built = s;
    for (int sep = left; sep < right; sep++) {
        pair<int, string> left_res = compress(s, left, sep);
        pair<int, string> right_res = compress(s, sep + 1, right);
        if (left_res.second == right_res.second) {
            mult = left_res.first + right_res.first;
            substr = left_res.second;
            built = construct(mult, substr);
        } else {
            string left_substr = construct(left_res.first, left_res.second);
            string right_substr = construct(right_res.first, right_res.second);
            if (built.length() > left_substr.length() + right_substr.length()) {
                mult = 1;
                substr = left_substr + right_substr;
                built = substr;
            }
        }
    }
    memo[{left, right}] = {mult, substr};
    return {mult, substr};
}

int main() {
    string s;
    cin >> s;
    pair<int, string> res = compress(s, 0, s.length() - 1);
    string result = construct(res.first, res.second);
    cout << result << endl;
    return 0;
}

