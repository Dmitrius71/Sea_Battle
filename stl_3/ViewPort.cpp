
#include "ViewPort.h"
#include<iostream>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

Coord ViewPort::GetShipCoordinate()
{
    Coord coord;
    int Derection;
    srand(time(NULL));
    cout << "                    ||==============================================================================|| \n"; Sleep(100);
    cout << "                    ||       �������� ������� ����������� ��������                                  || \n"; Sleep(100);
    cout << "                    ||       ���� �������� �������                           1                      || \n"; Sleep(100);
    cout << "                    ||       ���� �������  �������                           2                      || \n"; Sleep(100);
    cout << "                    ||============================================================================= || \n"; Sleep(100);
    cout << "                                    ";
    cin >> Derection;

    if (Derection == 2)
    {
        do
        {
            srand(time(NULL));
            cout << "                    ||==============================================================================|| \n"; Sleep(100);
            cout << "                    ||                                                                              || \n"; Sleep(100);
            cout << "                    ||                          ������� ���������� �������                          || \n"; Sleep(100);
            cout << "                    ||                                                                              || \n"; Sleep(100);
            cout << "                    ||                          ������� ����� ������                                || \n"; Sleep(100);
            cout << "                    ||                                                                              || \n"; Sleep(100);
            cout << "                    ||============================================================================= || \n"; Sleep(100);
            cout << endl;
            cout << "                                                "; cin >> coord.row;
            cout << endl;
            cout << endl;
            cout << endl;
            Sleep(200);
            cout << "                    ||==============================================================================|| \n"; Sleep(100);
            cout << "                    ||                                                                              || \n"; Sleep(100);
            cout << "                    ||                          ������� ���������� �������                          || \n"; Sleep(100);
            cout << "                    ||                                                                              || \n"; Sleep(100);
            cout << "                    ||                          ������� ����� �������                               || \n"; Sleep(100);
            cout << "                    ||                                                                              || \n"; Sleep(100);
            cout << "                    ||============================================================================= || \n"; Sleep(100);
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "                                                  "; cin >> coord.col;
            cout << endl;
            coord.row--;
            coord.col--;
        } while (coord.row < 0 || coord.row > 9 || coord.col < 0 || coord.col > 9);
    }

    else if (Derection == 1)
    {
        do
        {
            coord.row = rand() % 10;
            Sleep(100);
            coord.col = rand() % 10;
            coord.row--;
            coord.col--;
        } while (coord.row < 0 || coord.row > 9 || coord.col < 0 || coord.col > 9);
    }
    return coord;
}

Coord ViewPort::GetShipCoordinateRand()
{
    Coord coord;
    do
    {
        coord.row = rand() % 10;
        Sleep(500);
        coord.col = rand() % 10;
        coord.row--;
        coord.col--;
    } while (coord.row < 0 || coord.row > 9 || coord.col < 0 || coord.col > 9);
    return coord;
}

int ViewPort::GetShipSize()
{
    int shipSize;
    cout << endl;
    cout << endl;
    cout << "                    ||==============================================================================|| \n"; Sleep(100);
    cout << "                    ||                                                                              || \n"; Sleep(100);
    cout << "                    ||                          ������� ������ �������                              || \n"; Sleep(100);
    cout << "                    ||                                                                              || \n"; Sleep(100);
    cout << "                    ||============================================================================= || \n"; Sleep(100);
    cout << endl;
    cout << "                                                    ";  std::cin >> shipSize;
    cout << endl;
   
    return shipSize;
}

int ViewPort::GetShipSizeRand()
{
    int shipSize;
  

    return shipSize=rand()%4;

}

void ViewPort::ShowShips(int array[])
{
    for (int i = 1; i < 5; i++)
    {
        /*std::cout << "Ship at size = " << i << " is = " << array[i] << '\n';*/
        cout << "                    ||==============================================================================|| \n"; Sleep(100);
        cout << "                    ||                                                                              || \n"; Sleep(100);
        cout << "                    ||                ������ �������  " << i << "  ��������  ��������  " << array[i] <<  "                      || \n"; Sleep(100);
        cout << "                    ||                                                                              || \n"; Sleep(100);
        cout << "                    ||============================================================================= || \n"; Sleep(100);
    }
}

ShipDirection ViewPort::GetShipDirection()
{
    /*std::cout << "Input direction of ship:\n1-Horizontal\n2-Vertical\nDirection: ";*/

    cout << "                    ||==============================================================================|| \n"; Sleep(100);
    cout << "                    ||               ��� ���������� �������?                                        || \n"; Sleep(100);
    cout << "                    ||               ���� �� ��������� �������        1                             || \n"; Sleep(100);
    cout << "                    ||               ���� �� ����������� �������      2                             || \n"; Sleep(100);
    cout << "                    ||============================================================================= || \n"; Sleep(100);
    int direction;
    cout << "                                           "; cin >> direction;
    return (direction == 1) ? ShipDirection::HORIZONTAL : ShipDirection::VERTICAL;
}

