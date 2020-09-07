//
//  filedataprovider.cpp
//  2gis_test_app
//
//  Created by Sergey Zubkov on 07.09.2020.
//

#include "filedataprovider.h"
#include "idataconsumer.h"
#include <fstream>

namespace test_app {
	
void FileDataProvider::provide() { // throw(std::exception) {
    std::ifstream filestream(_filename);
    if (!filestream.is_open()) {
        throw std::runtime_error("Could not open file: " + _filename);
    }
    
    auto consumers = this->getDataConsumer();
    if (consumers.empty()) {
        return;
    }
    
    char buffer[1024];
    while(filestream) {
        filestream.read(buffer, 1024);

        size_t count = filestream.gcount();
        if (count) {
            std::vector<char> chunk(buffer, buffer + count);
            
            for (auto consumer : consumers) {
                consumer->nextDataChunk(chunk);
            }
        }
    }
}

}
