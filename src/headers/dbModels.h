#pragma once
#include <iostream>
#include <cstring>

namespace bms
{
  /// @brief Patient model, used to store the data into the database
  struct patientModel
  {
    std::string ssn;
    std::string mail;
    std::string name;
  };
  /// @brief Measurement model, used to store the data into the databse
  struct measurementModel
  {
    unsigned int id;
    std::string ssn;
    std::string date;

    unsigned int systolic;
    unsigned int diastolic;
    unsigned char seen;
  };
  struct queryModel
  {
    const char* quarystring;
    const char* table;
    const char* value;
  };




  #define char_map_size 10
  /*
    * Json element, are created to Read Json files, from the web_server.
      The plan is to create something that can read the request and parse
      it to the database. 

      This way i can simulate the flow of the application without, creating the
      web-server. and still keep it realistic. 



      Christian .j
    * 
   */
  class JsonElement{
    public:
    JsonElement(const char* data){
      json = data;

    }


    struct Attribute
    {
      int grp_id;       //- Indent
      int grp_element;  //- Element
      char key[255];    //- Id key for Element
      char value[255];
    };





    void handleRawData(){
      attributeSize = seekLength();
      pAttributes = new Attribute[attributeSize];

      printf("\nDone!");
    }



    int seekLength()
    {
      int length = 0;
      int position = 0;

      int state = 0;


      while(json[position] != '\0'){
        switch (json[position])
        {
        case '"':
          if(state == 0){
            length++;
            state = 1;
          }
          break;

        case '\n':
          state = 0;
          break;
        
        default:
          break;
        }



        position++; //- move to next char

      }
      
      printf("EOF");
      printf("%i", length);

      return length;
    }
    int seekChar(int &i, const char c){
      return -1;
    } 
    bool validChar(const char &c){
      return c != ' ' || c != '\r' || c!='\t';
    }



    Attribute *pAttributes;
    int attributeSize = 0;
    const char *json;
  };



}
