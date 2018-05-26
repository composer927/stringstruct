# Hstring StringStruct 0.0.7

An ansi string and wide string struct for c programming.

string struct is created in stack. So you don't need to use malloc or free functions. The string struct will be freed automatically.

You don't need to call strlen function because len member of the string struct holds the length of the string.

You can hold strings that includes NULL characters with this header.

## Examples

```
    int i;
    String s1, s2, s3; //declaring
    STRCPY(&s1,"Hey"); //copying or assigning char array
    printf("s1 = %s\n",&s1); //prints "Hey"
    ASSIGN(&s1,"Hello"); //same as STRCPY
    printf("s1 = %s\n",&s1); //prints "Hello"
    STRSTRCPY(&s2,&s1); //copying or assigning String
    printf("s2 = %s\n",&s2); //prints "Hello"
    s2 = COPY(&s1,0,4); //copying 0 to 4 index of s1 and assign to s2 
    printf("s2 = %s\n",&s2); //prints "Hell"
    s2 = LEFTSTR(&s1,3); //copying 0 to 3 index of s1 and assign to s2 
    printf("s2 = %s\n",&s2); //prints "Hel"
    s2 = LSTR(&s1,2); //same as LEFTSTR
    printf("s2 = %s\n",&s2); //prints "He"
    s2 = RIGHTSTR(&s1,2); //copying last 2 characters of s1 and assign to s2 
    printf("s2 = %s\n",&s2); //prints "lo"
    s2 = RSTR(&s1,3); //same as RIGHTSTR
    printf("s2 = %s\n",&s2); //prints "llo"
    STRCAT(&s1," World"); //adding " World" to s1
    printf("s1 = %s\n",&s1); //prints "Hello World"
    ASSIGN(&s2," Again"); //assigning to s2
    STRSTRCAT(&s1,&s2); //adding s2 to s1
    printf("s1 = %s\n",&s1); //prints "Hello World Again"
    i = LEN(&s1); //get length of s1
    printf("s1 = %s\n",&s1); //prints "Hello World Again"
    printf("len of s1 = %d\n",i); //prints 17
    i = LEN(&s2); //get length of s2
    printf("s2 = %s\n",&s2); //prints " Again"
    printf("len of s2 = %d\n",i); //prints 6
    (ISEMP(&s1)) ? printf("s1 is empty already.\n") : MAKEEMP(&s1); //make s1 empty
    printf("s1 = %s\n",&s1); //prints ""
    (ISEMP(&s1)) ? printf("s1 is empty already.\n") : MAKEEMP(&s1); //doit again
    printf("s1 = %s\n",&s1); //prints ""
    ASSIGN(&s1,"HELLO WORLD AGAIN"); //assigning to s1
    printf("s1 = %s\n",&s1); //prints "HELLO WORLD AGAIN"
    DELETE(&s1,5,6);//delete 6 characters from index 5, removes "WORLD"
    printf("s1 = %s\n",&s1); //prints "HELLO AGAIN"
    INSERT(&s1,5," WORLD"); //insert " WORLD" from index 5
    printf("s1 = %s\n",&s1); //prints "HELLO WORLD AGAIN"
    ASSIGN(&s1,"HELLO"); //assigning to s1
    (ISEQU(&s1,"HELLO")) ? printf("Yes, equal.\n") : printf("No, does not equal.\n"); //check equality
    (ISEQU(&s1,"HELLO FRIEND")) ? printf("Yes, equal.\n") : printf("No, does not equal.\n"); //check equality
    ASSIGN(&s2,"HELLO"); //assigning to s1
    (STRISEQU(&s1,&s2)) ? printf("Yes, equal.\n") : printf("No, does not equal.\n"); //check equality
    (STARTSWITH(&s1,"HELL")) ? printf("Yes, s1 starts with that.\n") : printf("No, s1 does not starts with that.\n"); 
    (STRSTARTSWITH(&s1,&s2)) ? printf("Yes, s1 starts with s2.\n") : printf("No, s1 does not starts with s2.\n"); 
    (ENDSWITH(&s1,"LLO")) ? printf("Yes, s1 ends with that.\n") : printf("No, s1 does not ends with that.\n"); 
    (STRENDSWITH(&s1,&s2)) ? printf("Yes, s1 ends with s2.\n") : printf("No, s1 does not ends with s2.\n"); 
    i = POS(&s1,"ELL"); //get start index of "ELL"
    printf("s1 = %s\n",&s1); //prints "HELLO"
    printf("i = %d\n",i); //prints 1
    i = POS(&s1,"EY"); //get start index of "EY"
    printf("i = %d\n",i); //prints -1
    i = POS(&s1,"LO"); //get start index of "LO"
    printf("i = %d\n",i); //prints 3
    i = STRPOS(&s1, &s2); // //get start index of s2 in s1
    printf("i = %d\n",i); //prints 0
    (CONTAINS(&s1,"ELL")) ? printf("Yes, contains.\n") : printf("No, does not contains.\n");
    (CONTAINS(&s1,&s2)) ? printf("Yes, contains.\n") : printf("No, does not contains.\n");
    REPLACE(&s1,"LL","YY"); //replace "ll" with "YY"
    printf("s1 = %s\n",&s1); //prints "HEYYO"
    ASSIGN(&s1,"HELLO"); //assigning to s1
    ASSIGN(&s2,"LL"); //assigning to s2
    ASSIGN(&s3,"YY"); //assigning to s3
    printf("s1 = %s\n",&s1); //prints "HEllO"
    printf("s2 = %s\n",&s2); //prints "ll"
    printf("s3 = %s\n",&s3); //prints "YY"
    STRREPLACE(&s1,&s2,&s3); //replace s2 with s3
    printf("s1 = %s\n",&s1); //prints "HEYYO"
    ASSIGN(&s1,"   HELLO   "); //assigning to s1
    printf("s1 = %s\n",&s1); //prints "   HELLO   "
    i = LEN(&s1); //get length of s1
    printf("len of s1 = %d\n",i); //prints 11
    LTRIM(&s1); //trim left spaces
    printf("s1 = %s\n",&s1); //prints "HELLO   "
    i = LEN(&s1); //get length of s1
    printf("len of s1 = %d\n",i); //prints 8
    RTRIM(&s1); //trim right spaces
    printf("s1 = %s\n",&s1); //prints "HELLO"
    i = LEN(&s1); //get length of s1
    printf("len of s1 = %d\n",i); //prints 5
    ASSIGN(&s1,"   HELLO   "); //assigning to s1
    printf("s1 = %s\n",&s1); //prints "   HELLO   "
    i = LEN(&s1); //get length of s1
    printf("len of s1 = %d\n",i); //prints 11
    TRIM(&s1); //trim spaces
    printf("s1 = %s\n",&s1); //prints "HELLO"
    i = LEN(&s1); //get length of s1
    printf("len of s1 = %d\n",i); //prints 5
    DUPE(&s1,"e",2); //assign s1 2 tmes e
    printf("s : %s\n",&s1); //prints "ee"
    ADDDUPE(&s1,"c",2); // add dupe 
    printf("s : %s\n",&s1); //prints "eecc"
    TOUPP(&s1); //uppercase
    printf("s : %s\n",&s1); //prints "EECC"
    TOLOW(&s1); //lovercase
    printf("s : %s\n",&s1); //prints "eecc"
    s1 = ITOS(47775); //integer to String
    printf("s1 : %s\n",&s1); //prints 47775
    i = STOI(&s1); //String to integer
    printf("i : %d\n",i); //prints 47775
```

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

