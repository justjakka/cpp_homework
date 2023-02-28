#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;


class Time {
    private:
        int mHours, mMinutes, mSeconds;
    public:
        Time()
        {
            mHours = 0;
            mMinutes = 0;
            mSeconds = 0;
        }
        
        Time(int hours, int minutes, int seconds)
        {
            mHours = hours;
            mMinutes = minutes;
            mSeconds = seconds;
        }

        Time(string_view s) 
        {   
            int counter = s.length() - 1;
            mMinutes = (s[counter - 4] - 48) * 10 + (s[counter - 3] - 48);
            mSeconds = (s[counter - 1] - 48) * 10 + (s[counter] - 48);

            counter -= 5;
            mHours = 0;
            while (counter >= 1)
            {
                int pow = 1;

                while (isdigit(s[counter]))
                {
                    mHours += (s[counter] - 48) * pow;
                    pow *= 10;
                    counter--;
                }

                counter--;
            }
        }

        Time operator+(Time b) const 
        {   
            Time result;
            result.mSeconds = b.mSeconds + mSeconds;
            result.mMinutes = b.mMinutes + mMinutes + (result.mSeconds / 60);
            result.mSeconds = result.mSeconds % 60;
            result.mHours = b.mHours + mHours + (result.mMinutes / 60);
            result.mMinutes = result.mMinutes % 60;

            return result;
        }

        Time& operator+=(const Time& b)
        {
            this->mSeconds += b.mSeconds;
            this->mMinutes += b.mMinutes + (this->mSeconds / 60);
            this->mSeconds = this->mSeconds % 60;
            this->mHours += b.mHours + (this->mMinutes / 60);
            this->mMinutes = this->mMinutes % 60;

            return *this;
        }

        int hours() const
        {
            return mHours;
        } 
        
        int minutes() const
        {
            return mMinutes;
        } 
        
        int seconds() const
        {
            return mSeconds;
        }

        friend ostream& operator<<(std::ostream& out, Time t)
        {
            out << setfill('0') << setw(2) << t.mHours << ":" << setfill('0') << setw(2) << t.mMinutes << ":" << setfill('0') << setw(2) << t.mSeconds;
            return out;
        }

};

vector<string_view> stringSplit(const string_view str)
{   
    vector<string_view> result;

    int indexCommaToLeftOfColumn = 0;
    int indexCommaToRightOfColumn = -1;

    for (int i = 0; i<static_cast<int>(str.size()); i++)
    {
        if (str[i] == ' ')
        {
            indexCommaToLeftOfColumn = indexCommaToRightOfColumn;
            indexCommaToRightOfColumn = i;
            int index = indexCommaToLeftOfColumn + 1;
            int length = indexCommaToRightOfColumn - index;

            string_view column(str.data() + index, length);
            result.push_back(column);
        }
    }
    const string_view finalColumn(str.data() + indexCommaToRightOfColumn + 1, str.size() - indexCommaToRightOfColumn - 1);
    result.push_back(finalColumn);
    return result;
}

vector<Time> getTimesFromString(string_view s)
{
    vector<string_view> strings = stringSplit(s);
    vector<Time> result;
    for (auto i: strings)
        result.push_back(Time(i));
    
    return result;
}

Time sumTimes(const vector<Time>& v)
{
    Time result;
    for (auto i: v)
        result += i;
    
    return result;
}

int main()
{
    Time test1(11, 22, 7);
    cout << test1 << endl;

    cout << endl;

    string_view a("12:37:56");
    Time test2(a);
    cout << test2 << endl;

    cout << endl;

    cout << test2 + test1 << endl;

    cout << endl;

    test1 += test2;

    cout << test1 << endl;

    cout << endl;

    vector<Time> test4 = getTimesFromString("12:20:05 05:45:30 22:10:45");
    for (auto i: test4)
        cout << i << endl;
    
    cout << endl;

    Time test5 = sumTimes(test4);
    cout << test5 << endl;
}