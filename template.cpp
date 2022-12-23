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

	//Asignacion de variables para posición en eje X y Y
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
		playerX += moveThisFrame;
	}
	if (agk::GetRawKeyState(AGK_KEY_LEFT) || agk::GetRawKeyState(AGK_KEY_A))
	{
		playerX -= moveThisFrame;
	}

	agk::SetSpritePositionByOffset(cheems, playerX, playerY);

	agk::Sync();

	return 0; // return 1 to close app
}


void app::End (void)
{

}
