# Keyboard Keymaps

This repository contains firmware for my keyboards running QMK.

## Keymap

![my_keymap](https://github.com/user-attachments/assets/38274f1a-18bb-4b8b-9a14-ad3ab30835de)<svg width="788" height="2040" viewBox="0 0 788 2040" class="keymap" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink">
<defs>/* start glyphs */
<svg id="tabler:brightness-down">
<svg
  xmlns="http://www.w3.org/2000/svg"
 
 
  viewBox="0 0 24 24"
  fill="none"
  stroke="currentColor"
  stroke-width="2"
  stroke-linecap="round"
  stroke-linejoin="round"
  class="icon icon-tabler icons-tabler-outline icon-tabler-brightness-down"
>
  <path stroke="none" d="M0 0h24v24H0z" fill="none"/>
  <path d="M12 12m-3 0a3 3 0 1 0 6 0a3 3 0 1 0 -6 0" />
  <path d="M12 5l0 .01" />
  <path d="M17 7l0 .01" />
  <path d="M19 12l0 .01" />
  <path d="M17 17l0 .01" />
  <path d="M12 19l0 .01" />
  <path d="M7 17l0 .01" />
  <path d="M5 12l0 .01" />
  <path d="M7 7l0 .01" />
</svg>
</svg>
<svg id="tabler:brightness-up">
<svg
  xmlns="http://www.w3.org/2000/svg"
 
 
  viewBox="0 0 24 24"
  fill="none"
  stroke="currentColor"
  stroke-width="2"
  stroke-linecap="round"
  stroke-linejoin="round"
  class="icon icon-tabler icons-tabler-outline icon-tabler-brightness-up"
>
  <path stroke="none" d="M0 0h24v24H0z" fill="none"/>
  <path d="M12 12m-3 0a3 3 0 1 0 6 0a3 3 0 1 0 -6 0" />
  <path d="M12 5l0 -2" />
  <path d="M17 7l1.4 -1.4" />
  <path d="M19 12l2 0" />
  <path d="M17 17l1.4 1.4" />
  <path d="M12 19l0 2" />
  <path d="M7 17l-1.4 1.4" />
  <path d="M6 12l-2 0" />
  <path d="M7 7l-1.4 -1.4" />
</svg>
</svg>
<svg id="tabler:volume">
<svg
  xmlns="http://www.w3.org/2000/svg"
 
 
  viewBox="0 0 24 24"
  fill="none"
  stroke="currentColor"
  stroke-width="2"
  stroke-linecap="round"
  stroke-linejoin="round"
  class="icon icon-tabler icons-tabler-outline icon-tabler-volume"
>
  <path stroke="none" d="M0 0h24v24H0z" fill="none"/>
  <path d="M15 8a5 5 0 0 1 0 8" />
  <path d="M17.7 5a9 9 0 0 1 0 14" />
  <path d="M6 15h-2a1 1 0 0 1 -1 -1v-4a1 1 0 0 1 1 -1h2l3.5 -4.5a.8 .8 0 0 1 1.5 .5v14a.8 .8 0 0 1 -1.5 .5l-3.5 -4.5" />
</svg>
</svg>
<svg id="tabler:volume-2">
<svg
  xmlns="http://www.w3.org/2000/svg"
 
 
  viewBox="0 0 24 24"
  fill="none"
  stroke="currentColor"
  stroke-width="2"
  stroke-linecap="round"
  stroke-linejoin="round"
  class="icon icon-tabler icons-tabler-outline icon-tabler-volume-2"
>
  <path stroke="none" d="M0 0h24v24H0z" fill="none"/>
  <path d="M15 8a5 5 0 0 1 0 8" />
  <path d="M6 15h-2a1 1 0 0 1 -1 -1v-4a1 1 0 0 1 1 -1h2l3.5 -4.5a.8 .8 0 0 1 1.5 .5v14a.8 .8 0 0 1 -1.5 .5l-3.5 -4.5" />
</svg>
</svg>
<svg id="tabler:volume-off">
<svg
  xmlns="http://www.w3.org/2000/svg"
 
 
  viewBox="0 0 24 24"
  fill="none"
  stroke="currentColor"
  stroke-width="2"
  stroke-linecap="round"
  stroke-linejoin="round"
  class="icon icon-tabler icons-tabler-outline icon-tabler-volume-off"
>
  <path stroke="none" d="M0 0h24v24H0z" fill="none"/>
  <path d="M15 8a5 5 0 0 1 1.912 4.934m-1.377 2.602a5 5 0 0 1 -.535 .464" />
  <path d="M17.7 5a9 9 0 0 1 2.362 11.086m-1.676 2.299a9 9 0 0 1 -.686 .615" />
  <path d="M9.069 5.054l.431 -.554a.8 .8 0 0 1 1.5 .5v2m0 4v8a.8 .8 0 0 1 -1.5 .5l-3.5 -4.5h-2a1 1 0 0 1 -1 -1v-4a1 1 0 0 1 1 -1h2l1.294 -1.664" />
  <path d="M3 3l18 18" />
</svg>
</svg>
</defs>/* end glyphs */
<style>/* inherit to force styles through use tags */
svg path {
    fill: inherit;
}

/* font and background color specifications */
svg.keymap {
    font-family: SFMono-Regular,Consolas,Liberation Mono,Menlo,monospace;
    font-size: 14px;
    font-kerning: normal;
    text-rendering: optimizeLegibility;
    fill: #24292e;
}

/* default key styling */
rect.key {
    fill: #f6f8fa;
}

rect.key, rect.combo {
    stroke: #c9cccf;
    stroke-width: 1;
}

/* default key side styling, only used is draw_key_sides is set */
rect.side {
    filter: brightness(90%);
}

/* color accent for combo boxes */
rect.combo, rect.combo-separate {
    fill: #cdf;
}

/* color accent for held keys */
rect.held, rect.combo.held {
    fill: #fdd;
}

/* color accent for ghost (optional) keys */
rect.ghost, rect.combo.ghost {
    stroke-dasharray: 4, 4;
    stroke-width: 2;
}

text {
    text-anchor: middle;
    dominant-baseline: middle;
}

/* styling for layer labels */
text.label {
    font-weight: bold;
    text-anchor: start;
    stroke: white;
    stroke-width: 4;
    paint-order: stroke;
}

/* styling for optional footer */
text.footer {
    text-anchor: end;
    dominant-baseline: auto;
    stroke: white;
    stroke-width: 4;
    paint-order: stroke;
}

/* styling for combo tap, and key non-tap label text */
text.combo, text.hold, text.shifted, text.left, text.right {
    font-size: 11px;
}

text.hold {
    text-anchor: middle;
    dominant-baseline: auto;
}

text.shifted {
    text-anchor: middle;
    dominant-baseline: hanging;
}

text.left {
    text-anchor: start;
}

text.right {
    text-anchor: end;
}

text.layer-activator {
    text-decoration: underline;
}

/* styling for hold/shifted label text in combo box */
text.combo.hold, text.combo.shifted, text.combo.left, text.combo.right {
    font-size: 8px;
}

/* lighter symbol for transparent keys */
text.trans {
    fill: #7b7e81;
}

/* styling for combo dendrons */
path.combo {
    stroke-width: 1;
    stroke: gray;
    fill: none;
}

/* Start Tabler Icons Cleanup */
/* cannot use height/width with glyphs */
.icon-tabler > path {
    fill: inherit;
    stroke: inherit;
    stroke-width: 2;
}
/* hide tabler's default box */
.icon-tabler > path[stroke="none"][fill="none"] {
    visibility: hidden;
}
/* End Tabler Icons Cleanup */

@media (prefers-color-scheme: dark) {
svg.keymap { fill: #d1d6db; }
rect.key { fill: #3f4750; }
rect.key, rect.combo { stroke: #60666c; }
rect.combo, rect.combo-separate { fill: #1f3d7a; }
rect.held, rect.combo.held { fill: #854747; }
text.label, text.footer { stroke: black; }
text.trans { fill: #7e8184; }
path.combo { stroke: #7f7f7f; }

}

svg.keymap { background-color: #FFF; }</style>
<g transform="translate(30, 0)" class="layer-BASE">
<text x="0" y="28" class="label" id="BASE">BASE:</text>
<g transform="translate(0, 56)">
<g transform="translate(28, 49)" class="key keypos-0">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">Q</text>
</g>
<g transform="translate(84, 35)" class="key keypos-1">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">W</text>
</g>
<g transform="translate(140, 28)" class="key keypos-2">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">E</text>
</g>
<g transform="translate(196, 35)" class="key keypos-3">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">R</text>
</g>
<g transform="translate(252, 42)" class="key keypos-4">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">T</text>
</g>
<g transform="translate(476, 42)" class="key keypos-5">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">Y</text>
</g>
<g transform="translate(532, 35)" class="key keypos-6">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">U</text>
</g>
<g transform="translate(588, 28)" class="key keypos-7">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">I</text>
</g>
<g transform="translate(644, 35)" class="key keypos-8">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">O</text>
</g>
<g transform="translate(700, 49)" class="key keypos-9">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">P</text>
</g>
<g transform="translate(28, 105)" class="key keypos-10">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">A</text>
<text x="0" y="24" class="key hold">Gui</text>
</g>
<g transform="translate(84, 91)" class="key keypos-11">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">S</text>
<text x="0" y="24" class="key hold">Alt</text>
</g>
<g transform="translate(140, 84)" class="key keypos-12">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">D</text>
<text x="0" y="24" class="key hold">Ctrl</text>
</g>
<g transform="translate(196, 91)" class="key keypos-13">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">F</text>
<text x="0" y="24" class="key hold">Shift</text>
</g>
<g transform="translate(252, 98)" class="key keypos-14">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">G</text>
<text x="0" y="24" class="key hold">Hyper</text>
</g>
<g transform="translate(476, 98)" class="key keypos-15">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">H</text>
<text x="0" y="24" class="key hold">Hyper</text>
</g>
<g transform="translate(532, 91)" class="key keypos-16">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">J</text>
<text x="0" y="24" class="key hold">Shift</text>
</g>
<g transform="translate(588, 84)" class="key keypos-17">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">K</text>
<text x="0" y="24" class="key hold">Ctrl</text>
</g>
<g transform="translate(644, 91)" class="key keypos-18">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">L</text>
<text x="0" y="24" class="key hold">Alt</text>
</g>
<g transform="translate(700, 105)" class="key keypos-19">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">;</text>
<text x="0" y="24" class="key hold">Gui</text>
</g>
<g transform="translate(28, 161)" class="key keypos-20">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">Z</text>
</g>
<g transform="translate(84, 147)" class="key keypos-21">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">X</text>
</g>
<g transform="translate(140, 140)" class="key keypos-22">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">C</text>
</g>
<g transform="translate(196, 147)" class="key keypos-23">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">V</text>
</g>
<g transform="translate(252, 154)" class="key keypos-24">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">B</text>
</g>
<g transform="translate(476, 154)" class="key keypos-25">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">N</text>
</g>
<g transform="translate(532, 147)" class="key keypos-26">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">M</text>
</g>
<g transform="translate(588, 140)" class="key keypos-27">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">,</text>
</g>
<g transform="translate(644, 147)" class="key keypos-28">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">.</text>
</g>
<g transform="translate(700, 161)" class="key keypos-29">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">/</text>
</g>
<g transform="translate(168, 205)" class="key keypos-30">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(230, 213) rotate(15.0)" class="key keypos-31">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">Esc</text>
<a href="#NAV">
<text x="0" y="24" class="key hold layer-activator">NAV</text>
</a></g>
<g transform="translate(295, 224) rotate(30.0)" class="key keypos-32">
<rect rx="6" ry="6" x="-26" y="-40" width="52" height="80" class="key"/>
<text x="0" y="0" class="key tap">Space</text>
<a href="#MOU">
<text x="0" y="38" class="key hold layer-activator">MOU</text>
</a></g>
<g transform="translate(433, 224) rotate(-30.0)" class="key keypos-33">
<rect rx="6" ry="6" x="-26" y="-40" width="52" height="80" class="key"/>
<text x="0" y="0" class="key tap">Enter</text>
<a href="#NUM">
<text x="0" y="38" class="key hold layer-activator">NUM</text>
</a></g>
<g transform="translate(498, 213) rotate(-15.0)" class="key keypos-34">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">BSpace</text>
<a href="#SYM">
<text x="0" y="24" class="key hold layer-activator">SYM</text>
</a></g>
<g transform="translate(560, 205)" class="key keypos-35">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g class="combo combopos-0">
<rect rx="6" ry="6" x="42" y="29" width="28" height="26" class="combo"/>
<text x="56" y="42" class="combo tap">:q!</text>
</g>
<g class="combo combopos-1">
<path d="M364,161 l-317,0" class="combo"/>
<path d="M364,161 l317,0" class="combo"/>
<rect rx="6" ry="6" x="350" y="148" width="28" height="26" class="combo"/>
<text x="364" y="161" class="combo tap">
<tspan x="364" dy="-0.6em">Input</tspan><tspan x="364" dy="1.2em">Source</tspan>
</text>
</g>
<g class="combo combopos-2">
<path d="M364,105 l-317,0" class="combo"/>
<path d="M364,105 l317,0" class="combo"/>
<rect rx="6" ry="6" x="350" y="92" width="28" height="26" class="combo"/>
<text x="364" y="105" class="combo tap">
<tspan x="364" dy="-0.6em">Caps</tspan><tspan x="364" dy="1.2em">Word</tspan>
</text>
</g>
<g class="combo combopos-3">
<rect rx="6" ry="6" x="98" y="74" width="28" height="26" class="combo"/>
<text x="112" y="88" class="combo tap">Tab</text>
</g>
<g class="combo combopos-4">
<rect rx="6" ry="6" x="602" y="74" width="28" height="26" class="combo"/>
<text x="616" y="88" class="combo tap"><tspan style="font-size: 78%">Backspace</tspan></text>
</g>
<g class="combo combopos-5">
<rect rx="6" ry="6" x="42" y="141" width="28" height="26" class="combo"/>
<text x="56" y="154" class="combo tap">Undo</text>
</g>
<g class="combo combopos-6">
<path d="M140,147 l-37,0" class="combo"/>
<path d="M140,147 l37,0" class="combo"/>
<rect rx="6" ry="6" x="126" y="134" width="28" height="26" class="combo"/>
<text x="140" y="147" class="combo tap">Cut</text>
</g>
<g class="combo combopos-7">
<rect rx="6" ry="6" x="98" y="130" width="28" height="26" class="combo"/>
<text x="112" y="144" class="combo tap">Copy</text>
</g>
<g class="combo combopos-8">
<rect rx="6" ry="6" x="154" y="130" width="28" height="26" class="combo"/>
<text x="168" y="144" class="combo tap">Paste</text>
</g>
</g>
</g>
<g transform="translate(30, 331)" class="layer-NAV">
<text x="0" y="28" class="label" id="NAV">NAV:</text>
<g transform="translate(0, 56)">
<g transform="translate(28, 49)" class="key keypos-0">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<use href="#tabler:brightness-down" xlink:href="#tabler:brightness-down" x="-7" y="-7" height="14" width="14.0" class="key tap glyph tabler:brightness-down"/>
</g>
<g transform="translate(84, 35)" class="key keypos-1">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<use href="#tabler:brightness-up" xlink:href="#tabler:brightness-up" x="-7" y="-7" height="14" width="14.0" class="key tap glyph tabler:brightness-up"/>
</g>
<g transform="translate(140, 28)" class="key keypos-2">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap"><tspan style="font-size: 70%">Screenshot</tspan></text>
</g>
<g transform="translate(196, 35)" class="key keypos-3">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(252, 42)" class="key keypos-4">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(476, 42)" class="key keypos-5">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(532, 35)" class="key keypos-6">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(588, 28)" class="key keypos-7">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(644, 35)" class="key keypos-8">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(700, 49)" class="key keypos-9">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Switch</tspan><tspan x="0" dy="1.2em">app</tspan>
</text>
</g>
<g transform="translate(28, 105)" class="key keypos-10">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">Gui</text>
</g>
<g transform="translate(84, 91)" class="key keypos-11">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">Alt</text>
</g>
<g transform="translate(140, 84)" class="key keypos-12">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">Ctrl</text>
</g>
<g transform="translate(196, 91)" class="key keypos-13">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">Shift</text>
</g>
<g transform="translate(252, 98)" class="key keypos-14">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(476, 98)" class="key keypos-15">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">←</text>
</g>
<g transform="translate(532, 91)" class="key keypos-16">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">↓</text>
</g>
<g transform="translate(588, 84)" class="key keypos-17">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">↑</text>
</g>
<g transform="translate(644, 91)" class="key keypos-18">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">→</text>
</g>
<g transform="translate(700, 105)" class="key keypos-19">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Switch</tspan><tspan x="0" dy="1.2em">app</tspan>
</text>
</g>
<g transform="translate(28, 161)" class="key keypos-20">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<use href="#tabler:volume-2" xlink:href="#tabler:volume-2" x="-7" y="-7" height="14" width="14.0" class="key tap glyph tabler:volume-2"/>
</g>
<g transform="translate(84, 147)" class="key keypos-21">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<use href="#tabler:volume" xlink:href="#tabler:volume" x="-7" y="-7" height="14" width="14.0" class="key tap glyph tabler:volume"/>
</g>
<g transform="translate(140, 140)" class="key keypos-22">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<use href="#tabler:volume-off" xlink:href="#tabler:volume-off" x="-7" y="-7" height="14" width="14.0" class="key tap glyph tabler:volume-off"/>
</g>
<g transform="translate(196, 147)" class="key keypos-23">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Tmux</tspan><tspan x="0" dy="1.2em">Prefix</tspan>
</text>
</g>
<g transform="translate(252, 154)" class="key keypos-24">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(476, 154)" class="key keypos-25">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Nav</tspan><tspan x="0" dy="1.2em">left</tspan>
</text>
</g>
<g transform="translate(532, 147)" class="key keypos-26">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Vim</tspan><tspan x="0" dy="1.2em">left</tspan>
</text>
</g>
<g transform="translate(588, 140)" class="key keypos-27">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Vim</tspan><tspan x="0" dy="1.2em">right</tspan>
</text>
</g>
<g transform="translate(644, 147)" class="key keypos-28">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Nav</tspan><tspan x="0" dy="1.2em">right</tspan>
</text>
</g>
<g transform="translate(700, 161)" class="key keypos-29">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Switch</tspan><tspan x="0" dy="1.2em">window</tspan>
</text>
</g>
<g transform="translate(168, 205)" class="key keypos-30">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(230, 213) rotate(15.0)" class="key held keypos-31">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key held"/>
</g>
<g transform="translate(295, 224) rotate(30.0)" class="key keypos-32">
<rect rx="6" ry="6" x="-26" y="-40" width="52" height="80" class="key"/>
</g>
<g transform="translate(433, 224) rotate(-30.0)" class="key keypos-33">
<rect rx="6" ry="6" x="-26" y="-40" width="52" height="80" class="key"/>
</g>
<g transform="translate(498, 213) rotate(-15.0)" class="key keypos-34">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(560, 205)" class="key keypos-35">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
</g>
</g>
<g transform="translate(30, 661)" class="layer-MOU">
<text x="0" y="28" class="label" id="MOU">MOU:</text>
<g transform="translate(0, 56)">
<g transform="translate(28, 49)" class="key keypos-0">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(84, 35)" class="key keypos-1">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(140, 28)" class="key keypos-2">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Mouse</tspan><tspan x="0" dy="1.2em">Min</tspan>
</text>
</g>
<g transform="translate(196, 35)" class="key keypos-3">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Mouse</tspan><tspan x="0" dy="1.2em">Max</tspan>
</text>
</g>
<g transform="translate(252, 42)" class="key keypos-4">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(476, 42)" class="key keypos-5">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(532, 35)" class="key keypos-6">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Click</tspan><tspan x="0" dy="1.2em">hint</tspan>
</text>
</g>
<g transform="translate(588, 28)" class="key keypos-7">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Mouse</tspan><tspan x="0" dy="1.2em">hint</tspan>
</text>
</g>
<g transform="translate(644, 35)" class="key keypos-8">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Screen</tspan><tspan x="0" dy="1.2em">hint</tspan>
</text>
</g>
<g transform="translate(700, 49)" class="key keypos-9">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Switch</tspan><tspan x="0" dy="1.2em">app</tspan>
</text>
</g>
<g transform="translate(28, 105)" class="key keypos-10">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">Gui</text>
</g>
<g transform="translate(84, 91)" class="key keypos-11">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">Alt</text>
</g>
<g transform="translate(140, 84)" class="key keypos-12">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">Ctrl</text>
</g>
<g transform="translate(196, 91)" class="key keypos-13">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">Shift</text>
</g>
<g transform="translate(252, 98)" class="key keypos-14">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(476, 98)" class="key keypos-15">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Mouse</tspan><tspan x="0" dy="1.2em">←</tspan>
</text>
</g>
<g transform="translate(532, 91)" class="key keypos-16">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Mouse</tspan><tspan x="0" dy="1.2em">↓</tspan>
</text>
</g>
<g transform="translate(588, 84)" class="key keypos-17">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Mouse</tspan><tspan x="0" dy="1.2em">↑</tspan>
</text>
</g>
<g transform="translate(644, 91)" class="key keypos-18">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Mouse</tspan><tspan x="0" dy="1.2em">→</tspan>
</text>
</g>
<g transform="translate(700, 105)" class="key keypos-19">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Switch</tspan><tspan x="0" dy="1.2em">app</tspan>
</text>
</g>
<g transform="translate(28, 161)" class="key keypos-20">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(84, 147)" class="key keypos-21">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(140, 140)" class="key keypos-22">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(196, 147)" class="key keypos-23">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(252, 154)" class="key keypos-24">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">Jiggle</text>
</g>
<g transform="translate(476, 154)" class="key keypos-25">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Scroll</tspan><tspan x="0" dy="1.2em">←</tspan>
</text>
</g>
<g transform="translate(532, 147)" class="key keypos-26">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Scroll</tspan><tspan x="0" dy="1.2em">↓</tspan>
</text>
</g>
<g transform="translate(588, 140)" class="key keypos-27">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Scroll</tspan><tspan x="0" dy="1.2em">↑</tspan>
</text>
</g>
<g transform="translate(644, 147)" class="key keypos-28">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Scroll</tspan><tspan x="0" dy="1.2em">→</tspan>
</text>
</g>
<g transform="translate(700, 161)" class="key keypos-29">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Switch</tspan><tspan x="0" dy="1.2em">window</tspan>
</text>
</g>
<g transform="translate(168, 205)" class="key keypos-30">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(230, 213) rotate(15.0)" class="key keypos-31">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(295, 224) rotate(30.0)" class="key held keypos-32">
<rect rx="6" ry="6" x="-26" y="-40" width="52" height="80" class="key held"/>
</g>
<g transform="translate(433, 224) rotate(-30.0)" class="key keypos-33">
<rect rx="6" ry="6" x="-26" y="-40" width="52" height="80" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Left</tspan><tspan x="0" dy="1.2em">click</tspan>
</text>
</g>
<g transform="translate(498, 213) rotate(-15.0)" class="key keypos-34">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Right</tspan><tspan x="0" dy="1.2em">click</tspan>
</text>
</g>
<g transform="translate(560, 205)" class="key keypos-35">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
</g>
</g>
<g transform="translate(30, 992)" class="layer-SYM">
<text x="0" y="28" class="label" id="SYM">SYM:</text>
<g transform="translate(0, 56)">
<g transform="translate(28, 49)" class="key keypos-0">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">&amp;</text>
</g>
<g transform="translate(84, 35)" class="key keypos-1">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">*</text>
</g>
<g transform="translate(140, 28)" class="key keypos-2">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">{</text>
</g>
<g transform="translate(196, 35)" class="key keypos-3">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">}</text>
</g>
<g transform="translate(252, 42)" class="key keypos-4">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">`</text>
</g>
<g transform="translate(476, 42)" class="key keypos-5">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">@</text>
</g>
<g transform="translate(532, 35)" class="key keypos-6">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">+</text>
</g>
<g transform="translate(588, 28)" class="key keypos-7">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">_</text>
</g>
<g transform="translate(644, 35)" class="key keypos-8">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">|</text>
</g>
<g transform="translate(700, 49)" class="key keypos-9">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">:</text>
</g>
<g transform="translate(28, 105)" class="key keypos-10">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">^</text>
</g>
<g transform="translate(84, 91)" class="key keypos-11">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">$</text>
</g>
<g transform="translate(140, 84)" class="key keypos-12">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">(</text>
</g>
<g transform="translate(196, 91)" class="key keypos-13">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">)</text>
</g>
<g transform="translate(252, 98)" class="key keypos-14">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">~</text>
</g>
<g transform="translate(476, 98)" class="key keypos-15">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">!</text>
</g>
<g transform="translate(532, 91)" class="key keypos-16">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">=</text>
</g>
<g transform="translate(588, 84)" class="key keypos-17">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">-</text>
</g>
<g transform="translate(644, 91)" class="key keypos-18">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">\</text>
</g>
<g transform="translate(700, 105)" class="key keypos-19">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">;</text>
</g>
<g transform="translate(28, 161)" class="key keypos-20">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">%</text>
</g>
<g transform="translate(84, 147)" class="key keypos-21">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">#</text>
</g>
<g transform="translate(140, 140)" class="key keypos-22">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">[</text>
</g>
<g transform="translate(196, 147)" class="key keypos-23">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">]</text>
</g>
<g transform="translate(252, 154)" class="key keypos-24">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">?</text>
</g>
<g transform="translate(476, 154)" class="key keypos-25">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">&#x27;</text>
</g>
<g transform="translate(532, 147)" class="key keypos-26">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">&quot;</text>
</g>
<g transform="translate(588, 140)" class="key keypos-27">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">,</text>
</g>
<g transform="translate(644, 147)" class="key keypos-28">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">.</text>
</g>
<g transform="translate(700, 161)" class="key keypos-29">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">/</text>
</g>
<g transform="translate(168, 205)" class="key keypos-30">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(230, 213) rotate(15.0)" class="key keypos-31">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(295, 224) rotate(30.0)" class="key keypos-32">
<rect rx="6" ry="6" x="-26" y="-40" width="52" height="80" class="key"/>
</g>
<g transform="translate(433, 224) rotate(-30.0)" class="key keypos-33">
<rect rx="6" ry="6" x="-26" y="-40" width="52" height="80" class="key"/>
</g>
<g transform="translate(498, 213) rotate(-15.0)" class="key held keypos-34">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key held"/>
</g>
<g transform="translate(560, 205)" class="key keypos-35">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g class="combo combopos-0">
<rect rx="6" ry="6" x="602" y="74" width="28" height="26" class="combo"/>
<text x="616" y="88" class="combo tap"><tspan style="font-size: 78%">Backspace</tspan></text>
</g>
</g>
</g>
<g transform="translate(30, 1323)" class="layer-NUM">
<text x="0" y="28" class="label" id="NUM">NUM:</text>
<g transform="translate(0, 56)">
<g transform="translate(28, 49)" class="key keypos-0">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(84, 35)" class="key keypos-1">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">7</text>
</g>
<g transform="translate(140, 28)" class="key keypos-2">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">8</text>
</g>
<g transform="translate(196, 35)" class="key keypos-3">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">9</text>
</g>
<g transform="translate(252, 42)" class="key keypos-4">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(476, 42)" class="key keypos-5">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(532, 35)" class="key keypos-6">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Vim</tspan><tspan x="0" dy="1.2em">Prefix</tspan>
</text>
</g>
<g transform="translate(588, 28)" class="key keypos-7">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(644, 35)" class="key keypos-8">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(700, 49)" class="key keypos-9">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(28, 105)" class="key keypos-10">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(84, 91)" class="key keypos-11">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">4</text>
</g>
<g transform="translate(140, 84)" class="key keypos-12">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">5</text>
</g>
<g transform="translate(196, 91)" class="key keypos-13">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">6</text>
</g>
<g transform="translate(252, 98)" class="key keypos-14">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(476, 98)" class="key keypos-15">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(532, 91)" class="key keypos-16">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">Shift</text>
</g>
<g transform="translate(588, 84)" class="key keypos-17">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">Ctrl</text>
</g>
<g transform="translate(644, 91)" class="key keypos-18">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">Alt</text>
</g>
<g transform="translate(700, 105)" class="key keypos-19">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">Gui</text>
</g>
<g transform="translate(28, 161)" class="key keypos-20">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">0</text>
</g>
<g transform="translate(84, 147)" class="key keypos-21">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">1</text>
</g>
<g transform="translate(140, 140)" class="key keypos-22">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">2</text>
</g>
<g transform="translate(196, 147)" class="key keypos-23">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">3</text>
</g>
<g transform="translate(252, 154)" class="key keypos-24">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(476, 154)" class="key keypos-25">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(532, 147)" class="key keypos-26">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Tmux</tspan><tspan x="0" dy="1.2em">Prefix</tspan>
</text>
</g>
<g transform="translate(588, 140)" class="key keypos-27">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">,</text>
</g>
<g transform="translate(644, 147)" class="key keypos-28">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">.</text>
</g>
<g transform="translate(700, 161)" class="key keypos-29">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(168, 205)" class="key keypos-30">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(230, 213) rotate(15.0)" class="key keypos-31">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(295, 224) rotate(30.0)" class="key keypos-32">
<rect rx="6" ry="6" x="-26" y="-40" width="52" height="80" class="key"/>
</g>
<g transform="translate(433, 224) rotate(-30.0)" class="key held keypos-33">
<rect rx="6" ry="6" x="-26" y="-40" width="52" height="80" class="key held"/>
</g>
<g transform="translate(498, 213) rotate(-15.0)" class="key keypos-34">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(560, 205)" class="key keypos-35">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g class="combo combopos-0">
<rect rx="6" ry="6" x="602" y="74" width="28" height="26" class="combo"/>
<text x="616" y="88" class="combo tap"><tspan style="font-size: 78%">Backspace</tspan></text>
</g>
<g class="combo combopos-1">
<rect rx="6" ry="6" x="210" y="26" width="28" height="26" class="combo"/>
<text x="224" y="38" class="combo tap">+</text>
</g>
<g class="combo combopos-2">
<rect rx="6" ry="6" x="490" y="26" width="28" height="26" class="combo"/>
<text x="504" y="38" class="combo tap">-</text>
</g>
<g class="combo combopos-3">
<rect rx="6" ry="6" x="210" y="138" width="28" height="26" class="combo"/>
<text x="224" y="150" class="combo tap">*</text>
</g>
<g class="combo combopos-4">
<rect rx="6" ry="6" x="490" y="138" width="28" height="26" class="combo"/>
<text x="504" y="150" class="combo tap">/</text>
</g>
<g class="combo combopos-5">
<rect rx="6" ry="6" x="210" y="82" width="28" height="26" class="combo"/>
<text x="224" y="94" class="combo tap">(</text>
</g>
<g class="combo combopos-6">
<rect rx="6" ry="6" x="490" y="82" width="28" height="26" class="combo"/>
<text x="504" y="94" class="combo tap">)</text>
</g>
</g>
</g>
<g transform="translate(30, 1653)" class="layer-WM">
<text x="0" y="28" class="label" id="WM">WM:</text>
<g transform="translate(0, 56)">
<g transform="translate(28, 49)" class="key keypos-0">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">WS</tspan><tspan x="0" dy="1.2em">1</tspan>
</text>
</g>
<g transform="translate(84, 35)" class="key keypos-1">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">WS</tspan><tspan x="0" dy="1.2em">2</tspan>
</text>
</g>
<g transform="translate(140, 28)" class="key keypos-2">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">WS</tspan><tspan x="0" dy="1.2em">3</tspan>
</text>
</g>
<g transform="translate(196, 35)" class="key keypos-3">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">WS</tspan><tspan x="0" dy="1.2em">4</tspan>
</text>
</g>
<g transform="translate(252, 42)" class="key keypos-4">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">WS</tspan><tspan x="0" dy="1.2em">5</tspan>
</text>
</g>
<g transform="translate(476, 42)" class="key keypos-5">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">→WS</tspan><tspan x="0" dy="1.2em">1</tspan>
</text>
</g>
<g transform="translate(532, 35)" class="key keypos-6">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">→WS</tspan><tspan x="0" dy="1.2em">2</tspan>
</text>
</g>
<g transform="translate(588, 28)" class="key keypos-7">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">→WS</tspan><tspan x="0" dy="1.2em">3</tspan>
</text>
</g>
<g transform="translate(644, 35)" class="key keypos-8">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">→WS</tspan><tspan x="0" dy="1.2em">4</tspan>
</text>
</g>
<g transform="translate(700, 49)" class="key keypos-9">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">→WS</tspan><tspan x="0" dy="1.2em">5</tspan>
</text>
</g>
<g transform="translate(28, 105)" class="key keypos-10">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap"><tspan style="font-size: 70%">Fullscreen</tspan></text>
</g>
<g transform="translate(84, 91)" class="key keypos-11">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">Resize</text>
</g>
<g transform="translate(140, 84)" class="key keypos-12">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">Move</text>
</g>
<g transform="translate(196, 91)" class="key keypos-13">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">Tiles</text>
</g>
<g transform="translate(252, 98)" class="key keypos-14">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap"><tspan style="font-size: 78%">Accordion</tspan></text>
</g>
<g transform="translate(476, 98)" class="key keypos-15">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Focus</tspan><tspan x="0" dy="1.2em">←</tspan>
</text>
</g>
<g transform="translate(532, 91)" class="key keypos-16">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Focus</tspan><tspan x="0" dy="1.2em">↓</tspan>
</text>
</g>
<g transform="translate(588, 84)" class="key keypos-17">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Focus</tspan><tspan x="0" dy="1.2em">↑</tspan>
</text>
</g>
<g transform="translate(644, 91)" class="key keypos-18">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Focus</tspan><tspan x="0" dy="1.2em">→</tspan>
</text>
</g>
<g transform="translate(700, 105)" class="key keypos-19">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">Float</text>
</g>
<g transform="translate(28, 161)" class="key keypos-20">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">Join</text>
</g>
<g transform="translate(84, 147)" class="key keypos-21">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(140, 140)" class="key keypos-22">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">Close</text>
</g>
<g transform="translate(196, 147)" class="key keypos-23">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(252, 154)" class="key keypos-24">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(476, 154)" class="key keypos-25">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(532, 147)" class="key keypos-26">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
<text x="0" y="0" class="key tap">
<tspan x="0" dy="-0.6em">Next</tspan><tspan x="0" dy="1.2em">Monitor</tspan>
</text>
</g>
<g transform="translate(588, 140)" class="key keypos-27">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(644, 147)" class="key keypos-28">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(700, 161)" class="key keypos-29">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(168, 205)" class="key keypos-30">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
<g transform="translate(230, 213) rotate(15.0)" class="key held keypos-31">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key held"/>
</g>
<g transform="translate(295, 224) rotate(30.0)" class="key keypos-32">
<rect rx="6" ry="6" x="-26" y="-40" width="52" height="80" class="key"/>
<text x="0" y="0" class="key tap">Reset</text>
</g>
<g transform="translate(433, 224) rotate(-30.0)" class="key keypos-33">
<rect rx="6" ry="6" x="-26" y="-40" width="52" height="80" class="key"/>
</g>
<g transform="translate(498, 213) rotate(-15.0)" class="key held keypos-34">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key held"/>
</g>
<g transform="translate(560, 205)" class="key keypos-35">
<rect rx="6" ry="6" x="-26" y="-26" width="52" height="52" class="key"/>
</g>
</g>
</g>
<text x="758.0" y="2012.0" class="footer">Created with <a href="https://github.com/caksoylar/keymap-drawer">keymap-drawer</a></text></svg>



## Installation

This repository is designed as an [External QMK Userspace](https://docs.qmk.fm/newbs_external_userspace). To use it with QMK, follow these steps:

1. [Set up QMK](https://docs.qmk.fm/newbs) if you have not already.
2. Clone this repository to your local machine.
3. Run the following command to configure QMK to use this repository as an overlay:

```sh
qmk config user.overlay_dir="$(realpath .)"
```

Once configured, you can compile and flash the keymaps for your keyboards using the following commands:

### Ergodox EZ

To compile and flash the keymap for the Ergodox EZ, use:

```sh
make ergodox_ez:dinhhuy258:teensy
```

### Corne

To compile and flash the keymap for the Corne, use:

```sh
make crkbd:dinhhuy258:flash
```

For one of my Corne keyboards equipped with the RP2040 chip, the default serial D2 pin is non-functional. As a result, the following modification has been made:

- The D2 and D3 pins have been connected and soldered together.
- D3 can be configured to function as the serial data pin in the firmware by using the build flag:

```sh
make crkbd:dinhhuy258:flash SERIAL_PIN=D3
```

```
              .__|~~|__.
    D3 [TX0] -|        |- [RAW]
    D2 [RX1] -|        |- [GND]
       [GND] -|        |- [RST]
       [GND] -|  Pro   |- [VCC]
SDA/D1 [  2] -|  Micro |- [A3 ] F4
SCL/D0 [  3] -|        |- [A2 ] F5
    D4 [  4] -|        |- [A1 ] F6
    C6 [  5] -|        |- [A0 ] F7
    D7 [  6] -|        |- [15 ] B1
    E6 [  7] -|        |- [14 ] B3
    B4 [  8] -|        |- [16 ] B2
    B5 [  9] -|________|- [10 ] B6
```

Additionally, RGB lighting can be controlled with build flags:

```sh
make crkbd:dinhhuy258:flash USE_RGB_LIGHTING=yes
```

You can also customize the tapping term (default is 200ms) by using the `TAPPING_TERM` build flag:

```sh
make crkbd:dinhhuy258:flash TAPPING_TERM=150
```

To initially boot the RP2040 into bootloader mode

1. Hold down the BOOT button on the RP2040 board.
2. While holding the BOOT button, plug the USB cable into your computer.
3. Release the BOOT button after the board is connected. The RP2040 should now appear as a USB mass storage device, allowing you to flash the firmware.
