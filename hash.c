#include <stdio.h>
#include <assert.h>

const int BASE = 256;

size_t hash_by_divide(const char *s, size_t m) {
  size_t h;
  unsigned const char *us;

  us = (unsigned const char*) s;

  h = 0;
  while (*us != '\0') {
    h = (h * BASE + *us) % m;
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

int main() {
  test_hash_by_divide();
}
