#pragma once

#include "CSCIx229.h"


// textures
unsigned int id_rockwall = 0;
unsigned int id_rockside = 0;
unsigned int id_wood = 0;
unsigned int id_woodengeround = 0;
unsigned int id_fabric = 0;
unsigned int id_fire = 0;
unsigned int id_rug = 0;
unsigned int id_shelf = 0;
unsigned int id_books = 0;
unsigned int id_morebooks = 0;
unsigned int id_bookside = 0;
unsigned int id_kuwait = 0;


/*
 *  Draw a cube
 *     at (x,y,z)
 *     dimensions (dx,dy,dz)
 *     rotated th about the y axis
 */
static void cube(
double x,double y,double z,
double dx,double dy,double dz,
double th,
double r, double g, double b,
unsigned int id
)
{
   //  Save transformation
   glPushMatrix();
   //  Offset
   glTranslated(x, y, z);
   glRotated(th,0,1,0);
   glScaled(dx,dy,dz);

   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, id);

   //  Cube
   glBegin(GL_QUADS);
   //  Front
   glColor3f(r, g, b);
   glNormal3f(0, 0, 1);
   glTexCoord2f(0, 0); glVertex3f(-1,-1, 1);
   glTexCoord2f(1, 0); glVertex3f(+1,-1, 1);
   glTexCoord2f(1, 1); glVertex3f(+1,+1, 1);
   glTexCoord2f(0, 1); glVertex3f(-1,+1, 1);
   //  Back
   glColor3f(r, g, b);
   glNormal3f(0, 0, -1);
   glTexCoord2f(0, 0); glVertex3f(+1,-1,-1);
   glTexCoord2f(1, 0); glVertex3f(-1,-1,-1);
   glTexCoord2f(1, 1); glVertex3f(-1,+1,-1);
   glTexCoord2f(0, 1); glVertex3f(+1,+1,-1);
   //  Right
   glColor3f(r, g, b);
   glNormal3f(1, 0, 0);
   glTexCoord2f(0, 0); glVertex3f(+1,-1,+1);
   glTexCoord2f(1, 0); glVertex3f(+1,-1,-1);
   glTexCoord2f(1, 1); glVertex3f(+1,+1,-1);
   glTexCoord2f(0, 1); glVertex3f(+1,+1,+1);
   //  Left
   glColor3f(r, g, b);
   glNormal3f(-1, 0, 0);
   glTexCoord2f(0, 0); glVertex3f(-1,-1,-1);
   glTexCoord2f(1, 0); glVertex3f(-1,-1,+1);
   glTexCoord2f(1, 1); glVertex3f(-1,+1,+1);
   glTexCoord2f(0, 1); glVertex3f(-1,+1,-1);
   //  Top
   glColor3f(r, g, b);
   glNormal3f(0, 1, 0);
   glTexCoord2f(0, 0); glVertex3f(-1,+1,+1);
   glTexCoord2f(1, 0); glVertex3f(+1,+1,+1);
   glTexCoord2f(1, 1); glVertex3f(+1,+1,-1);
   glTexCoord2f(0, 1); glVertex3f(-1,+1,-1);
   //  Bottom
   glColor3f(r, g, b);
   glNormal3f(0, -1, 0);
   glTexCoord2f(0, 0); glVertex3f(-1,-1,-1);
   glTexCoord2f(1, 0); glVertex3f(+1,-1,-1);
   glTexCoord2f(1, 1); glVertex3f(+1,-1,+1);
   glTexCoord2f(0, 1); glVertex3f(-1,-1,+1);
   //  End
   glEnd();
   glDisable(GL_TEXTURE_2D);
   //  Undo transformations
   glPopMatrix();
}



/*
 *  Draw a ball
 *     at (x,y,z)
 *     radius r
 */
static void ball(double x,double y,double z,double r)
{
   //  Save transformation
   glPushMatrix();
   //  Offset, scale and rotate
   glTranslated(x,y,z);
   glScaled(r,r,r);
   //  White ball
   glColor3f(1,1,1);
   glutSolidSphere(1.0,16,16);
   //  Undo transofrmations
   glPopMatrix();
}



// building blocks


void ground(double x, double y, double z, double len, int texture_id, int repeats = 10){
   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, texture_id);

   glPushMatrix();
   glTranslated(x, y, z);
   glScaled(len, 1, len);


   glBegin(GL_QUADS);
   glNormal3f(0, 1, 0);
   glTexCoord2f(0, 0);              glVertex3f(-1, 0, -1);
   glTexCoord2f(repeats, 0);        glVertex3f(+1, 0, -1);
   glTexCoord2f(repeats, repeats);  glVertex3f(+1, 0, +1);
   glTexCoord2f(0, repeats);        glVertex3f(-1, 0, +1);
   glEnd();

   glDisable(GL_TEXTURE_2D);

   glPopMatrix();
}


