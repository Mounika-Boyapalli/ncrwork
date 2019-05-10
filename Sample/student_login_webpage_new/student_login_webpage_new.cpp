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
void checkSQL1(string SQLQuery, string login_i)

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

			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);

			break;

		}

		else
		{

			char math[10];
			char sci[10];
			char eng[10];
			while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS) 
			{
				SQLGetData(SQLStatementHandle, 2, SQL_CHAR, &math, sizeof(math), NULL);
				SQLGetData(SQLStatementHandle, 3, SQL_CHAR, &sci, sizeof(sci), NULL);
				SQLGetData(SQLStatementHandle, 4, SQL_CHAR, &eng, sizeof(eng), NULL);	

				//cout << math << sci << eng;

				string m(math);
				string s(sci);
				string e(eng);
				
				cout << "<!DOCTYPE html><html>";
				cout << "<script type=\"text/javascript\">function tableHide(){document.getElementById(\"table\").style.display=\"none\";}function tableShow(){document.getElementById(\"table\").style.display=\"block\";document.getElementById(\"hr\").style.display=\"block\";}</script>";
				cout << "<body><h2 id=\"hr\" hidden>Marks Table</h2><style>table, th, td { border: 1px solid black; }</style><table id=\"table\" style=\"width:100%\" hidden><tr><th>Student ID</th><th>Maths</th><th>Science</th> <th>English</th></tr><tr>";
				cout << "<td>" + login_i + "</td>";
				cout << "<td>" + m + "</td>";
				cout << "<td>" + s + "</td>";
				cout << "<td>" + e + "</td>";
				cout << "</tr></table><br>";
				//string html = part + part0 + part1 + x + part2 + part3 + part4 + part5;
				//cout << html;
				cout << "<p><center><button id=\"btn\" onclick=\"tableShow()\" type=\"submit\" ><font size=10>Click to get Marks</font></button></center></p> \n";
				cout << "</body>";
				cout << "</html>";
				//ofstream fileobj("C:\\Program Files (x86)\\Apache Software Foundation\\Apache2.2\\htdocs\\marks.html");
				//fileobj << html;
				//system("start chrome student.html")
				}
			}
	} while (FALSE);
	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);

	SQLDisconnect(SQLConnectionHandle);

	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);

	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);

	// Frees the resources and disconnects

}
void checkSQL(string SQLQuery, string passwo, string login_i)

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

			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);

			break;

		}

		else
		{

			char pas[128];
			char log[128];
			int flag = 1;
			while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS)
			{
				SQLGetData(SQLStatementHandle, 1, SQL_CHAR, &log, sizeof(log), NULL);
				SQLGetData(SQLStatementHandle, 2, SQL_CHAR, &pas, sizeof(pas), NULL);

				if (!strcmp(log, login_i.std::string::c_str()))
				{

					if (!strcmp(pas, passwo.std::string::c_str()) && pas != NULL)
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
				cout << "Failed! " << endl;
			}
			else
			{
				string query = "select * from marks_table where login_id= '" + login_i + "';";
				checkSQL1(query, login_i);
			}
		}

	} while (FALSE);
	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);

	SQLDisconnect(SQLConnectionHandle);

	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);

	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);

	// Frees the resources and disconnects

}

int main(int argc, char **argv)
{
	try {
		Cgicc cgi;

		// Send HTTP header
		cout << HTTPHTMLHeader() << endl;

		// Set up the HTML document
		cout << html() << head(title("cgicc example")) << endl;
		cout << body() << endl;

		// Print out the submitted element
		form_iterator uname = cgi.getElement("name");
		form_iterator pwd = cgi.getElement("pwd");

		string SQLQuery1 = "select * from login_table where password='";
		SQLQuery1 = SQLQuery1 + **pwd;
		SQLQuery1 = SQLQuery1 + "';";

		checkSQL(SQLQuery1, **pwd, **uname);

		// Close the HTML document
		cout << body() << html();

	}
	catch (exception& e)
	{
		// handle any errors - omitted for brevity
	}
}