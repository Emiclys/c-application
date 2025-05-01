#pragma once

class Menu
{
private:
	int cursor = 0;

public:
	String name = "[MENU NAME]";
	List<Object> options;
	Menu* parent = NULL;
	Object* cursoredObject = NULL;

	void render()
	{
		CLEAR_CONSOLE;

		// renderiza o nome do menu
		if (parent == NULL)
			COUT << name << "\n\n";
		else
		{
			Menu* temp = parent;
			List<Menu*> tempList;

			while (parent != NULL)
			{
				tempList.append(parent);
				parent = parent->parent;
			}

			for (int i = tempList.length() - 1; i >= 0; i--)
				COUT << tempList.get(i)->data->name << " > ";

			COUT << name << "\n\n";
		}

		// renderiza as opções do menu
		for (int i = 0; i < options.length(); i++)
		{
			if (i == cursor)
				COUT << "> ";
			else
				COUT << "  ";

			options.get(i)->data.render();
		}
	}

	template<typename T>
	T* addOption()
	{
		return options.append(Object())->data.addComponent<T>();
	}

	void setCallback(int optionIndex, void(*func)())
	{
		options.get(optionIndex)->callback_ptr = func;
	}

	void call()
	{
		if (options.get(cursor)->callback_ptr != NULL)
			options.get(cursor)->callback_ptr();
	}

	int getCursorPosition() const
	{
		return cursor;
	}

	void moveCursorDown()
	{
		if (cursor < options.length() - 1)
		{
			while (options.get(++cursor)->data.selectable == false);
			render();
		}

		cursoredObject = &options.get(cursor)->data;
	}

	void moveCursorUp()
	{
		if (cursor > 0)
		{
			while (options.get(--cursor)->data.selectable == false);
			render();
		}

		cursoredObject = &options.get(cursor)->data;
	}

};