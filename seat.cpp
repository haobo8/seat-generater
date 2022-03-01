#include <iostream>
#include <cstdio>
#include <ctime>
#define ddfor for (int i = 0, cnt = 0; i < nx; i++){ for (int j = 0; j < ny && (i*ny+j)<n ; j++) 
#define ddforend }
using namespace std;
int d[999],n,nx,ny;
string ss[999][999], s[999];
void d122(){ ddfor ss[i][j] = s[d[cnt++]]; ddforend }
void setseat(string a, int ax, int ay){ ddfor if (ss[i][j] == a)  swap(ss[i][j], ss[ax-1][ay-1]); ddforend }
void printgraph(){ ddfor {cout << ss[i][j] << "\t"; if(j%2==1){}} printf("\n"); ddforend }
void seatmate(string a, string b)
{
    int ax, ay, bx, by;
    ddfor {if (ss[i][j] == a) {ax = i, ay = j;} if (ss[i][j] == b) {bx = i, by = j;}} ddforend
    if (ax != 0 && ay != 6) swap(ss[ax][ay % 2 == 0 ? ay + 1 : ay - 1], ss[bx][by]);
    else                    swap(ss[ax][ay], ss[bx][by % 2 == 0 ? by + 1 : by - 1]);
}
void randnum(int *x, int awa)
{
    int k, ong, rcnt = awa, vis[999];
    memset(vis, -1, sizeof(vis));
    for (int i = 0; i < awa; i++)
    {
        k = rand() % (rcnt--);
        ong = -1;
        while (k >= 0)  if (vis[++ong] < 0) k--;
        vis[ong] = 1;
        *(x + i) = ong;
    }
}
int main()
{
    srand(time(NULL));
    freopen("name.txt","r",stdin);
    scanf("%d%d%d",&n,&nx,&ny);
    randnum(d, n);
    for(int i=0;i<n;i++)    cin>>s[i];
    d122();
/*
Add the requirements here
for example:
seatmate("A","B") this is make A and B become the seat mate
setseat("A",1,1)  this is make A to seat at the place- 1 line, 1 column
*/
    
    
    
    printgraph();
    freopen("seat.txt","w",stdout);
    printgraph();
    fclose(stdout);
    return 0;
}
