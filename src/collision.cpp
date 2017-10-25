#include "collision.h"

//!< Initializer
Collision::Collision()
{
	bCollision = false;
	bCollisionAxisTest[0] = false;

	//Let's populate a vector with 4 empty elements
	normalsCombined.resize(4);
	overlaps.resize(4);
	reverse.resize(4);
}

//!< Update normals of combined OBB rectangles
void Collision::UpdateCombinedNormals(std::vector<sf::Vector2f>& first, std::vector<sf::Vector2f>& other)
{
	//Update normals
	normalsCombined[0] = first[0];
	normalsCombined[1] = first[1];
	normalsCombined[2] = other[0];
	normalsCombined[3] = other[1];
}

//!< Projections of OBB rectangle onto axis
void Collision::CheckVertices(sf::Vertex& vertex, sf::Vector2f& normal, float& fMin, float& fMax)
{
	//Projection onto axis
	float fProjectToAxis = vertex.position.x * normal.x + vertex.position.y * normal.y;

	//Getting min and max numbers
	float newMin = fProjectToAxis;
	float newMax = fProjectToAxis;

	//Rule to apply min and max
	if (newMin < fMin) fMin = newMin;
	if (newMax > fMax) fMax = newMax;
}

//!< Collision test AABB-AABB
bool Collision::Intersects(Rectangle &first, Rectangle &other, std::string sAABB)
{
	//Projecting points onto axis 
	for (int iAxisTestNum = 0; iAxisTestNum < 2; iAxisTestNum++)
	{
		//Reset min and max
		float fMin = 99999;
		float fMax = -99999;
		float fMinOther = 99999;
		float fMaxOther = -99999;

		//Checking vertices on the first rectangle
		for (int iVertexNum = 0; iVertexNum < 4; iVertexNum++) CheckVertices(first.getGlobalVertices()[iVertexNum], other.getNormals()[iAxisTestNum], fMin, fMax);

		//Checking vertices on the second rectangle
		for (int iVertexNum = 0; iVertexNum < 4; iVertexNum++) CheckVertices(other.getGlobalVertices()[iVertexNum], other.getNormals()[iAxisTestNum], fMinOther, fMaxOther);

		// Check the min and max for each box and check for intersection
		if (fMinOther - fMax < 0 && fMin - fMaxOther < 0)
		{
			float fSmallOverlap = std::min(fMax - fMinOther, fMaxOther - fMin); // The smallest overlap
			float fReverseNormal = fMax + fMin - fMaxOther - fMinOther; // Reversal
			reverse.at(iAxisTestNum) = fReverseNormal;
			overlaps.at(iAxisTestNum) = fSmallOverlap;
			bCollisionAxisTest[iAxisTestNum] = true;
		}
		else bCollisionAxisTest[iAxisTestNum] = false; //  found a gap between the boxes
	}

	//Reset overlap
	fRectOverlap = 99999;

	for (int unsigned i = 0; i < overlaps.size(); i++)
	{
		if (overlaps.at(i) < fRectOverlap)
		{
			fRectOverlap = overlaps.at(i); //Find the smallest overlap

			if (reverse.at(i) < 0) collisionRectNormal = -normalsCombined[i]; //Reverse normal
			else collisionRectNormal = normalsCombined[i];
		}
	}

	//If we collide on all 4 axis then we have a collision
	bCollision = bCollisionAxisTest[0] && bCollisionAxisTest[1];

	if (bCollision) return true;
	return false;
}

//!< Collision test OBB-OBB
bool Collision::Intersects(Rectangle &first, Rectangle &other)
{
	//OBB
	UpdateCombinedNormals(first.getNormals(), other.getNormals()); //update normals for OBB

	//Projecting points onto axis 
	for (int iAxisTestNum = 0; iAxisTestNum < 4; iAxisTestNum++)
	{
		//Reset min and max
		float fMin = 99999;
		float fMax = -99999;
		float fMinOther = 99999;
		float fMaxOther = -99999;
		
		//Checking vertices on the first rectangle
		for (int iVertexNum = 0; iVertexNum < 4; iVertexNum++) CheckVertices(first.getGlobalVertices()[iVertexNum], normalsCombined[iAxisTestNum], fMin, fMax);

		//Checking vertices on the second rectangle
		for (int iVertexNum = 0; iVertexNum < 4; iVertexNum++) CheckVertices(other.getGlobalVertices()[iVertexNum], normalsCombined[iAxisTestNum], fMinOther, fMaxOther);

		// Check the min and max for each box and check for intersection
		if (fMinOther - fMax < 0 && fMin - fMaxOther < 0)
		{	
			float fSmallOverlap = std::min(fMax - fMinOther, fMaxOther - fMin); // The smallest overlap
			float fReverseNormal = fMax + fMin - fMaxOther - fMinOther; // Reversal
			reverse.at(iAxisTestNum) = fReverseNormal;
			overlaps.at(iAxisTestNum) = fSmallOverlap;
			bCollisionAxisTest[iAxisTestNum] = true;
		}
		else bCollisionAxisTest[iAxisTestNum] = false; //  found a gap between the boxes
	}

	//Reset overlap
	fRectOverlap = 99999;

	for (int unsigned i = 0; i < overlaps.size(); i++)
	{
		if (overlaps.at(i) < fRectOverlap)
		{
			fRectOverlap = overlaps.at(i); //Find the smallest overlap

			if (reverse.at(i) < 0) collisionRectNormal = -normalsCombined[i]; //Reverse normal
			else collisionRectNormal = normalsCombined[i];			
		}
	}

	//If we collide on all 4 axis then we have a collision
	bCollision = bCollisionAxisTest[0] && bCollisionAxisTest[1] && bCollisionAxisTest[2] && bCollisionAxisTest[3];

	if (bCollision) return true;				
	return false;
}

