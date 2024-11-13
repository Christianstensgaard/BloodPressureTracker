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


//- TODO Finish this, for the controller class, to remove code dubli... 
std::unique_ptr<sql::ResultSet> bms::DatabaseController::executeQuery(const std::string& query) {
    if (getConnection() == nullptr) {
        std::cerr << "Connection is null!" << std::endl;
        return nullptr;
    }

    try {
        std::unique_ptr<sql::PreparedStatement> pstmt(getConnection()->prepareStatement(query));
        return std::unique_ptr<sql::ResultSet>(pstmt->executeQuery());
    } catch (const sql::SQLException& e) {
        std::cerr << "Error executing query: " << e.what() << std::endl;
        return nullptr;
    }
}

void bms::DatabaseController::openConnection() {
  printf("Opnen Connection!");
    try {
        driver = sql::mysql::get_mysql_driver_instance();
        connection = std::shared_ptr<sql::Connection>(
            driver->connect("tcp://127.0.0.1:3306", "root", "my-secret-pw")
        );

      connection->setSchema("bm_db");


    } catch (const sql::SQLException& e) {
        std::cerr << "Error opening connection: " << e.what() << '\n';
    }
}

std::shared_ptr<sql::Connection> bms::DatabaseController::getConnection() {
  return connection;
}