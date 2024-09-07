#include<iostream>
using namespace std;;

// -------------------- 数据设计 --------------------
/*
    棋盘:
        map[i][j]表示坐标(i,j)的值
        0表示空地
        1表示黑子
        2表示白子
    如: map[3][6] = 1  表示(3,6)的位置是黑子
*/
int map[19][19];

// 表示当前回合数  偶数表示黑棋落子  奇数表示白棋落子
// 如: flag = 20 表示当前是第[20]次落子  由黑方落子
int flag;
// -------------------- 数据设计 --------------------

// -------------------- service --------------------
/*
    负责人: 张三
    功能: 初始化游戏数据
        将棋盘的值初始化为0
        当前回合设为黑棋(flag设为0)
    参数: void
    返回值: void
*/
void init();

void init()
{
    memset(map, 0, sizeof(map));
}


/*
    *难点1
    负责人: 张三
    功能: 根据传入的坐标(map对应位置)和flag值 判断落点后是否获胜
    参数:
        x: 当前回合落子的x坐标
        y: 当前回合落子的y坐标
    返回值:
        0表示没有获胜
        1表示黑子胜利
        2表示白子胜利
*/
int isWin(int x, int y);

int isWin(int x, int y)
{
    int status = flag % 2;  //0黑 1白
    if (status == 0) {
        if (x - 2 >= 0 && x + 2 <= 18 && map[x - 2][y] == 1 && map[x - 1][y] == 1 && map[x + 1][y] == 1 && map[x + 2][y] == 1)  return 1;
        if (y - 2 >= 0 && y + 2 <= 18 && map[x][y - 2] == 1 && map[x][y - 1] == 1 && map[x][y + 1] == 1 && map[x][y + 2] == 1)  return 1;
        if (y - 2 >= 0 && y + 2 <= 18 && x - 2 >= 0 && x + 2 <= 18 && map[x - 2][y - 2] == 1 && map[x - 1][y - 1] == 1 && map[x + 1][y + 1] == 1 && map[x + 2][y + 2] == 1)  return 1;
        if (y - 2 >= 0 && y + 2 <= 18 && x - 2 >= 0 && x + 2 <= 18 && map[x - 2][y + 2] == 1 && map[x - 1][y + 1] == 1 && map[x + 1][y - 1] == 1 && map[x + 2][y - 2] == 1)  return 1;
    }
    else {
        if (x - 2 >= 0 && x + 2 <= 18 && map[x - 2][y] == 2 && map[x - 1][y] == 2 && map[x + 1][y] == 2 && map[x + 2][y] == 2)  return 2;
        if (y - 2 >= 0 && y + 2 <= 18 && map[x][y - 2] == 2 && map[x][y - 1] == 2 && map[x][y + 1] == 2 && map[x][y + 2] == 2)  return 2;
        if (y - 2 >= 0 && y + 2 <= 18 && x - 2 >= 0 && x + 2 <= 18 && map[x - 2][y - 2] == 2 && map[x - 1][y - 1] == 2 && map[x + 1][y + 1] == 2 && map[x + 2][y + 2] == 2)  return 2;
        if (y - 2 >= 0 && y + 2 <= 18 && x - 2 >= 0 && x + 2 <= 18 && map[x - 2][y + 2] == 2 && map[x - 1][y + 1] == 2 && map[x + 1][y - 1] == 2 && map[x + 2][y - 2] == 2)  return 2;
    }
    return 0;
}

/*
    负责人: 张三
    功能: 在指定位置落子
        如果map[x][y]是空地 则修改map[x][y]的值:改为相应颜色(flag对应颜色)
        否则不操作
    参数:
        x: 当前回合落子的x坐标
        y: 当前回合落子的y坐标
    返回值:
        0表示落子失败 (棋盘已经有子)
        1表示落子成功

*/
int playerMove(int x, int y);
// -------------------- service --------------------

int playerMove(int x, int y)
{
    if (map[x][y])  return 0;
    if (flag % 2 == 0) map[x][y] = 1;
    else map[x][y] = 2;
    return 1;
}

// -------------------- view --------------------
/*
    功能: 展示选项, 玩家可以在这里选择进入游戏, 进入设置或退出游戏
        进入游戏: 调用游戏界面函数gameView();
        进入设置: 敬请期待...
        退出游戏: 调用exit(0);
*/
void menuView();

void menuView()
{
    cout << "1.进入游戏" << '\n';
    cout << "2.进入设置" << '\n';
    cout << "3.退出游戏" << '\n';
    int choice=0;
    if (choice == 1) gameView();
    if (choice == 2);
    if (choice == 3) exit(0);
}
/*
    负责人: 张三
    功能: 根据map数组 打印游戏棋盘
    参数: void
    返回值: void
*/
void gameView_ShowMap();

void gameView_ShowMap()
{
    for(int i=0;i<=18;i++)
        for (int j = 0; i <= 18; j++)
        {
            cout << map[i][j] << " ";
        }
    cout << '\n';
}

/*
    负责人: 张三
    功能: 根据flag的值  打印游戏胜利界面  用户可以按任意键回到主菜单
    参数: void
    返回值: void
*/
void winView();

void winView()
{
    if (flag % 0) {
        cout << "白棋胜利，666" << endl;
    }
    else cout << "白棋胜利，666" << endl;
}
/*
    *难点2
    负责人: 张三
    功能: 游戏界面整合
        初始化游戏数据(调用函数init())
        while(1){
            打印游戏界面(调用函数gameView_ShowMap())
            接收玩家坐标输入

            落子(调用落子函数playerMove())
                (如果落子失败 重新开始循环)

            判断游戏是否胜利(调用胜利判断函数isWin())
                (如果游戏胜利 调用胜利界面函数 然后结束当前界面)
            切换玩家(修改flag值)
        }
    参数: void
    返回值: void
*/
void gameView();
// -------------------- view --------------------

int main()
{
    menuView();
    return 0;
}

void init() {
    //在此处完成代码
}

int isWin(int x, int y) {
    //在此处完成代码
    return 0;
}

int playerMove(int x, int y) {
    //在此处完成代码
}

void menuView() {
    //在此处完成代码
}

void gameView_ShowMap() {
    //在此处完成代码
}

void winView() {
    //在此处完成代码
}

void gameView() {
    //在此处完成代码
}
