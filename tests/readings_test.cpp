#include "../firmware/readings.h"
#include <cassert>
#include <cmath>

int main() {
  filament_scale::Readings samples;
  assert(!samples.ready(0));
  assert(std::isnan(samples.mass(0, 0, 100)));
  for (uint32_t i = 0; i < 25; ++i) samples.add(110000, i * 200);
  assert(samples.ready(4800));
  assert(samples.stable(4800, 100));
  assert(samples.mass(4800, 10000, 100) == 1000);
  assert(samples.mass(4800, 210000, -100) == 1000);
  assert(std::isnan(samples.mass(7800, 10000, 100)));
  assert(std::isnan(samples.mass(4800, 10000, 0)));
  samples.add(NAN, 7900);
  assert(!samples.ready(7900));
  samples.add(120000, 8000);
  assert(!samples.ready(8000));
  assert(!samples.stable(8000, 100));
  for (uint32_t i = 0; i < 25; ++i) samples.add(120000, 8200 + i * 200);
  assert(samples.stable(13000, 100));
  assert(samples.mass(13000, 10000, 100) == 1100);
  samples.add(8388607, 13200);
  assert(!samples.ready(13200));
  for (uint32_t i = 0; i < 25; ++i) samples.add(110000, 13400 + i * 200);
  assert(samples.ready(18200));
  samples.add(-8388608, 18400);
  assert(!samples.ready(18400));
  filament_scale::Readings wrapped;
  for (int i = 0; i < 25; ++i) wrapped.add(1, UINT32_MAX - 500);
  assert(wrapped.ready(500));
  assert(!wrapped.ready(3000));
}
