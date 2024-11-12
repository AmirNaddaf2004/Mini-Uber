#include <iostream>

using namespace std;

#ifndef TRAVEL
#define TRAVEL

class Travel
{
public:
    Travel(long long st, long long et, long long d);
    int duration_in_minute();
    long long get_distance();
    long long get_s_time();
    long long get_e_time();
    
private:
    long long s_time;
    long long e_time;
    long long distance;
};

#endif