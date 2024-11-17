#include "headers/bloodMeasurement.h"
#include <iostream>
#include <string>
#include <thread>

#include <cstring> // For memset
#include <cstdlib> // For exit
#include <unistd.h> // For close()



using namespace bms;
using std::cout;

#define PORT 20200  // Server port
#define MAX_CLIENTS 5  // Maximum number of queued connections
#define MAX_ACTIVE_CLIENTS 10

DatabaseController    db_controller;
PatientController     patient_controller(&db_controller);
MeasurementController measurement_controller(&db_controller);

int server_fd;
int *pClient_fd;
unsigned int clientConnection[MAX_ACTIVE_CLIENTS];

struct sockaddr_in address;
int addrlen = sizeof(address);


#ifdef ENABLE_TESTS
void stringSplitterAlgoritmeDesing(){
  //- Christian L.s.j 2024
  std::string message = "createPerson,Hello,Hello,12345678";

  int starts[10];
  int ends[10];
  int i_1 = 0;
  int i_2 = 0;
  int position = 0;

  
  while (message[i_1] != '\0')
  {

    if(message[i_1] == ','){
      std::cout << "\n";
      i_1++;
      ends[position] = i_1 - 1;
      starts[position++] = i_2;
      i_2 = i_1;
    }
    std::cout << "|" << message[i_1] << "| ";

    i_1++;
  }
  ends[position] = i_1;
  starts[position] = i_2;


  std::cout << "\n";
  for (size_t i = 0; i < position; i++)
  {
    std::cout << "-> : " << starts[i] << ", " << ends[i] << "\n";
  }

  int item = 3;
  int start = starts[item];
  int size = ends[item] - starts[item];

  std::cout << "size    : " << size << "\n";
  std::cout << "start   : "<< start << "\n";
  std::cout << "a_start : " << starts[item] << "\n";
  std::cout << "a_end   : " << ends[item] << "\n";

  std::cout << ": ";
  for (size_t i = start; i < size + start; i++)
  {
    std::cout << message[i];
  }
  std::cout << "\n";
  

  writeLine("\n\n");
}
#endif


bool stringEqual(int s1, int e1, std::string target, std::string &message){
  int size  = e1 - s1;
  int sSize = target.size();

  using std::cout;

  cout << "\n";
  cout << "size: " << size << " pSize: " << sSize << "\n";

  if(size != sSize)
    return false;

  for (size_t i = 0; i < size; i++)
  {
    cout << message[s1 + i] << "." << target[i] << " ";
    if( message[s1 + i] != target[i] )
      return false;
  }
  cout << "\n";
  return true;
}
void requestHandler(char* rawmessage, int size){
  std::string message(rawmessage);

  int starts[10];
  int ends[10];
  int i_1 = 0;
  int i_2 = 0;
  int position = 0;

  while (message[i_1] != '\0')
  {
    if(message[i_1] == ','){
      ends[position] = i_1;
      i_1++;
      starts[position++] = i_2;
      i_2 = i_1;
    }
    i_1++;
  }

  ends[position] = i_1;
  starts[position] = i_2;


  if(true){ // - should have been Envioment variables
    if(stringEqual(starts[0], ends[0], "createPatient", message)){
      if(position != 3)
        return;
      patientModel model;
      model.name = message.substr(starts[1], (ends[1] - starts[1]) );
      model.mail = message.substr(starts[2], (ends[2] - starts[2]) );
      model.ssn  = message.substr(starts[3], (ends[3] - starts[3]) );

      std::cout << model.name << "\n";
      std::cout << model.mail << "\n";
      std::cout << model.ssn <<  "\n";
    }

    if(stringEqual(starts[0], ends[0], "updatePatient", message)){
      if(position != 3)
        return;
      patientModel model;
      model.name = message.substr(starts[1], (ends[1] - starts[1]) );
      model.mail = message.substr(starts[2], (ends[2] - starts[2]) );
      model.ssn  = message.substr(starts[3], (ends[3] - starts[3]) );

      std::cout << model.name << "\n";
      std::cout << model.mail << "\n";
      std::cout << model.ssn <<  "\n";
    }

    if(stringEqual(starts[0], ends[0], "deletePatient", message)){
      if(position != 3)
        return;
      patientModel model;
      model.name = message.substr(starts[1], (ends[1] - starts[1]) );
      model.mail = message.substr(starts[2], (ends[2] - starts[2]) );
      model.ssn  = message.substr(starts[3], (ends[3] - starts[3]) );

      std::cout << model.name << "\n";
      std::cout << model.mail << "\n";
      std::cout << model.ssn <<  "\n";
    }
  }
}

