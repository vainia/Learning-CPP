#include <iostream>
#include <list>

using namespace std;

const int MAXV = 20; // maksymalna liczba wierzchołków

// Zmienne globalne

int n,m;  // liczba wierzchołków i krawędzi w grafie
list<int> q, L[MAXV+1];
bool visited[MAXV+1];

// Rekurencyjna funkcja DFS wyszukująca ścieżki w grafie

void DFSHamilton(int v)
{
  q.push_back(v);
  if(q.size() == n)
  {
    bool test = false;
    for(list<int>::iterator i = L[v].begin(); i != L[v].end(); i++)
      if((*i) == 1)
      {
        test = true; break;
      }
    if(test) cout << "    Cykl"; else cout << "Sciezka";
    cout << " Hamiltona : ";
    for(list<int>::iterator i = q.begin(); i != q.end(); i++)
      cout << (* i) << " ";
    cout << endl;
  }
  else
  {
    visited[v] = true;
    for(list<int>::iterator x = L[v].begin(); x != L[v].end(); x++)
      if(!visited[* x]) DFSHamilton(* x);
    visited[v] = false;
  }
  q.pop_back();
}

int main(){

// Odczytujemy definicję grafu ze standardowego wejścia

  cin >> n >> m;
  for(int i = 1; i <= m; i++)
  {
    int v,w; cin >> v >> w;
    L[v].push_back(w);
    L[w].push_back(v);
  }
  cout << endl;

// Rozoczynamy wyszukiwanie cykli Hamiltona

  q.clear();
  for(int i = 1; i <= n; i++) visited[i] = false;
  DFSHamilton(1);

// Koniec

  cout << endl;
  system("PAUSE");
}
