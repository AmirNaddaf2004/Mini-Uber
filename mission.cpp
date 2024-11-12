#include "mission.hpp"

Mission::Mission(int i, long long st, long long et, int r)
{
    if (st > et || r < 0)
        throw runtime_error("INVALID_ARGUMENTS");
    id = i;
    s_time = st;
    e_time = et;
    reward = r;
    status = "ongoing";
}

bool Mission::was_done_before()
{
    return status == "completed";
}

bool Mission::is_travel_in_mission_duration(Travel *new_travel)
{
    return s_time <= new_travel->get_s_time() && e_time >= new_travel->get_e_time();
}

void Mission::print_mission(bool show_status)
{
    if (show_status)
        cout << "\nmission " << id << ":" << endl;
    else
        cout << "\nmission: " << id << endl;
    cout << "start timestamp: " << s_time << endl;
    if (status == "completed")
        cout << "end timestamp: " << e_time << endl;
    else
        cout << "end timestamp: -1" << endl;
    cout << "reward: " << reward << endl;
    if (show_status)
        cout << "status: " << status << endl;
}

long long Mission::get_s_time()
{
    return s_time;
}

int Mission::get_id()
{
    return id;
}