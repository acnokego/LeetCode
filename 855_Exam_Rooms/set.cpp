class Interval {
public:
    int start, end, dist;
    Interval(int s, int e, int N){
        start = s;
        end = e;
        if(s == -1){
            dist = e;
        } else if (e == N){
            dist = N - 1 - s;
        } else {
            dist = (e - s) / 2;
        }             
    }
};
class ExamRoom {
private:
    int num_seats;
    
    struct compare{
        bool operator()(const Interval& i1, const Interval& i2)const{
            if(i1.dist == i2.dist){
                return i1.start < i2.start;
            } else{
                return i1.dist > i2.dist;
            }
        }  
    };
    set<Interval, compare>spaces;
public:

    
    ExamRoom(int N) {
        num_seats = N;
        // create node for head(-1), tail(N), nobody in the seat
        spaces.insert(Interval(-1, N, N));
    }
    
    int seat() {
        int seat = 0;
        auto max_interval = spaces.begin();
        if((*max_interval).start == -1){
            seat = 0;
        } else if ((*max_interval).end == num_seats){
            seat = num_seats - 1;
        } else {
            seat = ((*max_interval).start + (*max_interval).end) / 2;
        }
        spaces.insert(Interval((*max_interval).start, seat, num_seats));
        spaces.insert(Interval(seat, (*max_interval).end, num_seats));
        spaces.erase(max_interval);
        return seat;
        
    }
    
    void leave(int p) {
        int merge_start = INT_MIN, merge_end = INT_MIN;
        set<Interval>::iterator delete_1, delete_2;
        for(auto it = spaces.begin(); it != spaces.end(); ++it){
            if((*it).start == p){
                merge_end = (*it).end;
                delete_1 = it;
            }
            if((*it).end == p){
                merge_start = (*it).start;
                delete_2 = it;
            }
            if(merge_end != INT_MIN && merge_start != INT_MIN){
                break;
            }
        }
        
        spaces.erase(delete_1);
        spaces.erase(delete_2);
        // create new interval after remove p
        spaces.insert(Interval(merge_start, merge_end, num_seats));
       
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
