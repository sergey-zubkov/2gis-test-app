//
//  dataprovider.cpp
//  2gis_test_app
//
//  Created by Sergey Zubkov on 07.09.2020.
//

#include "dataprovider.h"

namespace test_app {

void DataProvider::addDataConsumer(const std::shared_ptr<IDataConsumer> &dataConsumerPtr) {
    _dataConsumer.push_back(dataConsumerPtr);
}

const std::vector<std::shared_ptr<IDataConsumer>> & DataProvider::getDataConsumer() {
    return _dataConsumer;
}

}
