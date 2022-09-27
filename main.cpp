#include "httplib.h"
#include "iostream"
#include "include/AIGCJson.hpp"
#include "CharacterConverter.h"
using namespace aigc;
using namespace std;

#define CPPHTTPLIB_OPENSSL_SUPPORT

class Student
{
public:
	string Name = "ะกร๗";
	int Age = 18;

	AIGC_JSON_HELPER(Name, Age) //class-members register
	AIGC_JSON_HELPER_RENAME("name", "age")//rename class-members
};

int main() {
	// HTTP
	httplib::Server svr;

	Student person;

	string jsonStr = "";
	JsonHelper::ObjectToJson(person, jsonStr);
	

	svr.Get("/hi", [&](const httplib::Request&, httplib::Response& res) {
		cout << jsonStr << endl;
		res.set_content(GBK_TO_UTF8(jsonStr), "application/json;charset=utf-8");
	});

	svr.listen("0.0.0.0", 8080);
}