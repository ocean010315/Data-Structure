#include <stdio.h>
#include "matrix.h"

void main() {
	int a[ROW][COL] = { {1, 0, 0}, {1, 0, 0}, {1, 0, 0} };
	int b[ROW][COL] = { {1, 1, 1}, {0, 0, 0}, {0, 0, 0} };
	int c[ROW][COL] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };

	matrix_print(a);
	matrix_print(b);

	matrix_add(a, b, c);
	matrix_print(c);

	matrix_init(c);
	matrix_mult(a, b, c);
	matrix_print(c);

	matrix_init(c);
	matrix_trans(a, c);
	matrix_print(c);
}

void matrix_init(int a[ROW][COL]) {
	int i, j;

	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++)
			a[i][j] = 0;
	}
}

void matrix_add(int a[ROW][COL], int b[ROW][COL], int c[ROW][COL]) {
	int i, j;

	printf("a + b = \n");

	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}

void matrix_mult(int a[ROW][COL], int b[ROW][COL], int c[ROW][COL]) {
	int i, j, m;

	printf("a * b = \n");

	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			for (m = 0; m < 3; m++) {
				c[i][j] += a[i][m] * b[m][j];
			}
		}
	}
}

void matrix_trans(int a[ROW][COL], int b[ROW][COL]) {
	int i, j;

	printf("a transpose = \n");

	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			b[j][i] = a[i][j];
		}
	}
}

void matrix_print(int a[ROW][COL]) {
	int i, j;
	
	puts("");
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			printf("%3d", a[i][j]);
		}
		puts("");
	}
	puts("");
}
