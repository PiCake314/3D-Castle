#pragma once
#include "shapes.hpp"


struct position{
   float x, y, z, xth, yth;
};


position poses[4] = {
   {81.25, -51, -74.3, 17, 48},
   {-6.84, -24, -378, -14.4, -1.6},
   {-48.7, -27, 94.85, 12.3, -124.3},
   {87, -123, -133, 0, 0}
};

//  Rotation angles
double xTh = 30.5;
double yTh = 0;

double xShift = -0;
double yShift = -360;
double zShift = -430;


// values to hold the original values while in ortho/presp mode.
double xTh_hold = xTh;
double yTh_hold = yTh;

double xShift_hold = xShift;
double yShift_hold = yShift;
double zShift_hold = zShift;

int th = 0;  // Azimuth of view angle
int ph = 90; // Elevation of view angle


bool moving_forward = false;
bool moving_backward = false;
bool moving_left = false;
bool moving_right = false;
bool moving_up = false;
bool moving_down = false;

bool rotating_right = false;
bool rotating_left = false;
bool rotating_up = false;
bool rotating_down = false;

int mode = 0;
#define FREE 0
#define PERSP 2
#define ORTHO 1

const float speed = 3.f;
const int rot_speed = 1;
const float mouse_speed = 0.3f;


const float X_OVERHEAD_ORTHO = -215.0f;
const float Y_OVERHEAD_ORTHO = -300;
const float Z_OVERHEAD_ORTHO = -250.0f;
const float xTH_OVERHEAD_ORTHO = 30.0f;
const float yTH_OVERHEAD_ORTHO = -40.0f;

const float X_OVERHEAD = 330;
const float Y_OVERHEAD = -395;
const float Z_OVERHEAD = -333;
const float xTH_OVERHEAD = 33;
const float yTH_OVERHEAD = 47;

float viewing_angle = 0.0f;

const float x_center = 0, y_center = 0, z_center = 0;

int lightSpeed = 0;

int width_ = 600;
int height_ = 600;



// ----------------------------------------------------------


void setupProjection()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (mode == ORTHO)
    {
      //  Orthogonal projection
      const double dim = 200;
      double asp = (height_>0) ? (double)width_/height_ : 1;
      glOrtho(-asp*dim,+asp*dim, -dim, +dim, .1, +1000);
    }
    else
    {
      // Apply perspective projection
      double aspectRatio = (double)width_ / height_;
      gluPerspective(45, aspectRatio, 0.1, 1000);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void setMode(){

   switch(mode){
      case ORTHO:

         xShift = X_OVERHEAD_ORTHO;
         yShift = Y_OVERHEAD_ORTHO;
         zShift = Z_OVERHEAD_ORTHO;
         xTh = xTH_OVERHEAD_ORTHO;
         yTh = yTH_OVERHEAD_ORTHO;

         glTranslatef(x_center, y_center, z_center);
         glRotatef(viewing_angle, 0, 1, 0);
         glTranslatef(-x_center, -y_center, -z_center);

         break;
      case PERSP:
         xShift = X_OVERHEAD;
         yShift = Y_OVERHEAD;
         zShift = Z_OVERHEAD;
         xTh = xTH_OVERHEAD;
         yTh = yTH_OVERHEAD;

         glTranslatef(x_center, y_center, z_center);
         glRotatef(viewing_angle, 0, 1, 0);
         glTranslatef(-x_center, -y_center, -z_center);

         break;
      
      case FREE:
         xTh_hold = xTh;
         yTh_hold = yTh;
         xShift_hold = xShift;
         yShift_hold = yShift;
         zShift_hold = zShift;
         break;
   }

}



// 

/*
 * This function is called by GLUT when the window is resized
 */
void reshape(int width,int height)
{
   width_ = width;
   height_ = height;

   //  Set viewport as entire window
   glViewport(0, 0, RES*width, RES*height);
   //  Select projection matrix
   glMatrixMode(GL_PROJECTION);
   //  Set projection to identity
   glLoadIdentity();

   setupProjection();


   //  Select model view matrix
   glMatrixMode(GL_MODELVIEW);
   //  Set model view to identity
   glLoadIdentity();
}

/*
 * This function is called by GLUT when special keys are pressed
 */
void special(int key,int x,int y){

   if(mode == FREE) switch (key){
      case GLUT_KEY_RIGHT: // Right arrow - increase rotation by 5 degree
         rotating_right = true;
         break;
   
      case GLUT_KEY_LEFT: // Left arrow - decrease rotation by 5 degree
         rotating_left = true;
         break;
   
      case GLUT_KEY_UP: // Up arrow - decrease rotation by 5 degree
         rotating_up = true;
         break;
   
      case GLUT_KEY_DOWN: // Down arrow - increases rotation by 5 degree
         rotating_down = true;
         break;
   }

   else switch (key){
      case GLUT_KEY_RIGHT:
         viewing_angle -= 5;
         break;

      case GLUT_KEY_LEFT:
         viewing_angle += 5;
         break;
      
   }


   //  Request display update
   glutPostRedisplay();
}

int X = 0, Y = 0;;
bool isDragging = false;

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        X = x;
        Y = y;
        isDragging = true;
    }
    else isDragging = false;
}

