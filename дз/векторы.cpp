/* 1)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };
	for_each(vec.begin(), vec.end(), [](int x) {
		cout << x << " ";
		});
	return 0;
}
*/
/* 2)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };
	for_each(vec.begin(), vec.end(), [](int &x) {
		x = x * 2;
		});
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i]<<" ";
	}
	return 0;
}
*/
/*
3)#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	vector<int> vec;
	int n;
	for (int i = 0; i < 20; i++) {
		cout << "type number: ";
		cin >> n;
		vec.push_back(n);
	}
	auto mx= max_element(vec.begin(), vec.end(), [](int x,int y) {
		return x<y;
		});
	cout << "max el: " << *mx;
	return 0;
}
*/
/* 4)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	vector<int> vec;
	int n;
	for (int i = 0; i < 5; i++) {
		cout << "type number: ";
		cin >> n;
		vec.push_back(n);
	}
	auto  newv= remove_if(vec.begin(), vec.end(), [](int x) {
		return x < 0;
		});
	vec.erase(newv, vec.end());
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}

	return 0;
}
*/
/* 5)
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main() {
	vector<int> vec;
	int n;
	for (int i = 0; i < 20; i++) {
		cout << "type number: ";
		cin >> n;
		vec.push_back(n);
	}
	auto mx = max_element(vec.begin(), vec.end(), [](int x, int y) {
		return x < y;
		});
	auto mn = min_element(vec.begin(), vec.end(), [](int x, int y) {
		return x < y;
		});
	cout << "max el: " << *mx << "min el: " << *mn;
	double midd = accumulate(vec.begin(), vec.end(), 0.0);
	midd = midd / vec.size();
	cout << "middle: " << midd;
	vector<int> s = vec;
	sort(s.begin(), s.end());
	double median = s[s.size() / 2 - 1] + s[s.size() / 2] / 2;
	cout << "median: " << median;
	return 0;
}
*/
/* 6)
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main() {
	vector<int> vec;
	int n;
	for (int i = 0; i < 20; i++) {
		cout << "type number: ";
		cin >> n;
		vec.push_back(n);
	}
	auto num = find(vec.begin(), vec.end(), 7);
	if (num != vec.end())
		cout << "7 find" << "\n";
	else cout << "not found" << "\n";

	sort(vec.begin(), vec.end());
	auto l = unique(vec.begin(), vec.end());
	vec.erase(l, vec.end());
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	return 0;
}
*/
/* 7)
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main() {
	vector<int> vec;
	double n;
	int k;
	cout << "quantity: ";
	cin >> k;
	for (int i = 0; i < k; i++) {
		cout << "type number: ";
		cin >> n;
		vec.push_back(n);
	}
	auto  newv = remove_if(vec.begin(), vec.end(), [](double x) {
		return x < -50 || x>50;
		});
	vec.erase(newv, vec.end());
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	auto mx = max_element(vec.begin(), vec.end(), [](int x, int y) {
		return x < y;
		});
	auto mn = min_element(vec.begin(), vec.end(), [](int x, int y) {
		return x < y;
		});
	cout << "max temp: " << *mx << ", min temp: " << *mn;
	double midd = accumulate(vec.begin(), vec.end(), 0.0);
	midd = midd / vec.size();
	cout << ", middle temp: " << midd;
	return 0;
}
*/
/*
8)
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main() {
	vector<int> vec;
	double n;
	int k;
	cout << "quantity: ";
	cin >> k;
	for (int i = 0; i < k; i++) {
		cout << "type number: ";
		cin >> n;
		vec.push_back(n);
	}
	auto  newv = remove_if(vec.begin(), vec.end(), [](double x) {
		return  x >= 120;
		});
	vec.erase(newv, vec.end());
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	double midd = accumulate(vec.begin(), vec.end(), 0.0);
	midd = midd / vec.size();
	cout << ", middle temp: " << midd;
	auto num = find(vec.begin(), vec.end(), 0);
	if (num != vec.end())
		cout << "0 find " << "\n";
	else cout << "not found 0 " << "\n";
	sort(vec.begin(), vec.end()); 
	for (int i = vec.size() - 10; i < vec.size(); i++) {
		cout <<"max 10 elements: " << vec[i] << " ";
	}

	return 0;
}
*/
/* 9)
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main() {
	vector<int> vec;
	double n;
	for (int i = 0; i < 20; i++) {
		cout << "type number: ";
		cin >> n;
		vec.push_back(n);
	}
	auto  newv = remove_if(vec.begin(), vec.end(), [](double x) {
		return x <0;
		});
	vec.erase(newv, vec.end());
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	auto mx = max_element(vec.begin(), vec.end(), [](int x, int y) {
		return x < y;
		});
	auto mn = min_element(vec.begin(), vec.end(), [](int x, int y) {
		return x < y;
		});
	cout << "max power: " << *mx << ", min power: " << *mn;
	double midd = accumulate(vec.begin(), vec.end(), 0.0);
	midd = midd / vec.size();
	cout << ", middle power: " << midd;
	bool within_range = all_of(vec.begin(), vec.end(),
		[](double x) { return x >= 10 && x <= 90; });
	cout << ", work in 10-90 kwt: " << (within_range ? "yes" : "no") << endl;

	sort(vec.begin(), vec.end());
	double median = vec[vec.size() / 2 - 1] + vec[vec.size() / 2] / 2;
	cout << "median: " << median;
	return 0;
}
*/
/*
 10)
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main() {
	vector<int> vec;
	double n;
	for (int i = 0; i < 20; i++) {
		cout << "type number: ";
		cin >> n;
		vec.push_back(n);
	}
	auto mx = max_element(vec.begin(), vec.end(), [](int x, int y) {
		return x < y;
		});
	auto mn = min_element(vec.begin(), vec.end(), [](int x, int y) {
		return x < y;
		});
	cout << "max power: " << *mx << ", min power: " << *mn;
	double sum = accumulate(vec.begin(), vec.end(), 0.0);
	double midd = sum / vec.size();
	cout << ", sum power: " << sum;
	cout << ", mid power: " << midd;
	auto minmax = minmax_element(vec.begin(), vec.end());
	double threshold = midd * 1.2;
	cout << "max days (> " << threshold << " kv): ";
	for (double cons : vec) {
		if (cons > threshold) {
			cout << cons << " ";
		}
	}
	cout << endl << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	return 0;
}
*/
/* 11)
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main() {
	vector<int> vec;
	double n;
	for (int i = 0; i < 20; i++) {
		cout << "type number: ";
		cin >> n;
		vec.push_back(n);
	}
	auto  newv = remove_if(vec.begin(), vec.end(), [](double x) {
		return x < 0.1;
		});
	vec.erase(newv, vec.end());
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	auto mx = max_element(vec.begin(), vec.end(), [](double x, double y) {
		return x < y;
		});
	auto mn = min_element(vec.begin(), vec.end(), [](double x, double y) {
		return x < y;
		});
	cout << "max: " << *mx << ", min: " << *mn;
	sort(vec.begin(), vec.end());
	if (*mn < 0.5) {
		cout << "have el <0.5";
	}
	cout << ", max 10 elements: ";
	for (int j = vec.size() - 10; j < vec.size(); j++) {
		cout << vec[j] << " ";
	}
	return 0;
}
*/
/*12)
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	vector<double> fuel = { 85, 70, 60, 50, 45, 40, 35, 30, 25, 20 };

	double min_fuel = *min_element(fuel.begin(), fuel.end());
	cout << "минимальный уровень: " << min_fuel << "%" << endl;

	double max_fuel = *max_element(fuel.begin(), fuel.end());
	bool never_low = all_of(fuel.begin(), fuel.end(),
		[max_fuel](double f) { return f >= max_fuel * 0.05; });
	cout << "никогда не опускалс€ ниже 5%: " << (never_low ? "ƒа" : "Ќет") << endl;

	double consumption = fuel.front() - fuel.back();
	cout << "потребление: " << consumption << "%" << endl;

	sort(fuel.begin(), fuel.end());
	double median = fuel[fuel.size() / 2];
	cout << "медиана: " << median << "%" << endl;

	return 0;
}
*/
/* 13)
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	vector<double> pressure = { 8.5, 15.0, 7.2, -1.0, 9.8, 6.5, 13.2, 4.8, 10.5, 11.1 };

	pressure.erase(remove_if(pressure.begin(), pressure.end(),
		[](double p) { return p < 0 || p > 12; }),
		pressure.end());
	double avg = accumulate(pressure.begin(), pressure.end(), 0.0) / pressure.size();
	cout << "среднее давление: " << avg << " бар" << endl;
	auto minmax = minmax_element(pressure.begin(), pressure.end());
	cout << "ћин: " << *minmax.first << " бар, ћакс: " << *minmax.second << " бар" << endl;

	cout << "давление > 8 бар: ";
	for_each(pressure.begin(), pressure.end(), [](double p) {
		if (p > 8) cout << p << " ";
		});
	cout << endl;

	return 0;
}
*/
/* 14)
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	vector<double> consumption = { 350, 280, 420, 310, 390, 250, 450, 320, 380, 290, 410, 330 };

	double total = accumulate(consumption.begin(), consumption.end(), 0.0);
	double avg = total / consumption.size();
	cout << "суммарное: " << total << " к¬тЈч" << endl;
	cout << "среднее: " << avg << " к¬тЈч" << endl;

	auto peak = max_element(consumption.begin(), consumption.end());
	cout << "пиковое потребление: " << *peak << " к¬тЈч" << endl;

	vector<double> deviations(consumption.size());
	transform(consumption.begin(), consumption.end(), deviations.begin(),
		[avg](double c) { return c - avg; });

	sort(consumption.begin(), consumption.end());
	cout << "топ 5 минимальных: ";
	for (int i = 0; i < 5; i++) {
		cout << consumption[i] << " ";
	}
	cout << endl;

	return 0;
}
*/
/* 15)
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	vector<vector<double>> temp = {
		{25, 26, 24, 27, 25},
		{30, 29, 31, 28, 30},
		{22, 23, 21, 24, 22}
	};

	vector<vector<double>> pressure = {
		{5.5, 6.0, 5.8, 6.2, 5.9},
		{7.2, 7.5, 7.1, 7.8, 7.3},
		{4.8, 5.2, 4.9, 5.5, 5.1}
	};

	vector<double> avg_temps;
	for (auto& channel : temp) {
		double avg = accumulate(channel.begin(), channel.end(), 0.0) / channel.size();
		avg_temps.push_back(avg);
		cout << "средн€€ температура: " << avg << endl;
	}

	for (int i = 0; i < pressure.size(); i++) {
		auto minmax = minmax_element(pressure[i].begin(), pressure[i].end());
		cout << "канал " << i + 1 << ": min=" << *minmax.first << ", max=" << *minmax.second << endl;
	}

	int max_var_channel = 0;
	double max_var = 0;
	for (int i = 0; i < temp.size(); i++) {
		double var = *max_element(temp[i].begin(), temp[i].end()) -
			*min_element(temp[i].begin(), temp[i].end());
		if (var > max_var) {
			max_var = var;
			max_var_channel = i;
		}
	}
	cout << "канал с наибольшей вариацией: " << max_var_channel + 1 << endl;
	for (auto& channel : pressure) {
		double min_val = *min_element(channel.begin(), channel.end());
		double max_val = *max_element(channel.begin(), channel.end());
		for (double& p : channel) {
			p = (p - min_val) / (max_val - min_val);
		}
	}
	cout << "пики давлени€: ";
	for (auto& channel : pressure) {
		for (double p : channel) {
			if (p > 0.9) cout << p << " ";
		}
	}
	cout << endl;
	auto hottest = max_element(avg_temps.begin(), avg_temps.end());
	cout << "самый гор€чий канал: " << distance(avg_temps.begin(), hottest) + 1 << endl;

	return 0;
}
*/