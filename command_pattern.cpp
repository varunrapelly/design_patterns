/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : command_pattern.cpp

* Purpose :

* Creation Date : 31-07-2019

* Last Modified : Wed Jul 31 09:06:37 2019

* Created By :  

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iostream>
#include <vector>
#include <memory>
#include <iterator>

using namespace std;

class Command
{
public:
	int res;
	virtual ~Command() {}
	virtual void execute() = 0;
	
};

class Add:public Command
{
public:
	Add(int a, int b):a(a),b(b) {}
	int a,b;
	void execute() override {
		res = a+b;
	}
};

class Sub:public Command
{
public:
	Sub(int a, int b):a(a),b(b) {}
	int a,b;
	void execute() override {
		res = a-b;
	}
};
class Mod:public Command
{
public:
	Mod(int a, int b):a(a),b(b) {}
	int a,b;
	void execute() override {
		res = a%b;
	}
};


class Div:public Command
{
public:
	Div(int a, int b):a(a),b(b) {}
	int a,b;
	void execute() override {
		res = a/b;
	}
};

class Math
{
public:
	vector<std::unique_ptr<Command>> cmds;
	void run()
	{
		vector<std::unique_ptr<Command>>::iterator s;
		for (s = cmds.begin(); s != cmds.end(); s++)
		{
			(*s)->execute();
			cout << " Res: " << (*s)->res << endl;

		}
	}
};

int main()
{
	Math m;
	m.cmds.push_back(std::unique_ptr<Command>(new Add(1,2)));
	m.cmds.push_back(std::unique_ptr<Command>(new Sub(11,2)));
	m.cmds.push_back(std::unique_ptr<Command>(new Mod(11,3)));
	m.cmds.push_back(std::unique_ptr<Command>(new Div(11,4)));
	m.run();
}
