#include <assert.h>
#include <stdio.h>

const int BASE = 256;
const int MULTIPLIER = 37;

size_t hash_by_divide(const char *s, size_t m) {
  size_t h;
  unsigned const char *us;

  us = (unsigned const char *)s;

  h = 0;
  while (*us != '\0') {
    h = (h * BASE + *us) % m;
    us++;
  }

  return h;
}

size_t hash_by_multi(const char *s) {
  size_t h;
  unsigned const char *us;
  us = (unsigned const char *)s;

  h = 0;
  while (*us != '\0') {
    h = h * MULTIPLIER + *us;
    us++;
  }

  return h;
}

void test_hash_by_divide() {
  size_t m = 739;
  assert(hash_by_divide("Cosimo", m) == hash_by_divide("Cosimo", m));
  assert(hash_by_divide("Viola", m) == hash_by_divide("Viola", m));
  assert(hash_by_divide("Viola", m) != hash_by_divide("viola", m));
  printf("test_hash_by_divide OK\n");
}

void test_hash_by_multiplication() {
  assert(hash_by_multi("Wang Miao") == hash_by_multi("Wang Miao"));
  assert(hash_by_multi("Ye Wenjie") == hash_by_multi("Ye Wenjie"));
  assert(hash_by_multi("Ye Wenjie") != hash_by_multi("ye wenjie"));
  assert(hash_by_multi("2008") == hash_by_multi("2008"));
  printf("test_hash_by_multiplication OK\n");
}

int main() {
  test_hash_by_divide();
  test_hash_by_multiplication();
}
