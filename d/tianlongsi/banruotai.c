inherit ROOM;

void create()
{
        set("short", "����̨");
        set("long",@LONG
���Ǹ���ͨ��ʯ̨���ഫ������������ٴ�̨������������ȥ���Ǳ�
���صء���Ĳ���á������д��������µ�����֮�������������׾Ͳ���
���У�����ǧ��Ҫ��ʲô���⡣
LONG );
	set("exits", ([
		"south" : __DIR__"munitang",
		"north" : __DIR__"doushuai",
	]));
	set("no_clean_up", 0);
	set("coor/x", -37000);
	set("coor/y", -57090);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}