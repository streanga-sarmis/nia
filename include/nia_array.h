#ifndef _NIA_ARRAY_H_
#define _NIA_ARRAY_H_

#include "nia_general.h"

template<typename T>
NIA_CLASS niaArray {
private:
    u32 size;
    T* data;

public:
    NIA_CALL niaArray();
    NIA_CALL ~niaArray();

    NIA_CALL void add(T element);
    NIA_CALL void clean();
    NIA_CALL T* getData();
    NIA_CALL u32 getSize() const;
    
    NIA_CALL T& operator[](u32 index) const;
};

#include "nia_vector.h"
template class niaArray<int>;
template class niaArray<unsigned int>;
template class niaArray<unsigned short>;

template class niaArray<niaVector3<float> >;
template class niaArray<niaVector2<float> >;

template class niaArray<niaVector2<int> >;
template class niaArray<niaVector2<unsigned int> >;

template class niaArray<niaVector3<int> >;
template class niaArray<niaVector3<unsigned int> >;

#endif // _NIA_ARRAY_H_