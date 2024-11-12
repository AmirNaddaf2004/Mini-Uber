#include <iostream>
#include <string>
#include <memory>
#include "travel.hpp"

using namespace std;

#ifndef MISSION
#define MISSION

class Mission
{
protected:
    int id;
    long long s_time;
    long long e_time;
    int reward;
    string status;
public:
    Mission(int i, long long st, long long et, int r);
    virtual Mission* make_clone() = 0;
    virtual bool was_done_before();
    virtual bool is_travel_in_mission_duration(Travel* new_travel);
    virtual void print_mission(bool show_status);

    virtual bool is_done(Travel* new_travel) = 0;
    virtual void update_state(Travel* new_travel) = 0;
    virtual long long get_s_time();
    virtual int get_id();
};

#endif