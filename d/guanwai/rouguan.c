// /guanwai/rouguan.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ���С�Ĺ���ݣ�������һ���ܴ������������ռȥ�˷���
��һ�롣������һ������ϼ�һ�ڴ�������������������ӹ��в���
ð�������ݵ��ϰ����ڹ��ԣ����ϵĸ�����ʢ��һ���������ڵ�������
LONG );
	set("exits", ([
		"east"  : __DIR__"nancheng",
	]));
	set("objects", ([
		__DIR__"npc/laoban" : 1,
	]));
	set("coor/x", 6030);
	set("coor/y", 5200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}