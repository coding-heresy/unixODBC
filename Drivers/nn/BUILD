
cc_library(
    name = 'headers',
    visibility = ['//visibility:public'],
    hdrs = [
        'nnconfig.h',
        'connect.h',
        'convert.h',
        'driver.h',
        'herr.h',
        'hstmt.h',
        'isql.h',
        'isqlext.h',
        'nncol.h',
        'nndate.h',
        'nnsql.h',
        'nntp.h',
        'stmt.h',
        'yyenv.h',
        'yyerr.h',
        'yylex.h',
        'yyparse.tab.h',
        'yystmt.h',
        'herr.ci',
        'nncol.ci',
        'nntp.ci',
        'yyerr.ci',
        'yylex.ci',
    ],
    includes = ['.'],
    copts = [
        '-DHAVE_CONFIG_H',
    ],
)

cc_library(
    name = 'libnn',
    visibility = ['//visibility:public'],
    srcs = [
        'SQLAllocConnect.c',
        'SQLAllocEnv.c',
        'SQLAllocStmt.c',
        'SQLBindCol.c',
        'SQLBindParameter.c',
        'SQLCancel.c',
        'SQLConnect.c',
        'SQLDescribeCol.c',
        'SQLDisconnect.c',
        'SQLDriverConnect.c',
        'SQLError.c',
        'SQLExecDirect.c',
        'SQLExecute.c',
        'SQLFetch.c',
        'SQLFreeConnect.c',
        'SQLFreeEnv.c',
        'SQLFreeStmt.c',
        'SQLGetConnectOption.c',
        'SQLGetData.c',
        'SQLNumParams.c',
        'SQLNumResultCols.c',
        'SQLParamData.c',
        'SQLPrepare.c',
        'SQLPutData.c',
        'SQLRowCount.c',
        'SQLSetConnectOption.c',
        'SQLSetParam.c',
        'misc.c',
        'connect.c',
        'convert.c',
        'execute.c',
        'herr.c',
        'prepare.c',
        'yylex.c',
        'yystmt.c',
        'yyerr.c',
        'yyevl.c',
        'yytchk.c',
        'nncol.c',
        'nndate.c',
        'nntp.c',
    ],
    copts = [
        '-DHAVE_CONFIG_H',
    ],
    deps = [
        '//:headers',
        ':headers',
    ],
)
