#include "raylib.h"
#include "string"
using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;

float xBall = 50;
float yBall = 100;
float ballSize = 32;
int ballXSpeed = 5;
int ballYSpeed = -5;
Rectangle balle{xBall, yBall, ballSize, ballSize};

float raquetteGaucheHeight = 128;
Rectangle raquetteGauche{0, 100, 32, raquetteGaucheHeight};
int vitesseRaquetteGauche = 4;

void load();
void draw();
void update();
void unload();

void load()
{
   InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");
   SetTargetFPS(60);
}

void draw()
{
    BeginDrawing();
    ClearBackground(BLACK);
    DrawRectangleRec(balle, WHITE);
    DrawRectangleRec(raquetteGauche, WHITE);
    EndDrawing();
}

void update()
{
    balle.x = balle.x + ballXSpeed;
    balle.y = balle.y + ballYSpeed;

    if (balle.y < 0)
    {
        ballYSpeed = -ballYSpeed;
    };
    
    if (balle.y + ballSize > SCREEN_HEIGHT)
    {
        ballYSpeed = -ballYSpeed;
    };

    if (balle.x < 0)
    {
        ballXSpeed = -ballXSpeed;
    };
    
    if (balle.x + ballSize> SCREEN_WIDTH)
    {
        ballXSpeed = -ballXSpeed;
    };

    if (IsKeyDown(KEY_S) && (raquetteGauche.y + raquetteGaucheHeight < SCREEN_HEIGHT)) {
        raquetteGauche.y = raquetteGauche.y + vitesseRaquetteGauche;
    } else if (IsKeyDown(KEY_W) && (raquetteGauche.y > 0)){
         raquetteGauche.y = raquetteGauche.y - vitesseRaquetteGauche;
    }
    
    
}



void unload() 
{
   CloseWindow();
}

int main(void)
{
   load();
   while (!WindowShouldClose())
   {
       update();
       draw();
    }

    unload();
    return 0;
}