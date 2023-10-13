//
// Created by Giuse on 17/10/2022.
//

#include "Data.h"

Data::Data(const std::string &d) {
    setData(d);
}

std::ostream& operator<<(std::ostream& os, const Data& dt){
    return os << dt._data;
}


std::string Data::getData() const {
    return _data;
}

void Data::setData(const std::string & data) {
    if (data.size()==10){
        if (data[4]=='-' && data[7]=='-'){
            if (stoi(data.substr(0,3))<2023 && stoi(data.substr(5,2))<13 && stoi(data.substr(5,2))>0 &&
                stoi(data.substr(8,2))<32 && stoi(data.substr(8,2))>0)
                _data=data;
            else
                throw DataErrata();
        }
        else
            throw DataErrata();
    }
    else
        throw DataErrata();
}

int Data::getNumber(const Data & data_inizio) const {
    int inizio;
    //anno
    inizio = stoi(data_inizio.getData().substr(0,4))*365;
    //giorno
    inizio+= stoi(data_inizio.getData().substr(8,2));
    //mese
    switch (stoi(data_inizio.getData().substr(5,2))) {
        case 2: inizio += 31;
            break;
        case 3: inizio += 59;
            break;
        case 4: inizio += 90;
            break;
        case 5: inizio += 120;
            break;
        case 6: inizio += 151;
            break;
        case 7: inizio += 181;
            break;
        case 8: inizio += 212;
            break;
        case 9: inizio += 243;
            break;
        case 10: inizio += 273;
            break;
        case 11: inizio += 304;
            break;
        case 12: inizio += 334;
            break;
    }


    return inizio;
}
