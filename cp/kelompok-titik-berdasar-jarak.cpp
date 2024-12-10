#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

double hitungJarak(int x1, int y1, int x2, int y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    int T, N;
    cin >> T >> N;

    vector<pair<int, int>> points(N); 
    bool visited[1000];  

    for (int i = 0; i < N; ++i) {
        visited[i] = false;
    }

    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    int clusterCount = 0;  

    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            clusterCount++;  
            visited[i] = true; 

            vector<int> stack;
            stack.push_back(i);

            while (!stack.empty()) {
                int current = stack.back();
                stack.pop_back();

                for (int j = 0; j < N; ++j) {
                    if (!visited[j] && hitungJarak(points[current].first, points[current].second, points[j].first, points[j].second) <= T) {
                        visited[j] = true; 
                        stack.push_back(j);  
                    }
                }
            }
        }
    }

    cout << "Jumlah cluster: " << clusterCount << endl;

    return 0;
}
