import sys, os
Import("env")
try:
    from xmodem import XMODEM
except ImportError:
    env.Execute('"$PYTHONEXE" -m pip install xmodem')

if sys.platform.startswith("win32"):
    env.Replace(UPLOADER = '"$PROJECT_DIR\\buildroot\\share\\PlatformIO\\scripts\\stm32-xmodem-uploader.py"')
elif sys.platform.startswith("linux"):
    env.Replace(UPLOADER = '"$PROJECT_DIR/buildroot/share/PlatformIO/scripts/stm32-xmodem-uploader.py"')
    
env.Replace(UPLOADCMD='python -u $UPLOADER "$UPLOAD_PORT" $UPLOAD_FLAGS "$BUILD_DIR/${PROGNAME}.bin"')