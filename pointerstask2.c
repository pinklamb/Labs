#include <stdio.h>
#include <stdlib.h>

/* IMPLEMENT ME: Declare your functions here */
int add (int a, int b);


int main (void)
{
	/* IMPLEMENT ME: Insert your algorithm here */

	return 0;
}

/* IMPLEMENT ME: Define your functions here */
int add (int a, int b) { printf ("Adding 'a' and 'b'\n"); return a + b; }
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

add_op:
    result = add(num1, num2);
    printf("Addition result: %d\n", result);
    goto end;

subtract_op:
    result = subtract(num1, num2);
    printf("Subtraction result: %d\n", result);
    goto end;

multiply_op:
    result = multiply(num1, num2);
    printf("Multiplication result: %d\n", result);
    goto end;

divide_op:
    result = divide(num1, num2);
    printf("Division result: %d\n", result);
    goto end;

exit_op:
    printf("Exiting program.\n");
    return 0;

int main() {
    void *operations[] = { &&add_op, &&subtract_op, &&multiply_op, &&divide_op, &&exit_op };

    char input;
    printf("Enter '0' for add, '1' for subtract, '2' for multiply, 3 for divide, or 4 to exit the program: ");
    scanf(" %c", &input);

    goto *operations[input - '0'];
}
