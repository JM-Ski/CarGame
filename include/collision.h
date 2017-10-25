#pragma once

#include "rectangle.h"
#include "circle.h"
#include "vectorMaths.h"

//!This class is used to do collision tests.
class Collision
{
private:
	/*!Confrim collision.*/
	bool bCollision; 

	/*!Confrim collision tests on axes.*/
	bool bCollisionAxisTest[4];

	/*!Rectangle collision normal.*/
	sf::Vector2f collisionRectNormal;

	/*!Circle collision normal.*/
	sf::Vector2f collisionCircNormal;

	/*!Combined rectangle face normals.*/
	std::vector<sf::Vector2f> normalsCombined;

	/*!Vector with overlaps from OBB tests.*/
	std::vector<float> overlaps;

	/*!Vector with reverses from OBB tests.*/
	std::vector<float> reverse;

	/*!Rectangle overlap.*/
	float fRectOverlap;

	/*!Circle overlap.*/
	float fCircOverlap;

	/*!A variable which deals with vector maths.*/
	VectorMaths m_vectMaths;

public:
	/*!An initializer.*/
	Collision();

	/*!Updates normals of combined OBB rectangles.*/
	/**@param first = Face normals of the first OBB rectangle.
	   @param other = Face normals of the second OBB rectangle.*/
	void UpdateCombinedNormals(std::vector<sf::Vector2f>& first, std::vector<sf::Vector2f>& other); //!< 

	/*!Projection of OBB rectangle onto axis.*/
	/**@param vertex = A vertex of the OBB rectangle.
	   @param normal = A face normal of the OBB rectangle.
	   @param fMin = A current minimum of the OBB rectangle.
	   @param fMax = A current maximum of the OBB rectangle.*/
	void CheckVertices(sf::Vertex& vertex, sf::Vector2f& normal, float& fMin, float& fMax);

	/*!Collision test AABB-AABB.*/
	/**@param firstAABB = First AABB rectangle.
	@param otherAABB = Second AABB rectangle.
	@param sAABB = A variable with any name to avoid overloading the OBB checks.*/
	bool Intersects(Rectangle &firstAABB, Rectangle &otherAABB, std::string sAABB);

	/*!Collision test OBB-OBB.*/
	/**@param first = First OBB rectangle.
	   @param other = Second OBB rectangle.*/
	bool Intersects(Rectangle &first, Rectangle &other);

	/*!Collision test OBB-Circle.*/
	/**@param first = An OBB rectangle.
	@param other = A circle.*/
	bool Intersects(Rectangle &first, Circle &other);

	/*!Collision test OBB-Circle.*/
	/**@param first = A first circle.
	@param other = A second circle.*/
	bool Intersects(Circle &first, Circle &other);

	/*!Returns collision normal of the rectangle.*/
	/**@return collisionRectNormal = Rectangle collision normal.*/
	sf::Vector2f getCollisionRectNormal();

	/*!Returns collision normal of the circle.*/
	/**@return collisionCircNormal = Circle collision normal.*/
	sf::Vector2f getCollisionCircNormal();

	/*!Returns overlap of the rectangle.*/
	/**@return fRectOverlap = Returns a rectangle overlap.*/
	float getRectOverlap();

	/*!Returns overlap of the circle.*/
	/**@return std::abs(fCircOverlap) = Returns a positive circle overlap.*/
	float getCircOverlap();
};