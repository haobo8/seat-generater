#include <cstdio>
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;
int al[99],a[99],b[99];
string s[99]={"廖从云","袁伟伦","林彦含","李星宸","曾韦翔","蔡朋骏","吴周毅","龚搏扬","白宇轩","王昊天","赖思轩","边麓元","郑俊永","金建烨","杨熙宇","张宸瑞","詹悦","黄婧涵","陈元畅","程启航","骆子墨","丁鹏元","章淏博","迟涵予","张扬","龙飞宇","邱晨朔","杜心扬","范青桐","卢逸","陈李石农"};

// vector<int> vec;
// bool aused[99];
int seat221(int x,int y)
{
    x--;    y--;
    if(x==0)    return y;
    if(x==1)    return 7+y;
    if(x==2)    return 15+y;
    if(x==3)    return 23+y;
    return -1;
}
int seatmate(int x)
{
    if(x<7)
    {
        if(x%2==1)
        {
            return  x-1;
        }
        if(x%2==0)
        {
            return x+1;
        }
    }
    else
    {
        if(x%2==1)
        {
            return x+1;
        }
        if(x%2==0)
        {
            return x-1;
        }
    }
    return 0;
}
// void getgiveway()
// {
//     freopen("giveway.txt","r",stdin);
//     int n;
//     scanf("%d",&n);
//     string nm;
//     for(int i=0,gw,x,y;i<n;i++)
//     {
//         scanf("%d",&gw);
//         cin>>nm;
//         scanf("%d%d",&x,&y);
//         int d=seat221(x,y);
//         al[d]=1;
//         a[gw]=d;
//         b[d]=gw;
//     }
//     fclose(stdin);
// }
// void set()
// {

// }
void printg()
{
    int cnt=0,line=0;
    for(int i=0;i<4;i++)
    {
        if(i<1)
        {
            line=7;
        }
        else
        {
            line=8;
        }
        for(int j=0;j<line;j++)
        {
            cout<<s[b[cnt++]];
            // cout<<b[cnt++];
            if(b[cnt-1]==30) 
            {
                continue;
            }
            printf("\t");
        }
        printf("\n");
    }
}
void create()
{
    memset(al,-1,sizeof(al));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    int rcnt=31,k,ah,ong;
    for(int i=0;i<31;i++)
    {
        if(a[i]!=0) continue;
        k=rand()%(rcnt--);
        ong=-1;
        while(k>=0)
        {
            if(al[++ong]<0)
            {
                k--;
            }
        }
        al[ong]=1;
        a[i]=ong;
        b[ong]=i;
        if(i==0)
        {
            al[seatmate(ong)]=1;
            a[1]=seatmate(ong);
            b[seatmate(ong)]=1;
            rcnt--;
        }
    }
    printg();
}
// void change2g()
// {
//     int x1,y1,x2,y2;
//     int T;
//     scanf("%d",&T);
//     for(int i=0;i<T;i++)
//     {
//         scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
//         printf("%d %d\n",a[seat221(x1,y1)],a[seat221(x2,y2)]);
//         swap(a[seat221(x1,y1)],a[seat221(x2,y2)]);
//     }
// }
// void change() 
// {
//     freopen("giveway.txt","w",stdout);
//     int n;
//     scanf("%d",&n);
//     for(int i=0,x1,y1,x2,y2,which;i<n;i++)
//     {
//         scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&which);
//         int d1=seat221(x1,y1);  int d2=seat221(x2,y2);
//         swap(a[b[d1]],a[b[d2]]);
//         if(which==1)
//         {
//             vec.push_back(b[d1]);
//         }
//         else 
//         {
//             vec.push_back(b[d2]);
//         }
//     }
//     fclose(stdout);
// }
// void setgiveway()
// {
//     freopen("giveway.txt","w",stdin);
//     int si=vec.size();
//     printf("%d\n",si);
//     int x;
//     for(vector<int>::iterator it=vec.begin();it!=vec.end();++it)
//     {
//         int pp=*it;
//         printf("%d ",pp);
//         cout<<a[pp]<<endl;
//     }
//     fclose(stdout);
// }
int main()
{
    // getgiveway();
remakeagraph:
    srand(time(NULL));
    // set();
    create();
    bool x;
    cin>>x;
    if(x==0)
    {
        goto remakeagraph;
    }
    // change2g();
    // change();
    // setgiveway();
    freopen("seat.txt","w",stdout);
    printg();
    fclose(stdout);
    return 0;
}