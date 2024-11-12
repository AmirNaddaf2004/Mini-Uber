#include <memory>
#include <vector>
#include "mission.hpp"
#include "time_mission.hpp"
#include "distance_mission.hpp"
#include "count_mission.hpp"

using namespace std;

#ifndef DRIVER
#define DRIVER

class Driver
{
public:
    Driver(int i);
    ~Driver();
    void add_mission(Mission* new_mission);
    void add_travel(Travel* new_travel);
    void check_done_missions(Travel* new_travel);
    void print_missions_status();
    int get_id();
private:
    void check_duplicate_mission(Mission* new_mission);

    int id;
    vector<Mission *> missions;
    vector<Travel *> travels;
};

#endif