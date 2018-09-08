//
//  Secp256k1.cpp
//  libNrEncryption
//
//  Created by Nyhl Rawlings on 06/09/2018.
//  Copyright © 2018 Nyhl Rawlings. All rights reserved.
//

#include "Secp256k1w.h"

namespace nrcore {
    
    Secp256k1::Secp256k1(const Memory& private_key) {
        this->private_key = private_key;
        this->cxt = secp256k1_context_create(SECP256K1_CONTEXT_SIGN);
    
        if (secp256k1_ec_pubkey_create(this->cxt, &this->pub_key, (const unsigned char*)this->private_key.getPtr())) {
            throw "Invalid Key";
        }
    }
    
    Secp256k1::~Secp256k1() {
        secp256k1_context_destroy(this->cxt);
    }
    
    Memory Secp256k1::sign(const Memory& hash) {
        Memory mem;
        
        return mem;
    }
    
}
