// Room: /d/nanyang/yidao3.c
// Last Modified by winder on Nov. 20 2001

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ����̣�
���Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ������
����������߷ɳ۶���������һ·��������·�������������������
�֡�
LONG );
	set("exits", ([
		"south" : __DIR__"beimen",
		"north" : __DIR__"ruzhou",
	]));
	set("no_clean_up", 0);
	set("outdoors", "nanyang");
	set("coor/x", 10);
	set("coor/y", 600);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
