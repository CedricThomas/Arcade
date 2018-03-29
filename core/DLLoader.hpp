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
			if (_lib == nullptr) {
				auto str = "cstr : " + file + " : " + std::string(dlerror());
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
			return _instance;
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
	};
}

#endif /* !ARCADE_LDLOADER_HPP */
