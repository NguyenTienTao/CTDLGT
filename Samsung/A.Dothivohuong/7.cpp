#include <iostream>
#include <vector>

using namespace std;

void floodFill(vector<vector<int>>& image, int row, int col, int start_color, int new_color) {
    int rows = image.size();
    int cols = image[0].size();

    if (row < 0 || row >= rows || col < 0 || col >= cols || image[row][col] != start_color) {
        return;
    }

    image[row][col] = new_color;

    int dr[] = {1, -1, 0, 0};
    int dc[] = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++) {
        int new_row = row + dr[i];
        int new_col = col + dc[i];

        floodFill(image, new_row, new_col, start_color, new_color);
    }
}

int main() {
    vector<vector<int>> image = {
        {1, 1, 1, 2},
        {2, 1, 1, 2},
        {2, 2, 1, 2},
        {2, 2, 2, 2}
    };

    floodFill(image, 0, 0, image[0][0], 3);

    for (int i = 0; i < image.size(); i++) {
        for (int j = 0; j < image[i].size(); j++) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
