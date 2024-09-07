#include<iostream>
using namespace std;;

// -------------------- ������� --------------------
/*
    ����:
        map[i][j]��ʾ����(i,j)��ֵ
        0��ʾ�յ�
        1��ʾ����
        2��ʾ����
    ��: map[3][6] = 1  ��ʾ(3,6)��λ���Ǻ���
*/
int map[19][19];

// ��ʾ��ǰ�غ���  ż����ʾ��������  ������ʾ��������
// ��: flag = 20 ��ʾ��ǰ�ǵ�[20]������  �ɺڷ�����
int flag;
// -------------------- ������� --------------------

// -------------------- service --------------------
/*
    ������: ����
    ����: ��ʼ����Ϸ����
        �����̵�ֵ��ʼ��Ϊ0
        ��ǰ�غ���Ϊ����(flag��Ϊ0)
    ����: void
    ����ֵ: void
*/
void init();

void init()
{
    memset(map, 0, sizeof(map));
}


/*
    *�ѵ�1
    ������: ����
    ����: ���ݴ��������(map��Ӧλ��)��flagֵ �ж������Ƿ��ʤ
    ����:
        x: ��ǰ�غ����ӵ�x����
        y: ��ǰ�غ����ӵ�y����
    ����ֵ:
        0��ʾû�л�ʤ
        1��ʾ����ʤ��
        2��ʾ����ʤ��
*/
int isWin(int x, int y);

int isWin(int x, int y)
{
    int status = flag % 2;  //0�� 1��
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
    ������: ����
    ����: ��ָ��λ������
        ���map[x][y]�ǿյ� ���޸�map[x][y]��ֵ:��Ϊ��Ӧ��ɫ(flag��Ӧ��ɫ)
        ���򲻲���
    ����:
        x: ��ǰ�غ����ӵ�x����
        y: ��ǰ�غ����ӵ�y����
    ����ֵ:
        0��ʾ����ʧ�� (�����Ѿ�����)
        1��ʾ���ӳɹ�

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
    ����: չʾѡ��, ��ҿ���������ѡ�������Ϸ, �������û��˳���Ϸ
        ������Ϸ: ������Ϸ���溯��gameView();
        ��������: �����ڴ�...
        �˳���Ϸ: ����exit(0);
*/
void menuView();

void menuView()
{
    cout << "1.������Ϸ" << '\n';
    cout << "2.��������" << '\n';
    cout << "3.�˳���Ϸ" << '\n';
    int choice=0;
    if (choice == 1) gameView();
    if (choice == 2);
    if (choice == 3) exit(0);
}
/*
    ������: ����
    ����: ����map���� ��ӡ��Ϸ����
    ����: void
    ����ֵ: void
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
    ������: ����
    ����: ����flag��ֵ  ��ӡ��Ϸʤ������  �û����԰�������ص����˵�
    ����: void
    ����ֵ: void
*/
void winView();

void winView()
{
    if (flag % 0) {
        cout << "����ʤ����666" << endl;
    }
    else cout << "����ʤ����666" << endl;
}
/*
    *�ѵ�2
    ������: ����
    ����: ��Ϸ��������
        ��ʼ����Ϸ����(���ú���init())
        while(1){
            ��ӡ��Ϸ����(���ú���gameView_ShowMap())
            ���������������

            ����(�������Ӻ���playerMove())
                (�������ʧ�� ���¿�ʼѭ��)

            �ж���Ϸ�Ƿ�ʤ��(����ʤ���жϺ���isWin())
                (�����Ϸʤ�� ����ʤ�����溯�� Ȼ�������ǰ����)
            �л����(�޸�flagֵ)
        }
    ����: void
    ����ֵ: void
*/
void gameView();
// -------------------- view --------------------

int main()
{
    menuView();
    return 0;
}

void init() {
    //�ڴ˴���ɴ���
}

int isWin(int x, int y) {
    //�ڴ˴���ɴ���
    return 0;
}

int playerMove(int x, int y) {
    //�ڴ˴���ɴ���
}

void menuView() {
    //�ڴ˴���ɴ���
}

void gameView_ShowMap() {
    //�ڴ˴���ɴ���
}

void winView() {
    //�ڴ˴���ɴ���
}

void gameView() {
    //�ڴ˴���ɴ���
}
