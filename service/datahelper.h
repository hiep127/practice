#ifndef DATAHELPER_H
#define DATAHELPER_H

#include <vector>
#include <string>
#include <DataDefine.h>



class DataHelper
{


public:
    //static DataHelper* getInstance();
    DataHelper();
    ~DataHelper();
    std::vector<EmployeeData> getDataFromFile(const std::string& fileName);
    void printData(std::vector<EmployeeData> data) const;
    void editData(std::vector<EmployeeData> data, std::string eName, std::vector<int> grade, const std::string& fileName);
private:
    //static DataHelper* instance;
//    DataHelper();
//    ~DataHelper();
};

#endif // DATAHELPER_H
