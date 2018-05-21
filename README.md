# hstring stringstruct 0.0.4

An ansi string and wide string struct for c programming.

string struct is created in stack. So you don't need to use malloc or free functions. The string struct will be freed automatically.

You don't need to call strlen function because len member of the string struct holds the length of the string.

You can hold strings that includes NULL characters with this header.

# Structs

typedef struct {
    char    str[MAX_STRLEN+1]; //+1 for null
    size_t  len;
} String; //for ansi string

typedef struct {
    wchar_t   str[MAX_STRLEN+1]; //+1 for null
    size_t  len;
} WString; //for wide string

# Functions

//Ansi string functions:

void scpy(String* dest, const char* src) : copies src of char* to dest String;
void sCpy(String* dest, const String* src) : copies src of String to dest String.

void scat(String* dest, const char* src) : concatanates src of char* dest String.
void sCat(String* dest, const String* src) : concatanates src of String to dest String.

void sEmp(String* dest) : makes empty the dest String.
bool sIsEmp(String* dest) : checks dest String is empty or not.

bool sequ(String* dest, const char* src) : checks src of char* and dest String equality.
bool sEqu(String* dest, const String* src) : checks src of String and dest String equality.

bool stw(String* dest, const char* src) : checks dest String starts with src of char*.
bool sTW(String* dest, const String* src) : checks dest String starts with src String.

int spos(const String* l, const char* s) : returns src of char* in l String.
int sPos(const String* l, const String* s) : returns src of String in l String.

##################################################################

//Wide string functions:

void wscpy(WString* dest, const wchar_t* src) : copies src of wchar_t* to dest WString;
void wsCpy(WString* dest, const WString* src) : copies src of WString to dest WString.

void wscat(WString* dest, const wchar_t* src) : concatanates src of wchar_t* dest WString.
void wsCat(WString* dest, const WString* src) : concatanates src of WString to dest WString.

void wsEmp(WString* dest) : makes empty the dest WString.
bool wsIsEmp(WString* dest) : checks dest WString is empty or not.

bool wsequ(WString* dest, const wchar_t* src) : checks src of wchar_t* and dest WString equality.
bool wsEqu(WString* dest, const WString* src) : checks src of WString and dest WString equality.

bool wstw(WString* dest, const wchar_t* src) : checks dest WString starts with src of wchar_t*.
bool wsTW(WString* dest, const WString* src) : checks dest WString starts with src WString.

int wspos(const WString* l, const wchar_t* s) : returns src of wchar_t* in l WString.
int wsPos(const WString* l, const WString* s) : returns src of WString in l WString.

# Release Notes:

WideString support added.

New functions added.

# hstring stringstruct 0.0.3

# Release Notes:

Bugs fixed.

New functions added.

# hstring stringstruct 0.0.2

New functions added.

# hstring stringstruct 0.0.1

Released.



