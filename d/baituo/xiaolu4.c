// Room: /d/baituo/xiaolu4.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
������һ����ɽ��С·��С·�����Ӳݴ����������������ˡ�����
·��ȴ����ƽ����������������һ�㡣�㲻���е���ԥ���������
ɽ��С·�����ֳ�һ�������������ɽ�������ѡ�
LONG	);
	set("outdoors", "baituo");
	set("exits", ([
		"north"     : __DIR__"dongkou",
		"southwest" : __DIR__"xiaolu3",
		"westdown"  : "/d/npc/m_weapon/lianzhangshi",
	]));
	set("objects",([
		__DIR__"npc/shanzei2" : 1,
	]));
	set("coor/x", -49960);
	set("coor/y", 20020);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
