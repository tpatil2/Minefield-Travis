/**
 * Unit Tests for Field class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "Field.h"

class FieldTest : public ::testing::Test
{
	protected:
		FieldTest(){}
		virtual ~FieldTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(FieldTest, placeMineInBounds)
{
	Field minefield;

	minefield.placeMine(4,5);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(4,5) );
}

TEST(FieldTest, isSafeEmpty)
{
	Field minefield;

	minefield.placeMine(4,5);
	ASSERT_TRUE( minefield.isSafe(1,1) );
}

TEST(FieldTest, isSafeBoom)
{
	Field minefield;

	minefield.placeMine(4,5);
	ASSERT_FALSE( minefield.isSafe(4,5) );
}

TEST(FieldTest, isSafeOutOfBounds)
{
	Field minefield;

	bool safe;
	safe = minefield.isSafe(-1,11);
	ASSERT_FALSE(safe);
}

TEST(FieldTest, revealAdjacentEmptyAllShown)
{
	Field minefield;

	minefield.revealAdjacent(1,2);
	ASSERT_EQ( EMPTY_SHOWN, minefield.get(0,0) );
	ASSERT_EQ( EMPTY_SHOWN, minefield.get(9,9) );
	ASSERT_EQ( EMPTY_SHOWN, minefield.get(0,9) );
	ASSERT_EQ( EMPTY_SHOWN, minefield.get(9,0) );
	ASSERT_EQ( EMPTY_SHOWN, minefield.get(1,2) );
}




TEST(FieldTest, revealAdjacentFirstColEmpty)
{
	Field minefield;
	minefield.placeMine(2,2);
	minefield.placeMineShown(2,2);
	minefield.revealAdjacent(0,2);

	ASSERT_EQ( EMPTY_SHOWN, minefield.get(3,0));
  ASSERT_EQ( EMPTY_SHOWN, minefield.get(9,9) );
	ASSERT_EQ( EMPTY_SHOWN, minefield.get(0,9) );
	ASSERT_EQ( EMPTY_SHOWN, minefield.get(9,0) );
	ASSERT_EQ( EMPTY_SHOWN, minefield.get(1,2) );

}



TEST(FieldTest, revealAdjacentFirstRowEmpty)
{
	Field minefield;

	for(int y=0; y<10; y++)
		minefield.placeMine(1,y);

	minefield.revealAdjacent(2,0);
	ASSERT_EQ( EMPTY_SHOWN, minefield.get(3,0) );
	ASSERT_EQ( EMPTY_SHOWN, minefield.get(9,9) );
	ASSERT_EQ( EMPTY_HIDDEN, minefield.get(0,0) );
	ASSERT_EQ( MINE_HIDDEN, minefield.get(1,0) );
}

TEST(FieldTest, revealAdjacentFirstColmEmpty){

  Field minefield;

  for(int x=0; x<10; x++)
    minefield.placeMine(x,1);

  minefield.revealAdjacent(0,2);
  ASSERT_EQ( EMPTY_SHOWN, minefield.get(0,3) );
  ASSERT_EQ( EMPTY_SHOWN, minefield.get(9,9) );
  ASSERT_EQ( EMPTY_HIDDEN, minefield.get(0,0) );
  ASSERT_EQ( MINE_HIDDEN, minefield.get(0,1) );


}