size_t LEN(String* dest) : length of dest String.

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

void TRIMLEFT(String* dest) : trims white spaces from left of dest String.<br>
void LTRIM(String* dest) : same as TRIMLEFT.<br>
void TRIMRIGHT(String* dest) : trims white spaces from right of dest String.<br>
void RTRIM(String* dest) : same as TRIMRIGHT.<br>
void TRIM(String* dest) : trims white spaces from left and right of dest String.

void DUPE(String* dest, const char* src, int count) : repeats char* of src and assign to dest String.<br>
void ADDDUPE(String* dest, const char* src, int count) : repeats char* of src and adds to dest String.

void TOUPP(String* dest) : makes dest String uppercase.<br>
void TOLOW(String* dest) : makes dest String lowercase.

String ITOS(int i) : int to string.<br>
int STOI(String* s) : string to int.

##################################################################

//Wide string functions:
//Comments that mentioned above are valid too.

void WSTRCPY(WString* dest, const wchar_t* src)<br>
void WASSIGN(WString* dest, const wchar_t* src)<br>
void WSTRSTRCPY(WString* dest, const WString* src)<br>
WString WCOPY(const WString* dest, int startindex, int count)<br>
WString WLEFTSTR(const WString* dest, int count)<br>
WString WLSTR(const WString* dest, int count)<br>
WString WRIGHTSTR(const WString* dest, int count)<br>
WString WRSTR(const WString* dest, int count)<br>
void WSTRCAT(WString* dest, const wchar_t* src)<br>
void WSTRSTRCAT(String* dest, const WString* src)<br>
size_t WLEN(String* dest)<br>
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
void WSTRREPLACE(WString* dest, const WString* olD, const WString* neW)<br>
void WTRIMLEFT(WString* dest) : trims white spaces from left of dest String.<br>
void WLTRIM(WString* dest) : same as TRIMLEFT.<br>
void WTRIMRIGHT(WString* dest) : trims white spaces from right of dest String.<br>
void WRTRIM(WString* dest) : same as TRIMRIGHT.<br>
void WTRIM(WString* dest) : trims white spaces from left and right of dest String.<br>
void WDUPE(WString* dest, const wchar_t* src, int count) : repeats char* of src and assign to dest String.<br>
void WADDDUPE(WString* dest, const wchar_t* src, int count) : repeats char* of src and adds to dest String.<br>
void WTOUPP(WString* dest) : makes dest String uppercase.<br>
void WTOLOW(WString* dest) : makes dest String lowercase.<br>
String ITOWS(int i) : int to string.<br>
int WSTOI(WString* s) : string to int.
String WTOS(const wchar_t* src)
WString STOW(const char* src)

## Release Notes

Bugs fixed.<br>
New functions added.

# hstring stringstruct 0.0.6

Bugs fixed.<br>
New functions added.

# hstring stringstruct 0.0.5

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




