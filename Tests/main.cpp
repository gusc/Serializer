//
//  main.cpp
//  Serializer
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

struct MyStruct {
    int a;
    bool b;
};

template<typename TChar>
void to_pack(gusc::Serializer::BinaryPacker<TChar>& packer, const MyStruct& inValue)
{
    packer << inValue.a << inValue.b;
}

template<typename TChar>
void from_pack(gusc::Serializer::BinaryUnpacker<TChar>& unpacker, MyStruct& outValue)
{
    unpacker >> outValue.a;
    unpacker >> outValue.b;
}

int main(int argc, const char * argv[]) {
    
    // Packer tests
    
    MyStruct x = {
        1, false
    };
    
    std::vector<char> data;
    gusc::Serializer::BinaryPacker packer(data);
    packer << true
           << 'a'
           << static_cast<uint8_t>(255)
           << static_cast<short>(512)
           << 123
           << static_cast<unsigned>(1)
           << static_cast<size_t>(1234567890)
           << static_cast<long>(987654321)
           << x;
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
    MyStruct y;
    unpacker >> a >> b >> c >> d >> e >> f >> g >> h >> y;
    std::cout << a << '\n' << b << '\n' << c << '\n' << d << '\n' << e << '\n' << f << '\n' << g << '\n' << h << '\n' << y.a << ',' << y.b << '\n';
    
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
