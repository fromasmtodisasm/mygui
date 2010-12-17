/*!
	@file
	@author		Albert Semenov
	@date		12/2010
*/
#ifndef __PROPERTY_FIELD_COMBO_BOX_H__
#define __PROPERTY_FIELD_COMBO_BOX_H__

#include "EditorToolTip.h"
#include "IPropertyField.h"

namespace tools
{
	class PropertyFieldComboBox :
		public IPropertyField
	{
	public:
		PropertyFieldComboBox();
		virtual ~PropertyFieldComboBox();

		virtual void initialise(MyGUI::Widget* _window, const std::string& _type, MyGUI::Widget* _currentWidget);

		virtual void setValue(const std::string& _value);
		virtual void setName(const std::string& _value);

		virtual MyGUI::IntSize getContentSize();
		virtual void setCoord(const MyGUI::IntCoord& _coord);

	private:
		void destroy();

		void notifyApplyProperties(MyGUI::Widget* _sender, bool _force);
		void notifyForceApplyProperties2(MyGUI::ComboBox* _widget, size_t _index);

		void notifyToolTip(MyGUI::Widget* _sender, const MyGUI::ToolTipInfo& _info);
		SkinInfo getCellData(MyGUI::Widget* _sender, size_t _index);

		bool checkType(MyGUI::EditBox* _edit, const std::string& _type);
		bool isSkinExist(const std::string& _skinName);
		bool checkTemplate(const std::string& _skinName);

	private:
		MyGUI::TextBox* mText;
		MyGUI::ComboBox* mField;
		MyGUI::Widget* mCurrentWidget;
		std::string mType;
	};

} // namespace tools

#endif // __PROPERTY_FIELD_COMBO_BOX_H__