/*
 *  Draw a cube
 *     at (x,y,z)
 *     dimensions (dx,dy,dz)
 *     rotated th about the y axis
 */
static void wall(
double x,double y,double z,
double dx,double dy,double dz,
double th
)
{
   //  Save transformation
   glPushMatrix();
   //  Offset
   glTranslated(x, y, z);
   glRotated(th, 0, 1, 0);
   glScaled(dx, dy, dz);

   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, id_rockwall);

   //  Cube
   glBegin(GL_QUADS);
   //  Front
   const int repeats = 4;
   glNormal3f(0, 0, 1);
   glTexCoord2f(0, 0);              glVertex3f(-1,-1, 1);
   glTexCoord2f(repeats, 0);        glVertex3f(+1,-1, 1);
   glTexCoord2f(repeats, repeats);  glVertex3f(+1,+1, 1);
   glTexCoord2f(0, repeats);        glVertex3f(-1,+1, 1);
   //  Back
   glNormal3f(0, 0, -1);
   glTexCoord2f(0, 0);              glVertex3f(+1,-1,-1);
   glTexCoord2f(repeats, 0);        glVertex3f(-1,-1,-1);
   glTexCoord2f(repeats, repeats);  glVertex3f(-1,+1,-1);
   glTexCoord2f(0, repeats);        glVertex3f(+1,+1,-1);
   glEnd();
   glDisable(GL_TEXTURE_2D);


   //  Top
   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, id_wood);
   glBegin(GL_QUADS);

   glNormal3f(0, 1, 0);
   glTexCoord2f(0, 0); glVertex3f(-1,+1,+1);
   glTexCoord2f(0, 2); glVertex3f(+1,+1,+1);
   glTexCoord2f(1, 2); glVertex3f(+1,+1,-1);
   glTexCoord2f(1, 0); glVertex3f(-1,+1,-1);
   //  Bottom
   glNormal3f(0, -1, 0);
   glTexCoord2f(0, 0); glVertex3f(-1,-1,-1);
   glTexCoord2f(1, 0); glVertex3f(+1,-1,-1);
   glTexCoord2f(1, 1); glVertex3f(+1,-1,+1);
   glTexCoord2f(0, 1); glVertex3f(-1,-1,+1);
   glEnd();
   glDisable(GL_TEXTURE_2D);


   //  Right
   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, id_rockside);
   glBegin(GL_QUADS);

   glNormal3f(1, 0, 0);
   glTexCoord2f(0, 0); glVertex3f(+1,-1,+1);
   glTexCoord2f(1, 0); glVertex3f(+1,-1,-1);
   glTexCoord2f(1, 4); glVertex3f(+1,+1,-1);
   glTexCoord2f(0, 4); glVertex3f(+1,+1,+1);
   //  Left
   glNormal3f(-1, 0, 0);
   glTexCoord2f(0, 0); glVertex3f(-1,-1,-1);
   glTexCoord2f(1, 0); glVertex3f(-1,-1,+1);
   glTexCoord2f(1, 4); glVertex3f(-1,+1,+1);
   glTexCoord2f(0, 4); glVertex3f(-1,+1,-1);

   //  End
   glEnd();
   glDisable(GL_TEXTURE_2D);

   //  Undo transformations
   // glPopMatrix();

   glScaled(1/dx, 1/dy, 1/dz);


   // glPushMatrix();
   // //  Offset
   // glTranslated(x, y, z);
   glTranslated(-dx, dy + 1, -dz);
   // glRotated(th, 0, 1, 0);


   // the cubic spikes on top
   const int num_spikes = dx/5;
   const int freq = dx/num_spikes * 2;

   for (int i = 1; i < num_spikes; i++){
      cube(freq*i, 1, 1, 2, 2, dz, 0, 1, 1, 1, id_rockside);
   }

   glPopMatrix();

}


