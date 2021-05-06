import sys
import os

SRC="main.cpp"
BIN="main"
HEX="main.hex"

CC="avr-g++"
CO="avr-objcopy"
CU="avrdude"

CLOCK=int(16e6)
TARGET="atmega328p"
BAUDRATE=115200
PORT="COM6"

def compile():
    print("Compiling...")
    cmd = f"{CC} -DF_CPU={CLOCK} -mmcu={TARGET} -Os {SRC} -o {BIN}"
    print(cmd)
    os.system(cmd)
    cmd = f"{CO} -O ihex {BIN} {HEX}"
    print(cmd)
    os.system(cmd)
    
def upload():
    print("Uploading...")
    cmd = f"{CU} -D -v -carduino -p{TARGET} -P{PORT} -b{BAUDRATE} -Uflash:w:{HEX}:i"
    cmd += " -CG:\\Programmes\\Arduino\\hardware\\tools\\avr\\etc\\avrdude.conf"
    print(cmd)
    os.system(cmd)

def clean():
    print("Cleaning...")
    try:
        os.remove(f"{BIN}")
    except:
        pass
    try:
        os.remove(f"{HEX}")
    except:
        pass

if __name__ == "__main__":
    if len(sys.argv) == 1:
        compile()
        upload()
        clean()
    elif sys.argv[1] == "compile":
        compile()
    elif sys.argv[1] == "upload":
        upload()
    elif sys.argv[1] == "clean":
        clean()
    else:
        raise Exception("Unknown target")
