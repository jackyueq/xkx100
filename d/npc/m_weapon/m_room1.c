// ROOM m_room1.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "ɳĮ����");
	set("long", @LONG
������ɳĮ�в����һ�����ޣ����ϲ�Զ��Լ���Կ���һ���ںڵ�
ɽ������紫��һЩ���������Ĵ�����������Ҳ��֪��˭�ڴ���ʲô��
LONG );
	set("exits", ([
		"east"  : "/d/xingxiu/nanjiang2",
		"south" : __DIR__"xuanbing",
	]));
	set("no_clean_up", 0);
	set("coor/x", -41200);
	set("coor/y", 8990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
