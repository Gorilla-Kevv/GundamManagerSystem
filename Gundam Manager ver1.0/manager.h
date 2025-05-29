#pragma once
#include <vector>
#include"GUNDAM.h"

#ifndef hostel_h 
#define hostel_h
using namespace std;

class GundamManager {
private:
	vector<GundamList> gundams;
public:
	void addGundam(const GundamList& g);
	const std::vector<GundamList>& getList() const;
};

#endif 