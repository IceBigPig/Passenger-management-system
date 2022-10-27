#include "httplib.h"
#include "iostream"
#include "include\AIGCJson.hpp"
#include "CharacterConverter.h"
#include "passenger.h"
#include "thread"
#include "service.h"
using namespace aigc;
using namespace std;

#define CPPHTTPLIB_OPENSSL_SUPPORT

int times = 999;

class Student
{
public:
	string Name = "小明";
	int Age = 18;
	void test() {
		cout << "213" << endl;
	}

	AIGC_JSON_HELPER(Name, Age) //class-members register
	AIGC_JSON_HELPER_RENAME("name", "age")//rename class-members
};

class tes1t : private Student {

	void test() {
		
		return Student::test();
	}
};

void httpServerTest() {
// HTTP
	httplib::Server svr;
	Student person;
	Passenger passenger("123", "123", "123");
	string jsonStr = "";
	Passenger a[10];

	JsonHelper::ObjectToJson(person, jsonStr);

	svr.Get("/hi", [&](const httplib::Request& req, httplib::Response& res) {
		cout << jsonStr << endl;
		res.set_content(GBK_TO_UTF8(jsonStr), "application/json;charset=utf-8");
		cout << req.get_header_value("1") << endl;
		cout << req.body << endl;
		cout << req.get_param_value("2") << endl;
	});
	svr.listen("0.0.0.0", 8080);
}

void thread_fun(int n) {
	while (1) {
		std::cout << n << "\t" << times++ << endl;
		Sleep(2);
	}
}



void test() {
	
	std::thread myThread_1(thread_fun, 1);
	std::thread myThread_2(thread_fun, 2);
	myThread_1.join();
	myThread_2.join();
}


void Menu() {
	while (true) {
		cout << "---------------------------------\n";
		cout << "\t0、创建房间\n";
		cout << "\t1、查看住宿情况\n";
		cout << "\t2、办理住宿\n";
		cout << "\t3、办理结算\n";
		cout << "---------------------------------\n";
		int order_cmd;
		cin >> order_cmd;
		switch (order_cmd)
		{
		case 0:
			addRooms();
		case 1:
			cout << "入住情况\n";
			viewLodgingState();
			break;
		case 2:
			lodging();
			break;
		case 3:
			cout << "结算\n";
			settlement();
			break;
		default:
			cout << "请输入正确命令！\n";
			break;
		}
	}
}

int main() {
	serviceInit();

	std::thread myThread_1(Menu);
	myThread_1.join();
	myThread_1.detach();
	std::thread myThread_2(Menu);
	myThread_2.join();
	myThread_2.detach();
}