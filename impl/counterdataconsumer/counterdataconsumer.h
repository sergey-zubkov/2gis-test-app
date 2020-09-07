//
//  counterdataconsumer.h
//  2gis_test_app
//
//  Created by Sergey Zubkov on 07.09.2020.
//

#ifndef counterdataconsumer_h
#define counterdataconsumer_h

#include <vector>
#include <string>
//
#include "idataconsumer.h"

namespace test_app {

class CounterDataConsumer : public IDataConsumer {
public:
    CounterDataConsumer(const std::string &searchword)
    : _searchword(searchword) {
    }
    
    void nextDataChunk(const std::vector<char> &dataChunk);
    std::string result();
    
    ~CounterDataConsumer() {
    }
    
private:
    int findWord(const std::vector<char> &buffer, const std::string &word);
    
private:
    int _counter;
    std::vector<char> _buffer;
    std::string _searchword;
};

}

#endif /* counterdataconsumer_h */
