//room: xianchou.c
inherit ROOM;

void create()
{
	set("short","�ɳ���");
	set("long",@LONG
����Ϳ쵽��翷�����ˣ�Խ�����ߣ�ɽ��Խ�ߣ�����������ߵ�
����������Ũ������������ɽ��·������ɽ��û�߼�����������ǰ����
һ��ʯ�������顺�ɳ��š��������֣�������ɽ֮�����ɡ�
LONG );
	set("outdoors", "lingjiu");
	set("exits",([
		"eastup" : __DIR__"dadao1",
		"southdown" : __DIR__"jian",
	]));
	set("objects",([
		CLASS_D("lingjiu")+"/first" :1,
	]));
	set("coor/x", -51010);
	set("coor/y", 30100);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}