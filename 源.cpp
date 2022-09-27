#include "httplib.h"
#include "iostream"
using namespace std;

#define CPPHTTPLIB_OPENSSL_SUPPORT


int main() {
	// HTTP
	httplib::Server svr;

	svr.Get("/hi", [](const httplib::Request&, httplib::Response& res) {
		res.set_content("Hello World!", "text/plain");
	});

	svr.listen("0.0.0.0", 8080);
}