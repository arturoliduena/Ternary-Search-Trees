#include <iostream>
using namespace std;

typedef struct Node *TST;

struct Node
{
  char c;
  TST left, mid, right;
};

// search for s[i..] in the (sub)TST t
bool search(TST t, const string &s, int i)
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

// insert s[i..] in the (sub)TST t
TST insert(TST t, const string &s, int i)
{
  if (t == 0)
    return new Node{s[i], 0, (s[i] == '\0' ? 0 : insert(0, s, i + 1)), 0};
  if (s[i] < t->c)
    t->left = insert(t->left, s, i);
  else if (s[i] > t->c)
    t->right = insert(t->right, s, i);
  else
    t->mid = insert(t->mid, s, i + 1);
  return t;
};

int main()
{
}