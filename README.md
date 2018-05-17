# hstring stringstruct 0.0.3
A string struct for c programming.

string struct is created in stack. So you don't need to use malloc or free functions. The string struct will be freed automatically.

You don't need to call strlen function because len member of the string struct holds the length of the string.

You can hold strings that includes NULL characters with this header.

# Functions

scpy : copies c string to string struct;

sCpy : copies string struct to another string struct.

scat  : concatanates c string to string struct.

sCat  : concatanates string struct to another string struct.

sEmp  : function makes empty the string struct.

sIsEmp : checks string structs is empty or not.

sequ  : checks c string and string struct equality.

sEqu  : checks string struct and another string struct equality.

stw   : checks strings struct starts with a c string.

sTW   : checks a strings struct starts with another string struct.

spos  : returns c string position in a string struct.

sPos  : returns a string struct position in another string struct.

# Release Notes:

Bugs fixed.

New functions added.

# hstring stringstruct 0.0.2

New functions added.

# hstring stringstruct 0.0.1

Released.



