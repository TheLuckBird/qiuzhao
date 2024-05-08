#include <vector>
#include <iostream>

using namespace std;

class Solution
{
private:
	vector<vector<int>> edgs;
	vector<int> visited;
	bool valid = true;

public:
	void dfs(int u)
	{
		visited[u] = 1;

		for (int v : edgs[u])
		{
			if (visited[v] == 0)
			{
				dfs(v);
				if (!valid)
					return;
			}
			if (visited[v] == 1)
			{
				valid = false;
				return;
			}
		}

		visited[u] = 2;
	}

	bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
	{
		edgs.resize(numCourses);
		visited.resize(numCourses);

		for (const auto& info : prerequisites)
		{
			edgs[info[1]].push_back(info[0]);
		}

		for (int i = 0; i < numCourses && valid; ++i)
		{
			if (!visited[i])
				dfs(i);
		}

		return valid;
	}
};