import sys
Import("env")

if sys.platform.startswith("win32"): 
    env.Replace(UPLOADER = "$PROJECT_DIR\\buildroot\\share\\PlatformIO\\scripts\\stm32-serial-uploader\\win32\\stm32-serial-uploader.exe")
else if sys.platform.startswith("linux")
    env.Replace(UPLOADER = "$PROJECT_DIR/buildroot/share/PlatformIO/scripts/stm32-serial-uploader/linux/stm32-serial-uploader")

env.Replace(UPLOADCMD="$UPLOADER --mcu-type $UPLOAD_FLAGS --port $UPLOAD_PORT --binary $BUILD_DIR/${PROGNAME}.bin")