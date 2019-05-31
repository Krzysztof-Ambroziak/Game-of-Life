#ifndef GAMEOFLIFE_ABSTRACTMODEL_H
#define GAMEOFLIFE_ABSTRACTMODEL_H

#include "model/cell.h"

class AbstractModel {
public:
    virtual int getRows() const = 0;
    
    virtual int getColumns() const = 0;
    
    virtual int getCellSize() const = 0;
    
    virtual Life getLife(int row, int column) const = 0;
    
    virtual ~AbstractModel() = default;
};

#endif // GAMEOFLIFE_ABSTRACTMODEL_H
