#include "leveldb/db.h"
#include "leveldb/env.h"
#include "leveldb/options.h"
#include <cstdio>
#include <leveldb/write_batch.h>
#include <iostream>
#include <ostream>
#include <string>
// #include "db/db_impl.h"

using namespace leveldb;

int	main(int argc, char **argv) {
    DB *mydb;
    Options option;
    option.create_if_missing = true;

    Status status;

    status = DB::Open(option , "test.ldb", &mydb);
    if (!status.ok()) {
        std::cout << "open file error" + status.ToString() << std::endl;
        return -1;
    }

    WriteOptions writeOption;
    ReadOptions readOption;

    writeOption.sync = 1;
    status = mydb->Put(writeOption, "key", "value");

    if (!status.ok()) {
        std::cout << "write key error" + status.ToString() << std::endl;
        return -1;
    }


    std::string value;
    status = mydb->Get(readOption, "key", &value);
    if (!status.ok()) {
        std::cout << "read key error" + status.ToString() << std::endl;
        return -1;
    }


    std::cout << "value is " + value << std::endl;
    return 0;
}
