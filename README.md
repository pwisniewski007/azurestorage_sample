Project using windows azure sdk for c++ testing basic cloud functionalities\r\n

Recruitment task for Acaisoft\r\n
Tested on Ubuntu OS \r\n
Dependencies: https://github.com/Azure/azure-storage-cpp/ and cpprestsdk as mentioned\r\n


Before usage followed settings in main.cpp must be changeds to Your , especially AzureAccountKey\r\n

string AzureStorage::m_AzureAccountName = "pwisniewski";</br>
string AzureStorage::m_AzureAccountKey = "secret_keyXXX";\r\n
string AzureStorage::m_AzureContainer = "pwisniewskiblobcontainer5";\r\n
string AzureStorage::m_AzureTable = "MySampleTable793";\r\n
Usage:\r\n
    1) cmake . -DWAS_PATH=[path to azure-storage-cpp sdk] for example cmake . -WAS_PATH=/home/user/azure-storage-cpp/   \r\n azure-storage-cpp/Microsoft.WindowsAzure.Storage\r\n

    2) make .\r\n

    3)./azure_Sample [--logs] |  [--add path to file] | [--remove file]\r\n
# azure sample task
