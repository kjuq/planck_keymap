# My Planck Layout

Clone qmk_firmware first

```bash
git clone --recursive https://github.com/qmk/qmk_firmware
```

Update sparse-checkout

`.git/info/sparse-checkout`

```
/*

!/keyboards/
/keyboards/planck/*

!/keyboards/planck/ez
!/keyboards/planck/light
!/keyboards/planck/rev1
!/keyboards/planck/rev2
!/keyboards/planck/rev3
!/keyboards/planck/rev4
!/keyboards/planck/rev5
!/keyboards/planck/rev6
!/keyboards/planck/rev6_drop
!/keyboards/planck/thk

!/keyboards/planck/keymaps

!/layouts/community
!/users
```

Then reload

```bash
git sparse-checkout reapply
```

Clone this repository

```bash
cd qmk_firmware/keyboards/planck
mkdir keymaps
cd keymaps
git clone https://github.com/kjuq/planck_keymap
```

Build

```bash
./build.sh
# or if you prefer docker
./build_docker.sh
```