//!< Collision test OBB-Circle
bool Collision::Intersects(Rectangle &first, Circle &other)
{
	//Declaring some empty variables
	sf::Vector2f clamp;
	Rectangle* p_rect = &first;
	Circle* p_circle = &other;
	sf::Transform rotation;

	//Keep a reference to an original origin
	sf::Vector2f originalOrigin = other.getOrigin();

	//Let's create some shapes
	Rectangle someRect = first;
	Circle someCirc = other;

	//Create a movement to origin
	sf::Vector2f moveToOrigin = -1.f * someRect.getPosition();

	//Apply this movement to circle and rectangle
	someRect.setPosition(someRect.getPosition() - moveToOrigin);
	someCirc.setPosition(someCirc.getPosition() - moveToOrigin);

	//Inverse the rotation
	float fInverseAngle = -1.f * someRect.getRotation();
	someRect.rotate(fInverseAngle); // And rotate the rectangle

	//Also we should rotate the circle around the rectangle
	rotation.rotate(fInverseAngle, someRect.getPosition().x, someRect.getPosition().y);
	sf::Vector2f newPos = rotation.transformPoint(someCirc.getPosition());
	someCirc.setPosition(newPos);

	//Let's have some pointers to those shapes
	p_rect = &someRect;
	p_circle = &someCirc;

	//Subtract positions
	sf::Vector2f centreDistance = p_circle->getPosition() - p_rect->getPosition();

	//Clamp the vector
	if (centreDistance.x < 0) clamp.x = std::max(-p_rect->getOrigin().x, centreDistance.x);
	if (centreDistance.x > 0) clamp.x = std::min(p_rect->getOrigin().x, centreDistance.x);
	if (centreDistance.y < 0) clamp.y = std::max(-p_rect->getOrigin().y, centreDistance.y);
	if (centreDistance.y > 0) clamp.y = std::min(p_rect->getOrigin().y, centreDistance.y);

	sf::Vector2f edgeDistance = centreDistance - clamp; //Subtract this clamp from the distance. This is also our normal

	//Normalise the normal
	collisionCircNormal = m_vectMaths.getNormalisedVector(edgeDistance);
	
	//positive and negative collision normal
	sf::Vector2f negative = collisionCircNormal;
	sf::Vector2f positive = -collisionCircNormal;

	//If we are at the top of the circle make sure our normal will satisfy this
	if (negative.y > 0) negative.y = -negative.y;

	//If we are at the bottom of the circle make sure our normal will satisfy this
	if (positive.y < 0) positive.y = -positive.y;

	//If we are on the left to the circle make sure our normal will satisfy this
	if (negative.x > 0) negative.x = -negative.x;

	//If we are on the right to the circle make sure our normal will satisfy this
	if (positive.x < 0) positive.x = -positive.x;

	//Let's get the real distance between two objects
	sf::Vector2f realPos = other.getPosition() - first.getPosition();

	//If we are at the top our y component should represent that
	if (realPos.y > 0 && realPos.x == 0.0f) collisionCircNormal.y = negative.y;
	if (realPos.y < 0.0f && realPos.x == 0.0f) collisionCircNormal.y = positive.y; // we are at the bottom

	//If we are on the left our x component should represent that
	if (realPos.x > 0 && realPos.y == 0.0f) collisionCircNormal.x = negative.x;
	if (realPos.x < 0.0f && realPos.y == 0.0f) collisionCircNormal.x = positive.x; // we are on the right

	//If we are on the top-left 
	if (realPos.y > 0 && realPos.x < 0)
	{
		collisionCircNormal.x = positive.x;
		collisionCircNormal.y = negative.y;
	}
	if (realPos.y < 0 && realPos.x > 0) // else we are on the bottom-left
	{
		collisionCircNormal.x = negative.x;
		collisionCircNormal.y = positive.y;
	}

	//If we are on the top-right
	if (realPos.y > 0 && realPos.x > 0)
	{
		collisionCircNormal.x = negative.x;
		collisionCircNormal.y = negative.y;
	}
	if (realPos.y < 0 && realPos.x < 0) //else we are on the bottom-left
	{
		collisionCircNormal.x = positive.x;
		collisionCircNormal.y = positive.y;
	}

	//Calculate the overlap
	fCircOverlap = m_vectMaths.getMagnitude(edgeDistance) - p_circle->getRadius() * p_circle->getRadius();
	
	//If it's bellow 0 we have a collision
	bCollision = fCircOverlap < 0;

	if (bCollision) return true;
	return false;

}

//!< Collision test Circle-Circle
bool Collision::Intersects(Circle& first, Circle& other)
{
	sf::Vector2f distance = first.getPosition() - other.getPosition();
	float fMag = m_vectMaths.getMagnitude(distance);
	float fSum = first.getRadius() + other.getRadius();

	if (fMag <= fSum * fSum) return true;
	return false;
}

//!< Returns collision normal of the rectangle
sf::Vector2f Collision::getCollisionRectNormal()
{
	return collisionRectNormal;
}

//!< Returns collision normal of the circle
sf::Vector2f Collision::getCollisionCircNormal()
{
	return collisionCircNormal;
}

//!< Returns overlap of the rectangle
float Collision::getRectOverlap()
{
	return fRectOverlap;
}

//!< Returns overlap of the circle
float Collision::getCircOverlap()
{
	return std::abs(fCircOverlap);
}
