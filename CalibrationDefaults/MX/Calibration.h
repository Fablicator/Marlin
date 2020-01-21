//============================================================================
//=========================== DEFINE PRINTER MODEL ===========================
//============================================================================

// UNCOMMMENT USING CTRL+/ TO SELECT THE PRINTER YOU ARE USING
// THIS WILL CHANGE THE CONFIGURATION TO MATCH THE PRINTER

// #define USING_FM1
// #define USING_SX
#define USING_MX

//=============================================================================
//============================= CALIBRATE PRINTER =============================
//=============================================================================


#define Z_MAX_POS 251.05            // Decrease this value if first layer is too close to the print bed.
#define HOTEND_OFFSET_Y {0.0, 0.1}  // (0, X in mm) If the right extruder is printing too far towards the front of the machine, decrease this number
#define X1_BED_OFFSET   9.5     // Distance between left extruder tip and left side of bed when it's at the home position
#define X2_BED_OFFSET   17.40   // If the right extruder is printing too far to the right, increase this value

// EXTRUDER PID TUNING
// USE "M303 C8 E0 S240" TO FIND VALUES AUTOMATICALLY
// #define  DEFAULT_Kp 11.44
// #define  DEFAULT_Ki 0.9
// #define  DEFAULT_Kd 36.31

#define TEMP_SENSOR_BED 16          // Defines what thermistor we are using on the bed (17 for the green thermistor, 16 for the new blue thermistor)
#define FILAMENT_RUNOUT_SENSOR    // Uncomment this to enable filament out sensors.

// #define USING_INDUSTRIAL_SUPPLY   // Define this to use the industrial supply setup.