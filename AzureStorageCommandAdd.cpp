#include "AzureStorage.h"
void AzureStorageCommandAdd:: play()
{
    
    try{
        // Upload a blob from a file
        string FileName=m_FilePath.substr(m_FilePath.find_last_of("/\\") + 1);
        concurrency::streams::istream input_stream = concurrency::streams::file_stream<uint8_t>::open_istream(_XPLATSTR(m_FilePath)).get();
        azure::storage::cloud_block_blob blob1 = m_Container.get_block_blob_reference(_XPLATSTR( FileName));
        blob1.upload_from_stream(input_stream);
        input_stream.close().wait();

        ostringstream strim;
        strim<<time(0);
        string Date = strim.str();
        azure::storage::table_entity entity(_XPLATSTR("date"), _XPLATSTR(Date));
        azure::storage::table_entity::properties_type& properties = entity.properties();
        properties.reserve(2);
        
        properties[U("filename")] = azure::storage::entity_property(FileName);
        properties[U("operation")] = azure::storage::entity_property(U("--add"));
        azure::storage::table_operation insert_operation = azure::storage::table_operation::insert_entity(entity);
        
        m_Table.execute(insert_operation);

        ucout<<"file added "<<FileName;
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