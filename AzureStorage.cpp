#include "AzureStorage.h"

AzureStorage::AzureStorage(int argc,char** argv) 
{
    if(argc == 3)
    {
        m_Commands[argv[1]] = argv[2];
        if((m_Commands.find("--add") != m_Commands.end()))
        {
            
            m_Command = new AzureStorageCommandAdd(container,Table,m_Commands["--add"]);
        }
        else if(m_Commands.find("--remove") != m_Commands.end())
        {
            m_Command = new AzureStorageCommandRemove(container,Table,m_Commands["--remove"]);
        }
    }
    else
    {
        m_Commands[argv[1]] = "";
        if(m_Commands.find("--logs") != m_Commands.end())
        {
            m_Command = new AzureStorageCommandLog(container,Table);
        }
    }
    
    
}
void AzureStorage::Connect()
{
    try{
        // Initialize storage account
            const utility::string_t m_ConnectionString(_XPLATSTR("DefaultEndpointsProtocol=https;AccountName=")+AzureStorage::m_AzureAccountName+_XPLATSTR(";AccountKey=")+AzureStorage::m_AzureAccountKey+_XPLATSTR(";EndpointSuffix=core.windows.net"));
        azure::storage::cloud_storage_account storage_account = azure::storage::cloud_storage_account::parse(m_ConnectionString);
                    // Create a blob container
        azure::storage::cloud_blob_client blob_client = storage_account.create_cloud_blob_client();
        container = blob_client.get_container_reference(AzureStorage::m_AzureContainer);
    
        // Return value is true if the container did not exist and was successfully created.
        container.create_if_not_exists();    
        // Create a table
        azure::storage::cloud_table_client table_client = storage_account.create_cloud_table_client();
        this->Table = table_client.get_table_reference(AzureStorage::m_AzureTable);
        this->Table.create_if_not_exists();

        
    }catch(const azure::storage::storage_exception& e)
    {
        ucout << _XPLATSTR("Error: ") << e.what() << std::endl;

        azure::storage::request_result result = e.result();
        azure::storage::storage_extended_error extended_error = result.extended_error();
        if (!extended_error.message().empty())
        {
            ucout << extended_error.message() << std::endl;
        }
    }
    
}
void AzureStorage::play()
{
    this->Connect();
    if(this->m_Command != nullptr)
    {     
        this->m_Command->play();
    }
}