void motion(int x, int y){
    if (isDragging) {
        float xDiff = mouse_speed * (X - x);
        float yDiff = mouse_speed * (Y - y);

        yTh -= Cos(th) * xDiff - Sin(th) * yDiff;
        xTh -= Sin(th) * xDiff + Cos(th) * yDiff;

        X = x;
        Y = y;

        glutPostRedisplay();
    }
}



void specialUp(int key,int x,int y){

   switch(key){
      case GLUT_KEY_RIGHT: // Right arrow - increase rotation by 5 degree
         rotating_right = false;
         break;
   
      case GLUT_KEY_LEFT: // Left arrow - decrease rotation by 5 degree
         rotating_left = false;
         break;
   
      case GLUT_KEY_UP: // Up arrow - decrease rotation by 5 degree
         rotating_up = false;
         break;
   
      case GLUT_KEY_DOWN: // Down arrow - increases rotation by 5 degree
         rotating_down = false;
         break;
   }


   //  Request display update
   glutPostRedisplay();
}


void keyboard(unsigned char ch,int x,int y){
   if(mode == FREE)
      switch (ch){
         case 27:   // Exit on ESC
            exit(0);
            break;
         
         case 'w':
            moving_forward = true;
            break;
         
         case 's':
            moving_backward = true;
            break;

         case 'a':
            moving_left = true;
            break;

         case 'd':
            moving_right = true;
            break;

         case ' ':
            moving_up = true;
            break;

         case '`':
            moving_down = true;
            break;

         case 'm':
            mode = (mode + 1) % 3;
            break;


         case '1':
            xShift = poses[0].x;
            yShift = poses[0].y;
            zShift = poses[0].z;
            xTh = poses[0].xth;
            yTh = poses[0].yth;
            break;

         case '2':
            xShift = poses[1].x;
            yShift = poses[1].y;
            zShift = poses[1].z;
            xTh = poses[1].xth;
            yTh = poses[1].yth;
            break;

         case '3':
            xShift = poses[2].x;
            yShift = poses[2].y;
            zShift = poses[2].z;
            xTh = poses[2].xth;
            yTh = poses[2].yth;
            break;

         case '4':
            xShift = poses[3].x;
            yShift = poses[3].y;
            zShift = poses[3].z;
            xTh = poses[3].xth;
            yTh = poses[3].yth;
            break;

         case '0':  // Reset the view angle
            xTh = yTh = xShift = yShift = zShift = 0;
            break;
      }
   else switch (ch){
         case 27:
            exit(0);
            break;

         case 'm':
            mode = (mode + 1) % 3;
            if(mode == FREE){
               xShift = xShift_hold;
               yShift = yShift_hold;
               zShift = zShift_hold;
               xTh = xTh_hold;
               yTh = yTh_hold;
            }
      }

   //  Request display update
   glutPostRedisplay();
}


void keyboardUp(unsigned char ch,int x,int y){

   switch (ch){
      
      case 'w':
         moving_forward = false;
         break;
      
      case 's':
         moving_backward = false;
         break;

      case 'a':
         moving_left = false;
         break;

      case 'd':
         moving_right = false;
         break;

      case ' ':
         moving_up = false;
         break;

      case '`':
         moving_down = false;
         break;
   }

   //  Request display update
   glutPostRedisplay();
}


/*
 *  GLUT calls this routine when there is nothing else to do
 */
void idle(){

   // double t = glutGet(GLUT_ELAPSED_TIME)/1000.0;
   // zh = fmod(90*t,360);

   yTh = fmod(yTh, 360);
    xTh = fmod(xTh, 360);

   float delta_x = speed * Sin(yTh);
   float delta_z = speed * Cos(yTh);

   if(moving_forward){

      xShift += -delta_x;
      zShift += delta_z;
   }
   
   if(moving_backward){
      xShift -= -delta_x;
      zShift -= delta_z;
   }

   if(moving_left){
      xShift += delta_z;
      zShift += delta_x;
   }

   if(moving_right){
      xShift -= delta_z;
      zShift -= delta_x;
   }

   if(moving_up){
      yShift -= speed;
   }

   if(moving_down){
      yShift += speed;
   }

   if(rotating_right){
      yTh += rot_speed;
   }

   if(rotating_left){
      yTh -= rot_speed;
   }

   if(rotating_up){
      xTh -= rot_speed;
   }

   if(rotating_down){
      xTh += rot_speed;
   }

   double t = glutGet(GLUT_ELAPSED_TIME)/1000.0;
   lightSpeed = fmod(90*t,360.0);


   glutPostRedisplay();
}
