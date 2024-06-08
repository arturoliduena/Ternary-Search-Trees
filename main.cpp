#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

typedef struct Node *TST;

struct Node
{
  char c;
  Node *left, *mid, *right;
  bool isEndOfString;
  Node(char ch) : c(ch), left(nullptr), mid(nullptr), right(nullptr), isEndOfString(false) {}
};

class TernarySearchTree
{
private:
  Node *root;
  unordered_set<string> stringSet;

  Node *insert(Node *t, const string &s, int i)
  {
    if (t == nullptr)
      t = new Node(s[i]);

    if (s[i] < t->c)
      t->left = insert(t->left, s, i);
    else if (s[i] > t->c)
      t->right = insert(t->right, s, i);
    else
    {
      if (i + 1 < s.size())
        t->mid = insert(t->mid, s, i + 1);
      else
        t->isEndOfString = true;
    }
    return t;
  }

  Node *erase(Node *t, const string &s, int i)
  {
    if (t == nullptr)
      return nullptr;

    if (s[i] < t->c)
      t->left = erase(t->left, s, i);
    else if (s[i] > t->c)
      t->right = erase(t->right, s, i);
    else
    {
      if (i + 1 < s.size())
        t->mid = erase(t->mid, s, i + 1);
      else
        t->isEndOfString = false;
    }
    return t;
  }

  // search for s[i..] in the (sub)TST t
  bool search(Node *t, const string &s, int i)
  {
    if (t == 0)
      return false;
    if (s[i] < t->c)
      return search(t->left, s, i);
    if (s[i] > t->c)
      return search(t->right, s, i);
    if (s[i] == '\0')
      return true;
    return search(t->mid, s, i + 1);
  }

  void clear(Node *&t)
  {
    if (t == nullptr)
      return;
    clear(t->left);
    clear(t->mid);
    clear(t->right);
    delete t;
    t = nullptr;
  }

  bool endsWith(const string &word, const string &suffix)
  {
    if (suffix.size() > word.size())
    {
      return false;
    }
    return equal(suffix.rbegin(), suffix.rend(), word.rbegin());
  }

public:
  TernarySearchTree() : root(nullptr) {}

  ~TernarySearchTree()
  {
    clear(root);
    stringSet.clear();
  }

  void insert(const string &s)
  {
    if (stringSet.find(s) == stringSet.end())
    {
      root = insert(root, s, 0);
      stringSet.insert(s);
    }
  }

  void erase(const string &s)
  {
    if (stringSet.find(s) != stringSet.end())
    {
      root = erase(root, s, 0);
      stringSet.erase(s);
    }
  }

  void reset()
  {
    // clear(root);
    root = nullptr;
    stringSet.clear();
  }

  // Function to count words ending with a given substring in an unordered_set
  int countWordsEndingWith(const string &suffix)
  {
    int count = 0;
    for (const auto &word : stringSet)
    {
      if (endsWith(word, suffix))
      {
        count++;
      }
    }
    return count;
  }
};

int main()
{
  TernarySearchTree ds;
  string operation, s;

  while (cin >> operation)
  {
    if (operation == "I")
    {
      cin >> s;
      ds.insert(s);
    }
    else if (operation == "E")
    {
      cin >> s;
      ds.erase(s);
    }
    else if (operation == "C")
    {
      cin >> s;
      cout << ds.countWordsEndingWith(s) << endl;
    }
    else if (operation == "R")
    {
      ds.reset();
      cout << "---" << endl;
    }
  }

  return 0;
}
