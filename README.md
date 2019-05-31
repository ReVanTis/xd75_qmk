# QMK Keymap for ReVanTis' XD75

How to setup:

- Setup qmk build environment.
- cd to qmk_firmware root.
- git clone git@github.com:ReVanTis/xd75_qmk.git keyboards/xd75/keymaps/vaninc
- run make xd75:vaninc to verify
- run make xd75:vaninc:dfu to flash
- To exclude this keymap from qmk_firmware locally add keyboards/xd75/keymaps/vaninc/* to qmk_firmware/.git/info/exclude


Or automatically:

- cd to qmk_firmware root.
- execute "curl -s https://raw.githubusercontent.com/ReVanTis/xd75_qmk/master/scripts/setup.sh | bash"
