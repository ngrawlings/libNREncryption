//
//  Secp256k1.hpp
//  libNrEncryption
//
//  Created by Nyhl Rawlings on 06/09/2018.
//  Copyright © 2018 Nyhl Rawlings. All rights reserved.
//

#ifndef Secp256k1_hpp
#define Secp256k1_hpp

#include <libnrcore/memory/Ref.h>
#include <libnrcore/memory/Memory.h>
#include "Cipher.h"

#include <secp256k1.h>

namespace nrcore {
    
    class Secp256k1 : public Cipher {
    public:
        Secp256k1(const Memory& private_key);
        virtual ~Secp256k1();
        
        virtual void setKey(const Memory &key, const Memory &iv) {};
        
        virtual CipherResult encrypt(const char* buf, int len) = 0;
        virtual CipherResult decrypt(const char* buf, int len) = 0;
        
        virtual int getBlockSize() = 0;
        
        Memory sign(const Memory& hash);

    private:
        secp256k1_context *cxt;
        Memory private_key;
        secp256k1_pubkey pub_key;
        
    };
    
}

#endif /* Secp256k1_hpp */
