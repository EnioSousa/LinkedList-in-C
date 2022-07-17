# LinkedList-in-C

This link list saves addresses and not actual data types. The point of doing this is to abstract the best we can using C. You can pass any type of data
as long it's an address, however, you will need to supply how print and free said object.

# Runnable example

There is a small example on how you can use this linked list. You can look at the source code, of the runnable, to see what you will get into to, and see
the headers files, for the information on what each function does. I recommend you use Visual studio code, with the appropriate extensions to more easily see the docs

To compile and run the code on a linux distributions do the following:
``` gcc -Wall node.c linkedList.c runnableExample.c -o app && ./app ```

# What can you do with this?

Well just copy the node.h, node.c, linkedList.h and linkedList.c to you work folder, and start working. I have no patience to actually make this work any other way, you are free to make it more streamline if you wish so.
