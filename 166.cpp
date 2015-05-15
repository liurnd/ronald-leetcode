#include <iostream>
#include <sstream>
#include <map>
#include <cstdlib>
using namespace std;

class Solution {
public:
    string fractionToDecimal(long numerator, long denominator) {
    	bool neg = false;
    	if (numerator == 0)
    		return "0";

    	if (denominator < 0)
    	{
    		neg = !neg;
    	}
    	if (numerator < 0)
    	{
    		neg = !neg;
    	}
        long long integerPart = numerator / denominator;
        long long remainder = numerator % denominator;
        std::map<long long, long long> remainderMap;

        std::stringstream ss;
        std::string tmpS;
        
        if (integerPart == 0 && neg)
        	ss<<'-';
        ss << integerPart;

        if (remainder == 0)
        	return ss.str();

        long long start = ss.str().size();
        ss << '.';


        for (long long i= 0; true; i++)
        {
        	if (remainder == 0)
        	{
				tmpS = ss.str();
				break;
        	}
        	if (remainderMap.find(remainder)!=remainderMap.end())
        	{
        			ss << ')';
        			tmpS = ss.str();
        			tmpS.insert(start+remainderMap[remainder]+1,1,'(');
        		break;
        	}
        	remainderMap[remainder] = i;
        	long long tmp = remainder * 10 / denominator;
        	ss << (tmp>0?tmp:-tmp);
        	remainder = remainder * 10 % denominator;
        }
        return tmpS;
    }
};

int main()
{
	Solution s;
	cout << s.fractionToDecimal(-1,-2147483648) << endl;
	cout << s.fractionToDecimal(-50,8) << endl;
	cout << s.fractionToDecimal(4,3) << endl;
	cout << s.fractionToDecimal(0,-5) << endl;
	cout << s.fractionToDecimal(6,7) << endl;
	return 0;
}