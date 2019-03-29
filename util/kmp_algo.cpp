/*
** match - linear time string match algorithm
** David Eppstein / Columbia University / 29 Jan 1988
*/

#include <cstring>

// match - linear time string match algorithm
// David Eppstein / Columbia University / 29 Jan 1988
//
// Only performs exact matches, not comparisons.
// Caller is responsible for case sensitivity or lack thereof.

class string_match {
  const char *target; // string we are looking for
  int index;          // index into target; how much matched so far
  int *retarget;      // what to set match to when mismatch found

public:
  string_match(const char *, int = -1);
  // set up to start matching target string given in first arg
  // second arg is length of string, default whole string up to null

  ~string_match() {
    delete target;
    delete retarget;
  }

  void reset() { index = 0; }
  int match(char c); // adds c to match; returns nz if all matched
};

// Make copy of string in a safe place
const char *save_string(const char *s, int slen = -1) {
  if (s == 0)
    return 0;
  if (slen < 0)
    slen = strlen(s);
  char *new_s = new char[slen + 1];
  if (new_s == 0)
    return 0;
  memcpy(new_s, s, slen);
  new_s[slen] = '\0';
  return new_s;
}

// Make jump table for mismatches (the usual finite state automaton).
//
// The inner loop works by checking the prefixes the next character of
// the target can continue, longest first, chaining back by way of the
// previously filled retarget entries, until it either finds one that
// matches (the != clause) or runs out of prefixes (the > 0 clause).

static int *make_retarget(const char *target) {
  if (target == 0)
    return 0;
  int *retarget = new int[strlen(target) + 1];
  if (retarget == 0)
    return 0;
  retarget[0] = -1; // set up for loop below; unused by match()

  for (int i = 0; target[i] != '\0'; i++) {
    retarget[i + 1] = retarget[i] + 1;
    while (retarget[i + 1] > 0 && target[i] != target[retarget[i + 1] - 1])
      retarget[i + 1] = retarget[retarget[i + 1] - 1] + 1;
  }
  return retarget;
}

// Construct matcher

string_match::string_match(const char *t, int tlen = -1) {
  target = save_string(t, tlen);
  retarget = make_retarget(target);
  index = 0;
}

// Do the search

int string_match::match(char c) {
  if (retarget == 0)
    return 0;

  while (c != target[index]) {
    if (index == 0)
      return 0;              // fell all the way back, have to give up
    index = retarget[index]; // more positions to fall back to, keep trying
  }
  if (target[++index] != '\0')
    return 0; // partial match
  else {
    index = retarget[index]; // full match, but keep going
    return 1;
  }
}
