#pragma once

#include <map>
#include <string>

class Pipe
{
	static inline int id{};
public:
	std::string name;
	float lenght;
	int diametr;
	bool condition;

	Pipe(std::string p_name, double p_lenght, int p_diam, bool p_repair) {
		++id;
		name = p_name;
		lenght = p_lenght;
		diametr = p_diam;
		condition = p_repair;

	}

	void Print();
	void Push(std::map <int, Pipe>& myMap);
};

