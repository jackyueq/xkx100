// Room: /d/suzhou/xidajie1.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣��������������ڣ�
����ϡ�٣������ĵغ������塣�����ǲ���ͤ�ͱ����ţ��ϱ��Ǳ�Ӫ��
���߾��������ˡ�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"west"      : __DIR__"xidajie2",
		"north"     : __DIR__"yamengate",
		"south"     : __DIR__"bingyinggate",
		"southeast" : __DIR__"baodaiqiao",
		"northeast" : __DIR__"canlangting",
		"northwest" : __DIR__"szyunhe",
	]));
	set("coor/x", 840);
	set("coor/y", -1010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
