// /kaifeng/road4.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����߸ߵ�����ͬ�ʺ�����˼䣬��ʮ����ʯ��ֱͨ�������¾���
ˮ����ӿ�Ĵ��˺ӡ���������������о��ۺ������Ȼ�����¿�ȥ����
���ڸ߲�֮�ϣ������Ĳ����ѡ�
LONG);
	set("exits", ([
		"southdown" : __DIR__"road3",
		"northdown" : __DIR__"road5",
	]));
	set("objects", ([
		__DIR__"npc/walker" : 1,
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
