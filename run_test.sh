filename=$1
g++ $filename -o ${filename%.*}.exe -lgnuradio-runtime -lgnuradio-audio -lgnuradio-analog -lboost_system
