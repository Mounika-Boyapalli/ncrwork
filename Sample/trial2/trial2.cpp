#include "pch.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
//#include<sstream>

#pragma warning(disable:4996) 
using namespace std;
void showSQLError(unsigned int handleType, const SQLHANDLE& handle)

{

	SQLCHAR SQLState[1024];

	SQLCHAR message[1024];

	if (SQL_SUCCESS == SQLGetDiagRec(handleType, handle, 1, SQLState, NULL, message, 1024, NULL))

		// Returns the current values of multiple fields of a diagnostic record that contains error, warning, and status information

		cout << "SQL driver message: " << message << "\nSQL state: " << SQLState << "." << endl;

}

void checkSQL(char* SQLQuery, char* passwo, char* login_i)

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

			(SQLCHAR*)"DRIVER={SQL Server}; SERVER=LAPTOP-MDD37LR0; DATABASE=trial;Trusted=true;",

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



		if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery, SQL_NTS))
		{

			// Executes a preparable statement

			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);

			break;

		}

		else
		{

			/*char name1[256];
			char name2[256];
			char name3[256];*/

			//while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS)
			//{

			//	SQLGetData(SQLStatementHandle, 1, SQL_C_DEFAULT, &name1, sizeof(name1), NULL);
			//	SQLGetData(SQLStatementHandle, 2, SQL_C_DEFAULT, &name2, sizeof(name2), NULL);
			//	SQLGetData(SQLStatementHandle, 3, SQL_C_DEFAULT, &name3, sizeof(name3), NULL);

			//	cout << name1 << " " << name2 << " " << name3 << endl;

			//	// Retrieves data for a single column in the result set
			//}
			char pas[128];
			char log[128];
			int flag = 1;
			while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS)
			{
				SQLGetData(SQLStatementHandle, 2, SQL_CHAR, &log, sizeof(log), NULL);
				SQLGetData(SQLStatementHandle, 3, SQL_CHAR, &pas, sizeof(pas), NULL);

				if (!strcmp(log,login_i))
				{

					if (!strcmp(pas, passwo) && pas != NULL)
					{
						flag = 0;
						//std::cout << " \n correct!" << endl;
					}
					else
					{
						//std::cout << "\n wrong" << endl;
					}
					continue;
				}
			}
			if (flag == 1)
			{
				cout << "wrong" << endl;
			}
			else
			{
				cout << "correct" << endl;
			}
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

	//char name[512];
	//char mail[512];
	//char fn[512];

	//cout << "Enter the details" << endl << "Enter your name" << endl;
	//cin >> name;
	//cout << "Enter your mail id" << endl;
	//cin >> mail;
	//cout << "Enter your father's name" << endl;
	//cin >> fn;

	////char SQLQuery1[2000] = "SELECT * FROM reg_table;";

	//char SQLQuery1[2000] = "INSERT INTO reg_table VALUES('";

	//strcat(SQLQuery1, name);

	//char c[] = "','";

	//strcat(SQLQuery1, c);

	//strcat(SQLQuery1, mail);

	//strcat(SQLQuery1, c);

	//strcat(SQLQuery1, fn);

	//char c1[] = "');";

	//strcat(SQLQuery1, c1);

	//checkSQL(SQLQuery1);

	//char SQLQuery2[] = "select * from reg_table;";

	//checkSQL(SQLQuery2);

	char login_i[100];
	char passwo[100];
	cout << "Enter the login_id and password: " << endl;
	cin >> login_i;
	cin >> passwo;

	char SQLQuery1[2000] = "select * from login_table where password='";
	strcat(SQLQuery1, passwo);
	char c[] = "';";
	strcat(SQLQuery1, c);
	  
	char cross[2000] = "select * from login_table where login_id='";
	strcat(cross, login_i);
	strcat(cross, c);

	checkSQL(SQLQuery1,passwo,login_i);

	system("PAUSE");
	return 0;
}