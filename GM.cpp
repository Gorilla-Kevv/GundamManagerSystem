#include"gm.h"
#include<sstream>

void GM::save(std::ostream& os) const {
    std::ostringstream tempStream;
    InfoAddition::save(tempStream); 
    std::string baseData = tempStream.str();

    // 移除基类保存数据中的换行符
    if (!baseData.empty() && baseData.back() == '\n') {
        baseData.pop_back();
    }

    os << baseData << "," << GroupID << "," << produceSerial << std::endl;
}

void GM::load(std::istream& is) {
	InfoAddition::load(is);
	getline(is, GroupID, ',');
	getline(is, produceSerial,',');
}
string GM::getTypeName() const {
	return "GM系列 - " + InfoAddition::getTypeName();
}