#ifndef CHANGE_H
#define CHANGE_H

#include "Read.h"

class Change {
public:
    void promote(Employee& emp); // 實習升正職
    void resign(Employee& emp);  // 辭職
};

#endif
