// /kaifeng/yanqing.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����۷������������ư��硣ʼ����Ԫ̫�����꣬ԭ��Ϊ�����ۣ�
Ϊ���������ȫ��̴�ʼ�������ڴ˴��̲������ڴ˶��޽�����������
�꣬��������ۡ�
LONG);
	set("exits", ([
		"east"  : __DIR__"wroad2",
		"north" : __DIR__"sanqing",
	]));
	set("objects", ([
		__DIR__"npc/walker" : 1,
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
