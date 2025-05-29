#pragma once

#ifndef GUNDAM_h
#define GUNDAM_h

#include<iostream>
#include<string>
using namespace std;

class GundamList {
protected:
	string model;
	string codeName;
	string pilot;
public:

	GundamList(const string& model,const string& codeName,const string& pilot) : model(model), codeName(codeName), pilot(pilot) {};

	string getModel() const { return model; }
	string getName() const { return codeName; }
	string getPilot() const { return pilot; }

};

enum class GundamType { ½����, ��ս��, ������, ������ };


class InfoAddition : public GundamList {
protected:
	GundamType type;
	double height;
	double weight;
	string buildYear;
public:
	InfoAddition(const string& model,
		const string& codeName, 
		const string& pilot,
		GundamType type,
		double h, double w, 
		const string& buildYear 
		)
		: GundamList(model, codeName, pilot),
		height(h), weight(w), 
		buildYear(buildYear),
		type(type)
	{};

	virtual string getTypeName() const;
	double getHeight() const {
		return height;
	}
	double getWeight() const {
		return weight;
	}
	string getBuildYear() const {
		return buildYear;
	}
	//��̬�洢
	virtual void save(std::ostream& os) const;
	virtual void load(std::istream& is);

	virtual bool isGM() const { return false; }
};


#endif