void cylinder(float radius, float height, int outter_id, int top_id){

   const int numSegments = 32; // The number of segments.
   const float segmentAngle = 2.0 * M_PI / numSegments; // The angle of each segment.


   glBindTexture(GL_TEXTURE_2D, outter_id);
   glEnable(GL_TEXTURE_2D);

   glBegin(GL_TRIANGLE_STRIP);
   // Draw the sides of the cylinder
   for (int i = 0; i <= numSegments; ++i){
      float angle = i * segmentAngle;
      float x = radius * cos(angle);
      float z = radius * sin(angle);
      float u = static_cast<float>(i) / numSegments;

      // Calculate normals
      float nx = cos(angle);
      float nz = sin(angle);

      glNormal3f(nx, 0.0f, nz);
      glTexCoord2f(u, 1.0f);
      glVertex3f(x, height, z);

      glNormal3f(nx, 0.0f, nz);
      glTexCoord2f(u, 0.0f);
      glVertex3f(x, 0.0f, z);
   }

   glEnd();
   glDisable(GL_TEXTURE_2D);



   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, top_id);

   glBegin(GL_TRIANGLE_FAN);
   glNormal3f(0.0f, 1.0f, 0.0f);
   glTexCoord2f(0.5f, 0.5f);
   glVertex3f(0.0f, height, 0.0f);
   // cylinder top
   for (int i = 0; i <= numSegments; ++i){
      float angle = i * segmentAngle;
      float x = radius * cos(angle);
      float z = radius * sin(angle);
      float u = 0.5f + 0.5f * cos(angle);
      float v = 0.5f + 0.5f * sin(angle);

      glNormal3f(0.0f, 1.0f, 0.0f);
      glTexCoord2f(u, v);
      glVertex3f(x, height, z);
   }

   glEnd();
   glDisable(GL_TEXTURE_2D);

   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, top_id);

   glBegin(GL_TRIANGLE_FAN);
   glNormal3f(0.0f, -1.0f, 0.0f);
   glTexCoord2f(0.5f, 0.5f);
   glVertex3f(0.0f, 0.0f, 0.0f);
   // cylinder bottom
   for (int i = numSegments; i >= 0; --i){
      float angle = i * segmentAngle;
      float x = radius * cos(angle);
      float z = radius * sin(angle);
      float u = 0.5f + 0.5f * cos(angle);
      float v = 0.5f + 0.5f * sin(angle);

      glNormal3f(0.0f, -1.0f, 0.0f);
      glTexCoord2f(u, v);
      glVertex3f(x, 0.0f, z);
   }

   glEnd();
   glDisable(GL_TEXTURE_2D);
}

void hollowCylinder(float outerRadius, float innerRadius, float height, int texture_id){
   const int numSegments = 32; // The number of segments.
   float segmentAngle = 2.0 * M_PI / numSegments;

   glBindTexture(GL_TEXTURE_2D, texture_id);
   glEnable(GL_TEXTURE_2D);

   // Draw top surface
   glBegin(GL_QUAD_STRIP);
   for (int i = 0; i <= numSegments; ++i)
   {
      float angle = i * segmentAngle;
      float xOuter = outerRadius * cos(angle);
      float zOuter = outerRadius * sin(angle);
      float xInner = innerRadius * cos(angle);
      float zInner = innerRadius * sin(angle);
      float u = static_cast<float>(i) / numSegments;

      glNormal3f(0.0f, 1.0f, 0.0f);
      glTexCoord2f(10*u, 0.0f);
      glVertex3f(xInner, height, zInner);

      glNormal3f(0.0f, 1.0f, 0.0f);
      glTexCoord2f(10*u, 1.0f);
      glVertex3f(xOuter, height, zOuter);
   }
   glEnd();

   // // Draw bottom surface
   // glBegin(GL_TRIANGLE_FAN);
   // glNormal3f(0.0f, -1.0f, 0.0f);
   // glTexCoord2f(0.5f, 0.5f);
   // glVertex3f(0.0f, 0.0f, 0.0f);

   // for (int i = numSegments; i >= 0; --i)
   // {
   //    float angle = i * segmentAngle;
   //    float xInner = innerRadius * cos(angle);
   //    float zInner = innerRadius * sin(angle);

   //    glNormal3f(0.0f, -1.0f, 0.0f);
   //    glTexCoord2f(0.5f + 0.5f * cos(angle), 0.5f + 0.5f * sin(angle));
   //    glVertex3f(xInner, 0.0f, zInner);
   // }
   // glEnd();

   // Draw outer surface
   glBegin(GL_QUAD_STRIP);
   for (int i = 0; i <= numSegments; ++i)
   {
      float angle = i * segmentAngle;
      float xOuter = outerRadius * cos(angle);
      float zOuter = outerRadius * sin(angle);
      float u = static_cast<float>(i) / numSegments;

      // Calculate normals
      float nxOuter = cos(angle);
      float nzOuter = sin(angle);

      glNormal3f(nxOuter, 0.0f, nzOuter);
      glTexCoord2f(6*u, 1.0f);
      glVertex3f(xOuter, height, zOuter);

      glNormal3f(nxOuter, 0.0f, nzOuter);
      glTexCoord2f(6*u, 0.0f);
      glVertex3f(xOuter, 0.0f, zOuter);
   }
   glEnd();

   // Draw inner surface
   glBegin(GL_QUAD_STRIP);
   for (int i = 0; i <= numSegments; ++i)
   {
      float angle = i * segmentAngle;
      float xInner = innerRadius * cos(angle);
      float zInner = innerRadius * sin(angle);
      float u = static_cast<float>(i) / numSegments;

      // Calculate normals
      float nxInner = -cos(angle);
      float nzInner = -sin(angle);

      glNormal3f(nxInner, 0.0f, nzInner);
      glTexCoord2f(6*u, 1.0f);
      glVertex3f(xInner, height, zInner);

      glNormal3f(nxInner, 0.0f, nzInner);
      glTexCoord2f(6*u, 0.0f);
      glVertex3f(xInner, 0.0f, zInner);
   }
   glEnd();

   glDisable(GL_TEXTURE_2D);
}

