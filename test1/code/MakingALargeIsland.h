﻿#pragma once
namespace LargeIsland
{
	/*
	https://www.youtube.com/watch?v=_426VVOB8Vo

	https://leetcode.com/problems/making-a-large-island/description/

	827. Making A Large Island

	You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

	Return the size of the largest island in grid after applying this operation.

	An island is a 4-directionally connected group of 1s.



	Example 1:

	Input: grid = [[1,0],[0,1]]
	Output: 3
	Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
	Example 2:

	Input: grid = [[1,1],[1,0]]
	Output: 4
	Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
	Example 3:

	Input: grid = [[1,1],[1,1]]
	Output: 4
	Explanation: Can't change any 0 to 1, only one island with area = 4.


	Constraints:

	n == grid.length
	n == grid[i].length
	1 <= n <= 500
	grid[i][j] is either 0 or 1.

Solution

Certainly! Let's dive deeper into the code without focusing on complexity.

1. **Solution Overview**:
	- The goal of this solution is to find the largest island (connected land area) in a given grid.
	- It does so by identifying individual land areas, calculating their sizes, and then considering adjacent 
	water cells to potentially merge areas.

2. **Key Components**:
	- `SolutionBase`:
		- Contains utility functions shared by the main solution.
		- `landSize(row, col)` recursively explores the grid starting from a given cell `(row, col)` and returns the 
		size of the connected land area.
		- It marks visited cells with an island ID (incremented from 2 onwards).
	- `Solution`:
		- Inherits from `SolutionBase`.
		- `get_areas(row, col)`:
			- Calls `landSize` to find the size of the land area starting from `(row, col)`.
			- Updates the maximum area (`m_max`) and stores the area in `m_IdAreaMap`.
		- `get_all_areas()`:
			- Iterates through the entire grid and calls `get_areas` for each land cell.
			- Initializes grid dimensions (`m_rows` and `m_cols`).
		- `largestIsland(grid)`:
			- Sets the grid (`m_matrix`) and computes all land areas using `get_all_areas()`.
			- Then iterates through water cells (value 0) to find adjacent islands and calculate their combined area.
			- Updates `m_max` with the largest area encountered.

3. **Algorithm Steps**:
	- For each land cell (value 1):
		- Explore its neighbors (up, down, left, right) recursively using `landSize`.
		- Mark visited cells with an island ID.
		- Update the maximum area (`m_max`) and store the area in `m_IdAreaMap`.
	- For each water cell (value 0):
		- Check neighboring land cells.
		- Collect unique island IDs.
		- Calculate the combined area of adjacent islands.
		- Update `m_max` if a larger area is found.

4. **Overall Approach**:
	- Identify land areas and compute their sizes.
	- Consider water cells adjacent to land areas and merge their sizes.
	- Keep track of the largest area encountered.

Feel free to ask if you need further clarification or have additional questions! 😊

2. **Time Complexity**:
	- The `landSize` function recursively explores the grid to find the size of a land area starting from a given cell. It visits each cell at most once.
	- The `get_all_areas` function iterates through the entire grid and calls `get_areas` for each land cell.
	- The outer loop in `largestIsland` iterates through all cells in the grid.
	- The inner loop within the same function iterates through neighboring cells of water (value 0) and computes their combined area.
	- Overall, the time complexity is dominated by the grid size, which is O(rows * cols).

3. **Space Complexity**:
	- The space complexity mainly depends on the additional data structures used:
		- `m_matrix`: The grid itself, which requires O(rows * cols) space.
		- `m_IdAreaMap`: A map that stores the area of each island, which can be up to O(rows * cols) in total.
		- Recursive call stack in `landSize`: At most O(rows * cols) due to the recursion depth.
	- Therefore, the overall space complexity is O(rows * cols).

	*/
#define PRINTV


	struct SolutionBase
	{
		void print() const
		{
#ifdef PRINTV
			cout << "\n";
			for (auto elem : m_matrix)
			{
				printv(elem);
			}
			cout << "\n";
#endif
		}
		vector <vector<int> > m_directions{ {0,1},{0,-1},{1,0},{-1,0}, };// down, up, right, left
		int m_rows{}, m_cols{}, m_max{ 0 };
		vector< vector<int> > m_matrix;
		size_t m_island_id{ 2 };

		int landSize(int row, int col)
		{
			if (row < 0 || row >= m_rows || col < 0 || col >= m_cols || m_matrix[row][col] != 1)
				return 0;

			m_matrix[row][col] = m_island_id;
			auto down = landSize(row + 1, col); // DOWN
			auto right = landSize(row, col + 1); // RIGHT
			auto up = landSize(row - 1, col); // UP
			auto left = landSize(row, col - 1); // LEFT
			return down + up + left + right + 1; // return 1 because we need to at least add this cell since it is == 1
		}
	};

