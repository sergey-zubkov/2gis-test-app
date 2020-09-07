//
//  idataprovider.h
//  2gis_test_app
//
//  Created by Sergey Zubkov on 07.09.2020.
//

#ifndef idataprovider_h
#define idataprovider_h

#include <exception>

namespace test_app {
	
class IDataProvider {
public:
    virtual void provide() = 0; //throw(std::exception) = 0;
    virtual ~IDataProvider() {};
};

}

#endif /* idataprovider_h */
