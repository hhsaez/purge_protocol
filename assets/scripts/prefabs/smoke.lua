function buildSmokeFX( config )
	
	local MAX_PARTICLES = 200
	
	return {
		type = 'crimild::Group',
		components = {
			{
				type = 'crimild::ParticleSystemComponent',
				maxParticles = MAX_PARTICLES,
				emitRate = 0.1 * MAX_PARTICLES,
				generators = {
					{
						type = 'crimild::BoxPositionParticleGenerator',
						origin = { 0.0, 0.0, 0.0 },
						size = { 5.0, 0.0, 5.0 },
					},
					{
						type = 'crimild::RandomVector3fParticleGenerator',
						attrib = 'velocity',
						minValue = { 0.0, 0.01, 0.0 },
						maxValue = { 0.0, 0.1, 0.0 },
					},
					{
						type = 'crimild::RandomVector3fParticleGenerator',
						attrib = 'acceleration',
						minValue = { 0.0, 0.0, 0.0 },
						maxValue = { 0.0, 0.0, 0.0 },
					},
					{
						type = 'crimild::ColorParticleGenerator',
						minStartColor = { 1.0, 1.0, 1.0, 1.0 },
						maxStartColor = { 1.0, 1.0, 1.0, 1.0 },
						minEndColor = { 0.0, 0.0, 0.0, 0.0 },
						maxEndColor = { 0.0, 0.0, 0.0, 0.0 },
					},
					{
						type = 'crimild::RandomReal32ParticleGenerator',
						attrib = 'uniform_scale_start',
						minValue = 0.25,
						maxValue = 0.5,
					},
					{
						type = 'crimild::RandomReal32ParticleGenerator',
						attrib = 'uniform_scale_end',
						minValue = 1.0,
						maxValue = 2.0,
					},
					{
						type = 'crimild::TimeParticleGenerator',
						minTime = 5.0,
						maxTime = 7.0,
					},
				},
				updaters = {
					{
						type = 'crimild::PositionVelocityParticleUpdater',
					},
					{
						type = 'crimild::TimeParticleUpdater',
					},
					{
						type = 'crimild::UniformScaleParticleUpdater',
					},
					{
						type = 'crimild::ColorParticleUpdater',
					},
					{
						type = 'crimild::CameraSortParticleUpdater',
					},
				},
				renderers = {
					{
						type = 'crimild::OrientedQuadParticleRenderer',
						texture = 'assets/textures/smoke.tga',
						blendMode = 'default',
						cullFaceEnabled = false,
						depthStateEnabled = false,
					},
				},
			},
			{
				type = 'purge::SmokeController',
			},
		},
		transformation = config.transformation,
	}
end

