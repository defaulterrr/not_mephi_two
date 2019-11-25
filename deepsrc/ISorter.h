#include "Sequence.h"
#include <functional>

#ifndef MEPHI_LAB_0_ISORTER_H
#define MEPHI_LAB_0_ISORTER_H

template <typename TElement>
class ISorter {
protected:
public:

   virtual Sequence<TElement> *sort(Sequence<TElement> *seq,TElement compare_(TElement first, TElement second));

    bool isSortSuccess(Sequence<TElement> *seq,TElement compare_ = 0) {
        int length = seq->getLength();
        for(int i = 1; i < length; i++) {
            if (compare_(seq->get(i), seq->get(i - 1)) == -1) { //seq->get(i) < seq->get(i-1)
                return false;
            }
        }

        return true;
    }

};


#endif 
