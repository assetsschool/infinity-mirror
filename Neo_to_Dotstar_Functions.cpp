// Apply LED color changes
void showStrip()
{
	strip.show();
}

// Set a LED color (not yet visible)
void setPixel(int Pixel, byte red, byte green, byte blue)
{
	strip.setPixelColor(Pixel, strip.Color(red, green, blue));
}

// Set all LEDs to a given color and apply it (visible)
void setAll(byte red, byte green, byte blue)
{
	for (int i = 0; i < NUMPIXELS; i++)
	{
		setPixel(i, red, green, blue);
	}
	strip.show();
}
