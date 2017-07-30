local camera = {
	type = 'crimild::Camera',
}

scene = {
	type = 'crimild::Group',
	nodes = {
		camera,
	},
	components = {
		{
			type = 'purge::LevelLoader',
			timeout = 2.0,
			nextScene = 'assets/scripts/scenes/room.lua',
		},
	},
}

