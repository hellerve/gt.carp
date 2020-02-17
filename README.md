# gt.carp

A simple wrapper around [my greenthread implementation](https://github.com/hellerve/gt).

## Installation

Currently you have to use `make install` to get `libgt` on your system. The
process then becomes

```
make install
carp -x examples/print.carp
```

## Caveat Emptor

This implementation will leak memory whenever `gt_stop` or `gt_ret` are called,
since they kill the current thread before its resources can be reclaimed. Since
those processes do not get killed before the system exits, this is “only” an
annoyance, since we’re wasting memory. The OS will later reclaim that memory,
but oh well. In order to rectify this, we’d probably need deeper support for
greenthreads inside Carp proper.

<hr/>

Have fun!