void drawCircularCubes(double x, double y, double z, int n, float r){

   for (int i = 0; i < n; i++){      
      glPushMatrix();

      float angle = i * 360.0/n;
      float x = r * Cos(angle);
      float z = r * Sin(angle);

      cube(x, y, z, 2, 5, 2, -angle, 1, 1, 1, id_rockside);
      glPopMatrix();

   }

   glDisable(GL_TEXTURE_2D);
}


void pillar(double x, double y, double z, double r, double height){

   glPushMatrix();
   //  Offset
   glTranslated(x, y, z);
   glScaled(r, height, r);

   cylinder(1, 1, id_rockwall, id_wood);

   glPopMatrix();

   glPushMatrix();
   //  Offset
   glTranslated(x, y + height, z);
   glScaled(r, 1, r);

   const int hollow_height = 25;
   hollowCylinder(1, 0.8, hollow_height, id_rockwall);

   glPopMatrix();

   glPushMatrix();
   //  Offset
   glTranslated(x, y + height + hollow_height, z);
   drawCircularCubes(0, 2, 0, 12, r*.9);

   glPopMatrix();

}

void halfOval(float x, float y, float z, float width, float height, int textureID) {
    // Enable necessary features and bind the texture
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Calculate the number of vertices
    const int numVertices = 100; // Adjust the value for desired smoothness

    // Set up the geometry and texture coordinates
    glBegin(GL_TRIANGLE_FAN);

    // Calculate the angle increment for each vertex
    const float angleIncrement = M_PI / numVertices;

    // Draw the vertices for the filled upper half of the oval shape
    glTexCoord2f(0.5f, 0.5f); // Texture coordinates for the center of the shape
    glVertex3f(x, y, z); // Center of the shape

    // Draw the outer vertices
    for (int i = 0; i <= numVertices; ++i) {
        const float angle = i * angleIncrement;
        const float vertexX = x + width * cos(angle) / 2.0f;
        const float vertexY = y + height * sin(angle) / 2.0f;
        const float textureX = 0.5f + 0.5f * cos(angle);
        const float textureY = 0.5f + 0.5f * sin(angle);

        glTexCoord2f(textureX, 1.0f - textureY); // Flip texture vertically
        glNormal3f(0.0f, 0.0f, 1.0f); // Normal vector pointing outwards
        glVertex3f(vertexX, vertexY, z);
    }

    glEnd();

    // Disable features and unbind the texture
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
}


void prism(float x, float y, float z, float side, float height, int texture_id){

   glPushMatrix();
   //  Offset
   glTranslated(x, y, z);
   glScaled(side, height, side);


   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, texture_id);

   
   // Base
   glBegin(GL_QUADS);
   glNormal3f(0, -1, 0);
   glTexCoord2f(0, 0); glVertex3f(-1, 0, -1);
   glTexCoord2f(1, 0); glVertex3f(+1, 0, -1);
   glTexCoord2f(1, 1); glVertex3f(+1, 0, +1);
   glTexCoord2f(0, 1); glVertex3f(-1, 0, +1);
   glEnd();


   // front
   glBegin(GL_QUADS);
   glNormal3f(0, 1, 1);
   glTexCoord2f(0, 0); glVertex3f(-1, 0, +1);
   glTexCoord2f(1, 0); glVertex3f(+1, 0, +1);
   glTexCoord2f(1, 1); glVertex3f(+1, 1, -1);
   glTexCoord2f(0, 1); glVertex3f(-1, 1, -1);
   glEnd();


   glBegin(GL_TRIANGLES);
   glNormal3f(1, 0, 0);
   glTexCoord2f(0, 0); glVertex3f(+1, 0, +1);
   glTexCoord2f(1, 0); glVertex3f(+1, 0, -1);
   glTexCoord2f(1, 1); glVertex3f(+1, 1, -1);
   glEnd();


   glBegin(GL_TRIANGLES);
   glNormal3f(-1, 0, 0);
   glTexCoord2f(0, 0); glVertex3f(-1, 0, +1);
   glTexCoord2f(1, 0); glVertex3f(-1, 0, -1);
   glTexCoord2f(1, 1); glVertex3f(-1, 1, -1);
   glEnd();


   glDisable(GL_TEXTURE_2D);

   glPopMatrix();

}



