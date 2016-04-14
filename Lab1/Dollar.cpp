#include "Dollar.h"

Dollar::Dollar() : Currency("Dollars", "Cents", 0, 0)
{
}

Dollar::Dollar(int w, int f) : Currency("Dollars", "Cents", w, f)
{
}

Dollar::~Dollar()
{
}
