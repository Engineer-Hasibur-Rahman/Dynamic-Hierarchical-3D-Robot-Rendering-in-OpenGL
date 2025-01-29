// Dynamic-Hierarchical-3D-Robot-Rendering-in-OpenGL

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <gl/glut.h>
#include <utility>
#include <vector>

using namespace std;
// Viewport width in pixels
const int vWidth = 650;   
// Viewport height in pixels 
const int vHeight = 500;    
// THE BODY IS THE BASE PART

// Robot Measurements
// Body Measurements
float robotBodyWidth = 8.0;
float robotBodyLength = 5.0;
float robotBodyDepth = 3.0;
	float robotBodyChestWidth = 7.75;
	float robotBodyChestLength = 3.0;
	float robotBodyChestDepth = 2.0;
		float robotBodyChestCubeWidth = 1.5;
		float robotBodyChestCubeLength = 1.25;
		float robotBodyChestCubeDepth = 0.5;
	float robotBodyMiddleWidth = 2.0;
	float robotBodyMiddleLength = 4.0;
	float robotBodyMiddleDepth = 1.5;
	float robotBodyWaistWidth = 7.25;
	float robotBodyWaistLength = 2.0;
	float robotBodyWaistDepth = 2.25;
	float robotBodyBackpackWidth = 5.0;
	float robotBodyBackpackLength = 5.0;
	float robotBodyBackpackDepth = 1.5;
		float robotBodyCylinderRadiusTop = 0.4;
		float robotBodyCylinderRadiusBottom = 0.4;
		float robotBodyCylinderDepth = 5.0;

// Head Measurements
float robotHeadWidth = 3.2;
float robotHeadLength = 3.2;
float robotHeadDepth = 3.2;
	float robotHeadBandWidth = 0.5;
	float robotHeadBandLength = 0.6;
	float robotHeadBandDepth = robotHeadLength + 0.5;
	float robotHeadBandBackWidth = 0.5;
	float robotHeadBandBackLength = 0.5;
	float robotHeadBandBackDepth = 0.5;
	float robotHeadRedTopWidth = 0.35;
	float robotHeadRedTopLength = 0.35;
	float robotHeadRedTopDepth = 0.4;
	float robotHeadAntennaLength = 2.5;
	float robotHeadAntennaRadius = 0.15;
	float robotHeadBrowLength = 1.25;
	float robotHeadBrowRadius = 0.1;
	float robotHeadEyeWidth = 0.15;
	float robotHeadEyeLength = 0.10;
	float robotHeadEyeDepth = 0.1;
	float robotHeadRedBottomWidth = 0.5;
	float robotHeadRedBottomLength = 0.5;
	float robotHeadRedBottomDepth = 0.5;

// Arm Measurements
float robotArmWidth = 2.0;
float robotArmLength = 10.0;
float robotArmDepth = 2.0;
float robotShoulderWidth = 2.75;
float robotShoulderLength = 2.5;
float robotShoulderDepth = 2.5;
float robotHandWidth = 2.05;
float robotHandLength = 1.5;
float robotHandDepth = 2.05;
float cannonCylinderRadiusTop = 1.0;
float cannonCylinderRadiusBottom = cannonCylinderRadiusTop;
float cannonCylinderDepth = 0.35 * robotArmLength;
float cannonCylinderMiniRadiusTop = 0.25;
float cannonCylinderMiniRadiusBottom = cannonCylinderMiniRadiusTop;
float cannonCylinderMiniDepth = 0.75 * robotArmLength;
float cannonTorusRadiusInner = 0.125 * cannonCylinderRadiusTop;
float cannonTorusRadiusOuter = cannonCylinderRadiusTop + 0.1;
float cannonArmWidth = 0.5 * robotArmWidth;
float cannonArmLength = 2.0;
float cannonArmDepth = 1.0;

// Hip Measurements
float robotHipWidth = 7.75;
float robotHipLength = 3.0;
float robotHipDepth = 3.0;
float robotHipMiddleWidth = 2.0;
float robotHipMiddleLength = 2.5;
float robotHipMiddleDepth = 2.0;
float robotHipCubeWidth = 1.75;
float robotHipCubeLength = 1.75;
float robotHipCubeDepth = 1.5;

// Leg Measurements
float robotLegWidth = 3.0;
float robotLegLength = 10.0;
float robotLegDepth = 2.5;
float robotKneeWidth = 3.5;
float robotKneeLength = 2.75;
float robotKneeDepth = 2.5;
float robotFeetWidth = 3.5;
float robotFeetLength = 1.0;
float robotFeetDepth = 4.25;


// Joint Angles
float robotAngle = 0.0;
float upperAngle = 0.0;
float headAngle = 0.0;
float leftArmAngle = 0.0;
float rightArmAngle = 0.0;
float cannonAngle = 90;
float cannonSpinAngle = 0.0;
float hipAngle = 0.0;
float leftLegAngle = 0.0;
float rightLegAngle = 0.0;

