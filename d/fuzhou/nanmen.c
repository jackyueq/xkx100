// Room: /d/fuzhou/nanmen.c
// Date: May 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����Ǹ������š�����������һƬƽչ��ƽԭ��һƬ�Ͱ���С����
������һƬƬ�����֡��Ž��֡�һ��ƽֱ�Ĵ��������ͨ��������һ��
�е���֦������������
LONG );
	set("exits", ([
		"south" : __DIR__"zhongzhou",
		"north" : __DIR__"nanmendou",
	]));
	set("no_clean_up", 0);
	set("outdoors", "fuzhou");
	set("coor/x", 1840);
	set("coor/y", -6330);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
