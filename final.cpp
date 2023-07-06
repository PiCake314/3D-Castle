#include "input-handler.hpp"


const char *modeText(){
   if(mode == PERSP) return "Overhead Presp";
   else if(mode == ORTHO) return "Overhead Ortho";
   return "1st Person";
}


// --------------------------------------------------------------------------------------------

void drawAxis(int len){

   // Drawing axis
   glBegin(GL_LINES);
   glColor3f(1,1,1);


   glVertex3d(0, 0, 0);
   glVertex3d(len, 0, 0);

   
   glVertex3d(0, 0, 0);
   glVertex3d(0, len, 0);

   
   glVertex3d(0, 0, 0);
   glVertex3d(0, 0, len);


   glEnd();

   glWindowPos2i(5,5);
   // Label axis

   
   glRasterPos3d(len, 0, 0);
   Print("X");

   glRasterPos3d(0, len, 0);
   Print("Y");

   glRasterPos3d(0, 0, len);
   Print("Z");

}


void light(){
   //  Translate intensity to color vectors
   float Ambient[]   = {0.3,0.3,0.3,1.0};
   float Diffuse[]   = {1,1,1,1};
   float Specular[]  = {1,1,0,1};
   float white[]     = {1,1,1,1};
   //  Light direction
   int rev_r = 10;
   float Position[]  = {float(rev_r*Cos(lightSpeed)), 5, float(rev_r*Sin(lightSpeed)), 1};
   //  Draw light position as ball (still no lighting here)
   ball(Position[0], Position[1], Position[2] , 0.1);

   //  Enable lighting with normalization
   glEnable(GL_LIGHTING);
   glEnable(GL_NORMALIZE);
   //  glColor sets ambient and diffuse color materials
   glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
   glEnable(GL_COLOR_MATERIAL);
   //  Enable light 0
   glEnable(GL_LIGHT0);
   glLightfv(GL_LIGHT0, GL_AMBIENT , Ambient);
   glLightfv(GL_LIGHT0, GL_DIFFUSE , Diffuse);
   glLightfv(GL_LIGHT0, GL_SPECULAR, Specular);
   glLightfv(GL_LIGHT0, GL_POSITION, Position);
   glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 32.0f);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);

   // glDisable(GL_LIGHTING);
}


// const double desiredFrameTime = 1.0 / 120.0;


const int gap = 25;
const int side = 100 - gap;
const int width = 2;
const int dist = side + width + gap;
const int height = 40;
const float r = gap + 2;
const float bed_width = 25;
const float bed_length = 45;
const float desk_length = 30;
const float desk_width = 15;
const float scale = 10;
const float gate_width = dist/1.5;

