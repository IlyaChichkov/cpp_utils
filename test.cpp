
#include <iostream>
#include <cstdint>
#include "utils.hpp"
#include "redmath.hpp"
#include "catch2/catch_amalgamated.hpp"

using namespace Catch;

using namespace f_io;
using namespace str_op;
using namespace math_op;
using namespace math_op::geom;

using string = std::string;

TEST_CASE("Read file test", "[text]")
{
    SECTION("Read All")
    {
        REQUIRE(string(ReadFileAll("poem.txt")) == "Home chapter arrived moreover estimating concealed appear on deal smart play certainly properly drawings loud hour boisterous.\nLasting possession girl judgment waited mistress estimable vicinity frequently year. \nBachelor behaved lasting humoured find around uncommonly offices. Am ourselves mistress moment. Hardly or soon wanted weather. Style game parlors view quiet asked \nsettled plate farther party temper rapturous. \n\nEarly between insipidity event wisdom first carriage her fully within led home agreeable grave. Charmed limited any suitable attempted estate. \nPolite pleased design indeed projecting explained fifteen linen feet ample repair resolve friendly. Without morning although feeling life thirty misery sweetness\nmany general whole around. Feel there order society against friendship valley. \n\nMoments great unpleasing thoroughly eldest denote wondered uneasy roused entreaties kindness eldest missed. Ourselves material building sense itself \nconsulted songs five resolved smiling listening sake tended estimable  carriage. Marked distant mistaken. Court marianne great dejection downs projecting advanced past shew remainder horrible. Moonlight strictly for moreover learning dashwood subject waited. \nForming worth suppose suitable engage secure zealously side views. Itself delightful age plenty object peculiar enquire attachment engage desire highest remain. \nWitty allow spoil give. Bringing excuse feebly diverted wishes. Eyes sing balls wicket betrayed entered recurred instantly company some add. ");
    }
    SECTION("Read Line")
    {
        REQUIRE(string(ReadFileLine("poem.txt", 0)) == "Home chapter arrived moreover estimating concealed appear on deal smart play certainly properly drawings loud hour boisterous.\n");
    }
    SECTION("Read Lines")
    {
        REQUIRE(string(ReadFileLines("poem.txt", 0, 0)) == "Home chapter arrived moreover estimating concealed appear on deal smart play certainly properly drawings loud hour boisterous.\n");
    }
    SECTION("Read chars")
    {
        REQUIRE(string(ReadFileChars("poem.txt", -4, 3)) == "");
        REQUIRE(string(ReadFileChars("poem.txt", 4, -3)) == "");
        REQUIRE(string(ReadFileChars("poem.txt", -4, -3)) == "");
        REQUIRE(string(ReadFileChars("poem.txt", 0, 3)) == "Home");
        REQUIRE(string(ReadFileChars("poem.txt", 0, 11)) == "Home chapter");
        REQUIRE_FALSE(string(ReadFileChars("poem.txt", 0, 11)) == "none");
    }
    SECTION("Write char")
    {
        REQUIRE(WriteChar("write.txt", "a") == 1);
        REQUIRE(string(ReadFileChar("write.txt", 0)) == "a");

        REQUIRE(WriteChar("write.txt", "5") == 1);
        REQUIRE(string(ReadFileChar("write.txt", 0)) == "5");

        REQUIRE(WriteChar("write.txt", "@fs") == 1);
        REQUIRE(string(ReadFileAll("write.txt")) == "@");
    }
    SECTION("Write chars")
    {
        REQUIRE(WriteChars("write.txt", "a743", 2) == 1);
        REQUIRE(string(ReadFileAll("write.txt")) == "a7");

        REQUIRE(WriteChars("write.txt", "5", 5) == 1);
        REQUIRE(string(ReadFileAll("write.txt")) == "5");

        REQUIRE(WriteChars("write.txt", "@fst", 4) == 1);
        REQUIRE(string(ReadFileAll("write.txt")) == "@fst");

        REQUIRE(WriteChars("write.txt", "@fst", 0) == 1);
        REQUIRE(string(ReadFileAll("write.txt")) == "");
    }
}

TEST_CASE("Basic math")
{
    SECTION("Factorial")
    {
        REQUIRE(GetFactorial(1) == 1);
        REQUIRE(GetFactorial(2) == 2);
        REQUIRE(GetFactorial(3) == 6);
        REQUIRE(GetFactorial(10) == 3628800);
    }
}

TEST_CASE("Area", "[double]") {
    SECTION("Circle")
    {
        REQUIRE(area_of_circle(2) == 12.566);
        REQUIRE(area_of_circle(4) == 50.265);
        REQUIRE(area_of_circle(0) == 0);
        REQUIRE(area_of_circle(-2) == 12.566);
        REQUIRE(area_of_circle(2.5) == 19.635);
        REQUIRE(area_of_circle(8798) == 243174363.599);
        REQUIRE(area_of_circle(6783.658) == 144569860.562);
    }
    SECTION("Poly in Circle")
    {
        // TODO: Write tests
    }
}

