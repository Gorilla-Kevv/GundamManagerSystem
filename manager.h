#pragma once
#include "gundam.h"
#include "gm.h"

#include <memory>
#include <vector>
#include <fstream>


#ifndef hostel_h 
#define hostel_h
using namespace std;

class GundamManager {

	vector<unique_ptr<InfoAddition>> units;  // 使用智能指针管理GundamList对象
	const std::string DATA_FILE = "mobile_suits_data.txt";

public:
	void addUnit(unique_ptr<InfoAddition> unit);
	void saveToFile();
	void loadFromFile();
	void showAll() const;
	const vector<std::unique_ptr<InfoAddition>>& getUnits() const { return units; }
private:
	void createFromStream(std::istream& is, const string& type);

};

#endif 