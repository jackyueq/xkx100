// Room: /d/quanzhou/jishi.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǿ������ճ�������Ʒ���̷��ĳ�����������ƷӦ�о��У�
������Ŀ��ͬʱ����Ҳ��������������˵��������ס����ϡ�ʯ���Ǳ�
���̼������ֵ�����Ʒ����Ϊ���Ƕ�֪��һ�������˵���ԭ��������
���������󡣲�������Ϊ�����ﳤ����������������������Ϣ������
���¾����ּۻ��۵�������
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"huajiaoting",
		"east"  : __DIR__"tumenji",
		"west"  : __DIR__"xinmenji",
	]));
	set("objects", ([
		__DIR__"npc/xiaofan" : 1,
	]));
	set("coor/x", 1850);
	set("coor/y", -6580);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
