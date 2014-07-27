ENTRY(TH_START)

SECTIONS
{
	.text 0x0:
	{ 
		TH_START = .;
		*(.text)
	}

	.data ALIGN(4):
	{ 
		data_start = .;
		*(.data)
		. = ALIGN(4);
	}

	.bss ALIGN(4):
	{
		bss_start = .;
		*(.bss)
	}
	_end = .;
}
