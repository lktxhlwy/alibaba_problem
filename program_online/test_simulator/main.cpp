#include<iostream>
#include<numeric>
#include<limits>
#include<vector>
using namespace std;
using std::vector;



int baby(vector<int> &table)
{
	int sum = 0;
	for (int i = 2; i < table.size() - 1; i++) {
		sum += table[i];
	}

	return sum;
}

int sum_table(vector<int> &table)
{
	int sum = 0;;
	for (int i = 0; i < table.size(); i++) {
		sum += table[i];
	}

	return sum;
}
void kill(vector<int> &table)
{
	for (int i = table.size() - 1; i >= 2; i++) {
		if (table[i] != 0) {
			table[i] = table[i] - 2;
			return;
		}
	}
}


int result(int x, int y) {
	vector<int> temp(x + 1, 0);
	temp[0] = 2;
	vector<int> table(x + 1, 0);

	for (int i = 0; i < y; i++) {
		for (int j = 1; j < table.size(); j++) {
			table[j] = temp[j - 1];
		}
		table[0] = baby(table);
		

		

		if (sum_table(table) > 10) {
			table[table.size() - 1] = 0;
			kill(table);
			kill(table);
		}

		table[table.size() - 1] = 0;

		temp = table;
		table.assign(x + 1, 0);
	}

	int res = 0;
	for (int i = 0; i < temp.size(); i++) {
		res += i*temp[i];
	}
	return res;
}
int main() {
	int x, y;
	cin >> x;
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	cin >> y;
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	int res = result(x, y);
	cout << res << endl;
	return 0;
}