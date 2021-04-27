set history filename cmds.gdb
set history save on
set listsize 15
list main
b 28
r
n
"Program received signal SIGFPE, Arithmetic exception."
list main
display/d x
display/d y
b 26
r
n
n
"y is still 0 at this point, error was at line 27"
q