TEST_CASE("Vector2 operations", "[Vector2]") {
    Vector2 v1(2.0, 3.0);
    Vector2 v2(4.0, 5.0);
    Vector2 v3(1.0, 2.0);
    
    SECTION("Operator *") {
        Vector2 result = *(v1 * v2);
        REQUIRE(result.x == Approx(8.0));
        REQUIRE(result.y == Approx(15.0));
    }

    SECTION("Operator *=") {
        v1 *= 2.0;
        REQUIRE(v1.x == Approx(4.0));
        REQUIRE(v1.y == Approx(6.0));
    }

    SECTION("Operator /") {
        Vector2 result = *(v1 / v3);
        REQUIRE(result.x == Approx(2.0));
        REQUIRE(result.y == Approx(1.5));
    }

    SECTION("Operator /=") {
        v1 /= 2.0;
        REQUIRE(v1.x == Approx(1.0));
        REQUIRE(v1.y == Approx(1.5));
    }

    SECTION("Operator +") {
        Vector2 result = *(v1 - v3);
        REQUIRE(result.x == Approx(1.0));
        REQUIRE(result.y == Approx(1.0));
    }

    SECTION("Operator -") {
        Vector2 result = *(v1 + v3);
        REQUIRE(result.x == Approx(3.0));
        REQUIRE(result.y == Approx(5.0));
    }
}

TEST_CASE("Vector2 constants", "[Vector2]") {
    SECTION("Zero constant") {
        REQUIRE(Vector2::Zero.x == Approx(0.0));
        REQUIRE(Vector2::Zero.y == Approx(0.0));
    }
    SECTION("One constant") {
        REQUIRE(Vector2::One.x == Approx(1.0));
        REQUIRE(Vector2::One.y == Approx(1.0));
    }
    SECTION("Left constant") {
        REQUIRE(Vector2::Left.x == Approx(-1.0));
        REQUIRE(Vector2::Left.y == Approx(0.0));
    }
    SECTION("Right constant") {
        REQUIRE(Vector2::Right.x == Approx(1.0));
        REQUIRE(Vector2::Right.y == Approx(0.0));
    }
    SECTION("Down constant") {
        REQUIRE(Vector2::Down.x == Approx(0.0));
        REQUIRE(Vector2::Down.y == Approx(-1.0));
    }
    SECTION("Up constant") {
        REQUIRE(Vector2::Up.x == Approx(0.0));
        REQUIRE(Vector2::Up.y == Approx(1.0));
    }
}

TEST_CASE("Vector2 rotation", "[Vector2]") {
    Vector2 v(1.0, 0.0);

    SECTION("Rotate by angle 90") {
        v.Rotate(90.0);
        REQUIRE(v.x == Approx(0.0));
        REQUIRE(v.y == Approx(1.0));
        v.Rotate(90.0);
        REQUIRE(v.x == Approx(-1.0));
        REQUIRE(v.y == Approx(0.0));
        v.Rotate(180.0);
        REQUIRE(v.x == Approx(1.0));
        REQUIRE(v.y == Approx(0.0));
    }
    SECTION("Rotate by angle 45") {
        v.Rotate(45.0);
        REQUIRE(v.x == Approx(0.71));
        REQUIRE(v.y == Approx(0.71));
    }

    // ... add more test cases for rotation
}

TEST_CASE("Vector2 size", "[Vector2]") {
    Vector2 v1(10.0, 0.0);
    Vector2 v2(4.0, 4.0);

    SECTION("Get size") {
        REQUIRE(v1.Size() == Approx(10.0));
    }

    SECTION("Get size") {
        REQUIRE(v2.Size() == Approx(5.6568));
    }
}

TEST_CASE("Vector2 normalization", "[Vector2]") {
    Vector2 v(10.0, 0.0);

    SECTION("Rotate by angle 90") {
        v.Normalize();
        REQUIRE(v.x == Approx(1.0));
        REQUIRE(v.y == Approx(0.0));
    }
}

TEST_CASE("Line operations", "[Line]") {
    Line l1(1, 1, 2, 2);

    double points[4] = {4, 4, 2, 2};
    Line l2(points);

    double p1[2] = {-2, 1};
    double p2[2] = {1, 9};
    Line l3(p1, p2);

    SECTION("Rotate by angle 90") {
        REQUIRE(l1.from.x == Approx(1.0));
        REQUIRE(l1.from.y == Approx(1.0));

        REQUIRE(l2.from.x == Approx(4.0));
        REQUIRE(l2.from.y == Approx(4.0));

        REQUIRE(l3.from.x == Approx(-2.0));
        REQUIRE(l3.from.y == Approx(1.0));
    }
}

TEST_CASE("Line size", "[Line]") {
    Line l1(0, 0, 15, 0);

    SECTION("Rotate by angle 90") {
        REQUIRE(l1.Size() == Approx(15.0));
    }
}

TEST_CASE("Line rotate", "[Line]") {
    
}

TEST_CASE("Line get center", "[Line]") {
    Line l1(0, 0, 15, 0);
    Line l2(-3, 6, 5, -1);

    SECTION("Rotate by angle 90") {
        REQUIRE(l1.GetCenter().x == Approx(7.5));
        REQUIRE(l2.GetCenter().x == Approx(1.0));
    }
}

TEST_CASE("Line normalize", "[Line]") {
    
}

TEST_CASE("Line direction", "[Line]") {
    
}

TEST_CASE("Line move", "[Line]") {
    
}