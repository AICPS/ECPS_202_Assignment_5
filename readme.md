
### Init submodules
```
git submodule add https://github.com/thiagoralves/OpenPLC_v3.git openplc
git submodule add https://github.com/beremiz/matiec.git matiec

git submodule update --init --recursive
```

### Build openplc and matiec
NB: It may require sudoers permission
```
cd openplc
./install.sh linux
```