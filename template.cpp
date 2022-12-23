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

	//Evita que la ventana de ejecución se pueda cambiar de tamaño
	agk::SetWindowAllowResize(0);

	//Es el titulo que aparece en lo alto del borde de la pantalla de ejecución
	agk::SetWindowTitle("Cheems Game");

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
	//Variables de movimiento en eje X y Y
	float moveX = 0.0f;
	float moveY = 0.0f;

	//Controles para mover al jugador
	if (agk::GetRawKeyState(AGK_KEY_UP) || agk::GetRawKeyState(AGK_KEY_W))
	{
		moveY -= 1.0f;
	}
	if (agk::GetRawKeyState(AGK_KEY_DOWN) || agk::GetRawKeyState(AGK_KEY_S))
	{
		moveY += 1.0f;
	}
	if (agk::GetRawKeyState(AGK_KEY_RIGHT) || agk::GetRawKeyState(AGK_KEY_D))
	{
		agk::SetSpriteFlip(cheems, 0, 0);
		moveX += 1.0f;
	}
	if (agk::GetRawKeyState(AGK_KEY_LEFT) || agk::GetRawKeyState(AGK_KEY_A))
	{
		agk::SetSpriteFlip(cheems, 1, 0);
		moveX -= 1.0f;
	}

	//Calculo para conocer la distancia
	const float moveDistance = agk::Sqrt((moveY * moveY) + (moveX * moveX));
	if (moveDistance > 0.0f)
	{
		playerX += (moveX / moveDistance) * moveThisFrame;
		playerY += (moveY / moveDistance) * moveThisFrame;
	}


	//variables para posición minima y maxima donde el jugador podra moverse
	const float minY = agk::GetSpriteHeight(cheems) / 2.0f;
	const float maxY = agk::GetVirtualHeight() - minY;
	const float minX = agk::GetSpriteWidth(cheems) / 2.0f;
	const float maxX = agk::GetVirtualWidth() - minX;

	//Condicion para restringir el movimiento del jugador mas allá de los bordes de la ventana
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

	//Actualizara la posición del jugador
	agk::SetSpritePositionByOffset(cheems, playerX, playerY);

	agk::Sync();

	return 0; // return 1 to close app
}


void app::End (void)
{

}
