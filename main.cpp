#include "base/files/file_path.h"
#include "base/files/file.h"

int main() {
	base::FilePath path(FILE_PATH_LITERAL("D:/tmp/traced_value.h"));
	base::File file{path, base::File::FLAG_OPEN};
	if (!file.IsValid()) {
		return -2;
	}
	return 0;
}