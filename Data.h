//
// Created by Giuse on 17/10/2022.
//

#ifndef MAIN_CPP_DATA_H
#define MAIN_CPP_DATA_H

#include <string>
#include "Eccezioni.h"
class Data {
public:
    Data(const std::string& d = "");

    void setData(const std::string&);
    std::string getData() const;

    friend std::ostream& operator<<(std::ostream& os, const Data& dt);

    bool operator< (const Data& data) const {
        if (_data < data.getData()){
            return true;
        } else {
            return false;
        }
    }

    [[nodiscard]] int getNumber(const Data&) const;

    int operator-(const Data& data_inizio){
        int fine,inizio;

        fine = getNumber(_data);

        inizio = getNumber(data_inizio);

        return fine-inizio;
    }

private:
    std::string _data;
};


#endif //MAIN_CPP_DATA_H
