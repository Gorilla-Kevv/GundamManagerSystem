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

	std::vector<unique_ptr<InfoAddition>> units;  // 使用智能指针管理GundamList对象
	const std::string DATA_FILE = "mobile_suits_data.txt";

public:
	void addUnit(unique_ptr<InfoAddition> unit);
	void saveToFile();
	void loadFromFile();
	void showAll() const;

private:
	void createFromStream(std::istream& is, const string& type);

};

#endif 