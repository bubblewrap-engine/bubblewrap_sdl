#include "Bubblewrap/Base/SdlClock.hpp"

namespace Bubblewrap
{
	namespace Base
	{
		Time SdlClock::GetElapsedTime()
		{
			return Time( 1.0f / 25.0f);
		}

		void SdlClock::Copy( SdlClock* Target, SdlClock* Base )
		{

		}

		void SdlClock::Update( float dt )
		{

		}
	}
}