// Possible joint values (for adjusting joint angles)
enum Joint {ROBOT, UPPER_BODY, HEAD, LEFT_ARM, RIGHT_ARM, HIP, LEFT_LEG, RIGHT_LEG, NONE}; 
// Holds the current join, when NONE -> no joint is selected
Joint activeJoint = NONE; 

// Flags
bool cannonStop = true;
bool walkStop = true;
bool walkFlag = true; // true = right leg step | false = left leg step

GLUquadric* quadric; // For quadric surfaces

// Material Colours

// Material Colours
// Robot Blue
GLfloat blue_ambient[] = { 0.101f, 0.146f, 0.229f, 1.0f };
GLfloat blue_specular[] = { 0.337f, 0.486f, 0.765f, 1.0f };
GLfloat blue_diffuse[] = { 0.101f, 0.146f, 0.229f, 1.0f };
GLfloat blue_shininess[] = { 32.0F };

// Robot Grey
GLfloat grey_ambient[] = { 0.133f, 0.16f, 0.169f, 1.0f };
GLfloat grey_specular[] = { 0.443f, 0.533f, 0.565f, 1.0f };
GLfloat grey_diffuse[] = { 0.222f, 0.267f, 0.282f, 1.0f };
GLfloat grey_shininess[] = { 32.0F };

// Robot Red
GLfloat red_ambient[] = { 0.247f, 0.066f, 0.038f, 1.0f };
GLfloat red_specular[] = { 0.824f, 0.220f, 0.125f, 1.0f };
GLfloat red_diffuse[] = { 0.412f, 0.110f, 0.063f, 1.0f };
GLfloat red_shininess[] = { 32.0F };

// Robot White
GLfloat white_ambient[] = { 0.251f, 0.268f, 0.262f, 1.0f };
GLfloat white_specular[] = { 0.835f, 0.894f, 0.875f, 1.0f };
GLfloat white_diffuse[] = { 0.418f, 0.447f, 0.438f, 1.0f };
GLfloat white_shininess[] = { 32.0F };

// Robot Yellow
GLfloat yellow_ambient[] = { 0.274f, 0.194f, 0.045f, 1.0f };
GLfloat yellow_diffuse[] = { 0.913f, 0.647f, 0.149f, 1.0f };
GLfloat yellow_specular[] = { 0.457f, 0.324f, 0.075f, 1.0f };
GLfloat yellow_shininess[] = { 32.0F };

// New Colors Added

// Robot Green
GLfloat green_ambient[] = { 0.105f, 0.230f, 0.104f, 1.0f };
GLfloat green_diffuse[] = { 0.196f, 0.784f, 0.196f, 1.0f };
GLfloat green_specular[] = { 0.357f, 0.824f, 0.357f, 1.0f };
GLfloat green_shininess[] = { 32.0F };

// Robot Purple
GLfloat purple_ambient[] = { 0.239f, 0.090f, 0.270f, 1.0f };
GLfloat purple_diffuse[] = { 0.604f, 0.196f, 0.784f, 1.0f };
GLfloat purple_specular[] = { 0.784f, 0.451f, 0.980f, 1.0f };
GLfloat purple_shininess[] = { 32.0F };

// Robot Cyan
GLfloat cyan_ambient[] = { 0.054f, 0.188f, 0.239f, 1.0f };
GLfloat cyan_diffuse[] = { 0.196f, 0.784f, 0.784f, 1.0f };
GLfloat cyan_specular[] = { 0.314f, 0.941f, 0.941f, 1.0f };
GLfloat cyan_shininess[] = { 32.0F };

// Robot Orange
GLfloat orange_ambient[] = { 0.278f, 0.145f, 0.060f, 1.0f };
GLfloat orange_diffuse[] = { 0.980f, 0.502f, 0.125f, 1.0f };
GLfloat orange_specular[] = { 0.824f, 0.412f, 0.224f, 1.0f };
GLfloat orange_shininess[] = { 32.0F };


GLfloat light_position0[] = { 4.0F, 8.0F, 8.0F, 1.0F };
GLfloat light_position1[] = { 4.0F, 8.0F, 8.0F, 1.0F };
GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light_ambient[] = { 0.2F, 0.2F, 0.2F, 1.0F };

void initOpenGL(int w, int h);
void display(void);
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);
void functionKeys(int key, int x, int y);
void animationHandler(int param);
void drawRobot();
void drawBody();
void drawHead();
void drawLeftArm();
void drawRightArm();
void drawHip();
void drawLeftLeg();
void drawRightLeg();

void cannonSpin(int param);
void robotWalk(int param);
void resetRobotWalk(int param);
void resetRobot(int param);