void table(float x, float y, float z, float width, int length, float height, int id_top, int id_legs){

   // Table top!
   glPushMatrix();

   glTranslated(x, y, z);
   glScaled(width, height, length);


   cube(0, 0, 0, .5f, 0.05, .5f, 0, .4, .4, .4, id_top);

   // Drawing legs
   cube(-.4f, -.35f, 0.4f, .05f, 0.3, .05f, 0, .3, .3, .3, id_legs);
   cube(.4f, -.35f, -0.4f, .05f, 0.3, .05f, 0, .3, .3, .3, id_legs);
   cube(-.4f, -.35f, -0.4f, .05f, 0.3, .05f, 0, .3, .3, .3, id_legs);
   cube(.4f, -.35f, 0.4f, .05f, 0.3, .05f, 0, .3, .3, .3, id_legs);

   glPopMatrix();
}


void bedFrame(float x, float y, float z, float width, float length, float height, int id_top, int id_legs){

   // Table top!
   glPushMatrix();
   glTranslated(x, y, z);

   glPushMatrix();
   glScaled(width, height, length);
   cube(0, 0, 0, .5f, 0.05, .5f, 0, .4, .4, .4, id_top);
   glPopMatrix();

   // Drawing legs
   cube(-width/2.5 -.4f, -2.5,   length/2.5 + .4f, .5, 2.5, .5, 0, .3, .3, .3, id_legs);
   cube( width/2.5 + .4f, -2.5, -length/2.5 -.4f,  .5, 2.5, .5, 0, .3, .3, .3, id_legs);
   cube(-width/2.5 -.4f, -2.5,  -length/2.5 -.4f,  .5, 2.5, .5, 0, .3, .3, .3, id_legs);
   cube( width/2.5 + .4f, -2.5,  length/2.5 + .4f, .5, 2.5, .5, 0, .3, .3, .3, id_legs);

   glPopMatrix();
}


void mattress(float x, float y, float z, float width, float length, float height, int texture_id){
   cube(x, y, z, width, height, length, 0, .4, .4, .4, texture_id);
}


