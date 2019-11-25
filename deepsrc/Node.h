
template<typename TElement>
class Node {
private:
    TElement item_;

    Node<TElement> *prev_;
    Node<TElement> *next_;
public:

    Node() {
        next_ = nullptr;
        prev_ = nullptr;
    }

    explicit Node(TElement item) {
        item_ = item;
        prev_ = nullptr;
        next_ = nullptr;
    }

    ~Node() {
        if (prev_ != nullptr) {
            prev_->setNext(next_);
        }
        if (next_ != nullptr) {
            next_->setPrev(prev_);
        }
        next_ = nullptr;
        prev_ = nullptr;;
    }

    TElement getItem() {
        return item_;
    }

    void setitem(TElement item) {
        item_ = item;
    }

    Node<TElement> *getNext() {
        return next_;
    }

    Node<TElement> *getPrev() {
        return prev_;
    }

    void setNext(Node<TElement> *next) {
        next_ = next;
    }

    void setPrev(Node<TElement> *prev) {
        prev_ = prev;
    }
};

