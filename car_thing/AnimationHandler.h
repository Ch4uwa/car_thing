#ifndef ANIMATIONHANDLER_H
#define ANIMATIONHANDLER_H

#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{
public:

	unsigned int startFrame;
	unsigned int endFrame;

	float duration;

	Animation(unsigned int startFrame, unsigned int endFrame, float duration)
		: startFrame(startFrame), endFrame(endFrame), duration(duration) {};

	unsigned int getLength() { return endFrame - startFrame + 1; }

};


class AnimationHandler
{
private:
	/* Array of animations */
	std::vector<Animation> animations;

	/* Current time since the animation loop started */
	float t;
	int currentAnim;

public:
	void addAnim(Animation& anim);
	void update(const float dt);
	void changeAnim(unsigned int animNum);

	sf::IntRect bounds;
	sf::IntRect frameSize;

	AnimationHandler() :t(0.0f), currentAnim(-1) {};
	AnimationHandler(const sf::IntRect& frameSize) :frameSize(frameSize),t(0.0f), currentAnim(-1) {};
	~AnimationHandler();
};

#endif // !ANIMATIONHANDLER_H
