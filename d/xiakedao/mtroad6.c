// mtroad6.c  ɽ��ƽ��

inherit ROOM;

void create()
{
	set("short", "ɽ��ƽ��");
	set("long", @LONG
������ɭ���е�һ��Сƽ�ء�����û�֣�Ұ�����������ܶ���
���ܵ�ɭ�֡�ʱ��ʱ��������Ұ��˻�У�����������������һ����
ͻأ���𣬼����վ���
LONG );
	set("outdoors", "motianya");
	set("exits", ([
		"east"  : __DIR__"mtroad4",
		"west"  : __DIR__"mtroad4",
		"north" : __DIR__"mtroad4",
		"south" : __DIR__"mtroad4",
	]));
	set("objects", ([
//		__DIR__"npc/shipopo" : 1,
		CLASS_D("lingxiao")+"/shipopo" : 1,
	]));
	set("coor/x", -1900);
	set("coor/y", -1700);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
