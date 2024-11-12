#include "travel.hpp"

Travel::Travel(long long st, long long et, long long d)
{
    if (st > et)
        throw runtime_error("bad duration");
    s_time = st;
    e_time = et;
    distance = d;
}

int Travel::duration_in_minute()
{
    return (e_time - s_time) / 60;
}

long long Travel::get_distance()
{
    return distance;
}

long long Travel::get_s_time()
{
    return s_time;
}

long long Travel::get_e_time()
{
    return e_time;
}