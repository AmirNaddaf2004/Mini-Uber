#include "driver.hpp"

Driver::Driver(int i)
{
    id = i;
}

Driver::~Driver()
{
    for (auto m : missions)
        delete m;
    for (auto t : travels)
        delete t;
}

void Driver::add_mission(Mission *new_mission)
{
    check_duplicate_mission(new_mission);
    Mission *clone_mission = new_mission->make_clone();
    missions.push_back(clone_mission);
    for (int i = 0; i < missions.size(); i++)
    {
        if (missions[missions.size() - 1]->get_s_time() < missions[i]->get_s_time())
        {
            Mission *temp;
            temp = missions[i];
            missions[i] = missions[missions.size() - 1];
            missions[missions.size() - 1] = temp;
        }
    }
}

void Driver::check_duplicate_mission(Mission *new_mission)
{
    for (auto m : missions)
        if (m->get_id() == new_mission->get_id())
            throw runtime_error("already has it");
}

void Driver::add_travel(Travel *new_travel)
{
    if (missions.size() != 0)
        travels.push_back(new_travel);
    check_done_missions(new_travel);
}

void Driver::check_done_missions(Travel *new_travel)
{
    cout << "completed missions for driver " << id << ":";
    bool printed_one = false;
    for (auto m : missions)
    {
        if (!m->was_done_before() && m->is_done(new_travel))
        {
            m->print_mission(false);
            printed_one = true;
        }
    }
    if (!printed_one)
        cout << endl;
}

void Driver::print_missions_status()
{
    if (missions.size() == 0)
        throw runtime_error("no mission");
    cout << "missions status for driver " << id << ":";
    for (auto m : missions)
        m->print_mission(true);
}

int Driver::get_id()
{
    return id;
}