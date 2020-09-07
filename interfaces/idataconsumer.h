//
//  idataconsumer.h
//  2gis_test_app
//
//  Created by Sergey Zubkov on 07.09.2020.
//

#ifndef idataconsumer_h
#define idataconsumer_h

#include <vector>

namespace test_app {
    
class IDataConsumer {
public:
    virtual void nextDataChunk(const std::vector<char> &dataChunk) = 0;
    virtual std::string result() = 0;
    virtual ~IDataConsumer() {};
};

}

#endif /* idataconsumer_h */
