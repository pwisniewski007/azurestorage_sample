Project using windows azure sdk for c++ testing basic cloud functionalities
Recruitment task for Acaisoft
Tested on Ubuntu OS 
Dependencies: https://github.com/Azure/azure-storage-cpp/ and cpprestsdk as mentioned


Before usage followed settings in main.cpp must be changeds to Your , especially AzureAccountKey

string AzureStorage::m_AzureAccountName = "pwisniewski";
string AzureStorage::m_AzureAccountKey = "secret_keyXXX";
string AzureStorage::m_AzureContainer = "pwisniewskiblobcontainer5";
string AzureStorage::m_AzureTable = "MySampleTable793";
Usage:
    1) cmake . -DWAS_PATH=[path to azure-storage-cpp sdk] for example cmake . -WAS_PATH=/home/user/azure-storage-cpp/    azure-storage-cpp/Microsoft.WindowsAzure.Storage

    2) make .

    3)./azure_Sample [--logs] |  [--add path to file] | [--remove file]
# azure sample task
