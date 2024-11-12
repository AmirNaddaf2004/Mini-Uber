#include "count_mission.hpp"

CountMission::CountMission(int i, long long st, long long et, int r, int n) : Mission(i, st, et, r)
{
    if (n < 0)
        throw runtime_error("INVALID_ARGUMENTS");
    gone_travel_number = 0;
    target_number = n;
}

CountMission* CountMission::make_clone()
{
    return new CountMission(*this);
}

bool CountMission::is_done(Travel* new_travel)
{
    update_state(new_travel);
    if (gone_travel_number >= target_number)
    {
        e_time = new_travel->get_e_time();
        status = "completed";
        return true;
    }
    return false;
}

void CountMission::update_state(Travel* new_travel)
{
    if (is_travel_in_mission_duration(new_travel))
        gone_travel_number++;
}