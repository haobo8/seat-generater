directory=`dirname $0`
cd $directory
g++ seatnewnew.cpp -o seatnewnew
./seatnewnew
python3.9 -u excgen.py
echo "Done!"
