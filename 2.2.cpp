#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, nr;
  vector<pair<int, int>> A;
  vector<int> B;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> nr;
    A.push_back({nr, 0});
  }
  for (int i = 0; i < n; i++)
  {
    cin >> nr;
    B.push_back(nr);
  }

  for (int i = 0; i < n; i++) {
    int count = 0;
    for (int j = i ; j < n; j++) {
      A[j].second++;
      count += A[j].first;
      if (count >= B[i]) {
        break;
      }
    }
  }

  int maxSunaturi = 0, nrSunaturi = 0;

  for (int i = 0; i < n; i++) {
    maxSunaturi = max(maxSunaturi, A[i].second);
  }

  for (int i = 0; i < n; i++) {
    if (A[i].second == maxSunaturi) {
      nrSunaturi++;
    }
  }
  
  cout << maxSunaturi << " " << nrSunaturi << "\n";

  return 0;
}