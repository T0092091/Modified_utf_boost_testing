#include <ostream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <boost/test/unit_test.hpp>

#include "route.h"

using namespace GPS;
//TEST SUIT
BOOST_AUTO_TEST_SUITE( Position_of_Data )

const double elip= 0.31;
const double percent = 0.1;

/*TEST CASE FOR FINDING LENGTH OF NAME*/
BOOST_AUTO_TEST_SUITE( Length_of_name)
{
	DataLength  length = { "32.31","S","10.03","N","5710"}};
    Position pos = positionFromSentenceData(sentenceData);
    BOOST_CHECK_lONGITUDE(longitude() , DIST("107.03") , percent );
   
}

/*CHECKING WEATHER THE ACTUAL NAME AND MISSING ELEMENTS THAT USER ENTER IF ANY*/
BOOST_AUTO_TEST_CASE( checking_the_missing_elements )
{
   const std::string DATA;
   DATA ="<gpx><rte><rtept lat=\"0\" lon=\"0\"></rtept></rte></gpx>";

   Route route = Route(DATA, isFileName);
   BOOST_CHECK_EQUAL( route.name(), defaultName );
}



/*Checking weather the name  is greater than zero*/
BOOST_AUTO_TEST_CASE( check_name_length )
{
   BOOST_CHECK_length( check_length_greater_than_zero(check_name_length) );
}
BOOST_AUTO_TEST_SUITE_END()

//NEW TEST SUIT

BOOST_AUTO_TEST_SUITE( NAMING_cONVENTION_OF_DATA )

/*Checking weather the router name is zero*/
BOOST_AUTO_TEST_CASE( check_name_length )
{
   BOOST_CHECK_isequal( check_length_greater_isequal_zero(check_name_legth,0) );
}

/*Checking weather the name hold spaces*/
BOOST_AUTO_TEST_CASE(check_name_spaces)
{
   BOOST_CHECK_SpacesinName( check_spaces_in_name(check_name_spaces) );
}

/*Checking weather the name hold spaces*/
BOOST_AUTO_TEST_CASE(check_route_name)
{
   BOOST_CHECK_RouteName( check_name_of_route(check_route_name,"ALexx") );
}



BOOST_AUTO_TEST_SUITE_END()
