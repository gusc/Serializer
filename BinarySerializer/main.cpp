//
//  main.cpp
//  BinarySerializer
//
//  Created by Gusts Kaksis on 31/08/2020.
//  Copyright © 2020 Gusts Kaksis. All rights reserved.
//

#include <iostream>
#include <vector>
#include "BinaryPacker.hpp"
#include "BinaryUnpacker.hpp"
#include "BinarySerializer.hpp"
#include "BinaryDeserializer.hpp"

int main(int argc, const char * argv[]) {
    
    // Packer tests
    
    std::vector<char> data;
    gusc::Serializer::BinaryPacker packer(data);
    packer << true
           << 'a'
           << static_cast<uint8_t>(255)
           << static_cast<short>(512)
           << 123
           << static_cast<unsigned>(1)
           << static_cast<size_t>(1234567890)
           << static_cast<long>(987654321);
    std::cout << data.size() << '\n';
    
    gusc::Serializer::BinaryUnpacker unpacker(data);
    bool a;
    char b;
    uint8_t c;
    short d;
    int e;
    unsigned f;
    size_t g;
    long h;
    unpacker >> a >> b >> c >> d >> e >> f >> g >> h;
    std::cout << a << '\n' << b << '\n' << c << '\n' << d << '\n' << e << '\n' << f << '\n' << g << '\n' << h << '\n';
    
    // Serializer tests
    std::vector<uint8_t> data2;
    
    gusc::Serializer::BinarySerializer serializer(data2);
    serializer << a
               << b
               << c
               << d
               << e
               << f
               << g
               << h;
    
    gusc::Serializer::BinaryDeserializer deserializer(data2);
    deserializer >> a >> b >> c >> d >> e >> f >> g >> h;
    
    std::cout << a << '\n' << b << '\n' << c << '\n' << d << '\n' << e << '\n' << f << '\n' << g << '\n' << h << '\n';
    
    return 0;
}
