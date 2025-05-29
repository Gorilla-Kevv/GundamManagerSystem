#pragma once

#include<iostream>
#include<string>

#ifndef GUNDAM_h
#define GUNDAM_h
using namespace std;
class GundamList {
protected:
	string model;
	string codeName;
	string pilot;
public:
	GundamList(const string& model,const string& codeName,const string& pilot) : model(model), codeName(codeName), pilot(pilot) {};
	void display() const;
	string getModel() const { return model; }
	string getName() const { return codeName; }
	string getPilot() const { return pilot; }
};

#endif