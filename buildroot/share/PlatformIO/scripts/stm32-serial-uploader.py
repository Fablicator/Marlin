Import("env")

env.Replace(
    UPLOADER="$PROJECT_DIR\\buildroot\\share\\PlatformIO\\scripts\\stm32-serial-uploader.exe",
    UPLOADCMD="$UPLOADER --mcu-type $UPLOAD_FLAGS --port $UPLOAD_PORT --binary $BUILD_DIR/${PROGNAME}.bin"
)