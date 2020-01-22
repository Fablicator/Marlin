# Keeping the firmware up to date

The firmware is kept up to date using Git version control. You can keep your version up to date by periodically running the provided fetch script which fetches the changes necessary to bring your copy up to date.

## To update the firmware:

1. Navigate to `C:\Fablicator\Marlin` and open the `Scripts` folder.
2. Double click `FetchUpdate.bat`.
3. Type `Y` and press enter to update to the latest version after reviewing what changes are being made, **or type `N` to cancel the update.**
4. Wait for script to pull the changes into your directory then press enter to close the script when prompted.
5. Navigate up one folder and open the `Marlin` folder.
6. Find and double click the `Marlin.ino` file to open the firmware in Arduino.
7. Upload the new version.

> **Before you upload, make sure that you either close the Fablicator Interface or click the disconnect button.** The uploader uses the same serial port as the Fablicator Interface to flash a new firmware. If you don't disconnect from the serial port, the Arduino won't be able to access the board to upload.

**In the case that there is a problem updating**, there is a script called `ResetRoot.bat`. This is used to reset the entire root folder to your version's default state.

# About

This firmware is a fork of the popular Marlin firmware ( `https://github.com/marlinfirmware/marlin` ). This fork contains configurations and some additional functionality for the Fablicator 3D printer line.

Our fork of the firmware can be found on GitHub. ( github.com/Fablicator/marlin)