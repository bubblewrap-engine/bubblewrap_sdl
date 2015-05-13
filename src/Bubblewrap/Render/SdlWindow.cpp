#include "Bubblewrap/Render/SdlWindow.hpp"
#include "Bubblewrap/Managers/Managers.hpp"
#include "Bubblewrap/Base/Game.hpp"
#include "Bubblewrap/Events/Events.hpp"
#include "Bubblewrap/Events/EventManager.hpp"
// #include "Sdl/Graphics.hpp"
#include "Bubblewrap/Events/SdlKeyTranslator.hpp"

namespace Bubblewrap
{
	namespace Render
	{
		SdlWindow::SdlWindow( Window::WindowSettings Settings )
			: Window( Settings )
		{
			// Window_ = sfWindow_ = new sf::RenderWindow( sf::VideoMode( Settings.Width_, Settings.Height_ ), Settings.Title_ );
			Window_ = SDL_CreateWindow( Settings.Name_.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Settings.Width_, Settings.Height_, SDL_WINDOW_SHOWN );
			//Get window surface
			Surface_ = SDL_GetWindowSurface( Window_ );
		}

		SdlWindow::~SdlWindow()
		{
			SDL_DestroyWindow( Window_ );
		}

		Window* SdlWindow::Create( void* Params, Managers::Managers* Owner )
		{
			Window::WindowSettings* Settings = ( Window::WindowSettings* )Params;
			return ( Window* ) ( new SdlWindow( *Settings ) );
		}
	

		void SdlWindow::Update( float dt )
		{
			// sfWindow_->clear(sf::Color( ClearColour_.R(), ClearColour_.G(), ClearColour_.B() ));
			//Fill the surface white
			//SDL_FillRect( Surface_, NULL, SDL_MapRGB( Surface_->format, ClearColour_.R(), ClearColour_.G(), ClearColour_.B() ) );
		}

		void SdlWindow::Display()
		{ 


			Window::Display();
			// sfWindow_->display();
			//Update the surface
			SDL_UpdateWindowSurface( Window_ );
		}

		void SdlWindow::HandleEvents()
		{
			SDL_Event event;
			while ( SDL_PollEvent( &event ) )
			{

			}
				/*sf::Event event;
			while ( sfWindow_->pollEvent( event ) )
			{
				// sm->Input( event );
				//if ( event.type == sf::Event::Closed )
				//window.close();
				if ( ( event.type == sf::Event::KeyPressed ) )
				{
					auto code = Bubblewrap::Events::TranslateKey( event.key.code );
					Events::InputData* newEvent = new Events::InputData();
					newEvent->InputType_ = Events::InputData::InputType::KeyDown;
					newEvent->Key_ = Bubblewrap::Events::TranslateKey( event.key.code );
					newEvent->Alt_ = event.key.alt;
					newEvent->Control_ = event.key.control;
					newEvent->Shift_ = event.key.shift;
					Events::Event evt = Events::Event( Events::EventTypes::Input, newEvent );
					GetManagers().GetEventManager().QueueEvent( evt );
				}
				else if ( ( event.type == sf::Event::KeyReleased ) )
				{
					auto code = Bubblewrap::Events::TranslateKey( event.key.code );
					Events::InputData* newEvent = new Events::InputData();
					newEvent->InputType_ = Events::InputData::InputType::KeyUp;
					newEvent->Key_ = Bubblewrap::Events::TranslateKey( event.key.code );
					newEvent->Alt_ = event.key.alt;
					newEvent->Control_ = event.key.control;
					newEvent->Shift_ = event.key.shift;
					Events::Event evt = Events::Event( Events::EventTypes::Input, newEvent );
					GetManagers().GetEventManager().QueueEvent( evt );
				}
				else if ( ( event.type == sf::Event::EventType::Closed ) )
				{
					GetManagers().GetGame()->Shutdown();
				}
			}/**/

		}

		void* SdlWindow::GetInternalPointer()
		{
			return Window_;
		}
	}
}