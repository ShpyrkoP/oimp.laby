#include <iostream>
#include <vector>

using namespace std;
char* _strcat(char* StrDest, const char* StrSource)
{
  char* ptr = StrDest;
  while (*ptr != '\0')
  {
    ptr++;
  }
  while (*StrSource != '\0')
  {
    *ptr = *StrSource;
    ptr++;
    StrSource++;
  }
  *ptr = '\0';
  return StrDest;
}
int main()
{
  char StrDest[100] = "The function ";
  char StrSource[100] = "is working";
  _strcat(StrDest, StrSource);
  cout << StrDest << endl;


  //задание В
  char str[300];
  cout << "Enter string of words (less than 300 symbols): ";
  cin.getline(str, 300);
  char* sptr = str;
  vector<char*> words{};      //массив состоит из указателей на отделенные пробелом слова
  bool wordtf = false;
  while (*sptr != '\0')
  {
    if (*sptr == ' ')
    {
      wordtf = false;
      *sptr = '\0';
    }
    else {
      if (!wordtf)
      {
        words.emplace_back(sptr);
        wordtf = true;
      }
    }
    sptr++;
  }
  if (words.empty())
  {
    cout << "The string is empty";
  }
  else {
    char* min = words[0];      //указатель на 1 слово. пусть оно будет самым маленьким по размеру
    int i = 1;
    int minl = 0;           //длина слова без повторяющихся символов
    int let = 0;          //считает не повторяющиеся символы
    bool vis[256] = { false };
    while (min[minl] != '\0')
    {
      if (vis[min[minl]] == false)
      {
        vis[min[minl]] = true;
        let++;
      }
      minl++;
    }
    minl = let;
    for (i; i < words.size(); i++)
    {
      int nowl = 0;      //длина iтого слова в векторе
      char* now = words[i];      //указатель на iтое слово в векторе
      bool visnow[256] = { false };
      int letn = 0;
      while (now[nowl] != '\0')
      {
        if (visnow[now[nowl]] == false)
        {
          visnow[now[nowl]] = true;
          letn++;
        }
        nowl++;
      }
      nowl = letn;
      if (minl > nowl)
      {
        minl = nowl;
        min = words[i];
      }
      else
      {
        continue;
      }
    }
    cout << "Minimum: " << min << endl;
  }
}