// It's just an ellipsoid
void pillow(float x, float y, float z, float width, float length, float height, int texture_id){
   // Enable texture mapping
   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, texture_id);

   glColor3f(1.0f, 1.0f, 1.0f);

   // Number of subdivisions for the ellipsoid
   int subdivisions = 32;

   // Calculate the step size for each subdivision
   float phiStep = 2.0f * M_PI / subdivisions;
   float thetaStep = M_PI / subdivisions;

   // glTranslatef(x, y, z);
   // glScalef(width, height, length);

   // Draw the ellipsoid
   glBegin(GL_TRIANGLES);

   // Loop through each subdivision
   for (int i = 0; i < subdivisions; ++i) {
      // Calculate the azimuth angle for the current row
      float phi = i * phiStep;

      // Calculate the azimuth angle for the next row
      float nextPhi = (i + 1) * phiStep;

      // Loop through each subdivision in the row
      for (int j = 0; j < subdivisions; ++j) {
         // Calculate the polar angle for the current column
         float theta = j * thetaStep;

         // Calculate the polar angle for the next column
         float nextTheta = (j + 1) * thetaStep;

         // Calculate the vertices of the current quad
         float x0 = x + width * sin(theta) * cos(phi);
         float y0 = y + length * sin(theta) * sin(phi);
         float z0 = z + height * cos(theta);

         float x1 = x + width * sin(theta) * cos(nextPhi);
         float y1 = y + length * sin(theta) * sin(nextPhi);
         float z1 = z + height * cos(theta);

         float x2 = x + width * sin(nextTheta) * cos(phi);
         float y2 = y + length * sin(nextTheta) * sin(phi);
         float z2 = z + height * cos(nextTheta);

         float x3 = x + width * sin(nextTheta) * cos(nextPhi);
         float y3 = y + length * sin(nextTheta) * sin(nextPhi);
         float z3 = z + height * cos(nextTheta);

         // Calculate the texture coordinates for the current quad
         float u0 = static_cast<float>(j) / subdivisions;
         float v0 = static_cast<float>(i) / subdivisions;

         float u1 = static_cast<float>(j + 1) / subdivisions;
         float v1 = static_cast<float>(i) / subdivisions;

         float u2 = static_cast<float>(j) / subdivisions;
         float v2 = static_cast<float>(i + 1) / subdivisions;

         float u3 = static_cast<float>(j + 1) / subdivisions;
         float v3 = static_cast<float>(i + 1) / subdivisions;

         // First triangle of the quad
         float normal_x = sin(theta) * cos(phi);
         float normal_y = sin(theta) * sin(phi);
         float normal_z = cos(theta);
         glNormal3f(normal_x, normal_y, normal_z);
         glTexCoord2f(u0, v0);
         glVertex3f(x0, y0, z0);

         float normal_x1 = sin(theta) * cos(nextPhi);
         float normal_y1 = sin(theta) * sin(nextPhi);
         float normal_z1 = cos(theta);
         glNormal3f(normal_x1, normal_y1, normal_z1);
         glTexCoord2f(u1, v1);
         glVertex3f(x1, y1, z1);

         float normal_x2 = sin(nextTheta) * cos(phi);
         float normal_y2 = sin(nextTheta) * sin(phi);
         float normal_z2 = cos(nextTheta);
         glNormal3f(normal_x2, normal_y2, normal_z2);
         glTexCoord2f(u2, v2);
         glVertex3f(x2, y2, z2);

         // Second triangle of the quad
         glNormal3f(normal_x2, normal_y2, normal_z2);
         glTexCoord2f(u2, v2);
         glVertex3f(x2, y2, z2);

         glNormal3f(normal_x1, normal_y1, normal_z1);
         glTexCoord2f(u1, v1);
         glVertex3f(x1, y1, z1);

         float normal_x3 = sin(nextTheta) * cos(nextPhi);
         float normal_y3 = sin(nextTheta) * sin(nextPhi);
         float normal_z3 = cos(nextTheta);
         glNormal3f(normal_x3, normal_y3, normal_z3);
         glTexCoord2f(u3, v3);
         glVertex3f(x3, y3, z3);
      }
   }

   glEnd();

   // Disable texture mapping
   glDisable(GL_TEXTURE_2D);
}


void chair(float x, float y, float z, float scale, float theta, int id_leg, int id_seat, int id_backrest){

   glPushMatrix();
   glTranslatef(x, y, z);
   glRotatef(theta, 0, 1, 0);
   glScalef(scale, scale, scale);

   // Draw the legs
   float leg_offset = .4f;
   float leg_width = .03f;
   float leg_height = 0.3f;

   for(int i = 0; i < 2; i++)
      for(int j = 0; j < 2; j++)
         cube(leg_offset * pow(-1, i), .05, leg_offset * pow(-1, j), leg_width, leg_height, leg_width, 0, .5, .5, .5, id_leg);

   // Draw the seat
   float chair_width = 0.5f;
   float chair_depth = .01f;
   float chair_height = 0.35f;
   cube(0, chair_height, 0, chair_width, chair_depth, chair_width, 0, .4, .4, .4, id_seat);

    // Draw the backrest
   cube(0, leg_height + chair_height + .05, chair_width, chair_width, chair_height, chair_depth, 0, .6, .6, .6, id_backrest);

   glPopMatrix();
}


// void sphere(float x, float y, float z, float r, int texture_id){

//     glPushMatrix();
//     glTranslatef(x, y, z);
//     glBindTexture(GL_TEXTURE_2D, texture_id);
    
//     // Enable texture coordinates
//     glEnable(GL_TEXTURE_2D);
//     glEnable(GL_TEXTURE_GEN_S);
//     glEnable(GL_TEXTURE_GEN_T);
    
//     // Generate texture coordinates
//     glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
//     glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);

//     gluSphere(gluNewQuadric(), r, 50, 50);

//     // Disable texture coordinates
//     glDisable(GL_TEXTURE_GEN_S);
//     glDisable(GL_TEXTURE_GEN_T);
//     glDisable(GL_TEXTURE_2D);

//     glPopMatrix();

// }



