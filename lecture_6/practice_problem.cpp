#include <iostream>
#include <vector>
// #include <fstream>
using namespace std;

#define ROWS 10
#define COLS 10

bool can_reach_edge(vector<vector<int>> &plane, int r, int c) {
  if (r < 0 || c < 0 || r >= ROWS || c >= COLS)
    return true;
  else if (plane[r][c] == 1 || plane[r][c] == 3)
    return false;
  plane[r][c] = 3;
  for (int ri = r - 1; ri <= r + 1; ri++) {
    for (int ci = c - 1; ci <= c + 1; ci++) {
      if (ri == r && ci == c)
        continue;
      if (can_reach_edge(plane, ri, ci))
        return true;
    }
  }
  return false;
}

bool is_in(vector<vector<int>> plane, int x, int y) {
  vector<vector<int>> plane_copy = plane;
  if (can_reach_edge(plane_copy, x, y))
    return false;
  return true;
}

void read_input(vector<vector<int>> &plane, int &x, int &y) {
    // TODO: read input from file and populate
}

void populate_manually(vector<vector<int>> &plane, int &x, int &y) {
  plane.push_back({1, 1, 1, 1, 1, 1, 0, 1, 0, 0});
  plane.push_back({1, 0, 0, 0, 0, 0, 0, 1, 0, 0});
  plane.push_back({1, 0, 2, 0, 0, 0, 0, 1, 0, 0});
  plane.push_back({1, 0, 0, 0, 0, 0, 0, 1, 0, 0});
  plane.push_back({1, 1, 1, 1, 1, 1, 1, 1, 0, 0});
  plane.push_back({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
  plane.push_back({0, 0, 0, 0, 1, 1, 1, 1, 1, 0});
  plane.push_back({0, 0, 0, 0, 1, 0, 0, 2, 1, 0});
  plane.push_back({0, 0, 0, 0, 1, 1, 1, 1, 1, 1});
  plane.push_back({2, 0, 0, 0, 0, 0, 0, 0, 1, 2});
  // x = 2, y = 2;
  // x = 7, y = 7;
  // x = 9, y = 9;
  x = 0, y = 9;
}

int main()
{
  vector<vector<int>> plane;
  int x, y;
  // read_input(plane, x, y);
  populate_manually(plane, x, y);
  if (is_in(plane, x, y))
    cout << "INSIDE";
  else
    cout << "OUTSIDE";
  return 0;
}