// nasty nasty hacks so can include and run student file with a main()
#define main studentmain
#include <lab_age.cpp>
#undef main
template<typename R, typename I, typename C>
R student_main_runner( R(*func)(I, C) ) { return func(0,{}); }
template<typename R>
R student_main_runner( R(*func)() ) { return func(); }
int student_main_runner(){ return student_main_runner(studentmain); }
// end of nasty nasty hacks

#include <catch.hpp>
#include <captureio.h>

#include <sstream>
#include <string>

SCENARIO( "Testing legitimate ages", "[age][legit]" )
{
    auto get_output = []( const int a ) -> std::string
    {
        CaptureStream cs( std::cout );
        InjectStream is( std::cin );

        cs.capture();
        is.capture();

        is << a << "\n";
        student_main_runner();

        cs.release();
        is.release();

        return cs.str();
    };

    WHEN( "Age is 4" )
    {
        auto response = get_output( 4 );
        REQUIRE_THAT( response, Catch::Contains( "You're a baby" ) );
        REQUIRE_THAT( response, !Catch::Contains( "You're a teenager" ) );
        REQUIRE_THAT( response, !Catch::Contains( "You can drive" ) );
        REQUIRE_THAT( response, !Catch::Contains( "You can vote" ) );
    }

    WHEN( "Age is 5" )
    {
        auto response = get_output( 5 );
        REQUIRE_THAT( response, !Catch::Contains( "You're a baby" ) );
        REQUIRE_THAT( response, !Catch::Contains( "You're a teenager" ) );
        REQUIRE_THAT( response, !Catch::Contains( "You can drive" ) );
        REQUIRE_THAT( response, !Catch::Contains( "You can vote" ) );
    }

    WHEN( "Age is 12" )
    {
        auto response = get_output( 12 );
        REQUIRE_THAT( response, !Catch::Contains( "You're a baby" ) );
        REQUIRE_THAT( response, !Catch::Contains( "You're a teenager" ) );
        REQUIRE_THAT( response, !Catch::Contains( "You can drive" ) );
        REQUIRE_THAT( response, !Catch::Contains( "You can vote" ) );
    }

    WHEN( "Age is 13" )
    {
        auto response = get_output( 13 );
        REQUIRE_THAT( response, !Catch::Contains( "You're a baby" ) );
        REQUIRE_THAT( response, Catch::Contains( "You're a teenager" ) );
        REQUIRE_THAT( response, !Catch::Contains( "You can drive" ) );
        REQUIRE_THAT( response, !Catch::Contains( "You can vote" ) );
    }

    WHEN( "Age is 15" )
    {
        auto response = get_output( 15 );
        REQUIRE_THAT( response, !Catch::Contains( "You're a baby" ) );
        REQUIRE_THAT( response, Catch::Contains( "You're a teenager" ) );
        REQUIRE_THAT( response, !Catch::Contains( "You can drive" ) );
        REQUIRE_THAT( response, !Catch::Contains( "You can vote" ) );    
    }

    WHEN( "Age is 16" )
    {
        auto response = get_output( 16 );
        REQUIRE_THAT( response, !Catch::Contains( "You're a baby" ) );
        REQUIRE_THAT( response, Catch::Contains( "You're a teenager" ) );
        REQUIRE_THAT( response, Catch::Contains( "You can drive" ) );
        REQUIRE_THAT( response, !Catch::Contains( "You can vote" ) );
    }

    WHEN( "Age is 18" )
    {
        auto response = get_output( 18 );
        REQUIRE_THAT( response, !Catch::Contains( "You're a baby" ) );
        REQUIRE_THAT( response, Catch::Contains( "You're a teenager" ) );
        REQUIRE_THAT( response, Catch::Contains( "You can drive" ) );
        REQUIRE_THAT( response, Catch::Contains( "You can vote" ) );
    }

    WHEN( "Age is 19" )
    {
        auto response = get_output( 19 );
        REQUIRE_THAT( response, !Catch::Contains( "You're a baby" ) );
        REQUIRE_THAT( response, !Catch::Contains( "You're a teenager" ) );
        REQUIRE_THAT( response, Catch::Contains( "You can drive" ) );
        REQUIRE_THAT( response, Catch::Contains( "You can vote" ) );    
    }

    WHEN( "Age is 101" )
    {
        auto response = get_output( 101 );
        REQUIRE_THAT( response, !Catch::Contains( "You're a baby" ) );
        REQUIRE_THAT( response, !Catch::Contains( "You're a teenager" ) );
        REQUIRE_THAT( response, Catch::Contains( "You can drive" ) );
        REQUIRE_THAT( response, Catch::Contains( "You can vote" ) );    
    }    
}
