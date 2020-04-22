#include <DirectXMath.h>
#include "Vector3D.h"
using namespace DirectX;

#pragma once
class Transform
{
public:

	Transform() { _previousVelocity, _previousPosition, _position, _rotation, _scale = XMFLOAT3(); _world = XMFLOAT4X4(); _centreOfMass = Vector3D(); };

	XMFLOAT3 getPrevVelocity() { return _previousVelocity; };
	XMFLOAT3 getPrevPosition() { return _previousPosition; };
	XMFLOAT3 getPosition() { return _position; };
	Vector3D getVector3Position() { return Vector3D(_position.x, _position.y, _position.z); };
	XMFLOAT3 getRotation() { return _rotation; };
	XMFLOAT3 getScale() { return _scale; };
	XMMATRIX getWorldMatrix() { return XMLoadFloat4x4(&_world); };
	Vector3D getCenterOfMass() { return _centreOfMass; };

	void setPrevVelocity(XMFLOAT3 value) { _previousVelocity = value; };
	void setPrevPosition(XMFLOAT3 value) { _previousPosition = value; };
	void setPosition(XMFLOAT3 value) { _position = value; setPrevPosition(_position); };
	void setRotation(XMFLOAT3 value) { _rotation = value; };
	void setScale(XMFLOAT3 value) { _scale = value; };
	void setWorldMatrix(XMFLOAT4X4 value) { _world = value; };
	void setWorldMatrix(XMMATRIX value) { XMStoreFloat4x4(&_world, value); };
	void setCenterOfMass(Vector3D value) { _centreOfMass = value; };

private:
	XMFLOAT3 _previousVelocity;
	XMFLOAT3 _previousPosition;
	XMFLOAT3 _position;
	XMFLOAT3 _rotation;
	XMFLOAT3 _scale;
	XMFLOAT4X4 _world;
	Vector3D _centreOfMass;
};

