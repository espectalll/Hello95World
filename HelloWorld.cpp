#include <stdio.h>
#include <afxinet.h>

int main() {
	printf("Establishing connection...\n");

	LPCTSTR ip= "10.0.2.2";
	INTERNET_PORT port = 8080;
	LPCTSTR path="/";

	CInternetSession session("My Session");
	CHttpConnection* connection = session.GetHttpConnection(
		ip, port);
	CHttpFile* res = connection->OpenRequest(
		( LPCTSTR ) "GET", path);
	CHAR buff[1024];
	if (res->SendRequest()) {
		res->Read(buff, 1024);
		printf("%1023s\n", buff);
	}
	else {
		printf("Sorry, unable to connect!");
		delete res;
		session.Close();
		return 1;
	}

	delete res;
	session.Close();
	return 0;
}