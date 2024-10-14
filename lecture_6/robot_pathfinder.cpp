// This program is part of the implementation of Lecture 6 of the CCI Course 2024 by Sarfraz Raza
// Problem 6e:
// Robot Pathfinding:
// Provided a 2D array with multiple robots and obstacles (robot_map.txt), determine whether each can
// reach the designated destination or not.

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void init_terrain(vector <vector <int>> &Terrain, ifstream &reader) {
	int rows, cols;
	reader >> rows >> cols;
	vector <int> DefaultRow(cols);
	vector <vector <int>> DefaultTerrain(rows, {DefaultRow});
	Terrain = DefaultTerrain;
}

void load_terrain(vector <vector <int>> &Terrain, ifstream &reader) {
	for (int ri = 0; ri < Terrain.size(); ri++)
		for (int ci = 0; ci < Terrain[ri].size(); ci++)
			reader >> Terrain[ri][ci];
}

void print_terrain(vector <vector <int>> Terrain) {
	for (int ri = 0; ri < Terrain.size(); ri++) {
		cout << endl;
		for (int ci = 0; ci < Terrain[ri].size(); ci++)
			cout << Terrain[ri][ci] << " ";
	}
	cout << endl;
}

struct Position {
	int ri, ci;
	Position() {
		ri = ci = 0;
	}
	Position(int r, int c) {
		ri = r;
		ci = c;
	}
};

void find_robots (vector <vector <int>> Terrain, vector <Position> &RobotPositions) {
	for (int ri = 0; ri < Terrain.size(); ri++)
		for (int ci = 0; ci < Terrain[ri].size(); ci++)
			if (Terrain[ri][ci] == 2)
				RobotPositions.push_back(Position {ri, ci});
}

bool can_reach (vector <vector <int>> &Terrain, Position position) {
	int rows = Terrain.size();
	int cols = Terrain[0].size();
	int row = position.ri;
	int col = position.ci;
	if (row < 0 || row >= rows || col < 0 || col >= cols)
		return false;
	else if (Terrain[row][col] == 1 || Terrain[row][col] == -1)
		return false;
	else if (Terrain[row][col] == 3)
		return true;
	else {
		Terrain[row][col] = -1;
		return (
			can_reach(Terrain, Position {row - 1, col}) ||
			can_reach(Terrain, Position {row + 1, col}) ||
			can_reach(Terrain, Position {row, col - 1}) ||
			can_reach(Terrain, Position {row, col + 1})
			);
	}
}

void print_reach_of_all_robots (vector <vector <int>> Terrain, vector <Position> RobotPositions) {
	for (int i = 0; i < RobotPositions.size(); i++) {
		Position robot = RobotPositions[i];
		vector <vector <int>> TerrainCopy = Terrain;
		cout << "robot at (" << robot.ri << "," << robot.ci << ") can";
		if (!can_reach(TerrainCopy, robot))
			cout << "not";
		cout << " reach the destination!" << endl;
	}
}

int main() {
	ifstream reader("robot_terrain.txt");
	vector <vector <int>> Terrain;
	init_terrain(Terrain, reader);
	load_terrain(Terrain, reader);
	print_terrain(Terrain);
	vector <Position> RobotPositions;
	find_robots(Terrain, RobotPositions);
	print_reach_of_all_robots(Terrain, RobotPositions);
	return 0;
}