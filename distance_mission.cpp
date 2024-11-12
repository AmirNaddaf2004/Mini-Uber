#include "distance_mission.hpp"

DistanceMission::DistanceMission(int i, long long st, long long et, int r, int d) : Mission(i, st, et, r)
{
    if (d < 0)
        throw runtime_error("INVALID_ARGUMENTS");
    gone_distance = 0;
    target_distance = d;
}

DistanceMission* DistanceMission::make_clone()
{
    return new DistanceMission(*this);
}

bool DistanceMission::is_done(Travel *new_travel)
{
    update_state(new_travel);
    if (gone_distance >= target_distance)
    {
        e_time = new_travel->get_e_time();
        status = "completed";
        return true;
    }
    return false;
}

void DistanceMission::update_state(Travel *new_travel)
{
    if (is_travel_in_mission_duration(new_travel))
        gone_distance += new_travel->get_distance();
}