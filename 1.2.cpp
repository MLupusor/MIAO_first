#include <bits/stdc++.h>

using namespace std;

int main()
{
  vector<int> v;
  int n;

  while (1)
  {
    cin >> n;
    v.push_back(n);
    if (!n)
      break;
  }

  vector<vector<int>> up;
  vector<int> helper;

  for (int i = 0; i < v.size() - 1; i++)
  {
    helper.push_back(v[i]);
    if (v[i] > v[i + 1])
    {
      up.push_back(helper);
      helper = {};
    }
  }

  for (int i = 0; i < up.size(); i++) {
    for (int j = 0; j < up[i].size(); j++) {
      cout << up[i][j] << " ";
    }
    cout << "\n";
  }

  int successes = 0;
  for (int i = 0; i < up.size(); i++) {
    if (up[i].size() > 1) {
      successes++;
    }
  }

  for (int i = 0; i < up.size(); i++) {
    for (int j = up[i].size() - 1; j >= 0; j--) {
      cout << up[i][j] << " ";
    }
  }

  cout << successes << "\n";

  return 0;
}