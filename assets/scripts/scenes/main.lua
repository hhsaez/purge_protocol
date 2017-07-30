require 'assets/scripts/prefabs/camera'

local camera = {
	type = 'crimild::Camera',
	frustum = {
		fov = 120,
	},
	nodes = {
		{
			filename = 'assets/models/signature.fbx',
			transformation = {
				translate = { 1.5, -1.5, -1.0 },
				scale = 0.1,
			},
		},
	},
	transformation = {
		translate = { -3.5, 3.0, -3.0 },
		rotate_euler = { -30.0, 220.0, 0.0 },
	},
}

local console = {
	type = 'crimild::Group',
	nodes = {
		{
			filename = 'assets/models/console_on.fbx',
		},
		{
			type = 'crimild::Light',
			lightType = 'point',
			color = { 0.75, 0.75, 1.0, 1.0 },
			attenuation = { 0.0, 0.0, 0.5 },
			ambient = { 0.015, 0.015, 0.05, 1.0 },
			transformation = {
				translate = { 0.0, 0.5, 0.5 },
			},
		},
		{
			filename = 'assets/models/console_welcome.fbx',
		},
	},
	transformation = {
		translate = { 0.0, 1.0, 2.7027 },
		rotate_euler = { 0.0, 180.0, 0.0 },
	},
}

local environment = {
	filename = 'assets/models/room.fbx',	
}

local ui = {
	type = 'crimild::Group',
	nodes = {
		{
			filename = 'assets/models/title.fbx',
			transformation = {
				translate = { -2.75, 1.25, -1.25 },
				rotate_euler = { 0.0, 230.0, 0.0 },
			},
		},
		{
			filename = 'assets/models/btn_play.fbx',
			transformation = {
				translate = { -3.0, 0.5, -2.5 },
				rotate_euler = { -30.0, 230.0, 0.0 },
				scale = 0.75,
			},
			components = {
				{
					type = 'purge::Button',
					action = 'load_scene',
					data = 'assets/scripts/scenes/intro.lua',
				},
			},
		},
		{
			filename = 'assets/models/btn_quit.fbx',
			transformation = {
				translate = { -4.0, 0.25, -2.0 },
				rotate_euler = { -30.0, 230.0, 0.0 },
				scale = 0.5
			},
			components = {
				{
					type = 'purge::Button',
					action = 'quit',
				},
			}
		},
	},
}

local lighting = {
	type = 'crimild::Group',
	nodes = {
		{
			type = 'crimild::Light',
			lightType = 'directional',
			color = { 1.0, 1.0, 0.5, 1.0 },
			ambient = { 0.1, 0.1, 0.015, 1.0 },
			--castShadows = true,
			transformation = {
				translate = { -20.0, 2.0, 4.0 },
				rotate_euler = { 0.0, -75.0, 0.0 },
			},
		},
	},
}

scene = {
	type = 'crimild::Group',
	nodes = {
		environment,
		lighting,
		console,
		camera,
		ui,
	},
	components = {
		{
			type = 'purge::GameController',
		},
	},
}

