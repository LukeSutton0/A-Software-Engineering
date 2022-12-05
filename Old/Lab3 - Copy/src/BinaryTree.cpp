#include "../headers/tree.h"
#define BOOST_TEST_MODULE Dictionary_Tests
#include <boost/test/included/unit_test.hpp>

// // Uncomment the below macros enable dynamic linking.
// // You will also need to comment-out the `single-header' macros above.
// #define BOOST_TEST_DYN_LINK
// #define BOOST_TEST_MODULE Dictionary_Tests
// #include <boost/test/unit_test.hpp>

////////////////////////////////////////////////////////////////////////////////

#include <string>
#include "dictionary.h"

////////////////////////////////////////////////////////////////////////////////

// Utility Functions

void isPresent(Dictionary & dict, int k, std::string i)
{
  std::string* p_i = dict.lookup(k);
  BOOST_CHECK_MESSAGE(p_i, std::to_string(k) + " is missing");
  if (p_i)
  {
    BOOST_CHECK_MESSAGE(*p_i == i,
      std::to_string(k) + " should be " + i + ", but found " + *p_i);
  }
}

void isAbsent(Dictionary & dict, int k)
{
  BOOST_CHECK_MESSAGE(dict.lookup(k) == nullptr,
    std::to_string(k) + " should be absent, but is present.");
}

void insertTestData(Dictionary & dict)
{
  dict.insert(22,"Jane");
  dict.insert(22,"Mary");
  dict.insert(0,"Harold");
  dict.insert(9,"Edward");
  dict.insert(37,"Victoria");
  dict.insert(4,"Matilda");
  dict.insert(26,"Oliver");
  dict.insert(42,"Elizabeth");
  dict.insert(19,"Henry");
  dict.insert(4,"Stephen");
  dict.insert(24,"James");
  dict.insert(-1,"Edward");
  dict.insert(31,"Anne");
  dict.insert(23,"Elizabeth");
  dict.insert(1,"William");
  dict.insert(26,"Charles");
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE( Lookup_Insert_Tests )

BOOST_AUTO_TEST_CASE( EmptyLookup )
{
  Dictionary dict;
  isAbsent(dict,1);
}

BOOST_AUTO_TEST_CASE( SingleInsert )
{
  Dictionary dict;
  dict.insert(22,"Mary");
}

BOOST_AUTO_TEST_CASE( SingleInsertLookup )
{
  Dictionary dict;
  dict.insert(22,"Mary");
  isPresent(dict,22,"Mary");
}

BOOST_AUTO_TEST_CASE( SingleOverwriteLookup )
{
  Dictionary dict;
  dict.insert(22,"Jane");
  dict.insert(22,"Mary");
  isPresent(dict,22,"Mary");
}

BOOST_AUTO_TEST_CASE( MultipleInsert )
{
  Dictionary dict;
  insertTestData(dict);
}

BOOST_AUTO_TEST_CASE( MultipleInsertLookupPresent )
{
  Dictionary dict;
  insertTestData(dict);

  isPresent(dict,22,"Mary");
  isPresent(dict,4,"Stephen");
  isPresent(dict,9,"Edward");
  isPresent(dict,1,"William");
  isPresent(dict,0,"Harold");
  isPresent(dict,24,"James");
  isPresent(dict,26,"Charles");
  isPresent(dict,19,"Henry");
  isPresent(dict,31,"Anne");
  isPresent(dict,23,"Elizabeth");
  isPresent(dict,37,"Victoria");
  isPresent(dict,42,"Elizabeth");
  isPresent(dict,-1,"Edward");
}

BOOST_AUTO_TEST_CASE( MultipleInsertLookupAbsent )
{
  Dictionary dict;
  insertTestData(dict);

  isAbsent(dict,2);
  isAbsent(dict,3);
  isAbsent(dict,-4);
  isAbsent(dict,56);
  isAbsent(dict,30);
}

BOOST_AUTO_TEST_SUITE_END()

////////////////////////////////////////////////////////////////////////////////