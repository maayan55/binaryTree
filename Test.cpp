#include "doctest.h"
#include "sources/BinaryTree.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;
using namespace ariel;

TEST_CASE("root- add or change")
{
  BinaryTree<string> stringT1;
  CHECK_NOTHROW(stringT1.add_root("first"));
  CHECK(*stringT1.begin_postorder() == "first");
  CHECK_NOTHROW(stringT1.add_root("second")); 
  CHECK(*stringT1.begin_postorder() == "second");
  CHECK_NOTHROW(stringT1.add_root("third"));
  CHECK(*stringT1.begin_postorder() == "third");

  BinaryTree<int> intT1;
  CHECK_NOTHROW(intT1.add_root(2));
  CHECK(*intT1.begin_preorder() == 2);
  CHECK_NOTHROW(intT1.add_root(4));
  CHECK(*intT1.begin_preorder() == 4);
}
   
TEST_CASE("left- add or change")
{
  BinaryTree<string> stringT2;
  CHECK_THROWS(stringT2.add_left("hey", "u"));//there isnt a root, should throw
  CHECK_NOTHROW(stringT2.add_root("hello"));
  CHECK_NOTHROW(stringT2.add_left("hello", "world"));
  CHECK(*stringT2.begin_postorder() == "world");
  CHECK_NOTHROW(stringT2.add_left("hello", "there"));
  CHECK(*stringT2.begin_postorder() == "there");
}

TEST_CASE("right- add or change")
{
  BinaryTree<int> intT2;
  CHECK_NOTHROW(intT2.add_root(10));
  CHECK_NOTHROW(intT2.add_right(10, 9));
  CHECK_THROWS(intT2.add_right(1, 3));//no such key 1, should throw
  CHECK_NOTHROW(intT2.add_right(10, 8));
  CHECK_NOTHROW(intT2.add_right(8, 2));
}

TEST_CASE("full trees")
{
    BinaryTree<int> intT3;
    CHECK_NOTHROW(intT3.add_root(100));
    CHECK_NOTHROW(intT3.add_left(100, 99));
    CHECK_NOTHROW(intT3.add_left(99, 98));
    CHECK_NOTHROW(intT3.add_right(100, 101));
    CHECK_THROWS(intT3.add_right(5,5));//no such key 5, should throw
    /*should be  
    98->99->100<-101
    */

    BinaryTree<int> intT4;
    CHECK_NOTHROW(intT4.add_root(7));
    CHECK_NOTHROW(intT4.add_right(7, 8));
    CHECK_NOTHROW(intT4.add_right(8, 9));
    CHECK_NOTHROW(intT4.add_right(9, 10));
    /* should be
    7->8->9->10
    */

    BinaryTree<string> stringT3;
    CHECK_NOTHROW(stringT3.add_root("c"));
    CHECK_NOTHROW(stringT3.add_left("c", "p"));
    CHECK_NOTHROW(stringT3.add_right("c", "p"));
    /* should be
    p->c<-p
    */
    CHECK_NOTHROW(stringT3.add_left("c", "+"));
    CHECK_NOTHROW(stringT3.add_right("c", "+"));
    /* should be
    +->c<-+
    */

    

}
