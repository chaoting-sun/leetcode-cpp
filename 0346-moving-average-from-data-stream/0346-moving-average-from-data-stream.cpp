class MovingAverage {
private:
    queue<int> q;
    int size = 0;
    int window_sum = 0;

public:
    MovingAverage(int size) {
        this->size = size;   
    }
    
    double next(int val) {
        q.push(val);
        window_sum += val;
        if (q.size() > size) {
            window_sum -= q.front();
            q.pop();
        }
        return (double)window_sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

// test case: size = 3, next call = 1,2,3,4
// size = 3
// q = [1], window_sum = 1 -> 1/1=1
// q = [1,2], window_sum = 3 -> 3/2=1.5
// q = [1,2,3], window_sum = 6 -> 6/3=2
// q = [1,2,3,4], window_sum = 10, window_sum = 9, q = [2,3,4] -> 9/3=3
