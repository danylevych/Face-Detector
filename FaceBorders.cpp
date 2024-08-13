#include "FaceBorders.h"

FaceBorders::FaceBorders(const cv::Scalar &boundColor, const std::string& text, const cv::Scalar &textColor, cv::HersheyFonts font)
	: boundColor(boundColor)
	, text(text)
	, thicknessBound(1)
	, thicknessFont(1)
	, textColor(textColor)
	, font(font)
{	}

void FaceBorders::SetBoundColor(const cv::Scalar &color)
{
	boundColor = color;
}

void FaceBorders::SetTextColor(const cv::Scalar &color)
{
	textColor = color;
}

void FaceBorders::SetText(const std::string &text)
{
	this->text = text;
}

void FaceBorders::SetBoundThickness(int value)
{
	thicknessBound = value;
}

void FaceBorders::SetFontThickness(int value)
{
	thicknessFont = value;
}

void FaceBorders::SetFont(const cv::HersheyFonts &font)
{
	this->font = font;
}


cv::Scalar FaceBorders::GetBoundColor() const
{
	return boundColor;
}

cv::Scalar FaceBorders::GetTextColor() const
{
	return textColor;
}

std::string FaceBorders::GetText() const
{
	return text;
}

int FaceBorders::GetBoundThickness() const
{
	return thicknessBound;
}

int FaceBorders::GetFontThickness() const
{
	return thicknessFont;
}

cv::HersheyFonts FaceBorders::GetFont() const
{
	return font;
}

void FaceBorders::Draw(cv::Rect &facePos, cv::Mat& dst)
{
	cv::rectangle(dst, facePos, boundColor, thicknessBound);
	cv::Point textPos(facePos.tl().x + 1, facePos.tl().y - thicknessBound - 5);
	cv::putText(dst, text, textPos, font, 1.2, textColor, thicknessFont);
}
