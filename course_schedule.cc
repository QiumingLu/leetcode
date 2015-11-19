#include <stdio.h>
#include <utility>
#include <vector>
#include <map>
#include <functional>

class Solution {
 public:
  bool CanFinish(int numCourses, std::vector<std::pair<int, int> >& prerequisites) {
    std::map<int, std::vector<int> > graph;
    int prerequisites_size = prerequisites.size();

    for (int i = 0; i < prerequisites_size; ++i) {
      graph[prerequisites[i].first].push_back(prerequisites[i].second);
    }

    std::vector<int> explored(numCourses, false);
    std::vector<int> path(numCourses, false);
    for (int i = 0; i < numCourses; ++i) {
      if (explored[i]) {
        continue;
      }
      if (HasCycle(i, graph, path, explored)) {
        return false;
      }
    }
    return true;
  }

 private:
  bool HasCycle(int n, 
                std::map<int, std::vector<int> >& graph, 
                std::vector<int>& path, 
                std::vector<int>& explored) {
    for (int i = 0; i < static_cast<int> (graph[n].size()); ++i) {
      if (path[graph[n][i]]) {
        return true;
      }
      path[graph[n][i]] = true;
      if (HasCycle(graph[n][i], graph, path, explored)) {
        return true;
      }
      path[graph[n][i]] = false;
    }

    explored[n] = true;
    return false;
  }
};

int main() {
  int numCourses;
  int size;
  std::vector<std::pair<int, int> > v;
  scanf("%d", &numCourses);
  scanf("%d", &size);
  for (int i = 0; i < size; ++i) {
    int first, second;
    scanf("%d %d", &first, &second);
    v.push_back(std::make_pair(first, second));
  }

  Solution solution;
  bool res = solution.CanFinish(numCourses, v);
  printf("%d\n", res);

  return 0;

