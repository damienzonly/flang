## Tokens
- `let`
- `;`
- `+`
- `-`
- `+=`
- `-=`
- `func`
- `exit`
- `(`
- `)`

prog:
- [statement]*

statement:
- assign
- func_declar
- exit

assign:
- assign_equal
- assign_plusequal
- assign_minusequal

exit:
