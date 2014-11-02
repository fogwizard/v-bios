ENTRY(TH_START)
SECTIONS
{
	.text ALIGN(4):
	{ 
		TH_START = .;
		*(.text)
	}

	.data ALIGN(4):
	{ 
		data_start = .;
		*(.data)
	}

	.bss ALIGN(4):
	{
		bss_start = .;
		*(.bss)
	}
	.APP ALIGN(4):
	{
		SYSCALL_BEGIN = .;
		*(.APP)
		. = ALIGN(4);
		SYSCALL_END = .;
	}
	.INITSECT ALIGN(4):
	{
		INIT_CALL_BEGIN = .;
		*(.INITSECT)
		. = ALIGN(4);
		INIT_CALL_END = .;
	}
	_end = .;
}
