/*
falta el delete
*/
#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std;

struct node
{
  int prefix_count;
  bool isEnd;
  struct node *child[26];
}*trie;

void init()
{ 
  trie = new node();
  trie->isEnd = false;
  trie->prefix_count = 0;
}

void insert(string word)
{
  node *current = trie;
  current->prefix_count++;
  
  for(int i = 0 ; i < word.length(); ++i)
  {
    int letter = word[i] - 'a'; 
    if(current->child[letter] == NULL)
      current->child[letter] = new node();
    current->child[letter]->prefix_count++;
    current = current->child[letter];   
  }
  current->isEnd = true;
}

bool search(string word)
{
  node *current = trie;
  for(int i = 0 ; i < word.length(); ++i)
  {
    int letter = word[i] - 'a';
    if(current->child[letter] == NULL)
        return false;   //not found
    current = current->child[letter];
  }
  return current->isEnd;
}

int words_with_prefix(string prefix)
{
  node *current = trie;
  for(int i = 0; i < prefix.length() ; ++i)
  {
    int letter = (int)prefix[i] - (int)'a';
    if(current->child[letter] == NULL)
      return 0;
    else
      current = current->child[letter];
  }
  return current->prefix_count;
}


int main()
{
  init();
  string s = "chandan";
  insert(s);
  s = "mittal";
  insert(s);
  s = "chirag";
  insert(s);
  s = "shashank";
  insert(s);
  s = "abhinav";
  insert(s);
  s = "arun";
  insert(s);
  s = "abhishek";
  insert(s);
  

  if(search("chanda"))
    printf("found chandan\n");
  else
    cout<<"asd"<<endl;
  if(search("arun"))
    printf("found arun\n");
  if(search("abhi"))
    printf("found abhi\n");
  else
    printf("not found abhi\n");
  
  printf("no of words with prefix abhi are %d\n",words_with_prefix("abhi"));
  printf("no of words with prefix ch are %d\n",words_with_prefix("ch"));
  printf("no of words with prefix k are %d\n ",words_with_prefix("k"));
  
  

  return 0;
}