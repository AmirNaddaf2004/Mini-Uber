#include <memory>
#include "mission.hpp"

#ifndef T_MISSION
#define T_MISSION

class TimeMission : public Mission
{   
public:
    TimeMission(int i, long long st, long long et, int r, int m);
    TimeMission* make_clone();
    bool is_done(Travel* new_travel);
    void update_state(Travel* new_travel);
private:
    int gone_minutes;
    int target_minutes;
};

#endif