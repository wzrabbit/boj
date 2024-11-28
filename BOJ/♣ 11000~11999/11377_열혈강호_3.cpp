#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[2001];
int L[2001], R[1001];
bool visited[2001];
int N, M, K;

bool dfs(int cur) {
    if (visited[cur]) {
        return false;
    }

    visited[cur] = true;

    for (int adj : graph[cur]) {
        if (R[adj] == 0 || (!visited[R[adj]] && dfs(R[adj]))) {
            L[cur] = adj;
            R[adj] = cur;
            return true;
        }
    }

    return false;
}

int get_matched_count() {
    int matched_count = 0;
    int limit = 0;

    for (int i = 1; i <= N; i++) {
        fill(visited + 1, visited + N * 2 + 1, false);

        if (dfs(i)) {
            matched_count += 1;
        }
    }

    for (int i = N + 1; i <= N * 2; i++) {
        fill(visited + 1, visited + N * 2 + 1, false);

        if (limit == K) {
            break;
        }

        if (dfs(i)) {
            matched_count += 1;
            limit += 1;
        }
    }

    return matched_count;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        int repeat;
        cin >> repeat;

        for (int j = 1; j <= repeat; j++) {
            int cur;
            cin >> cur;

            graph[i].push_back(cur);
            graph[N + i].push_back(cur);
        }
    }

    cout << get_matched_count();
}
