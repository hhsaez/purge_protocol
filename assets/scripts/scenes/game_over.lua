local camera = {
	type = 'crimild::Camera',
	nodes = {
		{
			filename = 'assets/models/game_over.fbx',
			transformation = {
				translate = { 0.0, 0.0, -1.0 },
				scale = 0.1,
			},
		},
	},
}

scene = {
	type = 'crimild::Group',
	nodes = {
		camera,
	},
	components = {
		{
			type = 'purge::LevelLoader',
			timeout = 5.0,
			nextScene = 'assets/scripts/scenes/main.lua',
		},
	},
}

