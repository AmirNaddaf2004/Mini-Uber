#include <memory>
#include "mission.hpp"

#ifndef D_MISSION
#define D_MISSION

class DistanceMission : public Mission
{   
public:
    DistanceMission(int i, long long st, long long et, int r, int d);
    DistanceMission* make_clone();
    bool is_done(Travel* new_travel);
    void update_state(Travel* new_travel);
private:
    int gone_distance;
    int target_distance;
};

#endif