//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "����");
	set ("long", @LONG
����һ�����������ȡ�����������֪�����˵��鷿�����߾�ͷ��һ
�䷿����������һƥ���������Ǹ����á��ϱ��Ƕ��᷿����֪�����˺�
�Ҿ�ס�ĵط�����������û�µ���������һ��Ѿ�ߵ�Ц�š�
LONG);
	set("objects", ([
		"/d/city/npc/yayi"   : 3,
		__DIR__"npc/yahuan1" : 1, 
	]));
	set("exits", ([
		"west"  : __DIR__"shufang",
		"east"  : __DIR__"lingtang",
		"south" : __DIR__"dongxiang",
	]));
  
	set("coor/x", -1480);
	set("coor/y", -2029);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
