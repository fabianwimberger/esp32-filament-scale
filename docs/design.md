# Design Notes

Why the parts look the way they do, and what the design does not cover. Z positions are measured from the base floor and exclude the 2 mm pads.

## Load path

The dryer's feet stand on the top. A seat in the top's underside is clamped to the free end of the cell; the cable end of the cell is clamped to a pedestal in the base. That is the only connection between the two parts.

The load tips the pedestal towards the free end: its front edge presses down and its rear screw pulls up with about three times the load each, 19 mm apart. Two solid rails run beside the cell from behind the pedestal to the far end wall and spread that couple over 140 mm. Nothing stands under the cell, which has to bend freely.

## Clearances

| Clearance | Nominal |
|---|---:|
| Top above the base wall (the visible gap) | 3.5 mm |
| Top's underside inside the base walls | 4 mm |
| Top's underside above the base rails | 4 mm |
| Top's underside above the board caps | 6.9 mm |
| Cell above the base floor | 2.3 mm, 1.3 mm at the potting |
| Channel roof above the fixed-end screw tips | 4.2 mm |

Assertions in [`cad/scale.scad`](../cad/scale.scad) fail the export if a parameter change breaks one of these.

## Fastening

The cell's M4 and M5 threads are larger than M3, so every screw passes through the cell and clamps it with a nut.

- **Fixed end** — heads in counterbores under the base, 3.7 mm of printed seat, the cell, then washer and nut. The seat is as thick as a 20 mm screw allows, which leaves the heads 0.4 mm proud of the floor, inside the height of the pads.
- **Moving end** — head and washer under the cell, through the cell and 3.6 mm of solid seat into a nut at the bottom of a hex well open to the top face. The nut has to sit above the seat: a nut between seat and cell would be drawn onto the cell and leave the top loose.

The screws have about 1 mm of play in the cell's holes. Lips on the pedestal form a 13 mm slot that sets the cell's angle; the top's seat is flat and is squared by eye before tightening.

## Stiffness

The top is carried from one 24 mm seat and cantilevers about 105 mm past it. It is a 7.5 mm plate on a solid underside 5.5 mm deep that hangs inside the base and ends level with the top of the cell, with a channel over the cell. At this depth a solid section is the stiffest option: ribs would sag about twice as much.

A beam estimate with E = 1.5 GPa puts the sag at the far feet at about 0.15 mm under 2 kg printed solid and 0.2 mm at 50% infill, plus about 0.2 mm from the base. Sag does not change the reading, since all weight still passes through the cell. An earlier 3.75 mm plate on a 4.5 mm underside sagged four times as much and visibly wobbled.

## Dimensions

| Feature | Position |
|---|---|
| Base | 180 × 100 mm footing, Z 0–4; 180 × 80 mm shell with 1.6 mm walls to Z 21 |
| Pedestal | X −40 to −16, top at Z 6.3, lips to Z 7.3 |
| Rails | 6 mm wide beside the cell; Z 15 at the pedestal, tapering to Z 8 at the far wall |
| Cell | Z 6.3–19, screws at X ±20 and ±35 |
| Board pockets | Boards at Z 5, walls to Z 10.5, caps to Z 12.1 |
| USB notch | X −73 to −57 in the rear wall, above Z 4.5 |
| Top | Plate Z 24.5–32, rim to Z 35, underside 168.8 × 68.8 mm down to Z 19 |
| Pads | X ±80, Y ±42 |

The caps limit how far a board can lift (0.5 to 1.7 mm) instead of clamping it, so they tolerate parts of different height. Each leg is 1 mm thick and bends 0.55 mm over a 0.7 mm ridge, about 3% strain.

## Limits

- **No overload stops.** The top would have to close the full 3.5 mm gap before the base catches it, far beyond the roughly 150% a 5 kg cell survives.
- **Off-center load.** The feet load the cell eccentrically. A bar cell's rating says nothing about corner accuracy; the checks in the [Build Guide](build.md#7-verify) measure it.
- **Heat.** The electronics sit in the same enclosure as the cell, under a dryer. The gap, the floor openings and the USB notch let air through, but the cell's temperature under a long drying cycle has not been measured.
- **Creep.** Printed seats relax under clamp force and warmth. Long-term drift has not been quantified.
- **Tipping.** The pads sit at Y ±42 against ±35 for the dryer's own feet, which roughly makes up for standing 34 mm higher.
- **Not sealed.** The enclosure is open to dust and spills.
