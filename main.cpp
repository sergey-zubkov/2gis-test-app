//
//  main.cpp
//  2gis_test_app
//
//  Created by Sergey Zubkov on 07.09.2020.
//

#include <iostream>
#include <map>
//
#include "filedataprovider.h"
#include "checksumdataconsumer.h"
#include "counterdataconsumer.h"

void showUsage() {
    std::cout << "usage: test" << std::endl
              << "\t[-f file_name]" << std::endl
              << "\t[-m mode < words | checksum >] mode \"words\" requires -v key" << std::endl
              << "\t[-v search_word]" << std::endl
              << "\t[-h] help" << std::endl;
}

std::map<std::string, std::string> parse_param(int argc, const char * argv[]) {
    std::map<std::string, std::string> params;
    
    for (int i = 0; i < argc; ++i) {
        std::string token(argv[i]);
        if (token == "-f") {
            // next token should be file_name
            if (i + 1 <= argc) {
                params[token] = std::string(argv[i + 1]);
            } else {
                params[token] = std::string("");
            }
        } else
        if (token == "-m") {
            // next token should be mode
            if (i + 1 <= argc) {
                params[token] = std::string(argv[i + 1]);
            } else {
                params[token] = std::string("");
            }
        } else
        if (token == "-v") {
            // next token should be search_word
            if (i + 1 <= argc) {
                params[token] = std::string(argv[i + 1]);
            } else {
                params[token] = std::string("");
            }
        } else
        if (token == "-h") {
            params[token] = std::string("");
        }
    }
    
    return params;
}

using namespace test_app;

int main(int argc, const char * argv[]) {
    auto appOptions = parse_param(argc, argv);
    
    if (appOptions.size() == 0) {
        showUsage();
        return 0;
    }
    
    if (appOptions.find("-h") != appOptions.end()) {
        showUsage();
        return 0;
    }
    
    std::shared_ptr<DataProvider> dataProvider;
    
    if (appOptions.find("-f") != appOptions.end()) {
        auto filename = appOptions["-f"];
        if (filename.length() > 0) {
            dataProvider = std::make_shared<FileDataProvider>(filename);
        } else {
            showUsage();
            return 0;
        }
    } else {
        showUsage();
        return 0;
    }
    
    if (appOptions.find("-m") != appOptions.end()) {
        if (appOptions["-m"] == "words") {
            if (appOptions.find("-v") != appOptions.end()) {
                auto searchword = appOptions["-v"];
                if (searchword.length() > 0) {
                    auto consumer = std::make_shared<CounterDataConsumer>(searchword);
                    dataProvider->addDataConsumer(consumer);
                } else {
                    showUsage();
                    return 0;
                }
            } else {
                showUsage();
                return 0;
            }
        } else
        if (appOptions["-m"] == "checksum") {
            auto consumer = std::make_shared<CheckSumDataConsumer>(0);
            dataProvider->addDataConsumer(consumer);
        }
    } else {
        showUsage();
        return 0;
    }
    
	try {
		dataProvider->provide();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return -1;
	}
    
    // print results
    for (auto consumer : dataProvider->getDataConsumer()) {
        std::cout << consumer->result() << std::endl;
    }

    return 0;
}
