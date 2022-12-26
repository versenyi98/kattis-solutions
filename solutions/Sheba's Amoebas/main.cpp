#include <iostream>

using namespace std;

int n, m;
char picture[100][100];

void floodFill(int i, int j) {

    if (i < 0 || j < 0 || i >= n || j >= m) return;
    if (picture[i][j] == '.') return;

    picture[i][j] = '.';

    floodFill(i - 1, j - 1);
    floodFill(i - 1, j    );
    floodFill(i - 1, j + 1);
    
    floodFill(i    , j - 1);
    floodFill(i    , j + 1);

    floodFill(i + 1, j - 1);
    floodFill(i + 1, j    );
    floodFill(i + 1, j + 1);
}

int main() {

    while (cin >> n >> m) {

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> picture[i][j];
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (picture[i][j] == '#') {
                    result++;
                    floodFill(i, j);
                }
            }
        }
        cout << result << endl;
    }
}