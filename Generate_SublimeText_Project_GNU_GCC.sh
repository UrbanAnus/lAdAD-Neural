set -e
cd "`dirname "$0"`"

if [ -f Neural/Tools/Scripts/Linux/Generate_SublimeText_Project_GNU_GCC.sh ]; then
    sh Neural/Tools/Scripts/Linux/Generate_SublimeText_Project_GNU_GCC.sh
fi