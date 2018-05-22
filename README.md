# hstring stringstruct 0.0.4

An ansi string and wide string struct for c programming.

string struct is created in stack. So you don't need to use malloc or free functions. The string struct will be freed automatically.

You don't need to call strlen function because len member of the string struct holds the length of the string.

You can hold strings that includes NULL characters with this header.

## Structs

typedef struct {<br>
    char    str[MAX_STRLEN+1]; //+1 for null<br>	
    size_t  len;<br>
} String; //for ansi string

typedef struct {<br>
    wchar_t   str[MAX_STRLEN+1]; //+1 for null<br>
    size_t  len;<br>
} WString; //for wide string

## Functions

//Ansi string functions:

void scpy(String* dest, const char* src) : copies src of char* to dest String;<br>
void sCpy(String* dest, const String* src) : copies src of String to dest String.

void scat(String* dest, const char* src) : concatanates src of char* dest String.<br>
void sCat(String* dest, const String* src) : concatanates src of String to dest String.

void sEmp(String* dest) : makes empty the dest String.<br>
bool sIsEmp(String* dest) : checks dest String is empty or not.

bool sequ(String* dest, const char* src) : checks src of char* and dest String equality.<br>
bool sEqu(String* dest, const String* src) : checks src of String and dest String equality.

bool stw(String* dest, const char* src) : checks dest String starts with src of char*.<br>
bool sTW(String* dest, const String* src) : checks dest String starts with src String.

int spos(const String* l, const char* s) : returns position of src in l String.<br>
int sPos(const String* l, const String* s) : returns position of src in l String.

##################################################################

//Wide string functions:

void wscpy(WString* dest, const wchar_t* src) : copies src of wchar_t* to dest WString;<br>
void wsCpy(WString* dest, const WString* src) : copies src of WString to dest WString.

void wscat(WString* dest, const wchar_t* src) : concatanates src of wchar_t* dest WString.<br>
void wsCat(WString* dest, const WString* src) : concatanates src of WString to dest WString.

void wsEmp(WString* dest) : makes empty the dest WString.<br>
bool wsIsEmp(WString* dest) : checks dest WString is empty or not.

bool wsequ(WString* dest, const wchar_t* src) : checks src of wchar_t* and dest WString equality.<br>
bool wsEqu(WString* dest, const WString* src) : checks src of WString and dest WString equality.

bool wstw(WString* dest, const wchar_t* src) : checks dest WString starts with src of wchar_t*.<br>
bool wsTW(WString* dest, const WString* src) : checks dest WString starts with src WString.

int wspos(const WString* l, const wchar_t* s) : returns position of src in l WString.<br>
int wsPos(const WString* l, const WString* s) : returns position of src in l WString.

## Release Notes:

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




