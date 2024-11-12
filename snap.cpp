#include "snap.hpp"

Snap::Snap()
{
}

Snap::~Snap()
{
    for (auto m : missions)
        delete m;
    for (auto d : drivers)
        delete d;
}

void Snap::handle_command()
{
    string command, line;
    while (getline(cin, line))
    {
        vector<string> command_words = split_words(line, SPACE);
        command = command_words[0];
        if (command == "add_time_mission")
            add_t_mission(command_words);
        else if (command == "add_distance_mission")
            add_d_mission(command_words);
        else if (command == "add_count_mission")
            add_c_mission(command_words);
        else if (command == "assign_mission")
            assign_mission(command_words);
        else if (command == "record_ride")
            record_ride(command_words);
        else if (command == "show_missions_status")
            show_missions_status(command_words);
        else
            cout << ARGUMENT_ER << endl;
    }
}

void Snap::add_t_mission(vector<string> info)
{
    if (!valid_request(info))
        return;
    Mission *adding_mission;
    try
    {
        TimeMission *new_mission = new TimeMission(stoi(info[1]), stoll(info[2]),
                                                   stoll(info[3]), stoi(info[5]), stoi(info[4]));

        adding_mission = new_mission;
    }
    catch (runtime_error &er)
    {
        cout << er.what() << endl;
        return;
    }
    missions.push_back(adding_mission);
    cout << "OK" << endl;
}

void Snap::add_d_mission(vector<string> info)
{
    if (!valid_request(info))
        return;
    Mission *adding_mission;
    try
    {
        DistanceMission *new_mission = new DistanceMission(stoi(info[1]), stoll(info[2]),
                                                           stoll(info[3]), stoi(info[5]), stoi(info[4]));
        adding_mission = new_mission;
    }
    catch (runtime_error &er)
    {
        cout << er.what() << endl;
        return;
    }
    missions.push_back(adding_mission);
    cout << "OK" << endl;
}

void Snap::add_c_mission(vector<string> info)
{
    if (!valid_request(info))
        return;
    Mission *adding_mission;
    try
    {
        CountMission *new_mission = new CountMission(stoi(info[1]), stoll(info[2]),
                                                     stoll(info[3]), stoi(info[5]), stoi(info[4]));
        adding_mission = new_mission;
    }
    catch (runtime_error &er)
    {
        cout << er.what() << endl;
        return;
    }
    missions.push_back(adding_mission);
    cout << "OK" << endl;
}

void Snap::show_missions_status(vector<string> info)
{
    if (info.size() != 2)
    {
        cout << ARGUMENT_ER << endl;
        return;
    }
    int driver_index = find_driver(stoi(info[1]));
    if (driver_index == NOT_FOUND)
    {
        cout << FIND_MISSON_ER << endl;
        return;
    }
    try
    {
        drivers[driver_index]->print_missions_status();
    }
    catch (runtime_error &er)
    {
        cout << DRIVER_MISSION_ER << endl;
    }
}

void Snap::record_ride(vector<string> info)
{
    if (info.size() != 5)
    {
        cout << ARGUMENT_ER << endl;
        return;
    }
    int driver_index = find_driver(stoi(info[3]));
    Travel *new_travel;
    try
    {
        new_travel = new Travel(stoll(info[1]), stoll(info[2]), stoi(info[4]));
    }
    catch (runtime_error &er)
    {
        cout << ARGUMENT_ER << endl;
        return;
    }
    drivers[driver_index]->add_travel(new_travel);
}

void Snap::assign_mission(vector<string> info)
{
    int mission_index = find_mission(stoi(info[1]));
    int driver_index = find_driver(stoi(info[2]));
    if (mission_index == NOT_FOUND)
    {
        cout << FIND_MISSON_ER << endl;
        return;
    }
    if (driver_index == NOT_FOUND)
    {
        driver_index = drivers.size();
        add_driver(stoi(info[2]));
    }
    try
    {
        drivers[driver_index]->add_mission(missions[mission_index]);
        cout << "OK" << endl;
    }
    catch (runtime_error &er)
    {
        cout << DUPLICATE_DRIVER_MISSION << endl;
    }
}

void Snap::add_driver(int id)
{
    Driver *new_driver = new Driver(id);
    drivers.push_back(new_driver);
}

int Snap::find_mission(int id)
{
    for (int i = 0; i < missions.size(); i++)
    {
        if (missions[i]->get_id() == id)
            return i;
    }
    return NOT_FOUND;
}

int Snap::find_driver(int id)
{
    for (int i = 0; i < drivers.size(); i++)
    {
        if (drivers[i]->get_id() == id)
            return i;
    }
    return NOT_FOUND;
}

bool Snap::valid_request(vector<string> info)
{
    int id = stoi(info[1]);
    if (missions.size() != 0)
    {
        for (auto m : missions)
        {
            if (m->get_id() == id)
            {
                cout << DUPLICATE_ID_ER << endl;
                return false;
            }
        }
    }
    if (info.size() != 6)
    {
        cout << ARGUMENT_ER << endl;
        return false;
    }
    for (auto i : info)
    {
        if (i == "" || i == "\0")
        {
            cout << ARGUMENT_ER << endl;
            return false;
        }
    }
    return true;
}

vector<string> Snap::split_words(string line, char del)
{
    vector<string> words_in_line;
    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == del)
        {
            words_in_line.push_back(line.substr(0, i));
            line = line.substr(i + 1, line.size());
            i = 0;
        }
        if (i == line.size() - 1)
        {
            words_in_line.push_back(line.substr(0));
            line = line.substr(i + 1, line.size());
            i = 0;
        }
    }
    return words_in_line;
}