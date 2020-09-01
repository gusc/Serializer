# BinarySerializer

Library for binary packing and serialization. Might be useful when working with remote systems or embedded hardware.

## Main classes

### BinaryPacker and BinaryUnpacker

Use this class to pack and unpack data from byte vector. This class is not checking type safety and assumes you know what you're doing. 

Simple usage:

```c++

std::vector<char> data;
gusc::Serializer::BinaryPacker packer(data);

packer << static_cast<uint8_t>(123) << true << 5;

gusc::Serializer::BinaryUnpacker unpacker(data);
uint8_t a;
unpacker >> a; // Should be 123
bool b;
unpacker >> b; // Should be true
int c;
unpacker >> c; // Should be 5
```

Extended usage with custom data types:

TODO

### BinarySerializer and BinaryDeserializer

Use this class to serialize and deserialize data from byte vector. This class *is* checking type safety and will throw a `std::invalid_argument` exception if requested type does not match.

Simple usage:

```c++

std::vector<char> data;
gusc::Serializer::BinarySerializer serializer(data);

serializer << static_cast<uint8_t>(123) << true << 5;

gusc::Serializer::BinaryDeserializer deserializer(data);
uint8_t a;
deserializer >> a; // Should be 123
bool b;
deserializer >> b; // Should be true
long c;
deserializer >> c; // will throw as we have written int instead of long
```

Extended usage with custom data types:

TODO
