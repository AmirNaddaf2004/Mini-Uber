all:  mission c_mission d_mission t_mission travel driver snap main result

mission: mission.hpp
	g++ -c --std=c++11 mission.cpp -o mission.o

c_mission: mission.hpp mission.o count_mission.hpp
	g++ -c --std=c++11 count_mission.cpp -o count_mission.o

d_mission: mission.hpp mission.o distance_mission.hpp
	g++ -c --std=c++11 distance_mission.cpp -o distance_mission.o

t_mission: mission.hpp mission.o time_mission.hpp
	g++ -c --std=c++11 time_mission.cpp -o time_mission.o

travel: travel.hpp
	g++ -c --std=c++11 travel.cpp -o travel.o

driver: mission.hpp mission.o count_mission.hpp count_mission.o time_mission.hpp time_mission.o distance_mission.hpp distance_mission.o travel.hpp travel.o
	g++ -c --std=c++11 driver.cpp -o driver.o

snap: mission.hpp mission.o count_mission.hpp count_mission.o time_mission.hpp time_mission.o distance_mission.hpp distance_mission.o travel.hpp travel.o driver.hpp driver.o
	g++ -c --std=c++11 snap.cpp -o snap.o

main: mission.hpp mission.o count_mission.hpp count_mission.o time_mission.hpp time_mission.o distance_mission.hpp distance_mission.o travel.hpp travel.o driver.hpp driver.o snap.hpp snap.o
	g++ -c --std=c++11 main.cpp -o main.o

result: mission.hpp mission.o count_mission.hpp count_mission.o time_mission.hpp time_mission.o distance_mission.hpp distance_mission.o travel.hpp travel.o driver.hpp driver.o snap.hpp snap.o main.o
	g++ --std=c++11 mission.o count_mission.o distance_mission.o time_mission.o travel.o driver.o snap.o main.o -o main