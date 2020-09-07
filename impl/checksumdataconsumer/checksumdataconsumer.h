//
//  checksumdataconsumer.h
//  2gis_test_app
//
//  Created by Sergey Zubkov on 07.09.2020.
//

#ifndef checksumdataconsumer_h
#define checksumdataconsumer_h

#include <vector>
#include <string>
//
#include "idataconsumer.h"

namespace test_app {

class CheckSumDataConsumer : public IDataConsumer {
public:
    CheckSumDataConsumer(int32_t initialValue = 0)
    : _checkSum(initialValue) {}
    
    void nextDataChunk(const std::vector<char> &dataChunk);
    std::string result();
    
    ~CheckSumDataConsumer() {}
	
private:
    std::vector<char> _buffer;
    uint64_t _checkSum;
};

}

#endif /* checksumdataconsumer_h */