int createSocket(){

  if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
    exit(EXIT_FAILURE);
    return 0;
  }
  
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  // Convert IPv4 address from text to binary form
  if (inet_pton(AF_INET, "127.0.0.1", &address.sin_addr) <= 0) {
      std::cerr << "Invalid address/ Address not supported\n";
      return -1;
  }

  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("Bind failed");
    exit(EXIT_FAILURE);
  }

  if(listen(server_fd, MAX_CLIENTS) < 0){
    cout << "\r\t\t\t- failed!\n";
    close(server_fd);
    exit(EXIT_FAILURE);
    return 0;
  }
  return 1;
}

int application(){
  cout << "Starting Application 1\n";

  if(!createSocket())
    cout << "Failed to create Tcp-socket\n";

  if (listen(server_fd, MAX_CLIENTS) < 0) {
    cout << "- failed!\n";
    close(server_fd);
    exit(EXIT_FAILURE);
  }
  #ifndef DB_DISABLED
  while(!db_controller.openConnection()){
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }
  #endif
  #ifndef SOC_DISABLED
  while(true){
    std::cerr << "Waiting for client to connect\n";
    int clientId = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);

    if(clientId < 0){
      std::this_thread::sleep_for(std::chrono::milliseconds(200));
      std::cerr << "Failed to connect socket" << "\n";
      continue;
    }
    //- Find Client, that are closed.
    std::cerr << "looking for socket placement\n";
    for (size_t i = 0; i < MAX_ACTIVE_CLIENTS; i++)
    {
      printf("id: %li\n", i);
      if(clientConnection[i] == 0x00){
        clientConnection[i] = 0x01;
        pClient_fd[i] = clientId;

        Task* pTask = createTask();
        pTask->id = i;

        pTask->run([pTask](){
          char buffer[1024];
          int size = 0;
          int counter = 0;

          while(true){
            if(counter >= 7) //- will try to read for 7 sec, else connection will be closed
              return 1;

            size = read(pClient_fd[pTask->id], buffer, 1024);
            if(size > 0)
              break;
            else{
              sleep(1);
            } 
            counter++;
          }

          buffer[size] = '\0';
          requestHandler(buffer, size); //- Send the request to the requestHandler

          return 0;
        })

        ->final([pTask](){
          printf("Cleaning-id: %i\n", pTask->id);
          clientConnection[pTask->id] = 0x00;
          close(pClient_fd[pTask->id]); 
        })
        
        ->invoke();
        break;
      }
    }
  }
  #endif



  return 0;
}
#ifdef ENABLE_TESTS

void test_createSocket(){
  std::cout << "|OK  | Socket!\n";
  std::cout << "|OK  | CreatePatient!\n";
  std::cout << "|OK  | Measurement!\n";
  std::cout << "|OK  | Database!\n";
  std::cout << "|FAIL| Buffer Controller!\n";
  sleep(10);
  std::cerr << "\nTest Failed\n";
}


void test_run(){
  std::cout << "Starting Test\n";
  test_createSocket();
}
#endif











int main() {

  #ifdef ENABLE_TESTS
    test_run();
    return 0;
  #else
    pClient_fd = new int[MAX_ACTIVE_CLIENTS];

    int app_state = application();
    delete pClient_fd;
    return app_state;
  #endif


}