dofile( "sdl2/sdl_genie.lua" )

PsyProjectEngineLib( "sdl" )
	files 
	{ 
		"include/**.h", 
		"include/**.hpp", 
		"src/**.cpp" 
	}
	includedirs { 
		"./include", 
		"../bubblewrap/External",
		"../bubblewrap/include/",
		"./sdl2/SDL2/include/",
		
		}
	PsyAddEngineLinks {
		"base"
	}
	
	PsyAddExternalLinks {
		"physfs",
		"json",
	}
