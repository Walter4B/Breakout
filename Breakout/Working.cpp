#include <string>
#include <vector>

constexpr int windowWidth{ 800 }, windowHeight{ 600 };

class Game
{
public:
	//std::vector <Brick> bricks;
};
class Brick
{
private:
	int widthPX;
	int heightPX;
	int hitPoints;
	int scoreValue;
	std::string audioPathHit;
	std::string audioPathBreak;
	std::string texturePath;

public:
	Brick(char hardnessChar) {
		widthPX = 32;
		heightPX = 16;
		switch (hardnessChar)
		{
		case 'I':
			hitPoints = 0;
			audioPathHit = "path";
			texturePath = "path";
			break;
		case 'S':
			hitPoints = 1;
			scoreValue = 50;
			audioPathHit = "path";
			audioPathBreak = "path";
			texturePath = "path";
			break;
		case 'M':
			hitPoints = 2;
			scoreValue = 100;
			audioPathHit = "path";
			audioPathBreak = "path";
			texturePath = "path";
			break;
		case 'H':
			hitPoints = 3;
			scoreValue = 150;
			audioPathHit = "path";
			audioPathBreak = "path";
			texturePath = "path";
			break;

		default:
			break;
		}
	}
	~Brick() {}

	int hpCheck()
	{
		--hitPoints;
		if (hitPoints < 0)
		{
			hitPoints++;
			return 0;
		}
		else if (hitPoints == 0)
		{
			return 1;
		}
		else
			return 0;
	}

	void Collision()
	{
		if (hpCheck())
		{
		}
	}


};

int main2()
{
	int countOfBricks = 45;

	int widthPX;
	int heightPX;
	int hitPoints;
	int scoreValue;
	std::string audioPathHit;
	std::string audioPathBreak;
	std::string texturePath;

	for (int i = 0; i < countOfBricks; i++)
	{
	}
	//Brick* pBrickArray = new Brick();
	//std::vector<Brick> bricks;
	return 0;
}