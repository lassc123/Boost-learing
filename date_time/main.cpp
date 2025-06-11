#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

//处理时间的组件
#include <boost/date_time/gregorian/gregorian.hpp>
//using namespace boost::gregorian; 对应库的命名空间
#include <boost/date_time/posix_time/posix_time.hpp>
//using namespace boost::posix_time; 对应库的命名空间

//data_time库中的一些特殊值利用枚举special_values来定义，位于命名空间boost::date_time
//pos_infin：表示正无限。
//neg_infin：表示负无限。
//not_a_date_time：无效时间。
//min_date_time：可表示的最小日期或时间。
//max_date_time：可表示的最大日期或时间。

// template<typename T,typename calendar,typename duration_type_>
// class date {
// public:
//     date(year_type,month_type,day_type);    //构造函数
//     date(const ymd_type&)
//
//     year_type year() const;     //基本操作函数
//     month_type month() const;
//     day_type day() const;
//     day_of_week_type day_of_week() const;
//     ymd_type year_month_day() const;
//
//     bool operator<(const date_type&) const;     //比较操作函数
//     bool operator==(const date_type&) const;
//
//     bool is_special() const;    //有效性验证
//     bool is_not_a_date() const;
//     bool is_infinity() const;
//     bool is_pos_infinity() const;
//     bool is_neg_infinity() const;
//     special_values as_special() const;
//
//     duration_type operator-(const date_type&) const;
//     //其他日期运算
// };
//int main() {
    // boost::gregorian::date d1;  //一个无效的日期
    // boost::gregorian::date d2(2010,1,1);//使用数字来构造日期
    // boost::gregorian::date d3(d2);  //date支持拷贝构造
    //
    // assert(d1 == boost::gregorian::date(boost::date_time::not_a_date_time)); //比较一个临时对象
    // assert(d2 == d3); //date支持比较操作
    // //assert(d3 < d2);
    // boost::gregorian::date d4 = boost::gregorian::from_string("1999-12-31"); //从一个使用连字符分隔符的字符串产生
    // boost::gregorian::date d5 ( boost::gregorian::from_string("2025/6/11")); //从一个使用斜杆分隔符的字符串产生
    // boost::gregorian::date d6 ( boost::gregorian::from_undelimited_string("20050604")); //从一个使用斜杆分隔符的字符串产生
    // // std::cout<<d1<<std::endl;
    // // std::cout<<d2<<std::endl;
    // // std::cout<<d3<<std::endl;
    // // std::cout<<d4<<std::endl;
    // // std::cout<<d5<<std::endl;
    // // std::cout<<d6<<std::endl;
    // //local_day()显示本地时间，universal_day()显示UTC时间
    // std::cout<<boost::gregorian::day_clock::local_day()<< "\n" << boost::gregorian::day_clock::universal_day()<<std::endl;
    // boost::gregorian::date d7(boost::date_time::neg_infin); //负无限日期
    // boost::gregorian::date d8(boost::date_time::pos_infin); //正无限日期
    // boost::gregorian::date d9(boost::date_time::not_a_date_time); //无效日期
    // boost::gregorian::date d10(boost::date_time::max_date_time); //最大可能日期
    // boost::gregorian::date d11(boost::date_time::min_date_time); //最小可能日期
    // std::cout<<d7<<"\n"<<d8<<"\n"<<d9<<"\n"<<d10<<"\n"<<d11<<std::endl;

    //创建日期对象时使用了非法值，或者不存在的月份或者日期，那么date_time会抛出异常，而不是转换为一个无效日期
    // boost::gregorian::date d1(1399,12,1);   //超过日期下限
    // boost::gregorian::date d2(10000,12,1); //超过日期上限
    // boost::gregorian::date d3(2025,13,1);   //不存在的日期
    // std::cout << d1 << std::endl;
    // std::cout << d2 << std::endl;
    // std::cout << d3 << std::endl;
    // boost::gregorian::date date(2025,6,12);
    // assert(date.day() == 12);   //成员函数year()返回日期的年，month()返回日期的月，day()返回日期的日
    // assert(date.month() == 6);
    // assert(date.year() == 2025);
    //
    // //成员函数year_month_day()返回一个date::ymd_type结构，可以一次性获取年月日数据：
    // boost::gregorian::date::ymd_type ymd = date.year_month_day();
    // assert(ymd.year == date.year());
    // assert(ymd.month == date.month());
    // assert(ymd.day == date.day());


    // boost::gregorian::date date(2025,6,12);
    // //成员函数day_of_week()返回date的星期数，0表示星期天
    // std::cout << date.day_of_week() << std::endl;
    // //day_of_year()返回date是当年的第几天
    // std::cout << date.day_of_year() << std::endl;
    // //end_of_month()返回当月的最后一天的date对象
    // std::cout << date.end_of_month() << std::endl;
    // //week_number()返回date所在的周是当年的第几周
    // std::cout << date.week_number() << std::endl;
    // //date还有5个is_xxx()函数，用于检验日期是否为一个特殊日期：
    // assert(boost::gregorian::date(boost::date_time::pos_infin).is_infinity());
    // assert(boost::gregorian::date(boost::date_time::pos_infin).is_pos_infinity());
    // assert(boost::gregorian::date(boost::date_time::neg_infin).is_neg_infinity());
    // assert(boost::gregorian::date(boost::date_time::not_a_date_time).is_not_a_date());
    // assert(boost::gregorian::date(boost::date_time::not_a_date_time).is_special());
    // assert(!boost::gregorian::date(boost::date_time::not_a_date_time).is_special());
    //
    //

    //boost::gregorian::date date(2025,6,12);
    // std::cout << date << std::endl;
    // std::cout << boost::gregorian::to_simple_string(date) << std::endl;
    // std::cout << boost::gregorian::to_iso_string(date) << std::endl;
    // std::cout << boost::gregorian::to_iso_extended_string(date) << std::endl;
    // std::cin>>date;
    // std::cout<<date<<std::endl;
//}
int main() {
    //转换为c结构的tm
    boost::gregorian::date date(2025,6,12);

}