// ROOM lianbangshi.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "����Ժ");
	set("long", @LONG
�����������Ŷ��Ĵ���ĵط������ڳɶ�ؤ��ֶ��СԺ�һ��
��׳�ĺ�������һ���������ڵĴ���¯������һ����������ͣ���ô���
ʲô��
LONG );
	set("exits", ([
		"south" : "/d/chengdu/ruin1",
	]));
	set("objects", ([
		__DIR__"npc/shibang" :1,
	]));
	set("coor/x", -8070);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
