class MyCalendar {
private:
    // key-value map
    // black-red tree: sorted
    map<int,int> bookings;
public:
    MyCalendar() {
        
    }
    /*
     * Complexity: O(lgn)
     * Space: O(n)
     */
    bool book(int start, int end) {
        auto next = bookings.lower_bound(start);
        if(next != bookings.end() && next -> first == start) return false;
        // bigger than start
        if(next != bookings.end() && end > next -> first) return false;
        // for empty array begin() == end()
        if(next != bookings.begin() && (--next) -> second > start) return false;
        bookings[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
