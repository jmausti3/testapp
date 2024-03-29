#include "SDL/SDL.h" // Required by SDL
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

// To use OpenGL, uncomment the following line:
//#include "SDL/SDL_opengl.h"

static GLboolean should_rotate  = GL_TRUE;
static GLboolean up             = GL_FALSE;
static GLboolean down           = GL_FALSE;
static GLboolean left           = GL_FALSE;
static GLboolean right          = GL_FALSE;
static float     spinMulti      = 1;
static float     colourModifier = 1;

static void quit(int errorCode){
    SDL_Quit();
    if(errorCode == 10){
        printf("User exited with code %d", errorCode);
    }
    if(errorCode == 0){
        printf("exit success");
    }else{
        printf("exit with code: %d", errorCode);
    }

    exit(errorCode);
}


static void handle_key_down(SDL_keysym* keysym){

    switch(keysym->sym){
        case SDLK_ESCAPE:
            quit(10);
            break;
        case SDLK_SPACE:
            should_rotate = !should_rotate;
            break;

        case SDLK_DOWN:
            if(spinMulti >= .05){
                spinMulti = spinMulti - .05;
            }else {spinMulti = 0;}


            down = !down;
            break;
        case SDLK_RIGHT:
            if(colourModifier < .95){
                colourModifier = colourModifier +.05;
            } else{colourModifier = 1;}
            right = !right;
            break;
        case SDLK_LEFT:
            if(colourModifier >= .05){
                colourModifier = colourModifier - .05;
            } else{colourModifier = 0;}

            left = !left;
            break;
        case SDLK_UP:
            spinMulti = spinMulti + .05;


            up = !up;

            break;
        default:
            break;
    }


}

static void process_events(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_KEYDOWN:
                handle_key_down(&event.key.keysym);
                break;
            case SDL_QUIT:
                quit(0);
                break;
            default:
                break;
        }
    }
}

static void draw_screen( void )
{
    /* Our angle of rotation. */
    static float angle = 0.0f;

    /*
     * EXERCISE:
     * Replace this awful mess with vertex
     * arrays and a call to glDrawElements.
     *
     * EXERCISE:
     * After completing the above, change
     * it to use compiled vertex arrays.
     *
     * EXERCISE:
     * Verify my windings are correct here ;).
     */
    static GLfloat v0[] = { -1.0f, -1.0f,  1.0f };
    static GLfloat v1[] = {  1.0f, -1.0f,  1.0f };
    static GLfloat v2[] = {  1.0f,  1.0f,  1.0f };
    static GLfloat v3[] = { -1.0f,  1.0f,  1.0f };
    static GLfloat v4[] = { -1.0f, -1.0f, -1.0f };
    static GLfloat v5[] = {  1.0f, -1.0f, -1.0f };
    static GLfloat v6[] = {  1.0f,  1.0f, -1.0f };
    static GLfloat v7[] = { -1.0f,  1.0f, -1.0f };

    GLubyte colorVal = (GLubyte)255*colourModifier;

    printf("%d\n", colorVal);
    static GLubyte red[]    = { colorVal,   0,   0, 255 };
    static GLubyte green[]  = {   0, colorVal,   0, 255 };
    static GLubyte blue[]   = {   0,   0, colorVal, 255 };
    static GLubyte white[]  = { colorVal, colorVal, colorVal, 255 };
    static GLubyte yellow[] = {   0, colorVal, colorVal, 255 };
    static GLubyte black[]  = {   0,   0,   0, 255 };
    static GLubyte orange[] = { colorVal, colorVal,   0, 255 };
    static GLubyte purple[] = { colorVal,   0, colorVal,   0 };

    /* Clear the color and depth buffers. */
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );



    /* We don't want to modify the projection matrix. */
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );

    /* Move down the z-axis. */
    glTranslatef( 0.0, 0.0, -5.0 );

    glRotatef(angle, 1.0, 1.0, 1.0);

//    printf("the angle is %f;\nthe spinMulti is %f", angle, spinMulti);
    if(should_rotate){

        angle = angle + (1*spinMulti);
        if( angle > 360.0){
            angle = 0.0f;
        }
    }

    glBegin(GL_TRIANGLES);
