#pragma once

// Texto simples
struct Text : public Component
{
	String text;

	virtual void render()
	{
		if (selectable)
			COUT << text << "\n";
		else
		{
			Console::SetTextColor(Color::gray);
			COUT << text << "\n";
			Console::SetTextColor(Color::white);
		}
	}

	// Construtor
	Text() : text("[text]") {};
	Text(String t) : text(t) {};
};

// Seletor de opções
struct Selector : public Component
{
	int position;

	String label;
	List<String> options;

	virtual void render()
	{
		COUT << label << ": < " << options.get(position)->data << " >\n";
	}

	virtual void addOption(String o)
	{
		options.append(o);
	}

	virtual void selectNext()
	{
		if (position < options.length() - 1)
		{
			position += 1;
		}
	}

	virtual void selectPrevious()
	{
		if (position > 0)
		{
			position -= 1;
		}
	}

	// Construtor
	Selector() : label("[selector_label]") {};
	Selector(String _label) : label(_label) {};
};