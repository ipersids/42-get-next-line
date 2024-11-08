<div align="center">
<picture>
  <img alt="Get Next Line with bonus" src="https://github.com/ayogun/42-project-badges/blob/main/badges/get_next_linem.png" />
</picture>

## Get Next Line

</div>

The Get Next Line project is a part of the [Hive Helsinki (42 School Network)](https://www.hive.fi/en/curriculum) core curriculum.  

 Function `get_next_line` helps to read a file descriptor one line at a time. It returns the line that was read, including the terminating `\n` character, except when reaching the end of the file without a new line. If there is nothing left to read or an error occurs, the function will return `NULL`.  
 
 The buffer size can be defined at compile time using the `-D BUFFER_SIZE` directive, allowing for flexible memory management.  

 ### Algorithm  
 The following diagram illustrates how the `get_next_line` function works:  

```mermaid
---
title: Get Next Line Algorithm

---
graph TD;

    start([Start]) --> if1{{Is the buffer size and file descriptor valid?}};
    if1 -- No --> r1[/Return NULL/];
    r1 --> stop([Stop]);
    if1 -- Yes --> a1{{Does the buffer contain a newline?}};
    
    a1 -- Yes --> a2[Locate '\n' character in buffer];
    a1 -- No --> a3[Read more from file into buffer];

    a2 --> a4[Allocate memory for the line];
    a4 -- Fail --> a5[Free allocated memory and reset pointers];
    a5 --> r2[/Return NULL/];
    r2 --> stop;
    a4 -- Success --> a6[Move any leftover data after '\n' to the start of the buffer];
    a6 --> r4[/Return new line/];
    r4 --> stop;

    a3 --> if2{{Did read succeed?}};
    if2 -- No --> a7[Free allocated memory and reset pointers];
    a7 --> r3[/Return NULL/];
    r3 --> stop;
    if2 -- Yes --> if3{{Is it EOF?}};

    if3 -- No --> a1;
    if3 -- Yes --> if4{{Is there content to return?}};
    
    if4 -- Yes --> r5[/Return last line. Set buffer to NULL/];
    r5 --> stop;
    if4 -- No --> a8[/Free allocated memory/];
    a8 --> r6[/Return NULL/];
    r6 --> stop;
```

------

Made by Julia Persidskaia.  
[LinkedIn](https://www.linkedin.com/in/iuliia-persidskaia/)  
