#pragma once

#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>


namespace bms{
  class DatabaseController{
    public:
    DatabaseController();
    ~DatabaseController();



    void openConnection();
    


    private:
    sql::mysql::MySQL_Driver* driver;
    std::unique_ptr<sql::Connection> connection;
  };
}