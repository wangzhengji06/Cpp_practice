#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    // while the numCourses >= 0
    // I want to to bredth first search. I want to first calculate the indegree

    vector<vector<int>> graph(numCourses);

    vector<int> indegree(numCourses, 0);
    for (vector<int> relationship : prerequisites) {
      auto target = relationship[0];
      auto prerequsite = relationship[1];
      graph[prerequsite].push_back(target);
      ++indegree[target];
    }

    // Now I want to do search, the order is that, I only want those who start
    // with degree 0. if no degree 0, then it is already mission impossible.

    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }

    int completed = 0;

    while (!q.empty()) {
      int course = q.front();
      q.pop();
      ++completed;

      for (int following : graph[course]) {
        if (--indegree[following] == 0) {
          q.push(following);
        }
      }
    }
    return completed == numCourses;
  }
};
