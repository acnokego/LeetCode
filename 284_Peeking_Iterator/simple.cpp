// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
    int n;
    bool has_n;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
      /*
       * get the next value first
       * when the peek() is called return that value. when the next() is called
       * return that value as well and get the next value at the same time.
       */
        has_n = Iterator::hasNext();
        if(has_n) n = Iterator::next();
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return n;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        int ret = n;
        has_n = Iterator::hasNext();
        if(has_n) n = Iterator::next();
	    return ret;
	}

	bool hasNext() const {
	    return has_n;
	}
};
