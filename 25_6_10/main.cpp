#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


// //boost中timer库的使用
// #define BOOST_TIMER_ENABLE_DEPRECATED //启用已经废弃的boost——timer模块
// #include <boost/timer.hpp>
//
// int main() {
//     boost::timer t; //声明一个计时器对象，开始计时
//
//     cout << "max timespan:" << t.elapsed_max()/3600 << "h" << endl; //可度量的最大时间，以小时为单位
//
//     cout << "min timespan:" << t.elapsed_min() << "s" << endl; //可度量的最小时间，以秒为单位
//
//     cout << "now time elapsed:" << t.elapsed() << "s" << endl; //从开始到现在输出已经流逝的时间
// }

//源码：
// class timer {
// public:
//     //std::clock()函数，返回自进程启动以来的clokc数
//     timer() {_start_time = std::clock();}//以当前的clock为计时起点
//     void restart() {_start_time = std::clock();}//更新clokc数，进行重新计时
//     double elapsed() const{
//         return (std::clock() - _start_time)/static_cast<double>(CLOCKS_PER_SEC)//每秒的clock数
//     }
//     double elapsed_min() const {
//         return (1)/static_cast<double>(CLOCKS_PER_SEC);//timer能测量的最小时间
//     }
//     double elapsed_max() const {
//         return (static_cast<double>((std::numeric_limits<std::clock_t>::max)()) - static_cast<double>(_start_time)/static_cast<double>(CLOCKS_PER_SEC));
//         利用标准库的数值极限类numeric_limits来获得clokc_t的最大值，从而求得能测量的最大时间范围
//     }
//     无析构函数->仅有一个类型为clokc_t的成员变量_start_time,不需要析构函数来特意释放申请的资源
// private:
//     std::clock_t _start_time;
// };

#define BOOST_TIMER_ENABLE_DEPRECATED//启用已经废弃的boost——timer模块
#include <boost/progress.hpp>//progress_timer是timer的一个派生类
// int main() {
//     boost::progress_timer t;  //声明一个计时器对象，开始计时，记录的是cpu时间而不是墙钟时间,使得sleep函数对计时器不会有影响
//
//     //do someting...
//     sleep(10);
//     //退出作用域，自动调用progress_timer的析构函数，并且输出流逝的时间
// }
// int main() {
//     //要在一个程序中测量多个时间，可以用花括号{}来限定progress_timer的生命周期
//     {
//         boost::progress_timer t;    //第一个计时
//         //do someting...
//         //退出作用域，自动调用progress_timer的析构函数，并且输出流逝的时间
//     }
//     {
//         boost::progress_timer t;    //第二个计时
//         //do someting...
//         //退出作用域，自动调用progress_timer的析构函数，并且输出流逝的时间
//     }
// }
// class progress_timer:public boost::timer,noncopyable {
// public:
//     explicit progress_timer();
//     progress_timer(std::ostream& os);
//     ~progress_timer();
// };
// int main() {
//  std::stringstream ss; //一个字符串流对象
//  {
//   boost::progress_timer t(ss);  //要求progress_tmier输出到ss中
//                                     //progress_timer在这里析构，自动输出时间
//  }
//  cout << ss.str() << endl;
// }