/*********************************************************************
 *
 * unixODBC Cursor Library
 *
 * Created by Nick Gorham
 * (nick@lurcher.org).
 *
 * copyright (c) 1999 Nick Gorham
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 **********************************************************************
 *
 * $Id: SQLForeignKeys.c,v 1.2 2009/02/18 17:59:17 lurcher Exp $
 *
 * $Log: SQLForeignKeys.c,v $
 * Revision 1.2  2009/02/18 17:59:17  lurcher
 * Shift to using config.h, the compile lines were making it hard to spot warnings
 *
 * Revision 1.1.1.1  2001/10/17 16:40:15  lurcher
 *
 * First upload to SourceForge
 *
 * Revision 1.1.1.1  2000/09/04 16:42:52  nick
 * Imported Sources
 *
 * Revision 1.2  1999/09/23 21:46:37  ngorham
 *
 * Added cursor support for metadata functions
 *
 * Revision 1.1  1999/09/19 22:22:50  ngorham
 *
 *
 * Added first cursor library work, read only at the moment and only works
 * with selects with no where clause
 *
 *
 **********************************************************************/

#include <config.h>
#include "cursorlibrary.h"

SQLRETURN CLForeignKeys(
    SQLHSTMT           statement_handle,
    SQLCHAR            *szpk_catalog_name,
    SQLSMALLINT        cbpk_catalog_name,
    SQLCHAR            *szpk_schema_name,
    SQLSMALLINT        cbpk_schema_name,
    SQLCHAR            *szpk_table_name,
    SQLSMALLINT        cbpk_table_name,
    SQLCHAR            *szfk_catalog_name,
    SQLSMALLINT        cbfk_catalog_name,
    SQLCHAR            *szfk_schema_name,
    SQLSMALLINT        cbfk_schema_name,
    SQLCHAR            *szfk_table_name,
    SQLSMALLINT        cbfk_table_name )
{
    CLHSTMT cl_statement = (CLHSTMT) statement_handle;
    SQLRETURN ret;

    ret = SQLFOREIGNKEYS( cl_statement -> cl_connection,
            cl_statement -> driver_stmt,
            szpk_catalog_name,
            cbpk_catalog_name,
            szpk_schema_name,
            cbpk_schema_name,
            szpk_table_name,
            cbpk_table_name,
            szfk_catalog_name,
            cbfk_catalog_name,
            szfk_schema_name,
            cbfk_schema_name,
            szfk_table_name,
            cbfk_table_name );

    if ( SQL_SUCCEEDED( ret ))
    {
        SQLSMALLINT column_count;

        ret = SQLNUMRESULTCOLS( cl_statement -> cl_connection,
           cl_statement -> driver_stmt,
           &column_count );

        cl_statement -> column_count = column_count;
        cl_statement -> first_fetch_done = 0;
        cl_statement -> not_from_select = 1;

        if ( column_count > 0 )
        {
            ret = get_column_names( cl_statement );
        }
    }
    return ret;
}
