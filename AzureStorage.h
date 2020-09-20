#ifndef _AZURE_STORAGE_
#define _AZURE_STORAGE_
#include<string>
#include<map>
#include <was/storage_account.h>
#include <was/storage_account.h>
#include <was/blob.h>
#include <cpprest/filestream.h>
#include "was/common.h"
#include <cpprest/containerstream.h>
#include<iostream>
#include<map>
#include<string>
#include<memory>
#include <was/table.h>
#include<sstream>
#include<chrono>
#include<sstream>
using namespace std;
#define U(X) _XPLATSTR(X)
using namespace std;
class AzureStorageCommand
{
     public:
        azure::storage::cloud_blob_container& m_Container;
         azure::storage::cloud_table& m_Table;
        AzureStorageCommand( azure::storage::cloud_blob_container& container, azure::storage::cloud_table& table) : m_Container(container),m_Table(table)
        {

        }
        virtual void play(){};
};
class AzureStorage{
    public:
        static string m_AzureAccountName;
        static string m_AzureAccountKey;
        static string m_AzureContainer;
        static string m_AzureTable;
        map<string,string>m_Commands;
        AzureStorageCommand* m_Command;
        azure::storage::cloud_blob_container container;
        azure::storage::cloud_table Table;
        AzureStorage(int argc,char** argv);
       
        void Connect();
        void play();
};
class AzureStorageCommandLog : public AzureStorageCommand
{
    public:
        AzureStorageCommandLog(azure::storage::cloud_blob_container& container, azure::storage::cloud_table& table) : AzureStorageCommand(container, table){}
        void play();
};
class AzureStorageCommandRemove : public AzureStorageCommand
{
    public:
        string m_File;
        AzureStorageCommandRemove(azure::storage::cloud_blob_container& container, azure::storage::cloud_table& table,string file) :AzureStorageCommand(container,table),m_File(file){}
        void play();
};
class AzureStorageCommandAdd : public AzureStorageCommand
{
    public:
        string m_FilePath;
        AzureStorageCommandAdd(azure::storage::cloud_blob_container& container, azure::storage::cloud_table& table,string file) :AzureStorageCommand(container,table),m_FilePath(file){}
        void play();
};

#endif
