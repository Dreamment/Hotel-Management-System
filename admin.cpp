#include "admin.h"
#include "mysql.h"
#include <iostream>

admin::admin(){
    MYSQL* conn;
    conn = mysql_init(nullptr);
    if (conn == nullptr){
        cout<<"\n\t\tMySQL initialization failed: " + string(mysql_error(conn));
    }
    else{
        conn = mysql_real_connect(conn, host, user, pass, nullptr, 0, nullptr, 0);
        if (conn == nullptr){
            string createDBQuery = "CREATE DATABASE IF NOT EXISTS ";
            createDBQuery += db;
            if (mysql_query(conn, createDBQuery.c_str())){
                cout<< "\n\t\tError while creating database: "<<mysql_error(conn);
            }
            mysql_close(conn);
        }
        else{
            cout<<"\n\t\tConnection Failed: " + string(mysql_error(conn));
        }
    }
}

bool admin::customer_login(const string& _username, const string& _password) {
    bool login_status = false;
    MYSQL* conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    conn = mysql_init(nullptr);
    if (conn == nullptr){
        throw invalid_argument("MySQL initialization failed: " + string(mysql_error(conn)));
    }
    else{
        conn = mysql_real_connect(conn, host, user, pass, db, port, nullptr, 0);
        if (conn == nullptr){
            throw invalid_argument("MySQL connection failed: " + string(mysql_error(conn)));
        }
        else{
            string query = "SELECT * FROM customers WHERE username = '" + _username + "'";
            const char* q = query.c_str();
            int qstate = mysql_query(conn, q);
            if (!qstate){
                res = mysql_store_result(conn);
                while (row = mysql_fetch_row(res)){
                    if (row[2] == _password){
                        login_status = true;
                    }
                }
            }
            else{
                throw invalid_argument("MySQL query failed: " + string(mysql_error(conn)));
            }
        }
    }
    mysql_free_result(res);
    mysql_close(conn);
    return login_status;
}

bool admin::manager_login(const string& _username, const string& _password) {
    bool login_status = false;
    MYSQL* conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    conn = mysql_init(nullptr);
    if (conn == nullptr){
        throw invalid_argument("MySQL initialization failed: " + string(mysql_error(conn)));
    }
    else{
        conn = mysql_real_connect(conn, host, user, pass, db, port, nullptr, 0);
        if (conn == nullptr){
            throw invalid_argument("MySQL connection failed: " + string(mysql_error(conn)));
        }
        else{
            string query = "SELECT * FROM managers WHERE username = '" + _username + "'";
            const char* q = query.c_str();
            int qstate = mysql_query(conn, q);
            if (!qstate){
                res = mysql_store_result(conn);
                while (row = mysql_fetch_row(res)){
                    if (row[2] == _password){
                        login_status = true;
                    }
                }
            }
            else{
                throw invalid_argument("MySQL query failed: " + string(mysql_error(conn)));
            }
        }
    }
    mysql_free_result(res);
    mysql_close(conn);
    return login_status;
}

bool admin::customer_register(const std::string &_username, const std::string &_password,
                              const std::string &_passwordAgain, const std::string &_email, const std::string &_phone,
                              const string& _name, const string& _surname) {
    bool register_status = false;
    MYSQL* conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    conn = mysql_init(nullptr);
    if (conn == nullptr){
        throw invalid_argument("MySQL initialization failed: " + string(mysql_error(conn)));
    }
    else {
        conn = mysql_real_connect(conn, host, user, pass, db, port, nullptr, 0);
        if (conn == nullptr){
            throw invalid_argument("MySQL connection failed: " + string(mysql_error(conn)));
        }
        else{
            string query = "SELECT * FROM customers WHERE username = '" + _username + "' OR email = '" + _email + "' OR phone = '" + _phone + "'";
            const char* q = query.c_str();
            int qstate = mysql_query(conn, q);
            if (!qstate){
                res = mysql_store_result(conn);
                while (row = mysql_fetch_row(res)){
                    if (row[1] == _username){
                        throw invalid_argument("Username already exists!");
                    }
                    else if (row[3] == _email){
                        throw invalid_argument("Email already exists!");
                    }
                    else if (row[4] == _phone){
                        throw invalid_argument("Phone already exists!");
                    }
                }
                if (_password == _passwordAgain){
                    query = "SELECT * FROM customers";
                    q = query.c_str();
                    qstate = mysql_query(conn, q);
                    if (!qstate){
                        res = mysql_store_result(conn);
                        int id = 0;
                        while (row = mysql_fetch_row(res)){
                            int temp = stoi(row[0]);
                            if (id + 1 != temp){
                                id++;
                                break;
                            }
                            else if (id + 1 == temp){
                                id++;
                                continue;
                            }
                        }
                        query = "INSERT INTO customers (id, username, password, email, phone, name, surname) VALUES "
                                "('" + to_string(id) + "', '" + _username + "', '" + _password + "', '" + _email
                                + "', '" + _phone + "', '" + _name + "', '" + _surname + "')";
                        q = query.c_str();
                        qstate = mysql_query(conn, q);
                        if (!qstate){
                            register_status = true;
                        }
                        else{
                            throw invalid_argument("MySQL query failed: " + string(mysql_error(conn)));
                        }
                    }
                    else{
                        throw invalid_argument("MySQL query failed: " + string(mysql_error(conn)));
                    }
                }
                else{
                    throw invalid_argument("Passwords do not match!");
                }
            }
            else{
                throw invalid_argument("MySQL query failed: " + string(mysql_error(conn)));
            }
        }
    }
    mysql_free_result(res);
    mysql_close(conn);
    return register_status;
}

bool admin::manager_register(const std::string &_username, const std::string &_password,
                             const std::string &_passwordAgain, const std::string &_email, const std::string &_phone,
                             const string& _name, const string& _surname) {
    bool register_status = false;
    MYSQL* conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    conn = mysql_init(nullptr);
    if (conn == nullptr){
        throw invalid_argument("MySQL initialization failed: " + string(mysql_error(conn)));
    }
    else {
        conn = mysql_real_connect(conn, host, user, pass, db, port, nullptr, 0);
        if (conn == nullptr){
            throw invalid_argument("MySQL connection failed: " + string(mysql_error(conn)));
        }
        else{
            string query = "SELECT * FROM managers WHERE username = '" + _username + "' OR email = '" + _email + "' OR phone = '" + _phone + "'";
            const char* q = query.c_str();
            int qstate = mysql_query(conn, q);
            if (!qstate){
                res = mysql_store_result(conn);
                while (row = mysql_fetch_row(res)){
                    if (row[1] == _username){
                        throw invalid_argument("Username already exists!");
                    }
                    else if (row[3] == _email){
                        throw invalid_argument("Email already exists!");
                    }
                    else if (row[4] == _phone){
                        throw invalid_argument("Phone already exists!");
                    }
                }
                if (_password == _passwordAgain){
                    query = "SELECT * FROM managers";
                    q = query.c_str();
                    qstate = mysql_query(conn, q);
                    if (!qstate){
                        res = mysql_store_result(conn);
                        int id = 0;
                        while (row = mysql_fetch_row(res)){
                            int temp = stoi(row[0]);
                            if (id + 1 != temp){
                                id++;
                                break;
                            }
                            else if (id + 1 == temp){
                                id++;
                                continue;
                            }
                        }
                        query = "INSERT INTO managers (id, username, password, email, phone, name, surname) VALUES "
                                "('" + to_string(id) + "', '" + _username + "', '" + _password + "', '" + _email +
                                "', '" + _phone + "', '" + _name + "', '" + _surname + "')";
                        q = query.c_str();
                        qstate = mysql_query(conn, q);
                        if (!qstate){
                            register_status = true;
                        }
                        else{
                            throw invalid_argument("MySQL query failed: " + string(mysql_error(conn)));
                        }
                    }
                    else{
                        throw invalid_argument("MySQL query failed: " + string(mysql_error(conn)));
                    }
                }
                else{
                    throw invalid_argument("Passwords do not match!");
                }
            }
            else{
                throw invalid_argument("MySQL query failed: " + string(mysql_error(conn)));
            }
        }
    }
    mysql_free_result(res);
    mysql_close(conn);
    return register_status;
}