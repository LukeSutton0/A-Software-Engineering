#define BOOST_TEST_MODULE Dictionary_Tests
#include <boost/test/included/unit_test.hpp>

// // Uncomment the below macros enable dynamic linking.
// // You will also need to comment-out the `single-header' macros above.
// #define BOOST_TEST_DYN_LINK
// #define BOOST_TEST_MODULE Dictionary_Tests
// #include <boost/test/unit_test.hpp>
////////////////////////////////////////////////////////////////////////////////

#include "../Dictionary/dictionary.h"

////////////////////////////////////////////////////////////////////////////////

// Utility Functions

void isPresent(Dictionary& Dictionary, int k, std::string i)
{
    std::string* p_i = Dictionary.lookup(k);
    BOOST_CHECK_MESSAGE(p_i, std::to_string(k) + " is missing");
    if (p_i)
    {
        BOOST_CHECK_MESSAGE(*p_i == i,
            std::to_string(k) + " should be " + i + ", but found " + *p_i);
    }
}

void isAbsent(Dictionary& Dictionary, int k)
{
    BOOST_CHECK_MESSAGE(Dictionary.lookup(k) == nullptr,
        std::to_string(k) + " should be absent, but is present.");
}

void insertTestData(Dictionary& Dictionary)
{
    Dictionary.insert(22, "Jane");
    Dictionary.insert(22, "Mary");
    Dictionary.insert(0, "Harold");
    Dictionary.insert(9, "Edward");
    Dictionary.insert(37, "Victoria");
    Dictionary.insert(4, "Matilda");
    Dictionary.insert(26, "Oliver");
    Dictionary.insert(42, "Elizabeth");
    Dictionary.insert(19, "Henry");
    Dictionary.insert(4, "Stephen");
    Dictionary.insert(24, "James");
    Dictionary.insert(-1, "Edward");
    Dictionary.insert(31, "Anne");
    Dictionary.insert(23, "Elizabeth");
    Dictionary.insert(1, "William");
    Dictionary.insert(26, "Charles");
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(Lookup_Insert_Tests)

BOOST_AUTO_TEST_CASE(EmptyLookup)
{
    Dictionary Dictionary;
    isAbsent(Dictionary, 1);
}

BOOST_AUTO_TEST_CASE(SingleInsert)
{
    Dictionary Dictionary;
    Dictionary.insert(22, "Mary");
}

BOOST_AUTO_TEST_CASE(SingleInsertLookup)
{
    Dictionary Dictionary;
    Dictionary.insert(22, "Mary");
    isPresent(Dictionary, 22, "Mary");
}

BOOST_AUTO_TEST_CASE(SingleOverwriteLookup)
{
    Dictionary Dictionary;
    Dictionary.insert(22, "Jane");
    Dictionary.insert(22, "Mary");
    isPresent(Dictionary, 22, "Mary");
}

BOOST_AUTO_TEST_CASE(MultipleInsert)
{
    Dictionary Dictionary;
    insertTestData(Dictionary);
}

BOOST_AUTO_TEST_CASE(MultipleInsertLookupPresent)
{
    Dictionary Dictionary;
    insertTestData(Dictionary);

    isPresent(Dictionary, 22, "Mary");
    isPresent(Dictionary, 4, "Stephen");
    isPresent(Dictionary, 9, "Edward");
    isPresent(Dictionary, 1, "William");
    isPresent(Dictionary, 0, "Harold");
    isPresent(Dictionary, 24, "James");
    isPresent(Dictionary, 26, "Charles");
    isPresent(Dictionary, 19, "Henry");
    isPresent(Dictionary, 31, "Anne");
    isPresent(Dictionary, 23, "Elizabeth");
    isPresent(Dictionary, 37, "Victoria");
    isPresent(Dictionary, 42, "Elizabeth");
    isPresent(Dictionary, -1, "Edward");
}

BOOST_AUTO_TEST_CASE(MultipleInsertLookupAbsent)
{
    Dictionary Dictionary;
    insertTestData(Dictionary);

    isAbsent(Dictionary, 2);
    isAbsent(Dictionary, 3);
    isAbsent(Dictionary, -4);
    isAbsent(Dictionary, 56);
    isAbsent(Dictionary, 30);
}

BOOST_AUTO_TEST_SUITE_END()
/*
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(Remove_Tests)

BOOST_AUTO_TEST_CASE(EmptyRemove)
{
    Dictionary Dictionary;
    Dictionary.remove(43);
    isAbsent(Dictionary, 43);
}

BOOST_AUTO_TEST_CASE(RemoveChildlessRoot)
{
    Dictionary Dictionary;
    Dictionary.insert(7, "John");
    Dictionary.remove(7);
    isAbsent(Dictionary, 7);
}

BOOST_AUTO_TEST_CASE(RemoveLeftChildOfRoot)
{
    Dictionary Dictionary;
    Dictionary.insert(31, "Anne");
    Dictionary.insert(7, "John");
    Dictionary.remove(7);

    isAbsent(Dictionary, 7);
    isPresent(Dictionary, 31, "Anne");
}

BOOST_AUTO_TEST_CASE(RemoveRightChildOfRoot)
{
    Dictionary Dictionary;
    Dictionary.insert(7, "John");
    Dictionary.insert(31, "Anne");
    Dictionary.remove(31);

    isAbsent(Dictionary, 31);
    isPresent(Dictionary, 7, "John");
}

BOOST_AUTO_TEST_CASE(InsertMany_RemoveChildlessNodes)
{
    Dictionary Dictionary;
    insertTestData(Dictionary);

    Dictionary.remove(-1);
    isAbsent(Dictionary, -1);

    Dictionary.remove(1);
    isAbsent(Dictionary, 1);

    Dictionary.remove(19);
    isAbsent(Dictionary, 19);

    Dictionary.remove(23);
    isAbsent(Dictionary, 23);

    Dictionary.remove(31);
    isAbsent(Dictionary, 31);

    Dictionary.remove(42);
    isAbsent(Dictionary, 42);

    Dictionary.remove(4);
    isAbsent(Dictionary, 4);

    isPresent(Dictionary, 22, "Mary");
    isPresent(Dictionary, 9, "Edward");
    isPresent(Dictionary, 0, "Harold");
    isPresent(Dictionary, 24, "James");
    isPresent(Dictionary, 26, "Charles");
    isPresent(Dictionary, 37, "Victoria");
}

BOOST_AUTO_TEST_CASE(OverwriteThenRemove)
{
    Dictionary Dictionary;
    Dictionary.insert(22, "Jane");
    Dictionary.insert(22, "Mary");
    Dictionary.insert(4, "Matilda");
    Dictionary.insert(26, "Oliver");
    Dictionary.insert(4, "Stephen");
    Dictionary.insert(26, "Charles");

    Dictionary.remove(4);
    isAbsent(Dictionary, 4);

    Dictionary.remove(26);
    isAbsent(Dictionary, 26);

    Dictionary.remove(22);
    isAbsent(Dictionary, 22);
}

BOOST_AUTO_TEST_CASE(RemoveRootWithLeftChild)
{
    Dictionary Dictionary;
    Dictionary.insert(31, "Anne");
    Dictionary.insert(7, "John");
    Dictionary.remove(31);

    isAbsent(Dictionary, 31);
    isPresent(Dictionary, 7, "John");
}

BOOST_AUTO_TEST_CASE(RemoveRootWithRightChild)
{
    Dictionary Dictionary;
    Dictionary.insert(7, "John");
    Dictionary.insert(31, "Anne");
    Dictionary.remove(31);

    isAbsent(Dictionary, 31);
    isPresent(Dictionary, 7, "John");
}

BOOST_AUTO_TEST_CASE(InsertMany_RemoveNodesWithOneChild)
{
    Dictionary Dictionary;
    insertTestData(Dictionary);

    Dictionary.remove(4);
    isAbsent(Dictionary, 4);

    Dictionary.remove(1);
    isAbsent(Dictionary, 1);

    Dictionary.remove(9);
    isAbsent(Dictionary, 9);

    isPresent(Dictionary, 22, "Mary");
    isPresent(Dictionary, 0, "Harold");
    isPresent(Dictionary, 24, "James");
    isPresent(Dictionary, 26, "Charles");
    isPresent(Dictionary, 19, "Henry");
    isPresent(Dictionary, 31, "Anne");
    isPresent(Dictionary, 23, "Elizabeth");
    isPresent(Dictionary, 37, "Victoria");
    isPresent(Dictionary, 42, "Elizabeth");
    isPresent(Dictionary, -1, "Edward");
}

BOOST_AUTO_TEST_CASE(RemoveRootWithChildren)
{
    Dictionary Dictionary;
    Dictionary.insert(31, "Anne");
    Dictionary.insert(7, "John");
    Dictionary.insert(42, "Elizabeth");
    Dictionary.remove(31);

    isAbsent(Dictionary, 31);
    isPresent(Dictionary, 7, "John");
    isPresent(Dictionary, 42, "Elizabeth");
}

BOOST_AUTO_TEST_CASE(InsertMany_RemoveNodesWithChildren)
{
    Dictionary Dictionary;
    insertTestData(Dictionary);

    Dictionary.remove(0);
    isAbsent(Dictionary, 0);

    Dictionary.remove(37);
    isAbsent(Dictionary, 37);

    Dictionary.remove(22);
    isAbsent(Dictionary, 22);

    isPresent(Dictionary, 4, "Stephen");
    isPresent(Dictionary, 9, "Edward");
    isPresent(Dictionary, 1, "William");
    isPresent(Dictionary, 24, "James");
    isPresent(Dictionary, 26, "Charles");
    isPresent(Dictionary, 19, "Henry");
    isPresent(Dictionary, 31, "Anne");
    isPresent(Dictionary, 23, "Elizabeth");
    isPresent(Dictionary, 42, "Elizabeth");
    isPresent(Dictionary, -1, "Edward");
}

BOOST_AUTO_TEST_CASE(InsertMany_RemoveAbsent)
{
    Dictionary Dictionary;
    insertTestData(Dictionary);

    Dictionary.remove(6);
    isAbsent(Dictionary, 6);

    isPresent(Dictionary, 22, "Mary");
    isPresent(Dictionary, 4, "Stephen");
    isPresent(Dictionary, 9, "Edward");
    isPresent(Dictionary, 1, "William");
    isPresent(Dictionary, 0, "Harold");
    isPresent(Dictionary, 24, "James");
    isPresent(Dictionary, 26, "Charles");
    isPresent(Dictionary, 19, "Henry");
    isPresent(Dictionary, 31, "Anne");
    isPresent(Dictionary, 23, "Elizabeth");
    isPresent(Dictionary, 37, "Victoria");
    isPresent(Dictionary, 42, "Elizabeth");
    isPresent(Dictionary, -1, "Edward");
}

BOOST_AUTO_TEST_SUITE_END()

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(Copy_Constructor_Tests)

BOOST_AUTO_TEST_CASE(CopyConstructorFullyCopies)
{
    Dictionary dict1;
    insertTestData(dict1);

    Dictionary dict2(dict1);

    isPresent(dict2, 22, "Mary");
    isPresent(dict2, 4, "Stephen");
    isPresent(dict2, 9, "Edward");
    isPresent(dict2, 1, "William");
    isPresent(dict2, 0, "Harold");
    isPresent(dict2, 24, "James");
    isPresent(dict2, 26, "Charles");
    isPresent(dict2, 19, "Henry");
    isPresent(dict2, 31, "Anne");
    isPresent(dict2, 23, "Elizabeth");
    isPresent(dict2, 37, "Victoria");
    isPresent(dict2, 42, "Elizabeth");
    isPresent(dict2, -1, "Edward");
}

BOOST_AUTO_TEST_CASE(CopyConstructorDoesNotDeleteSource)
{
    Dictionary dict1;
    insertTestData(dict1);

    Dictionary dict2(dict1);

    isPresent(dict1, 22, "Mary");
    isPresent(dict1, 4, "Stephen");
    isPresent(dict1, 9, "Edward");
    isPresent(dict1, 1, "William");
    isPresent(dict1, 0, "Harold");
    isPresent(dict1, 24, "James");
    isPresent(dict1, 26, "Charles");
    isPresent(dict1, 19, "Henry");
    isPresent(dict1, 31, "Anne");
    isPresent(dict1, 23, "Elizabeth");
    isPresent(dict1, 37, "Victoria");
    isPresent(dict1, 42, "Elizabeth");
    isPresent(dict1, -1, "Edward");
}

BOOST_AUTO_TEST_CASE(CopyConstructorIsDeep)
{
    Dictionary dict1;
    insertTestData(dict1);

    Dictionary dict2(dict1);

    dict1.insert(2, "William");
    isPresent(dict1, 2, "William");
    isAbsent(dict2, 2);

    dict2.insert(3, "Henry");
    isPresent(dict2, 3, "Henry");
    isAbsent(dict1, 3);

    dict1.remove(24);
    isAbsent(dict1, 24);
    isPresent(dict2, 24, "James");

    dict2.remove(26);
    isAbsent(dict2, 26);
    isPresent(dict1, 26, "Charles");
}

BOOST_AUTO_TEST_SUITE_END()

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(Move_Constructor_Tests)

BOOST_AUTO_TEST_CASE(MoveConstructorFullyMoves)
{
    Dictionary dict1;
    insertTestData(dict1);

    Dictionary dict2(std::move(dict1));

    isPresent(dict2, 22, "Mary");
    isPresent(dict2, 4, "Stephen");
    isPresent(dict2, 9, "Edward");
    isPresent(dict2, 1, "William");
    isPresent(dict2, 0, "Harold");
    isPresent(dict2, 24, "James");
    isPresent(dict2, 26, "Charles");
    isPresent(dict2, 19, "Henry");
    isPresent(dict2, 31, "Anne");
    isPresent(dict2, 23, "Elizabeth");
    isPresent(dict2, 37, "Victoria");
    isPresent(dict2, 42, "Elizabeth");
    isPresent(dict2, -1, "Edward");
}

BOOST_AUTO_TEST_CASE(MoveConstructorSteals)
{
    Dictionary* dictPtr;
    {
        Dictionary dict1;
        insertTestData(dict1);

        dictPtr = new Dictionary(std::move(dict1));

        isAbsent(dict1, 22);
        isAbsent(dict1, 4);
        isAbsent(dict1, 9);
        isAbsent(dict1, 1);
        isAbsent(dict1, 0);
        isAbsent(dict1, 24);
        isAbsent(dict1, 26);
        isAbsent(dict1, 19);
        isAbsent(dict1, 31);
        isAbsent(dict1, 23);
        isAbsent(dict1, 37);
        isAbsent(dict1, 42);
        isAbsent(dict1, -1);

        // dict1 gets deleted here
    }

    isPresent(*dictPtr, 22, "Mary");
    isPresent(*dictPtr, 4, "Stephen");
    isPresent(*dictPtr, 9, "Edward");
    isPresent(*dictPtr, 1, "William");
    isPresent(*dictPtr, 0, "Harold");
    isPresent(*dictPtr, 24, "James");
    isPresent(*dictPtr, 26, "Charles");
    isPresent(*dictPtr, 19, "Henry");
    isPresent(*dictPtr, 31, "Anne");
    isPresent(*dictPtr, 23, "Elizabeth");
    isPresent(*dictPtr, 37, "Victoria");
    isPresent(*dictPtr, 42, "Elizabeth");
    isPresent(*dictPtr, -1, "Edward");

    delete dictPtr;
}

BOOST_AUTO_TEST_SUITE_END()

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(Copy_Assignment_Tests)

BOOST_AUTO_TEST_CASE(CopyAssignmentFullyCopies)
{
    Dictionary dict1;
    insertTestData(dict1);

    Dictionary dict2;
    dict2 = dict1;

    isPresent(dict2, 22, "Mary");
    isPresent(dict2, 4, "Stephen");
    isPresent(dict2, 9, "Edward");
    isPresent(dict2, 1, "William");
    isPresent(dict2, 0, "Harold");
    isPresent(dict2, 24, "James");
    isPresent(dict2, 26, "Charles");
    isPresent(dict2, 19, "Henry");
    isPresent(dict2, 31, "Anne");
    isPresent(dict2, 23, "Elizabeth");
    isPresent(dict2, 37, "Victoria");
    isPresent(dict2, 42, "Elizabeth");
    isPresent(dict2, -1, "Edward");
}

BOOST_AUTO_TEST_CASE(CopyAssignmentOverwrites)
{
    Dictionary dict1;
    insertTestData(dict1);

    Dictionary dict2;
    dict2.insert(22, "Jane");
    dict2.insert(2, "William");

    dict1 = dict2;

    isAbsent(dict1, 4);
    isAbsent(dict1, 9);
    isAbsent(dict1, 1);
    isAbsent(dict1, 0);
    isAbsent(dict1, 24);
    isAbsent(dict1, 26);
    isAbsent(dict1, 19);
    isAbsent(dict1, 31);
    isAbsent(dict1, 23);
    isAbsent(dict1, 37);
    isAbsent(dict1, 42);
    isAbsent(dict1, -1);

    isPresent(dict1, 2, "William");
    isPresent(dict1, 22, "Jane");
}

BOOST_AUTO_TEST_CASE(CopyAssignmentDoesNotReverseCopy)
{
    Dictionary dict1;
    insertTestData(dict1);

    Dictionary dict2;

    dict2.insert(22, "Jane");
    dict2.insert(2, "William");

    dict2 = dict1;

    isAbsent(dict1, 2);
}

BOOST_AUTO_TEST_CASE(CopyAssignmentIsDeep)
{
    Dictionary dict1;
    insertTestData(dict1);

    Dictionary dict2;
    dict2 = dict1;

    dict1.insert(2, "William");
    isPresent(dict1, 2, "William");
    isAbsent(dict2, 2);

    dict2.insert(3, "Henry");
    isPresent(dict2, 3, "Henry");
    isAbsent(dict1, 3);

    dict1.remove(24);
    isAbsent(dict1, 24);
    isPresent(dict2, 24, "James");

    dict2.remove(26);
    isAbsent(dict2, 26);
    isPresent(dict1, 26, "Charles");
}

BOOST_AUTO_TEST_CASE(CopySelfAssignment)
{
    Dictionary Dictionary;
    insertTestData(Dictionary);

    Dictionary = Dictionary;
    isPresent(Dictionary, 24, "James");
    isPresent(Dictionary, 26, "Charles");
    isAbsent(Dictionary, 2);
}

BOOST_AUTO_TEST_SUITE_END()

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(Move_Assignment_Tests)

BOOST_AUTO_TEST_CASE(MoveAssignmentFullyMoves)
{
    Dictionary dict1;
    insertTestData(dict1);

    Dictionary dict2;
    dict2 = std::move(dict1);

    isPresent(dict2, 22, "Mary");
    isPresent(dict2, 4, "Stephen");
    isPresent(dict2, 9, "Edward");
    isPresent(dict2, 1, "William");
    isPresent(dict2, 0, "Harold");
    isPresent(dict2, 24, "James");
    isPresent(dict2, 26, "Charles");
    isPresent(dict2, 19, "Henry");
    isPresent(dict2, 31, "Anne");
    isPresent(dict2, 23, "Elizabeth");
    isPresent(dict2, 37, "Victoria");
    isPresent(dict2, 42, "Elizabeth");
    isPresent(dict2, -1, "Edward");
}

BOOST_AUTO_TEST_CASE(MoveAssignmentSteals)
{
    Dictionary dict1, dict2;
    insertTestData(dict1);

    dict2 = std::move(dict1);

    isAbsent(dict1, 22);
    isAbsent(dict1, 4);
    isAbsent(dict1, 9);
    isAbsent(dict1, 1);
    isAbsent(dict1, 0);
    isAbsent(dict1, 24);
    isAbsent(dict1, 26);
    isAbsent(dict1, 19);
    isAbsent(dict1, 31);
    isAbsent(dict1, 23);
    isAbsent(dict1, 37);
    isAbsent(dict1, 42);
    isAbsent(dict1, -1);
}

BOOST_AUTO_TEST_CASE(MoveAssignmentOverwrites)
{
    Dictionary dict1;
    insertTestData(dict1);

    Dictionary dict2;
    dict2.insert(22, "Jane");
    dict2.insert(2, "William");

    dict1 = std::move(dict2);

    isAbsent(dict1, 4);
    isAbsent(dict1, 9);
    isAbsent(dict1, 1);
    isAbsent(dict1, 0);
    isAbsent(dict1, 24);
    isAbsent(dict1, 26);
    isAbsent(dict1, 19);
    isAbsent(dict1, 31);
    isAbsent(dict1, 23);
    isAbsent(dict1, 37);
    isAbsent(dict1, 42);
    isAbsent(dict1, -1);

    isPresent(dict1, 2, "William");
}

BOOST_AUTO_TEST_CASE(MoveAssignmentIsNotShallowCopy)
{
    Dictionary dict1;
    insertTestData(dict1);

    Dictionary dict2;
    dict2 = std::move(dict1);

    dict1.remove(19);
    dict1.remove(23);
    isPresent(dict2, 19, "Henry");
    isPresent(dict2, 23, "Elizabeth");
}

BOOST_AUTO_TEST_CASE(MoveSelfAssignment)
{
    Dictionary Dictionary;
    insertTestData(Dictionary);

    Dictionary = std::move(Dictionary);

    isPresent(Dictionary, 24, "James");
    isPresent(Dictionary, 26, "Charles");
}

BOOST_AUTO_TEST_SUITE_END()

////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
//
//BOOST_AUTO_TEST_SUITE(RemoveIf_Tests)
//
//BOOST_AUTO_TEST_CASE(RemoveNone)
//{
//    Dictionary Dictionary;
//    insertTestData(Dictionary);
//
//    Dictionary.removeIf([](int k) {return false;});
//
//    isPresent(Dictionary, 22, "Mary");
//    isPresent(Dictionary, 4, "Stephen");
//    isPresent(Dictionary, 9, "Edward");
//    isPresent(Dictionary, 1, "William");
//    isPresent(Dictionary, 0, "Harold");
//    isPresent(Dictionary, 24, "James");
//    isPresent(Dictionary, 26, "Charles");
//    isPresent(Dictionary, 19, "Henry");
//    isPresent(Dictionary, 31, "Anne");
//    isPresent(Dictionary, 23, "Elizabeth");
//    isPresent(Dictionary, 37, "Victoria");
//    isPresent(Dictionary, 42, "Elizabeth");
//    isPresent(Dictionary, -1, "Edward");
//}
//
//BOOST_AUTO_TEST_CASE(RemoveAll)
//{
//    Dictionary Dictionary;
//    insertTestData(Dictionary);
//
//    Dictionary.removeIf([](int k) {return true;});
//
//    isAbsent(Dictionary, 22);
//    isAbsent(Dictionary, 4);
//    isAbsent(Dictionary, 9);
//    isAbsent(Dictionary, 1);
//    isAbsent(Dictionary, 0);
//    isAbsent(Dictionary, 24);
//    isAbsent(Dictionary, 26);
//    isAbsent(Dictionary, 19);
//    isAbsent(Dictionary, 31);
//    isAbsent(Dictionary, 23);
//    isAbsent(Dictionary, 37);
//    isAbsent(Dictionary, 42);
//    isAbsent(Dictionary, -1);
//}
//
//BOOST_AUTO_TEST_CASE(RemoveOddKeys)
//{
//    Dictionary Dictionary;
//    insertTestData(Dictionary);
//
//    Dictionary.removeIf([](int k) {return k % 2 != 0;});
//
//    isPresent(Dictionary, 22, "Mary");
//    isPresent(Dictionary, 4, "Stephen");
//    isPresent(Dictionary, 0, "Harold");
//    isPresent(Dictionary, 24, "James");
//    isPresent(Dictionary, 26, "Charles");
//    isPresent(Dictionary, 42, "Elizabeth");
//
//    isAbsent(Dictionary, 9);
//    isAbsent(Dictionary, 1);
//    isAbsent(Dictionary, 19);
//    isAbsent(Dictionary, 31);
//    isAbsent(Dictionary, 23);
//    isAbsent(Dictionary, 37);
//    isAbsent(Dictionary, -1);
//}
//
//BOOST_AUTO_TEST_SUITE_END()
//
*/
//////////////////////////////////////////////////////////////////////////////////
