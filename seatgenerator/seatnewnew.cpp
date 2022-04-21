#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int n = 32;
const int sach[9] = {8, 8, 8, 9};
int nfs = 0;
string namelist[999] = {"章淏博", "金建烨", "袁伟伦", "廖从云", "边麓元", "骆子墨", "龚搏扬", "赖思轩", "杜心扬", "林彦含", "李星宸", "曾韦翔", "蔡朋骏", "吴周毅", "白宇轩", "王昊天", "郑俊永", "杨熙宇", "张宸瑞", "詹悦", "黄婧涵", "陈元畅", "程启航", "丁鹏元", "迟涵予", "张扬", "龙飞宇", "邱晨朔", "范青桐", "卢逸", "陈李", "石清泓"};
map<string, int> keylist;
struct studentlink
{
    int x, y;
    string name;
    int num, vis;
    int lp;
} stu[999], fstu[9][999];
vector<struct studentlink> seat[9];
int fstucnt[9];
bool ms[9][9];
vector<string> bn;
struct setpos
{
    int x, y;
    string name;
} sps[99];
int spscnt = 0;
void seatmate(string x, string y)
{
    int xpos = keylist[x], ypos = keylist[y];
    stu[xpos].num++;
    stu[xpos].name = x + "\t" + y;
    stu[ypos].num = 0;
    stu[ypos].name = "";
}
void changepos(int x1, int y1, int x2, int y2s, int y2e)
{
    if (y2s == y2e)
    {
        struct studentlink exc;
        exc = seat[x1][y1];
        seat[x1][y1] = seat[x2][y2s];
        seat[x2][y2s] = exc;
    }
    if (y2s + 1 == y2e)
    {
        struct studentlink exc1l, exc1r, exc2;

        exc1l.name = seat[x1][y1].name.substr(0, seat[x1][y1].name.find("\t"));
        exc1r.name = seat[x1][y1].name.substr(seat[x1][y1].name.find("\t") + 1);
        exc1l.num = exc1r.num = 1;
        exc2.name = string(seat[x2][y2s].name + "\t" + seat[x2][y2e].name);
        exc2.num = 2;
        seat[x1][y1] = exc2;
        seat[x2][y2s] = exc1l;
        seat[x2][y2e] = exc1r;
    }
}
void setarea(string name, int num, int x1, int y1, int x2, int y2)
{
    int ca = 0;
    vector<int> xis, ysis, yeis;
    for (int i = x1; i <= x2; i++)
    {
        int ncp = 0;
        for (int j = 0; j < seat[i].size(); j++)
        {
            if (seat[i][j].name == name && ncp >= y1 && ncp <= y2)
            {
                ca = 1;
            }
            if (num == 1 && (seat[i][j].num == 1 && seat[i][j].lp == -1 && ncp >= y1 && ncp <= y2))
            {
                xis.push_back(i);
                ysis.push_back(j);
                yeis.push_back(j);
            }
            if (num == 2 && (seat[i][j].num == 1 && seat[i][j + 1].num == 1 && seat[i][j].lp == -1 && seat[i][j + 1].lp == -1 && ncp >= y1 && ncp + 1 <= y2 && ms[i][ncp] == 0))
            {
                xis.push_back(i);
                ysis.push_back(j);
                yeis.push_back(j + 1);
            }
            if (num == 2 && (seat[i][j].num == 2 && seat[i][j].lp == -1 && ncp >= y1 && ncp <= y2))
            {
                xis.push_back(i);
                ysis.push_back(j);
                yeis.push_back(j);
            }
            ncp += seat[i][j].num;
        }
    }
    if (ca != 1)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < seat[i].size(); j++)
            {
                if (seat[i][j].name == name)
                {
                    int k = rand() % xis.size();
                    changepos(i, j, xis[k], ysis[k], yeis[k]);
                }
            }
        }
    }
}
void setseat(string name, int x, int y)
{
    if (x < 3)
    {
        if (y % 2 == 1)
        {
            ms[x][y - 1] = 1;
        }
    }
    else
    {
        if (y == 1 || y < 7 && y > 2 || y == 8)
        {
            ms[x][y - 1] = 1;
        }
    }
    sps[spscnt].x = x;
    sps[spscnt].y = y;
    sps[spscnt].name = name;
    spscnt++;
}
void generatebound()
{
    spscnt = 0;
    for (int i = 0; i < n; i++)
    {
        sps[i].x = 0;
        sps[i].y = 0;
        sps[i].name = "";
    }
    for (int i = 0; i < n; i++)
    {
        stu[i].name = "";
        stu[i].num = 0;
        stu[i].vis = -1;
        stu[i].lp = -1;
    }
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j < sach[i]; j++)
        {
            fstu[i][j].name = "";
            fstu[i][j].num = 0;
            fstu[i][j].vis = -1;
            fstu[i][j].lp = -1;
        }
    }
    for (int i = 0; i <= 2; i++)
        fstucnt[i] = 0;
    for (int i = 0; i < 4; i++)
        seat[i].clear();
    memset(ms, 0, sizeof(ms));

    // tip:此处必须顺序排列，别问我为什么，我也不知道
    setseat("陈李", 0, 3);
    setseat("易诗兰", 0, 7);
    for (int i = 0; i < n; i++)
    {
        bool jf = 0;
        for (int j = 0; j < spscnt; j++)
        {
            if (sps[j].name == namelist[i])
            {
                jf = 1;
                break;
            }
        }
        if (jf == 1)
        {
            continue;
        }
        keylist[namelist[i]] = i;
        stu[i].name = namelist[i];
        stu[i].num = 1;
    }
    for (int cc = 0; cc < 4; cc++)
    {
        for (int ccn = 0; ccn < sach[cc]; ccn++)
        {
            if (ccn % 2 == 1 && cc < 3 || cc == 3 && (ccn == 1 || ccn == 6 || ccn == 8) || cc == 0 && ccn == 6)
            {
                ms[cc][ccn] = 1;
            }
        }
    }
    int wc=(time(NULL)-1583683200)/604800;
    switch(wc%3)
    {
        case 0:
            seatmate("林彦含","黄婧涵");
            break;
        case 1:
            seatmate("黄婧涵","詹悦");
            break;
        case 2:
            seatmate("詹悦","林彦含");
            break;
    }
    seatmate("章淏博", "袁伟伦");
    seatmate("赖思轩", "骆子墨");
    seatmate("白宇轩", "迟涵予");
    seatmate("廖从云", "边麓元");
    for (int i = 0; i < n; i++)
    {
        if (stu[i].num != 0)
        {
            fstu[stu[i].num][fstucnt[stu[i].num]++] = stu[i];
        }
    }
}
/*
** ** ** *
** ** ** **
** ** ** **
** ***** **
*/
void randseat()
{
    int cc = 0, ccn = 0, ccnm = sach[cc];
    while (cc < 4)
    {
        for (int i = 0; i < spscnt; i++)
        {
            if (cc == sps[i].x && ccn == sps[i].y)
            {
                struct studentlink temp;
                temp.vis = -1;
                temp.num = 1;
                temp.name = sps[i].name;
                temp.lp = 1;
                seat[cc].push_back(temp);
                ccn++;
            }
        }
        if (ccn == ccnm)
        {
            ccn = 0;
            cc++;
            ccnm = sach[cc];
            continue;
        }
        if (ms[cc][ccn] == 1)
        {
            int k = rand() % (fstucnt[1]--), ong = -1;
            while (k >= 0)
                if (fstu[1][++ong].vis < 0)
                    k--;
            fstu[1][ong].vis = 1;
            seat[cc].push_back(fstu[1][ong]);
            ccn++;
        }
        else
        {
            int k = rand() % (fstucnt[1] + fstucnt[2]), ong = -1;
            if (k < fstucnt[1])
            {
                fstucnt[1]--;
                while (k >= 0)
                    if (fstu[1][++ong].vis < 0)
                        k--;
                fstu[1][ong].vis = 1;
                seat[cc].push_back(fstu[1][ong]);
                ccn++;
            }
            else
            {
                fstucnt[2]--;
                k -= fstucnt[1];
                while (k >= 0)
                    if (fstu[2][++ong].vis < 0)
                        k--;
                fstu[2][ong].vis = 1;
                seat[cc].push_back(fstu[2][ong]);
                ccn += 2;
            }
        }
    }
}
void print()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0, curcnt = 0; j < seat[i].size(); j++)
        {
            curcnt += seat[i][j].num;
            cout << seat[i][j].name << "\t";
            if (curcnt % 2 == 0 && i < 3)
            {
                cout << "\t";
            }
            if (i == 3 && (curcnt == 2 || curcnt == 7))
            {
                cout << "\t";
            }
        }
        cout << endl;
    }
}
int main()
{
    srand(time(NULL));
    cout << "y. 排座位 n. 仅转换" << endl;
    string fg;
    cin >> fg;
    if (fg == "n")
    {
        return 0;
    }
begin:
    generatebound();
    randseat();
    setarea("章淏博\t袁伟伦", 2, 2, 2, 3, 5);
    setarea("廖从云\t边麓元", 2, 0, 2, 1, 5);
    print();
    cout << "Yes or No?(y or n)";
    string x;
    cin >> x;
    if (x != "y")
    {
        goto begin;
    }
    freopen("seat.txt", "w", stdout);
    print();
    fclose(stdout);
    return 0;
}