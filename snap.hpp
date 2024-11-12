#include <iostream>
#include <vector>
#include <string>
#include "driver.hpp"
#include "mission.hpp"
#include "count_mission.hpp"
#include "distance_mission.hpp"
#include "time_mission.hpp"
#include "travel.hpp"

using namespace std;

#ifndef SNAP
#define SNAP

const string DUPLICATE_ID_ER = "DUPLICATE_MISSION_ID";
const string ARGUMENT_ER = "INVALID_ARGUMENTS";
const string DUPLICATE_DRIVER_MISSION = "DUPLICATE_DRIVER_MISSION";
const string FIND_MISSON_ER = "MISSION_NOT_FOUND";
const string DRIVER_MISSION_ER = "DRIVER_MISSION_NOT_FOUND";

enum
{
    TIME_M_INDEX,
    DISTANCE_M_INDEX,
    COUNT_M_INDEX
};

const int NOT_FOUND = -1;
const char SPACE = ' ';

class Snap
{
public:
    Snap();
    ~Snap();
    void handle_command();
    void add_t_mission(vector<string> info);
    void add_c_mission(vector<string> info);
    void add_d_mission(vector<string> info);
    void assign_mission(vector<string> info);
    void record_ride(vector<string> info);
    void show_missions_status(vector<string> info);
private:
    bool valid_request(vector<string> info);
    vector<string> split_words(string line, char del);
    int find_driver(int id);
    int find_mission(int id);
    void add_driver(int id);

    vector<Mission *> missions;
    vector<Driver *> drivers;
};

#endif