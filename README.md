This is my layout for the [Inland MK47] ortholinear keyboard.

[inland mk47]: https://www.microcenter.com/product/661264/inland-47-keys-hot-swappable-rgb-wired-mechanical-keyboard,

## Compiling

First, clone the [qmk_firmware] repository:

    git clone https://github.com/qmk/qmk_firmware

Change into that directory, and then clone this repository into `keyboards/inland/mk47/keymaps/larsks`:

    git clone https://github.com/larsks/qmk-keymap-mk47 keyboards/inland/mk47/keymaps/larsks

Then you can compile it using `qmk compile`:

    qmk comple -kb inland/mk47 -km larsks

Or by using `make`:

    make -C keyboards/inland/mk47/keymaps/larsks

[qmk firmware]: https://github.com/qmk/qmk_firmware

