ENTRY(TH_START)

SECTIONS
{
	.text ALIGN(4):
	{
		*(.text)
	}
	
	.data ALIGN(4):
	{
		*(.data)
	}

	.rodata ALIGN(4):
	{
		*(.rodata)
	}
	.end=ALIGN(4);
}
