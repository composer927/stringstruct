# hstring stringstruct 0.0.1
A string struct for c programming.

string struct is created in stack. So you don't need to use malloc or free functions. The string struct will be freed when scope of the string variable is valid.

You don't need to call strlen function because len member of the string struct holds the length of the string.

You can hold strings that includes NULL characters with this header.

strCpy function copies c string to string struct.
strCat function concatanate c string to string struct.
strEmpty function makes empty the string struct.


