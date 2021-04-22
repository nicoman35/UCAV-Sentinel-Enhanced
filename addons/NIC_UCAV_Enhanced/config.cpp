class CfgPatches {
	class UCAV_Enhanced {
		name = "UCAV Sentinel Enhanced";
		requiredAddons[] = {
			"A3_Air_F_Jets",
			"ace_maverick"
		};
		requiredVersion = 0.1;
		authors[] = {
			"NIC"
		};
		units[] = {
			"B_UAV_05_F_Enhanced"
		};
		weapons[] = {
			"weapon_HARMLauncher",
			"weapon_SDBLauncher"
		};
		ammo[] = {
			"ace_maverick_L"
		};
	};
};
class CfgFunctions {
	class NIC_EUAV {
		class Functions {
			file = "UCAV_Enhanced\functions";
			class AddAiRefreshAction {};
			class ProjectileMonitor {};
			class RefreshAi {};
			class RefreshAiActionCheck {};
		};
	};
};
class SensorTemplateAntiRadiation;
class SensorTemplateActiveRadar;
class SensorTemplateDataLink;
class SensorTemplateIR;
class SensorTemplateLaser;
class SensorTemplateMan;
class SensorTemplateNV;
class SensorTemplatePassiveRadar;
class SensorTemplateVisual;
class CfgAmmo {
	class MissileCore;
	class MissileBase: MissileCore {
		class Components;
	};
	class Missile_AGM_02_F: MissileBase {};
	class ace_maverick_L: Missile_AGM_02_F {
		timeToLive = 240;
		missileLockMaxDistance = 20000;
		cameraViewAvailable = 1;
		class ace_missileguidance {
			enabled = 1;
			minDeflection = 0;
			maxDeflection = 0.0020000001;
			incDeflection = 0.001;
			canVanillaLock = 0;
			defaultSeekerType = "SALH";
			seekerTypes[] = {
				"SALH"
			};
			defaultSeekerLockMode = "LOAL";
			seekerLockModes[] = {
				"LOAL",
				"LOBL"
			};
			seekLastTargetPos = 1;
			seekerAngle = 60;
			seekerAccuracy = 1;
			seekerMinRange = 1;
			seekerMaxRange = 20000;
			defaultAttackProfile = "maverick";
			attackProfiles[] = {
				"maverick"
			};
		};
	};
	class LaserBombCore;
	class ammo_Bomb_LaserGuidedBase;
	class ammo_Bomb_SmallDiameterBase;
	class ammo_Bomb_SDB: ammo_Bomb_SmallDiameterBase
	{
		model="\A3\Weapons_F_Sams\Ammo\Bomb_05_F_fly.p3d";
		proxyShape="\A3\Weapons_F_Sams\Ammo\Bomb_05_F.p3d";
		cameraViewAvailable = 1;
		class Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class NVSensorComponent: SensorTemplateNV
					{
						class AirTarget
						{
							minRange=8000;
							maxRange=8000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=16000;
							maxRange=16000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						maxTrackableSpeed=30;
						angleRangeHorizontal=180;
						angleRangeVertical=180;
					};
					class LaserSensorComponent: SensorTemplateLaser
					{
						class AirTarget
						{
							minRange=8000;
							maxRange=8000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=16000;
							maxRange=16000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						maxTrackableSpeed=30;
						angleRangeHorizontal=180;
						angleRangeVertical=180;
					};
					class IRSensorComponent: SensorTemplateIR
					{
						class AirTarget
						{
							minRange=500;
							maxRange=8000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=500;
							maxRange=16000;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
						};
						maxTrackableSpeed=55;
						angleRangeHorizontal=180;
						angleRangeVertical=180;
					};
				};
			};
		};
	};
};
class DefaultVehicleSystemsDisplayManagerLeft {
	class components;
};
class DefaultVehicleSystemsDisplayManagerRight {
	class components;
};
class VehicleSystemsTemplateLeftPilot: DefaultVehicleSystemsDisplayManagerLeft {
	class components;
};
class VehicleSystemsTemplateRightPilot: DefaultVehicleSystemsDisplayManagerRight {
	class components;
};
class Eventhandlers;
class CfgVehicles {
		class Air;
		class Plane: Air {
			class HitPoints;
		};
	class Plane_Base_F: Plane {
		class AnimationSources;
		class HitPoints: HitPoints {
			class HitHull;
		};
		class Components;
	};
	class PlaneWreck;
	class UAV: Plane {
		class NewTurret;
		class ViewPilot;
		class ViewOptics;
		class AnimationSources;
		class Components;
	};
	class UAV_05_Base_F_Enhanced: UAV {
		scope = 0;
		vehicleClass = "Autonomous";
		side = 1;
		faction = "BLU_F";
		displayName = "UCAV Sentinel Enhanced Base";
		author = "NIC";
		unitInfoType = "RscOptics_AV_airplane_pilot";
		simulation = "airplaneX";
		DLC = "Jets";
		crew = "B_UAV_AI";
		typicalCargo[] = {
			"B_UAV_AI"
		};
		editorPreview = "\A3\EditorPreviews_F_Jets\Data\Cfgvehicles\B_UAV_05_F.jpg";
		picture = "\A3\Air_F_Jets\UAV_05\Data\UI\uav_05_picture_ca.paa";
		icon = "\A3\Air_F_Jets\UAV_05\Data\UI\uav_05_icon_ca.paa";
		mapSize = 20.1;
		model = "\A3\Air_F_Jets\UAV_05\UAV_05_F.p3d";
		animated = 1;
		hiddenSelections[] = {
			"Camo1",
			"Camo2",
			"Camo_engine_fire"
		};
		hiddenSelectionsTextures[] = {
			"A3\Air_F_Jets\UAV_05\Data\UAV05_fuselage_01_co.paa",
			"A3\Air_F_Jets\UAV_05\Data\UAV05_fuselage_02_co.paa",
			"A3\Air_F_Jets\UAV_05\Data\UAV05_engine_fire_ca.paa"
		};
		weapons[] = {"CMFlareLauncher"};
		magazines[] = {"120Rnd_CMFlare_Chaff_Magazine"};
		driveOnComponent[] = {};
		cabinOpening = 0;
		gearRetracting = 1;
		geardowntime = 5;
		gearuptime = 5;
		lightOnGear = 1;
		damperSize = 0.0099999998;
		damperForce = 0.0099999998;
		damperDamping = 0;
		canFloat = 0;
		formationX = 30;
		formationZ = 30;
		availableForSupportTypes[] = {
			"CAS_Bombing"
		};
		getInRadius = 0;
		armor = 50;
		armorStructural = 1;
		damageResistance = 0.0040000002;
		damageEffect = "AirDestructionEffects";
		killFriendlyExpCoef = 0.1;
		epeImpulseDamageCoef = 120;
		class HitPoints: HitPoints {
			class HitHull {
				armor = 3;
				explosionShielding = 5;
				name = "HitHull";
				passThrough = 0.5;
				visual = "HitHull_visual";
				radius = 0.30000001;
				minimalHit = 0.02;
				depends = "Total";
				material = -1;
			};
			class HitEngine: HitHull {
				armor = 1.5;
				explosionShielding = 2;
				name = "HitEngine";
				passThrough = 0.5;
				visual = "HitEngineL_visual";
				radius = 0.55000001;
				minimalHit = 0.1;
			};
			class HitEngine2: HitEngine {
				armor = 1.5;
				explosionShielding = 2;
				name = "HitEngine2";
				passThrough = 0.5;
				visual = "HitEngineR_visual";
				radius = 0.55000001;
				minimalHit = 0.1;
			};
			class HitAvionics: HitHull {
				armor = 3;
				explosionShielding = 1;
				name = "HitAvionics";
				passThrough = 0.2;
				visual = "HitAvionics_visual";
				radius = 0.2;
			};
			class HitAmmo: HitHull {
				armor = 3;
				explosionShielding = 1;
				name = "HitAmmo";
				passThrough = 0;
				visual = "HitAmmo_visual";
				radius = 0.30000001;
			};
			class HitFuel: HitHull {
				armor = 3;
				explosionShielding = 4;
				name = "HitFuel";
				passThrough = 0.5;
				visual = "HitHull_visual";
				radius = 0.30000001;
				minimalHit = 0.1;
			};
			class HitFuel2: HitFuel {
				armor = 3;
				explosionShielding = 4;
				name = "HitFuel2";
				passThrough = 0.5;
				visual = "HitHull_visual";
				radius = 0.30000001;
				minimalHit = 0.1;
			};
			class HitLAileron: HitHull {
				armor = 1.5;
				explosionShielding = 3;
				name = "HitLAileron";
				passThrough = 0.1;
				visual = "HitAileronL_visual";
				radius = 0.2;
				minimalHit = 0.1;
			};
			class HitRAileron: HitLAileron {
				armor = 1.5;
				explosionShielding = 3;
				name = "HitRAileron";
				passThrough = 0.1;
				visual = "HitAileronR_visual";
				radius = 0.2;
				minimalHit = 0.1;
			};
			class HitLCElevator: HitHull {
				armor = 1.5;
				explosionShielding = 3;
				name = "HitLCElevator";
				passThrough = 0.1;
				visual = "HitElevatorL_visual";
				radius = 0.2;
				minimalHit = 0.1;
			};
			class HitRElevator: HitLCElevator {
				armor = 1.5;
				explosionShielding = 3;
				name = "HitRElevator";
				passThrough = 0.1;
				visual = "HitElevatorR_visual";
				radius = 0.2;
				minimalHit = 0.1;
			};
		};
		class Damage {
			tex[] = {
				"A3\Air_F_Jets\UAV_05\Data\uav05_engine_fire_ca.paa",
				"A3\Air_F_Jets\UAV_05\Data\uav05_engine_fire_ca.paa",
				"A3\Data_F\clear_empty.paa"
			};
			mat[] = {
				"A3\Air_F_Jets\UAV_05\Data\UAV05_fuselage_01.rvmat",
				"A3\Air_F_Jets\UAV_05\Data\UAV05_fuselage_01_damage.rvmat",
				"A3\Air_F_Jets\UAV_05\Data\UAV05_fuselage_01_destruct.rvmat",
				"A3\Air_F_Jets\UAV_05\Data\UAV05_fuselage_02.rvmat",
				"A3\Air_F_Jets\UAV_05\Data\UAV05_fuselage_02_damage.rvmat",
				"A3\Air_F_Jets\UAV_05\Data\UAV05_fuselage_02_destruct.rvmat"
			};
		};
		LockDetectionSystem = "1 + 2 + 4 + 8";
		incomingMissileDetectionSystem = "8 + 16";
		enableGPS = 1;
		radarTarget = 1;
		visualTarget = 1;
		radarTargetSize = 0.15000001;
		visualTargetSize = 0.89999998;
		irTargetSize = 0.80000001;
		reportRemoteTargets = 1;
		reportOwnPosition = 1;
		namesound = "veh_air_plane_s";
		class Components: Components {
			class SensorsManagerComponent {
				class Components {
					class IRSensorComponent: SensorTemplateIR {
						class AirTarget {
							minRange = 500;
							maxRange = 10000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget {
							minRange = 500;
							maxRange = 12000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						typeRecognitionDistance = 10000;
						maxTrackableSpeed = 50;
						angleRangeHorizontal = 51;
						angleRangeVertical = 37;
						animDirection = "mainGun";
						aimDown = -0.5;
					};
					class VisualSensorComponent: SensorTemplateVisual {
						class AirTarget {
							minRange = 500;
							maxRange = 10000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget {
							minRange = 500;
							maxRange = 12000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						typeRecognitionDistance = 10000;
						maxTrackableSpeed = 50;
						angleRangeHorizontal = 51;
						angleRangeVertical = 37;
						animDirection = "mainGun";
						aimDown = -0.5;
					};
					class PassiveRadarSensorComponent: SensorTemplatePassiveRadar {};
					class ActiveRadarSensorComponent: SensorTemplateActiveRadar {
						class AirTarget {
							minRange = 500;
							maxRange = 25000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = 1;
						};
						class GroundTarget {
							minRange = 500;
							maxRange = 25000;
							objectDistanceLimitCoef = 1;
							viewDistanceLimitCoef = 1;
						};
						typeRecognitionDistance = 25000;
						angleRangeHorizontal = 60;
						angleRangeVertical = 60;
						aimDown = 20;
					};
					class AntiRadiationSensorComponent: SensorTemplateAntiRadiation {
						class AirTarget {
							minRange = 16000;
							maxRange = 40000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						class GroundTarget {
							minRange = 16000;
							maxRange = 40000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						maxTrackableATL = 100;
						maxTrackableSpeed = 60;
						angleRangeHorizontal = 60;
						angleRangeVertical = 180;
					};
					class LaserSensorComponent: SensorTemplateLaser {};
					class NVSensorComponent: SensorTemplateNV {};
				};
			};
			class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
				defaultDisplay="MinimapDisplay";
				class Components {
					class EmptyDisplay {
						componentType = "EmptyDisplayComponent";
					};
					class MinimapDisplay {
						componentType = "MinimapDisplayComponent";
						resource = "RscCustomInfoAirborneMiniMap";
					};
					class UAVDisplay {
						componentType = "UAVFeedDisplayComponent";
					};
					// class VehicleMissileDisplay {
						// componentType = "TransportFeedDisplayComponent";
						// source = "Missile";
					// };
					// class MissileDisplay {
						// componentType="TransportFeedDisplayComponent";
						// source="Missile";
					// };
					class SensorDisplay {
						componentType = "SensorsDisplayComponent";
						range[] = {8000,16000,2000,4000};
						resource = "RscCustomInfoSensors";
					};
				};
			};
			class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
				defaultDisplay = "SensorDisplay";
				class Components {
					class EmptyDisplay {
						componentType = "EmptyDisplayComponent";
					};
					class MinimapDisplay {
						componentType = "MinimapDisplayComponent";
						resource = "RscCustomInfoAirborneMiniMap";
					};
					class UAVDisplay {
						componentType = "UAVFeedDisplayComponent";
					};
					// class VehicleMissileDisplay {
						// componentType = "TransportFeedDisplayComponent";
						// source = "Missile";
					// };
					// class MissileDisplay {
						// componentType="TransportFeedDisplayComponent";
						// source="Missile";
					// };
					class SensorDisplay {
						componentType = "SensorsDisplayComponent";
						range[] = {8000,16000,2000,4000};
						resource = "RscCustomInfoSensors";
					};
				};
			};
			class TransportPylonsComponent {
				UIPicture = "\A3\Air_F_Jets\UAV_05\Data\UI\UAV_05_3DEN_CA.paa";
				class pylons {
					class pylon1 {
						hardpoints[] = {
							"B_GBU12",
							"B_AGM65_DUAL",
							"B_HARM_INT",
							"B_SDB_QUAD_RAIL"
						};
						attachment = "PylonRack_Bomb_SDB_x4";
						priority = 1;
						maxweight = 1500;
						turret[] = {0};
						UIposition[] = {0.5,0.25};
						bay = 2;
					};
					class pylon2: pylon1 {
						UIposition[] = {0.15000001,0.25};
						mirroredMissilePos = 1;
						bay = 1;
					};
				};
				class Bays {
					class BayLeft1 {
						bayOpenTime = 0.5;
						openBayWhenWeaponSelected = 0;
						autoCloseWhenEmptyDelay = 2;
					};
					class BayRight1 {
						bayOpenTime = 0.5;
						openBayWhenWeaponSelected = 0;
						autoCloseWhenEmptyDelay = 2;
					};
				};
				class Presets {
					class Empty {
						displayName = "$STR_empty";
						attachment[] = {};
					};
					class Default {
						displayName = "$STR_vehicle_default";
						attachment[] = {
							"PylonRack_Bomb_SDB_x4",
							"PylonRack_Bomb_SDB_x4"
						};
					};
					class AT {
						displayName = "$STR_A3_CAS_PRESET_DISPLAYNAME";
						attachment[] = {
							"PylonMissile_Missile_AGM_02_x2",
							"PylonMissile_Missile_AGM_02_x2"
						};
					};
				};
			};
		};
		uavCameraDriverPos = "pos_pip0";
		uavCameraDriverDir = "pos_pip0_dir";
		uavCameraGunnerPos = "pos_pip1";
		uavCameraGunnerDir = "pos_pip1_dir";
		memoryPointLDust = "pos_Dust_L";
		memoryPointRDust = "pos_Dust_R";
		memoryPointCM[] = {
			"pos_flare_launcher1",
			"pos_flare_launcher2"
		};
		memoryPointCMDir[] = {
			"pos_flare_launcher1_dir",
			"pos_flare_launcher2_dir"
		};
		memoryPointDriverOptics = "pos_pip0";
		slingLoadCargoMemoryPoints[] = {
			"SlingLoadCargo1",
			"SlingLoadCargo2",
			"SlingLoadCargo3",
			"SlingLoadCargo4"
		};
		class TransportItems {};
		extCameraPosition[] = {0,3,-30};
		driverOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Driver_F.p3d";
		driverForceOptics = 1;
		driverCompartments = "Compartment3";
		cargoCompartments[] = {
			"Compartment2"
		};
		class ViewPilot: ViewPilot {
			minFov = 0.25;
			maxFov = 1.25;
			initFov = 0.75;
			initAngleX = 0;
			minAngleX = -65;
			maxAngleX = 85;
			initAngleY = 0;
			minAngleY = -150;
			maxAngleY = 150;
		};
		class Viewoptics: ViewOptics {
			initAngleX = 0;
			minAngleX = 0;
			maxAngleX = 0;
			initAngleY = 0;
			minAngleY = 0;
			maxAngleY = 0;
			minFov = 0.25;
			maxFov = 1.25;
			initFov = 0.75;
			visionMode[] = {
				"Normal",
				"NVG",
				"Ti"
			};
			thermalMode[] = {0,1};
		};
		class Turrets {
			class MainTurret: NewTurret {
				isCopilot = 0;
				minElev = -100;
				maxElev = 10;
				initElev = -45;
				minTurn = -180;
				maxTurn = 180;
				initTurn = 0;
				outGunnerMayFire = 1;
				inGunnerMayFire = 1;
				commanding = -1;
				body = "mainTurret";
				gun = "mainGun";
				animationSourceBody = "mainTurret";
				animationSourceGun = "mainGun";
				memoryPointGun = "pos_pip1";
				memoryPointGunnerOptics = "pos_pip1_dir";
				gunBeg = "pos_pip1_dir";
				gunEnd = "pos_pip1";
				gunnerName = "$STR_A3_UCAV_05_operator_displayName";
				gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Gunner_F.p3d";
				gunnerForceOptics = 1;
				turretInfoType = "RscOptics_UAV_gunner";
				stabilizedInAxes = 3;
				maxHorizontalRotSpeed = 10;
				maxVerticalRotSpeed = 10;
				enableManualFire = 0;
				weapons[] = {
					"Laserdesignator_mounted"
				};
				magazines[] = {
					"Laserbatteries"
				};
				GunnerCompartments = "Compartment1";
				startEngine = 0;
				class Components {
					class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
						defaultDisplay="MinimapDisplay";
						class Components {
							class EmptyDisplay {
								componentType = "EmptyDisplayComponent";
							};
							class MinimapDisplay {
								componentType = "MinimapDisplayComponent";
								resource = "RscCustomInfoAirborneMiniMap";
							};
							class UAVDisplay {
								componentType = "UAVFeedDisplayComponent";
							};
							// class VehicleMissileDisplay {
								// componentType = "TransportFeedDisplayComponent";
								// source = "Missile";
							// };
							// class MissileDisplay {
								// componentType="TransportFeedDisplayComponent";
								// source="Missile";
							// };
							class SensorDisplay {
								componentType = "SensorsDisplayComponent";
								range[] = {8000,16000,2000,4000};
								resource = "RscCustomInfoSensors";
							};
						};
					};
					class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
						defaultDisplay = "SensorDisplay";
						class Components {
							class EmptyDisplay {
								componentType = "EmptyDisplayComponent";
							};
							class MinimapDisplay {
								componentType = "MinimapDisplayComponent";
								resource = "RscCustomInfoAirborneMiniMap";
							};
							class UAVDisplay {
								componentType = "UAVFeedDisplayComponent";
							};
							// class VehicleMissileDisplay {
								// componentType = "TransportFeedDisplayComponent";
								// source = "Missile";
							// };
							// class MissileDisplay {
								// componentType="TransportFeedDisplayComponent";
								// source="Missile";
							// };
							class SensorDisplay {
								componentType = "SensorsDisplayComponent";
								range[] = {8000,16000,2000,4000};
								resource = "RscCustomInfoSensors";
							};
						};
					};
				};
				class OpticsIn {
					class Wide {
						opticsDisplayName = "W";
						initAngleX = 0;
						minAngleX = -35;
						maxAngleX = 85;
						initAngleY = 0;
						minAngleY = -130;
						maxAngleY = 130;
						initFov = 0.5;
						minFov = 0.5;
						maxFov = 0.5;
						directionStabilized = 1;
						visionMode[] = {
							"Normal",
							"NVG",
							"Ti"
						};
						thermalMode[] = {0,1};
						gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
					};
					class Medium1: Wide {			// 2.5x (baseline FOV 0.25 / 0.1  = 2.5)
						opticsDisplayName 	 = 	"M1";
						initFov 			 = 0.1;
						minFov 				 = 0.1;
						maxFov  			 = 0.1;
						gunnerOpticsModel 	 = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
					};
					class Medium2: Medium1 {		// 5x (baseline FOV 0.25 / 0.050000001  = 5)
						opticsDisplayName 	 = "M2";
						initFov  			 = 0.050000001;
						minFov  			 = 0.050000001;
						maxFov  			 = 0.050000001;
						gunnerOpticsModel	 = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
					};
					class Medium3: Medium2 {  		// 10x (baseline FOV 0.25 / 0.025  = 10)
						opticsDisplayName 	 = "M3";
						initFov 			 = 0.025;
						minFov 				 = 0.025;
						maxFov 				 = 0.025;
						gunnerOpticsModel 	 = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
					};
					class Medium4: Medium3 { 		// 20x (baseline FOV 0.25 / 0.0125  = 20)
						opticsDisplayName	 = "M4";
						initFov 			 = 0.0125;
						minFov 				 = 0.0125;
						maxFov 				 = 0.0125;
						gunnerOpticsModel	 = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
					};
					class Narrow: Medium4 {			// 80x (baseline FOV 0.25 / 0.0031250001  = 80)
						opticsDisplayName	 = "N";
						initFov  			 = 0.0031250001;
						minFov  			 = 0.0031250001;
						maxFov  			 = 0.0031250001;
						gunnerOpticsModel	 = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
					};
				};
				class OpticsOut {
					class Monocular {
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						initFov = 1.1;
						minFov = 0.133;
						maxFov = 1.1;
						visionMode[] = {
							"Normal",
							"NVG"
						};
						gunnerOpticsModel = "";
						gunnerOpticsEffect[] = {};
					};
				};
			};
		};
		attenuationEffectType = "PlaneAttenuation";
		soundGetIn[] = {
			"A3\Sounds_F\vehicles\air\CAS_01\getin_wipeout",
			1,
			1,
			40
		};
		soundGetOut[] = {
			"A3\Sounds_F\air\Plane_Fighter_03\getout",
			1,
			1,
			40
		};
		cabinOpenSound[] = {
			"A3\Sounds_F_Jets\vehicles\air\Shared\FX_UAV_05_cabine_open_ext",
			3.1622801,
			1,
			40
		};
		cabinCloseSound[] = {
			"A3\Sounds_F_Jets\vehicles\air\Shared\FX_UAV_05_cabine_close_ext",
			3.1622801,
			1,
			40
		};
		cabinOpenSoundInternal[] = {
			"A3\Sounds_F_Jets\vehicles\air\Shared\FX_UAV_05_cabine_open_int",
			10,
			1,
			40
		};
		cabinCloseSoundInternal[] = {
			"A3\Sounds_F_Jets\vehicles\air\Shared\FX_UAV_05_cabine_close_int",
			10,
			1,
			40
		};
		soundWaterCollision1[] = {
			"A3\Sounds_F\vehicles\crashes\planes\plane_crash_water_1",
			1.41254,
			1,
			500
		};
		soundWaterCollision2[] = {
			"A3\Sounds_F\vehicles\crashes\planes\plane_crash_water_2",
			1.41254,
			1,
			500
		};
		soundWaterCrashes[] = {
			"soundWaterCollision1",
			0.5,
			"soundWaterCollision2",
			0.5
		};
		buildCrash0[] = {
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_1",
			1,
			1,
			900
		};
		buildCrash1[] = {
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_2",
			1,
			1,
			900
		};
		buildCrash2[] = {
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_3",
			1,
			1,
			900
		};
		buildCrash3[] = {
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_4",
			1,
			1,
			900
		};
		soundBuildingCrash[] = {
			"buildCrash0",
			0.25,
			"buildCrash1",
			0.25,
			"buildCrash2",
			0.25,
			"buildCrash3",
			0.25
		};
		WoodCrash0[] = {
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_1",
			3.1622801,
			1,
			900
		};
		WoodCrash1[] = {
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_2",
			3.1622801,
			1,
			900
		};
		WoodCrash2[] = {
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_6",
			3.1622801,
			1,
			900
		};
		WoodCrash3[] = {
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_8",
			3.1622801,
			1,
			900
		};
		soundWoodCrash[] = {
			"woodCrash0",
			0.25,
			"woodCrash1",
			0.25,
			"woodCrash2",
			0.25,
			"woodCrash3",
			0.25
		};
		armorCrash0[] = {
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_1",
			1,
			1,
			900
		};
		armorCrash1[] = {
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_2",
			1,
			1,
			900
		};
		armorCrash2[] = {
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_3",
			1,
			1,
			900
		};
		armorCrash3[] = {
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_4",
			1,
			1,
			900
		};
		soundArmorCrash[] = {
			"ArmorCrash0",
			0.25,
			"ArmorCrash1",
			0.25,
			"ArmorCrash2",
			0.25,
			"ArmorCrash3",
			0.25
		};
		Crash0[] = {
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_1",
			1,
			1,
			900
		};
		Crash1[] = {
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_2",
			1,
			1,
			900
		};
		Crash2[] = {
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_3",
			1,
			1,
			900
		};
		Crash3[] = {
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_4",
			1,
			1,
			900
		};
		soundCrashes[] = {
			"Crash0",
			0.25,
			"Crash1",
			0.25,
			"Crash2",
			0.25,
			"Crash3",
			0.25
		};
		soundDammage[] = {
			"",
			0.56234097,
			1
		};
		soundEngineOnInt[] = {
			"A3\Sounds_F_Jets\vehicles\air\UAV_05\B_UAV_05_engine_start_int",
			1,
			1
		};
		soundEngineOnExt[] = {
			"A3\Sounds_F_Jets\vehicles\air\UAV_05\B_UAV_05_engine_start_ext",
			1.75,
			1,
			300
		};
		soundEngineOffInt[] = {
			"A3\Sounds_F_Jets\vehicles\air\UAV_05\B_UAV_05_engine_shut_int",
			1,
			1
		};
		soundEngineOffExt[] = {
			"A3\Sounds_F_Jets\vehicles\air\UAV_05\B_UAV_05_engine_shut_ext",
			1.75,
			1,
			300
		};
		soundLocked[] = {
			"A3\Sounds_F_Jets\vehicles\air\Shared\FX_Plane_Jet_lockedOn1",
			1,
			1
		};
		soundIncommingMissile[] = {
			"A3\Sounds_F_Jets\vehicles\air\Shared\FX_Plane_Jet_lockedon2",
			1,
			1.5
		};
		soundGearUp[] = {
			"A3\Sounds_F_Jets\vehicles\air\Shared\FX_Plane_Jet_gear_up",
			2.25,
			1,
			250
		};
		soundGearDown[] = {
			"A3\Sounds_F_Jets\vehicles\air\Shared\FX_Plane_Jet_gear_down",
			2.25,
			1,
			250
		};
		soundFlapsUp[] = {
			"A3\Sounds_F_Jets\vehicles\air\Shared\FX_Plane_Jet_Flaps_Up",
			1.5,
			1,
			150
		};
		soundFlapsDown[] = {
			"A3\Sounds_F_Jets\vehicles\air\Shared\FX_Plane_Jet_Flaps_Down",
			1.5,
			1,
			150
		};
		class Sounds {
			soundSets[] = {
				"UAV_05_EngineLowExt_SoundSet",
				"UAV_05_EngineHighExt_SoundSet",
				"UAV_05_ForsageExt_SoundSet",
				"UAV_05_WindNoiseExt_SoundSet",
				"UAV_05_DistanceRumble_SoundSet",
				"UAV_05_EngineLowInt_SoundSet",
				"UAV_05_EngineHighInt_SoundSet",
				"UAV_05_ForsageInt_SoundSet",
				"UAV_05_WindNoiseInt_SoundSet"
			};
		};
		class RainExt {
			sound[] = {
				"A3\Sounds_F\vehicles\noises\rain1_ext",
				1.77828,
				1,
				100
			};
			frequency = 1;
			volume = "camPos * rain * (speed factor[50, 0])";
		};
		class RainInt {
			sound[] = {
				"A3\Sounds_F\vehicles\noises\rain1_int",
				1,
				1,
				100
			};
			frequency = 1;
			volume = "(1-camPos) * rain * (speed factor[50, 0])";
		};
		class AnimationSources: AnimationSources {
			class gear_front_hook_down {
				source = "user";
				animPeriod = 2.5;
				initPhase = 0;
			};
			class tailhook {
				source = "user";
				animPeriod = 2.5;
				initPhase = 1;
			};
			class tailhook_door_l_1 {
				source = "user";
				animPeriod = 2.5;
				initPhase = 1;
			};
			class tailhook_door_l_2 {
				source = "user";
				animPeriod = 2.5;
				initPhase = 1;
			};
			class tailhook_door_r_1 {
				source = "user";
				animPeriod = 2.5;
				initPhase = 1;
			};
			class tailhook_door_r_2 {
				source = "user";
				animPeriod = 2.5;
				initPhase = 1;
			};
			class wing_fold_l_arm {
				source = "user";
				animPeriod = 4.5;
				initPhase = 0;
			};
			class wing_fold_l {
				source = "user";
				animPeriod = 4.5;
				initPhase = 0;
				displayName = "$STR_A3_action_wings_fold";
				mass = 0;
				forceAnimatePhase = 1;
				forceAnimatePhase2 = 0;
				forceAnimate[] = {
					"wing_fold_l",
					1,
					"wing_fold_l_arm",
					1,
					"wing_fold_cover_l_arm",
					1,
					"wing_fold_cover_l",
					1,
					"wing_fold_r",
					1,
					"wing_fold_r_arm",
					1,
					"wing_fold_cover_r_arm",
					1,
					"wing_fold_cover_r",
					1
				};
				forceAnimate2[] = {
					"wing_fold_l",
					0,
					"wing_fold_l_arm",
					0,
					"wing_fold_cover_l_arm",
					0,
					"wing_fold_cover_l",
					0,
					"wing_fold_r",
					0,
					"wing_fold_r_arm",
					0,
					"wing_fold_cover_r_arm",
					0,
					"wing_fold_cover_r",
					0
				};
			};
			class wing_fold_cover_l_arm {
				source = "user";
				animPeriod = 4.5;
				initPhase = 0;
			};
			class wing_fold_cover_l {
				source = "user";
				animPeriod = 4.5;
				initPhase = 0;
			};
			class wing_fold_r_arm {
				source = "user";
				animPeriod = 4.5;
				initPhase = 0;
			};
			class wing_fold_r {
				source = "user";
				animPeriod = 4.5;
				initPhase = 0;
			};
			class wing_fold_cover_r_arm {
				source = "user";
				animPeriod = 4.5;
				initPhase = 0;
			};
			class wing_fold_cover_r {
				source = "user";
				animPeriod = 4.5;
				initPhase = 0;
			};
			class CollisionLightRed1_source {
				source = "MarkerLight";
				markerLight = "CollisionLightRed1";
			};
			class Damper_1_source {
				source = "damper";
				wheel = "Wheel_1";
			};
			class Damper_2_source {
				source = "damper";
				wheel = "Wheel_2";
			};
			class Damper_3_source {
				source = "damper";
				wheel = "Wheel_3";
			};
			class Wheel_1_source {
				source = "wheel";
				wheel = "Wheel_1";
			};
			class Wheel_2_source {
				source = "wheel";
				wheel = "Wheel_2";
			};
			class Wheel_3_source {
				source = "wheel";
				wheel = "Wheel_3";
			};
		};
		class MarkerLights {
			class CollisionLightRed1 {
				name = "pos_collision_light_red_1";
				blinking = 1;
				blinkingStartsOn = 1;
				blinkingPattern[] = {0.1,0.89999998};
				blinkingPatternGuarantee = 1;
				color[] = {0.80000001,0,0};
				ambient[] = {0.079999998,0,0};
				intensity = 75;
				drawLight = 1;
				drawLightSize = 0.25;
				drawLightCenterSize = 0.050000001;
				activeLight = 0;
				dayLight = 0;
				useFlare = 0;
				class Attenuation {
					start = 0;
					constant = 0;
					linear = 25;
					quadratic = 50;
					hardLimitStart = 0.75;
					hardLimitEnd = 1;
				};
			};
		};
		class Reflectors {
			class Gear_Front_light_1 {
				position = "pos_gear_front_light";
				direction = "pos_gear_front_light_dir";
				hitpoint = "pos_gear_front_light";
				selection = "gear_front_light";
				color[] = {0.85000002,0.94999999,1};
				ambient[] = {0.0085000005,0.0094999997,0.0099999998};
				intensity = 500000;
				size = 1;
				innerAngle = 15;
				outerAngle = 50;
				coneFadeCoef = 1;
				useFlare = 1;
				dayLight = 0;
				FlareSize = 2;
				flareMaxDistance = 500;
				class Attenuation {
					start = 1;
					constant = 0;
					linear = 0;
					quadratic = 4;
					hardLimitStart = 350;
					hardLimitEnd = 650;
				};
			};
		};
		airBrake = 1;
		airBrakeFrictionCoef = 2.2;
		flaps = 1;
		flapsFrictionCoef = 0.15000001;
		gearsUpFrictionCoef = 0.80000001;
		brakeDistance = 250;
		wheelSteeringSensitivity = 2;
		maxSpeed = 800;
		altFullForce = 4000;
		altNoForce = 14000;
		rudderInfluence = 0.93959999;
		aileronSensitivity = 0.69999999;
		elevatorSensitivity = 0.60000002;
		elevatorControlsSensitivityCoef = 3;
		aileronControlsSensitivityCoef = 3;
		rudderControlsSensitivityCoef = 3;
		envelope[] = {0,0.28,1.04,2.1600001,3.2,4,4.3200002,5.1199999,5.4899998,5.8800001,6};
		thrustCoef[] = {1.4,1.35,1.3200001,1.37,1.42,1.46,1.48,1.5,1.51,1.25,0.89999998,0,0};
		elevatorCoef[] = {0,0.36000001,1.4400001,0.64999998,0.5,0.44999999,0.40000001,0.34999999,0.30000001,0.25999999,0.22,0.19,0.13};
		aileronCoef[] = {0,0.12,0.38,0.40000001,0.44999999,0.46000001,0.47,0.47999999,0.49000001,0.5,0.49000001,0.47999999,0.44999999};
		rudderCoef[] = {0,0.2,0.89999998,1.9,2,2.0999999,2.0999999,2.2,2.2,2.0999999,2.0999999,1.9,1.5};
		angleOfIndicence = "-0.25*3.1415/180";
		draconicForceXCoef = 9.5;
		draconicForceYCoef = 0.89999998;
		draconicForceZCoef = 1;
		draconicTorqueXCoef[] = {8,8.3000002,8.6000004,8.8999996,9.3000002,9.6999998,10.1,10.6,11.1,11.6,12,12.4,12.8};
		draconicTorqueYCoef[] = {14,9,2,0.1,0,0,0,0,0,0,0,0,0};
		airFrictionCoefs0[] = {0,0,0};
		airFrictionCoefs1[] = {0.1,0.5,0.0055};
		airFrictionCoefs2[] = {0.001,0.0049999999,5.6000001e-005};
		gunAimDown = 0;
		landingSpeed = 225;
		stallSpeed = 200;
		stallWarningTreshold = 0.1;
		acceleration = 200;
		landingAoa = "8.5*3.1415/180";
		class UserActions {
			class UAV05_tailhook_down {
				displayName = "$STR_A3_action_tailhook_down";
				shortcut = "";
				condition = "this animationPhase ""tailhook"" > 0.1 and speed this > 100";
				statement = "this animate [""tailhook"",0]; this animate [""tailhook_door_l_1"",0]; this animate [""tailhook_door_l_2"",0]; this animate [""tailhook_door_r_1"",0]; this animate [""tailhook_door_r_2"",0]; this say ""UAV_05_tailhook_down_sound""; this say3D ""UAV_05_tailhook_down_sound""; [this] spawn BIS_fnc_AircraftTailhook;";
				position = "pilotcontrol";
				radius = 10;
				onlyforplayer = 1;
				showWindow = 0;
				hideOnUse = 1;
			};
			class UAV05_tailhook_up {
				displayName = "$STR_A3_action_tailhook_up";
				shortcut = "";
				condition = "this animationPhase ""tailhook"" < 0.1";
				statement = "this animate [""tailhook"",1]; this animate [""tailhook_door_l_1"",1]; this animate [""tailhook_door_l_2"",1]; this animate [""tailhook_door_r_1"",1]; this animate [""tailhook_door_r_2"",1]; this say ""UAV_05_tailhook_up_sound""; this say3D ""UAV_05_tailhook_up_sound""";
				position = "pilotcontrol";
				radius = 10;
				onlyforplayer = 1;
				showWindow = 0;
				hideOnUse = 1;
			};
			class UAV05_fold_wings {
				displayName = "$STR_A3_action_wings_fold";
				position = "pilotcontrol";
				shortcut = "";
				radius = 5;
				condition = "this animationPhase ""wing_fold_l"" < 0.1 and (getpos this select 2) < 1 and (speed this) < 40";
				statement = "this animate [""wing_fold_l"",1]; this animate [""wing_fold_l_arm"",1]; this animate [""wing_fold_cover_l_arm"",1]; this animate [""wing_fold_cover_l"",1]; this animate [""wing_fold_r"",1]; this animate [""wing_fold_r_arm"",1]; this animate [""wing_fold_cover_r_arm"",1]; this animate [""wing_fold_cover_r"",1]; this say3D ""UAV_05_foldwing_sound""";
				onlyforplayer = 1;
				showWindow = 0;
				hideOnUse = 1;
			};
			class UAV05_unfold_wings {
				displayName = "$STR_A3_action_wings_unfold";
				position = "pilotcontrol";
				shortcut = "";
				radius = 5;
				condition = "this animationPhase ""wing_fold_l"" > 0.9";
				statement = "this animate [""wing_fold_l"",0]; this animate [""wing_fold_l_arm"",0]; this animate [""wing_fold_cover_l_arm"",0]; this animate [""wing_fold_cover_l"",0]; this animate [""wing_fold_r"",0]; this animate [""wing_fold_r_arm"",0]; this animate [""wing_fold_cover_r_arm"",0]; this animate [""wing_fold_cover_r"",0]; this say3D ""UAV_05_foldwing_sound""";
				onlyforplayer = 1;
				showWindow = 0;
				hideOnUse = 1;
			};
		};
		class TextureSources {
			class DarkGrey {
				displayName = "$STR_A3_VirtualGarage_UAV_05_Camo_01";
				author = "$STR_A3_author_B01";
				textures[] = {
					"A3\Air_F_Jets\UAV_05\Data\UAV05_fuselage_01_co.paa",
					"A3\Air_F_Jets\UAV_05\Data\UAV05_fuselage_02_co.paa"
				};
				factions[] = {
					"BLU_F"
				};
			};
			class DarkGreyCamo {
				displayName = "$STR_A3_VirtualGarage_UAV_05_Camo_02";
				author = "$STR_A3_author_B01";
				textures[] = {
					"A3\Air_F_Jets\UAV_05\Data\UAV05_fuselage_01_Camo_co.paa",
					"A3\Air_F_Jets\UAV_05\Data\UAV05_fuselage_02_Camo_co.paa"
				};
				factions[] = {
					"BLU_F"
				};
			};
		};
		animationList[] = {};
		textureList[] = {
			"DarkGrey",
			1,
			"DarkGreyCamo",
			0
		};
		maxOmega = 3000;
		class Wheels {
			disableWheelsWhenDestroyed = 1;
			class Wheel_1 {
				boneName = "wheels_f";
				steering = 1;
				side = "left";
				center = "pos_wheels_f_center";
				boundary = "pos_wheels_f_rim";
				width = 0.30000001;
				mass = 150;
				MOI = 2;
				dampingRate = 0.1;
				dampingRateDamaged = 1;
				dampingRateDestroyed = 1000;
				maxBrakeTorque = 1000;
				maxHandBrakeTorque = 0;
				suspTravelDirection[] = {0,-1,0};
				suspForceAppPointOffset = "pos_wheels_f_center";
				tireForceAppPointOffset = "pos_wheels_f_center";
				maxCompression = 0.15000001;
				maxDroop = 0.15000001;
				sprungMass = 3000;
				springStrength = 230000;
				springDamperRate = 62000;
				longitudinalStiffnessPerUnitGravity = 1500;
				latStiffX = 2;
				latStiffY = 20;
				frictionVsSlipGraph[] = { {0,0.60000002}, {0.2,1}, {0.60000002,0.80000001}
				};
			};
			class Wheel_2: Wheel_1 {
				boneName = "wheel_l";
				steering = 0;
				center = "pos_wheel_l_center";
				boundary = "pos_wheel_l_rim";
				width = 0.28;
				sprungMass = 4225;
				springStrength = 310000;
				springDamperRate = 82000;
				maxBrakeTorque = 2000;
				longitudinalStiffnessPerUnitGravity = 1800;
				suspForceAppPointOffset = "pos_wheel_l_center";
				tireForceAppPointOffset = "pos_wheel_l_center";
			};
			class Wheel_3: Wheel_2 {
				boneName = "wheel_r";
				side = "right";
				center = "pos_wheel_r_center";
				boundary = "pos_wheel_r_rim";
				suspForceAppPointOffset = "pos_wheel_r_center";
				tireForceAppPointOffset = "pos_wheel_r_center";
			};
		};
		class Exhausts {
			class Exhaust1 {
				position = "pos_exhaust1";
				direction = "pos_exhaust1_dir";
				effect = "ExhaustsEffectPlaneHP";
				engineIndex = 0;
			};
			class Exhaust2 {
				position = "pos_exhaust2";
				direction = "pos_exhaust2_dir";
				effect = "ExhaustsEffectPlaneHP";
				engineIndex = 1;
			};
		};
		class WingVortices {
			class WingTipLeft {
				effectName = "FX_WingVortices_FighterJet";
				position = "pos_wingtip_vapour_L";
			};
			class WingTipRight {
				effectName = "FX_WingVortices_FighterJet";
				position = "pos_wingtip_vapour_R";
			};
			class BodyLeft_inner_1 {
				effectName = "FX_FuselageVapour_FighterJet";
				position = "pos_body_vapour_L_1";
			};
			class BodyLeft_inner_2 {
				effectName = "FX_FuselageVapour_FighterJet";
				position = "pos_body_vapour_L_2";
			};
			class BodyLeft_inner_3 {
				effectName = "FX_FuselageVapour_FighterJet";
				position = "pos_body_vapour_L_3";
			};
			class BodyRight_inner_1 {
				effectName = "FX_FuselageVapour_FighterJet";
				position = "pos_body_vapour_R_1";
			};
			class BodyRight_inner_2 {
				effectName = "FX_FuselageVapour_FighterJet";
				position = "pos_body_vapour_R_2";
			};
			class BodyRight_inner_3 {
				effectName = "FX_FuselageVapour_FighterJet";
				position = "pos_body_vapour_R_3";
			};
		};
		class Armory {
			description = "$STR_A3_UCAV_05_armory_description";
		};
		tailHook = 1;
		class CarrierOpsCompatability {
			ArrestHookAnimationList[] = {
				"tailhook",
				"tailhook_door_l_1",
				"tailhook_door_l_1",
				"tailhook_door_r_1",
				"tailhook_door_r_1"
			};
			ArrestHookAnimationStates[] = {0,0.52999997,1};
			ArrestHookMemoryPoint = "pos_tailhook";
			ArrestMaxAllowedSpeed = 295;
			ArrestSlowDownStep = 0.69999999;
			ArrestVelocityReduction = -12;
			LaunchVelocity = 275;
			LaunchVelocityIncrease = 10;
			LaunchAccelerationStep = 0.001;
		};
		class AircraftAutomatedSystems {
			wingStateControl = 1;
			wingFoldAnimations[] = {
				"wing_fold_l",
				"wing_fold_l_arm",
				"wing_fold_cover_l_arm",
				"wing_fold_cover_l",
				"wing_fold_r",
				"wing_fold_r_arm",
				"wing_fold_cover_r_arm",
				"wing_fold_cover_r"
			};
			wingStateFolded = 1;
			wingStateUnFolded = 0;
			wingAutoUnFoldSpeed = 40;
		};
		class Eventhandlers: Eventhandlers {
			init = 				"[_this select 0] spawn NIC_EUAV_fnc_AddAiRefreshAction";
			landing = 			"[_this, true] call bis_fnc_aircraftTailhookAi";
			landingcanceled = 	"[_this, false] call bis_fnc_aircraftTailhookAi";
			engine = 			"_this call bis_fnc_aircraftFoldingWings";
			gear = 				"_this call bis_fnc_aircraftFoldingWings";
			fired = 				"[_this select 0, _this select 5, _this select 6] spawn NIC_EUAV_fnc_ProjectileMonitor";
		};
	};
	class B_UAV_05_F_Enhanced: UAV_05_Base_F_Enhanced {
		class SimpleObject {
			eden = 1;
			animate[] = {
				{
					"damagehide",
					0
				},
				{
					"engine_fire_l",
					0
				},
				{
					"engine_fire_right",
					0
				},
				{
					"weapons_bay_l_1",
					0
				},
				{
					"weapons_bay_l_2",
					0
				},
				{
					"weapons_bay_r_1",
					0
				},
				{
					"weapons_bay_r_2",
					0
				},
				{
					"weapons_rack_l_1",
					0
				},
				{
					"weapons_rack_l_2",
					0
				},
				{
					"weapons_rack_l_3",
					0
				},
				{
					"weapons_rack_r_1",
					0
				},
				{
					"weapons_rack_r_2",
					0
				},
				{
					"weapons_rack_r_3",
					0
				},
				{
					"gear_door_f_1",
					0
				},
				{
					"gear_door_f_2",
					0
				},
				{
					"gear_door_l_1",
					0
				},
				{
					"gear_door_l_2",
					0
				},
				{
					"gear_door_r_1",
					0
				},
				{
					"gear_door_r_2",
					0
				},
				{
					"gear_front_hydraulic_4",
					0
				},
				{
					"gear_front",
					0
				},
				{
					"gear_front_hydraulic_1",
					0
				},
				{
					"gear_front_hook",
					0
				},
				{
					"gear_front_hydraulic_2",
					0
				},
				{
					"gear_front_hydraulic_3",
					0
				},
				{
					"gear_front_stearing",
					0
				},
				{
					"gear_front_suspension",
					0
				},
				{
					"gear_front_suspension_1",
					0
				},
				{
					"gear_front_suspension_2",
					0
				},
				{
					"gear_rear_l",
					0
				},
				{
					"gear_rear_hydraulic_l_1",
					0
				},
				{
					"gear_rear_hydraulic_l_2",
					0
				},
				{
					"gear_rear_rotate_l",
					0
				},
				{
					"gear_rear_suspension_l",
					0
				},
				{
					"gear_rear_suspension_l_1",
					0
				},
				{
					"gear_rear_suspension_l_2",
					0
				},
				{
					"gear_rear_r",
					0
				},
				{
					"gear_rear_hydraulic_r_1",
					0
				},
				{
					"gear_rear_hydraulic_r_2",
					0
				},
				{
					"gear_rear_rotate_r",
					0
				},
				{
					"gear_rear_suspension_r",
					0
				},
				{
					"gear_rear_suspension_r_1",
					0
				},
				{
					"gear_rear_suspension_r_2",
					0
				},
				{
					"wheels_f",
					0
				},
				{
					"wheel_l",
					0
				},
				{
					"wheel_r",
					0
				},
				{
					"aileron_l",
					0
				},
				{
					"aileron_r",
					0
				},
				{
					"airbrake_l",
					0
				},
				{
					"airbrake_r",
					0
				},
				{
					"rudder_l",
					0
				},
				{
					"rudder_r",
					0
				},
				{
					"elevator_l_1",
					0
				},
				{
					"elevator_l_2",
					0
				},
				{
					"elevator_r_1",
					0
				},
				{
					"elevator_r_2",
					0
				},
				{
					"flap_l",
					0
				},
				{
					"flap_r",
					0
				},
				{
					"mainturret",
					0
				},
				{
					"maingun",
					-0.79000002
				},
				{
					"collision_lights_l",
					0
				},
				{
					"collision_lights_r",
					0
				},
				{
					"collision_lights_c1_blinking",
					0
				}
			};
			hide[] = {
				"clan",
				"zasleh",
				"gear_front_light",
				"zadni svetlo",
				"podsvit pristroju",
				"poskozeni"
			};
			verticalOffset = 1.791;
			verticalOffsetWorld = -0.064000003;
			init = "[this, '', []] call bis_fnc_initVehicle";
		};
		author = "NIC";
		scope = 2;
		scopeCurator = 2;
		displayName = "UCAV Sentinel Enhanced";
	};
};
class CfgWeapons {
	class MissileLauncher;
	class RocketPods;
	class weapon_HARMLauncher: MissileLauncher {
		displayName = "$STR_A3_Missile_HARM_weapon_name";
		weaponLockDelay = 1.5;
		weaponLockSystem = 0;
		cmImmunity = 0.75;
		showAimCursorInternal = 0;
		reloadTime = 0.1;
		magazineReloadTime = 0.1;
		magazines[] = {
			"magazine_Missile_HARM_x1",
			"PylonRack_Missile_HARM_x1",
			"PylonMissile_Missile_HARM_x1",
			"PylonMissile_Missile_HARM_INT_x1"
		};
		aiRateOfFire = 15;
		aiRateOfFireDispersion = -10;
		aiRateOfFireDistance = 10000;
		minRange = 1000;
		minRangeProbab = 0.89999998;
		midRange = 3000;
		midRangeProbab = 1;
		maxRange = 16000;
		maxRangeProbab = 1;
		textureType = "semi";
		sounds[] = {
			"StandardSound"
		};
		class StandardSound {
			begin1[] = {
				"A3\Sounds_F\weapons\Rockets\missile_2",
				1.12202,
				1.3,
				1000
			};
			soundBegin[] = {
				"begin1",
				1
			};
			weaponSoundEffect = "DefaultRifle";
		};
		soundFly[] = {
			"A3\Sounds_F\weapons\Rockets\rocket_fly_1",
			1,
			1.5,
			700
		};
		lockedTargetSound[] = {
			"\A3\Sounds_F\weapons\Rockets\locked_3",
			0.56234133,
			2.5
		};
		lockingTargetSound[] = {
			"\A3\Sounds_F\weapons\Rockets\locked_1",
			0.56234133,
			1
		};
		modes[] = {
			"LoalDistance"
		};
		class LoalDistance: MissileLauncher {
			displayName = "$STR_A3_Missile_HARM_weapon_name";
			textureType = "semi";
			reloadTime = 4;
			aiRateOfFire = 15;
			aiRateOfFireDispersion = -10;
			aiRateOfFireDistance = 10000;
			minRange = 1000;
			minRangeProbab = 0.89999998;
			midRange = 3000;
			midRangeProbab = 1;
			maxRange = 16000;
			maxRangeProbab = 1;
			sounds[] = {
				"StandardSound"
			};
			class StandardSound {
				begin1[] = {
					"A3\Sounds_F\weapons\Rockets\missile_2",
					1.12202,
					1.3,
					1000
				};
				soundBegin[] = {
					"begin1",
					1
				};
				weaponSoundEffect = "DefaultRifle";
			};
			soundFly[] = {
				"A3\Sounds_F\weapons\Rockets\rocket_fly_1",
				1,
				1.5,
				700
			};
			lockedTargetSound[] = {
				"\A3\Sounds_F\weapons\Rockets\locked_3",
				0.56234133,
				2.5
			};
			lockingTargetSound[] = {
				"\A3\Sounds_F\weapons\Rockets\locked_1",
				0.56234133,
				1
			};
		};
	};
	class weapon_SDBLauncher: RocketPods {
		displayName = "$STR_A3_Bomb_SDB_weapon_name";
		weaponLockDelay = 0.1;
		weaponLockSystem = "2 + 4";
		cmImmunity = 0.30000001;
		minRange = 300;
		minRangeProbab = 0.40000001;
		midRange = 1000;
		midRangeProbab = 0.94999999;
		maxRange = 8000;
		maxRangeProbab = 0.89999998;
		magazines[] = {
			"magazine_Bomb_SDB_x1",
			"PylonRack_Bomb_SDB_x4"
		};
		reloadTime = 0.1;
		autoFire = 0;
		magazineReloadTime = 0.1;
		aiRateOfFire = 5;
		aiRateOfFireDistance = 500;
		nameSound = "";
		cursor = "EmptyCursor";
		cursorAim = "bomb";
		showAimCursorInternal = 0;
		ballisticsComputer = 8;
		textureType = "semi";
		lockedTargetSound[] = {
			"\A3\Sounds_F\weapons\Rockets\locked_3",
			5.56234133,
			2.5
		};
		lockingTargetSound[] = {
			"\A3\Sounds_F\weapons\Rockets\locked_1",
			5.56234133,
			1
		};
	};
	
};

