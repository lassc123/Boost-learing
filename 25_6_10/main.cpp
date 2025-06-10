#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


//boost中timer库的使用
#define BOOST_TIMER_ENABLE_DEPRECATED //启用已经废弃的boost——timer模块
#include <boost/timer.hpp>

int main() {
    boost::timer t; //声明一个计时器对象，开始计时

    cout << "max timespan:" << t.elapsed_max()/3600 << "h" << endl; //可度量的最大时间，以小时为单位

    cout << "min timespan:" << t.elapsed_min() << "s" << endl; //可度量的最小时间，以秒为单位

    cout << "now time elapsed:" << t.elapsed() << "s" << endl; //从开始到现在输出已经流逝的时间
}

//源码：
class timer {
public:
    //std::clock()
    timer() {_start_time = std::clock();}
    void restart() {_start_time = std::clock();}
    double elapsed() const{
        return (std::clock() - _start_time)/static_cast<double>(CLOCKS_PER_SEC);
    }
    double elapsed_min() const {
        return (1)/static_cast<double>(CLOCKS_PER_SEC);
    }
    double elapsed_max() const {
        return (static_cast<double>((std::numeric_limits<std::clock_t>::max)()) - static_cast<double>(_start_time)/static_cast<double>(CLOCKS_PER_SEC));
    }
private:
    std::clock_t _start_time;
};