#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include<windows.h>
#include<comdef.h>
#include <sqlext.h>
#include <sqltypes.h>
#include<fstream>
#include <sql.h>

#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

#pragma warning(disable:4996) 
using namespace std;
using namespace cgicc;
void showSQLError(unsigned int handleType, const SQLHANDLE& handle)

{

	SQLCHAR SQLState[1024];

	SQLCHAR message[1024];

	if (SQL_SUCCESS == SQLGetDiagRec(handleType, handle, 1, SQLState, NULL, message, 1024, NULL))

		// Returns the current values of multiple fields of a diagnostic record that contains error, warning, and status information

		cout << "SQL driver message: " << message << "\nSQL state: " << SQLState << "." << endl;

}

void checkSQL(string SQLQuery)

{

	SQLHANDLE SQLEnvHandle = NULL;

	SQLHANDLE SQLConnectionHandle = NULL;

	SQLHANDLE SQLStatementHandle = NULL;

	SQLRETURN retCode = 0;

	do {

		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvHandle))

			// Allocates the environment

			break;



		if (SQL_SUCCESS != SQLSetEnvAttr(SQLEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))

			// Sets attributes that govern aspects of environments

			break;



		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvHandle, &SQLConnectionHandle))

			// Allocates the connection

			break;



		if (SQL_SUCCESS != SQLSetConnectAttr(SQLConnectionHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0))

			// Sets attributes that govern aspects of connections

			break;



		SQLCHAR retConString[1024]; // Conection string

		switch (SQLDriverConnect(SQLConnectionHandle, NULL,

			(SQLCHAR*)"DRIVER={SQL Server}; SERVER=LAPTOP-MDD37LR0; DATABASE=sms;Trusted=true;",

			SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT)) {

			// Establishes connections to a driver and a data source

		case SQL_SUCCESS:

			break;

		case SQL_SUCCESS_WITH_INFO:

			break;

		case SQL_NO_DATA_FOUND:

			showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);

			retCode = -1;

			break;

		case SQL_INVALID_HANDLE:

			showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);

			retCode = -1;

			break;

		case SQL_ERROR:

			showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);

			retCode = -1;

			break;

		default:

			break;

		}



		if (retCode == -1)

			break;



		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, SQLConnectionHandle, &SQLStatementHandle))

			// Allocates the statement

			break;



		if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery.std::string::c_str(), SQL_NTS))
		{

			// Executes a preparable statement
			cout << "Entry Failed \n";
			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);

			break;

		}

		else
		{

			cout << "Entry Success \n";

		}

	} while (FALSE);
	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);

	SQLDisconnect(SQLConnectionHandle);

	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);

	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);

	// Frees the resources and disconnects

}

int main()
{

	Cgicc cgi;

	// Send HTTP header
	cout << HTTPHTMLHeader() << endl;

	// Set up the HTML document
	cout << html() << head(title("cgicc example")) << endl;
	cout << body() << endl;
	form_iterator id = cgi.getElement("std_id");
	form_iterator m = cgi.getElement("maths");
	form_iterator s = cgi.getElement("sci");
	form_iterator e = cgi.getElement("eng");

	//char SQLQuery1[2000] = "SELECT * FROM reg_table;";
	
	/*string SQLQuery2 = "DELETE FROM marks_table where login_id='";
	SQLQuery2 = SQLQuery2 + **id;
	SQLQuery2 = SQLQuery2 + "';";
	checkSQL(SQLQuery2);
	char c1[] = "');";
	char c[] = "','";*/

	string SQLQuery1 = "UPDATE marks_table SET Login_ID='";

	SQLQuery1 = SQLQuery1 + **id;

	SQLQuery1 = SQLQuery1 + "',Maths ='";

	SQLQuery1 = SQLQuery1 + **m;

	SQLQuery1 = SQLQuery1 + "',Science='";

	SQLQuery1 = SQLQuery1 + **s;

	SQLQuery1 = SQLQuery1 + "',English='";

	SQLQuery1 = SQLQuery1 + **e;

	SQLQuery1 = SQLQuery1 + "'";

	SQLQuery1 = SQLQuery1 + "WHERE Login_ID='";

	SQLQuery1 = SQLQuery1 + **id;

	SQLQuery1 = SQLQuery1 + "';";

	checkSQL(SQLQuery1);

	system("PAUSE");
	return 0;

}
