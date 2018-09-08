//
//  main.cpp
//  UnitTests
//
//  Created by Nyhl Rawlings on 06/09/2018.
//  Copyright © 2018 Nyhl Rawlings. All rights reserved.
//

#include <iostream>

#include <libnrcore/memory/Memory.h>

#include <libnrdebug/UnitTests.h>
#include <libnrencryption/Secp256k1w.h>
#include <libnrcore/utils/ByteUtils.h>

using namespace nrcore;

bool testSecp256k1() {
    Ref<char> bytes = ByteUtils::getRandomBytes(32);
    Memory private_key(bytes.getPtr(), 32);
    bytes.release();
    
    Secp256k1 secp(private_key);
    
    return true;
}

int main(int argc, const char * argv[]) {
    UnitTests tests;
    
    tests.addTest("testSecp256k1", testSecp256k1);
    tests.run();
    
    return 0;
}
