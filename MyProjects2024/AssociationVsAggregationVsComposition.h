#pragma once
/*******************************************************************************************************
Association:
===========================
Association represents a relationship between two or more objects where each object has its own lifecycle,
and there is no ownership or dependency between them.For example, let's say we have a Car class and a Driver class.
The Car and Driver have an association, as a driver can drive multiple cars, and a car can be driven by multiple drivers.
The Car and Driver objects are connected through this association, but neither object owns or depends on the other.

Aggregation:
============================
Aggregation represents a relationship between two objects where one object is a part or a component of the other object,
but their lifecycles are not necessarily dependent on each other. For example, a Car class may have a relationship
with a Wheel class through aggregation. A car consists of four wheels, and the wheels are part of the car.
However, even if the car is destroyed, the wheels can still exist independently or be used by another car.
The Car class may have a collection of Wheel objects as a member variable, and it can create, modify, or delete wheels as needed.

Composition:
===========================

Composition is a strong form of aggregation where one object owns or is responsible for the existence and lifecycle of another object.
For example, a Car class may have a relationship with an Engine class through composition. The engine is an essential component of
the car, and it cannot exist without the car.
The Car class owns an Engine object, and the engine is created, modified, and destroyed along with the car.
In this case, the Car class may have an Engine object as a member variable, and it is responsible for
creating and destroying the engine.

/**************************************************************************************************************/
