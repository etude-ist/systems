#include <assert.h>
#include <stdio.h>

// "[...] merely an intellectual amusement."
void inplace_swap(int *x, int *y) {
  *y = *x ^ *y;
  *x = *x ^ *y;
  *y = *x ^ *y;
}

void reverse_array(int a[], int cnt) {
  int first, last;
  for (first = 0, last = cnt - 1; first <= last && first != last;
       first++, last--) {
    inplace_swap(&a[first], &a[last]);
  }
}

int cmp_arr(int a[], int b[], int n) {
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      return 0;
    }
  }
  return 1;
}

int bit_xor_op(int a, int b) { return a & b; }

int bit_complement_op(int a, int b) { return a ^ b; }

int bit_or_op(int a, int b) { return a | b; }

int bit_mask(int a, int mask, int (*comp)(int, int)) { return comp(a, mask); }

int bit_equals(int a, int b) { return !(a ^ b); }

int main() {
  int a = 82;
  int b = 19;
  inplace_swap(&a, &b);
  assert(a == 19);
  assert(b == 82);

  int array[] = {1, 2, 3, 4};
  reverse_array(array, 4);
  int test_array_a[] = {1, 2, 3, 4};
  int test_array_b[] = {4, 3, 2, 1};
  assert(cmp_arr(array, test_array_a, 4) == 0);
  assert(cmp_arr(array, test_array_b, 4) == 1);

  int array_odd[] = {1, 2, 3, 4, 5};
  reverse_array(array_odd, 5);
  int test_array_c[] = {5, 4, 3, 2, 1};
  assert(cmp_arr(array_odd, test_array_c, 5) == 1);

  int same = 3;
  inplace_swap(&same, &same);
  assert(same == 0);
  assert(0 == (3 ^ 3));

  int c = 0x87654321;
  assert(bit_mask(c, 0xFF, bit_xor_op) == 0x00000021);
  assert(bit_mask(c, 0xFFFFFF00, bit_complement_op) == 0x789ABC21);
  assert(bit_mask(c, 0xFF, bit_or_op) == 0x876543FF);

  int x = 0x66;
  int y = 0x39;
  assert((x & y) == 0x20);
  assert((x | y) == 0x7F);
  // assert((~x | ~y) == 0xDF);
  assert((x & !y) == 0x00);

  assert(bit_equals(3, 3) == 1);
  assert(bit_equals(3, 4) == 0);

  // Left shifts
  assert(0xC3 << 3 == 0x618);
  assert(0x75 << 3 == 0x3A8);
  assert(0x87 << 3 == 0x438);
  assert(0x66 << 3 == 0x330);

  // Right shifts (logical)
  assert(0xC3 >> 2 == 0x30);
  assert(0x75 >> 2 == 0x1D);
  assert(0x87 >> 2 == 0x21);
  assert(0x66 >> 2 == 0x19);

  printf("All tests pass!\n");
  return 0;
}
