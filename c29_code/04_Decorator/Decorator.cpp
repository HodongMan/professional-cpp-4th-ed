#include <string>
#include <string_view>
#include <iostream>

class IParagraph
{
public:
	virtual ~IParagraph() = default;  // Always a virtual destructor!
	virtual std::string getHTML() const = 0;
};

class Paragraph : public IParagraph
{
public:
	Paragraph(std::string_view text) : mText(text) { }
	virtual std::string getHTML() const override { return mText; }

private:
	std::string mText;
};

class BoldParagraph : public IParagraph
{
public:
	BoldParagraph(const IParagraph& paragraph) : mWrapped(paragraph) { }

	virtual std::string getHTML() const override
	{
		return "<B>" + mWrapped.getHTML() + "</B>";
	}

private:
	const IParagraph& mWrapped;
};

class ItalicParagraph : public IParagraph
{
public:
	ItalicParagraph(const IParagraph& paragraph) : mWrapped(paragraph) { }

	virtual std::string getHTML() const override
	{
		return "<I>" + mWrapped.getHTML() + "</I>";
	}

private:
	const IParagraph& mWrapped;
};



int main()
{
	Paragraph p("A party? For me? Thanks!");

	// Bold
	std::cout << BoldParagraph(p).getHTML() << std::endl;

	// Bold and Italic
	std::cout << ItalicParagraph(BoldParagraph(p)).getHTML() << std::endl;

	return 0;
}
