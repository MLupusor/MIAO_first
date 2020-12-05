#include <bits/stdc++.h>

using namespace std;

int main()
{
  string line;
  vector<string> data;
  ifstream file("labirint.txt");

  while (getline(file, line))
  {
    data.push_back(line);
  }


  vector<pair<int, int>> initiale;
  for (int i = 0; i < data.size(); i++)
  {
    for (int j = 0; j < data[i].size(); j++)
    {
      if (data[i][j] == '$')
      {
        initiale.push_back({i + 1, j});
      }
    }
  }

  for (int q = 0; q < initiale.size(); q++)
  {
    stack<string> stiva;
    string flag = "";
    bool found = false;
    for (int i = initiale[q].first; i < data.size() && !found; i++)
    {
      for (int j = initiale[q].second; j < data[i].size(); j++)
      {
        if (data[i][j] == '@')
        {
          cout << flag << "\n";
          found = true;
          break;
        }
        if (data[i][j] == '#')
        {
          found = true;
          break;
        }
        if (data[i][j] == '(')
        {
          string f = stiva.top();
          stiva.pop();
          flag = f + flag;
          string nr = "";
          for (int k = 1; isdigit(data[i][j + k]); k++)
          {
            nr += data[i][j + k];
          }
          j = j - stoi(nr) - 1;
          continue;
        }
        if (data[i][j] == ')')
        {
          string f = stiva.top();
          stiva.pop();
          flag = flag + f;
          string nr = "";
          for (int k = 1; isdigit(data[i][j - k]); k++)
          {
            nr = nr + data[i][j - k];
          }
          j = j + stoi(nr) - 1;
          continue;
        }
        if (data[i][j] == '-')
        {
          string newFlag = "";
          for (int k = 1; k < flag.size(); k++)
          {
            newFlag += flag[k];
          }
          flag = newFlag;
          string nr = "";
          for (int k = 1; isdigit(data[i + k][j]); k++)
          {
            nr = nr + data[i + k][j];
          }
          i = i - stoi(nr);
          j--;
          continue;
        }
        if (data[i][j] == '+')
        {
          string newFlag = "";
          for (int k = 0; k < flag.size() - 1; k++)
          {
            newFlag += flag[k];
          }
          flag = newFlag;
          string nr = "";
          for (int k = 1; isdigit(data[i - k][j]); k++)
          {
            nr = nr + data[i - k][j];
          }
          i = i + stoi(nr);
          j--;
          continue;
        }
        if (data[i][j] == '%')
        {
          string newFlag = "";
          for (int k = flag.size() - 1; k >= 0; k--)
          {
            newFlag += flag[k];
          }
          flag = newFlag;
          i++;
          j--;
          continue;
        }
        if (data[i][j] == '[')
        {
          string ch = "";
          ch += data[i][j + 1];
          stiva.push(ch);
          j++;
          continue;
        }
        if (data[i][j] == ']')
        {
          string ch = "";
          ch += data[i][j - 1];
          stiva.push(ch);
          j -= 3;
          continue;
        }
        if (data[i][j] == '*')
        {
          string ch = "";
          ch += data[i - 1][j];
          stiva.push(ch);
          i -= 2;
          j--;
          continue;
        }
        if (data[i][j] == '.')
        {
          string ch = "";
          ch += data[i + 1][j];
          stiva.push(ch);
          i += 2;
          j--;
          continue;
        }
        if (data[i][j] == '<')
        {
          string nr = "";
          for (int k = 1; isdigit(data[i][j + k]); k++)
          {
            nr = nr + data[i][j + k];
          }
          j = j - stoi(nr) - 1;
          continue;
        }
        if (data[i][j] == '>')
        {
          string nr = "";
          for (int k = 1; isdigit(data[i][j - k]); k++)
          {
            nr = nr + data[i][j - k];
          }
          j = j + stoi(nr) - 1;
          continue;
        }
        if (data[i][j] == '^')
        {
          string nr = "";
          for (int k = 1; isdigit(data[i + k][j]); k++)
          {
            nr = nr + data[i + k][j];
          }
          i = i - stoi(nr);
          j--;
          continue;
        }
        if (data[i][j] == 'v')
        {
          string nr = "";
          for (int k = 1; isdigit(data[i - k][j]); k++)
          {
            nr = nr + data[i - k][j];
          }
          i = i + stoi(nr);
          j--;
          continue;
        }
      }
    }
  }

  return 0;
}