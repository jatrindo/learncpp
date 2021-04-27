set history filename cmds.gdb
set history save on
info functions
list main
show listsize
set listsize 15
list main
b 24
display/d x
r
display/d x
list main
n
n
n
list main
list readNumber
list main
b 26
i b
d 1
r
list main
b 25
i b
d 2
r
list
"x is still 0 when we're about to execute line 25, error is on line 24"
q