void sphere(float x, float y, float z, float r, int texture_id, int light_id){
   glPushMatrix();
   glTranslatef(x, y, z);
   
   // Enable lighting
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0 + light_id);
   
   // Set up light properties
   float light_position[] = {0.0f, 1.0f, 0.0f, 0.0f};
   float light_diffuse[] = {1.5f, 1.5f, 1.5f, 1.f};
   glLightfv(GL_LIGHT0 + light_id, GL_POSITION, light_position);
   glLightfv(GL_LIGHT0 + light_id, GL_DIFFUSE, light_diffuse);

   glBindTexture(GL_TEXTURE_2D, texture_id);

   // Enable texture coordinates
   glEnable(GL_TEXTURE_2D);
   glEnable(GL_TEXTURE_GEN_S);
   glEnable(GL_TEXTURE_GEN_T);

   // Generate texture coordinates
   glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
   glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);

   // Set material properties
   float material_diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
   glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);

   gluSphere(gluNewQuadric(), r, 50, 50);

   // Disable texture coordinates
   glDisable(GL_TEXTURE_GEN_S);
   glDisable(GL_TEXTURE_GEN_T);
   glDisable(GL_TEXTURE_2D);

   // Disable lighting
   // glDisable(GL_LIGHT0 + light_id);
   // glDisable(GL_LIGHTING);

   glPopMatrix();
}



void torch(float x, float y, float z, float scale, float theta, int id_wood, int id_fire, int id_light){
   glPushMatrix();
   glTranslatef(x, y, z);
   glRotatef(theta, 0, 1, 0);
   glScalef(scale, scale, scale);
   glRotatef(30, 1, 0, 0);

   // Draw the wood
   const float wood_width = .1f;
   const float wood_height = .5f;
   const float wood_depth = .1f;
   cube(0, 0, 0, wood_width, wood_height, wood_depth, 0, .5, .5, .5, id_wood);

   // Draw the fire with a sphere
   const float fire_radius = .2;
   glTranslatef(0, wood_height, 0);
   sphere(0, 0, 0, fire_radius, id_fire, id_light);
   // cube(0, .5, 0, .5, .5, .5, 0, 1, 1, 1, id_fire);
   

   glPopMatrix();
}



void rug(float x, float y, float z, float width, float length, float th, int texture_id){
   glPushMatrix();
   glScaled(width, 1, length);
   glTranslatef(x, y, z);
   glRotatef(th, 0, 1, 0);

   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, texture_id);

   glBegin(GL_QUADS);
   glNormal3f(0, 1, 0);

   glTexCoord2f(0, 0);glVertex3f(-.5, 0, -.5);

   glTexCoord2f(0, 1);glVertex3f(-.5, 0, .5);

   glTexCoord2f(1, 1);glVertex3f(.5, 0, .5);

   glTexCoord2f(1, 0);glVertex3f(.5, 0, -.5);

   glEnd();

   glDisable(GL_TEXTURE_2D);

   glPopMatrix();
}


void shelf(float x, float y, float z, float width, float height, float depth, float th, int texture_id){
   cube(x, y, z, width, height, depth, th, 1, 1, 1, texture_id);
}


// FAILED ATTEMPT
// void book(float x, float y, float z, float width, float height, float depth, float th, int id_back, int id_side){
//    glPushMatrix();
//    glTranslatef(x, y, z + depth/2.25);
//    glRotatef(th, 0, 1, 0);
//    glScalef(width, height, 1);


//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D, id_back);

//    glBegin(GL_QUADS);
//    glNormal3f(0, 0, 1);

//    glTexCoord2f(0, 0);glVertex3f(-.5, -.5, .5);
//    glTexCoord2f(0, 1);glVertex3f(-.5, .5, .5);
//    glTexCoord2f(1, 1);glVertex3f(.5, .5, .5);
//    glTexCoord2f(1, 0);glVertex3f(.5, -.5, .5);

//    glEnd();

//    glDisable(GL_TEXTURE_2D);

//    glPopMatrix();

//    glPushMatrix();
//    glTranslatef(x + width/2.1, y, z);
//    glRotatef(th, 0, 1, 0);
//    glScalef(1, height, depth);
   
//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D, id_side);

//    glBegin(GL_QUADS);
//    glNormal3f(1, 0, 0);

//    glTexCoord2f(0, 0);glVertex3f(.5, -.5, .5);
//    glTexCoord2f(0, 1);glVertex3f(.5, .5, .5);
//    glTexCoord2f(1, 1);glVertex3f(.5, .5, -.5);
//    glTexCoord2f(1, 0);glVertex3f(.5, -.5, -.5);

//    glEnd();

//    glDisable(GL_TEXTURE_2D);

//    glPopMatrix();


//    glPushMatrix();
//    glTranslatef(x - width/2.1, y, z);
//    glRotatef(th, 0, 1, 0);
//    glScalef(1, height, depth);

