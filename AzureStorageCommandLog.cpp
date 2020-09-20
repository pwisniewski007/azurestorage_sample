#include "AzureStorage.h"
void AzureStorageCommandLog::play()
{
    try{
        azure::storage::table_query query;
            
        azure::storage::table_query_iterator it = m_Table.execute_query(query);
        azure::storage::table_query_iterator endOfResults;
        for( ; it !=endOfResults;++it)
        {     
            const azure::storage::table_entity::properties_type& properties = it->properties();
            
            ucout << endl<<_XPLATSTR("filename: ") << properties.at(_XPLATSTR("filename")).string_value();
            ucout << properties.at(_XPLATSTR("operation")).string_value()<<endl;
        }
            
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