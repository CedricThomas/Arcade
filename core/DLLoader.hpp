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
	#include "Errors.hpp"

namespace Arcade {
	template <typename T>
	class DLLoader {
	public:

		explicit DLLoader(const std::string file, int mod = RTLD_LAZY)
		: _instance(nullptr), _lib()
		{
			_lib = dlopen(file.c_str(), mod);
			_path = file;
			if (_lib == nullptr) {
				auto str = "cstr : " + file;
				str += + " : " + std::string(dlerror());
				throw LoadingError(str);
			}
			loadInstance();
		}

		virtual ~DLLoader()
		{
			if (_lib != nullptr) {
				if (_instance)
					_instance = nullptr;
				dlclose(_lib);
			}
		}

		T *getInstance() const
		{
			if (_instance == nullptr) {
				auto str = "load : No instance loaded";
				throw LoadingError(str);
			}
			return _instance;
		}

		const std::string &getPath() const
		{
			return _path;
		}

		T *loadInstance(std::string sym_name="entryPoint")
		{
			auto *sym = dlsym(_lib, sym_name.c_str());
			if (sym == nullptr) {
				auto str = "load : " + std::string(dlerror());
				throw LoadingError(str);
			}
			auto fct = reinterpret_cast<void *(*)()>(sym);
			_instance = reinterpret_cast<T *>(fct());
			return _instance;
		}

	private:
		T *_instance;
		void *_lib;
		std::string _path;
	};
}

#endif /* !ARCADE_LDLOADER_HPP */
