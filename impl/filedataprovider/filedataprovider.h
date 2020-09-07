//
//  filedataprovider.h
//  2gis_test_app
//
//  Created by Sergey Zubkov on 07.09.2020.
//

#ifndef filedataprovider_h
#define filedataprovider_h

#include <exception>
#include <string>
//
#include "dataprovider.h"

namespace test_app {

class FileDataProvider : public DataProvider {
public:
    FileDataProvider(const std::string &filename)
    : _filename(filename) {}
    
    virtual void provide(); //throw(std::exception);
    
    ~FileDataProvider() {}
    
private:
    std::string _filename;
};

}

#endif /* filedataprovider_h */
