#include "headers/databaseController.h"

bms::DatabaseController::DatabaseController()
{
}

bms::DatabaseController::~DatabaseController()
{
  
}

void bms::DatabaseController::openConnection()
{
  try
  {
    driver      = sql::mysql::get_mysql_driver_instance();
    connection  = std::unique_ptr<sql::Connection>(driver->connect("tcp://127.0.0.1:3306", "username", "password"));
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  
}