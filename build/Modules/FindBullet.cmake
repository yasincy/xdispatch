FILE(
	GLOB
	BULLET_INCLUDE_PATHS
	$ENV{HOME}/include/bullet
	/usr/local/include/bullet
	/usr/include/bullet
	$ENV{ProgramW6432}/bullet*/include/bullet
	$ENV{ProgramFiles}/bullet*/include/bullet
)

FILE(
	GLOB
	BULLET_LIBRARY_PATHS
	$ENV{HOME}/lib
	/usr/local/lib
	/usr/lib
	$ENV{ProgramW6432}/bullet*/lib
	$ENV{ProgramFiles}/bullet*/lib
)

FIND_PATH(
	BULLET_INCLUDE_DIRS
	NAMES
	Bullet-C-Api.h
	HINTS
	${BULLET_INCLUDE_PATHS}
)

FIND_LIBRARY(
	BULLET_COLLISION_LIBRARY
	NAMES
	bulletcollision BulletCollision
	HINTS
	${BULLET_LIBRARY_PATHS}
)

FIND_LIBRARY(
	BULLET_DYNAMICS_LIBRARY
	NAMES
	bulletdynamics BulletDynamics
	HINTS
	${BULLET_LIBRARY_PATHS}
)

FIND_LIBRARY(
	BULLET_MATH_LIBRARY
	NAMES
	bulletmath LinearMath
	HINTS
	${BULLET_LIBRARY_PATHS}
)

FIND_LIBRARY(
	BULLET_SOFTBODY_LIBRARY
	NAMES
	bulletsoftbody BulletSoftBody
	HINTS
	${BULLET_LIBRARY_PATHS}
)

SET(
	BULLET_LIBRARIES
	${BULLET_COLLISION_LIBRARY}
	${BULLET_DYNAMICS_LIBRARY}
	${BULLET_MATH_LIBRARY}
	${BULLET_SOFTBODY_LIBRARY}
)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(
	Bullet
	DEFAULT_MSG
	BULLET_INCLUDE_DIRS
	BULLET_COLLISION_LIBRARY
	BULLET_DYNAMICS_LIBRARY
	BULLET_MATH_LIBRARY
	BULLET_SOFTBODY_LIBRARY
)

MARK_AS_ADVANCED(
	BULLET_INCLUDE_DIRS
	BULLET_COLLISION_LIBRARY
	BULLET_DYNAMICS_LIBRARY
	BULLET_LIBRARIES
	BULLET_MATH_LIBRARY
	BULLET_SOFTBODY_LIBRARY
) 
