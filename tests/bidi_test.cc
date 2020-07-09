﻿#include "base/bidi.h"
#include "tkc/wstr.h"
#include "gtest/gtest.h"

TEST(Bidi, basic) {
  bidi_t bidi;
  bidi_t* b = bidi_init(&bidi, FALSE, FALSE, BIDI_TYPE_LTR);
  ASSERT_EQ(bidi_log2vis(b, L"abc", 3), RET_OK); 
  bidi_deinit(b);
}

TEST(Bidi, auto1) {
  bidi_t bidi;
  wstr_t str;
  wstr_init(&str, 10);
  wstr_append(&str, L"م");
  wstr_append(&str, L"ص");
  wstr_append(&str, L"ر");

  bidi_t* b = bidi_init(&bidi, FALSE, FALSE, BIDI_TYPE_RTL);
  ASSERT_EQ(bidi_log2vis(b, str.str, str.size), RET_OK); 

  bidi_deinit(b);
}

