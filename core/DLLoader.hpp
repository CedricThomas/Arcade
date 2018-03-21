/*
** EPITECH PROJECT, 2018
** ArcadeBS
** File description:
** LDLoader.hpp
*/

#ifndef ARCADE_LDLOADER_HPP
	#define ARCADE_LDLOADER_HPP

	#include <string>
	#include <dlfcn.h>
namespace Arcade {
	template <typename T>
	class DLLoader {
	public:

		DLLoader(const std::string file, int mod)
		: error_str(), error_bool(false), lib()
		{
			this->lib = dlopen(file.c_str(), mod);
			if (this->lib == nullptr) {
				this->error_str = std::string(dlerror());
				this->error_bool = true;
			}
		}

		~DLLoader()
		{
			if (this->lib)
				if (dlclose(this->lib) != 0) {
					error_str = std::string(dlerror());
					this->error_bool = true;
				}
		}

		T *getInstance(std::string sym_name="entryPoint") {
			if (this->error_bool)
				return nullptr;
			auto *sym = dlsym(this->lib, sym_name.c_str());
			if (sym == nullptr) {
				this->error_str = std::string(dlerror());
				this->error_bool = true;
				return nullptr;
			}
			auto fct = reinterpret_cast<void *(*)()>(sym);
			return reinterpret_cast<T *>(fct());
		}

		bool isError()
		{
			return this->error_bool;
		}

		const std::string &getError()
		{
			return error_str;
		}

	private:
		std::string error_str;
		bool error_bool;
		void *lib;
	};
}

#endif /* !ARCADE_LDLOADER_HPP */
