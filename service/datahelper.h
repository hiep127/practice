#ifndef DATAHELPER_H
#define DATAHELPER_H

#include <vector>
#include <string>
#include <ServiceDefine.h>
#include </home/avn//practice/Utils/IPCDefine.h>




class DataHelper
{


public:
    DataHelper();
    ~DataHelper();
    std::vector<EmployeeGrade> getDataFromFile(const std::string& fileName);
    void printData(std::vector<EmployeeGrade> data) const;
    void editData(std::vector<EmployeeGrade> data, std::string eName, std::vector<int> grade, const std::string& fileName);
    std::vector<EmployeeData> convertToEmployeeList(std::vector<EmployeeGrade> data);
    float calculateAverage(std::vector<int> grade);
private:
};

#endif // DATAHELPER_H
