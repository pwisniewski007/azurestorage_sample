#include "AzureStorage.h"
void AzureStorageCommandRemove::play()
{
    try{
        
        
        azure::storage::cloud_block_blob blob1 = m_Container.get_block_blob_reference(_XPLATSTR(m_File));
        blob1.delete_blob();

        ostringstream strim;
        strim<<time(0);
        string Date = strim.str();
        // Insert a table entity
        azure::storage::table_entity entity(_XPLATSTR("date"), _XPLATSTR(Date));
        azure::storage::table_entity::properties_type& properties = entity.properties();
        properties.reserve(2);
        
        properties[U("filename")] = azure::storage::entity_property(m_File);
        properties[U("operation")] = azure::storage::entity_property(U("--remove"));
        azure::storage::table_operation insert_operation = azure::storage::table_operation::insert_entity(entity);
        
        m_Table.execute(insert_operation);
        ucout<<"file removed "<<m_File;
        
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
    catch (const std::exception& e)
    {
        ucout << _XPLATSTR("Error: ") << e.what() << std::endl;
    }
}