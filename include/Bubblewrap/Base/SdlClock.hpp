#ifndef BUBBLEWRAP_SDL_BASE_SDLCLOCK_HPP
#define BUBBLEWRAP_SDL_BASE_SDLCLOCK_HPP

#include "Bubblewrap/Base/Clock.hpp"
namespace Bubblewrap
{
	namespace Base
	{
		/*! An implementation of Clock using Sdl's sf::Clock*/
		class SdlClock
			: public Clock
		{
		public:
			CREATE_REGISTER_OVERRIDE( SdlClock, Clock );

		public:
			Time GetElapsedTime();
			void Update( float dt );

		private:
		};
	}
}


#endif