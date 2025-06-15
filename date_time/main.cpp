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
// int main() {
//     //转换为c结构的tm
//     boost::gregorian::date date(2025,6,12);
//     // std::cout << date << std::endl;
//     //to_tm(date):将date转换到tm。将tm的时分秒均置为0，夏令时标志tm_isdst置为-1（表示未知）
//     // datetm.tm_year = ymd.year - 1900;
//     // datetm.tm_mon = ymd.month - 1;
//     // datetm.tm_mday = ymd.day;
//     tm t = to_tm(date);
//     assert(t.tm_hour == 0 && t.tm_min == 0 && t.tm_sec == 0);
//     std::cout << t.tm_year << std::endl;
//     std::cout << t.tm_mon << std::endl;
//     std::cout << t.tm_mday << std::endl;
//     assert(t.tm_mon == 5 && t.tm_mday == 12 && t.tm_year == 125);
//
//     //date_from_tm(datetm)：将tm转换到date，只使用年月日三个成员
//     boost::gregorian::date d2 = boost::gregorian::date_from_tm(t);
//     assert(date == d2);
// }
//日期长度？以天为单位的时长，度量时间长度的一个标量，可正可负，任何整数
//基本的日期长度类date_duration,其类摘要：
// class date_duration {
// public:
//     date_duration(long); //构造函数：“date_duration可以使用构造函数创建一个日期长度”
//     date_duration(boost::date_time::special_values);
//
//     long days() const;  //成员访问函数，“days（）返回时长的天数”
//     bool is_special() const; //“is_special（）和is_negative（）可以判断date_duration对象是否为特殊值”
//     bool is_negative() const;
//
//     bool operator==(const date_duration&) const;    //操作符函数，“date_duration支持全序比较操作（==、！=、＜、＜=等）
//                                                      ，也支持完全的加减法和递增递减操作”
//     static date_duration unit();    //时长单位，“unit（）返回时长的最小单位，即date_duration（1）”
//
// “此外date_duration还支持除法运算，可以除以一个整数，但不能除以另一个date_duration，
// 它不支持其他的数学运算，如乘法、取模、取余等”
// };

// int main() {
//     boost::gregorian::days dd1(10),dd2(-200),dd3(225);
//     assert(dd1>dd2 && dd1<dd3);
//     assert(dd1+dd2 == boost::gregorian::days(-190));
//     assert((dd1+dd3).days() == 235);
//     assert(dd1/5==boost::gregorian::days(2));
// }
//

//为了方便计算时间长度，date_time库还提供了months、years、weeks3个时长类，分别用来表示月、年和星期

// int main() {
//     boost::gregorian::weeks w(3); //三个星期
//     assert(w.days() == 21);
//
//     boost::gregorian::months m(5); //5个月
//     boost::gregorian::years y(2); //2年
//
//     boost::gregorian::months m2 = y+m; //两年零五个月
//     assert(m2.number_of_months() == 29);
//     assert((y*2).number_of_years() == 4);
// }

//日期计算
//date支持加减运算，但是两个date对象的加法操作是无意义的（编译错误的形式告知），date主要用来与时长概率进行运算
//int main() {
    // boost::gregorian::date d1(2000,1,1),d2(2017,11,18);
    // std::cout<<d1 - d2 << std::endl;
    // assert(d1 + (d2 - d1) == d2);
    //
    // d1 += boost::gregorian::days(10); //2000-1-11
    // assert(d1.day() == 11);
    //
    // d1 += boost::gregorian::months(2); //2000-3-11
    // assert(d1.month() == 3 && d1.day() == 11);
    //
    // d1 -= boost::gregorian::weeks(1); //2000-3-4
    // assert(d1.day() == 4);
    //
    // d2 -= boost::gregorian::years(10);
    // assert(d2.year() == d1.year() + 7);

    // boost::gregorian::date d1(2017,1,1);
    // boost::gregorian::date d2 = d1 + boost::gregorian::days(boost::date_time::pos_infin);
    // assert(d2.is_pos_infinity());
    //
    // d2 = d1 + boost::gregorian::days(boost::date_time::not_a_date_time);
    // assert(d2.is_not_a_date());
    //
    // d2 = boost::gregorian::date(boost::date_time::neg_infin);
    // boost::gregorian::days dd = d1 - d2;
    // assert(dd.is_special() && !dd.is_negative());

    // boost::gregorian::date d(2017,3,30);
    // d -= boost::gregorian::months(1); //2017-2-28,变为2月月末，同时30的日期信息丢失
    // d -= boost::gregorian::months(1); //2017-1-31
    // d += boost::gregorian::months(2); //2017-3-31
    // std::cout << d << std::endl;
    // assert(d.day() == 31); //与原来的日期不一致
//}

//int main() {
    // boost::gregorian::date_period dp1(boost::gregorian::date(2017,1,1),boost::gregorian::days(20));
    //
    // assert(!dp1.is_null());
    // assert(dp1.length().days() == 20);
    // assert(dp1.begin().day() == 1);
    // assert(dp1.last().day() == 20);
    // assert(dp1.end().day() == 21);
    //
    // std::cout << dp1 << std::endl;
    //
    // //shift()将日期区间平移n天，而长度不变
    // dp1.shift(boost::gregorian::days(3));
    // std::cout << dp1 << std::endl;
    //
    // //expand（）将日期向两端延伸n天，相当于区间长度增加2n天
    // dp1.expand(boost::gregorian::days(3));
    // std::cout << dp1 << std::endl;

    // boost::gregorian::date_period dp(boost::gregorian::date(2010,1,1),boost::gregorian::days(20)); //1-1至1-20
    //
    // assert(dp.is_after((boost::gregorian::date(2009,12,1))));
    // assert(dp.is_before((boost::gregorian::date(2010,12,1))));
    // assert(dp.contains((boost::gregorian::date(2010,1,10))));
    //
    // boost::gregorian::date_period dp2(boost::gregorian::date(2010,1,5),boost::gregorian::days(10)); //1-5至1-15
    //
    // assert(dp.contains(dp2));
    //
    // assert(dp.intersects(dp2));
    // assert(dp.intersection(dp2) == dp2);
    //
    // boost::gregorian::date_period dp3(boost::gregorian::date(2010,1,21),boost::gregorian::days(5)); //1-21至1-26
    // assert(!dp3.intersects(dp2));
    // assert(dp.intersection(dp3).is_null());
    //
    // assert(dp.is_adjacent(dp3)); //表两个时段是否相切
    // assert(!dp.intersects(dp3));

    // merge()：返回两个日期区间的并集，如果日期区间无交集或不相邻，则返回无效区间
    // span()：合并两个日期区间及其两者间的间隔，相当于广义的merge()
    //  boost::gregorian::date_period dp1(boost::gregorian::date(2010,1,1),boost::gregorian::days(20));
    //  boost::gregorian::date_period dp2(boost::gregorian::date(2010,1,5),boost::gregorian::days(10));
    //  boost::gregorian::date_period dp3(boost::gregorian::date(2010,2,1),boost::gregorian::days(5));
    //
    //  boost::gregorian::date_period dp4(boost::gregorian::date(2010,1,15),boost::gregorian::days(10));
    //
    //  assert(dp1.contains(dp2) && dp1.merge(dp2) == dp1);
    //  assert(!dp1.intersects(dp3) && dp1.merge(dp3).is_null());
    //  assert(dp1.intersects(dp2) && dp1.merge(dp4).end() == dp4.end());
    //  assert(dp1.span(dp3).end()==dp3.end());
//}


//日期迭代器
int main() {

}






