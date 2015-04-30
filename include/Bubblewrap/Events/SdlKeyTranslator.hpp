#ifndef BUBBLEWRAP_SDL_EVENTS_SDLKEYTRANSLATOR_HPP
#define BUBBLEWRAP_SDL_EVENTS_SDLKEYTRANSLATOR_HPP

#include "Bubblewrap/Events/EventKeyInput.hpp"

namespace Bubblewrap
{
	namespace Events
	{
		/*! Translates an sf::Keyboard::Key into a Bubblewrap::Events::Key
		\param key Sdl keycode
		\returns The corresponding Bubblewrap keycode 
		*/
		Key TranslateKey( int key );
	}

}

#endif