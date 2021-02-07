#include "noflyzone_util.h"

//basically copied from nav_survey_polygon.c
//return 0 if the two line segments don't intersect, 1 if they do.
//If they do, sets the first two parameters to the coordinates of intersection.
int intersect_two_lines(float *x_i, float *y_i, float ax0, float ay0, float ax1, float ay1, float bx0, float by0, float bx1, float by1) {
  float divider, fac;
  divider = (((by1 - by0) * (ax1 - ax0)) + ((ay0 - ay1) * (bx1 - bx0)));
  if (divider == 0) { return 0; }
  fac = ((ax1 * (ay0 - by0)) + (ax0 * (by0 - ay1)) + (bx0 * (ay1 - ay0))) / divider;
  if (fac > 1.0) { return 0; }
  if (fac < 0.0) { return 0; }
  *x_i = bx0 + fac * (bx1 - bx0);
  *x_i = by0 + fac * (by1 - by0);
  return 1;
}

int path_intersect_nfz(int num_verts, coords *verts) {
}
