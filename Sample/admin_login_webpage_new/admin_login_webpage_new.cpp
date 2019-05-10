#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include<windows.h>
#include<comdef.h>
#include <sqlext.h>
#include <sqltypes.h>
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
void checkSQL2(string SQLQuery)

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

			char name[128];
			char email[128];
			char log[128];
			char add[128];
			char fath[128];
			cout << "<html>";
			cout << "<center><button onclick=\"tableShow2()\" id=\"det2\">Get Faculty Details<button></center>";
			cout << "<center><p><a href=\"http://localhost/edit_fac_details.html\"><font size=10>Edit Faculty details</font></a></p></center>";
			cout << "<center><p><a href=\"http://localhost/delete_faculty.html\"><font size=10>Delete Faculty details</font></a></p></center>";
			cout << "<center><p id=\"mydet2\" hidden>Details Table</p></center>";
			cout << "<script type=\"text/javascript\">function tableHide2(){document.getElementById(\"table2\").style.display=\"none\";}function tableShow2(){document.getElementById(\"table2\").style.display=\"block\";document.getElementById(\"mydet2\").style.display=\"block\";}</script>";
			cout << "<body><style>table, th, td { border: 1px solid black; width: 100%; padding: 8px; }</style><table id=\"table2\" style=\"width:100%\" hidden><tr><th> Faculty Name</th><th>Email</th><th>LoginID</th> <th>Address</th><th>Father Name</th></tr>";

			while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS)
			{
				SQLGetData(SQLStatementHandle, 1, SQL_CHAR, &name, sizeof(name), NULL);
				SQLGetData(SQLStatementHandle, 2, SQL_CHAR, &email, sizeof(email), NULL);
				SQLGetData(SQLStatementHandle, 3, SQL_CHAR, &log, sizeof(log), NULL);
				SQLGetData(SQLStatementHandle, 4, SQL_CHAR, &add, sizeof(add), NULL);
				SQLGetData(SQLStatementHandle, 5, SQL_CHAR, &fath, sizeof(fath), NULL);

				string n(name);
				string e(email);
				string l(log);
				string a(add);
				string f(fath);
				cout << "<tr>";
				cout << "<td>" + n + "</td>";
				cout << "<td>" + e + "</td>";
				cout << "<td>" + l + "</td>";
				cout << "<td>" + a + "</td>";
				cout << "<td>" + f + "</td>";
				cout << "</tr>";
				//cout << name << email << log << add << fath;
			}
			cout << "</table><br>";
			cout << "</body>";
			cout << "</html>";
		}

	} while (FALSE);
	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);

	SQLDisconnect(SQLConnectionHandle);

	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);

	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);

	// Frees the resources and disconnects

}
void checkSQL1(string SQLQuery)

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

			char name[128];
			char email[128];
			char log[128];
			char add[128];
			char fath[128];
			cout << "<html>";
			cout << "<center><button onclick=\"tableShow1()\" id=\"det1\">Get Student Details<button></center>";
			cout << "<center><p><a href=\"http://localhost/edit_student_reg.html\"><font size=10>Edit Student details</font></a></p></center>";
			cout << "<center><p><a href=\"http://localhost/delete_student.html\"><font size=10>Delete Student details</font></a></p></center>";
			cout << "<center><p id=\"mydet1\" hidden>Details Table</p></center>";
			cout << "<script type=\"text/javascript\">function tableHide1(){document.getElementById(\"table1\").style.display=\"none\";}function tableShow1(){document.getElementById(\"table1\").style.display=\"block\";document.getElementById(\"mydet1\").style.display=\"block\";}</script>";
			cout << "<body><style>table, th, td { border: 1px solid black; width: 100%; padding: 8px; }</style><table id=\"table1\" style=\"width:100%\" hidden><tr><th>Student Name</th><th>Email</th><th>LoginID</th> <th>Address</th><th>Father Name</th></tr>";

			while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS)
			{
				SQLGetData(SQLStatementHandle, 1, SQL_CHAR, &name, sizeof(name), NULL);
				SQLGetData(SQLStatementHandle, 2, SQL_CHAR, &email, sizeof(email), NULL);
				SQLGetData(SQLStatementHandle, 3, SQL_CHAR, &log, sizeof(log), NULL);
				SQLGetData(SQLStatementHandle, 4, SQL_CHAR, &add, sizeof(add), NULL);
				SQLGetData(SQLStatementHandle, 5, SQL_CHAR, &fath, sizeof(fath), NULL);

				string n(name);
				string e(email);
				string l(log);
				string a(add);
				string f(fath);
				cout << "<tr>";
				cout << "<td>" + n + "</td>";
				cout << "<td>" + e + "</td>";
				cout << "<td>" + l + "</td>";
				cout << "<td>" + a + "</td>";
				cout << "<td>" + f + "</td>";
				cout << "</tr>";
				//cout << name << email << log << add << fath;
			}
			cout << "</table><br>";
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
				string newq1 = "select * from reg_table";
				checkSQL1(newq1);
				string newq2 = "select * from faculty_data";
				checkSQL2(newq2);
				//system("start chrome admin.html")
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

		string SQLQuery1 = "select * from admin_login where apassword='";
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
