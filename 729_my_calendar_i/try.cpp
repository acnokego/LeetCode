class MyCalendar {
private:
    vector<pair<int,int>> bookings;
public:
    MyCalendar() {
        
    }
    /*
     * Complexity: O(n) # the number of booked events
     * Space: O(n)
     */
    bool book(int start, int end) {
        int i = 0;
        for(; i < bookings.size(); ++i){
            int start_2 = bookings[i].first, end_2 = bookings[i].second;
            // 1. start is inside a booking interval.
            // 2. end is inside a booking interval
            // 3. the booking interval cover (larger) than a interval already booked
            if((start >= start_2 && start < end_2)
                || (end > start_2 && end <= end_2) 
                || (start < start_2 && end > end_2)) return false;
            // no overlap, it ends earlier than the start time of this event
            // also, its start_time is >= than previous end
            else if(end <= start_2) break;
        }
        if(i == bookings.size()) bookings.push_back(make_pair(start, end));
        else bookings.insert(bookings.begin() + i, make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
