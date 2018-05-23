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

void STRCPY(String* dest, const char* src) : copies src of char* to dest String.<br>
void ASSIGN(String* dest, const char* src) : same as STRCPY.<br>
void STRSTRCPY(String* dest, const String* src) : copies src of String to dest String.

String COPY(const String* dest, int startindex, int count) : copies part of dest String and returns it.<br>
String LEFTSTR(const String* dest, int count) : copies left part of dest String and returns it.<br>
String LSTR(const String* dest, int count) : same as LEFTSTR.<br>
String RIGHTSTR(const String* dest, int count) : copies right part of dest String and returns it.<br>
String RSTR(const String* dest, int count) : same as RIGHTSTR.

void STRCAT(String* dest, const char* src) : concatanates src of char* dest String.<br>
void STRSTRCAT(String* dest, const String* src) : concatanates src of String to dest String.

void MAKEEMP(String* dest) : makes empty the dest String.<br>
bool ISEMP(String* dest) : checks dest String is empty or not.

void DELETE(String* dest, int startindex, int count) : deletes a part of dest string.<br>
void INSERT(String* dest, int startindex, const char* src) : inserts char* into dest string.

bool ISEQU(String* dest, const char* src) : checks src of char* and dest String equality.<br>
bool STRISEQU(String* dest, const String* src) : checks src of String and dest String equality.

bool STARTSWITH(String* dest, const char* src) : checks dest String starts with src of char*.<br>
bool STRSTARTSWITH(String* dest, const String* src) : checks dest String starts with src String.<br>
bool ENDSWITH(const String* dest, const char* src) : checks dest String ends with src of char*.<br>
bool STRENDSWITH(const String* dest, const String* src) : checks dest String ends with src String.

int POS(const String* l, const char* s) : returns position of src in l String.<br>
int STRPOS(const String* l, const String* s) : returns position of src in l String.<br>
bool CONTAINS(const String* l, const char* s) : checks l String contains s char*.<br>
bool STRCONTAINS(const String* l, const String* s) checks l String contains s String.

void REPLACE(String* dest, const char* olD, const char* neW)<br> 
void STRREPLACE(String* dest, const String* olD, const String* neW)

##################################################################

//Wide string functions:
//Comments that mentioned above are valid too.

void WSTRCPY(WString* dest, const wchar_t* src)<br>
void WASSIGN(WString* dest, const wchar_t* src)<br>
void WSTRSTRCPY(WString* dest, const WString* src)<br>
String WCOPY(const WString* dest, int startindex, int count)<br>
String WLEFTSTR(const WString* dest, int count)<br>
String WLSTR(const WString* dest, int count)<br>
String WRIGHTSTR(const WString* dest, int count)<br>
String WRSTR(const WString* dest, int count)<br>
void WSTRCAT(WString* dest, const wchar_t* src)<br>
void WSTRSTRCAT(String* dest, const WString* src)<br>
void WMAKEEMP(WString* dest)<br>
bool WISEMP(const WString* dest)<br>
void WDELETE(WString* dest, int startindex, int count)<br>
void WINSERT(WString* dest, int startindex, const wchar_t* src)<br>
bool WISEQU(const String* dest, const wchar_t* src)<br>
bool WSTRISEQU(const WString* dest, const WString* src)<br>
bool WSTARTSWITH(const WString* dest, const wchar_t* src)<br>
bool WSTRSTARTSWITH(const WString* dest, const WString* src)<br>
bool WENDSWITH(const WString* dest, const wchar_t* src)<br>
bool WSTRENDSWITH(const WString* dest, const WString* src)<br>
int WPOS(const WString* l, const wchar_t* s)<br>
int WSTRPOS(const WString* l, const WString* s)<br>
bool WCONTAINS(const WString* l, const wchar_t* s)<br>
bool WSTRCONTAINS(const WString* l, const WString* s)<br>
void WREPLACE(WString* dest, const wchar_t* olD, const wchar_t* neW)<br>
void WSTRREPLACE(WString* dest, const WString* olD, const WString* neW)

## Release Notes:

Bugs fixed.

Funcion names changed.

New functions added.

# hstring stringstruct 0.0.4

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




