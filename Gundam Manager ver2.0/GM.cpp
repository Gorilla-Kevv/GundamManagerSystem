#include"gm.h"
#include<sstream>

void GM::save(std::ostream& os) const {
    InfoAddition::save(os);
	os << "," << GroupID << ","
		<< produceSerial << std::endl;
}
void GM::load(std::istream& is) {
	InfoAddition::load(is);
	string token;
	getline(is, GroupID, ',');
	getline(is, produceSerial);
}
string GM::getTypeName() const {
	return "GMÏµÁÐ - " + InfoAddition::getTypeName();
}