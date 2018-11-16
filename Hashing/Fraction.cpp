string Solution::fractionToDecimal(int numerator, int denominator) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(numerator == 0) return "0";

    string ans;

    if(numerator < 0 ^ denominator < 0) ans += '-';

    long long numer = numerator < 0 ? (long)numerator * (-1) : (long)numerator;
    long long denom = denominator < 0 ? (long)denominator * (-1) : (long)denominator;

    long integralPart = numer/denom;
    ans += to_string(integralPart);
    long remainder = numer % denom;
    if(remainder == 0) return ans;

    ans += '.';

    unordered_map<long, long> hashMap;
    hashMap[remainder] = ans.length();
    while(remainder != 0)
    {
    	remainder *= 10;
    	long quotient = remainder/denom;
    	ans += to_string(quotient);
    	remainder = (remainder % denom);

    	if(hashMap.find(remainder) != hashMap.end())
    	{
    		ans.insert(hashMap[remainder], 1, '(');
    		ans += ')';
    		break;
    	}
    	else hashMap[remainder] = ans.size();
    }

    return ans;
}

// http://www.geeksforgeeks.org/find-recurring-sequence-fraction/
// https://discuss.leetcode.com/topic/17071/0ms-c-solution-with-detailed-explanations
// https://discuss.leetcode.com/topic/7876/my-clean-java-solution

string Solution::fractionToDecimal(int numerator, int denominator) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(numerator == 0) return "0";

    string ans;

    if(numerator < 0 ^ denominator < 0) ans += '-';

    long long numer = numerator < 0 ? (long)numerator * (-1) : (long)numerator;
    long long denom = denominator < 0 ? (long)denominator * (-1) : (long)denominator;

    long integralPart = numer/denom;
    ans += to_string(integralPart);

    long remainder = numer % denom;
    if(remainder == 0) return ans;

    ans += '.';
    remainder *= 10;

    unordered_map<long, long> hashMap;
    while(remainder != 0)
    {
        long quotient = remainder/denom;
        if(hashMap.find(remainder) != hashMap.end())
        {
            ans.insert(hashMap[remainder], 1, '(');
            ans += ')';
            break;
        }
        hashMap[remainder] = ans.size();
        ans += to_string(quotient);
        remainder = (remainder % denom) * 10;
    }

    return ans;
}