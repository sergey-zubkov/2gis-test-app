//
//  dataprovider.h
//  2gis_test_app
//
//  Created by Sergey Zubkov on 07.09.2020.
//

#ifndef dataprovider_h
#define dataprovider_h

#include <memory>
#include <vector>
//
#include "idataprovider.h"

namespace test_app {

class IDataConsumer;

class DataProvider : public IDataProvider {
public:
    void addDataConsumer(const std::shared_ptr<IDataConsumer> &dataConsumerPtr);
    const std::vector<std::shared_ptr<IDataConsumer>> & getDataConsumer();
	
private:
    std::vector<std::shared_ptr<IDataConsumer>> _dataConsumer;
};

}

#endif /* dataprovider_h */
