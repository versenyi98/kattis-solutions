#include <bits/stdc++.h>

using namespace std;

int main() {

    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int rows, cols, tile_rows, tile_cols;

    while (cin >> rows >> cols >> tile_rows >> tile_cols) {
    
        string grid[rows];
        for (int i = 0; i < rows; i++) {
            cin >> grid[i];
        }
        
        int row_padding = 2 * tile_rows - (rows % tile_rows);
        int col_padding = 2 * tile_cols - (cols % tile_cols);
        int padded_rows = rows + row_padding + tile_rows;
        int padded_cols = cols + col_padding + tile_cols;

        vector<vector<int>> RSQ(padded_rows);
        vector<vector<int>> sum(padded_rows);

        for (int i = 0; i < padded_rows; i++) {
            RSQ[i] = vector<int>(padded_cols, 0);
            sum[i] = vector<int>(padded_cols, 0);
        }

        for (int p_row = row_padding; p_row < padded_rows; p_row++) {
            int row = p_row - row_padding;
            for (int p_col = col_padding; p_col < padded_cols; p_col++) {
                int col = p_col - col_padding;

                if (row < rows && col < cols) {
                    sum[p_row][p_col] += grid[row][col] == 'X' ? 1 : 0;
                }
                sum[p_row][p_col] += sum[p_row - 1][p_col] + sum[p_row][p_col - 1] - sum[p_row - 1][p_col - 1];

                RSQ[p_row][p_col] = sum[p_row][p_col];

                if (p_row - tile_rows >= 0) {
                    RSQ[p_row][p_col] -= sum[p_row - tile_rows][p_col];
                }

                if (p_col - tile_cols >= 0) {
                    RSQ[p_row][p_col] -= sum[p_row][p_col - tile_cols];
                }

                if (p_row - tile_rows >= 0 && p_col - tile_cols >= 0) {
                    RSQ[p_row][p_col] += sum[p_row - tile_rows][p_col - tile_cols];
                }
            }
        }
        int result = INT_MAX;
        for (int start_row = 0; start_row < tile_rows; start_row++) {
            for (int start_col = 0; start_col < tile_cols; start_col++) {
                int tiles_needed = 0;
                for (int row = start_row; row < padded_rows; row += tile_rows) {
                    for (int col = start_col; col < padded_cols; col += tile_cols) {
                        if (RSQ[row][col] > 0) {
                            tiles_needed++;
                        }
                    }
                }
                result = min(result, tiles_needed);
            }
        }
        cout << result << endl;
    }


    return 0;
}