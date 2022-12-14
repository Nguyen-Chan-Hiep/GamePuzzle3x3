#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string.h>
#include <stdlib.h>
using namespace std;
class Game
{
    int a[3][3];
    int x0, y0;

public:
    Game();
    ~Game();
    friend ostream &operator<<(ostream &os, Game &r);
    void up();
    void down();
    void left();
    void right();
    void isUp();
    void isDown();
    void isLeft();
    void isRight();
    void mix(int k);
    void random();
    void play(char c);
    void autoPlay();
    bool isFinish();
};
Game::Game()
{
    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = 3;
    a[1][0] = 4;
    a[1][1] = 5;
    a[1][2] = 6;
    a[2][0] = 7;
    a[2][1] = 8;
    a[2][2] = 0;
    x0 = y0 = 2;
}
ostream &operator<<(ostream &os, Game &r)
{
    os << r.a[0][0] << " | " << r.a[0][1] << " | " << r.a[0][2] << endl;
    os << r.a[1][0] << " | " << r.a[1][1] << " | " << r.a[1][2] << endl;
    os << r.a[2][0] << " | " << r.a[2][1] << " | " << r.a[2][2];
    return os;
}
void Game::up()
{
    if (x0 != 0)
    {
        a[x0][y0] = a[x0 - 1][y0];
        a[x0 - 1][y0] = 0;
        x0 = x0 - 1;
    }
}
void Game::down()
{
    if (x0 != 2)
    {
        a[x0][y0] = a[x0 + 1][y0];
        a[x0 + 1][y0] = 0;
        x0 = x0 + 1;
    }
}
void Game::left()
{
    if (y0 != 0)
    {
        a[x0][y0] = a[x0][y0 - 1];
        a[x0][y0 - 1] = 0;
        y0 = y0 - 1;
    }
}
void Game::right()
{
    if (y0 != 2)
    {
        a[x0][y0] = a[x0][y0 + 1];
        a[x0][y0 + 1] = 0;
        y0 = y0 + 1;
    }
}

void Game::mix(int k)
{
    switch (k)
    {
    case 1:
        up();
        break;
    case 2:
        down();
        break;
    case 3:
        left();
        break;
    case 4:
        right();
        break;
    default:
        break;
    }
}

void Game::isUp()
{
    if (x0 != 0)
    {
        up();
        cout << "Up sucses" << endl;
    }
    else
    {
        cout << "Can't up" << endl;
    }
}

void Game::isDown()
{
    if (x0 != 2)
    {
        down();
        cout << "Down sucses" << endl;
    }
    else
    {
        cout << "Can't down" << endl;
    }
}

void Game::isLeft()
{
    if (y0 != 0)
    {
        left();
        cout << "Left sucses" << endl;
    }
    else
    {
        cout << "Can't left" << endl;
    }
}

void Game::isRight()
{
    if (y0 != 2)
    {
        right();
        cout << "Right sucses" << endl;
    }
    else
    {
        cout << "Can't right" << endl;
    }
}

void Game::random()
{
    srand(time(0));
    int step = rand();
    for (int i = 0; i < step; i++)
    {
        int ran = rand() % 4 + 1;
        mix(ran);
    }
}

void Game::play(char c)
{
    switch (c)
    {
    case 'w':
        isUp();
        break;
    case 's':
        isDown();
        break;
    case 'a':
        isLeft();
        break;
    case 'd':
        isRight();
        break;
    default:
        cout << "Vui l??ng nh???p ????ng k?? t??? ????? ch??i!" << endl;
        break;
    }
}

bool Game::isFinish()
{
    if (a[0][0] == 1 &&
        a[0][1] == 2 &&
        a[0][2] == 3 &&
        a[1][0] == 4 &&
        a[1][1] == 5 &&
        a[1][2] == 6 &&
        a[2][0] == 7 &&
        a[2][1] == 8 &&
        a[2][2] == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Game::autoPlay()
{
	srand(time(0));
    int autodem = 0;
    while (isFinish() == false)
    {
        int ran = rand() % 4 + 1;
        mix(ran);
        autodem++;
    }
    cout << "S??? b?????c nh???y: " << autodem << endl;
}

Game::~Game()
{
}

int main()
{
    Game game2;
    cout << game2 << endl;
    cout << "Game Start!!!" << endl;
    game2.random();
    cout << game2 << endl;
    cout << "Di chuy???n s??? 0 ????? m???ng v??? h??nh d???ng ban ?????u" << endl;
    cout << "S??? d???ng c??c n??t sau ????? di chuy???n: " << endl;
    cout << "W: di chuy???n s??? 0 l??n tr??n" << endl;
    cout << "S: di chuy???n s??? 0 xu???ng d?????i" << endl;
    cout << "A: di chuy???n s??? 0 sang tr??i" << endl;
    cout << "D: di chuy???n s??? 0 sang ph???i" << endl;
    cout << "p: t??? ?????ng ch??i" << endl;
    int dem = 0;
    while (game2.isFinish() == false)
    {
        cout << "Nh???p W, A, S or D ????? ch??i: ";
        char c;
        cin >> c;
        if (c == 'p')
        {
            game2.autoPlay();
            cout << game2 << endl;
            break;
        }
        else
        {
        	
            game2.play(c);
            cout << game2 << endl;
            dem++;
        }
    }
    cout << "S??? b?????c ???? ??i: " << dem;
    game2.~Game();
    return 0;
}