//
//    glColor4ubv(green);
//    glVertex3fv(v0);
//    glVertex3fv(v1);
//    glVertex3fv(v2);
//
//    glVertex3fv(v0);
//    glVertex3fv(v2);
//    glVertex3fv(v3);
//
//    glVertex3fv(v1);
//    glVertex3fv(v0);
//    glVertex3fv(v4);
//
//    glColor4ubv(blue);
//    glVertex3fv(v1);
//    glVertex3fv(v4);
//    glVertex3fv(v5);

//    glVertex3fv(v3);
//    glVertex3fv(v4);
//    glVertex3fv(v5);
//    glVertex3fv(v6);
//    glVertex3fv(v7);



    glColor4ubv( red );
    glVertex3fv( v0 );
    glColor4ubv( green );
    glVertex3fv( v1 );
    glColor4ubv( blue );
    glVertex3fv( v2 );

    glColor4ubv( red );
    glVertex3fv( v0 );
    glColor4ubv( blue );
    glVertex3fv( v2 );
    glColor4ubv( white );
    glVertex3fv( v3 );

    glColor4ubv( green );
    glVertex3fv( v1 );
    glColor4ubv( black );
    glVertex3fv( v5 );
    glColor4ubv( orange );
    glVertex3fv( v6 );

    glColor4ubv( green );
    glVertex3fv( v1 );
    glColor4ubv( orange );
    glVertex3fv( v6 );
    glColor4ubv( blue );
    glVertex3fv( v2 );

    glColor4ubv( black );
    glVertex3fv( v5 );
    glColor4ubv( yellow );
    glVertex3fv( v4 );
    glColor4ubv( purple );
    glVertex3fv( v7 );

    glColor4ubv( black );
    glVertex3fv( v5 );
    glColor4ubv( purple );
    glVertex3fv( v7 );
    glColor4ubv( orange );
    glVertex3fv( v6 );

    glColor4ubv( yellow );
    glVertex3fv( v4 );
    glColor4ubv( red );
    glVertex3fv( v0 );
    glColor4ubv( white );
    glVertex3fv( v3 );

    glColor4ubv( yellow );
    glVertex3fv( v4 );
    glColor4ubv( white );
    glVertex3fv( v3 );
    glColor4ubv( purple );
    glVertex3fv( v7 );

    glColor4ubv( white );
    glVertex3fv( v3 );
    glColor4ubv( blue );
    glVertex3fv( v2 );
    glColor4ubv( orange );
    glVertex3fv( v6 );

    glColor4ubv( white );
    glVertex3fv( v3 );
    glColor4ubv( orange );
    glVertex3fv( v6 );
    glColor4ubv( purple );
    glVertex3fv( v7 );

    glColor4ubv( green );
    glVertex3fv( v1 );
    glColor4ubv( red );
    glVertex3fv( v0 );
    glColor4ubv( yellow );
    glVertex3fv( v4 );

    glColor4ubv( green );
    glVertex3fv( v1 );
    glColor4ubv( yellow );
    glVertex3fv( v4 );
    glColor4ubv( black );
    glVertex3fv( v5 );

    glEnd();

    SDL_GL_SwapBuffers();
}

static void setup_opengl(int width, int height){

    float ratio = (float) width / (float) height;

    glShadeModel(GL_SMOOTH);

    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);
    glEnable(GL_CULL_FACE);

    glClearColor(0, 0, 0, 0 );

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(60.0, ratio, 1.0, 1024.0);

}

int main(int argc, char *argv[]) {

    const SDL_VideoInfo* info = NULL;
    int width = 0;
    int height = 0;
    int bpp = 0;
    int flags = 0;

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("error1");
        quit(1);
        return -1;
    }

    info = SDL_GetVideoInfo();

    if(!info){
        printf("error2");
        quit(2);
        return -1;
    }

    width = 640;
    height = 480;
    bpp = info->vfmt->BitsPerPixel;

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    flags = SDL_OPENGL | SDL_NOFRAME;

    if(SDL_SetVideoMode(width, height, bpp, flags) == 0){
        printf("error3");
        quit(3);
        return -1;
    }

    setup_opengl(width, height);

    while(1){
        process_events();
        draw_screen();

    }
    return 0;
}