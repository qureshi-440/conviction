#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    string fluid;
    int ts, ti, v;
    float width, l, h, a;
    float x, density, kv, pr, k;
    float rey, hblt, tblt, cf, avgcf, shear, drag, nussavg, nussx, hx, q;

    cout << "Hello\n";
    cout << "To evaluate a problem using fundamentals of convection, input parameters\n";
    cout << "Enter the type of fluid : ";
    cin >> fluid;
    cout << "Enter the width of the plate : ";
    cin >> width;
    cout << "Enter the length of the plate : ";
    cin >> l;
    cout << "Enter the value of x : ";
    cin >> x;
    cout << "Enter the surface temperature : ";
    cin >> ts;
    cout << "Enter the ambient temperature : ";
    cin >> ti;

    cout << "\n \n";
    int tf = (ts + ti) / 2;
    cout << "The film temperature is " << tf;
    cout << "\n \n";

    cout << "Enter the velocity of the " << fluid << " : ";
    cin >> v;
    cout << "Enter the density of the " << fluid << " : ";
    cin >> density;
    cout << "Enter the kinematic viscosity of the " << fluid << " : ";
    cin >> kv;
    cout << "Enter the Prandlt number of the " << fluid << " : ";
    cin >> pr;
    cout << "Enter the thermal conductivity of the " << fluid << " : ";
    cin >> k;
    rey = (v * x) / (kv);
    cout << "Value of rey for " << fluid << " is " << rey << " : ";
    if (rey <= 500000)
    {
        cout << "The flow is LAMINAR ";
        hblt = (5 * x) / (sqrt(rey));
        tblt = hblt * (pow(pr, -0.33));
        cf = 0.664 / (sqrt(rey));
        nussx = 0.332 * (sqrt(rey)) * (pow(pr, (1 / 3)));
    }
    if (rey > 500000)
    {
        cout << "\n Flow is TURBULENT \n";

        hblt = 0.381 * x * pow(rey, -0.2);
        tblt = (7 / 72) * hblt;
        cf = 0.0592 * pow(rey, -0.2);
        nussx = 0.0296 * pow(rey, 0.8) * pow(pr, 0.33);
    }

    avgcf = 2 * cf;
    nussavg = 2 * nussx;
    shear = cf * density * v * v * 0.5;

    a = l * width;
    drag = shear / a;

    hx = (nussx * k) / l;
    h = 2 * hx;
    q = h * a * (ts - ti);

    cout << "\n 1) The hydrodynamic boundary layer thickness at distance x from leading edge is " << hblt;
    cout << "\n 2) The thermal boundary layer thickness at a distance of x from leading edge is " << tblt;
    cout << "\n 3) Heat loss Q : " << q << "watts";
    cout << "\n 2) Drag force Fd : " << drag;
    cout << "\n 5) Shear force : " << shear;
    cout << "\n 6) Cf :" << cf;
    cout << "\n 7) Average Cf : " << avgcf;
    cout << "\n 8) nx : " << nussx;
    cout << "\n 9) Average nx : " << nussavg;
    cout << "\n 10) average Heat Co-efficient : " << h;
    cout << "\n \n";
    return 0;
}