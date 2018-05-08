# This script is used to simplify building the static c++ project library, then building the required Node.js
# module and moving it to the proper location, and lastly starting the Node.js server

echo "Building static library..."
res="$(cd c++ && make clean || cd c++ && make)"
echo "${res}"

echo "Removing old Node.js module version..."
res="$(rm nodejs/lib/module.node)"
echo "${res}"

echo "Building Node.js module..."
res="$(cd nodejs && npm run compile --python=python2.7)"
echo "${res}"

echo "Moving new Node.js module..."
res="$(mv nodejs/build/Release/module.node nodejs/lib/module.node)"
echo "${res}"

# echo "Starting Node.js server..."
# res="$(cd nodejs && nodemon start)"
# echo "${res}"