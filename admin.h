#ifndef HOTEL_MANAGEMENT_SYSTEM_LOGIN_H
#define HOTEL_MANAGEMENT_SYSTEM_LOGIN_H

#include <string>

using namespace std;

class admin {
private:
    string username;
    string password;
public:
    explicit admin();
    bool customer_login(const string& _username, const string& _password);
    bool manager_login(const string& _username, const string& _password);

};


#endif
