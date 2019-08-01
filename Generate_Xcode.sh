set -e
cd "`dirname "$0"`"

if [ -f Neural/Tools/Scripts/Mac/Generate_Xcode.sh ]; then
    sh Neural/Tools/Scripts/Mac/Generate_Xcode.sh
fi