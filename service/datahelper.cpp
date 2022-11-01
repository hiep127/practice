#include "datahelper.h"
#include <cstring>
#include <iostream>
#include <fstream>

//DataHelper *DataHelper::getInstance()
//{
//    if (instance == nullptr) {
//        instance = new DataHelper();
//    }
//    return instance;
//}

std::vector<EmployeeData> DataHelper::getDataFromFile(const std::string& fileName)
{
    std::vector<EmployeeData> res;
    std::ifstream inData;
    std::string name;
    int grade;
    int count = 0;
    EmployeeData data;
    inData.open(fileName);
    if (!inData) {
        std::cout << "error while loading file" << std::endl;
        return res;
    }
    while (!inData.eof()) {
        if (count < MAX_NAME_LENGTH) {
            inData >> name;
            data.eName += name;
            if (count < 2)
                data.eName += " ";
            count++;
        }
        else if (count >= MAX_NAME_LENGTH && count < (MAX_GRADE_LENGTH + MAX_NAME_LENGTH)) {
            inData >> grade;
            data.grade.push_back(grade);
            count++;
        }
        else {
            count = 0;
            res.push_back(data);
            data.grade.clear();
            data.eName.clear();
        }
    }
    inData.close();
    return res;
}

void DataHelper::printData(std::vector<EmployeeData> data) const
{
    for (const auto &e : data) {
        std::cout << e.eName ;
        std::cout << std::endl;
        for (int i = 0; i < MAX_GRADE_LENGTH; i++) {
            std::cout << e.grade[i] << " " << std::endl;
        }
        std::cout << std::endl;
    }
}

void DataHelper::editData(std::vector<EmployeeData> data, std::string eName, std::vector<int> grade, const std::string& fileName)
{
    std::fstream oData;
    oData.open(fileName);
    for (auto& e : data) {
        std::cout << e.eName << eName << std::endl;
        if (e.eName.compare(eName) == 0) {
            std::cout << "edit here";
            e.grade = grade;
        }
        oData << e.eName << " ";
        for (auto g : e.grade) {
            oData << g << " ";
        }
        oData << std::endl;
    }
}

DataHelper::DataHelper()
{

}

DataHelper::~DataHelper()
{

}
