// Room: /d/songshan/houting.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "��ͥ");
	set("long", @LONG
�����Ǿ�����Ժ��Ժ�ڵĺ�ͥ��ͥԺ����ʯ�̵ء��Ű�ɭɭ������
�Ǳ���������������֮�����������������������Ƕ���̳��
LONG );
	set("exits", ([
		"north" : __DIR__"duzuntan",
		"south" : __DIR__"huayuan",
		"east"  : __DIR__"woshi",
		"west"  : __DIR__"danfang",
	]));
	set("objects", ([
		CLASS_D("songshan")+"/ding" : 1,
	]));
	set("outdoors", "songshan");
	set("coor/x", -20);
	set("coor/y", 930);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
