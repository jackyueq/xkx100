//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "��¥");
	set ("long", @LONG
�������ŵ���ס�ĵط�������һ���а˸����ӣ����������������
�⣬����Ķ�ס�����ǽ�Ϲ��˼��ѵ�����
LONG);
	set("exits", ([
		"north" : __DIR__"dating",
		"east"  : __DIR__"chaifang",
	]));
	set("objects", ([
		__DIR__"npc/shencheng" : 1,
		__DIR__"npc/sunjun"    : 1,
		__DIR__"npc/boyuan"    : 1,
		__DIR__"npc/fengtan"   : 1,
	]));
  
	set("coor/x", -1489);
	set("coor/y", -2041);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
