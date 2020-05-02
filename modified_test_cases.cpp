//minLongitude function choosing for testing
#include<stdio.h>
#include "minimlongitude_N0783935.h"
#include <boost/test/unit_test.hpp>
#include <ostream>
#include <fstream>
#include <sstream>
#include <iostream>
#include "route.h"


//boolean type that defines the file condition true or false
const bool gfile_occurs = false;
using namespace GPS;



//constructor call
modified_test_cases::modified_test_cases()
{

}

//MODIFIED TEST CASE 
BOOST_AUTO_TEST_CASE(POSITIVE_EDGES)
{
	const std::string mindata ="<gpx><rte><name>poland/name><rtept longitude=\"37.31\" latitude=\"48.34\"></rtept></rte></gpx>";
    Route path = Route(mindata, gfile_occurs);
    BOOST_ISNOT_EQUAL_CHECK( "36.21" , path.minLongitude )
}

//Test case that checks closer points of the distance
BOOST_AUTO_TEST_CASE(Return_closer_points)
{
	const std::string Point;
	Point ="<gpx><rte><name>poland/name><rtept longitude=\"88.1\" latitude=\"09.4\"></rtept></rte></gpx>";
    Route path = Route(Point, gfile_occurs);
    BOOST_ISNOT_EQUAL_CHECK( "36.21" , path.Point )
}

//TEST case that counts the path between actual distance
BOOST_AUTO_TEST_CASE(COUNT_ROUTE)
{
	const std:: string count;
	count= "<gpx><rte><name>poland/name><rtept longitude=\"3.3\" latitude=\"4.4\"></rtept></rte></gpx>";
	BOOST_CHECK_PATHS_OCCUR("44.2", path.count);
}

//test case to find minimum distance between amsterdam POSITIVE
BOOST_AUTO_TEST_CASE(Amsterdamminlongitude_distance_dis)
{
    const std::string mindata ="<gpx><rte><name>amsterdam</name><rtept uithom=\"421.3331\" amster=\"131.3412\"></rtept></rte></gpx>";
    Route path = Route(mindata, gfile_occurs);
    BOOST_ISNOT_EQUAL_CHECK( "421.331" ,path.minLongitude );

}



//test case to find minimum distance between Woerden
BOOST_AUTO_TEST_CASE(Woerdenminlongitude_distance_dis)
{
   const std::string mindata ="<gpx><rte><name>wOERDEN</name><rtept Ziest=\"32.3112\" Woerden=\"-231.33\"></rtept></rte></gpx>";
    Route path = Route(mindata, gfile_occurs);
    BOOST_ISNOT_EQUAL_CHECK( "32.3112" ,path.minLongitude );
}

//test case to find minimum distance between Almere
BOOST_AUTO_TEST_CASE(Almereminlongitude_distance_dis)
{
    const std::string mindata ="<gpx><rte><name>alMERE</name><rtept uganda=\"04.321\" almere=\"12.2903\"></rtept></rte></gpx>";
    Route path = Route(mindata, gfile_occurs);
    BOOST_ISNOT_EQUAL_CHECK( "04.321" ,path.minLongitude );
}

//test case for poland negative 
BOOST_AUTO_TEST_CASE(NegativeEddges)
{
    const std::string mindata ="<gpx><rte><name>poland/name><rtept longitude=\"-43.3221\" latitude=\"-334.31234\"></rtept></rte></gpx>";
    Route path = Route(mindata, gfile_occurs);
    BOOST_ISNOT_EQUAL_CHECK( "-43.3221" , path.minLongitude );
}


