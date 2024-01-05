#pragma warning( disable : 4996 )
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <list>
#include <unordered_map>

using namespace std;

class Person {
public:
	string name;
	int weight;

	//Person();
	//Person(string Name, int Weight) {
	//	name = Name;
	//	weight = Weight;
	//}
};

int main() {

	Person P;
	while (cin >> P.name) {

		queue<Person> Outside;
		queue<Person> Line;
		stack<Person> Elevator;


		while (P.name != "-1") {
			cin >> P.weight;
			Outside.push(P);
			cin >> P.name;
		}
		int n = Outside.size();

		while (Outside.size() || Line.size()) {
			//排隊
			while (Line.size() < 8 && Outside.size() != 0) {
				Line.push(Outside.front());
				Outside.pop();
			}
			//cout << "\n~~" << Line.size()<<"~~\n";

			int W = 0;
			int num = 0;
			//進電梯
			for (int k = 0; k < 8 && Line.size()!=0; k++) {
				if (W + Line.front().weight <= 400) {
					W += Line.front().weight;
					Elevator.push(Line.front());
					Line.pop();
				}
				else
				{
                    Line.push(Line.front());					
					Line.pop();
					break;

					// //cout << "\n==" << Line.front().name << "==\n";
					// Person Over;
					// Over.name = Line.front().name;
					// Over.weight = Line.front().weight;

					// Line.pop();
					// //cout << "\n==" << Line.front().name << "==\n";

					// Line.push(Over);
					// //cout << "\n==" << Line.back().name << "==\n";
                    //break;
				}
			}

			//出電梯
			while (Elevator.size() != 0) {
				cout << Elevator.top().name << " ";
				Elevator.pop();
			}
			cout << endl;


		}
		cout << endl;
	}

}