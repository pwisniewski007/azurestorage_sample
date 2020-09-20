
#include "AzureStorage.h"

string AzureStorage::m_AzureAccountName = "pwisniewski";
string AzureStorage::m_AzureAccountKey = "secret_keyXXX";
string AzureStorage::m_AzureContainer = "pwisniewskiblobcontainer5";
string AzureStorage::m_AzureTable = "MySampleTable793";
int main(int argc, char** argv)
{
      if(argc == 2 || argc==3 )
    {  

        AzureStorage azureStorage(argc,argv);
        azureStorage.play();
       
        
    }
  
   
}