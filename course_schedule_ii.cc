#include <stdio.h>
#include <vector>
#include <utility>
#include <unordered_map>

class Solution {
 public:
  std::vector<int> FindOrder(
      int numCourses, 
      std::vector<std::pair<int, int> >& prerequisites) {
    int prerequisites_size = prerequisites.size();
    std::unordered_map<int, std::vector<int> > graph;
    std::vector<int> entertrance(numCourses, true);

    for (int i = 0; i < prerequisites_size; ++i) {
      graph[prerequisites[i].first].push_back(prerequisites[i].second);
      entertrance[prerequisites[i].second] = false;
    }

    std::vector<int> path(numCourses, false);
    std::vector<int> explored(numCourses, false);
    std::vector<int> resVec;
    for (int i = 0; i < numCourses; ++i) {
      if (!entertrance[i] || explored[i]) {
        continue;
      }
      if (!TopologicalSort(i, graph, path, explored, resVec)) {
        return resVec;
      }
    }

    if (static_cast<int>(resVec.size()) != numCourses) {
      return std::vector<int>();
    }
    return resVec;
  }

 private:
  // If has cycle, return false, else return true.
  bool TopologicalSort(int n, 
                       std::unordered_map<int, std::vector<int> >& graph,
                       std::vector<int>& path,
                       std::vector<int>& explored, 
                       std::vector<int>& resVec) {
    if (explored[n]) {
      return true;
    }
    for (int i = 0; i < static_cast<int> (graph[n].size()); ++i) {
      if (path[graph[n][i]]) {
        resVec.clear();
        return false;
      }

      path[graph[n][i]] = true;
      if (!TopologicalSort(graph[n][i], graph, path, explored, resVec)) {
        resVec.clear();
        return false;
      }
      path[graph[n][i]] = false;

    }

    resVec.push_back(n);
    explored[n] = true;
    return true;
  }
};

int main() {
  int numCourses;
  int v_size;
  std::vector<std::pair<int, int> > v;
  scanf("%d", &numCourses);
  scanf("%d", &v_size);
  for (int i = 0; i < v_size; ++i) {
    int first, second;
    scanf("%d %d", &first, &second);
    v.push_back(std::make_pair(first, second));
  }

  Solution solution;
  std::vector<int> resVec = solution.FindOrder(numCourses, v);
  for (int i = 0; i < static_cast<int>(resVec.size()); ++i) {
    printf("%d ",resVec[i]);
  }
  printf("\n");

  return 0;
}
