#include "catch.hpp"

#include "int_array.h"
#include "int_array.h" // test include guards are good

TEST_CASE("can create array") {
  dsc::IntArray array(5);
}

TEST_CASE("array has correct size") {
  REQUIRE(dsc::IntArray(5).size() == 5);
  REQUIRE(dsc::IntArray(1).size() == 1);
  REQUIRE(dsc::IntArray(678).size() == 678);
}

TEST_CASE("can get size of const array") {
  const dsc::IntArray array(5);
  REQUIRE(array.size() == 5);
}

TEST_CASE("can set elements in array") {
  dsc::IntArray array(5);

  array[0] = 11;
  array[3] = 2;

  REQUIRE(array[0] == 11);
  REQUIRE(array[3] == 2);
}

TEST_CASE("Returns elements by reference") {
  dsc::IntArray array(5);

  array[0] = 1;
  int& ref1 = array[0];
  int& ref2 = array[0];
  ref2 = 3;

  REQUIRE(&ref1 == &ref2);
  REQUIRE(ref1 == 3);
  REQUIRE(ref2 == 3);
}


TEST_CASE("can access elements in const array") {
  dsc::IntArray array(5);

  array[0] = 11;
  array[3] = 2;

  const dsc::IntArray& const_ref = array;
  REQUIRE(const_ref[0] == 11);
  REQUIRE(const_ref[3] == 2);
}

TEST_CASE("copy constructed array has correct size") {
  dsc::IntArray src(4);
  dsc::IntArray copy = src;

  REQUIRE(copy.size() == 4);
}

TEST_CASE("copy constructed array is not shallow") {
  dsc::IntArray src(4);
  dsc::IntArray copy = src;

  REQUIRE(&copy[0] != &src[0]);
}

TEST_CASE("copy constructed array has same values") {
  dsc::IntArray src(4);
  src[0] = 10;
  src[1] = 30;
  src[2] = 600;
  src[3] = 99;

  dsc::IntArray copy = src;
  REQUIRE(copy[0] == 10);
  REQUIRE(copy[1] == 30);
  REQUIRE(copy[2] == 600);
  REQUIRE(copy[3] == 99);
  REQUIRE(src[0] == 10);
  REQUIRE(src[1] == 30);
  REQUIRE(src[2] == 600);
  REQUIRE(src[3] == 99);
}

TEST_CASE("copy assigned array has correct size") {
  dsc::IntArray src(3);
  dsc::IntArray copy(10);
  copy = src;

  REQUIRE(copy.size() == 3);
}

TEST_CASE("copy assigned array is not shallow") {
  dsc::IntArray src(4);
  dsc::IntArray copy(2);
  copy = src;

  REQUIRE(&copy[0] != &src[0]);
}

TEST_CASE("copy assigned array has same values") {
  dsc::IntArray src(4);
  src[0] = 10;
  src[1] = 30;
  src[2] = 600;
  src[3] = 99;

  dsc::IntArray copy(2);
  copy = src;
  REQUIRE(copy[0] == 10);
  REQUIRE(copy[1] == 30);
  REQUIRE(copy[2] == 600);
  REQUIRE(copy[3] == 99);
  REQUIRE(src[0] == 10);
  REQUIRE(src[1] == 30);
  REQUIRE(src[2] == 600);
  REQUIRE(src[3] == 99);
}

TEST_CASE("can self-assign") {
  dsc::IntArray array(5);
  array = array;

  array[0] = 11;
  array[3] = 2;

  REQUIRE(array[0] == 11);
  REQUIRE(array[3] == 2);
}
