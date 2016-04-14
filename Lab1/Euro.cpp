#include "Euro.h"

Euro::Euro() : Currency("Euro", "Cents", 0, 0)
{
}

Euro::Euro(int w, int f) : Currency("Euro", "Cents", w, f)
{
}

Euro::~Euro()
{
}
