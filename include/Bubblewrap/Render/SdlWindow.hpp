#ifndef BUBBLEWRAP_SDL_RENDER_SDLWINDOW_HPP
#define BUBBLEWRAP_SDL_RENDER_SDLWINDOW_HPP


#include "Bubblewrap/Managers/BaseManager.hpp"
#include "Bubblewrap/Render/Window.hpp"
#include <functional>
#include <SDL.h>
namespace Bubblewrap
{
	namespace Render
	{
		/*! An implementation of Window using Sdl's sf::RenderWindow */
		class SdlWindow
			: public Window
		{
		public:
			/*! Creates an SdlWindow
			\param Settings The settings that should be used to setup the window */
			SdlWindow( Window::WindowSettings Settings );

			/*! Destroys the SdlWindow
			*/
			~SdlWindow();

			void Update( float dt );
			void Display();
			void HandleEvents();

			/*! Performs a function on the RenderWindow 
			\param Function The function that should be called on Window
			*/
			void Do( std::function<void( void* Window )> Function );

			/*! Creates a new Window
			\param Params a pointer to the parameters that should be used to create the window
			\returns A pointer to a new window
			*/
			static Window* Create( void *Params, Managers::Managers* Owner );

			virtual void* GetInternalPointer();
		private:
			int defaultWindow = 0;
			// sf::RenderWindow* sfWindow_;
			/*! The Window that we'll be rendering to
			*/
			SDL_Window* Window_;
			/*! The surface we'll be drawing to
			*/
			SDL_Surface* Surface_;

		};

	}
}

#endif