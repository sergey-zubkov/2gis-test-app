//
//  checksumdataconsumer.cpp
//  2gis_test_app
//
//  Created by Sergey Zubkov on 07.09.2020.
//

#include "checksumdataconsumer.h"
//
#include <sstream>
#include <iomanip>

namespace test_app {

void CheckSumDataConsumer::nextDataChunk(const std::vector<char> &dataChunk) {
    _buffer.insert(_buffer.end(), dataChunk.begin(), dataChunk.end());
    
    int i = 0;
    while (_buffer.size() - i >= 4) {
        uint32_t value = (_buffer[i] << 24) | (_buffer[i + 1] << 16) | (_buffer[i + 2] << 8) | (_buffer[i + 3]);
        _checkSum = (uint32_t)(_checkSum + value);
        i += 4;
    }
    
    _buffer.erase(_buffer.begin(), _buffer.begin() + i);
}

std::string CheckSumDataConsumer::result() {
    uint32_t value =
        (_buffer.size() > 0 ? _buffer[0] << 24 : 0) |
        (_buffer.size() > 1 ? _buffer[1] << 16 : 0) |
        (_buffer.size() > 2 ? _buffer[2] <<  8 : 0) |
        (_buffer.size() > 3 ? _buffer[3]       : 0);
    
    _checkSum = (uint32_t)(_checkSum + value);
    
    std::stringstream stream;
    stream << "0x"
           << std::setfill ('0') << std::setw(sizeof(uint32_t) * 2)
           << std::hex << _checkSum;
    
    return stream.str();
}

}
