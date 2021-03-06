#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include "VRFontHandler.h"

#include "VRButton.h"

VRButton::VRButton(std::string name, std::string text) : VRMenuElement(name, text)
{

}

VRButton::~VRButton()
{

}

void VRButton::draw()
{
	glBegin(GL_QUADS);
	// Draw A Quad
	if (m_hover){
		glColor3f(0.8f, 0.0f, 0.0f);
	}
	else
	{
		glColor3f(1.0f, 1.0, 1.0f);
	}
	glVertex3f(m_x, m_y + m_height, Z_OFFSET);              // Top Left
	glVertex3f(m_x + m_width, m_y + m_height, Z_OFFSET);				// Top Right
	glVertex3f(m_x + m_width, m_y, Z_OFFSET);					// Bottom Right
	glVertex3f(m_x, m_y, Z_OFFSET);              // Bottom Left
	glEnd();

	glColor3f(0.0f, 0.0, 0.0f);
	glBegin(GL_LINE_STRIP);
	// Draw A Quad
	glVertex3f(m_x, m_y + m_height, 2.0 * Z_OFFSET);					// Top Left
	glVertex3f(m_x + m_width, m_y + m_height, 2.0 * Z_OFFSET);		// Top Right
	glVertex3f(m_x + m_width, m_y, 2.0 * Z_OFFSET);					// Bottom Right
	glVertex3f(m_x, m_y, 2.0 * Z_OFFSET);							// Bottom Left
	glVertex3f(m_x, m_y + m_height, 2.0 * Z_OFFSET);					// Top Left
	glEnd();

	if (!m_text.empty())
		VRFontHandler::getInstance()->renderTextBox(m_text, m_x, m_y, 2.0*Z_OFFSET, m_width, m_height);
}

void VRButton::click(double x, double y, bool isDown)
{
	if (isDown)
	{
		m_menu->sendEvent(this);
	}
}
