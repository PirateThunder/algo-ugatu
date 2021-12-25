#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
//using namespace std;

bool cmp(std::pair<int, int> a, std::pair<int, int> b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> events;
    int d1, m1, y1, d2, m2, y2;
    int delta_d, delta_m, delta_y;
    for (int i = 0; i < n; i++) {
        std::cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;
        delta_d = d2 - d1;
        delta_m = m2 - m1;
        delta_y = y2 - y1;
        if (delta_y == 18) {
            if (delta_m > 0) {
                events.push_back({y1+18, 1});
                events.push_back({y2, -1});
            } else if (delta_m == 0) {
                if (delta_d > 0) {
                    events.push_back({y1+18, 1});
                    events.push_back({y2, -1});
                }
            }
        } else if (delta_y > 18 && delta_y < 80) {
            if (d2 == 1 && m2 == 1) {
                events.push_back({y1+18, 1});
                events.push_back({y2-1, -1});
            } else {
                events.push_back({y1+18, 1});
                events.push_back({y2, -1});
            }
        } else if (delta_y == 80) {
            if (delta_m > 0) {
                //events.push_back({y1+18, 1});
                //events.push_back({y1+80, -1});
                if (d2 == 1 && m2 == 1) {
                    events.push_back({y1+18, 1});
                    events.push_back({y1+79, -1});
                } else {
                    events.push_back({y1+18, 1});
                    events.push_back({y1+80, -1});
                }
            } else if (delta_m < 0) {
                //events.push_back({y1+18, 1});
                //events.push_back({y1+80, -1});
                if (d2 == 1 && m2 == 1) {
                    events.push_back({y1+18, 1});
                    events.push_back({y1+79, -1});
                } else {
                    events.push_back({y1+18, 1});
                    events.push_back({y1+80, -1});
                }
            } else {
                if (delta_d > 0) {
                    //events.push_back({y1+18, 1});
                    //events.push_back({y1+80, -1});
                    if (d2 == 1 && m2 == 1) {
                        events.push_back({y1+18, 1});
                        events.push_back({y1+79, -1});
                    } else {
                        events.push_back({y1+18, 1});
                        events.push_back({y1+80, -1});
                    }
                } else if (delta_d < 0) {
                    //events.push_back({y1+18, 1});
                    //events.push_back({y1+80, -1});
                    if (d2 == 1 && m2 == 1) {
                        events.push_back({y1+18, 1});
                        events.push_back({y1+79, -1});
                    } else {
                        events.push_back({y1+18, 1});
                        events.push_back({y1+80, -1});
                    }
                } else {
                    //events.push_back({y1+18, 1});
                    //events.push_back({y1+80, -1});
                    if (d2 == 1 && m2 == 1) {
                        events.push_back({y1+18, 1});
                        events.push_back({y1+79, -1});
                    } else {
                        events.push_back({y1+18, 1});
                        events.push_back({y1+80, -1});
                    }
                }
            }
        } else if (delta_y > 80) {
            // не может
            //events.push_back({y1+18, 1});
            //events.push_back({y1+80, -1});
            if (d2 == 1 && m2 == 1) {
                events.push_back({y1+18, 1});
                events.push_back({y1+79, -1});
            } else {
                events.push_back({y1+18, 1});
                events.push_back({y1+80, -1});
            }
        }
    }
    std::stable_sort(begin(events), end(events), cmp);

    int tmp = 0, ans = 0;
    for (int i = 0; i < events.size(); i++) {
        //std::cout << events[i].first << " " << events[i].second << "\n";
    	ans = std::max(ans, tmp);
        tmp += events[i].second;
        ans = std::max(ans, tmp);
    }
    std::cout << ans;
}
