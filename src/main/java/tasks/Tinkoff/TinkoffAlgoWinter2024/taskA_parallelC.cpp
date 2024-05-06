#include <iostream>
#include <vector>

using namespace std;

int main() {
    int balloons, workers;
    cin >> balloons >> workers;

    vector<int> balloon_time_arr, balloons_to_rest_arr, long_period_arr;
    for (int i = 0; i < workers; i++) {
        int balloon_time, balloons_to_rest, time_to_rest;
        cin >> balloon_time >> balloons_to_rest >> time_to_rest;
        int long_period = balloon_time * balloons_to_rest + time_to_rest;
        balloon_time_arr.push_back(balloon_time);
        balloons_to_rest_arr.push_back(balloons_to_rest);
        long_period_arr.push_back(long_period);
    }

    int left = 1, right = 1e9;
    while (left <= right) {
        int mid = (left + right) / 2;
        long long will_inflate = 0;
        for (int i = 0; i < workers; i++) {
            will_inflate += (mid / long_period_arr[i]) * balloons_to_rest_arr[i];
            will_inflate += min(balloons_to_rest_arr[i], mid % long_period_arr[i] / balloon_time_arr[i]);
        }
        if (will_inflate >= balloons) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << left << endl;

    return 0;
}
