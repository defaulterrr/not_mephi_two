#ifndef HASHABLE_H
#define HASHABLE_H

    class Hashable {
        public: 
            virtual int hash() = 0;
            virtual int hash(int max) = 0;
    };

#endif