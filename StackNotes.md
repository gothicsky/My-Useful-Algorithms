# Stack

### Stack Details 

A stack similar to an array can store multiple data items of the same type

We can do two operations on a stack 
 - Push an item onto the stack
 - Pop an item from the stack  

Pushishing adds it to one end (the stack top)
Popping removes it from the the stack top

*Rules*: We can't examine or modify an item that's not at the top of the stack 

### Implementation 

 - [ ] Store items of stack in an Array called contents 
 - [ ] A seperate integer called top marks the position of stack top 
 - [ ] If the stack is empty, top has value 0
 - [ ] To push an item onto the stack store the item in contents at the position indicated by top then increment the top
 - [ ] To pop an item from the stack, decrement the top, then use it as an index into contents to fetch the item being popped
