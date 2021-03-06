#pragma once

#include "mvTypeBases.h"

namespace Marvel {

	PyObject* add_tab_bar(PyObject* self, PyObject* args, PyObject* kwargs);

	class mvTabBar : public mvStringPtrBase
	{

		MV_APPITEM_TYPE(mvAppItemType::TabBar, mvTabBar, "add_tab_bar")

		MV_CREATE_THEME_CONSTANT(mvAppItemType::TabBar, mvThemeCol_TabBar, 35L, 0L);

		MV_START_COLOR_CONSTANTS
			MV_CREATE_CONSTANT_PAIR(mvThemeCol_TabBar),
		MV_END_COLOR_CONSTANTS

	public:

		static void InsertParser(std::map<std::string, mvPythonParser>* parsers);

	public:

		mvTabBar(const std::string& name);

		std::string& getValue();
		void         setValue(const std::string& value);
		void         draw()               override;

#ifndef MV_CPP
		void setExtraConfigDict(PyObject* dict) override;
		void getExtraConfigDict(PyObject* dict) override;
#endif // !MV_CPP

	private:

		ImGuiTabBarFlags m_flags = ImGuiTabBarFlags_None;

	};

}