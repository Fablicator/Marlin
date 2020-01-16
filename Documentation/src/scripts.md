# About

The `.bat` files located in the *MXFirmware/Scripts* folder automate tasks such as opening the configuration and fetching updates for the firmware from our repository.

# How to use them

To run a script, double-click the `.bat` file.

**Don't drag these scripts outside of the Scripts folder.** 

*If you want a shortcut to a script, right-click the script and click **Create Shortcut** then drag the shortcut to the desktop* 

## Updating the firmware

To update the firmware or check for updates to the firmware, run ***FetchUpdate.bat***. This will download a list of the changes since your version and display them to you asking if you want to use them.

If you want to update, type `Y` ( make sure the Y is capitalized ) then click enter. Your version will then be updated to the latest one.

**After updating you must open the configuration and upload the firmware again.**

## Opening the configuration

The easy way to open the current configuration is to run ***OpenConfiguration.bat***. This will open the firmware files and show `Calibration.h`. 

*This process takes some time because PlatformIO must look through all of the folders in the firmware. **If Atom shows a window that says that it stopped responding just click the button to wait for the program to respond.***