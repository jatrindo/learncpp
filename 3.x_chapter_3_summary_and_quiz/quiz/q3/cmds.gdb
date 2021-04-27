set history filename cmds.gdb
set history save on
set listsize 15
list d
set history filename cmds.gdb
set history save on
set listsize 15
list d
b 8
r
backtrace
"d() <- b() <- a() <- main()"
q
