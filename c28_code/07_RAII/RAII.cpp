#include <cstdio>

class File final
{
public:
	File(std::FILE* file);
	~File();

	// Prevent copy construction and copy assignment.
	File(const File& src) = delete;
	File& operator=(const File& rhs) = delete;

	// Allow move construction and move assignment.
	File(File&& src) noexcept = default;
	File& operator=(File&& rhs) noexcept = default;

	// get(), release(), and reset()
	std::FILE* get() const noexcept;
	std::FILE* release() noexcept;
	void reset(std::FILE* file = nullptr) noexcept;

private:
	std::FILE* mFile;
};

File::File(std::FILE* file) : mFile(file)
{
}

File::~File()
{
	reset();
}

std::FILE* File::get() const noexcept
{
	return mFile;
}

std::FILE* File::release() noexcept
{
	std::FILE* file = mFile;
	mFile = nullptr;
	return file;
}

void File::reset(std::FILE* file /*= nullptr*/) noexcept
{
	if (mFile) {
		fclose(mFile);
	}
	mFile = file;
}

int main()
{
	File myFile(fopen("input.txt", "r"));

	return 0;
}
