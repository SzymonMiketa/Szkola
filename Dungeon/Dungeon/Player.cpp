#include "Player.h"
#include "Create_objects.h"

Player::Player(string FileName, Audio & audio)
{
	if (!PlayerTexture.loadFromFile(FileName))
	{
		std::cout << "blad";
	}
	PlayerSprite.setTexture(PlayerTexture);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Frames.push_back(sf::IntRect(j * 16, i * 16, 16, 16));
		}
	}
	PlayerSprite.setTextureRect(Frames[0]);
	PlayerSprite.setOrigin(8, 8);
	CurrentFrame = 0;
	speed = 1.5;
	CurrentWeaponSpeed = 2;
	CurrentReloadSpeed = 0.05;
	isReloaded = 0;
	maxhitpoints = 100;
	hitpoints = 100;
	R = 10;
	buffer.push_back(&audio.buffer[0]);
	buffer.push_back(&audio.buffer[2]);
	buffer.push_back(&audio.buffer[3]);
	buffer.push_back(&audio.buffer[4]);
	exp = 0;
	CurrentDamage = 10;
}

Player::~Player()
{

}

void Player::Update_GUI()
{
	gui.Set_Sprites(maxhitpoints, hitpoints, exp);
}

bool Player::check_collision(TileMap & map)
{
	int temp = map.ReturnValue(TilePositionX, TilePositionY);
	if (temp == 63 || temp == 64 || temp == 84 || temp == 105 || temp == 106 || temp == 108 || temp == 87 || temp == 66 || temp == 65 || temp == 107)
	{
		return 0;
	}
	return 1;
}


void Player::action(TileMap & map)
{
	TilePositionX = PlayerSprite.getPosition().x;
	TilePositionX = TilePositionX / 16;
	TilePositionY = PlayerSprite.getPosition().y;
	TilePositionY = TilePositionY / 16;
}

void Player::draw(sf::RenderWindow & window)
{
	gui.draw(window);
	window.draw(PlayerSprite);
}

void Player::SetPosition(int x, int y)
{
	PlayerSprite.setPosition(x, y);
}



void Player::update(TileMap & map, Create_objects & o, Audio & audio)
{
	if (hitpoints > maxhitpoints)
	{
		hitpoints = maxhitpoints;
	}
	Update_GUI();
	sf::Vector2f position = PlayerSprite.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		if (CurrentFrame < 8 || CurrentFrame >= 12)
		{
			CurrentFrame = 8;
		}
		else
		{
			CurrentFrame = CurrentFrame + (speed * 0.1);
			if (CurrentFrame >= 12)
			{
				CurrentFrame = 8;
			}
		}
		PlayerSprite.move(speed, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		if (CurrentFrame < 12 || CurrentFrame >= 15)
		{
			CurrentFrame = 12;
		}
		else
		{
			CurrentFrame = CurrentFrame + (speed * 0.1);
			if (CurrentFrame >= 15)
			{
				CurrentFrame = 12;
			}
		}
		PlayerSprite.move(0, -speed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		if (CurrentFrame < 4 || CurrentFrame >= 8)
		{
			CurrentFrame = 4;
		}
		else
		{
			CurrentFrame = CurrentFrame + (speed * 0.1);
			if (CurrentFrame >= 8)
			{
				CurrentFrame = 4;
			}
		}
		PlayerSprite.move(-speed, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		if (CurrentFrame >= 4)
		{
			CurrentFrame = 0;
		}
		else
		{
			CurrentFrame = CurrentFrame + (speed * 0.1);
			if (CurrentFrame >= 4)
			{
				CurrentFrame = 0;
			}
		}
		PlayerSprite.move(0, speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		shoot(o, audio);
	}
	action(map);
	if (check_collision(map) == 0)
	{
		PlayerSprite.setPosition(position);
	}
	PlayerSprite.setTextureRect(Frames[CurrentFrame]);
	if (isReloaded < 1)
	{
		isReloaded += CurrentReloadSpeed;
	}
	x = PlayerSprite.getPosition().x;
	y = PlayerSprite.getPosition().y;
}

void Player::HitByProjectile(bool & a, int & b)
{
	if (a == true) //a == true - wrogi pocisk
	{
		hitpoints -= b;
		if (hitpoints > 0)
		{
			s2.setBuffer(*buffer[2]);
			s2.play();
		}
		else
		{
			s2.setBuffer(*buffer[3]);
			s2.play();
		}
	}
}

void Player::BuffedByPotion()
{
	s2.setBuffer(*buffer[1]);
	s2.play();
}

void Player::shoot(Create_objects & o, Audio & audio)
{
	if (isReloaded >= 1)
	{
		float tmpX = 0, tmpY = 0;
		if (CurrentFrame < 4) tmpY = CurrentWeaponSpeed;
		else if (CurrentFrame >= 4 && CurrentFrame < 8) tmpX = -CurrentWeaponSpeed;
		else if (CurrentFrame >= 8 && CurrentFrame < 12) tmpX = CurrentWeaponSpeed;
		else tmpY = -CurrentWeaponSpeed;
		o.Create_New_Projectile(sf::IntRect(6 * 16, 21 * 16, 16, 16), PlayerSprite.getPosition().x, PlayerSprite.getPosition().y, false, 10, tmpX, tmpY, 0, CurrentDamage, 1, audio);
		isReloaded = 0;
		s.setBuffer(*buffer[0]);
		s.play();
	}

}


const type_info & Player::return_type()
{
	return typeid(this);
}