void display(){

   // auto frameStartTime = std::chrono::high_resolution_clock::now();


   //  Erase the window and the depth buffer
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   setupProjection();
   //  Enable Z-buffering in OpenGL
   glEnable(GL_DEPTH_TEST);

   //  Undo previous transformations
   glLoadIdentity();
   // gluLookAt(Ex,Ey,Ez , Ox,Oy,Oz , 0,1,0);

   glRotatef(xTh, 1, 0, 0);
   glRotatef(yTh, 0, 1, 0);

   glTranslatef(xShift, yShift, zShift);
   // -----------------------

   
   setMode();


   if(xShift >= -100 && xShift <= 100 && zShift >= -100 && zShift <= 100 && yShift >= -65 && yShift <= 0){
      torch(0, 30, -dist + 3, 5, 0, id_wood, id_fire, 2);

      torch(-dist + 3, 30, -40 + 3, 5, 90, id_wood, id_fire, 4);
      torch(+dist - 3, 30, -40 + 3, 5, 270, id_wood, id_fire, 5);

      torch(-dist + 3, 30, +40 + 3, 5, 90, id_wood, id_fire, 6);
      torch(+dist - 3, 30, +40 + 3, 5, 270, id_wood, id_fire, 7);

      torch(-40, 30, dist - 3, 5, 180, id_wood, id_fire, 1);
      torch(+40, 30, dist - 3, 5, 180, id_wood, id_fire, 3);
   }
   else{
      glPushMatrix();
      glScalef(20, 20, 20);
      light();
      glPopMatrix();
   }



   // putting the ground
   ground(0, 0, 0, dist, id_woodengeround);

   // setting up the walls
   wall(0, side/2 + 1, dist, side, height, width, 0);
   wall(dist, side/2 + 1, 0, side, height, width, 90);
   wall(0, side/2 + 1, -dist, side, height, width, 180);
   wall(-dist, side/2 + 1, 0, side, height, width, 270);


   // setting up the pillars
   pillar(dist, 0, dist, r, height + 30);
   pillar(-dist, 0, dist, r, height + 30);
   pillar(dist, 0, -dist, r, height + 30);
   pillar(-dist, 0, -dist, r, height + 30);

   // gate
   halfOval(0, 0, dist+5, gate_width, 2.5*height, id_wood);

   // gate sides
   prism(gate_width/2 + 15, 0, dist+9, 7, 50, id_rockside);
   prism(-gate_width/2 - 15, 0, dist+9, 7, 50, id_rockside);

   // roof
   ground(0, side - 10, 0, dist, id_woodengeround);


   table(bed_width, 10, -dist + bed_length/2 - 10, 10, 10, 15, id_wood, id_wood);

   bedFrame(0, 5.1, -dist + bed_length/2 + 3, bed_width, bed_length, 15, id_wood, id_wood);
   mattress(0, 6, -dist + bed_length/2 + 3, bed_width/2 -.5, bed_length/2 - .5, 1, id_fabric);
   pillow(0, 10, -dist + bed_length/2 - 10, 10, 3, 7, id_fabric);


   // DESK
   table(-dist + desk_width/2, 10, -20 + bed_length/2 - 10, desk_width, desk_length, 15, id_wood, id_wood);
   chair(-dist + desk_width/2 + scale, 2.5, -20 + bed_length/2 - 10, scale, 90, id_wood, id_rockside, id_wood);

   rug(0, 0.01, 0, 75, 50, 0, id_rug);

   shelf(dist - 7, 25, 0, 15, 1, 5, 90, id_shelf);
   cube(dist - 7, 29, -2, 10, 3, 2.5, 90, 1, 1, 1, id_books);


   shelf(dist - 7, 40, 0, 15, 1, 5, 90, id_shelf);
   cube(dist - 7, 44, 0, 10, 3, 6, 90, 1, 1, 1, id_morebooks);

   flag(-dist, side + 25,  dist, 30, 15, 30, 0, id_kuwait);



   // FINAL TOUCHE!!?
   finalPillar(0, side - 9.99, 0, r, height + 60, 0, side + height + 75, 0, 75);
   flag(0, side + height + 160,  0, 30, 15, 15, 0, id_kuwait);

   


   glDisable(GL_LIGHTING);



   glTranslatef(0, 1, 0);
   drawAxis(dist/2);
   glTranslatef(0, -1, 0);


   glRotatef(xTh, 1, 0, 0);
   glRotatef(yTh, 0, 1, 0);


   // -----------------------

   // auto frameEndTime = std::chrono::high_resolution_clock::now();
   // double elapsedFrameTime = std::chrono::duration<double>(frameEndTime - frameStartTime).count();

   // // Calculate remaining time to reach desired frame time
   // double remainingFrameTime = desiredFrameTime - elapsedFrameTime;

   // if(remainingFrameTime > 0.0){
   //    // Sleep or wait to achieve the desired frame time
   //    std::this_thread::sleep_for(std::chrono::duration<double>(remainingFrameTime));
   // }



   //  Five pixels from the lower left corner of the window
   glColor3f(1, 1, 1);
   glWindowPos2i(5,5);
   Print(
      "X: %g, Y: %g, Z: %g, xTh: %g, yTh: %g, MODE: %s (%d), ROT: %g", 
      xShift, yShift, zShift, xTh, yTh,
      modeText(), mode, viewing_angle
   );


   //  Render the scene
   ErrCheck("display");
   glFlush();
   glutSwapBuffers();
}


void loadTextures(){

   id_rockwall = LoadTexBMP("textures/rockwall2.bmp");
   id_rockside = LoadTexBMP("textures/brokenwall1.bmp");
   id_wood = LoadTexBMP("textures/wood.bmp");
   id_woodengeround = LoadTexBMP("textures/weathered_planks_diff_1k.bmp");
   id_fabric = LoadTexBMP("textures/fabric.bmp");
   id_fire = LoadTexBMP("textures/fire2.bmp");
   id_rug = LoadTexBMP("textures/rug2.bmp");
   id_shelf = LoadTexBMP("textures/shelf.bmp");
   id_books = LoadTexBMP("textures/books.bmp");
   id_morebooks = LoadTexBMP("textures/morebooks.bmp");
   id_bookside = LoadTexBMP("textures/bookside.bmp");
   id_kuwait = LoadTexBMP("textures/kuwait.bmp");

}


/*
 *  Main
 */
int main(int argc, char *argv[])
{
   
   //  Initialize GLUT
   glutInit(&argc,argv);
   glutInitWindowSize(1080, 720);
   //  Request double buffered true color window with Z-buffer
   glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
   //  Create window
   glutCreateWindow("Ali Almutawa Jr.: A Medieval Castle!");

#ifdef USEGLEW
   //  Initialize GLEW
   if (glewInit()!=GLEW_OK) Fatal("Error initializing GLEW\n");
#endif

   //  Register display, reshape and key callbacks
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutSpecialFunc(special);
   glutSpecialUpFunc(specialUp);
   glutKeyboardFunc(keyboard);
   glutKeyboardUpFunc(keyboardUp);
   glutIdleFunc(idle);
   glutMotionFunc(motion);
   glutMouseFunc(mouse);
   // glutPassiveMotionFunc(motion);

   //  Enable Z-buffer depth test
   glEnable(GL_DEPTH_TEST);

   loadTextures();

   //  Pass control to GLUT for events
   glutMainLoop();

   return 0;
}