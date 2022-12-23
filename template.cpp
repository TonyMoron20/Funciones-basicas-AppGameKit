// Includes
#include "template.h"

app App;

//Asignando valor para la variable de velocidad del jugador
const float app::speed = 200.0f;

void app::Begin(void)
{
	agk::SetVirtualResolution (1024, 768);
	agk::SetClearColor( 151,170,204 ); // light blue
	agk::SetSyncRate(60,0);
	agk::SetScissor(0,0,0,0);

	//Asignando imagenes a las variables tipo unsigned int
	background = agk::LoadSprite("media/space.jpg");
	cheems = agk::LoadSprite("media/musculo.png");

	//Asignacion de variables para posici�n en eje X y Y
	playerX = agk::GetVirtualWidth() / 2.0f;
	playerY = agk::GetVirtualHeight() / 2.0f;

	//Posicionando al sprite del jugador
	agk::SetSpritePositionByOffset(cheems, playerX, playerY);


}

int app::Loop (void)
{
	const float moveThisFrame = speed * agk::GetFrameTime();

	//Controles para mover al jugador
	if (agk::GetRawKeyState(AGK_KEY_UP) || agk::GetRawKeyState(AGK_KEY_W))
	{
		playerY -= moveThisFrame;
	}
	if (agk::GetRawKeyState(AGK_KEY_DOWN) || agk::GetRawKeyState(AGK_KEY_S))
	{
		playerY += moveThisFrame;
	}
	if (agk::GetRawKeyState(AGK_KEY_RIGHT) || agk::GetRawKeyState(AGK_KEY_D))
	{
		agk::SetSpriteFlip(cheems, 0, 0);
		playerX += moveThisFrame;
	}
	if (agk::GetRawKeyState(AGK_KEY_LEFT) || agk::GetRawKeyState(AGK_KEY_A))
	{
		agk::SetSpriteFlip(cheems, 1, 0);
		playerX -= moveThisFrame;
	}

	//variables para posici�n minima y maxima donde el jugador podra moverse
	const float minY = agk::GetSpriteHeight(cheems) / 2.0f;
	const float maxY = agk::GetVirtualHeight() - minY;
	const float minX = agk::GetSpriteWidth(cheems) / 2.0f;
	const float maxX = agk::GetVirtualWidth() - minX;

	//Condicion para restringir el movimiento del jugador mas all� de los bordes de la ventana
	if (playerY < minY)
	{
		playerY = minY;
	}
	else if (playerY > maxY)
	{
		playerY = maxY;
	}
	if (playerX < minX)
	{
		playerX = minX;
	}
	else if (playerX > maxX)
	{
		playerX = maxX;
	}

	//Actualizara la posici�n del jugador
	agk::SetSpritePositionByOffset(cheems, playerX, playerY);

	agk::Sync();

	return 0; // return 1 to close app
}


void app::End (void)
{

}
