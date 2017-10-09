# neuron
Project B3 SV EPFL 2017

## Git command:

git clone https://github.com/lucie-godot/neuron.git

git status

git add .

git status

git commit -m 'my first commit'

git status

git push

Pour recuperer des fichiers sur git (origin/master):

git fetch  -> met a jour l'historique

git pull  -> met a jour les fichiers

## Build a project with cmake:

Don't be in neuron (to avoid reading it with git) or git ignore build folder (right way)


mkdir build

cd build

cmake ../neuron

make
