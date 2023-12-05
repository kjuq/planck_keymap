# My Planck Layout

## Usage

Clone `qmk_firmware` first

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

!/docs/zh-cn
```

Then reload

```bash
git sparse-checkout reapply
```

Ignore keymap. Add this line to `.gitignore`.

```bash
nvim .gitignore
```

```gitignore
/keyboards/planck/keymaps/*
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

## Development

To use clangd and suppress inconpatible flags' errors

```bash
nvim qmk_firmware/.clangd
```

Append them to `CompileFlags/Remove`

```yaml
---
CompileFlags:
  Remove:
    - -mcpu=*
    - -mfpu=*
    - -mfloat-abi=*
    - -mno-unaligned-access
```

It should be like below

```yaml
CompileFlags:
  Add: [-Wno-unknown-attributes, -Wno-maybe-uninitialized, -Wno-unknown-warning-option]
  Remove: [-W*, -mcall-prologues]
  Compiler: clang
---
CompileFlags:
  Remove:
    - -mcpu=*
    - -mfpu=*
    - -mfloat-abi=*
    - -mno-unaligned-access
Diagnostics:
  Suppress:
    - unused-includes
    - unused-parameter
```
