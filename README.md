Qt-TabletSupport
================

Support for wacom WinTab is not working since Qt 5. So that I write a small helper like class to wrap WinTab API, via loading WinTab32.dll dynamically.

I haven't write document yet, however, I wrote a simple hand writing program as example for this. Check it out in example folder.

Up to now, things supported: 

* Device detection.
* Coordinate of each moving, pressing and releasing.
* Normal pressure in relative.
* Basic device info query.

What's not supported yet:

* Tangent pressure.
* Tilt.
* WinTab extensions, such as UID.
* A lot more.

As you can see, I have only few basic supported features. Feel free to do pull requests.

### License

MIT.