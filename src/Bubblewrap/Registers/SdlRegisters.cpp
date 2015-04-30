#include "Bubblewrap/Registers/SdlRegisters.hpp"
#include "Bubblewrap/Base/ObjectRegister.hpp"
#include "Bubblewrap/Base/SdlClock.hpp"
#include "Bubblewrap/Managers/Managers.hpp"
#include "Bubblewrap/Render/SdlWindow.hpp"

namespace Bubblewrap
{
	namespace Registers
	{
		void SdlRegisters::RegisterUtilities( void* ObjectRegister )
		{
			Base::ObjectRegister* Register = ( Base::ObjectRegister* ) ObjectRegister;

			Register->RegisterCreator( "Clock", Base::SdlClock::Create, Base::SdlClock::CopyDef, true );

			Register->GetManager()->GetWindowManager().SetCreate( Render::SdlWindow::Create );
		}

		void SdlRegisters::RegisterGraphics( void* ObjectRegister )
		{
			Base::ObjectRegister* Register = (Base::ObjectRegister*) ObjectRegister;
			Register->GetManager()->GetWindowManager().SetCreate(Render::SdlWindow::Create);
		}

	}
}