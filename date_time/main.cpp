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
//max_date_time：可表示的最大日期或时间。”

