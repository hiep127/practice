#ifndef DATAHELPER_H
#define DATAHELPER_H

#include <vector>
#include <string>
#include <ServiceDefine.h>
#include <../Utils/CommonDefine.h>




class DataHelper
{


public:
    DataHelper();
    ~DataHelper();
    std::vector<EmployeeGrade> getDataFromFile(const std::string& fileName);
    void printData(std::vector<EmployeeGrade> data) const;
    void editData(std::vector<EmployeeGrade> &data, std::vector<int> eData, const std::string& fileName);
    std::vector<EmployeeData> convertToEmployeeList(std::vector<EmployeeGrade> data);
    float calculateAverage(std::vector<int> grade);
    EmployeeGrade queryForId(int id, std::vector<EmployeeGrade> data);
    std::vector<EmployeeData> searchForText(std::string text, std::vector<EmployeeData> data);
private:
};

#endif // DATAHELPER_H
