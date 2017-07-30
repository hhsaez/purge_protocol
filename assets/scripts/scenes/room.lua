require 'assets/scripts/prefabs/camera'
require 'assets/scripts/prefabs/smoke'

local camera = createMainCamera(
	{
		transformation = {
			translate = { 0.0, 1.8, -3.0 },
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
			attenuation = { 0.0, 0.0, 0.5 },
			ambient = { 0.015, 0.015, 0.05, 1.0 },
			transformation = {
				translate = { 0.0, 0.5, 0.5 },
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

local actors = {
	type = 'crimild::Group',
	nodes = {
		{
			filename = 'assets/models/expendable.fbx',
			components = {
				{
					type = 'purge::Expendable',
				},
			},
			transformation = {
				translate = { -8.0, -1.5, 2.5 },
				rotate_euler = { 0.0, 90.0, 0.0 },
			},
		},
		{
			filename = 'assets/models/expendable_group.fbx',
			components = {
				{
					type = 'purge::ExpendableGroup',
				},
			},
			transformation = {
				translate = { -15.0, 5.0, 3.0 },
			},
		},		
	},
}

local environment = {
	filename = 'assets/models/room.fbx',	
	components = {
		{
			type = 'crimild::navigation::NavigationMeshContainer',
			navmesh = 'assets/models/room.navmesh',
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
			castShadows = true,
			transformation = {
				translate = { -20.0, 2.0, 4.0 },
				rotate_euler = { 0.0, -75.0, 0.0 },
			},
			components = {
				{
					type = 'purge::LightController',
					enableOnEvent = false,
				},
			},
		},
		{
			type = 'crimild::Light',
			lightType = 'point',
			color = { 1.0, 1.0, 1.0, 1.0 },
			ambient = { 0.1, 0.1, 0.05, 1.0 },
			attenuation = { 2.0, 0.0, 0.0 },
			transformation = {
				translate = { 0.0, 3.0, 0.0 },
			},
			components = {
				{
					type = 'purge::LightController',
					enableOnEvent = true,
				},
			},
		},
	},
}

local fx = {
	type = 'crimild::Group',
	nodes = {
		buildSmokeFX(
			{
				transformation = {
					translate = { 0.0, 0.0, 0.0 },
				},
			}
		),
	},
}

scene = {
	type = 'crimild::Group',
	nodes = {
		environment,
		lighting,
		console,
		actors,
		fx,
		camera,
	},
	components = {
		{
			type = 'purge::GameController',
		},
	},
}

