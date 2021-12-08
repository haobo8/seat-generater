#include <iostream>
#include <cstdio>
#include <ctime>
#define ddfor for (int i = 0, njn, cnt = 0; i < 4; i++){ if (i == 0) njn = 7; else njn = 8; for (int j = 0; j < njn; j++) 
#define ddforend }
using namespace std;
int d[999];
string ss[999][999], s[999] = {"龚搏扬", "袁伟伦", "章淏博", "赖思轩", "骆子墨", "金建烨", "杜心扬", "边麓元", "廖从云", "林彦含", "李星宸", "曾韦翔", "蔡朋骏", "吴周毅", "白宇轩", "王昊天", "郑俊永", "杨熙宇", "张宸瑞", "詹悦", "黄婧涵", "陈元畅", "程启航", "丁鹏元", "迟涵予", "张扬", "龙飞宇", "邱晨朔", "范青桐", "卢逸", "陈李"};
void d122(){ ddfor ss[i][j] = s[d[cnt++]]; ddforend }
void setseat(string a, int ax, int ay){ ddfor if (ss[i][j] == a)  swap(ss[i][j], ss[ax][ay]); ddforend }
void printgraph(){ ddfor {cout << ss[i][j] << "\t";} printf("\n"); ddforend }
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
begin:
    randnum(d, 31);
    d122();
    printgraph();
    int x; cin>>x;
    if(x==0) goto begin;
    return 0;
}
