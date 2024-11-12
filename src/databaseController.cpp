#include "headers/databaseController.h"

bms::DatabaseController::DatabaseController()
{
  printf("DatabaseControllerInstance()");
  driver = nullptr;
  connection = nullptr;
}

bms::DatabaseController::~DatabaseController()
{
  printf("DatabaseController() Destroyed");
  
}

void bms::DatabaseController::openConnection() {
  printf("Opnen Connection!");
    try {
        driver = sql::mysql::get_mysql_driver_instance();
        connection = std::shared_ptr<sql::Connection>(
            driver->connect("tcp://127.0.0.1:3306", "root", "my-secret-pw")
        );
    } catch (const sql::SQLException& e) {
        std::cerr << "Error opening connection: " << e.what() << '\n';
    }
}

std::shared_ptr<sql::Connection> bms::DatabaseController::getConnection() {
  return connection;
}