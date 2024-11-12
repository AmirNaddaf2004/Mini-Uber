#include "time_mission.hpp"

TimeMission::TimeMission(int i, long long st, long long et, int r, int m) : Mission(i, st, et, r)
{
    if (m < 0)
        throw runtime_error("INVALID_ARGUMENTS");
    gone_minutes = 0;
    target_minutes = m;
}

TimeMission* TimeMission::make_clone()
{
    return new TimeMission(*this);
}

bool TimeMission::is_done(Travel* new_travel)
{
    update_state(new_travel);
    if (gone_minutes >= target_minutes)
    {
        e_time = new_travel->get_e_time();
        status = "completed";
        return true;
    }
    return false;
}

void TimeMission::update_state(Travel* new_travel)
{
    if (is_travel_in_mission_duration(new_travel))
        gone_minutes += new_travel->duration_in_minute();
}