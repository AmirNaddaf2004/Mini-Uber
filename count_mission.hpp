#include <memory>
#include "mission.hpp"

#ifndef N_MISSION
#define N_MISSION

class CountMission : public Mission
{   
public:
    CountMission(int i, long long st, long long et, int r, int n);
    CountMission* make_clone();
    bool is_done(Travel* new_travel);
    void update_state(Travel* new_travel);
private:
    int gone_travel_number;
    int target_number;
};

#endif