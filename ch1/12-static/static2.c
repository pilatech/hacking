#include <stdio.h>

void function() { // example function with own context
int var = 5;
static int static_var = 5; // static variable initialization

printf("\t[in function] var = %d\n", var);
printf("\t[in function] static_var = %d\n", static_var);

printf("\t[in function] var @ %p = %d\n", &var, var);
printf("\t[in function] var @ %p = %d\n", &static_var, static_var);
var++; // Add one to var
static_var++; // add one to static_var.
}

int main() { // The main func with own context
int i;
static int static_var = 1337; // Another static, in diff context

for (i = 0; i < 5; i++) {
printf("[in main] static_var @ %p = %d\n", &static_var, static_var);
printf("[in main] static_var = %d\n", static_var);
function(); // call the function
}

return (0);
}
