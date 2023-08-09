#include "admin.h"
#include "mysql.h"
#include <iostream>

admin::admin() = default;

bool admin::customer_login(const string& _username, const string& _password) {
    bool login_status = false;
    MYSQL* conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    const char *host = "localhost";
    const char *user = "root";
    const char *pass = "dreamment";
    const char *db = "hotel_management_system";
    const int port = 3306;
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
            string query = "SELECT * FROM customer WHERE username = '" + _username + "'";
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
    const char *host = "localhost";
    const char *user = "root";
    const char *pass = "dreamment";
    const char *db = "hotel_management_system";
    const int port = 3306;
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