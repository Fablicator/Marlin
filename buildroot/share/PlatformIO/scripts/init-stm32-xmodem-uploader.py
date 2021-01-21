import sys, os, serial, serial.tools.list_ports
Import("env")
try:
    from xmodem import XMODEM
except ImportError:
    env.Execute('"$PYTHONEXE" -m pip install xmodem')

if sys.platform.startswith("win32"):
    port_pattern = 'COM{0}'
    env.Replace(UPLOADER = '"$PROJECT_DIR\\buildroot\\share\\PlatformIO\\scripts\\stm32-xmodem-uploader.py"')
elif sys.platform.startswith("linux"):
    port_pattern = '/dev/ttyUSB{0}'
    env.Replace(UPLOADER = '"$PROJECT_DIR/buildroot/share/PlatformIO/scripts/stm32-xmodem-uploader.py"')

if 'auto' in env['UPLOAD_PORT']:
    port_name = ''
    for com_port in serial.tools.list_ports.comports():
        if com_port.vid == 0x0403 and com_port.pid == 0x6015:
            try:
                port_name = com_port.device
                port = serial.Serial(port = port_name, baudrate = 115200)
                port.close()
                port = None
                env.Replace(UPLOAD_PORT=port_name)
                break
            except:
                port_name = ''
                pass

    if port_name == '':
        raise IOError('Upload port cannot be automatically detected!')

env.Replace(UPLOADCMD='python3 -u $UPLOADER "$UPLOAD_PORT" $UPLOAD_FLAGS "$BUILD_DIR/${PROGNAME}.bin"')