//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D, id_side);

//    glBegin(GL_QUADS);
//    glNormal3f(-1, 0, 0);
   
//    glTexCoord2f(0, 0);glVertex3f(-.5, -.5, .5);
//    glTexCoord2f(0, 1);glVertex3f(-.5, .5, .5);
//    glTexCoord2f(1, 1);glVertex3f(-.5, .5, -.5);
//    glTexCoord2f(1, 0);glVertex3f(-.5, -.5, -.5);

//    glEnd();

//    glDisable(GL_TEXTURE_2D);

//    glPopMatrix();


//    glPushMatrix();
//    glTranslatef(x, y + height/2.5, z);
//    glRotatef(th, 0, 1, 0);
//    glScalef(width, 1, depth);

//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D, id_side);

//    glBegin(GL_QUADS);
//    glNormal3f(0, 1, 0);

//    glTexCoord2f(0, 0);glVertex3f(-.5, .5, .5);
//    glTexCoord2f(0, 1);glVertex3f(-.5, .5, -.5);
//    glTexCoord2f(1, 1);glVertex3f(.5, .5, -.5);
//    glTexCoord2f(1, 0);glVertex3f(.5, .5, .5);

//    glEnd();

//    glDisable(GL_TEXTURE_2D);


//    glPopMatrix();
// }


void flag(float x, float y, float z, float width, float height, float stick_height, float th, int id_flag){

   // stick!
   cube(x, y, z, .5, stick_height, .5, 0, 1, 1, 1, id_wood);


   glPushMatrix();
   glTranslatef(x + width/2, y + stick_height - height/2, z);
   glRotatef(th, 0, 1, 0);
   glScalef(width, height, 1);

   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, id_flag);

   glBegin(GL_QUADS);
   glNormal3f(0, 0, 1);

   glTexCoord2f(0, 0);glVertex3f(-.5, -.5, 0);
   glTexCoord2f(0, 1);glVertex3f(-.5, .5, 0);
   glTexCoord2f(1, 1);glVertex3f(.5, .5, 0);
   glTexCoord2f(1, 0);glVertex3f(.5, -.5, 0);

   glEnd();

   glDisable(GL_TEXTURE_2D);

   glPopMatrix();
}


// WHAT!
void cone(float x, float y, float z, float r, float height, int texture_id) {
   glPushMatrix();
   glTranslatef(x, y, z);
   
   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, texture_id);
   

   float top_y = height;
   float bottom_y = 0.0f;

   int subdivisions = 32;
   
   float thetaStep = 2.0f * M_PI / subdivisions;

   glBegin(GL_TRIANGLE_FAN);

   glNormal3f(0.0f, 1.0f, 0.0f);
   glTexCoord2f(0.5f, 0.5f);
   glVertex3f(0.0f, top_y, 0.0f);

   for(int i = 0; i <= subdivisions; ++i){
      float theta = i * thetaStep;

      float x = r * cos(theta);
      float z = r * sin(theta);

      glNormal3f(0.0f, -1.0f, 0.0f);
      glTexCoord2f(0.5f * cos(theta) + 0.5f, 0.5f * sin(theta) + 0.5f);
      glVertex3f(x, bottom_y, z);
   }

   glEnd();


   glBegin(GL_TRIANGLE_FAN);

   glNormal3f(0.0f, -1.0f, 0.0f);
   glTexCoord2f(0.5f, 0.5f);
   glVertex3f(0.0f, bottom_y, 0.0f);

   for(int i = 0; i <= subdivisions; ++i){
      float theta = i * thetaStep;

      float x = r * cos(theta);
      float z = r * sin(theta);

      glNormal3f(0.0f, -1.0f, 0.0f);
      glTexCoord2f(0.5f * cos(theta) + 0.5f, 0.5f * sin(theta) + 0.5f);
      glVertex3f(x, bottom_y, z);
   }

   glEnd();

   glDisable(GL_TEXTURE_2D);

   glPopMatrix();
}




void finalPillar(
double x, double y, double z, double r, double height,
double x0, double y0, double z0, double cone_height
){

   glPushMatrix();
   //  Offset
   glTranslated(x, y, z);
   glScaled(r, height, r);

   cylinder(1, 1, id_rockwall, id_wood);

   glPopMatrix();

   glPushMatrix();
   //  Offset
   glTranslated(x, y + height, z);
   glScaled(r, 1, r);

   const int hollow_height = 25;
   hollowCylinder(1, 0.8, hollow_height, id_rockwall);

   glPopMatrix();


   cone(x0, y0, z0, r, cone_height, id_rockside);
}