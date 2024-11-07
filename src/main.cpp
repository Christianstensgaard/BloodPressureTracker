#include <stdio.h>

#define CONNECTIONSTRING "DO_SOME_CONNECTON";

void openConnectionToDb(){
  const char* connectionString = CONNECTIONSTRING;
  printf("connecting to database!\n");

}

void openConnectionToSocket(){
  printf("Connecting to Websocket!\n");


}

int main(int argc, char const *argv[])
{
  printf("Hello from main!\n");
  openConnectionToDb();
  openConnectionToSocket();


  printf("Closing Application!\n");
  return 0;
}
