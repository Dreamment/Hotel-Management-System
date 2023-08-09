#ifndef HOTEL_MANAGEMENT_SYSTEM_LOGIN_H
#define HOTEL_MANAGEMENT_SYSTEM_LOGIN_H

#include <string>

using namespace std;

class admin {
private:
    string username;
    string password;
    string passwordAgain;
    string email;
    string phone;
    const char *host = "localhost";
    const char *user = "root";
    const char *pass = "dreamment";
    const char *db = "hotel_management_system";
    const int port = 3306;
public:
    explicit admin();
    bool customer_login(const string& _username, const string& _password);
    bool manager_login(const string& _username, const string& _password);
    bool customer_register(const string& _username, const string& _password, const string & _passwordAgain,
                           const string& _email, const string& _phone, const string& _name, const string& _surname);
    bool manager_register(const string& _username, const string& _password, const string & _passwordAgain,
                          const string& _email, const string& _phone, const string& _name, const string& _surname);

};


#endif
