// Room: /d/qilian/bulangpo1.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����������ɽ���Ŀ�ʼ�����Ƹ��ӡ�ɽ�ж�Ϊ�˼�����֮�������
�ķᣬ��ɽ�����ڶ�Ұ�������Ѳ�ԡ��ñ��ĺ�ȥ����
LONG );
	set("outdoors", "qilian");
	set("exits", ([
		"northup" : __DIR__"bulangpo2",
		"south"   : __DIR__"bonanshan",
	]));
	set("objects", ([
		__DIR__"npc/mulang": 1,
	]));
	set("coor/x", -9900);
	set("coor/y", 2800);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}