	class SolutionMaxAreaOfIsland : private SolutionBase
	{
		bool get_max_size()
		{
			m_rows = m_matrix.size();
			if (m_rows == 0)
			{
				return false;
			}
			print();

			m_cols = m_matrix[0].size();
			for (int row = 0; row < m_rows; row++)
			{
				for (int col = 0; col < m_cols; col++)
				{
					if (m_matrix[row][col] == 1)
					{
						auto size = landSize(row, col);
						m_max = max(m_max, size);
					}
				}
			}
			return true;
		}

	public:
		int maxAreaOfIsland(vector<vector<int>>& grid)
		{
			m_matrix = grid;
			auto res = get_max_size();
			if (!res)
			{
				return 0;
			}
			return m_max;
		}
	};
	// For https://leetcode.com/problems/making-a-large-island/description/
	// 827. Making A Large Island
	class Solution : private SolutionBase
	{

		map<int, int> m_IdAreaMap;

		void get_areas(int row, int col)
		{
			auto size = landSize(row, col);
			m_max = max(m_max, size);
			m_IdAreaMap[m_island_id++] = size;
			print();
		}

		bool get_all_areas()
		{
			m_rows = m_matrix.size();
			if (m_rows == 0)
			{
				return false;
			}
			print();

			m_cols = m_matrix[0].size();
			for (int row = 0; row < m_rows; row++)
			{
				for (int col = 0; col < m_cols; col++)
				{
					if (m_matrix[row][col] == 1)
					{
						get_areas(row, col);
					}
				}
			}
			return true;
		}

	public:

		int largestIsland(vector< vector<int> >& grid)
		{
			m_matrix = grid;
			auto res = get_all_areas();
			if (!res)
			{
				return 0;
			}
			//now we need to iterate the grid to find 0s and then move up and down.
			// we will find area ids. We get the in our set of island ids.
			for (int row = 0; row < m_rows; row++)
			{
				for (int col = 0; col < m_cols; col++)
				{
					if (m_matrix[row][col] == 0)
					{
						// here we obtain a set of unique island ids thanks to the sorting and unique set capabilities
						set<int> island_ids; 
						for (auto& direction : m_directions)
						{
							// check all directions
							auto x = direction[0] + row;
							auto y = direction[1] + col;
							// boundaries check and make sure our current cell is no 0: if it is 0 it is not an island
							if (x > -1 && y > -1 && x < m_rows && y < m_cols && m_matrix[x][y] != 0)
							{
								island_ids.insert(m_matrix[x][y]);
							}
						}
						int sum{ 1 }; // init to 1 because we initialize cell from 0 -> 1
						for (auto& islandid: island_ids)
						{
							sum += m_IdAreaMap[islandid];
						}
						m_max = max(m_max, sum);

					}
				}
			}

			return m_max;
		}



	};


	void process()
	{
		if (true)
		{
			cout << "find largest island\n";
			{
				// find largest island
				vector<vector<int>> matrix
				{
					{1,1,0,0,0,},
					{1,1,0,0,0,},
					{0,0,1,0,0,},
					{0,0,0,1,1,}
				};
				SolutionMaxAreaOfIsland sol;
				cout << sol.maxAreaOfIsland(matrix) << "\n";
			}
			{
				// find largest island 2
				vector<vector<int>> matrix
				{
					{0,0,1,0,0,0,0,1,0,0,0,0,0},
					{0,0,0,0,0,0,0,1,1,1,0,0,0},
					{0,1,1,0,1,0,0,0,0,0,0,0,0},
					{0,1,0,0,1,1,0,0,1,0,1,0,0},
					{0,1,0,0,1,1,0,0,1,1,1,0,0},
					{0,0,0,0,0,0,0,0,0,0,1,0,0},
					{0,0,0,0,0,0,0,1,1,1,0,0,0},
					{0,0,0,0,0,0,0,1,1,0,0,0,0}
				};
				SolutionMaxAreaOfIsland sol;
				cout << sol.maxAreaOfIsland(matrix) << "\n";
			}
		}
		if(true)
		{
			cout << "find largest if we change from 0 to 1\n";

			// find largest if we change from 0 to 1
			vector<vector<int>> matrix
			{
				{1,1,0,0,0,},
				{1,1,0,0,0,},
				{0,0,1,0,0,},
				{0,0,0,1,1,}
			};
			Solution sol;
			cout << sol.largestIsland(matrix) << "\n";
		}
	}
}