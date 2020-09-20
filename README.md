Project using windows azure sdk for c++ testing basic cloud functionalities</br>

Recruitment task for Acaisoft</br>
Tested on Ubuntu OS </br>
Dependencies: https://github.com/Azure/azure-storage-cpp/ and cpprestsdk as mentioned</br>


Before usage followed settings in main.cpp must be changeds to Your , especially AzureAccountKey</br>

string AzureStorage::m_AzureAccountName = "pwisniewski";</br>
string AzureStorage::m_AzureAccountKey = "secret_keyXXX";</br>
string AzureStorage::m_AzureContainer = "pwisniewskiblobcontainer5";</br>
string AzureStorage::m_AzureTable = "MySampleTable793";</br>
Usage:</br>

    1) cmake . -DWAS_PATH=[path to azure-storage-cpp sdk] for example cmake . -WAS_PATH=/home/user/azure-storage-cpp/   azure-storage-cpp/Microsoft.WindowsAzure.Storage</br>

    2) make .</br>

    3)./azure_Sample [--logs] |  [--add path to file] | [--remove file]</br>

