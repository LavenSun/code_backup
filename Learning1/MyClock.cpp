#if 0
// µœ÷ ±÷”
#include<iostream>
#include<time.h>
#include<iomanip>
using namespace std;
class Clock
{
public:
	Clock()
	{
		time_t t = time(NULL);
		struct tm T = *localtime(&t);
		hour = T.tm_hour;
		minute = T.tm_min;
		second = T.tm_sec;
	}
	void run()
	{
		while (1)
		{
			system("cls");
			//_sleep(1);
			show();
			tick();
		}
	}
private:
	int hour;
	int minute;
	int second;
	void show()
	{
		system("cls");
		cout << setw(2) << setfill('0') << hour << ":";
		cout << setw(2) << setfill('0') << minute << ":";
		cout << setw(2) << setfill('0') << second;
	}
	void tick()
	{
		_sleep(1);
		if (++second == 60)
		{
			second = 0;
			minute++;
			if (++minute == 60)
			{
				minute = 0;
				hour++;
				if (hour == 24)
					hour = 0;
			}
		}
	}
};
int main()
{
	Clock MyClock;
	MyClock.run();
	return 0;
}
#endif