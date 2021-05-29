# Arrays and Strings (C++)

## Arrays:
An array in C or C++ is a collection of items stored at contiguous memory locations and elements can be accessed randomly using indices of the array.

  - One Dimensional Array:

    > data_type variable_name[size]
    >  
    >  <b>data_type</b> is the type of array (i.e., int, float, char, etc.)<br/>
    >  <b>variable_name</b> is the name of the array.<br/>
    >  <b>size</b> is the length of the array which is fixed.

  - Two Dimensional Array (Matrix):
    
    > data_type variable_name[N][M]
    > 
    > <b>data_type</b> is the type of array (i.e., int, float, char, etc.)<br/>
    > <b>variable_name</b> is the name of the array.<br/>
    > <b>N</b> is the number of rows. <br/>
    > <b>M</b> is the numbers of columns.

## Strings:

Internally, C++ uses a character array to store strings. Memory management, allocation, and null termination are all handled by the string class itself, which is why it's easy to use. 

  > char str[] = "hello world!"
