#include <iostream>
#include <afxinet.h>
using namespace std;

int main(int argc, char* argv[]) {
	LPCTSTR ip = "10.0.2.2";
	INTERNET_PORT port = 80;
	LPCTSTR path = "/";

	if (argv[1] != NULL) {
		ip = argv[1];
		if (argv[2] != NULL) {
			port = (unsigned short)(LPWSTR) argv[2];
		}
	}

	cout << "Establishing connection to "
		<< ip << ":" << port << "..." << endl;

	CInternetSession session("HelloWorld");
	CHttpConnection* connection = session.GetHttpConnection(
		ip, port);
	CHttpFile* res = connection->OpenRequest("GET", path);
	CHAR buff[1024];
	if (res->SendRequest()) {
		while(res->Read(buff, 1024)) {
			cout << buff;
		}
		cout << endl;
	}
	else {
		cout << "Sorry, unable to connect!" << endl;
		delete res;
		session.Close();
		return 1;
	}

	delete res;
	session.Close();
	return 0;
}