#include"gundam.h"
#include<sstream>


void InfoAddition:: save(std::ostream& os) const {
    os << model << ","
        << codeName << ","
        << pilot << ","
        << static_cast<int>(type) << ","
        << height << ","
        << weight <<","
		<< buildYear << std::endl;
}

void InfoAddition::load(std::istream& is) {
    string token;
    getline(is, model, ',');
    getline(is, codeName, ',');
    getline(is, pilot, ',');

    getline(is, token, ',');
    type = static_cast<GundamType>(stoi(token));

    getline(is, token, ',');
    height = stod(token);

    getline(is, token);
    weight = stod(token);

	getline(is, buildYear, ',');
}
string InfoAddition::getTypeName() const {
    switch (type) {
    case GundamType::½����: return "½����";
    case GundamType::��ս��: return "��ս��";
    case GundamType::������: return "������";
    default: return "������";
    }
}
