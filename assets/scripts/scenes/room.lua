require 'assets/scripts/prefabs/camera'

local camera = createMainCamera(
	{
		transformation = {
			translate = { 0.0, 1.8, 0.0 },
			rotate_euler = { 0.0, 180.0, 0.0 },
		},
	}
)

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
			attenuation = { 0.0, 0.0, 1.0 },
			transformation = {
				translate = { 0.0, 0.25, 0.0 },
			},
		},			
	},
	components = {
		{
			type = 'purge::ConsoleController',
		},
	},
	transformation = {
		translate = { 0.0, 1.0, 2.7027 },
		rotate_euler = { 0.0, 180.0, 0.0 },
	},
}

local environment = {
	filename = 'assets/models/room.fbx',	
	components = {
--		{
--			type = 'crimild::navigation::NavigationMeshContainer',
--			navmesh = 'assets/models/environments/siege.obj',
--		},
	},
}

local lighting = {
	type = 'crimild::Group',
	nodes = {
		{
			type = 'crimild::Light',
			lightType = 'point',
			color = { 1.0, 1.0, 1.0, 1.0 },
			ambient = { 0.05, 0.05, 0.05, 1.0 },
			transformation = {
				translate = { 0.0, 3.0, 0.0 },
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
	},
}

