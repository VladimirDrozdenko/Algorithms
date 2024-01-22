#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


const vector<vector<int>> maze = {
        {0, 1, 0, 1},
        {0, 0, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0}
};

int count_paths(int row, int col) {

    if (row == maze.size() - 1 && col == maze.at(row).size() - 1 && maze.at(row).at(col) == 0) {
        return 1;
    }

    if (row == maze.size() || col == maze.at(row).size() || maze.at(row).at(col) == 1) {
        return 0;
    }

    return count_paths(row, col+1) + count_paths(row+1, col);
}

int main() {

    for (const auto& row: maze) {
        copy(row.cbegin(), row.cend(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    cout << count_paths(0, 0) << endl;

    return 0;
}
