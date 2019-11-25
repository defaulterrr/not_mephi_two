#include "ISorter.h"

template <typename Comparable>
class InsertSort: public ISorter<Comparable> {
public:
        Sequence<Comparable> *sort(Sequence<Comparable> *seq, Comparable compare_(Comparable first, Comparable second)){
                
                int temp,item; 
                    for (int counter = 1; counter < seq->getLength(); counter++)
                    {
                        temp = seq->get(counter);
                        item = counter-1; 
                        while(item >= 0 && compare_(seq->get(item),temp)) 
                        {
                            seq->setElement(item + 1,seq->get(item));
                            seq->setElement(item,temp);
                            item--;
                        }
                    }


                 return seq;
        }
};