// Room: /d/songshan/woshi.c
// Last Modified by winder on Jul. 17 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���߽���һ�����ҡ�һ�ַǳ������ĸо�����������ٽ��黭����
��ǽ�ϡ�����������һ�ж�����������
    ����һ�Ŵ�������һ���ƶб����������������ʡ�
LONG );
	set("exits", ([
		"west" : __DIR__"houting",
	]));
	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", 930);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
