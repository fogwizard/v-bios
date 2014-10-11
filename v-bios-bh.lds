ENTRY(GBotHalfEntry)

SECTIONS
{
	.text ALIGN(4):
	{ 
		GBotHalfEntry = .;
		*(.text)
	}

	.data ALIGN(4):
	{ 
		*(.data)
	}

	.bss ALIGN(4):
	{
		*(.bss)
	}

	.APP ALIGN(4):
	{
		SYSCALL_BEGIN = .;
		*(.APP)
		. = ALIGN(4);
		SYSCALL_END = .;
	}

	.InitSect ALIGN(4):
	{
		*(.Code.InitSect)
		*(.Data.InitSect)
		g_pfInitCallBegin = .;
		*(.Level0.InitSect)
		*(.Level1.InitSect)
		*(.Level2.InitSect)
		*(.Level3.InitSect)
		*(.Level4.InitSect)
		g_pfInitCallEnd = .;
	}
	
	. = ALIGN(4);
	g_pGBiosEnd = .;
}
