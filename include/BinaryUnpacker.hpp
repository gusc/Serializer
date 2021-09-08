//
//  BinaryUnpacker.h
//  Serializer
//
//  Created by Gusts Kaksis on 31/08/2020.
//  Copyright © 2020 Gusts Kaksis. All rights reserved.
//

#ifndef BinaryUnpacker_h
#define BinaryUnpacker_h

namespace gusc::Serializer
{
    
template<typename TChar,
         typename _ = typename std::enable_if<sizeof(TChar)==1>::type>
class BinaryUnpacker
{
    typedef typename std::vector<TChar>::const_iterator const_iterator;
    
public:
    BinaryUnpacker(std::vector<TChar>& initTargetVector)
        : itBegin(initTargetVector.cbegin())
        , itEnd(initTargetVector.cend())
    {}
    
    template<typename TValue>
    BinaryUnpacker& operator>>(TValue& outValue);
    
    inline void read(TChar* data, size_t numElements)
    {
        if (size() < numElements)
        {
            throw std::length_error("Insufficient data");
        }
        std::copy(itBegin, itBegin + numElements, data);
        itBegin += numElements;
    }
    
    inline void peek(TChar* data, size_t numElements)
    {
        if (size() < numElements)
        {
            throw std::length_error("Insufficient data");
        }
        std::copy(itBegin, itBegin + numElements, data);
    }
    
    inline size_t size() const noexcept
    {
        return static_cast<size_t>(std::distance(itBegin, itEnd));
    }
    
    inline void skip(size_t numElements)
    {
        if (size() < numElements)
        {
            throw std::length_error("Insufficient data");
        }
        itBegin += numElements;
    }
    
private:
    const_iterator itBegin;
    const_iterator itEnd;
};

template<typename TChar, typename TEnable>
template<typename TValue>
BinaryUnpacker<TChar, TEnable>& BinaryUnpacker<TChar, TEnable>::operator>>(TValue& outValue)
{
    from_pack(*this, outValue);
    return *this;
}

template<typename TChar>
void from_pack(BinaryUnpacker<TChar>& unpacker, TChar& outValue)
{
    unpacker.read(&outValue, 1);
}

template<typename TChar,
         typename TValue>
void from_pack(BinaryUnpacker<TChar>& unpacker, TValue& outValue)
{
    TChar tmp[sizeof(TValue)];
    unpacker.read(&tmp[0], sizeof(TValue));
    memcpy(&outValue, tmp, sizeof(TValue));
}

template<typename TChar,
         typename TValue>
void from_pack(BinaryUnpacker<TChar>& unpacker, std::vector<TValue>& outValue)
{
    for (auto& it : outValue)
    {
        unpacker >> *it;
    }
}

}

#endif /* BinaryUnpacker_h */
