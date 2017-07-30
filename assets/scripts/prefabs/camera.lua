function createMainCamera( config )
	config = config or {} 

	local fov = config.fov or 60.0
	local farPlane = config.farPlane or 5000
	local components = config.components or {}
	local nodes = config.nodes or {}
	local transformation = config.transformation

	table.insert(
		components,
		{
			type = 'purge::FirstPersonCameraController',
			speed = 2.0,
		}		
	)

	table.insert(
		components,
		{
			type = 'crimild::navigation::NavigationController',
		}		
	)

	return {
		type = 'crimild::Camera',
		frustum = {
			fov = fov,
			far = farPlane,
		},
		isMainCamera = true,
		enableCulling = false,
		components = components,
		nodes = nodes,
		transformation = transformation,
	}
end

