#ifndef DICTIONARY_H
#define DICTIONARY_H

    template<typename Key, typename Value> class Dictionary {
        public:
            virtual int getCount() = 0;
            virtual int getCapacity() = 0;
            virtual Value get(Key key) = 0;
            virtual bool containsKey(Key key) = 0;
            virtual void add(Value value) = 0;
            virtual void add(Key key, Value value) = 0;
    };

#endif