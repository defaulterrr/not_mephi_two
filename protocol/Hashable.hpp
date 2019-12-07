#ifndef HASHABLE_H
#define HASHABLE_H

    class Hashable {
        public: 
            virtual int hash() const= 0;
            virtual int hash(int max) const= 0;
    };

#endif
