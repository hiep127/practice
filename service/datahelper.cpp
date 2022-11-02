#include "datahelper.h"
#include <cstring>
#include <iostream>
#include <fstream>


std::vector<EmployeeGrade> DataHelper::getDataFromFile(const std::string& fileName)
{
    std::cout << "reading data" << std::endl;
    std::vector<EmployeeGrade> res;
    std::ifstream inData;
    std::string name;
    int grade;
    int count = 0;
    EmployeeGrade data;
    inData.open(fileName);
    int id = 0;
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
            data.id = id;
            id++;
            res.push_back(data);
            data.grade.clear();
            data.eName.clear();
        }
    }
    inData.close();
    std::cout << "end reading data" << std::endl;
    return res;
}

void DataHelper::printData(std::vector<EmployeeGrade> data) const
{
    for (const auto &e : data) {
        std::cout << e.eName ;
        std::cout << std::endl;
        std::cout << "ID: " << e.id << std::endl;
        for (int i = 0; i < MAX_GRADE_LENGTH; i++) {
            std::cout << e.grade[i] << " " << std::endl;
        }
        std::cout << std::endl;
    }
}

void DataHelper::editData(std::vector<EmployeeGrade> &data, std::vector<int> eData, const std::string& fileName)
{
    std::fstream oData;
    oData.open(fileName);
    for (auto& e : data) {
        if (eData[ID_INDEX] == e.id) {
            std::cout << "edit here";
            for (int i = 0; i < NUM_OF_SKILL; i++) {
                e.grade[i] = eData[i];
            }
        }
        for (auto g : data) {
            oData << g.eName << " ";
            for (auto i : g.grade) {
                oData << i << " ";
            }
            oData << std::endl;
        }
    }
}

std::vector<EmployeeData> DataHelper::convertToEmployeeList(std::vector<EmployeeGrade> data)
{
    std::vector<EmployeeData> res;
    EmployeeData temp;
    for (auto i : data) {
        temp.id = i.id;
        strncpy(temp.name, i.eName.c_str(), sizeof(i.eName));
        temp.average = calculateAverage(i.grade);
        res.push_back(temp);
    }
    return res;
}

float DataHelper::calculateAverage(std::vector<int> grade)
{
    float res = 0;
    for (const auto& i : grade) {
        res += i;
    }
    res = res / (grade.size());
    return res;
}

std::vector<EmployeeData> DataHelper::searchForText(std::string text, std::vector<EmployeeData> data)
{
    std::vector<EmployeeData> res;
    for (auto d : data) {
        std::string temp = d.name;
        if (temp.find(text) != std::string::npos) {
            res.push_back(d);
        }
    }
    return res;
}

EmployeeGrade DataHelper::queryForId(int id, std::vector<EmployeeGrade> data)
{
    for (auto i : data) {
        std::cout << i.id << "    " << id << std::endl;
        if (i.id == id) {
            return i;
        }
    }
}

DataHelper::DataHelper()
{

}

DataHelper::~DataHelper()
{

}
