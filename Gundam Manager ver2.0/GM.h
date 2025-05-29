#pragma once
#pragma once

#ifndef GM_h
#define GM_h

#include<iostream>
#include<string>
#include"GUNDAM.h"
class GM : public InfoAddition {
	string GroupID; 
	string produceSerial;
public:
	GM(const string& model,
		const string& codeName,
		const string& pilot,
		GundamType type,
		double h,
		double w,
		const string& buildYear,
		
		const string& GroupID,
		const string& serial)
		: InfoAddition(model, codeName, pilot,type ,h, w, buildYear),
		GroupID(GroupID),
		produceSerial(serial)
		 {};

	virtual void save(std::ostream& os) const override;
	virtual void load(std::istream& is) override;

	

	virtual bool isGM() const override { return true; }

	string getTypeName() const override;

	string getGroupID() const { return GroupID; }
	string getProduceSerial() const { return produceSerial; }



};



#endif