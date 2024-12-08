#include <bits/stdc++.h>

using namespace std;

class StackMin {
private:
    vector<pair<int, int>> mins;
    vector<int> stack;

public:
    StackMin() {}

    int get_min() {
        return mins.back().second;
    }

    void push(int x) {
        int i = stack.size();
        stack.push_back(x);
        if (i == 0 || mins.back().second > x) {
            mins.push_back(make_pair(i, x));
        }
    }

    void pop() {
        int i = stack.size() - 1;
        stack.pop_back();
        if (mins.back().first == i) {
            mins.pop_back();
        }
    }
};

void solve() {
    int n;
    cin >> n;
    StackMin st;
    for (int j = 0; j < n; j++) {
        char s;
        cin >> s;
        if (s == '1') {
            int x;
            cin >> x;
            st.push(x);
        } else if (s == '2') {
            st.pop();
        } else {
            cout << st.get_min() << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}