ShipDirection ViewPort::GetShipDirectionRandom()
{
    int direction;
    direction=rand()%2;
    return (direction == 1) ? ShipDirection::HORIZONTAL : ShipDirection::VERTICAL;
}

Coord ViewPort::GetShootCoordinate()
{
    Coord coord;
    do
    {
        std::cout << "Input coordinate of shoot\n";
        std::cout << "Input ROW (1-10): ";
        std::cin >> coord.row;
        coord.row--;
        std::cout << "Input COL (1-10): ";
        std::cin >> coord.col;
        coord.col--;
    } while (coord.row < 0 || coord.row > 9 || coord.col < 0 || coord.col > 9);
    return coord;
}

std::string ViewPort::GetHumanName()
{

    PlaySound(TEXT("I:\\3. OOP C++\\�������� ������\\stl_3\\stl_3\\stl_3\\1.wav"), NULL, SND_ASYNC);
    setlocale(LC_ALL, "rus");

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "                       ||==================================================================================||\n";
    cout << "                       ||                                                                      ===         ||\n"; Sleep(200);
    cout << "                       ||    ___     ___    ______    ______    _____    __   __   ______    __   __       ||\n"; Sleep(200);
    cout << "                       ||   |   \\   /   |  |  __  |  |  __  |  | ____|  |  | / /  |  __  |  |  | |  |      ||\n"; Sleep(200);
    cout << "                       ||   |    \\_/    |  | |  | |  | |__| |  | |      |  |/ /   | |  | |  |  |/   |      || \n"; Sleep(200);
    cout << "                       ||   |  |\\___/|  |  | |__| |  |   ___|  | |___   |  |\\ \\   | |__| |  |   /|  |      ||  \n"; Sleep(300);
    cout << "                       ||   |__|     |__|  |______|  |__|      |_____|  |__| \\_\\  |______|  |__| |__|      || \n"; Sleep(300);
    cout << "                       ||                                                                                  ||\n"; Sleep(300);
    cout << "                       ||      *        *          *                     *           *              *      ||\n"; Sleep(300);
    cout << "                       ||                                *         *                                       ||\n"; Sleep(300);
    cout << "                       ||          *          *                 *       *      ===          *    *         || \n"; Sleep(300);
    cout << "                       ||                             _______    ________    __   __                       ||\n"; Sleep(300);
    cout << "                       ||                  *      *  |   ____|  |   __   |  |  | |  |                      ||\n"; Sleep(300);
    cout << "                       ||          *                 |  |____   |  |  |  |  |  |/   |      *               ||\n"; Sleep(300);
    cout << "                       ||                            |  ____ |  |  |__|  |  |   /|  |              *       ||\n"; Sleep(300);
    cout << "                       ||                  *         |_______|  |________|  |__| |__|        *             ||\n"; Sleep(300);
    cout << "                       ||      *                                                        *                  || \n"; Sleep(300);
    cout << "                       ||                   *                                            *        *        || \n"; Sleep(300);
    cout << "                       ||==================================================================================|| \n"; Sleep(300);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    cout << "                    ||============================================================================================|| \n"; Sleep(100);
    cout << "                    ||                                 ������� ����:                                              || \n"; Sleep(100);
    cout << "                    ||    ����� ������� ���� ������ ����� ����� ����������� ���� ������� �� ����� �������� �����. || \n"; Sleep(100);
    cout << "                    || ������ ������� �������� ��� ���������������� ��������� �� �����, ������������� ����        || \n"; Sleep(100);
    cout << "                    || �������������, ���� �����������. ���������� ��������� ��� ������� ������� ������������     || \n"; Sleep(100);
    cout << "                    || ����� �������. ������� �� ����� ������������� (�� ���� ������ ���� ������� ����� ��������  || \n"; Sleep(100);
    cout << "                    || ����� �������� ������� � �����). ���� � ���������� ����������� �������� ��������� ���      || \n"; Sleep(100);
    cout << "                    || ������� ������. ��� ����� ������������� � ����������� �� ������                            || \n"; Sleep(100);
    cout << "                    ||                                                                                            || \n"; Sleep(100);
    cout << "                    ||============================================================================================|| \n"; Sleep(100);
    cout << endl;
    cout << endl;
    cout << "\n\t                               ������� ����� ������ ��� �����������! � ���� ��������!!!";
    cin.get();
    cout << endl;
    cout << endl;
    std::cout << "                                                     ��� ��� �����?: ";
    std::string name;
    std::cin >> name;
    return name;
}

void ViewPort::ShowMiss(std::string name)
{
    std::cout << name << " miss\n";
}

void ViewPort::ShowHit(std::string name)
{
    std::cout << name << " hit\n";
}

void ViewPort::ShowKill(std::string name)
{
    std::cout << name << " kill\n";
}

void ViewPort::RoundStart(std::string name)
{
 
    std::cout << "*********************************************\n";
    std::cout << "Round for " << name << "\n";
    std::cout << "*********************************************\n";
}

void ViewPort::GameWin(std::string name)
{
    std::cout << "*********************************************\n";
    std::cout << name << " WIN" << "\n";
    std::cout << "*********************************************\n";
}


