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
        cout << "Vui lòng nhập đúng ký tự để chơi!" << endl;
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
    cout << "Số bước nhảy: " << autodem << endl;
}

Game::~Game()
{
}

istream& getline (istream& is, string& str, char delim);
istream& getline (istream& is, string& str);

int main()
{
    Game game2;
    cout << game2 << endl;
    cout << "Game Start!!!" << endl;
    game2.random();
    cout << game2 << endl;
    cout << "Di chuyển số 0 để mảng về hình dạng ban đầu" << endl;
    cout << "Sử dụng các nút sau để di chuyển: " << endl;
    cout << "W: di chuyển số 0 lên trên" << endl;
    cout << "S: di chuyển số 0 xuống dưới" << endl;
    cout << "A: di chuyển số 0 sang trái" << endl;
    cout << "D: di chuyển số 0 sang phải" << endl;
    cout << "p: tự động chơi" << endl;
    int dem = 0;
    while (game2.isFinish() == false)
    {
        cout << "Nhập W, A, S or D để chơi: ";
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
    cout << "Số bước đã đi: " << dem;
    game2.~Game();
    return 0;
}