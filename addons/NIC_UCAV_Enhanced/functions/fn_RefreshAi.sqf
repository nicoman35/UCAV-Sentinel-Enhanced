/*
	Author: 		Nicoman
	Function: 		NIC_EUAV_fnc_RefreshAi
	Version: 		1.0
	Edited Date: 	26.04.2021
	
	Description:
		Deletes old AI crew of an UAV, then creates a new one. Reconnects player and reassigns old role.
		Intention: 	Sometimes, UAVs get unresponsive to commands, fly away on their own, do things
					not commanded to do, etc. By replacing the UAV crew with a new one, hopefully
					things get corrected and the UAV gets responsive again.
	
	Parameters:
		_UAV:		Object - UAV 
		
	Returns:
		None
*/

params [["_UAV", objNull]];
if (isNull _UAV) exitWith {};

private _group = group _UAV;																		// get UAV AI group
[_group, (currentWaypoint _group)] setWaypointPosition [getPosASL ((units _group) select 0), -1];	// set current waypoint's position to position of group leader
sleep 0.1;																							// needed short waiting period for group to 'achieve' current waypoint
for "_i" from count waypoints _group - 1 to 0 step -1 do {deleteWaypoint [_group, _i]};				// delete all group waypoints from last to first
// playtest only above code. If AI still causing problems, reactivate code below

// private _connectedPlayer = UAVControl _UAV select 0;
// private _role = UAVControl _UAV select 1;
// _connectedPlayer connectTerminalToUAV objNull;
// {_UAV deleteVehicleCrew _x} forEach crew _UAV;														// delete every AI unit in UAV group
// sleep 0.1;																							// wait a bit (eventually not needed?)
// createVehicleCrew _UAV;																				// create new UAV AI group
// (group ((crew _UAV) select 0)) setBehaviour "SAFE";
// if !(isNull _connectedPlayer) then {																
	// _connectedPlayer connectTerminalToUAV _UAV;														// if player was connected, reconnect player
	// if (_role == "Driver") exitWith {_connectedPlayer action ["SwitchToUAVDriver", _UAV]};			// if player was driver, give player driver role
	// if (_role == "Gunner") then {_connectedPlayer action ["SwitchToUAVGunner", _UAV]};				// if player was gunner, give player gunner role
// };