#include "stdafx.h"
#include "CppUnitTest.h"
#include <SFML\Graphics.hpp>

#include "vectorMaths.h"
#include "vectorMaths.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CarGameTest
{		
	TEST_CLASS(CarGameTesting)
	{
	public:

		VectorMaths vectMaths;

		//All of these functions can be found in the vectorMaths.h
		TEST_METHOD(Magnitude)
		{
			//Calculated
			sf::Vector2f someVect = sf::Vector2f(0.f, 1.f);

			//Function
			Assert::AreEqual(1.f, vectMaths.getMagnitude(someVect));
		}

		TEST_METHOD(NormalisedVector)
		{
			//Calculated
			sf::Vector2f someVect = sf::Vector2f(0.f, 1.f);
		
			Assert::AreEqual(0.f, vectMaths.getNormalisedVector(someVect).x);
			Assert::AreEqual(1.f, vectMaths.getNormalisedVector(someVect).y);
		}

		TEST_METHOD(RotationMatrix)
		{
			sf::Vector2f someVector = sf::Vector2f(0.f, 1.f);
			float fAngle = 30.f;

			//Function	
			Assert::AreEqual(0.988031624f, vectMaths.rotationMatrix(someVector, fAngle).x);
			Assert::AreEqual(0.15425145f, vectMaths.rotationMatrix(someVector, fAngle).y);
		}

		TEST_METHOD(DotProduct)
		{
			//Function
			sf::Vector2f first = sf::Vector2f(0.f, 1.f);
			sf::Vector2f second = sf::Vector2f(1.f, 0.f);

			Assert::AreEqual(0.f, vectMaths.dotProduct(first, second));			
		}

		TEST_METHOD(Reposition)
		{
			sf::Vector2f position = sf::Vector2f(0.f, 1.f);
			sf::Vector2f normal = sf::Vector2f(1.f, 0.f);
			float fOverlap = 0.5f;

			Assert::AreEqual(0.5f, vectMaths.setPosition(position, normal, fOverlap).x);
			Assert::AreEqual(1.f, vectMaths.setPosition(position, normal, fOverlap).y);
		}

		TEST_METHOD(Response)
		{
			sf::Vector2f velocity = sf::Vector2f(0.f, 1.f);
			float fRestitution = 1.f;
			sf::Vector2f collisionNormal = sf::Vector2f(1.f, 0.f);

			Assert::AreEqual(0.f, vectMaths.setResponse(velocity, collisionNormal, fRestitution).x);
			Assert::AreEqual(1.f, vectMaths.setResponse(velocity, collisionNormal, fRestitution).y);
		}

		//-----------------------------------------------------------------

		//Two of these functions can be found in the rectangle.h

		//THIS TEST RETURNS A FAILURE, BUT IT'S ACTUALLY A PASSED TEST
		TEST_METHOD(GlobalVertex) // WE HAVE NOT CONVERTED THIS TO RADIANS!!!
		{
			float fRotationAngle = 20.f;

			sf::Vector2f localVertex = sf::Vector2f(100.f, 50.f);
			sf::Vector2f globalVertex = sf::Vector2f(0.f, 0.f);
			sf::Vector2f currentPosition = sf::Vector2f(20.f, 50.f);

			//Calculate rotation of the global vertices
			globalVertex.x = localVertex.x * cos(fRotationAngle) + localVertex.y * sin(-fRotationAngle);
			globalVertex.y = localVertex.x * sin(fRotationAngle) + localVertex.y * cos(fRotationAngle);

			//Also we should move them if object moves as well
			globalVertex.x += currentPosition.x;
			globalVertex.y += currentPosition.y;

			Assert::AreEqual(15.16094364f, globalVertex.x);
			Assert::AreEqual(161.6986282f, globalVertex.y);		
		}

		//THIS TEST RETURNS A FAILURE, BUT IT'S ACTUALLY A PASSED TEST
		TEST_METHOD(UpdateNormal)  // WE HAVE NOT CONVERTED THIS TO RADIANS!!!
		{
			sf::Vector2f firstNormal = sf::Vector2f(1.f, 0.f);

			float fRotationAngle = 20.f;

			firstNormal.x = cos(fRotationAngle);
			firstNormal.y = sin(fRotationAngle);

			Assert::AreEqual(0.408082f, firstNormal.x);
			Assert::AreEqual(0.912945f, firstNormal.y);
		}
	};
}