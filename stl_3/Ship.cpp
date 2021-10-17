#include "Ship.h"

int Ship::Size()
{
    return size;
}

ShipDirection Ship::Direction()
{
    return direction;
}

int& Ship::Row()
{
    return coord.row;
}

int& Ship::Col()
{
    return coord.col;
}

bool Ship::isLive()
{
    return goodCells != 0;
}

int& Ship::GoodCells()
{
    return goodCells;
}
