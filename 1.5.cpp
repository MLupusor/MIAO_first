#include <bits/stdc++.h>

using namespace std;

vector<pair<char, char>> key;
vector<pair<char, char>> newKeys;

char foundEncrypt(char e)
{
  for (int i = 0; i < key.size(); i++)
  {
    if (key[i].second == e)
    {
      return key[i].first;
    }
  }
  return e;
}

char foundDencrypt(char e)
{
  for (int i = 0; i < key.size(); i++)
  {
    if (key[i].first == e)
    {
      return key[i].second;
    }
  }
  return e;
}

vector<string> getAllWordsWithNrChars(vector<string> data, int nrChars)
{
  vector<string> result;
  for (int i = 0; i < data.size(); i++)
  {
    string word = "";
    for (int j = 0; j < data[i].size(); j++)
    {
      if (j + 1 == data[i].size())
      {
        if (word.size() == nrChars)
        {
          result.push_back(word);
        }
        word = "";
      }
      else if (data[i][j] == '.' || data[i][j] == '!' || data[i][j] == ',' || data[i][j] == ' ' || data[i][j] == '-')
      {
        if (word.size() == nrChars)
        {
          result.push_back(word);
        }
        word = "";
      }
      else
      {
        word += data[i][j];
      }
    }
  }
  return result;
}

bool isKey(char c)
{
  for (int i = 0; i < key.size(); i++)
  {
    if (key[i].second == c)
    {
      return true;
    }
  }
  return false;
}

bool isNewKeyNoExpected(char c)
{
  for (int i = 0; i < newKeys.size(); i++)
  {
    if (newKeys[i].first == c)
    {
      return true;
    }
  }
  return false;
}

bool isNewKey(char c, char expected)
{
  for (int i = 0; i < newKeys.size(); i++)
  {
    if (newKeys[i].first == c && newKeys[i].second == expected)
    {
      return true;
    }
  }
  return false;
}

vector<string> eliminDecryptets(vector<string> data)
{
  vector<string> result;
  for (int i = 0; i < data.size(); i++)
  {
    bool isAccesible = false;
    for (int j = 0; j < data[i].size(); j++)
    {
      if (!isKey(data[i][j]))
      {
        isAccesible = true;
      }
    }
    result.push_back(data[i]);
  }
  return result;
}

void searchInOrd(vector<string> data, string word)
{

  for (int i = 0; i < word.size(); i++)
  {
    vector<string> result;
    for (int j = 0; j < data.size(); j++)
    {
      if (isNewKey(data[j][i], word[i]))
      {
        result.push_back(data[j]);
      }
      else if (isKey(data[j][i]) && data[j][i] == word[i])
      {
        result.push_back(data[j]);
      }
      else if (!isKey(data[j][i]))
      {
        result.push_back(data[j]);
      }
    }
    data = result;
  }

  cout << "Word: " << word << "\nFounded: \n";
  for (int i = 0; i < data.size(); i++)
  {
    for (int j = 0; j < data[i].size(); j++)
    {
      if (!isKey(data[i][j]) && word[j] != data[i][j] && !isNewKeyNoExpected(data[i][j]))
      {
        cout << word[j] << " -> " << data[i][j] << "\n";
        newKeys.push_back({data[i][j], word[j]});
      }
    }
  }

  cout << "\n\n";
}

int main()
{
  string tryLine;
  vector<string> tryData;
  ifstream tryFile("new_out.txt");

  while (getline(tryFile, tryLine))
  {
    tryData.push_back(tryLine);
  }
  tryFile.close();

  key.push_back({'a', 'v'});
  key.push_back({'b', 'a'});
  key.push_back({'c', 'e'});
  key.push_back({'d', 'g'});
  key.push_back({'z', 'f'});
  key.push_back({'y', 'p'});
  key.push_back({'x', 'j'});
  key.push_back({'r', 'b'});
  key.push_back({'v', 'h'});
  key.push_back({'q', 'm'});
  key.push_back({'l', 'q'});
  key.push_back({'p', 'w'});
  key.push_back({'s', 'x'});
  key.push_back({'u', 's'});
  key.push_back({'w', 't'});
  key.push_back({'e', 'z'});

  // key.push_back({'m', 'r'});
  // key.push_back({'i', 'o'});
  // key.push_back({'o', 'i'});
  // key.push_back({'t', 'k'});
  // key.push_back({'f', 'y'});
  // key.push_back({'g', 'c'});
  // key.push_back({'h', 'u'});

  vector<string> tryDencrypted;

  for (int i = 0; i < tryData.size(); i++)
  {
    string newLine = "";
    for (int j = 0; j < tryData[i].size(); j++)
    {
      newLine += foundEncrypt(tryData[i][j]);
    }
    tryDencrypted.push_back(newLine);
  }

  searchInOrd(eliminDecryptets(getAllWordsWithNrChars(tryDencrypted, 5)), "olimp");
  searchInOrd(eliminDecryptets(getAllWordsWithNrChars(tryDencrypted, 9)), "ghintuita");

  for (int i = 0; i < newKeys.size(); i++)
  {
    key.push_back({newKeys[i].second, newKeys[i].first});
  }


  string line;
  vector<string> data;
  ifstream file("new_out.txt");

  while (getline(file, line))
  {
    data.push_back(line);
  }
  file.close();

  vector<string> dencrypted;

  for (int i = 0; i < tryData.size(); i++)
  {
    string newLine = "";
    for (int j = 0; j < tryData[i].size(); j++)
    {
      newLine += foundEncrypt(tryData[i][j]);
    }
    dencrypted.push_back(newLine);
  }

  for (int i = 0; i < dencrypted.size(); i++) {
    cout << dencrypted[i] << "\n";
  }

  cout << "\n\n";

  string lineEncrypt;
  vector<string> dataEncrypt;
  ifstream fileEncrypt("encryptThis.txt");

  while (getline(fileEncrypt, lineEncrypt))
  {
    dataEncrypt.push_back(lineEncrypt);
  }
  fileEncrypt.close();

  vector<string> encrypted;

  for (int i = 0; i < dataEncrypt.size(); i++)
  {
    string newLine = "";
    for (int j = 0; j < dataEncrypt[i].size(); j++)
    {
      newLine += foundDencrypt(dataEncrypt[i][j]);
    }
    encrypted.push_back(newLine);
  }

  for (int i = 0; i < encrypted.size(); i++) {
    cout << encrypted[i] << "\n";
  }

  return 0;
}