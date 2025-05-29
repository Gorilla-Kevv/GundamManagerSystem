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
    getline(is, model, ',');
    getline(is, codeName, ',');
    getline(is, pilot, ',');

    int typeInt;
    is >> typeInt;
    type = static_cast<GundamType>(typeInt);
    is.ignore(std::numeric_limits<std::streamsize>::max(), ','); 

    is >> height;
    is.ignore(std::numeric_limits<std::streamsize>::max(), ','); 

    is >> weight;
    is.ignore(std::numeric_limits<std::streamsize>::max(), ','); 


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
