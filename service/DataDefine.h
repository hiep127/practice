#ifndef DATADEFINE_H
#define DATADEFINE_H

#endif // DATADEFINE_H
#include <string>
#include <vector>

#define MAX_NAME_LENGTH 3
#define MAX_GRADE_LENGTH 5

struct EmployeeData {
    std::string eName;
    std::vector<int> grade;
};
