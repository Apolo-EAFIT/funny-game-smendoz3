# funny-game-smendoz3
funny-game-smendoz3 created by GitHub Classroom

#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int main(){
  int n,raiz;
  scanf("%d %d",&n,&raiz);
  --raiz;

  vector<int> arr[1000];

  for(int i = 1,u,v;i<n;++i){
    scanf("%d %d",&u,&v);
    --u; --v;
    arr[u].push_back(v);
    arr[v].push_back(u);
  }

  int Q[1000],cola = 0,padre[1000];
  memset(padre,-1,sizeof(padre));

  Q[cola] = raiz; ++cola;
  padre[raiz] = -2;

  for(int i = 0;i<n;++i){
    int cur = Q[i];

    for(int j = arr[cur].size()-1;j>=0;--j){
      int sig = arr[cur][j];

      if(padre[sig]==-1){
        Q[cola] = sig; ++cola;
        padre[sig] = cur;
      }
    }
  }

  bool ganador[1000];

  for(int i = n-1;i>=0;--i){
    int cur = Q[i];
    ganador[cur] = false;

    for(int j = arr[cur].size()-1;j>=0;--j){
      int sig = arr[cur][j];

      if(padre[sig]==cur && !ganador[sig])
        ganador[cur] = true;
    }
  }

  if(!ganador[raiz]) printf("First player loses\n");
  else{
    int choose = n+1;

    for(int i = arr[raiz].size()-1;i>=0;--i){
      int sig = arr[raiz][i];

      if(padre[sig]==raiz && !ganador[sig] && sig<choose)
        choose = sig;
    }

    printf("First player wins flying to airport %d\n",choose+1);
  }

  return 0;
}

