#include <bits/stdc++.h>

using namespace std;

int value(char r);
int romanToDecimal(string &str);

int main()
{

  string line;
  vector<string> data;
  ifstream file("1.4.txt");

  while (getline(file, line))
  {
    data.push_back(line);
  }

  vector<pair<string, string>> val;
  for (int i = 0; i < data.size(); i++)
  {
    string roman = "";
    int j = 0;
    for (; j < data[i].size(); j++)
    {
      if (data[i][j] == ':')
      {
        break;
      }
      else
      {
        roman += data[i][j];
      }
    }
    string key = "";
    for (j = j + 2; j < data[i].size(); j++)
    {
      key += data[i][j];
    }
    val.push_back({roman, key});
  }

  vector<pair<int, string>> valDecimals;
  for (int i = 0; i < val.size(); i++)
  {
    valDecimals.push_back({romanToDecimal(val[i].first), val[i].second});
  }


  sort(valDecimals.begin(), valDecimals.end());
  for (int i = 0; i < valDecimals.size(); i++) {
    cout << valDecimals[i].second;
    
  }
  cout << "\n";

  return 0;
}

int romanToDecimal(string &str)
{
  // Initialize result
  int res = 0;

  // Traverse given input
  for (int i = 0; i < str.length(); i++)
  {

    // Getting value of symbol s[i]
    int s1 = value(str[i]);

    if (i + 1 < str.length())
    {

      // Getting value of symbol s[i+1]
      int s2 = value(str[i + 1]);

      // Comparing both values
      if (s1 >= s2)
      {

        // Value of current symbol
        // is >= the next symbol
        res = res + s1;
      }
      else
      {

        // Value of current symbol
        // is < the next symbol
        res = res + s2 - s1;
        i++;
      }
    }
    else
    {
      res = res + s1;
    }
  }
  return res;
}

int value(char r)
{
  // I in roman is equal to
  // 1 in decimal
  if (r == 'I')
    return 1;

  // V in roman is equal to
  // 5 in decimal
  if (r == 'V')
    return 5;

  // X in roman is equal to
  // 10 in decimal
  if (r == 'X')
    return 10;

  // L in roman is equal to
  // 50 in decimal
  if (r == 'L')
    return 50;

  // C in roman is equal to
  // 100 in decimal
  if (r == 'C')
    return 100;

  // D in roman is equal to
  // 500 in decimal
  if (r == 'D')
    return 500;

  // M in roman is equal to
  // 1000 in decimal
  if (r == 'M')
    return 1000;

  return -1;
}