#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <string>


class FaceBorders
{
private:
	int thicknessBound;
	int thicknessFont;
	std::string text;
	cv::Scalar boundColor;
	cv::Scalar textColor;
	cv::HersheyFonts font;

public:
	FaceBorders(const cv::Scalar& boundColor, const std::string& text, const cv::Scalar& textColor, cv::HersheyFonts font);

public:
	void SetBoundColor(const cv::Scalar& color);
	void SetTextColor(const cv::Scalar& color);
	void SetText(const std::string& text);
	void SetBoundThickness(int value);
	void SetFontThickness(int value);
	void SetFont(const cv::HersheyFonts& font);

public:
	cv::Scalar GetBoundColor() const;
	cv::Scalar GetTextColor() const;
	std::string GetText() const;
	int GetBoundThickness() const;
	int GetFontThickness() const;
	cv::HersheyFonts GetFont() const;

public:
	void Draw(cv::Rect& facePos, cv::Mat& dst);
};
