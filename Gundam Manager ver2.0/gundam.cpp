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
    case GundamType::陆地型: return "陆地型";
    case GundamType::空战型: return "空战型";
    case GundamType::宇宙型: return "宇宙型";
    default: return "泛用型";
    }
}
