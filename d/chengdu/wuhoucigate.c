// Room: wuhoucigate.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "���������");
	set("long", @LONG
����ԭ����������������˽��˳�������������ԭ�������ǰ
�����츣������������������ȥ������Ϊ���Т֮�ס���������Ű�
�����ǧ�����£�����ͷ���Բ�ȥ�ס�
LONG
	);
	set("exits", ([
		"east"      : __DIR__"nanjie",
		"northwest" : __DIR__"wuhouci",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8060);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
